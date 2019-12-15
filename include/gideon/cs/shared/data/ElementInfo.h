#pragma once

#include "Code.h"
#include <cassert>

namespace gideon {

/**
 * Element 코드
 * - Category(1B) | empty(1B) | index(2B)
 */
typedef DataCode ElementCode;
const ElementCode invalidElementCode = invalidDataCode;


/// ElementCode를 만든다
inline ElementCode makeElementCode(uint16_t index)
{
    return getMinGideonCode(ctElement) + index;
}


inline uint16_t getElementCodeIndex(ElementCode sc)
{
    assert(getCodeType(sc) == ctElement);
    return static_cast<uint16_t>(sc & 0x0000FFFF);
}


/// ElementCode를 파싱한다
inline bool parseElementCode(uint16_t& index, ElementCode sc)
{
    const CodeType codeType = getCodeType(sc);
    if (codeType != ctElement) {
        return false;
    }

    index = getElementCodeIndex(sc);
    return true;
}


/// 유효한 Element 코드인가?
inline bool isValidElementCode(ElementCode sc)
{
    uint16_t index = 0;
    if (! parseElementCode(index, sc)) {
        return false;
    }
    return index > 0;
}

} // namespace gideon {
