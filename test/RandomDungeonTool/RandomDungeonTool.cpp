#include "RandomDungeonToolPCH.h"
#include "Config.h"
#include <gideon/cs/randun/RandomDungeonConstructor.h>
#include <iostream>

namespace {

inline std::string readPipe()
{
    std::string de;
    de.reserve(2048);

    FILE* pipe = stdin;

    int c;
    while ((c = fgetc(pipe)) != EOF) {
        if (iscntrl(c)) {
            break;
        }
        de += char(c);
    }

    fclose(pipe);
    return de;
}

} // namespace

bool run(const Config& config)
{
    gideon::randun::RandomDungeonConstructor randunConstructor(32, 16, config.getBaseZ());

    if (config.shouldImportDe()) {
        randunConstructor.importDe(readPipe());
    }
    else {
        randunConstructor.generate(10, 400);
    }

    (void)randunConstructor.analyze(0, 0); // 디버깅하려고 호출

    const gideon::MapCode mapCode = gideon::makeMapCode(gideon::mtRandomDundeon, 1);
    const gideon::MapInfo mapInfo = randunConstructor.getMapInfo(mapCode, 30);
    std::cerr << "center(" << mapInfo.originX_ << "," << mapInfo.originY_ << "," <<
        mapInfo.originZ_ << "), sector(" << mapInfo.xSectorCount_ << "," <<
        mapInfo.ySectorCount_ << "," << mapInfo.zSectorCount_ << "), " <<
        mapInfo.sectorLength_ << "\n";

    std::cerr << "--------------------------------\n";

    if (config.shouldExportDe()) {
        std::cout <<
            "<div id=\"level0\" class=\"level current\" rel=\"0\" title=\"floor 0\" "
            "onclick=\"changeToLevel(0);\">0<div class=\"data\">" <<
            randunConstructor.exportDe() << "</div></div>\n";
    }
    else if (config.shouldExportMission()) {
        gideon::randun::ExportParameters params("", config.getBaseFolder());
        std::cout << randunConstructor.exportMission(params) << "\n";
    }
    return true;
}


int main(int argc, char* argv[])
{
    Config config;
    if (! config.parseArgs(argc, argv)) {
        config.printUsage();
        return EXIT_FAILURE;
    }

    const bool succeeded = run(config);
    return succeeded ? EXIT_SUCCESS : EXIT_FAILURE;
}
