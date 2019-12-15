#pragma once

#include <gideon/cs/shared/data/AchievementInfo.h>
#include <gideon/cs/datatable/template/achievement_table.hxx>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {


/**
 * @class AchievementTable
 *
 */
class GIDEON_CS_API AchievementTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(AchievementTable);

public:
    typedef sne::core::HashMap<AchievementCode, const gdt::achievement_t*> AchievementMap;
    typedef sne::core::Vector<const gdt::achievement_t*> Achievements;
    typedef std::array<AchievementMap, acCount> AchievementMaps;
    typedef std::array<Achievements, acmtCount> Achievementss;

public:
    virtual ~AchievementTable() {}

public:
    virtual const AchievementMap& getAchievementMap(AchievementCategory category) const = 0;
    virtual const Achievements& getAchievements(AchievementMissionType type) const = 0;

    virtual const AchievementMaps& getAchievementMaps() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;

public:
    const gdt::achievement_t* getAchievement(AchievementCode code) const {
        const AchievementMap& achvMap = getAchievementMap(getAchievementCategory(code));
        const AchievementMap::const_iterator pos = achvMap.find(code);
        if (pos == achvMap.end()) {
            return nullptr;
        }
        return (*pos).second;
    }
};

}} // namespace gideon { namespace datatable {

#define ACHIEVEMENT_TABLE gideon::datatable::AchievementTable::instance()
