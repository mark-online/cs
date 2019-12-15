#pragma once

#include "Code.h"
#include <cassert>

namespace gideon {

/**
 * 보석 코드
 * - Category(1B) | empty(1B) | index(2B)
 */
typedef DataCode GemCode;
const GemCode invalidGemCode = invalidDataCode;


/// GemCode를 만든다
inline GemCode makeGemCode(uint16_t index)
{
    return getMinGideonCode(ctGem) + index;
}


inline uint16_t getGemIndex(GemCode sc)
{
    assert(getCodeType(sc) == ctGem);
    return static_cast<uint16_t>(sc & 0x0000FFFF);
}


/// GemCode를 파싱한다
inline bool parseGemCode(uint16_t& index, GemCode sc)
{
    const CodeType codeType = getCodeType(sc);
    if (codeType != ctGem) {
        return false;
    }

    index = getGemIndex(sc);
    return true;
}


/// 유효한 Gem 코드인가?
inline bool isValidCGemCode(GemCode sc)
{
    uint16_t index = 0;
    if (! parseGemCode(index, sc)) {
        return false;
    }
    return index > 0;
}

} // namespace gideon {
