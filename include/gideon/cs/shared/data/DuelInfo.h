#pragma once

#include "Time.h"

namespace gideon {

const sec_t duelReadyTime = 3;
const sec_t duelStopTime = 300; // 5분

/**
 * @enum FieldDuelResultType
 */
enum FieldDuelResultType
{
    fdrtUnknown,
    fdrtCancelDistance,
    fdrtCancelTimeout,
    fdrtCancelPlayer,
    fdrtCancelEffect,
    fdrtLogoutPlayer,
    fdrtOk,
    fdrtCount,
};

inline bool isValid(FieldDuelResultType type)
{
    return fdrtUnknown < type && type < fdrtCount;
}


inline bool isCancelled(FieldDuelResultType type)
{
    return isValid(type) && (type != fdrtOk);
}

} // namespace gideon {


namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::FieldDuelResultType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::FieldDuelResultType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::FieldDuelResultType>(value);
    return lhs;
}

}} // namespace sne { namespace core {