#pragma once

#include "ObjectInfo.h"
#include <sne/srpc/RpcContainers.h>

namespace gideon {

/**
 * @enum ExpPoint
 * 경험치
 */
enum ExpPoint
{
    ceUnknown = -1,
    ceMin = 0,
    ceMax = 1087800
};


inline bool isValid(ExpPoint ce)
{
    return (ceMin <= ce) && (ce <= ceMax);
}


template <typename T>
inline ExpPoint toExpPoint(T value)
{
    const ExpPoint point = static_cast<ExpPoint>(value);
    assert(isValid(point));
    return point;
}


/**
 * @enum CreatureLevel
 * 생명체 레벨
 */
enum CreatureLevel
{
    clInvalidLevel = 0,
    clMinLevel = 1,
    clMaxPlayerLevel = 30,
    clMaxPlayerCount,
    clMaxNpcLevel = 200,
    clCount,
};


inline bool isValidPlayerLevel(CreatureLevel level)
{
    return clMinLevel <= level && level <= clMaxPlayerLevel;
}


inline bool isValidNpcLevel(CreatureLevel level)
{
    return clMinLevel <= level && level <= clMaxNpcLevel;
}


template <typename T>
inline CreatureLevel toCreatureLevel(T value)
{
    return static_cast<CreatureLevel>(static_cast<int32_t>(value));
}



/**
 * @enum LevelStep
 */
enum LevelStep
{
    lsMinLevel = 0,
    lsMaxLevel = 4,
    lsCount,
};


inline bool isValid(LevelStep levelStep)
{
    return lsMinLevel <= levelStep && levelStep <= lsMaxLevel;
}


inline bool isMaxPlayerLevel(CreatureLevel level, LevelStep levelStep)
{
    return clMaxPlayerLevel <= level && lsMinLevel <= levelStep;
}


template <typename T>
inline LevelStep toLevelStep(T value)
{
    return static_cast<LevelStep>(value);
}


inline bool isBeginnerProtectionLevel(CreatureLevel level)
{
    return level < toCreatureLevel(20);
}


/**
 * @struct CurrentLevel
 */
struct CurrentLevel
{
    CreatureLevel level_;
    LevelStep levelStep_;

    CurrentLevel() :
        level_(clInvalidLevel),
        levelStep_(lsMinLevel) {}

    void reset() {
        level_ = clInvalidLevel;
        levelStep_ = lsMinLevel;
    }

    bool isValid() const {
        return gideon::isValidPlayerLevel(level_) && gideon::isValid(levelStep_);
    }

    /// 만렙?
    bool isMaxLevel() const {
        return gideon::isMaxPlayerLevel(level_, levelStep_);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & level_ & levelStep_;
    }
};


} // namespace gideon {



namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::CreatureLevel rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::CreatureLevel& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::CreatureLevel>(value);
    return lhs;
}



inline OStream& operator<<(OStream& lhs, gideon::LevelStep rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::LevelStep& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::LevelStep>(value);
    return lhs;
}

}} // namespace sne { namespace core {
