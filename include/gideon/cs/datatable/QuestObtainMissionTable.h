#pragma once

#include <gideon/cs/datatable/template/quest_obtain_mission_table.hxx>
#include <gideon/cs/shared/data/QuestInfo.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @struct QuestMissionObtainGoalInfo
 *
 */
struct QuestMissionObtainGoalInfo : QuestGoalInfo
{
	QuestGoalType goalType_;

    explicit QuestMissionObtainGoalInfo(QuestGoalType goalType = qgtUnknown,
        DataCode goalCode = invalidDataCode, uint32_t goalValue = 0) :
        QuestGoalInfo(goalCode, goalValue),
		goalType_(goalType) {}

    bool isValid() const {
        return QuestGoalInfo::isValid() && isObtainType(goalType_);
    }
};


/**
 * @class QuestObtainMissionTemplate
 *
 */
class QuestObtainMissionTemplate
{
public:
	QuestObtainMissionTemplate(const gdt::quest_obtain_mission_t& mission) :
		missionCode_(mission.mission_code()) {
		initMissionGoal(mission);
        initMarkerCodes(mission);
	}
	
	const QuestMissionObtainGoalInfo& getGoalInfo() const {
		return questMissionObtainGoalInfo_;
	}

    const DataCodes& getMarkerCodes() const {
        return markerCodes_;
    }

private:
	void initMissionGoal(const gdt::quest_obtain_mission_t& mission) {
		questMissionObtainGoalInfo_ = QuestMissionObtainGoalInfo(
            static_cast<QuestGoalType>(mission.goal()), mission.goal_info(), mission.goal_value());
        assert(questMissionObtainGoalInfo_.isValid());
	}

    void initMarkerCodes(const gdt::quest_obtain_mission_t& mission) {
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
	QuestMissionObtainGoalInfo questMissionObtainGoalInfo_;
    DataCodes markerCodes_;
};



/**
 * @class QuestObtainMissionTable
 *
 */
class GIDEON_CS_API QuestObtainMissionTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(QuestObtainMissionTable);

public:
	typedef sne::core::HashMap<QuestMissionCode, QuestObtainMissionTemplate> QuestObtainMissionMap;

public:
    virtual ~QuestObtainMissionTable() {}

public:
    virtual const QuestObtainMissionTemplate* getQuestObtainMissionTemplate(QuestMissionCode code) const = 0;

    virtual const QuestObtainMissionMap& getQuestObtainMissionMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define QUEST_OBTAIN_MISSION_TABLE gideon::datatable::QuestObtainMissionTable::instance()
