#pragma once

#include <gideon/cs/Common.h>

namespace gideon {
/**
 * FactionCode 코드
 * 1 ~ 255
 */
typedef uint8_t FactionCode;
const FactionCode invalidFactionCode = invalidDataCode;
const FactionCode playerFactionCode = 3; //< 저항군(편의를 위해 hardcoding)

/// 유효한 Faction 코드인가?
template <typename T>
inline bool isValidFactionCode(T fc)
{
    return (1 <= fc) && (fc <= 255);
}


/**
 * @enum FactionMask
 */
enum FactionMask
{
    famUnknown = 0,
    famAllPlayers = 1,
    famNpc = 2,
    famMonster = 4,
    famBounday = 255
};


inline bool isValid(FactionMask value)
{
    return (famUnknown < value) && (value < famBounday);
}


typedef sne::core::Set<FactionCode> FactionCodeSet;


inline bool hasFactionCode(const FactionCodeSet& set, FactionCode code)
{
    return set.find(code) != set.end();
}

} // namespace gideon {
