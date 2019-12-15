#pragma once

#include "EffectInfo.h"
#include "StatusInfo.h"
#include <sne/srpc/RpcContainers.h>

namespace gideon {

/**
 * @enum EffectStatusType
 * 스킬 결과값에 이용되는 스텟값들
 */
enum EffectStatusType
{
    esttNone,
    esttStrength, // 힘
    esttDexterity,  // 민첩
    esttIntellect, // 지혜
    esttEnergy, // 활력
    esttHitRate,
    esttPhysicalCriticalRate, //
    esttBlockRate,
    esttDodgeRate,
    esttDefence,
    esttLight, // 10
    esttDark,
    esttFire,
    esttIce,
    esttLightResist,
    esttDarkResist,
    esttFireResist,
    esttIceResist,
    esttHp,
    esttMp,
    esttMinAttack,    // 최소뎀 20
    esttMaxAttack,    // 맥뎀
    esttPhysical,     // 물리
    esttMagic,        // 마법'
    esttCasterCalcPhysical,
    esttCasterCalcMagic,  // 25
    esttMagicCriticalRate, //
};


template <typename T>
EffectStatusType toEffectStatusType(T value)
{
    return static_cast<EffectStatusType>(static_cast<uint8_t>(value));
}


inline bool isStatusType(EffectStatusType type)
{
    return esttStrength <= type && type <= esttMagic;
}


inline bool isBaseStatusType(EffectStatusType type) 
{
    return esttStrength <= type && type <= esttEnergy;
}


inline BaseStatusIndex getBaseStatusIndex(EffectStatusType type) 
{    
    switch (type) {
    case esttStrength:
        return bsiStrength;
    case esttDexterity:
        return bsiDexterity;
    case esttIntellect:
        return bsiIntellect;
    case esttEnergy:
        return bsiEnergy;
    }
    assert(false);
    return bsiCount; // invalidValue
}


inline bool isAttackPowerStatusType(EffectStatusType type) 
{
    return esttMinAttack <= type && type <= esttMagic;
}


inline AttackPowerIndex getAttackPowerIndex(EffectStatusType type)
{
    switch (type) {
    case esttMinAttack:
        return apiMinAttack;
    case esttMaxAttack:
        return apiMaxAttack;
    case esttCasterCalcPhysical:
    case esttPhysical:
        return apiPhysical;
    case esttCasterCalcMagic:
    case esttMagic:
        return apiMagic;
    }
    assert(false);
    return apiCount; // invalidValue
}


inline bool isAttackStatusType(EffectStatusType type) 
{
    return esttHitRate == type || esttPhysicalCriticalRate == type || esttMagicCriticalRate == type;
}


inline AttackStatusIndex getAttackStatusIndex(EffectStatusType type) 
{
    switch (type) {
    case esttHitRate:
        return atsiHitRate;
    case esttPhysicalCriticalRate:
        return atsiPhysicalCriticalRate;
    case esttMagicCriticalRate:
        return atsiMagicCriticalRate;
    }
    assert(false);
    return atsiCount; // invalidValue
}


inline bool isDefenceStatusType(EffectStatusType type)
{
    return esttBlockRate == type || esttDodgeRate == type || esttDefence == type;
}


inline DefenceStatusIndex getDefenceStatusIndex(EffectStatusType type) 
{
    switch (type) {
    case esttBlockRate:
        return dsiBlockRate;
    case esttDodgeRate:
        return dsiDodgeRate;
    case esttDefence:
        return dsiDefence;
    }
    assert(false);
    return dsiCount; // invalidValue
}


inline bool isAttributeRateType(EffectStatusType type)
{
    return esttLight <= type && type <= esttIceResist;
}


inline AttributeRateIndex getAttributeRateIndex(EffectStatusType type)
{
    switch (type) {
    case esttLight:
    case esttLightResist:
        return abiLight;
    case esttDark:
    case esttDarkResist:
        return abiDark;
    case esttFire:
    case esttFireResist:
        return abiFire;
    case esttIce:
    case esttIceResist:
        return abiIce;
    }
    assert(false);
    return abiCount; // invalidValue
}


inline bool isAttributeRateResist(EffectStatusType type)
{
    switch (type) {
    case esttDarkResist:
    case esttLightResist:
    case esttFireResist:
    case esttIceResist:
        return true;
    }
    assert(false);
    return false; // invalidValue
}


inline bool isCalcAttackType(EffectStatusType type) 
{
    return esttCasterCalcPhysical == type || type == esttCasterCalcMagic;
}

} //namespace gideon {


namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::EffectStatusType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::EffectStatusType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::EffectStatusType>(value);
    return lhs;
}

}} // namespace sne { namespace core {