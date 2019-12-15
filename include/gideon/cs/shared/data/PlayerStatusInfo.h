#pragma once
#include "StatusInfo.h"

namespace gideon {


inline HitPoint getHitPoint(CharacterClass cc, int strength, int dexterity, int energy)
{
    if (isCommonClass(cc)) {
        return toHitPoint((100 + (strength * 0.8) + (dexterity * 0.3) + (energy * 4)) * 1.5);
    }

    // TODO: 2차 직업 스탯 추가
    CharacterClass firstClass = ccUnknown;
    if (isFirstClass(cc)) {
        firstClass = cc;
    }
    else if (isSecondClass(cc)) {
        firstClass = toFirstClass(cc);
    }

    switch (firstClass) {
    case ccWizard:
        return toHitPoint((100 + (strength * 0.8) + (dexterity * 0.3) + (energy * 5)) * 1.8);
    case ccFighter:
        return toHitPoint((100 + (strength * 0.8) + (dexterity * 0.3) + (energy * 6.4)) * 1.8) ;        
    case ccRogue:
        return toHitPoint((100 + (strength * 0.8) + (dexterity * 0.3) + (energy * 6)) * 1.8);
    }
    return toHitPoint(hpMin);
}


inline ManaPoint getManaPoint(CharacterClass cc, int intellect, int energy)
{
    if (isCommonClass(cc)) {
        return toManaPoint(100 + (intellect * 0.25) + (energy * 0.2));
    }

    // TODO: 2차 직업 스탯 추가
    CharacterClass firstClass = ccUnknown;
    if (isFirstClass(cc)) {
        firstClass = cc;
    }
    else if (isSecondClass(cc)) {
        firstClass = toFirstClass(cc);
    }

    switch (firstClass) {
    case ccWizard:
        return toManaPoint(100 + (intellect * 0.7) + (energy * 0.2));
    case ccFighter:
        return toManaPoint(100 + (intellect * 0.3) + (energy * 0.2));        
    case ccRogue:
        return toManaPoint(100 + (intellect * 0.3) + (energy * 0.2));
    }
    return toManaPoint(mpMin);
}


inline int getPhysicalPower(CharacterClass cc, int strength, int dexterity)
{
    if (isCommonClass(cc)) {
        return static_cast<int>(((strength * 0.45) + (dexterity * 0.18)) / 2);
    }

    // TODO: 2차 직업 스탯 추가
    CharacterClass firstClass = ccUnknown;
    if (isFirstClass(cc)) {
        firstClass = cc;
    }
    else if (isSecondClass(cc)) {
        firstClass = toFirstClass(cc);
    }

    switch (firstClass) {
    case ccWizard:
        return static_cast<int>(((strength * 0.25) + (dexterity * 0.18)) / 2);
    case ccFighter:
        return static_cast<int>(((strength * 0.45) + (dexterity * 0.18)) / 2);
    case ccRogue:
        return static_cast<int>(((strength * 0.45) + (dexterity * 0.18)) / 2);
    }
    return 0;
}


inline int getMagicPower(CharacterClass cc, int intellect)
{
    if (isCommonClass(ccAny)) {
        return static_cast<int>(intellect * 0.25);
    }

    // TODO: 2차 직업 스탯 추가
    CharacterClass firstClass = ccUnknown;
    if (isFirstClass(cc)) {
        firstClass = cc;
    }
    else if (isSecondClass(cc)) {
        firstClass = toFirstClass(cc);
    }

    switch (firstClass) {
    case ccWizard:
        return static_cast<int>(intellect * 0.35);
    case ccFighter:
        return static_cast<int>(intellect * 0.25);
    case ccRogue:
        return static_cast<int>(intellect * 0.19);
    }
    return 0;
}


inline int16_t getPhysicalCriticalRate(int strength, int dexterity)
{
    return static_cast<int16_t>((strength * 0.1f) + (dexterity * 0.4f));
}


inline int16_t getPhysicalCriticalRate(const BaseStatus& baseStatus)
{
    return getPhysicalCriticalRate(baseStatus[bsiStrength], baseStatus[bsiDexterity]);
}


inline int16_t getMagicCriticalRate(int intellect)
{
    return static_cast<int16_t>((intellect * 0.5f));
}


inline int16_t getMagicCriticalRate(const BaseStatus& baseStatus)
{
    return getMagicCriticalRate(baseStatus[bsiIntellect]);
}


inline int16_t getParryRate(int strength, int dexterity)
{
    return static_cast<int16_t>((strength * 0.5f) + (dexterity * 0.25f));
}


inline int16_t getParryRate(const BaseStatus& baseStatus)
{
    return getParryRate(baseStatus[bsiStrength], baseStatus[bsiDexterity]);
}


inline int16_t getBlockRate(int strength, int intellect)
{
    return static_cast<int16_t>((strength * 0.7f) + (intellect * 0.3f));
}


inline int16_t getBlockRate(const BaseStatus& baseStatus)
{
    return getBlockRate(baseStatus[bsiStrength], baseStatus[bsiIntellect]);
}


inline int16_t getDodgeRate(int dexterity, int intellect)
{
    return static_cast<int16_t>((dexterity * 0.5f) + (intellect * 0.25f));
}


inline int16_t getDodgeRate(const BaseStatus& baseStatus)
{
    return getDodgeRate(baseStatus[bsiDexterity], baseStatus[bsiIntellect]);
}


inline int16_t getDefencevalue(CharacterClass cc, int strength, int energy)
{
    if (isCommonClass(cc)) {
        return static_cast<int16_t>(((strength * 0.25) + (energy * 0.025)) * 0.25);
    }

    // TODO: 2차 직업 스탯 추가
    CharacterClass firstClass = ccUnknown;
    if (isFirstClass(cc)) {
        firstClass = cc;
    }
    else if (isSecondClass(cc)) {
        firstClass = toFirstClass(cc);
    }

    switch (firstClass) {
    case ccWizard:
        return static_cast<int16_t>(((strength * 0.4) + (energy * 0.025)) * 0.5);
    case ccFighter:
        return static_cast<int16_t>(((strength * 0.5) + (energy * 0.025)) * 0.5);
    case ccRogue:
        return static_cast<int16_t>(((strength * 0.4) + (energy * 0.025)) * 0.5);
    }
    return 0;
}


} // namespace gideon {