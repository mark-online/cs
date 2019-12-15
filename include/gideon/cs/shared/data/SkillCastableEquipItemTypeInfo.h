#pragma once

#include "EquipmentInfo.h"

namespace gideon {
    

/**
 * @enum SkillCastableEquipType
 * 장비 종류
 */
enum SkillCastableEquipType
{
    scetAny = 0, //< 무저건 사용가능
    scetClothHelmet = 1, //< 천 투구
    scetLeatherHelmet = 2, //< 가죽 투구
    scetMetalHelmet = 3, //< 금속 투구
    scetClothShoulder = 4, //< 천 어깨
    scetLeatherShoulder = 5, //< 가죽 어깨
    scetMetalShoulder = 6, //<금속 어깨
    scetClothArmor = 7, //< 천 갑옷
    scetLeatherArmor = 8, //< 가죽 갑옷
    scetMetalArmor = 9, //< 금속 갑옷
    scetClothWaist = 10, //< 천 허리
    scetLeatherWaist = 11, //< 가죽 허리
    scetMetalWaist = 12, //< 금속 허리
    scetClothTrousers = 13, //< 천 바지
    scetLeatherTrousers = 14, //< 가죽 바지
    scetMetalTrousers = 15, //< 금속 바지
    scetClothGaiters = 16, //< 천 각반
    scetLeatherGaiters = 17, //< 가죽 각반
    scetMetalGaiters = 18, //< 금속 각반
    scetClothShoes = 19, //< 천 신발
    scetLeatherShoes = 20, //< 가죽 신발
    scetMetalShoes = 21, //< 금속 신발
    scetClothGloves = 22, //< 천 장갑
    scetLeatherGloves = 23, //< 가죽 장갑
    scetMetalGloves = 24, //< 금속 장갑
    scetOneHandSword = 25, //< 한손 검류(onehandsword)
    scetBothHandsSword = 26, //< 양손 검류(twohandsword)
    scetOneHandBlunt = 27, //< 한손 타격류(onehandblunt)
    scetTwoHandsBlunt = 28, //< 양손 타격류(twohandblunt)
    scetDualWeapon = 29, //< 이도류
    scetStaff = 30, //< 지팡이 류(staff)
    scetThrowing = 31, //< 투척 류(throwing)
    scetBow = 32, //< 장궁류(bow)
    scetCrossbow = 33, //< 석궁류(crossbow)
    scetShield = 34, //< 방패류(Shield)
    scetOneWeapon = 35, // 한손 검류, 한손 타격류(장비종류를 25,27, 29번 체크합니다.)
    scetTwoWeapon = 36, // 양손 검류, 양손 타격류(장비종류를 26,28번 체크합니다.)
    scetMeleeWeapon = 37, // 한손 검류, 양손 검류, 한손 타격류, 양손 타격류, 창 류, 지팡이류(25~30 을 체크 합니다.)
    scetRangeWeapon = 38, // 장궁류, 석궁류(31, 32 를 체크 합니다.)
    scetCount,
};


inline bool isValid(SkillCastableEquipType type)
{
    return scetAny <= type && type < scetCount;
}


inline bool shouldCheckable(SkillCastableEquipType type) 
{
    return scetAny < type && type < scetCount;
}


inline bool isOneMatch(SkillCastableEquipType type)
{
    return scetClothHelmet <= type && type <= scetShield;
}

template <typename T>
inline SkillCastableEquipType toSkillCastableEquipType(T value)
{
    return static_cast<SkillCastableEquipType>(static_cast<uint8_t>(value));
}


inline SkillCastableEquipType toSkillCastableEquipType(EquipType type)
{
    return static_cast<SkillCastableEquipType>(type);
}


inline bool isOneHandWeapon(SkillCastableEquipType type)
{
    return (scetOneHandSword == type) || (scetOneHandBlunt == type) || (scetDualWeapon == type);
}


inline bool isDualWeapon(SkillCastableEquipType type)
{
    return (scetDualWeapon == type);
}


inline bool isTwoHandWeapon(SkillCastableEquipType type)
{
    return (scetBothHandsSword == type) || (scetTwoHandsBlunt == type);
}


inline bool isStaffWeapon(SkillCastableEquipType type)
{
    return (scetStaff == type);
}


inline bool isRange(SkillCastableEquipType type)
{
    return (scetBow == type) || (scetCrossbow == type);
}

inline bool isBowWeapon(SkillCastableEquipType type)
{
    return (scetBow == type);
}

inline bool isCrossbowWeapon(SkillCastableEquipType type)
{
    return (scetCrossbow == type);
}

inline bool isShield(SkillCastableEquipType type)
{
    return (scetShield == type);
}


inline bool isSkillCastableEquipType(SkillCastableEquipType castableType, EquipType type)
{       
    SkillCastableEquipType equipedType = toSkillCastableEquipType(type);
    if (castableType == scetAny) {
        return true;
    }
    else if (isOneMatch(castableType)) {
        return equipedType == castableType;
    }
    else if (castableType == scetOneWeapon) {
        return isOneHandWeapon(equipedType);
    }
    else if (castableType == scetTwoWeapon) {
        return isTwoHandWeapon(equipedType);
    }
    else if (castableType == scetStaff) {
        return isStaffWeapon(equipedType);
    }
    else if (castableType == scetMeleeWeapon) {
        return isOneHandWeapon(equipedType) || isTwoHandWeapon(equipedType) ||
            isStaffWeapon(equipedType);
    }
    else if (castableType == scetRangeWeapon) {
        return isRange(equipedType);
    }

    return false;
}

} // namespace gideon {