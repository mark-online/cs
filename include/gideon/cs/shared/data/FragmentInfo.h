#pragma once

#include "Code.h"
#include <cassert>

namespace gideon {
/**
 * FragmentCode 코드
 * - Category(1B) | empty(1B) | index(2B)
 */
typedef DataCode FragmentCode;
const FragmentCode invalidFragmentCode = invalidDataCode;


/// FragmentCode를 만든다
inline FragmentCode makeFragmentCode(uint16_t index)
{
    return getMinGideonCode(ctFragment) + index;
}


inline uint16_t getFragmentCodeIndex(FragmentCode sc)
{
    assert(getCodeType(sc) == ctFragment);
    return static_cast<uint16_t>(sc & 0x0000FFFF);
}


/// FragmentCode를 파싱한다
inline bool parseFragmentCode(uint16_t& index, FragmentCode sc)
{
    const CodeType codeType = getCodeType(sc);
    if (codeType != ctFragment) {
        return false;
    }

    index = getFragmentCodeIndex(sc);
    return true;
}


/// 유효한 Fragment 코드인가?
inline bool isValidFragmentCode(FragmentCode sc)
{
    uint16_t index = 0;
    if (! parseFragmentCode(index, sc)) {
        return false;
    }
    return index > 0;
}



} // namespace gideon {
