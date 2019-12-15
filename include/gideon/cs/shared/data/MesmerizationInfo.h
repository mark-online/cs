#pragma once

#include <sne/srpc/RpcContainers.h>

namespace gideon {

/***
 * @enum MesmerizationType
 ***/
enum MesmerizationType
{
    meztUnknown = 0,
    meztStun,
    meztShackles,
    meztSleep, //< 잠들게 하기
    meztHide,
    meztFrenzy,
    meztParalyze,
    meztInvincible,
    meztSpawnProtection,
    meztDisableMagic,
    meztPanic,
};


inline bool shouldCancelCasting(MesmerizationType mezType)
{
    switch(mezType)
    {
    case meztStun:
    case meztSleep:
    case meztParalyze:
    case meztPanic:
    case meztDisableMagic:
        return true;
    }

    return false;
}

inline bool isStuckStateType(MesmerizationType mezType)
{
    switch(mezType)
    {
    case meztStun:
    case meztSleep:
    case meztParalyze:
    case meztShackles:
        return true;
    }

    return false;
}


inline CreatureStateType toCreatureStateType(MesmerizationType mezType)
{
    switch(mezType)
    {
    case meztStun:
        return cstStun;
    case meztShackles:
        return cstShackle;
    case meztSleep:
        return cstSleep;
    case meztHide:
        return cstHide;
    case meztFrenzy:
        return cstFrenzie;
    case meztParalyze:
        return cstParalyse;
    case meztInvincible:
        return cstInvincible;
    case meztSpawnProtection:
        return cstSpawnProtection;
    case meztDisableMagic:
        return cstDisableMagic;
    case meztPanic:
        return cstPanic;
    }

    assert(false);
    return cstNormal;
}

} //namespace gideon {



namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::MesmerizationType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::MesmerizationType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::MesmerizationType>(value);
    return lhs;
}

}} // namespace sne { namespace core {