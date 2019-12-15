#pragma once

#include <gideon/cs/shared/data/DeviceInfo.h>
#include <gideon/cs/datatable/template/quest_activation_mission_table.hxx>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @struct QuestActivationGoalInfo
 *
 */
struct QuestActivationGoalInfo : QuestGoalInfo
{
    explicit QuestActivationGoalInfo(DataCode dataCode = invalidDataCode,
        uint32_t activationCount = 0) :
        QuestGoalInfo(dataCode, activationCount) {}

    bool isValid() const {
        return QuestGoalInfo::isValid() && isAllowedDataCode(goalCode_);
    }

private:
    bool isAllowedDataCode(DataCode dataCode) const {
        if (! isValidDataCode(dataCode)) {
            return false;
        }
        const gideon::CodeType codeType = getCodeType(dataCode);
        if ((codeType == ctDevice) || (codeType == ctQuestItem)) {
            return true;
        }
        assert(false);
        return false;
    }
};


/**
 * @class QuestActivationMissionTemplate
 *
 */
class QuestActivationMissionTemplate
{
public:
	QuestActivationMissionTemplate(const gdt::quest_activation_mission_t& mission) :
        availableMapCode_(mission.map_code()),
        availableRegionCode_(mission.region_code()),
		missionCode_(mission.mission_code()) {
		initMissionGoal(mission);
        initMarkerCodes(mission);
	}
	
	const QuestActivationGoalInfo& getGoalInfo() const {
		return questActivationGoalInfo_;
	}

    MapCode getAvailableMapCode() const {
        return availableMapCode_;
    }

    RegionCode getAvailableRegionCode() const {
        return availableRegionCode_;
    }

    const DataCodes& getMarkerCodes() const {
        return markerCodes_;
    }

private:
	void initMissionGoal(const gdt::quest_activation_mission_t& mission) {
		questActivationGoalInfo_ = QuestActivationGoalInfo(mission.goal_info(), mission.goal_value());
        assert(questActivationGoalInfo_.isValid());
	}

    void initMarkerCodes(const gdt::quest_activation_mission_t& mission) {
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
    MapCode availableMapCode_;
    RegionCode availableRegionCode_;
	QuestMissionCode missionCode_;
	QuestActivationGoalInfo questActivationGoalInfo_;
    DataCodes markerCodes_;
};



/**
 * @class QuestActivationMissionTable
 *
 */
class GIDEON_CS_API QuestActivationMissionTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(QuestActivationMissionTable);

public:
	typedef sne::core::HashMap<QuestMissionCode, QuestActivationMissionTemplate> QuestActivationMissionMap;

public:
    virtual ~QuestActivationMissionTable() {}

public:
    virtual const QuestActivationMissionTemplate* getQuestActivationMissionTemplate(QuestMissionCode code) const = 0;

    virtual const QuestActivationMissionMap& getQuestQuestActivationMissionMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define QUEST_ACTIVATION_MISSION_TABLE gideon::datatable::QuestActivationMissionTable::instance()
