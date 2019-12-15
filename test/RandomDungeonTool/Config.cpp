#include "RandomDungeonToolPCH.h"
#include "Config.h"
#include <iostream>

Config::Config() :
    shouldImportDe_(false),
    shouldExportDe_(false),
    shouldExportMission_(false),
    baseZ_(10)
{
}


bool Config::parseArgs(int argc, char* argv[])
{
    for (int i = 1; i < argc; ++i) {
        const std::string arg(argv[i]);
        if (arg == "-?") {
            break;
        }
        
        if (arg == "-id") {
            shouldImportDe_ = true;
        }
        else if (arg == "-ed") {
            shouldExportDe_ = true;
        }
        else if (arg == "-em") {
            shouldExportMission_ = true;
        }
        else if (arg.compare(0, 4, "-bf=") == 0) {
            baseFolder_ = arg.substr(4).c_str();
        }
        else if (arg.compare(0, 4, "-bz=") == 0) {
            baseZ_ = uint16_t(atoi(arg.substr(4).c_str()));
        }
        else {
            std::cerr << "* Unknown option '" << arg << "'.\n";
        }
    }

    if (baseFolder_.empty() || ((! shouldExportDe_) && (! shouldExportMission_))) {
        printUsage();
        return false;
    }

    return true;
}


void Config::printUsage()
{
    std::cout << "Random Dungeon Tool v0.0.1\n" <<
        "USAGE: RandomDungeonTool [command] [options]\n" <<
        "  command\n" <<
        "    -ed Construct a random dungeon and export DE format\n" <<
        "    -em Construct a random dungeon and export Mission format\n" <<
        "    -bf=<folder> Base DTS folder\n" <<
        "    -bz=<integer> Base Z axis\n" <<
        "  options\n" <<
        "    -? show this message\n";
}
