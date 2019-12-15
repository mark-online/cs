#pragma once

#include "ObjectInfo.h"
#include <sne/srpc/RpcContainers.h>

namespace gideon {


/***
 * @enum Chaotic
 * 범죄자 수치
 ***/
enum Chaotic
{
    graveStoneChaotic = 200,
    killChaotic = 500,
    minChaotic = 0,
    maxChaotic = 10000,
    temporaryChaotic = 99999,
};


inline bool isValid(Chaotic chaotic)
{
    return minChaotic <= chaotic && chaotic <= maxChaotic;
}


template <typename T>
inline Chaotic toChaotic(T value)
{
    return static_cast<Chaotic>(static_cast<int16_t>(value));
}


} // namespace gideon {

namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::Chaotic rhs)
{
    lhs << static_cast<uint16_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::Chaotic& rhs)
{
    uint16_t value;
    lhs >> value;
    rhs = static_cast<gideon::Chaotic>(value);
    return lhs;
}

}} //namespace sne { namespace core {