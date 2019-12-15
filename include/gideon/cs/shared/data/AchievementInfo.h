#pragma once

#include "Code.h"
#include "Time.h"
#include <sne/srpc/RpcContainers.h>

namespace gideon {

typedef uint32_t AchievementPoint;

typedef DataCode AchievementCode;

const AchievementCode invalidAchievementCode = 0;

typedef sne::srpc::RSet<AchievementCode> AchievementCodeSet;

/**
 * @enum AchievementCategory
 * 업적 카테고리
 */
enum AchievementCategory
{
    acUnknown = 0,
    caStart = 1,
    acCharacter = 1,
    acZone,
    acDungeon,
    acPvP,
    acHunt,
    acQuest,
    acCount,
};


inline bool isValid(AchievementCategory category)
{
    return acUnknown < category && category < acCount;
}

/// makeAchievementCode를 만든다
inline AchievementCode makeAchievementCode(AchievementCategory category, uint32_t index)
{
    return getMinGideonCode(ctAchievement) + (category << 16) + index;
}


/// AchievementCategory을 얻는다
inline AchievementCategory getAchievementCategory(DataCode achievementCode)
{
    return static_cast<AchievementCategory>((achievementCode & 0x00ff0000) >> 16);
}


inline bool isValidAchievementCode(AchievementCode code)
{
    if (! isAchievementType(getCodeType(code))) {
        return false;
    }
    return isValid(getAchievementCategory(code));
}

/**
 * @enum AchievementMissionType
 * 케릭터 업적 미션 타입
 */
enum AchievementMissionType
{
    acmtUnknown = 0,
    acmtLevel = 1,
    acmtAddBuddy = 2,
    acmtInventory = 3,
    acmtBankGameMoney = 4,
    acmtChao = 5,
    acmtTreasure = 6,
    acmtEquip = 7,
    acmtStore = 8,
    acmtPvPDeath = 9,
    acmtPvPKill = 10,
    acmtPvPWin = 11,
    acmtExecution = 12,
    acmtHunter = 13,
    acmtQuest = 14,
    acmtCount,
};


inline bool isValid(AchievementMissionType missionType)
{
    return acmtUnknown < missionType && missionType < acmtCount;
}


template <typename T>
AchievementMissionType toAchievementMissionType(T value)
{
    return static_cast<AchievementMissionType>(static_cast<uint8_t>(value));
}

/**
 * @enum ProcessAchievementInfo
 * 진행 중인 업적 정보
 */
struct ProcessAchievementInfo
{
    uint64_t param1_;
    uint64_t param2_;
    sec_t lastUpdateTime_;

    ProcessAchievementInfo(uint64_t param1 = 0, uint64_t param2 = 0, sec_t lastUpdateTime = 0) :
        param1_(param1),
        param2_(param2),
        lastUpdateTime_(lastUpdateTime)
    {
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & param1_ & param2_ & lastUpdateTime_;
    }
};


typedef sne::srpc::RMap<AchievementCode, ProcessAchievementInfo> ProcessAchievementInfoMap;

/**
 * @enum CompleteAchievementInfo
 * 완료된 업적
 */
struct CompleteAchievementInfo
{    
    AchievementCode achievementCode_;
    sec_t completeTime_;

    explicit CompleteAchievementInfo(AchievementCode achievementCode = invalidAchievementCode,
        sec_t completeTime = 0) :
        achievementCode_(achievementCode),
        completeTime_(completeTime)
    {
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & achievementCode_ & completeTime_;
    }
};
    
typedef sne::srpc::RMap<AchievementCode, CompleteAchievementInfo> CompleteAchievementInfoMap;

} // namespace gideon {
