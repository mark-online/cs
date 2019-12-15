#pragma once

#include <gideon/cs/datatable/RegionTable.h>

namespace gideon { namespace datatable {

/**
 * @class RegionTableImpl
 *
 */
class RegionTableImpl : public RegionTable
{
public:
    RegionTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            std::unique_ptr<gdt::region_table> regionTable =
                gdt::region_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::region_t& region : regionTable->region_template()) {
                RegionTemplate& regionTemplate = regionMap_[region.region_code()];
                regionTemplate = RegionTemplate(region);
                if (regionTemplate.isQuestProbeRegion()) {
                    regionMapByQuestMission_[regionTemplate.getQuestMissionCode()] =
                        &regionTemplate;
                }
            }
            isLoaded_ = true;
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const RegionTemplate* getRegion(RegionCode code) const {
        const RegionMap::const_iterator pos = regionMap_.find(code);
        if (pos != regionMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const RegionMap& getRegionMap() const {
        return regionMap_;
    }

    virtual const RegionTemplate* getRegionByQuestMissionCode(QuestMissionCode missionCode) const {
        const RegionMapByQuestMission::const_iterator pos = regionMapByQuestMission_.find(missionCode);
        if (pos != regionMapByQuestMission_.end()) {
            return (*pos).second;
        }
        return nullptr;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    RegionMap regionMap_;
    RegionMapByQuestMission regionMapByQuestMission_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
