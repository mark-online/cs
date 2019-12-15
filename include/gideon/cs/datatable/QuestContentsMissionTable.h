#pragma once

#include <gideon/cs/datatable/template/quest_contents_mission_table.hxx>
#include <gideon/cs/shared/data/QuestInfo.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>


namespace gideon { namespace datatable {


struct QuestContentsGoalInfo : public QuestGoalInfo
{
    QuestContentMissionType contentMissionType_;

    explicit QuestContentsGoalInfo(QuestContentMissionType contentMissionType = qcmtUnknown,
        DataCode dataCode = invalidDataCode, uint32_t activationCount = 0) :
        QuestGoalInfo(dataCode, activationCount),
        contentMissionType_(contentMissionType) {}
};

/**
 * @class QuestContentMissionTemplate
 *
 */
class QuestContentMissionTemplate
{
public:
	QuestContentMissionTemplate(const gdt::quest_contents_mission_t& mission) :
		missionCode_(mission.mission_code()),
        questContentsGoalInfo_(toQuestContentMissionType(mission.quest_contents_type()),
            mission.info(), mission.value())
    {
        initMarkerCodes(mission);
	}
	
	const QuestContentsGoalInfo& getGoalInfo() const {
		return questContentsGoalInfo_;
	}

    const DataCodes& getMarkerCodes() const {
        return markerCodes_;
    }

private:
    void initMarkerCodes(const gdt::quest_contents_mission_t& mission) {
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
    QuestContentsGoalInfo questContentsGoalInfo_;
    DataCodes markerCodes_;
};


/**
 * @class QuestContentsMissionTable
 *
 */
class GIDEON_CS_API QuestContentsMissionTable : public boost::noncopyable
{
public:
	SNE_DECLARE_SINGLETON(QuestContentsMissionTable);

public:
    typedef sne::core::HashMap<QuestMissionCode, QuestContentMissionTemplate> QuestContentsMissionMap;

public:
    virtual ~QuestContentsMissionTable() {}

public:										 
    virtual const QuestContentMissionTemplate* getQuestContentsMission(QuestMissionCode code) const = 0;

    virtual const QuestContentsMissionMap& getQuestContentsMissionMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define QUEST_CONTENTS_MISSION_TABLE gideon::datatable::QuestContentsMissionTable::instance()