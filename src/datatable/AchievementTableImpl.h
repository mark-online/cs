#pragma once

#include <gideon/cs/datatable/AchievementTable.h>

namespace gideon { namespace datatable {

/**
 * @class AchievementTableImpl
 *
 */
class AchievementTableImpl : public AchievementTable
{
public:
    AchievementTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            achievementTable_ =
                gdt::achievement_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::achievement_t& achievement : achievementTable_->achievement_template()) {
                AchievementCategory category = getAchievementCategory(achievement.achievement_code());
                if (! isValid(category)) {
                    assert(false && "invalid category");
                    return;
                }
                achievementMaps_[category].emplace(achievement.achievement_code(), &achievement);

                const AchievementMissionType missionType = toAchievementMissionType(achievement.mission_type());
                if (! isValid(missionType)) {
                    assert(false);
                    continue;
                }

                achievementss_[missionType].push_back(&achievement);                                                    
            }
			AchievementTable::instance(this);
            isLoaded_ = true;
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const AchievementMap& getAchievementMap(AchievementCategory category) const {
        if (! isValid(category)) {
            assert(false && "invalid category");
            static AchievementMap nullObj;
            return nullObj;
        }

        return achievementMaps_[category];
    }

    virtual const Achievements& getAchievements(AchievementMissionType type) const {
        if (! isValid(type)) {
            assert(false && "invalid type");
            static Achievements nullObj;
            return nullObj;
        }

        return achievementss_[type];
    }

    virtual const AchievementMaps& getAchievementMaps() const {
        return achievementMaps_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::achievement_table> achievementTable_;
    AchievementMaps achievementMaps_;
    Achievementss achievementss_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
