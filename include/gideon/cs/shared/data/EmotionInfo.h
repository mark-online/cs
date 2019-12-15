#pragma once

#include "ObjectInfo.h"

namespace gideon {

enum Emotion
{
    emUnknown = 0,
    emBoast,
    emWave,
    emDeny,
    emLaugh,
    emDialog,
    emApplause,
    emCry,
    emCheer,
    emBoundary
};

inline bool isValid(Emotion e)
{
    return (emUnknown < e) && (e < emBoundary);
}

} // namespace gideon {

namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::Emotion rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::Emotion& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::Emotion>(value);
    return lhs;
}


}} // namespace sne { namespace core {
