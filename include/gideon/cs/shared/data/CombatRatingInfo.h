#pragma once

#include <gideon/cs/Common.h>
#include "Rate.h"

namespace gideon {

/// 데미지 무시(회피, 무기막기, 방패 막기)에 적용할 gain값 구하기
inline float getAvoidanceGain(int level)
{
    const int refLevel = 1;
    const int maxLevel = 100;
    const int rollOffLevel = 5;
    const float factor = 0.02f;

    const int aLevel = (std::min)((std::max)(level, refLevel), maxLevel);
    return (float(maxLevel - level) / (refLevel + rollOffLevel * (aLevel - refLevel + 1))) * factor;
}


/// 물리/마법 치명타 gain값 구하기
inline float getCriticalGain(int level)
{
    const int refLevel = 1;
    const int maxLevel = 100;
    const int rollOffLevel = 5;
    const float factor = 0.02f;

    const int aLevel = (std::min)((std::max)(level, refLevel), maxLevel);
    return (float(maxLevel - level) / (refLevel + rollOffLevel * (aLevel - refLevel + 1))) * factor;
}


/// hit rate 1pt = 0.035% hit chance
inline bips_t getHitChance(int16_t hitRate)
{
    const float hitChancePerRate = 0.035f;
    return static_cast<bips_t>(hitRate * hitChancePerRate * 100);
}


inline bips_t getDodgeChance(CreatureLevel level, int16_t dodgeRate)
{
    return static_cast<bips_t>(dodgeRate * getAvoidanceGain(level) * 100);
}


inline bips_t getParryChance(CreatureLevel level, int16_t parryRate)
{
    return static_cast<bips_t>(parryRate * getAvoidanceGain(level) * 100);
}


inline bips_t getBlockChance(CreatureLevel level, int16_t blockRate)
{
    return static_cast<bips_t>(blockRate * getAvoidanceGain(level) * 100);
}


inline bips_t getPhysicalCriticalChance(CreatureLevel level, int16_t criticalRate)
{
    return static_cast<bips_t>(criticalRate * getCriticalGain(level) * 100);
}


inline bips_t getMagicCriticalChance(CreatureLevel level, int16_t criticalRate)
{
    return static_cast<bips_t>(criticalRate * getCriticalGain(level) * 100);
}


inline float getDamageReductionRate(int16_t defense, CreatureLevel attackerLevel)
{
    const float maxRate = 0.75f;

    return (std::min)(defense / (defense + (40.0f * attackerLevel)), maxRate);
}

} // namespace gideon {
