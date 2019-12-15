#pragma once

#include <gideon/cs/shared/data/QuestInfo.h>
#include <gideon/cs/shared/data/WorldInfo.h>
#include <gideon/cs/shared/data/Coordinate.h>
#include <gideon/cs/datatable/template/quest_transport_mission_table.hxx>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @struct QuestMissionTransportGoalInfo
 *
 */
struct QuestMissionTransportGoalInfo
{
	QuestGoalType goalType_;
	DataCode goalCode_; // current NpcCode
    Position goalPosition_;
    MapCode mapCode_;
	QuestItemCode questItemCode_;

	QuestMissionTransportGoalInfo(QuestGoalType goalType = qgtUnknown,
		DataCode goalCode = invalidDataCode, const Position& goalPosition = Position(),
        MapCode mapCode = invalidMapCode, QuestItemCode issueItem = invalidQuestItemCode) :
		goalType_(goalType),
		goalCode_(goalCode),
		goalPosition_(goalPosition),
        mapCode_(mapCode),
        questItemCode_(issueItem)
	{
	}
};

typedef sne::core::Vector<QuestMissionTransportGoalInfo> QuestMissionTransportGoalInfos;


/**
 * @class QuestTransportMissionTemplate
 *
 */
class QuestTransportMissionTemplate
{
public:
	QuestTransportMissionTemplate(const gdt::quest_transport_mission_t& mission) :
		missionCode_(mission.mission_code())
	{
		initMissionGoal(mission);
        initMarkerCodes(mission);
	}
	
	const QuestMissionTransportGoalInfo& getQuestMissionTransportGoalInfo() const {
		return questMissionTransportGoalInfo_;
	}

    const DataCodes& getMarkerCodes() const {
        return markerCodes_;
    }

private:
	void initMissionGoal(const gdt::quest_transport_mission_t& mission) {
		const QuestGoalType goal =  toQuestGoalType(mission.goal());
		if (isValid(goal)) {
            Position position;
            uint32_t value = 0;
            if (isPostionTransport(goal)) {
                 const gdt::float_list_t& goalPosition = mission.goal_position();
                position.x_ = goalPosition[0];
                position.y_ = goalPosition[1];
                position.z_ = goalPosition[2];
            }
            else {
                value = static_cast<uint32_t>(mission.goal_info());
            }

            questMissionTransportGoalInfo_ = QuestMissionTransportGoalInfo(
                goal, value, position, mission.map_code(), mission.issue_item_code());
		}
	}

    void initMarkerCodes(const gdt::quest_transport_mission_t& mission) {
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
	QuestMissionTransportGoalInfo questMissionTransportGoalInfo_;
    DataCodes markerCodes_;
};



/**
 * @class QuestTransportMissionTable
 *
 */
class GIDEON_CS_API QuestTransportMissionTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(QuestTransportMissionTable);

public:
	typedef sne::core::HashMap<QuestCode, QuestTransportMissionTemplate> QuestTransportMissionMap;

public:
    virtual ~QuestTransportMissionTable() {}

public:
    virtual const QuestTransportMissionTemplate* getQuestTransportMissionTemplate(QuestMissionCode code) const = 0;

    virtual const QuestTransportMissionMap& getQuestTransportMissionMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define QUEST_TRANSPORT_MISSION_TABLE gideon::datatable::QuestTransportMissionTable::instance()
