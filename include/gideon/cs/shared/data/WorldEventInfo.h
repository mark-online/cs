#pragma once

#include "RegionInfo.h"
#include "Time.h"
#include "UserId.h"
#include "ObjectInfo.h"

namespace gideon {

typedef uint32_t WorldEventCode;
const WorldEventCode invalidWorldEventCode = 0;


typedef uint32_t WorldEventMissionCode;
const WorldEventMissionCode invalidWorldEventMissionCode = 0;

const uint8_t rewardRanking = 7;

/**
 * @enum WorldEventMissionStateType
 */
enum WorldEventMissionStateType
{
    wemstUnknown = 0,
    wemstComplete = 1,
    wemstPlay = 2,
    wemstFailed = 3,
    wemstWait = 4,
};


inline bool isPlayWorldEventMission(WorldEventMissionStateType state)
{
    return wemstPlay == state;
}


inline bool isCompleteWorldEventMission(WorldEventMissionStateType state)
{
    return wemstComplete == state;
}


inline bool isWaitWorldEventMission(WorldEventMissionStateType state)
{
    return wemstWait == state;
}


inline bool isFailWorldEventMission(WorldEventMissionStateType state)
{
    return wemstFailed == state;
}


/**
 * @enum WorldEventStateType
 */
enum WorldEventStateType
{
    westUnknown = 0,
    westComplete = 1,
    westPlay = 2,
    westFailed = 3,
    westWait = 4,
};


inline bool isPlayWorldEvent(WorldEventStateType state)
{
    return westPlay == state;
}


inline bool isCompleteWorldEvent(WorldEventStateType state)
{
    return westComplete == state;
}


inline bool isWaitWorldEvent(WorldEventStateType state)
{
    return westWait == state;
}


inline bool isFailWorldEvent(WorldEventStateType state)
{
    return westFailed == state;
}


/**
 * @enum WorldEventMissionType
 */
enum WorldEventMissionType
{
    wemtUnknown = 0,
    wemtBegin = 1,
    wemtKillBoss = wemtBegin,
    wemtKillAll = 2,
    wemtGuard = 3,
    wemtEscort = 4,
    wemtCount
};

template <typename T>
inline WorldEventMissionType toWorldEventMissionType(T value)
{
    return static_cast<WorldEventMissionType>(static_cast<uint8_t>(value));
}


inline bool canDrawRegionOnMap(WorldEventMissionType value)
{
    return value == wemtKillAll;
}

/**
 * @enum WorldEventOpenType
 */
enum WorldEventOpenType
{
    weotHour = 1,
    weotDay = 2,
    weotDate = 3,
    weotWeek = 4,
    weotRandom = 5,
};


template <typename T>
inline WorldEventOpenType toWorldEventOpenType(T value)
{
    return static_cast<WorldEventOpenType>(static_cast<uint8_t>(value));
}

/***
 * @struct WorldEventMissionInfo
 ***/
struct WorldEventMissionInfo
{
    WorldEventMissionCode missionCode_;
    WorldEventMissionStateType missionStateType_;

    WorldEventMissionInfo(WorldEventMissionCode missionCode = invalidWorldEventMissionCode,
        WorldEventMissionStateType missionStateType = wemstUnknown) :
        missionCode_(missionCode),
        missionStateType_(missionStateType)
    {}

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & missionCode_ & missionStateType_;
    }
};

typedef sne::srpc::RVector<WorldEventMissionInfo> WorldEventMissionInfos;

/**
 * @struct WorldEventInfo
 */
struct WorldEventInfo
{
    WorldEventCode worldEventCode_;
    uint8_t eventPhase_;
    sec_t startEventTime_;
    WorldEventMissionInfos infos_;

    WorldEventInfo(WorldEventCode worldEventCode = invalidWorldEventCode,
        uint8_t eventPhase = 0, sec_t startEventTime = 0) :
        worldEventCode_(worldEventCode),
        eventPhase_(eventPhase),
        startEventTime_(startEventTime)
    {
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & worldEventCode_ & eventPhase_ & startEventTime_ & infos_;
    }
};

typedef sne::srpc::RVector<WorldEventInfo> WorldEventInfos;

/**
 * @struct WorldEventRankerInfo
 */
struct WorldEventRankerInfo
{
    ObjectId playerId_;
    uint32_t score_;
    uint8_t ranking_;
    Nickname nickname_;

    WorldEventRankerInfo(ObjectId playerId = invalidObjectId,
        uint32_t score = 0, uint8_t ranking = 0, const Nickname& nickname = L"") :
        playerId_(playerId),
        score_(score),
        ranking_(ranking),
        nickname_(nickname)
    {
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & playerId_ & score_ & ranking_ & nickname_;
    }
};

typedef sne::srpc::RVector<WorldEventRankerInfo> WorldEventRankerInfos;

/**
 * @struct RankingRewardInfo
 */
struct RankingRewardInfo
{
    Nickname nickname_;
    uint32_t rewardValue_;

    RankingRewardInfo(const Nickname& nickname = L"", uint32_t rewardValue = 0) :
        nickname_(nickname),
        rewardValue_(rewardValue)
    {
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & nickname_ & rewardValue_;
    }
};

typedef sne::srpc::RVector<RankingRewardInfo> RankingRewardInfos;

/**
 * @struct WorldEventKillMissionInfo
 */
struct WorldEventKillMissionInfo
{
    uint8_t goalCount_;
    uint8_t currentCount_;

    WorldEventKillMissionInfo(uint8_t goalCount = 0, uint8_t currentCount = 0) :
        goalCount_(goalCount),
        currentCount_(currentCount)
    {
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & goalCount_ & currentCount_;
    }
};

typedef sne::srpc::RMap<DataCode, WorldEventKillMissionInfo> WorldEventKillMissionInfoMap;

} // namespace gideon {

namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::WorldEventMissionStateType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::WorldEventMissionStateType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::WorldEventMissionStateType>(value);
    return lhs;
}


inline OStream& operator<<(OStream& lhs, gideon::WorldEventStateType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::WorldEventStateType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::WorldEventStateType>(value);
    return lhs;
}



}} // namespace sne { namespace core {