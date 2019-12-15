#pragma once

#include "ObjectInfo.h"

namespace gideon {

/// GameMoney.
typedef uint64_t GameMoney;
const GameMoney gameMoneyMin = 0;

const GameMoney unlearnSkillFee = 100;


inline uint32_t asGold(GameMoney money)
{
    return uint32_t(money / 10000);
}


inline uint32_t asSilver(GameMoney money)
{
    return uint32_t(money / 100);
}


inline uint32_t asCopper(GameMoney money)
{
    return uint32_t(money % 100);
}


inline GameMoney byGold(uint32_t gold)
{
    return gold * 10000;
}


inline GameMoney bySilver(uint32_t silver)
{
    return silver * 100;
}


inline GameMoney toGameMoney(uint32_t gold, uint8_t silver, uint8_t copper)
{
    return byGold(gold) + bySilver(silver) + copper;
}

inline bool isValid(GameMoney money)
{
    if(money > 0)
        return true;
    return false;
}


typedef uint32_t EventCoin;
const EventCoin eventCoinMin = 0;

typedef uint32_t ForgeCoin;
const ForgeCoin forgeCoinMin = 0;

} // namespace gideon {
