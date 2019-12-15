#pragma once

#include <gideon/cs/Common.h>

/**
 * @class Config
 * Configuration.
 */
class Config
{
public:
    Config();

    bool parseArgs(int argc, char* argv[]);

    void printUsage();

    bool shouldImportDe() const {
        return shouldImportDe_;
    }

    bool shouldExportDe() const {
        return shouldExportDe_;
    }

    bool shouldExportMission() const {
        return shouldExportMission_;
    }

    const std::string& getBaseFolder() const {
        return baseFolder_;
    }

    uint16_t getBaseZ() const {
        return baseZ_;
    }

private:
    bool shouldImportDe_;
    bool shouldExportDe_;
    bool shouldExportMission_;
    std::string baseFolder_;
    uint16_t baseZ_;
};
