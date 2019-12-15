#pragma once

#include "UserId.h"
#include "ZoneInfo.h"
#include "InventoryInfo.h"
#include "AppearanceInfo.h"
#include "LevelInfo.h"
#include <esut/Random.h>
#include <array>

namespace gideon {

/**
 * @enum HitPoint
 */
enum BaseStatusIndex
{
    bsiStrength, // 힘
    bsiDexterity,  // 민첩
    bsiIntellect, // 지혜
    bsiEnergy, // 활력
    
    bsiCount,
};


/**
 * @class BaseStatus
 */
class BaseStatus : public std::array<int32_t, bsiCount>
{
public:
    BaseStatus() {
        fill(0);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        for (int i = 0; i < bsiCount; ++i) {
            stream & data()[i];
        }
    }
};


/**
 * @enum AttackPowerIndex
 */
enum AttackPowerIndex
{
    apiMinAttack,    // 최소뎀
    apiMaxAttack,    // 맥뎀
    apiPhysical,     // 물리
    apiMagic,        // 마법
    apiCount,
};


/**
 * @class AttackPower
 */
class AttackPowers : public std::array<int32_t, apiCount>
{
public:
    AttackPowers() {
        fill(0);
    }

    int32_t getMinCalcAttackValue(AttackPowerIndex usePower, int32_t attributeValue) const {
        if (apiPhysical == usePower || apiMagic == usePower) {
            return getAttackValue(apiMinAttack, usePower) + attributeValue;
        }
        return 0;
    }

    int32_t getMaxCalcAttackValue(AttackPowerIndex usePower, int32_t attributeValue) const {
        if (apiPhysical == usePower || apiMagic == usePower) {
            return getAttackValue(apiMaxAttack, usePower) + attributeValue;
        }
        return 0;
    }

    int32_t getRandomCalcAttackValue(AttackPowerIndex usePower, int32_t attributeValue) const {
        return esut::random(getMinCalcAttackValue(usePower, attributeValue),
            getMaxCalcAttackValue(usePower, attributeValue));
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        for (int i = 0; i < apiCount; ++i) {
            stream & data()[i];
        }
    }

private:
    int32_t getAttackValue(AttackPowerIndex minMaxIndex, AttackPowerIndex usePower) const {
        return static_cast<int32_t>((data()[minMaxIndex] + data()[usePower]) + (data()[usePower] * 0.6f));
    }
};


/**
 * @enum AttackStatusIndex
 */
enum AttackStatusIndex
{
    atsiHitRate,
    atsiPhysicalCriticalRate,
    atsiMagicCriticalRate,
    atsiCount
};

/**
 * @class AttackStatus
 */
class AttackStatus : public std::array<int16_t, atsiCount>
{
public:
    AttackStatus() {
        fill(0);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        for (int i = 0; i < atsiCount; ++i) {
            stream & data()[i];
        }
    }
};


/**
 * @enum DefenceStatusIndex
 */
enum DefenceStatusIndex
{
    dsiBlockRate,
    dsiDodgeRate,
    dsiParryRate,
    dsiDefence,
    dsiCount,
};


/**
 * @class DefenceStatus
 */
class DefenceStatus : public std::array<int16_t, dsiCount>
{
public:
    DefenceStatus() {
        fill(0);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        for (int i = 0; i < dsiCount; ++i) {
            stream & data()[i];
        }
    }
};

/**
 * @class AttributeType
 */
enum AttributeRateType
{
    abtNone,
    abtLight,
    abtDark,
    abtFire,
    abtIce,
};


inline bool isValid(AttributeRateType type) 
{
    return abtLight <= type && type <= abtIce;
}

template <typename T>
inline AttributeRateType toAttributeRateType(T value)
{
    return static_cast<AttributeRateType>(static_cast<uint8_t>(value));
}

/**
 * @class AttributeRateIndex
 */
enum AttributeRateIndex
{
    abiLight,
    abiDark,
    abiFire,
    abiIce,
    abiCount,
};


inline AttributeRateIndex getAttributeRateIndex(AttributeRateType type)
{
    switch (type) {
    case abtLight:
        return abiLight;
    case abtDark:
        return abiDark;
    case abtFire:
        return abiFire;
    case abtIce:
        return abiIce;
    }
    assert(false);
    return abiCount;     
}

/**
 * @class AttributeRates
 */
class AttributeRates : public std::array<int16_t, abiCount>
{
public:
    AttributeRates() {
        fill(0);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        for (int i = 0; i < abiCount; ++i) {
            stream & data()[i];
        }
    }
};

/**
 * @enum HitPoint
 */
enum HitPoint
{
    hpUnknown = -1,
    hpMin = 0,
    hpMax = INT_MAX,

    hpDefault = 100
};


inline bool isValid(HitPoint hp)
{
    return (hpMin <= hp) && (hp <= hpMax);
}


inline bool isDied(HitPoint hp)
{
    return hp <= hpMin;
}


template <typename T>
inline HitPoint toHitPoint(T value)
{
    const HitPoint point = static_cast<HitPoint>(static_cast<int32_t>(value));
    assert(isValid(point));
    return point;
}


/**
 * @enum ManaPoint
 */
enum ManaPoint
{
    mpMin = 0,
    mpMax = INT_MAX,

    mpDefault = 100
};


inline bool isValid(ManaPoint mp)
{
    return (mpMin <= mp) && (mp <= mpMax);
}


template <typename T>
inline ManaPoint toManaPoint(T value)
{
    const ManaPoint point = static_cast<ManaPoint>(static_cast<int32_t>(value));
    assert(isValid(point));
    return point;
}


/**
 * @struct HitPoints
 * HP/MaxHP
 */
struct HitPoints
{
    HitPoint hp_;
    HitPoint maxHp_;

    explicit HitPoints(HitPoint hp = hpMin, HitPoint maxHp = hpMin) :
        hp_(hp),
        maxHp_(maxHp) {}

    void reset() {
        hp_ = hpMin;
        maxHp_ = hpMin;
    }

    void reduce(HitPoint hp) {
        assert(hp >= hpMin);
        if (hp_ < hp) {
            hp_ = hpMin;            
        }
        else {
            hp_ = toHitPoint(hp_ - hp);
        }
    }

    void refill(HitPoint hp) {
        assert(hp >= hpMin);
        hp_ = toHitPoint(hp_ + hp);
        if (hp_ > maxHp_) {
            hp_ = maxHp_;            
        }
        
    }

    bool isMin() const {
        return hp_ <= hpMin;
    }

    bool isMax() const {
        return hp_ <= maxHp_;
    }

        
    template <typename Stream>
    void serialize(Stream& stream) {
        stream & hp_ & maxHp_;
    }
};

/**
 * @struct ManaPoints
 * MP/MaxMp
 */
struct ManaPoints
{
    ManaPoint mp_;
    ManaPoint maxMp_;

    explicit ManaPoints(ManaPoint mp = mpMin, ManaPoint maxMp = mpMin) :
        mp_(mp),
        maxMp_(maxMp) {}

    void reset() {
        mp_ = mpMin;
        maxMp_ = mpMin;
    }

    void reduce(ManaPoint mp) {
        assert(mp >= mpMin);
        if (mp_ < mp) {
            mp_ = mpMin;            
        }
        else {
            mp_ = toManaPoint(mp_ - mp);
        }
    }

    void refill(ManaPoint mp) {
        assert(mp >= mpMin);
        mp_ = toManaPoint(mp_ + mp);
        if (maxMp_ < mp_) {
            mp_ = maxMp_;            
        }
        else {
            mp_ = toManaPoint(mp_ + mp);
        }
    }

    bool isMin() const {
        return mp_ <= mpMin;
    }

    bool isMax() const {
        return mp_ <= maxMp_;
    }
        
    template <typename Stream>
    void serialize(Stream& stream) {
        stream & mp_ & maxMp_;
    }
}; 



/**
 * @struct Points
 * HP/MP/CP
 */
struct Points
{
    HitPoint hp_;
    ManaPoint mp_;

    explicit Points(HitPoint hp = hpMin, ManaPoint mp = mpMin) :
        hp_(hp),
        mp_(mp) {}

	Points(const Points& point) :
		hp_(point.hp_),
		mp_(point.mp_) {}

    void reset() {
        hp_ = hpMin;
        mp_ = mpMin;
    }

    bool isMinPoints() const {
        return hp_ == hpMin && mp_ == mpMin;
    }

	void setHp(HitPoint hp, bool canDie) {
		if (hp < hpMin && ! canDie) {			
			hp_ = toHitPoint(hpMin + 1);			
		}
		else {
			hp_ = hp;
		}
	}

	void setMp(ManaPoint mp) {		
		mp_ = mp ;
	}

    void reduceHp(HitPoint hp, bool canDie) {
        HitPoint temp = hpMin;
        reduceHp(temp, hp, canDie);
    }

    void reduceHp(HitPoint& applyPoint, HitPoint hp, bool canDie) {
        assert(hp >= hpMin);
        if (hp_ < hp) {
            if (canDie) {
                applyPoint = toHitPoint(applyPoint + hp_);
                hp_ = hpMin;
            }
            else {
                applyPoint = toHitPoint(applyPoint + hp_ - 1);
                hp_ = toHitPoint(hpMin + 1);
            }
        }
        else {
            hp_ = toHitPoint(hp_ - hp);
            applyPoint = toHitPoint(applyPoint + hp);
        }
    }

    void reduceMp(ManaPoint mp) {
        ManaPoint temp = mpMin;
        reduceMp(temp, mp);
    }

    void reduceMp(ManaPoint& applyPoint, ManaPoint mp) {
        assert(mp >= mpMin);
        if (mp_ < mp) {
            applyPoint = toManaPoint(applyPoint + mp_);
            mp_ = mpMin;
        }
        else {
            applyPoint = toManaPoint(applyPoint + mp);
            mp_ = toManaPoint(mp_ - mp);
        }
    }    

    void fillHp(HitPoint hp) {
        assert(hp >= hpMin);
        hp_ = toHitPoint(hp_ + hp);
    }

    void fillMp(ManaPoint mp) {
        assert(mp >= mpMin);
        mp_ = toManaPoint(mp_ + mp);
    }

    
    void refillPoints(const Points& maxPoints) {
        hp_ = maxPoints.hp_;
        mp_ = maxPoints.mp_;
    }

    void clampPoints(const Points& maxPoints) {
        clamp(hp_, hpMin, maxPoints.hp_);
        clamp(mp_, mpMin, maxPoints.mp_);
    }

    bool isDied() const {
        return gideon::isDied(hp_);
    }

    bool isValid() const {
        return gideon::isValid(hp_) && gideon::isValid(mp_);
    }

    bool operator==(const Points& rhs) const {
        return (hp_ == rhs.hp_) && (mp_ == rhs.mp_);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & hp_ & mp_;
    }

private:
    template <typename T>
    void clamp(T& value, T vMin, T vMax) {
        if (value < vMin) {
            value = vMin;
        }
        else if (value > vMax) {
            value = vMax;
        }       
    }
};


/**
 * @enum PointType
 * 
 */
enum PointType
{
    ptUnknown, 
    ptHp,
    ptMp,
    ptCount,
};


inline bool isValid(PointType pt)
{
    return ptUnknown < pt && pt < ptCount;
}


template <typename T>
inline PointType toPointType(T value)
{
    return static_cast<PointType>(static_cast<uint8_t>(value));
}

} // namespace gideon {

namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::HitPoint rhs)
{
    lhs << static_cast<uint32_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::HitPoint& rhs)
{
    uint32_t value;
    lhs >> value;
    rhs = static_cast<gideon::HitPoint>(value);
    return lhs;
}


inline OStream& operator<<(OStream& lhs, gideon::ManaPoint rhs)
{
    lhs << static_cast<uint32_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::ManaPoint& rhs)
{
    uint32_t value;
    lhs >> value;
    rhs = static_cast<gideon::ManaPoint>(value);
    return lhs;
}


inline OStream& operator<<(OStream& lhs, gideon::PointType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::PointType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::PointType>(value);
    return lhs;
}

}} // namespace sne { namespace core {
