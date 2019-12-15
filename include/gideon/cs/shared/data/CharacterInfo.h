#pragma once

#include "CreatureInfo.h"
#include "UserId.h"
#include "ZoneInfo.h"
#include "InventoryInfo.h"
#include "BankAccountInfo.h"
#include "AppearanceInfo.h"
#include "SkillInfo.h"
#include "EquipmentInfo.h"
#include "AccessoryInfo.h"
#include "CreatureStatusInfo.h"
#include "LevelInfo.h"
#include "ActionBar.h"
#include "CreatureStates.h"
#include "Money.h"
#include "QuestInfo.h"
#include "MercenaryInfo.h"
#include "ChaoInfo.h"
#include "GuildInfo.h"
#include "ArenaInfo.h"
#include "BindRecallInfo.h"
#include "CooldownInfo.h"
#include "GliderInfo.h"
#include "VehicleInfo.h"
#include "CharacterClass.h"
#include "SexType.h"
#include "CharacterTitleInfo.h"
#include "AchievementInfo.h"

namespace gideon {

/**
 * @enum ShardMaxCharacter
 */
enum ShardMaxCharacter
{
    maxShardCharacterCount = 3,
};


/**
 * @struct CharacterInfo
 * 캐릭터 기본 정보
 * - 관심 영역에서 캐릭터를 표시하기 위해 사용
 */
struct CharacterInfo : CreatureInfo
{
    CharacterClass characterClass_;
    Nickname nickname_;
    SexType sexType_;
    CharacterAppearance appearance_;
    Chaotic chaotic_;
    GuildId guildId_;
    bool isBeginnerProtection_;


    explicit CharacterInfo(ObjectId characterId = invalidObjectId) :
        CreatureInfo(otPc, characterId),
        characterClass_(ccUnknown),
        sexType_(stMale),
        chaotic_(minChaotic),
        guildId_(invalidGuildId),
        isBeginnerProtection_(false) {}

    void reset() {
        CreatureInfo::reset();
        characterClass_ = ccUnknown;
        nickname_.clear();
        sexType_ = stMale;
        appearance_.reset();
        chaotic_ = minChaotic;
        guildId_ = invalidGuildId;
        isBeginnerProtection_ = false;
    }

    bool isValid() const {
        return CreatureInfo::isValid() &&
            gideon::isValid(characterClass_) &&
            (! nickname_.empty()) && gideon::isValid(sexType_) &&
            appearance_.isValid();
    }

    void upChaotic(Chaotic chaotic) {
        chaotic_ = toChaotic(chaotic_ + chaotic);
        if (chaotic_ > maxChaotic) {
            chaotic_ = maxChaotic;
        }
    }

    void downChaotic(Chaotic chaotic) {
        chaotic_ = toChaotic(chaotic_ - chaotic);
        if (chaotic_ < minChaotic) {
            chaotic_ = minChaotic;
        }
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        CreatureInfo::serialize(stream);
        stream & characterClass_ & nickname_ & sexType_ & appearance_ & chaotic_ &
            guildId_ & isBeginnerProtection_;
    }
};

/**
* @struct CharacterArenaPlayResults
* 캐릭터 투기장 결과
*/
struct  CharacterArenaPlayResults
{
    ArenaModePlayResultMap resultMap_;
 
    void reset() {
        resultMap_.clear();
    }

    void updateResult(ArenaModeType mode, uint32_t score,
        ArenaResultType result) {
        ArenaPlayResult* playResult = getPlayResult(mode);
        if (playResult) {
            if (isWin(result)) {
                ++playResult->winCount_;
            }
            else if (isLose(result)) {
                ++playResult->loseCount_;
            }
            else {
                ++playResult->drawCount_;
            }
            playResult->score_ += score;
        }
        else {
            uint32_t win = isWin(result) ? 1 : 0;
            uint32_t lose = isLose(result) ? 1 : 0;
            uint32_t draw = isDraw(result) ? 1 : 0;
            ArenaPlayResult createPlayResult(score, 0, win, lose, draw);
            insertArena(mode, createPlayResult);
        }        
    }

    bool isExist(ArenaModeType mode) const {
        return getPlayResult(mode) != nullptr;
    }
    
    ArenaPlayResult* getPlayResult(ArenaModeType mode) {
        ArenaModePlayResultMap::iterator pos = resultMap_.find(mode);
        if (pos != resultMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    const ArenaPlayResult* getPlayResult(ArenaModeType mode) const {
        ArenaModePlayResultMap::const_iterator pos = resultMap_.find(mode);
        if (pos != resultMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    void insertArena(ArenaModeType mode, const ArenaPlayResult& result) {
        resultMap_.insert(ArenaModePlayResultMap::value_type(mode, result));
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & resultMap_;
    }
    
};



/**
* @struct FullCharacterInfo
* 캐릭터의 상세 정보
*/
struct FullCharacterInfo : CharacterInfo
{
    ZoneId zoneId_;

    CharacterTitleCode selectTitleCode_;
    EquipType selectEquipType_; // 최초 생성시 선택 무기(스킬 초기화때 필요함)
    SkillPoint sp_;
    ExpPoint exp_;
    ArenaPoint arenaPoint_;
    CurrentLevel currentLevel_;
    AchievementPoint achievementPoint_;

    InventoryInfo inventory_;
    BankAccountInfo bankAccountInfo_;
    QuestInventoryInfo questInventory_;

	CharacterEquipments equipments_;
    CreatureSkills skills_;
    CharacterActionBars actionBars_;
	
	GameMoney gameMoney_;
    EventCoin eventCoin_;
	ForgeCoin forgeCoin_;

	QuestCodes completedQuests_;
	AcceptedQuestInfos acceptedQuestInfos_;
    AcceptedRepeatQuestInfos acceptedRepeatQuestInfos_;
    CompletedRepeatQuestInfos completedRepeatQuestInfos_;
    
    CharacterArenaPlayResults arenaPlayResults_;

    CharacterAccessories characterAccessories_;
    BindRecallInfos bindRecallInfos_;

    sec_t deserterExpireTime_;

    uint8_t maxBindRecallCont_;
    CooltimeInfos cooltimeInfos_;
    RemainEffectInfos remainEffects_;

	VehicleInventory vehicleInventory_;
	GliderInventory gliderInventory_;
    
    FullCharacterInfo() :
        zoneId_(invalidZoneId),
        selectTitleCode_(invalidCharacterTitleCode),
        selectEquipType_(EquipType::etUnknown),
        sp_(spMin),
        exp_(ceMin),
        arenaPoint_(0),
		gameMoney_(gameMoneyMin),
        eventCoin_(eventCoinMin),
        forgeCoin_(forgeCoinMin),
        deserterExpireTime_(0),
        maxBindRecallCont_(0)
        {}

    FullCharacterInfo(const CharacterInfo& characterInfo) :
        CharacterInfo(characterInfo),
        zoneId_(invalidZoneId),
        selectTitleCode_(invalidCharacterTitleCode),
        sp_(spMin),
        exp_(ceMin),
        arenaPoint_(0),
        gameMoney_(gameMoneyMin),
        eventCoin_(eventCoinMin),
        forgeCoin_(forgeCoinMin),
        deserterExpireTime_(0),
        maxBindRecallCont_(0) {}

    void reset() {
        CharacterInfo::reset();
        selectTitleCode_ = invalidCharacterTitleCode;
        zoneId_ = invalidZoneId;
        sp_ = spMin;
        exp_ = ceMin;
        selectEquipType_ = EquipType::etUnknown;
        arenaPoint_ = 0;
        currentLevel_.reset();
        inventory_.reset();
		bankAccountInfo_.reset();
        questInventory_.reset();
        equipments_.reset();
        skills_.clear();
        actionBars_.reset();
        gameMoney_ = gameMoneyMin;
        eventCoin_ = eventCoinMin;
        forgeCoin_ = forgeCoinMin;
        completedQuests_.clear();
        acceptedQuestInfos_.clear();
        acceptedRepeatQuestInfos_.clear();
        completedRepeatQuestInfos_.clear();
        arenaPlayResults_.reset();
        characterAccessories_.reset();
        deserterExpireTime_ = 0;
        bindRecallInfos_.clear();
        maxBindRecallCont_ = 0;
        cooltimeInfos_.clear();
        remainEffects_.clear();
		vehicleInventory_.reset();
		gliderInventory_.reset();
    }

    bool operator==(const FullCharacterInfo& rhs) const {
        return objectId_ == rhs.objectId_;
    }

    bool isEquipped(EquipPart part) const {
        assert(gideon::isValid(part));
        return isValidObjectId(equipments_[part]);
    }

    bool isValid() const {
        return CharacterInfo::isValid() && gideon::isValid(selectEquipType_) &&
            gideon::isValid(sp_) && gideon::isValid(exp_) &&
            currentLevel_.isValid() &&
            isValidInventory() && equipments_.isValid() &&
            gideon::isValid(skills_);
    }

    AccessoryIndex getAccessoryIndex(ObjectId itemId) const {
        for (int i = 0; i <  aiCount; ++i) {
            if (characterAccessories_[i] == itemId) {
                return toAccessoryIndex(i);
            }
        }
        return aiInvalid;
    }

	void upGameMoney(GameMoney gameMoney) {
		gameMoney_ += gameMoney;
	}    

	void downGameMoney(GameMoney gameMoney) {
		if (gameMoney_ > gameMoney) {
			gameMoney_ -= gameMoney;
		}
		else {
			gameMoney_ = gameMoneyMin;
		}
	}

    void upAchievementPoint(AchievementPoint point) {
        achievementPoint_ += point;
    }

	void upForgeCoin(ForgeCoin forgeCoin) {
		forgeCoin_ += forgeCoin;
	}    

	void downForgeCoin(ForgeCoin forgeCoin) {
		if (forgeCoin_ > forgeCoin) {
			forgeCoin_ -= forgeCoin;
		}
		else {
			forgeCoin_ = forgeCoinMin;
		}
	}

    void upArenaPoint(ArenaPoint arenaPoint) {
        arenaPoint_ += arenaPoint;
    }

    void downArenaPoint(ArenaPoint arenaPoint) {
        if (arenaPoint_ > arenaPoint) {
            arenaPoint_ -= arenaPoint;
        }
        else {
            arenaPoint_ = 0;
        }
    }

    SkillPoint getRewardedSkillPoint() const {
        return toSkillPoint(((currentLevel_.level_ - 1) * spOneCreatureLevelSkillPoint) + 
            (currentLevel_.levelStep_ * spLevelStepupRewardPoint)) ;
    }

    void upEventCoin(EventCoin eventCoin) {
        eventCoin_ += eventCoin;
    }

    void downEventCoin(EventCoin eventCoin) {
        if (eventCoin_ > eventCoin) {
            eventCoin_ -= eventCoin;
        }
        else {
            eventCoin_ = 0;
        }
    }

    bool hasCooltime(DataCode code) {
        for (const CooltimeInfo& info : cooltimeInfos_) {
            if (info.dataCode_ == code) {
                return true;
            }
        }
        return false;
    }


    const BindRecallInfo* getBindRecallInfo(ObjectId linkId) const {
        for (const BindRecallInfo& bindRecallInfo : bindRecallInfos_) {
            if (bindRecallInfo.linkId_ == linkId) {
                return &bindRecallInfo;
            }
        }
        return nullptr;
    }

    void removeBindRecall(ObjectId bindRecallId) {
        BindRecallInfos::iterator pos = bindRecallInfos_.begin();
        BindRecallInfos::iterator end = bindRecallInfos_.end();
        for (; pos != end; ++pos) {
            BindRecallInfo& info = (*pos);
            if (info.linkId_ == bindRecallId) {
                bindRecallInfos_.erase(pos);
                return;
            }
        }
    }

    sec_t getRepeatQuestAcceptTime(QuestCode questCode) const {
        AcceptedRepeatQuestInfos::const_iterator pos = acceptedRepeatQuestInfos_.begin();
        AcceptedRepeatQuestInfos::const_iterator end = acceptedRepeatQuestInfos_.end();
        for (; pos != end; ++pos) {
            const AcceptedRepeatQuestInfo& quest = (*pos);
            if (quest.questCode_ == questCode) {
                return quest.acceptTime_;
            }			
        }
        return 0;
    }

	bool isAcceptedQuest(QuestCode questCode) const {
		AcceptedQuestInfos::const_iterator pos = acceptedQuestInfos_.begin();
		AcceptedQuestInfos::const_iterator end = acceptedQuestInfos_.end();
		for (; pos != end; ++pos) {
			const AcceptedQuestInfo& quest = (*pos);
			if (quest.questCode_ == questCode) {
				return true;
			}			
		}
		return false;
	}

    bool isAcceptRepeatQuest(QuestCode questCode) const {
        AcceptedRepeatQuestInfos::const_iterator pos = acceptedRepeatQuestInfos_.begin();
        AcceptedRepeatQuestInfos::const_iterator end = acceptedRepeatQuestInfos_.end();
        for (; pos != end; ++pos) {
            const AcceptedRepeatQuestInfo& quest = (*pos);
            if (quest.questCode_ == questCode) {
                return true;
            }			
        }
        return false;
    }

	void removeQuest(QuestCode questCode) {
		AcceptedQuestInfos::iterator pos = acceptedQuestInfos_.begin();
		const AcceptedQuestInfos::iterator end = acceptedQuestInfos_.end();
		for (; pos != end; ++pos) {
			const AcceptedQuestInfo& quest = (*pos);
			if (quest.questCode_ == questCode) {
				acceptedQuestInfos_.erase(pos);
				return;
			}			
		}
	}

    void removeRepeatQuest(QuestCode questCode) {
        AcceptedRepeatQuestInfos::iterator pos = acceptedRepeatQuestInfos_.begin();
        const AcceptedRepeatQuestInfos::iterator end = acceptedRepeatQuestInfos_.end();
        for (; pos != end; ++pos) {
            const AcceptedRepeatQuestInfo& quest = (*pos);
            if (quest.questCode_ == questCode) {
                acceptedRepeatQuestInfos_.erase(pos);
                return;
            }			
        }
    }

    void removeCompleteRepeatQuest(QuestCode questCode) {
        const CompletedRepeatQuestInfos::iterator pos =
            completedRepeatQuestInfos_.find(CompletedRepeatQuestInfo(questCode));
        if (pos != completedRepeatQuestInfos_.end()) {
            completedRepeatQuestInfos_.erase(pos);
        }
    }

	bool hasQuestGoalMission(QuestCode questCode, QuestMissionCode missionCode,
		const QuestGoalInfo& goalInfo) const {
		AcceptedQuestInfos::const_iterator pos = acceptedQuestInfos_.begin();
		const AcceptedQuestInfos::const_iterator end = acceptedQuestInfos_.end();
		for (; pos != end; ++pos) {
			const AcceptedQuestInfo& quest = (*pos);
			if (quest.questCode_ == questCode) {
				QuestGoalInfosMap::const_iterator mPos = quest.questGoalInfosMap_.find(missionCode);
				if (mPos != quest.questGoalInfosMap_.end()) {
					const QuestGoalInfos& goalInfos = (*mPos).second;
					for (const QuestGoalInfo& questGoalInfo : goalInfos) {
						if (goalInfo.goalCode_ == questGoalInfo.goalCode_) {
							return true;
						}
					}
				}
				return false;
			}			
		}
		return false;
	}

    bool hasRepeatQuestGoalMission(QuestCode questCode, QuestMissionCode missionCode,
        const QuestGoalInfo& goalInfo) const {
        AcceptedRepeatQuestInfos::const_iterator pos = acceptedRepeatQuestInfos_.begin();
        const AcceptedRepeatQuestInfos::const_iterator end = acceptedRepeatQuestInfos_.end();
        for (; pos != end; ++pos) {
            const AcceptedRepeatQuestInfo& quest = (*pos);
            if (quest.questCode_ == questCode) {
                QuestGoalInfosMap::const_iterator mPos = quest.questGoalInfosMap_.find(missionCode);
                if (mPos != quest.questGoalInfosMap_.end()) {
                    const QuestGoalInfos& goalInfos = (*mPos).second;
                    for (const QuestGoalInfo& questGoalInfo : goalInfos) {
                        if (goalInfo.goalCode_ == questGoalInfo.goalCode_) {
                            return true;
                        }
                    }
                }
                return false;
            }			
        }
        return false;
    }

	void updateQuestGoalMission(QuestCode questCode, QuestMissionCode missionCode,
		const QuestGoalInfo& goalInfo) {
		AcceptedQuestInfos::iterator pos = acceptedQuestInfos_.begin();
		const AcceptedQuestInfos::const_iterator end = acceptedQuestInfos_.end();
		for (; pos != end; ++pos) {
			AcceptedQuestInfo& quest = (*pos);
			if (quest.questCode_ == questCode) {
				QuestGoalInfosMap::iterator mPos = quest.questGoalInfosMap_.find(missionCode);
				if (mPos != quest.questGoalInfosMap_.end()) {					
					QuestGoalInfos& goalInfos = (*mPos).second;
					for (QuestGoalInfo& questGoalInfo : goalInfos) {
						if (goalInfo.goalCode_ == questGoalInfo.goalCode_) {
							questGoalInfo = goalInfo;
							return;
						}
					}
					goalInfos.push_back(goalInfo);
					return;
				}
				else {
					QuestGoalInfos infos;
					infos.push_back(goalInfo);
					quest.questGoalInfosMap_.insert(
                        QuestGoalInfosMap::value_type(missionCode, infos));
					return;
				}
			}			
		}
	}

    void updateRepeatQuestGoalMission(QuestCode questCode, QuestMissionCode missionCode,
        const QuestGoalInfo& goalInfo) {
        AcceptedRepeatQuestInfos::iterator pos = acceptedRepeatQuestInfos_.begin();
        const AcceptedRepeatQuestInfos::iterator end = acceptedRepeatQuestInfos_.end();
        for (; pos != end; ++pos) {
            AcceptedRepeatQuestInfo& quest = (*pos);
            if (quest.questCode_ == questCode) {
                const QuestGoalInfosMap::iterator mPos = quest.questGoalInfosMap_.find(missionCode);
                if (mPos != quest.questGoalInfosMap_.end()) {					
                    QuestGoalInfos& goalInfos = (*mPos).second;
                    for (QuestGoalInfo& questGoalInfo : goalInfos) {
                        if (goalInfo.goalCode_ == questGoalInfo.goalCode_) {
                            questGoalInfo = goalInfo;
                            return;
                        }
                    }
                    goalInfos.push_back(goalInfo);
                    return;
                }
                else {
                    QuestGoalInfos infos;
                    infos.push_back(goalInfo);
                    quest.questGoalInfosMap_.insert(
                        QuestGoalInfosMap::value_type(missionCode, infos));
                    return;
                }
            }			
        }
    }

    bool isValidInventory() const {
        // TODO: equipments_에 있는 아이템이 inventory_에 있는지 검사한다
        return true;
    }

    ItemInfo* getItemInfo(ObjectId itemId)  {
        ItemInfo* itemInfo = inventory_.getItemInfo(itemId);
        if (! itemInfo) {
            itemInfo = bankAccountInfo_.getItemInfo(itemId);
        }
        if (! itemInfo) {
            itemInfo = vehicleInventory_.inventory_.getItemInfo(itemId);
        }
        return itemInfo;
    }

    const ItemInfo* getItemInfo(ObjectId itemId)  const {
        const ItemInfo* itemInfo = inventory_.getItemInfo(itemId);
        if (! itemInfo) {
            itemInfo = bankAccountInfo_.getItemInfo(itemId);
        }
        if (! itemInfo) {
            itemInfo = vehicleInventory_.inventory_.getItemInfo(itemId);
        }
        return itemInfo;
    }

    bool addItem(InvenType invenType, const ItemInfo& itemInfo)
    {
        if (itPc == invenType) {
            inventory_.addItem(itemInfo);
        }
        else if (itBank == invenType) {
            bankAccountInfo_.addItem(itemInfo);
        }
        else if (itVehicle == invenType) {
            vehicleInventory_.inventory_.addItem(itemInfo);
        }
        else {
            return false;
        }
        return true;
    }
    
    template <typename Stream>
    void serialize(Stream& stream) {
        CharacterInfo::serialize(stream);
        stream & zoneId_ & selectTitleCode_ & selectEquipType_ & sp_ & exp_ & arenaPoint_ & currentLevel_ & achievementPoint_ &
            inventory_ & bankAccountInfo_ & equipments_ & skills_ & 
            actionBars_ & gameMoney_ & eventCoin_ & forgeCoin_ & completedQuests_ & acceptedQuestInfos_ &
            questInventory_  & acceptedRepeatQuestInfos_ & completedRepeatQuestInfos_ & arenaPlayResults_ &
            characterAccessories_ & deserterExpireTime_ & maxBindRecallCont_ & bindRecallInfos_ & 
			cooltimeInfos_ & remainEffects_ & vehicleInventory_ & gliderInventory_;
    }
};


typedef sne::srpc::RHashMap<ObjectId, FullCharacterInfo> FullCharacterInfos;

} // namespace gideon {


namespace sne { namespace core {


inline OStream& operator<<(OStream& lhs, gideon::ExpPoint rhs)
{
    lhs << static_cast<uint32_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::ExpPoint& rhs)
{
    uint32_t value;
    lhs >> value;
    rhs = static_cast<gideon::ExpPoint>(value);
    return lhs;
}


inline OStream& operator<<(OStream& lhs, gideon::SkillPoint rhs)
{
    lhs << static_cast<uint16_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::SkillPoint& rhs)
{
    uint16_t value;
    lhs >> value;
    rhs = static_cast<gideon::SkillPoint>(value);
    return lhs;
}


}} // namespace sne { namespace core {
