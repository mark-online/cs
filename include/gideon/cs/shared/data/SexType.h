#pragma once

#include <sne/core/stream/Stream.h>

namespace gideon {

/**
 * @enum SexType
 */
enum SexType
{
    stMale = 0,
    stFemale
};


inline bool isValid(SexType st)
{
    return (stMale == st) || (st == stFemale);
}

} // namespace gideon {


namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::SexType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::SexType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::SexType>(value);
    return lhs;
}

}} // namespace sne { namespace core {