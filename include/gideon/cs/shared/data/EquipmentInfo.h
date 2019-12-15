#pragma once

#include "InventoryInfo.h"
#include <cassert>

namespace gideon {

/**
 * 장착 장비 코드
 * - Category(1B) | Subcategory(1B) | Index(2B)
 */
typedef DataCode EquipCode;
const EquipCode invalidEquipCode = invalidDataCode;


/**
 * @enum EquipPart
 * 장비 장착 부위 (서브 카테고리)
 */
enum EquipPart 
{
    epInvalid = 0, //< 착용될 슬롯 없음
    epFirst = 1,

    epBaseHair = epFirst, //< 베이스_헤어
    epBaseFace = 2, //< 베이스_얼굴
    epBaseUpperBody = 3, //< 베이스_상체
    epBaseLowerBody = 4, //< 베이스_하체
    epBaseHands = 5, //< 베이스_손
    epBaseFoots = 6, //< 베이스_발
    epBaseUpperUnderwear = 7, //< 베이스_속옷상의
    epBaseLowerUnderwear = 8, //< 베이스_속옷하의
    epHelmet = 9, //< 투구
    epShoulder = 10, //< 어깨
    epArmor = 11, //< 갑옷
    epWaist = 12, //< 허리
    epTrousers = 13, //< 바지
    epGaiters = 14, //< 각반
    epGloves = 15, //< 장갑
    epShoes = 16, //< 신발
    epRightHand = 17, //< 오른손 장비
    epLeftHand = 18, //< 왼손 장비
    epTwoHands = 19, //< 양손 장비

    epCount,
    epEnd = epCount - 1
};


inline bool isValid(EquipPart ep)
{
    return (epFirst <= ep) && (ep <= epEnd);
}

inline bool isWeaponPart(EquipPart ep) 
{
    return epRightHand == ep || epLeftHand == ep || epTwoHands == ep; 
}

inline bool isArmorPart(EquipPart ep)
{
    return epHelmet == ep || epShoulder == ep || epArmor == ep || epWaist == ep || epTrousers == ep || epGaiters == ep || epGloves == ep || epShoes == ep;
}

inline bool isOneHandWeapon(EquipPart ep)
{
    return epRightHand == ep || epLeftHand == ep;
}


template <typename T>
inline EquipPart toEquipPart(T value)
{
    return static_cast<EquipPart>(static_cast<int32_t>(value));
}

/// EquipCode를 만든다
inline EquipCode makeEquipCode(EquipPart ep, uint16_t index)
{
    return getMinGideonCode(ctEquipment) + (ep << 16) + index;
}


inline EquipPart getEquipPart(EquipCode ec)
{
    assert(getCodeType(ec) == ctEquipment);
    return static_cast<EquipPart>((ec & 0x00FF0000) >> 16);
}


inline uint16_t getEquipCodeIndex(EquipCode ec)
{
    assert(getCodeType(ec) == ctEquipment);
    return static_cast<uint16_t>(ec & 0x0000FFFF);
}


/// EquipCode를 파싱한다
inline bool parseEquipCode(EquipPart& ep, uint16_t& index, EquipCode ec)
{
    ep = epInvalid;
    index = 0;

    const CodeType codeType = getCodeType(ec);
    if (codeType != ctEquipment) {
        return false;
    }

    ep = getEquipPart(ec);
    index = getEquipCodeIndex(ec);
    return true;
}


/// 유효한 장비 코드인가?
inline bool isValidEquipCode(EquipCode ec)
{
    EquipPart ep = epInvalid;
    uint16_t index = 0;
    if (! parseEquipCode(ep, index, ec)) {
        return false;
    }
    return isValid(ep) && (index > 0);
}


/**
 * @enum MaterialType
 * 재질
 */
enum MaterialType
{
    matUnknown = 0,
    matCloth = 1, //< 천
    matLeather = 2, //< 가죽
    matMetal = 3, //< 금속

    matOneHandWood = 4, //< 한손 나무 무기류
    matTwoHandWood = 5, //< 양손 나무 무기류
    matOneHandMetal = 6, //< 한손 철 무기류
    matTwoHandMetal = 7, //< 양손 철 무기류
    matBow = 8, //< 활(석궁)
    matShield = 9, //< 방패

    matUnarmedSmall = 10, //< 작은 맨 손(인간 주먹, 작은 크기 몬스터 발 등)
    matUnarmedMedium = 11, //< 큰 맨 손(중간 크기 몬스터 발 등)
    matUnarmedLarge = 12, //< 아주 큰 맨 손(큰 크기 몬스터 발 등)

    matFlesh = 13, //< 육체
    matStone = 14, //< 돌 재질(집)
    matWood = 15, //< 나무 재질(공성 무기)

    matCount
};


inline bool isValid(MaterialType mt)
{
    return (matUnknown < mt) && (mt < matCount);
}

/**
 * @enum EquipType
 * 장비 종류
 */
enum class EquipType : uint8_t
{
    etUnknown = 0, //< 장비 아님
    etClothHelmet = 1, //< 천 투구
    etLeatherHelmet = 2, //< 가죽 투구
    etMetalHelmet = 3, //< 금속 투구
    etClothShoulder = 4, //< 천 어깨
    etLeatherShoulder = 5, //< 가죽 어깨
    etMetalShoulder = 6, //<금속 어깨
    etClothArmor = 7, //< 천 갑옷
    etLeatherArmor = 8, //< 가죽 갑옷
    etMetalArmor = 9, //< 금속 갑옷
    etClothWaist = 10, //< 천 허리
    etLeatherWaist = 11, //< 가죽 허리
    etMetalWaist = 12, //< 금속 허리
    etClothTrousers = 13, //< 천 바지
    etLeatherTrousers = 14, //< 가죽 바지
    etMetalTrousers = 15, //< 금속 바지
    etClothGaiters = 16, //< 천 각반
    etLeatherGaiters = 17, //< 가죽 각반
    etMetalGaiters = 18, //< 금속 각반
    etClothShoes = 19, //< 천 신발
    etLeatherShoes = 20, //< 가죽 신발
    etMetalShoes = 21, //< 금속 신발
    etClothGloves = 22, //< 천 장갑
    etLeatherGloves = 23, //< 가죽 장갑
    etMetalGloves = 24, //< 금속 장갑
    etOneHandSword = 25, //< 한손 검류(onehandsword)
    etBothHandsSword = 26, //< 양손 검류(twohandsword)
    etOneHandBlunt = 27, //< 한손 타격류(onehandblunt)
    etTwoHandsBlunt = 28, //< 양손 타격류(twohandblunt)
    etDualWeapon = 29, //< 이도류
    etStaff = 30, //< 지팡이 류(staff)
    etThrowing = 31, //< 투척 류(throwing)
    etBow = 32, //< 장궁류(bow)
    etCrossbow = 33, //< 석궁류(crossbow)
    etShield = 34, //< 방패류(Shield)

    etCount
};

inline bool isValid(EquipType et)
{
    return (EquipType::etUnknown < et) && (et < EquipType::etCount);
}


inline bool isBowType(EquipType et) 
{
    return EquipType::etBow == et || EquipType::etCrossbow == et;
}


inline bool isMeleeWeaponEquipped(EquipType et)
{
    switch (et) {
    case EquipType::etOneHandSword:
    case EquipType::etBothHandsSword:
    case EquipType::etOneHandBlunt:
    case EquipType::etTwoHandsBlunt:
    case EquipType::etDualWeapon:
    case EquipType::etStaff:
        return true;
    }
    return false;
}


inline MaterialType getMaterialType(EquipType et)
{
    switch (et) {
    case EquipType::etClothHelmet:
    case EquipType::etClothShoulder:
    case EquipType::etClothArmor:
    case EquipType::etClothWaist:
    case EquipType::etClothTrousers:
    case EquipType::etClothGaiters:
    case EquipType::etClothShoes:
    case EquipType::etClothGloves:
        return matCloth;
    case EquipType::etLeatherHelmet:
    case EquipType::etLeatherShoulder:
    case EquipType::etLeatherArmor:
    case EquipType::etLeatherWaist:
    case EquipType::etLeatherTrousers:
    case EquipType::etLeatherGaiters:
    case EquipType::etLeatherShoes:
    case EquipType::etLeatherGloves:
        return matLeather;
    case EquipType::etMetalHelmet:
    case EquipType::etMetalShoulder:
    case EquipType::etMetalArmor:
    case EquipType::etMetalWaist:
    case EquipType::etMetalTrousers:
    case EquipType::etMetalGaiters:
    case EquipType::etMetalShoes:
    case EquipType::etMetalGloves:
        return matMetal;;
    }
    return matUnknown;
}


template <typename T>
EquipType toEquipType(T value)
{
    return static_cast<EquipType>(static_cast<uint32_t>(value));
}

typedef sne::core::HashMap<EquipPart, EquipType> EquipPartTypeMap;

inline EquipPart getEquipPart(EquipType et)
{
    switch (et) {
    case EquipType::etClothHelmet:
    case EquipType::etLeatherHelmet:
    case EquipType::etMetalHelmet:
        return epHelmet;
    case EquipType::etClothShoulder:
    case EquipType::etLeatherShoulder:
    case EquipType::etMetalShoulder:
        return epShoulder;
    case EquipType::etClothArmor:
    case EquipType::etLeatherArmor:
    case EquipType::etMetalArmor:
        return epArmor;
    case EquipType::etClothWaist:
    case EquipType::etLeatherWaist:
    case EquipType::etMetalWaist:
        return epWaist;
    case EquipType::etClothTrousers:
    case EquipType::etLeatherTrousers:
    case EquipType::etMetalTrousers:
        return epTrousers;
    case EquipType::etClothGaiters:
    case EquipType::etLeatherGaiters:
    case EquipType::etMetalGaiters:
        return epGaiters;
    case EquipType::etClothShoes:
    case EquipType::etLeatherShoes:
    case EquipType::etMetalShoes:
        return epShoes;
    case EquipType::etClothGloves:
    case EquipType::etLeatherGloves:
    case EquipType::etMetalGloves:
        return epGloves;
    case EquipType::etOneHandSword:
    case EquipType::etOneHandBlunt:
        return epRightHand;
    case EquipType::etBothHandsSword:
    case EquipType::etTwoHandsBlunt:
    case EquipType::etDualWeapon:
    case EquipType::etStaff:
    case EquipType::etBow:
    case EquipType::etCrossbow:
        return epTwoHands;
    case EquipType::etShield:
        return epLeftHand;
    // TODO: case etThrowing:
    }
    assert(false && "invalid EquipType");
    return epInvalid;
}


/**
 * @class CreatureEquipments
 * Creature 장착 장비 정보
 */
class CreatureEquipments : public sne::srpc::RArray<EquipCode, epCount>
{
public:
    CreatureEquipments() {
        reset();
    }

    void reset() {
        fill(invalidEquipCode);
    }

    bool isValid() const {
        for (const EquipCode ec : *this) {
            if (isValidDataCode(ec)) {
                if (! isValidEquipCode(ec)) {
                    return false;
                }
            }
        }

        if (isValidEquipCode(operator[](epTwoHands))) {
            if ((isValidEquipCode(operator[](epLeftHand))) ||
                (isValidEquipCode(operator[](epRightHand)))) {
                    return false;
            }
        }
        return true;
    }
};


/**
 * @class CharacterEquipments
 * 캐릭터 장착 장비 정보
 */
class CharacterEquipments : public sne::srpc::RArray<ObjectId, epCount>
{
public:
    CharacterEquipments() {
        reset();
    }

    void reset() {
        fill(invalidObjectId);
    }

    bool isValid() const {
        if (isValidObjectId(operator[](epTwoHands))) {
            if ((isValidObjectId(operator[](epLeftHand))) ||
                (isValidObjectId(operator[](epRightHand)))) {
                return false;
            }
        }
        return true;
    }
};

} // namespace gideon {


namespace sne { namespace core {

    inline OStream& operator<<(OStream& lhs, gideon::EquipType rhs)
    {
        lhs.writeEnum(static_cast<uint64_t>(rhs), Bits<gideon::EquipType>::size);
        return lhs;
    }


    inline IStream& operator>>(IStream& lhs, gideon::EquipType& rhs)
    {
        uint64_t value;
        lhs.readEnum(value, Bits<gideon::EquipType>::size);
        rhs = static_cast<gideon::EquipType>(value);
        return lhs;
    }

}} // namespace sne { namespace core {

