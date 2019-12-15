#pragma once

#include <gideon/cs/shared/data/ItemInfo.h>
#include <gideon/cs/shared/data/QuestInfo.h>
#include <gideon/cs/shared/data/NpcInfo.h>
#include <gideon/cs/shared/data/SkillInfo.h>
#include <gideon/cs/shared/data/RegionInfo.h>
#include <gideon/cs/datatable/template/quest_table.hxx>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {


typedef sne::core::Vector<QuestMissionCode> QuestMissionCodes;

/**
 * @class QuestRemunerationInfo
 * 보상 정보
 */
struct QuestRemunerationInfo
{
	QuestRemunerationKind kind_;
	DataCode remunerationCode_;
	uint32_t remunerationValue_;


	QuestRemunerationInfo(QuestRemunerationKind kind,
		DataCode remunerationCode, uint32_t remunerationValue) :
		kind_(kind),
		remunerationCode_(remunerationCode),
		remunerationValue_(remunerationValue)
	{}

};

typedef sne::core::Vector<QuestRemunerationInfo> QuestRemunerationInfos;

/**
 * @class IssueSpecialConditionInfo
 * 보상 정보
 */
struct IssueSpecialConditionInfo
{
    QuestIssueSpecialCondition condition_;
    uint32_t info_;
    uint32_t value_;

    IssueSpecialConditionInfo(QuestIssueSpecialCondition condition,
        uint32_t info = 0, uint32_t value = 0) :
        condition_(condition),
        info_(info),
        value_(value)
    {}

    bool shoudRemoveItem() const {
        return condition_ == qiscRemoveInvenItem || condition_ == qiscRemoveQuestItem;
    }
};


typedef sne::core::Vector<IssueSpecialConditionInfo> IssueSpecialConditionInfos;


/**
 * @class QuestTable
 *
 */
class QuestTemplate
{
public:
	QuestTemplate(const gdt::quest_t& questInfo) :
		questInfo_(&questInfo),
		questCode_(questInfo.quest_code()),
		issueCondition_(static_cast<QuestIssueCondition>(static_cast<uint8_t>(questInfo.issue_condition()))),
		issConditionCode_(questInfo.issue_info()),
        completeNpcCode_(questInfo.complete_npc()) ,
        isPartyQuest_(questInfo.is_party_quest()),
        isRepeatQuest_(questInfo.is_repeat_quest())
	{
        initIssueSpecialConditions();
		initRemunerationInfos();
		initMissions();
        initSelectRemunerationItemInfos();
	}

	const QuestMissionCodes& getMissionCodes() const {
		return questMissionCodes_;
	}

	const QuestRemunerationInfos& getQuestRemunerationInfos() const {
		return questRemunerationInfos_;
	}

	~QuestTemplate() {
	}

    NpcCode getCompleteNpcCode() const {
        return completeNpcCode_;
    }

    bool isPartyQuest() const {
        return isPartyQuest_;
    }

    bool isRepeatQuest() const {
        return isRepeatQuest_;
    }

	QuestCode getQuestCode() const {
		return questCode_;
	}

    uint32_t getTalkCode() const {
        return questInfo_->talk_code();
    }

    bool isShareable() const {
        return questInfo_->is_shareable() != 0;
    }

    CreatureLevel getIssueLevel() const {
        return toCreatureLevel(questInfo_->issue_level());
    }

	QuestIssueCondition getIssueCondition() const {
		return issueCondition_;
	}

    const IssueSpecialConditionInfos& getIssueSpecialConditionInfos() const {
        return specialConditions_;
    }
 
	DataCode getIssConditionCode() const {
		return issConditionCode_;
	}    

    const gdt::quest_t* getQuestInfo() const {
	  return questInfo_;
	}

    const DataCodes& getSelectItems() const {
        return questSelectDataCodes_;
    }

	//const DataCode getRewardUpdateEquipCode() const {
	//	if (questSelectDataCodes_.size() != 1) {
	//		return invalidDataCode;
	//	}
	//	DataCode dataCode = questSelectDataCodes_[0];
	//	return isQuestUpgradeEquipType(getCodeType(dataCode)) ? dataCode : invalidDataCode;
	//}

    const BaseItemInfo* getSelectItem(DataCode itemCode) const {
        for (const BaseItemInfo& item : questSelectRemunerationItems_) {
            if (item.itemCode_ == itemCode) {
                return &item;
            }
        }
        return nullptr;
    }

    SkillCode getSelectSkill(DataCode skillCode) const {
        for (DataCode selectSkillCode : questSelectDataCodes_) {
            if (selectSkillCode == skillCode) {
                return selectSkillCode;
            }
        }
        return invalidSkillCode;
    }

	bool hasAnyMissionCodes() const {
	  for (const QuestMissionCode missionCode :questMissionCodes_)
		 if(missionCode != invalidQuestMissionCode)
			return true;

	  return false;
	}

    bool isAllTransportMission() const {
        bool isNotTransportMission = false;
        for (QuestMissionCode missionCode : questMissionCodes_) {
            const QuestMissionType missionType = getQuestMissionType(missionCode);
            if (isTransportMission( missionType ) && missionCode != invalidQuestMissionCode) {
                isNotTransportMission = true;
            }
            else if (! isTransportMission( missionType ) && missionCode != invalidQuestMissionCode) {
                isNotTransportMission = false;
            }
        }

        return isNotTransportMission;
    }


    bool hasContentsMission() const {
        for (QuestMissionCode missionCode : questMissionCodes_) {
            const QuestMissionType missionType = getQuestMissionType(missionCode);
            if (isContentMission(missionType) ) {
                return true;
            }
        }

        return false;
    }

    MapCode getMapCode() const {
        return questInfo_->map_code();
    }

    RegionCode getRegionCode() const {
        return questInfo_->region_code();
    }

public:
	void deleteQuestInfo() {
		if (questInfo_) {
			delete questInfo_;
		}
	}

private:
    void initIssueSpecialConditions() {
        QuestIssueSpecialCondition condition1 = toQuestIssueSpecialCondition(questInfo_->issue_special_condition_1());
        if (hasCondition(condition1)) {
            specialConditions_.push_back(IssueSpecialConditionInfo(condition1, questInfo_->special_condition_info_1(),
                questInfo_->special_condition_value_1()));
        }
        QuestIssueSpecialCondition condition2 = toQuestIssueSpecialCondition(questInfo_->issue_special_condition_2());
        if (hasCondition(condition2)) {
            specialConditions_.push_back(IssueSpecialConditionInfo(condition2, questInfo_->special_condition_info_2(),
                questInfo_->special_condition_value_2()));
        }
    }
	void initRemunerationInfos() {
		const QuestRemunerationKind kind1 = static_cast<QuestRemunerationKind>(questInfo_->remuneration_kind_1());
		if (isValid(kind1)) {
			DataCode dataCode = questInfo_->remuneration_info_1();
			uint32_t value = questInfo_->remuneration_value_1();
			questRemunerationInfos_.push_back(QuestRemunerationInfo(kind1, dataCode, value));
		}

		const QuestRemunerationKind kind2 = static_cast<QuestRemunerationKind>(questInfo_->remuneration_kind_2());
		if (isValid(kind2)) {
			DataCode dataCode = questInfo_->remuneration_info_2();
			uint32_t value = questInfo_->remuneration_value_2();
			questRemunerationInfos_.push_back(QuestRemunerationInfo(kind2, dataCode, value));
		}

		const QuestRemunerationKind kind3 = static_cast<QuestRemunerationKind>(questInfo_->remuneration_kind_3());
		if (isValid(kind3)) {
			DataCode dataCode = questInfo_->remuneration_info_3();
			uint32_t value = questInfo_->remuneration_value_3();
			questRemunerationInfos_.push_back(QuestRemunerationInfo(kind3, dataCode, value));
		}
	}

    void initSelectRemunerationItemInfos() {        
        DataCode dataCode1 = questInfo_->select_remuneration_item_code_1();
        if (isValidDataCode(dataCode1)) {
            if (isItemType(getCodeType(dataCode1))) {
                uint8_t value = questInfo_->select_remuneration_item_value_1();
                questSelectRemunerationItems_.push_back(BaseItemInfo(dataCode1, value));
            }

            questSelectDataCodes_.push_back(dataCode1);
        }
        DataCode dataCode2 = questInfo_->select_remuneration_item_code_2();
        if (isValidDataCode(dataCode2)) {
            if (isItemType(getCodeType(dataCode2))) {
                uint8_t value = questInfo_->select_remuneration_item_value_2();
                questSelectRemunerationItems_.push_back(BaseItemInfo(dataCode2, value));
            }

            questSelectDataCodes_.push_back(dataCode2);
        }
        DataCode dataCode3 = questInfo_->select_remuneration_item_code_3();
        if (isValidDataCode(dataCode3)) {
            if (isItemType(getCodeType(dataCode3))) {
                uint8_t value = questInfo_->select_remuneration_item_value_3();
                questSelectRemunerationItems_.push_back(BaseItemInfo(dataCode3, value));
            }

            questSelectDataCodes_.push_back(dataCode3);
        }
        DataCode dataCode4 = questInfo_->select_remuneration_item_code_4();
        if (isValidDataCode(dataCode4)) {
            if (isItemType(getCodeType(dataCode4))) {
                uint8_t value = questInfo_->select_remuneration_item_value_4();
                questSelectRemunerationItems_.push_back(BaseItemInfo(dataCode4, value));
            }

            questSelectDataCodes_.push_back(dataCode4);
        }
        DataCode dataCode5 = questInfo_->select_remuneration_item_code_5();
        if (isValidDataCode(dataCode5)) {
            if (isItemType(getCodeType(dataCode5))) {
                uint8_t value = questInfo_->select_remuneration_item_value_5();
                questSelectRemunerationItems_.push_back(BaseItemInfo(dataCode5, value));
            }

            questSelectDataCodes_.push_back(dataCode5);
        }
    }


	void initMissions() {
		const QuestMissionCode missionCode1 = questInfo_->mission_code_1();
		if (isValidQuestMissionCode(missionCode1)) {
			questMissionCodes_.push_back(missionCode1);
		}

		const QuestMissionCode missionCode2 = questInfo_->mission_code_2();
		if (isValidQuestMissionCode(missionCode2)) {
			questMissionCodes_.push_back(missionCode2);
		}

		const QuestMissionCode missionCode3 = questInfo_->mission_code_3();
		if (isValidQuestMissionCode(missionCode3)) {
			questMissionCodes_.push_back(missionCode3);
		}
	}

private:
	const gdt::quest_t* questInfo_;
	QuestCode questCode_;
	QuestIssueCondition issueCondition_;
	DataCode issConditionCode_;
    IssueSpecialConditionInfos specialConditions_;
	NpcCode completeNpcCode_;
	QuestRemunerationInfos questRemunerationInfos_;
	QuestMissionCodes questMissionCodes_;
    BaseItemInfos questSelectRemunerationItems_;
    DataCodes questSelectDataCodes_;
    bool isPartyQuest_;
    bool isRepeatQuest_;
};


/**
 * @class QuestTable
 *
 */
class GIDEON_CS_API QuestTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(QuestTable);

public:
	typedef sne::core::HashMap<QuestCode, QuestTemplate> QuestMap;

public:
    virtual ~QuestTable() {}

public:
    virtual const QuestTemplate* getQuestTemplate(QuestCode code) const = 0;

    virtual const QuestMap& getQuestMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define QUEST_TABLE gideon::datatable::QuestTable::instance()
