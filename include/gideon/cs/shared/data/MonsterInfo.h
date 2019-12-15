#pragma once

#include "NpcInfo.h"
#include <cassert>

namespace gideon {

/**
 * 몬스터 등급
 */
enum MonsterGrade
{
    mgUnknown = 0,

    mgInfant = 1, //< 유아 형태
    mgOriginal = 2, //< 원 형태
    mgMutantInfant = 3, //< 변질 유아 형태
    mgMutant = 4, //< 변질 형태
    mgEvolution = 5, //< 진화형
    mgBoss = 6, //< 우두머리
    mgMutantBoss = 7, //< 변질 우두머리

    mgBoundary
};


inline bool isValid(MonsterGrade grade)
{
    return (mgUnknown < grade) && (grade < mgBoundary);
}


inline bool isNormalMonster(MonsterGrade grade)
{
    return (mgInfant <= grade) && (grade <= mgMutantInfant);
}


inline bool isEliteMonster(MonsterGrade grade)
{
    return (mgMutant <= grade) && (grade <= mgEvolution);
}


inline bool isBossMonster(MonsterGrade grade)
{
    return (mgBoss <= grade) && (grade <= mgMutantBoss);
}

} // namespace gideon {
