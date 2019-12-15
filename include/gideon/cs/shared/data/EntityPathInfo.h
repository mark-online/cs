#pragma once

#include "CreatureInfo.h"
#include <cassert>

namespace gideon {

/**
 * NPC Path 코드
 * - Category(1B) | index(2B)
 */
typedef DataCode EntityPathCode;
const EntityPathCode invalidEntityPathCode = invalidDataCode;


/// EntityPathCode를 만든다
inline EntityPathCode makeEntityPathCode(uint16_t index)
{
    return getMinGideonCode(ctEntityPath) + index;
}


inline uint16_t getEntityPathCodeIndex(EntityPathCode sc)
{
    assert(getCodeType(sc) == ctEntityPath);
    return static_cast<uint16_t>(sc & 0x0000FFFF);
}


/// EntityPathCode를 파싱한다
inline bool parseEntityPathCode(uint16_t& index, EntityPathCode sc)
{
    const CodeType codeType = getCodeType(sc);
    if (codeType != ctEntityPath) {
        return false;
    }

    index = getEntityPathCodeIndex(sc);
    return true;
}


/// 유효한 NPC 코드인가?
inline bool isValidEntityPathCode(EntityPathCode sc)
{
    uint16_t index = 0;
    if (! parseEntityPathCode(index, sc)) {
        return false;
    }
    return index > 0;
}

} // namespace gideon {
