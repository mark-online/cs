#pragma once

#include "UserId.h"
#include "ObjectInfo.h"
#include "StatusInfo.h"
#include "Time.h"
#include "LevelInfo.h"
#include "Coordinate.h"
#include "CharacterClass.h"

namespace gideon {

typedef uint32_t ArenaPoint;


/****
/* @enum ArenaModeType
****/
enum ArenaModeType
{
	amtUnknown = 0,
    amtStart = 1,
	amtDualMatch = amtStart,
	amtDeathMatch = 2,
    amtTeamDeathMatch = 3,
    amtOccupation = 4,
    amtDefence = 5,
    amtBoundary,
};

inline bool isValid(ArenaModeType mode)
{
    return amtUnknown < mode && mode < amtBoundary;
}


template <typename T>
ArenaModeType toArenaModeType(T value)
{
    return static_cast<ArenaModeType>(static_cast<uint8_t>(value));
}

/****
/* @enum ArenaTeamType
****/
enum ArenaTeamType
{
    attUnknown = 0,
    attRed = 1,
    attBlue = 2,
    attBoundary
};

inline bool isValid(ArenaTeamType team)
{
    return attUnknown < team && team < attBoundary;
}


/****
/* @struct ArenaPlayerInfo
****/
struct ArenaPlayerInfo
{
    ObjectId playerId_;
    Nickname nickname_;
    CharacterClass characterClass_;
    HitPoints currentPoints_;
    ManaPoints manaPoints_;
    uint16_t killCount_;
    uint16_t deathCount_;
    uint32_t score_;
    Waypoint waypoint_;

    explicit ArenaPlayerInfo(ObjectId playerId = invalidObjectId, CharacterClass characterClass = ccUnknown,
        const Nickname& nickname = L"",
        const HitPoints& currentPoints = HitPoints(), const ManaPoints& manaPoints = ManaPoints(),
        uint16_t killCount = 0, uint16_t deathCount = 0,
        uint32_t score = 0) :
        playerId_(playerId),
        characterClass_(characterClass),
        nickname_(nickname),
        currentPoints_(currentPoints),
        manaPoints_(manaPoints),
        killCount_(killCount),
        deathCount_(deathCount),
        score_(score) {}

    bool operator<(const ArenaPlayerInfo& rhs) const {
        return playerId_ < rhs.playerId_;
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & playerId_ & characterClass_ & nickname_ & currentPoints_ & manaPoints_& killCount_ & deathCount_ & score_ & waypoint_;
    }
};

typedef sne::srpc::RSet<ArenaPlayerInfo> ArenaPlayerInfos;

/****
 * @enum ArenaState
****/
enum ArenaState
{
    asWaiting = 1,
    asCountdown = 2,
    asPlaying = 3,
    asStop = 4,
};


const sec_t countdownSec = 5;
const sec_t lockDeserterTime = 60 * 15; // 탈영병 입장 불가 시간
const uint32_t perJoinTime = 30; // 남은시간이 총 플리이 시간의 30% 이상일때 참여가능
const uint32_t perValidPlayTime = 20; // 지난 총 플리이 시간의 20%일때 게임이 정상결과 저장


/****
 * @enum ArenaResultType
****/
enum ArenaResultType
{
    artWin,
    artLose,
    artDraw,
    artCancel, //  무효
};


inline bool isWin(ArenaResultType type)
{
    return artWin == type;
}


inline bool isLose(ArenaResultType type)
{
    return artLose == type;
}


inline bool isDraw(ArenaResultType type)
{
    return artDraw == type;
}


inline bool isCancel(ArenaResultType type)
{
    return artCancel == type;
}


inline ArenaPoint getRewardMatchPoint(ArenaResultType type)
{
    if (isWin(type)) {
        return 300;
    }
    else if (isLose(type)) {
        return 100;
    }
    return 0;
}


/****
 * @struct ArenaMatchModeInfo
****/
struct ArenaMatchModeInfo
{
    ArenaState state_;
    sec_t startTime_;
    uint32_t blueScore_;
    uint32_t redScore_;

    explicit ArenaMatchModeInfo() :
        state_(asWaiting),
        startTime_(0),
        blueScore_(0),
        redScore_(0)
    {
    }

    ArenaResultType getRestutType(ArenaTeamType teamType) const {       
        if (blueScore_ > redScore_) {
            if (teamType == attBlue) {
                return artWin;
            }
            return artLose;
        }
        else if (blueScore_ < redScore_) {
            if (teamType == attBlue) {
                return artLose;
            }
            return artWin;
        }
        return artDraw;
    }
    
    bool isDraw() const {
        return blueScore_ == redScore_;
    }


    bool isWating() const {
        return asWaiting == state_;
    }

    void startCountdown(sec_t startServerLocalTime) {
        state_ = asCountdown;
        startTime_ = startServerLocalTime;
    }

    bool isCountdown() const {
        return asCountdown == state_;
    }

    void startPlaying(sec_t startServerLocalTime) {
        state_ = asPlaying;
        startTime_ = startServerLocalTime;
    }

    bool isPlaying() const {
        return asPlaying == state_;
    }

    bool isStopPlaying() const {
        return asStop == state_;
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & state_ & startTime_ & blueScore_ & redScore_;
    }
};

const CreatureLevel arenaEnterableLevel = toCreatureLevel(10);

/****
 * @struct ArenaPlayResult
 * 누적되는 결과
****/
struct ArenaPlayResult
{
    uint32_t score_; // 누적 랭킹 산출할때 
    uint32_t rank_;
    uint32_t winCount_;
    uint32_t loseCount_;
    uint32_t drawCount_;

    ArenaPlayResult(uint32_t score = 0, uint32_t rank = 0, uint32_t winCount = 0,
        uint32_t loseCount = 0, uint32_t drawCount = 0) :
        score_(score),
        rank_(rank),
        winCount_(winCount),
        loseCount_(loseCount),
        drawCount_(drawCount)
    {
    }
    
    template <typename Stream>
    void serialize(Stream& stream) {
        stream & score_ & rank_ & winCount_ & loseCount_ & drawCount_;
    }
};

typedef sne::srpc::RHashMap<ArenaModeType, ArenaPlayResult> ArenaModePlayResultMap;


} // namespace gideon {

namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::ArenaModeType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::ArenaModeType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::ArenaModeType>(value);
    return lhs;
}


inline OStream& operator<<(OStream& lhs, gideon::ArenaState rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::ArenaState& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::ArenaState>(value);
    return lhs;
}


inline OStream& operator<<(OStream& lhs, gideon::ArenaResultType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::ArenaResultType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::ArenaResultType>(value);
    return lhs;
}

}} // namespace sne { namespace core {