#pragma once

#include <gideon/cs/shared/data/QuestInfo.h>
#include <gideon/cs/datatable/template/quest_probe_mission_table.hxx>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>


namespace gideon { namespace datatable {

/**
 * @class QuestProbeMissionTemplate
 *
 */
class QuestProbeMissionTemplate
{
public:
	QuestProbeMissionTemplate(const gdt::quest_probe_mission_t& mission) :
		missionCode_(mission.mission_code())
	{
        initMarkerCodes(mission);
	}

    const DataCodes& getMarkerCodes() const {
        return markerCodes_;
    }

    const QuestMissionCode getMissionCode() const {
        return missionCode_;
    }

private:

    void initMarkerCodes(const gdt::quest_probe_mission_t& mission) {
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
    DataCodes markerCodes_;
};

/**
 * @class QuestProbeMissionTable
 *
 */
class GIDEON_CS_API QuestProbeMissionTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(QuestProbeMissionTable);

public:
    typedef sne::core::HashMap<QuestMissionCode, QuestProbeMissionTemplate> QuestProbeMissionMap;

public:
    virtual ~QuestProbeMissionTable() {}

    virtual const QuestProbeMissionTemplate* getQuestProbeMission(QuestMissionCode code) const = 0;

    virtual const QuestProbeMissionMap& getQuestProbeMissionMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;

};

}} // namespace gideon { namespace datatable {

#define QUEST_PROBE_MISSION_TABLE gideon::datatable::QuestProbeMissionTable::instance()
