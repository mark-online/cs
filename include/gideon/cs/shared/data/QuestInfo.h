#pragma once

#include "ObjectInfo.h"
#include "Code.h"
#include "Time.h"
#include "NpcInfo.h"
#include "EquipmentInfo.h"
#include <sne/srpc/RpcContainers.h>

namespace gideon {


/// QuestCode.
typedef DataCode QuestCode;
const QuestCode invalidQuestCode = 0;

const uint32_t maxAcceptQuestCount = 15;

/// is valid QuestCode
inline bool isValidQuestCode(QuestCode code)
{
	return getCodeType(code) == ctQuest;
}


/// QuestCode를 만든다
inline QuestCode makeQuestCode(uint32_t index)
{
    return getMinGideonCode(ctQuest) + index;
}

/// 임시로 용병 수송 퀘스트 코드를 만들었다!!!
const QuestCode mercenaryTransportMissionQuestCode = makeQuestCode(0);


typedef sne::srpc::RSet<QuestCode> QuestCodes;


typedef DataCode QuestItemCode;

const QuestItemCode invalidQuestItemCode = 0;

inline bool isValidQuestItemCode(QuestItemCode code)
{
    return getCodeType(code) == ctQuestItem;
}


/// QuestItemCode를 만든다
inline QuestItemCode makeQuestItemCode(uint32_t index)
{
    return getMinGideonCode(ctQuestItem) + index;
}

/**
 * @enum UpgradeEquipPartType
 * 퀘스트 보상 강화 종류
 */
enum UpgradeEquipPartType
{
    ueptUnkonown,
    ueptAttackItem,
	ueptDeffencetItem,
    ueptBoundery,
};


inline bool isValid(UpgradeEquipPartType type)
{
    return ueptUnkonown < type && type < ueptBoundery;
}


///// UpgradeEquipReawardCode를 만든다
//inline DataCode makeUpgradeEquipReawardCode(UpgradeEquipPartType part, ItemGrade grade,
//	uint8_t level)
//{
//    return getMinGideonCode(ctQuestUpgradeEquip) + (part << 16) + (grade <<8 ) + level;
//}
//

/// UpgradeEquipPartType을 얻는다
inline UpgradeEquipPartType getUpgradePartType(uint32_t info)
{
    return static_cast<UpgradeEquipPartType>((info & 0x00ff0000) >> 16);
}


/// ItemGrade 얻는다
inline ItemGrade getEquipGradeType(uint32_t info)
{
    return static_cast<ItemGrade>((info & 0x0000ff00) >> 8);
}


/// 최대 강화 체크 레벨
inline uint8_t getMaxEquipLevel(uint32_t info)
{
    return static_cast<uint8_t>(info & 0x000000ff);
}

//
///// makeSelectUpgradeEquipReawardCode를 만든다
//inline DataCode makeSelectUpgradeEquipReawardCode(EquipPart part)
//{
//    return getMinGideonCode(ctQuestSelectUpgradeEquip) + (part << 16);
//}
//
//
///// 선택 강화 파트를 가지고 온다
//inline EquipPart getSelectEquipPart(DataCode code)
//{
//	return static_cast<EquipPart>((code & 0x00ff0000) >> 16);
//}

/***
 * @struct QuestContentMissionType
 ***/
enum QuestContentMissionType
{
	qcmtUnknown = 0,
	qcmtArenaEnter,
    qcmtEquipUpgrade,
    qcmtEquipEnchant,
    qcmtSkillLearn,
    qcmtTargetAttack,
    qcmtCount,
};


inline bool isValid(QuestContentMissionType type)
{
    return qcmtUnknown < type && type < qcmtCount;
}

template <typename T>
inline QuestContentMissionType toQuestContentMissionType(T value)
{
	return static_cast<QuestContentMissionType>(static_cast<uint8_t>(value));
}


/***
 * @struct QuestItemInfo
 ***/
struct QuestItemInfo
{
    ObjectId itemId_;
    QuestItemCode questItemCode_;
    uint8_t usableCount_;
	uint8_t stackCount_;
    QuestCode questCode_;
    
    explicit QuestItemInfo(ObjectId itemId = invalidObjectId,
        QuestItemCode questItemCode = invalidQuestItemCode,
        uint8_t usableCount = 0, uint8_t stackCount = 0, QuestCode questCode = invalidQuestCode) :
        itemId_(itemId),
        questItemCode_(questItemCode),
        usableCount_(usableCount),
		stackCount_(stackCount),
        questCode_(questCode)
    {}   
    
    bool isValid() const {
        return isValidObjectId(itemId_) &&
            isValidQuestItemCode(questItemCode_);
    }

    /// @return zero remained
    bool useItem() {
        if (usableCount_ > 0) {
            --usableCount_;
            return usableCount_ <= 0;
        }
        return false;
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & itemId_ & questItemCode_ & usableCount_ & stackCount_ & questCode_;
	}
};

typedef sne::srpc::RVector<QuestItemInfo> QuestItemInfos;

/***
 * @strucnt QuestInventoryInfo
 ***/
struct QuestInventoryInfo
{
    enum {defaultMaxSlot = 5 * 5};

    uint8_t maxSlotCount_;
    QuestItemInfos questItems_;

    QuestInventoryInfo() {
        reset();
    }

    bool canAddItem(uint8_t addCount) {
        return maxSlotCount_ > questItems_.size() + addCount;
    }

    bool addItem(const QuestItemInfo& itemInfo) {
        if (maxSlotCount_ <= questItems_.size()) {
            return false;
        }
        questItems_.push_back(itemInfo);
        return true;
    }


    void removeItem(ObjectId itemId) {
        QuestItemInfos::iterator pos = questItems_.begin();
        QuestItemInfos::iterator end = questItems_.end();
        for (; pos != end; ++pos) {
            if ((*pos).itemId_ == itemId) {
                questItems_.erase(pos);
                return;
            }
        }
    }

    QuestItemInfo* getItemInfoById(ObjectId itemId) {
        for (QuestItemInfo& itemInfo : questItems_) {
            if (itemInfo.itemId_ == itemId) {
                return &itemInfo;
            }
        }
        return nullptr;
    }

    const QuestItemInfo* getItemInfoById(ObjectId itemId) const {
        for (const QuestItemInfo& itemInfo : questItems_) {
            if (itemInfo.itemId_ == itemId) {
                return &itemInfo;
            }
        }
        return nullptr;
    }

	const QuestItemInfo* getItemInfoByCode(QuestItemCode questItemCode) const {
		for (const QuestItemInfo& itemInfo : questItems_) {
			if (itemInfo.questItemCode_ == questItemCode) {
				return &itemInfo;
			}
		}
		return nullptr;
	}

	QuestItemInfo* getItemInfoByCode(QuestItemCode questItemCode) {
		for (QuestItemInfo& itemInfo : questItems_) {
			if (itemInfo.questItemCode_ == questItemCode) {
				return &itemInfo;
			}
		}
		return nullptr;
	}

    void reset() {
        maxSlotCount_ = defaultMaxSlot;
        questItems_.clear();
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & maxSlotCount_ & questItems_;
    }
};


typedef uint32_t QuestMissionCode;
const QuestMissionCode invalidQuestMissionCode = 0;

/// is valid QuestMissionCode
inline bool isValidQuestMissionCode(QuestMissionCode missionCode)
{
    return getCodeType(missionCode) == ctQuestMission;
}

/**
 * @enum QuestMissionType
 * 퀘스트 미션 종류
 */
enum QuestMissionType
{
	qmtUnknown = 0,
	qmtKill = 1,
    qmtObtain = 2,
    qmtTrasport = 3,
    qmtProbe = 4,
    qmtActivation = 5, //< Device 작동
	qmtContent = 6, // 컨텐츠 유도 미
	qmtEnd,
};


inline bool isValid(QuestMissionType qmt)
{
	return qmtUnknown < qmt && qmt < qmtEnd;
}


inline bool isKillMission(QuestMissionType qmt)
{
    return qmtKill == qmt;
}


inline bool isObtainMission(QuestMissionType qmt)
{
    return qmtObtain == qmt;
}


inline bool isTransportMission(QuestMissionType qmt)
{
    return qmtTrasport == qmt;
}


inline bool isProbeMission(QuestMissionType qmt)
{
    return qmtProbe == qmt;
}


inline bool isActivationMission(QuestMissionType qmt)
{
    return qmtActivation == qmt;
}


inline bool isContentMission(QuestMissionType qmt)
{
	return qmtContent == qmt;
}

/// QuestMissionCode를 만든다
inline QuestMissionCode makeQuestMissionCode(QuestMissionType qmt, uint16_t index)
{
    return getMinGideonCode(ctQuestMission) + (qmt << 16) + index;
}


inline QuestMissionType getQuestMissionType(QuestMissionCode qmc)
{
    assert(getCodeType(qmc) == ctQuestMission);
    return static_cast<QuestMissionType>((qmc & 0x00FF0000) >> 16);
}

/**
 * @enum QuestIssueCondition
 * 퀘스트 발행 조건
 */
enum QuestIssueCondition
{
	qicUnknone = 0,
	qicNpc,
	quiTalk,
    quiStaticNpc,
};


inline bool isValid(QuestIssueCondition condition)
{
	return qicNpc == condition || quiStaticNpc == condition;
}


/**
 * @enum QuestIssueSpecialCondition
 * 퀘스트 발행 특수 조건
 */
enum QuestIssueSpecialCondition
{
	qiscNone = 0, // 없음
	qiscPreQuest, // 선행 퀘스트
	qiscChaotic, // 카오틱 수치
	qiscLawful, // 라오풀 수치
	qiscGameMoney, // 돈 지불
	qiscQuestPoint, // 퀘스트 포인트 지불
	qiscKeyword, // 키워드 확인
	qiscItem, // 인벤토리 아이템 확인
    qiscQuestItem, // 퀘스트 아이템
	qiscLevel, // 레벨 이상
    qiscCharacterClass, // 특정 캐릭터 클래스
    qiscCharacterClassAndLevel, // 특정 캐릭터 클래스 Level
    qiscTime, // 특정한 시간
    qiscRemoveInvenItem, // 체크후 삭제(발행시)
    qiscRemoveQuestItem, // 체크후 삭제(발행시)
    qiscEnd,
};


inline bool isValid(QuestIssueSpecialCondition condition)
{
	return qiscNone <= condition && condition < qiscEnd;
}


inline bool hasCondition(QuestIssueSpecialCondition condition)
{
    return qiscNone < condition && condition < qiscEnd;
}


template <typename T>
inline QuestIssueSpecialCondition toQuestIssueSpecialCondition(T value)
{
    return static_cast<QuestIssueSpecialCondition>(static_cast<uint8_t>(value));
}


/**
 * @enum QuestRemunerationKind
 * 퀘스트 보상 종류
 */
enum QuestRemunerationKind
{
	qrkNone = 0,
	qrkMoney,
	qrkExp,
	qrkChaotic,
	qrkItem,
	qrkFaction,
	qrkKeyword,
    qrkChangeCharacterClass,
    qrkQuestItem,
    qrkArmorFragment,
    qrkWeaponFragment,
    qrkCount,
};


inline bool isValid(QuestRemunerationKind kind)
{
	return qrkNone < kind && kind < qrkCount;
}


inline bool isEquipDependent(QuestRemunerationKind kind)
{
    return (kind == qrkArmorFragment) || (kind == qrkWeaponFragment);
}


inline bool isArmorDependent(QuestRemunerationKind kind)
{
    assert(isEquipDependent(kind));
    return kind == qrkArmorFragment;
}


/**
 * @enum QuestGoalType
 * 퀘스트 목표 타입
 */
enum QuestGoalType
{
	qgtUnknown = 0,

	qgtKillUser = 10,
	qgtKillNpc = 11,
	qgtKillChaotic = 12,
	qgtKillLawful = 13,
	qgtKillFaction = 14,
    qutKillEnd = qgtKillFaction,

    qgtObtainItem = 20,
    qgtObtainEnd = qgtObtainItem,

    qgtTransportNpc = 30,
    qgtTransportPosition = 31,
    qgtTransportEnd = qgtTransportPosition,
};

template <typename T>
inline QuestGoalType toQuestGoalType(T value)
{
    return static_cast<QuestGoalType>(static_cast<uint8_t>(value));
}


inline bool isValid(QuestGoalType type)
{
	return (qgtKillUser <= type && type <= qgtKillFaction) ||
        (qgtObtainItem <= type && type <= qgtObtainEnd) ||
        (qgtTransportNpc <= type && type <= qgtTransportEnd);
}

inline bool isKillGoalType(QuestGoalType type)
{
    return (qgtKillUser <= type && type <= qgtKillFaction);
}


inline bool isObtainType(QuestGoalType type)
{
    return (qgtObtainItem <= type && type <= qgtObtainEnd);
}


inline bool isTransportType(QuestGoalType type)
{
    return (qgtTransportNpc <= type && type <= qgtTransportEnd);
}


inline bool isPostionTransport(QuestGoalType type)
{
    return type == qgtTransportPosition ;
}

/**
 * @struct QuestGoalInfo
 * 퀘스트 목표 수치
 */
struct QuestGoalInfo
{
	DataCode goalCode_;
	uint32_t goalValue_;

	explicit QuestGoalInfo(DataCode goalCode = invalidDataCode, uint32_t goalValue = 0) :
		goalCode_(goalCode),
		goalValue_(goalValue) {}

    bool isValid() const {
        return isValidDataCode(goalCode_) && (goalValue_ > 0);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & goalCode_ & goalValue_;
	}
};


typedef sne::srpc::RVector<QuestGoalInfo> QuestGoalInfos;


typedef sne::srpc::RMap<QuestMissionCode, QuestGoalInfos> QuestGoalInfosMap;


/**
 * @struct AcceptedQuestInfo
 * 수락한 퀘스트 
 */
struct AcceptedQuestInfo
{	
	QuestCode questCode_;
	QuestGoalInfosMap questGoalInfosMap_;

	explicit AcceptedQuestInfo(QuestCode questCode = invalidQuestCode) :
		questCode_(questCode) {}

	const QuestGoalInfos* getQuestGoalInfos(QuestMissionCode missionCode) const {
		const QuestGoalInfosMap::const_iterator pos = questGoalInfosMap_.find(missionCode);
		if (pos != questGoalInfosMap_.end()) {
			return &(*pos).second;
		}
		return nullptr;
	}

	QuestGoalInfos* getQuestGoalInfos(QuestMissionCode missionCode) {
		const QuestGoalInfosMap::iterator pos = questGoalInfosMap_.find(missionCode);
		if (pos != questGoalInfosMap_.end()) {
			return &(*pos).second;
		}
		return nullptr;
	}

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & questCode_ & questGoalInfosMap_;
    }
};


typedef sne::srpc::RVector<AcceptedQuestInfo> AcceptedQuestInfos;


/***
 * @struct AcceptedRepeatQuestInfo
 ***/
struct AcceptedRepeatQuestInfo : public AcceptedQuestInfo
{
    sec_t acceptTime_;

    explicit AcceptedRepeatQuestInfo(QuestCode questCode = invalidQuestCode, sec_t acceptTime = 0) :
        AcceptedQuestInfo(questCode),
        acceptTime_(acceptTime) {}

    template <typename Stream>
    void serialize(Stream& stream) {
        AcceptedQuestInfo::serialize(stream);
        stream & acceptTime_;
    }
};


typedef sne::srpc::RVector<AcceptedRepeatQuestInfo> AcceptedRepeatQuestInfos;

/***
 * @sturct CompletedRepeatQuestInfo
 ***/
struct CompletedRepeatQuestInfo
{
    QuestCode questCode_;
    sec_t acceptTime_;

    explicit CompletedRepeatQuestInfo(QuestCode questCode = invalidQuestCode, 
        sec_t acceptTime = 0) :
        questCode_(questCode),
        acceptTime_(acceptTime) {}


    bool operator<(const CompletedRepeatQuestInfo& rhs) const {
        return questCode_ < rhs.questCode_;
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & questCode_ & acceptTime_;
    }
};


typedef sne::srpc::RSet<CompletedRepeatQuestInfo> CompletedRepeatQuestInfos;

/***
 * @sturct QuestToPartyResultType
 ***/
enum QuestToPartyResultType
{
    qtprtUnknown,
    qtprtOk, //< 상대에게 수락 요청이 전송되었다
    qtprtAccepted, //< 상대가 퀘스트를 수락하였다
    qtprtAlreadyAcceptQuest, //< 이미 받은 퀘스트
    qtprtCompleteQuest, //< 완료된 퀘스트
    qtprtNotAcceptCondtion, //< 받을수 없는 조건
    qtprtIsNotSameWorld, //< 같은 월드에 없다
    qtprtNotEnoughLevel, //< 받을수 없는 레벨
    qtprtTargetRefusal, //< 상대방이 거절
    qtprtBoundery,
};


inline bool isValid(QuestToPartyResultType type)
{
    return qtprtUnknown < qtprtOk && type < qtprtBoundery;
}


inline bool isSucceeded(QuestToPartyResultType result)
{
    return qtprtOk == result;
}

} // namespace gideon {

namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::QuestContentMissionType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::QuestContentMissionType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::QuestContentMissionType>(value);
    return lhs;
}


inline OStream& operator<<(OStream& lhs, gideon::QuestToPartyResultType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::QuestToPartyResultType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::QuestToPartyResultType>(value);
    return lhs;
}

}} // namespace sne { namespace core {