#pragma once

#include <gideon/cs/shared/data/QuestInfo.h>
#include <gideon/cs/datatable/template/quest_kill_mission_table.hxx>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @struct QuestMissionKillGoalInfo
 *
 */
struct QuestMissionKillGoalInfo : QuestGoalInfo
{
	QuestGoalType goalType_;

	explicit QuestMissionKillGoalInfo(QuestGoalType goalType = qgtUnknown,
		DataCode goalCode = invalidDataCode, uint32_t goalValue = 0) :
        QuestGoalInfo(goalCode, goalValue),
		goalType_(goalType) {}

    bool isValid() const {
        return QuestGoalInfo::isValid() && isKillGoalType(goalType_);
    }
};


/**
 * @class QuestKillMissionTemplate
 *
 */
class QuestKillMissionTemplate
{
public:
	QuestKillMissionTemplate(const gdt::quest_kill_mission_t& mission) :
		missionCode_(mission.mission_code())
	{
		initMissionGoal(mission);
        initMarkerCodes(mission);
	}
	
	const QuestMissionKillGoalInfo& getGoalInfo() const {
		return questMissionKillGoalInfo_;
	}

    const DataCodes& getMarkerCodes() const {
        return markerCodes_;
    }

private:
	void initMissionGoal(const gdt::quest_kill_mission_t& mission) {
		questMissionKillGoalInfo_ = QuestMissionKillGoalInfo(
            static_cast<QuestGoalType>(mission.goal()), mission.goal_info(), mission.goal_value());
        assert(questMissionKillGoalInfo_.isValid());
	}

    void initMarkerCodes(const gdt::quest_kill_mission_t& mission) {
        if (isValidDataCode(mission.marker_code_1())) {
            markerCodes_.push_back(mission.marker_code_1());
        }
        if (isValidDataCode(mission.marker_code_2())) {
            markerCodes_.push_back(mission.marker_code_2());
        }
        if (isValidDataCode(mission.marker_code_3())) {
            markerCodes_.push_back(mission.marker_code_3());
        }
    }

private:
	QuestMissionCode missionCode_;
	QuestMissionKillGoalInfo questMissionKillGoalInfo_;
    DataCodes markerCodes_;
};



/**
 * @class QuestKillMissionTable
 *
 */
class GIDEON_CS_API QuestKillMissionTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(QuestKillMissionTable);

public:
	typedef sne::core::HashMap<QuestMissionCode, QuestKillMissionTemplate> QuestKillMissionMap;

public:
    virtual ~QuestKillMissionTable() {}

public:
    virtual const QuestKillMissionTemplate* getQuestKillMissionTemplate(QuestMissionCode code) const = 0;

    virtual const QuestKillMissionMap& getQuestKillMissionMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define QUEST_KILL_MISSION_TABLE gideon::datatable::QuestKillMissionTable::instance()
