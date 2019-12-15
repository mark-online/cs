#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/datatable/template/region_table.hxx>
#include <gideon/cs/shared/data/RegionInfo.h>
#include <gideon/cs/shared/data/QuestInfo.h>
#include <gideon/cs/shared/data/WorldInfo.h>
#include <sne/core/container/Containers.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @struct RegionTemplate
 */
struct RegionTemplate
{
    RegionCode regionCode_;
    uint32_t param1_;
    uint32_t param2_;

    RegionTemplate() :
        regionCode_(invalidRegionCode),
        param1_(0),
        param2_(0) {}

    RegionTemplate(const gdt::region_t& region) :
        regionCode_(region.region_code()),
        param1_(region.param1()),
        param2_(region.param2()) {}

    RegionTemplate(RegionCode regionCode, uint32_t param1 = 0, uint32_t param2 = 0) :
        regionCode_(regionCode),
        param1_(param1),
        param2_(param2) {}

public:
    bool isRegionTrigger() const {
        return isQuestProbeRegion() || isPortalRegion();
    }

    bool isQuestProbeRegion() const {
        return getRegionType(regionCode_) == rtProbe;
    }

    bool isPortalRegion() const {
        return getRegionType(regionCode_) == rtPortal;
    }

    bool isWorldEventRegion() const {
        return getRegionType(regionCode_) == rtWorldEvent;
    }

public:
    // = rtProbe
    QuestCode getQuestCode() const {
        if (isQuestProbeRegion()) {
            return param1_;
        }
        assert(false);
        return invalidQuestCode;
    }

    QuestMissionCode getQuestMissionCode() const {
        if (isQuestProbeRegion()) {
            return param2_;
        }
        assert(false);
        return invalidQuestMissionCode;
    }

public:
    // = rtPortal
    MapCode getTargetMapCode() const {
        if (isPortalRegion()) {
            return param1_;
        }
        assert(false);
        return invalidMapCode;
    }

    RegionCode getTargetRegionCode() const {
        if (isPortalRegion()) {
            return param2_;
        }
        assert(false);
        return invalidRegionCode;
    }
};


/**
 * @class RegionTable
 *
 */
class GIDEON_CS_API RegionTable : public boost::noncopyable
{
public:
    typedef sne::core::HashMap<RegionCode, RegionTemplate> RegionMap;
    typedef sne::core::HashMap<QuestMissionCode, const RegionTemplate*> RegionMapByQuestMission;

public:
    virtual ~RegionTable() {}

public:
    virtual const RegionTemplate* getRegion(RegionCode code) const = 0;

    virtual const RegionMap& getRegionMap() const = 0;

    virtual const RegionTemplate* getRegionByQuestMissionCode(QuestMissionCode missionCode) const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {
