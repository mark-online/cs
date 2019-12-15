#pragma once

#include "ObjectInfo.h"
#include "code.h"

namespace gideon {

typedef uint32_t MercenaryPoint;

const MercenaryPoint minMercenaryPoint = 0;

enum MercenaryGrade
{
    mgD = 20,
    mgC = 60,
    mgB = 140,
    mgA = 300,
    mgS = 600,
    mgSS = 1000,
};


const MercenaryPoint acceptMercenaryPoint = 2;
const MercenaryPoint completeMercenaryPoint = 6;
const MercenaryPoint cancelMercenaryPoint = 1;

inline uint32_t getMaxMemberCount(MercenaryPoint mep)
{
    if (mep >= mgA) {
        return 24;
    }
    if (mep >= mgB) {
        return 16;
    }
    if (mep >= mgC) {
        return 10;
    }
    return 6;
}


inline bool canInviteMemberCount(MercenaryPoint mep, uint32_t memberCount)
{
    const uint32_t maxMemberCount = getMaxMemberCount(mep);
    return memberCount < maxMemberCount;
}


} // namespace gideon {