#pragma once

#include "StatusInfo.h"

namespace gideon {

/**
 * @struct CreatureStatusInfo
 * 
 * - 현재 장착한 장비능력치들(total)
 */
struct CreatureStatusInfo
{
    Points points_;
    BaseStatus baseStatus_;
    AttackPowers attackPowers_;
    AttackStatus attackStatus_;
    DefenceStatus defenceStatus_;
    AttributeRates attributes_;
    AttributeRates attributeResists_;

    explicit CreatureStatusInfo(const Points& points = Points(),
        const BaseStatus& baseStatus = BaseStatus(),
        const AttackPowers& attackPowers = AttackPowers(),
        const AttackStatus& attackStatus = AttackStatus(),
        const DefenceStatus& defenceStatus = DefenceStatus(),
        const AttributeRates& attributes = AttributeRates(),
        const AttributeRates& attributeResists = AttributeRates()) :
        points_(points),
        baseStatus_(baseStatus),
        attackPowers_(attackPowers),
        attackStatus_(attackStatus),
        defenceStatus_(defenceStatus),
        attributes_(attributes),
        attributeResists_(attributeResists) {}

    void reset() {
        points_.reset();
        baseStatus_.fill(0);
        attackPowers_.fill(0);
        attackStatus_.fill(0);
        defenceStatus_.fill(0);
        attributes_.fill(0);
        attributeResists_.fill(0);
    }

    void clampPoints(Points& points) {
        points.clampPoints(points_);
    }    

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & points_ & baseStatus_ & attackPowers_ & attackStatus_ & 
            defenceStatus_ & attributes_ & attributeResists_;
    }
};


struct PlayerCreatureStatusInfo : CreatureStatusInfo
{
    //void updateStrength(CharacterClass cc) {
    //    if (cc == ccAny) {
    //        abillityPoints_.hp_ = toHitPoint((100 + (abillityStatus_[asiStrength] * 0.8) + 
    //            (abillityStatus_[asiAgility]*0.3) + (abillityStatus_[asiEnergy] * 4)));
    //        물리 (abillityStatus_[asiStrength] + (abillityStatus_[asiAgility] *0.18))/2
    //    }
    //}
};


/**
 * @struct LifeStats
 * 
 */
struct LifeStats
{
    Points currentPoints_;
    Points maxPoints_;

    explicit LifeStats(const Points currentPoints = Points(),
        const Points& maxPoints = Points()) :
        currentPoints_(currentPoints),
        maxPoints_(maxPoints)
    {
    }

	LifeStats(const LifeStats& stats) :
		currentPoints_(stats.currentPoints_),
		maxPoints_(stats.maxPoints_)
	{
	}

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & currentPoints_ & maxPoints_;
    }
};

/**
 * @struct FullCreatureStatusInfo
 * 
 */
struct FullCreatureStatusInfo
{
    Points currentPoints_;
    CreatureStatusInfo currentGameStatus_;

    explicit FullCreatureStatusInfo(const Points currentPoints = Points(),
        const CreatureStatusInfo& currentGameStatus_ = CreatureStatusInfo()) :
        currentPoints_(currentPoints),
        currentGameStatus_(currentGameStatus_)
    {
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & currentPoints_ & currentGameStatus_;
    }
};


/**
 * @struct CreatureShields
 * HP/Mp Shield
 */
struct CreatureShields
{
    bool hasHpShield_;
    bool hasMpShield_;

    HitPoints shlidHp_;
    ManaPoints shlidMp_;

    CreatureShields() :
        hasHpShield_(false),
        hasMpShield_(false)
    {}

	void reset() {
		hasHpShield_ = false;
		hasMpShield_ = false;
		shlidHp_.reset();
		shlidHp_.reset();
	}

    bool createShield(PointType pt, uint32_t point)
    {
        if (pt == ptHp) {
            if (hasHpShield_) {
                return false;
            }
            hasHpShield_ = true;
            shlidHp_.maxHp_ = toHitPoint(point);
            shlidHp_.hp_= toHitPoint(point);
        }
        else if (pt == ptMp) {
            if (hasMpShield_) {
                return false;
            }
            hasMpShield_ = true;
            shlidMp_.maxMp_ = toManaPoint(point);
            shlidMp_.mp_= toManaPoint(point);
        }
        else {
            assert(false && "Invalid type");
            return false;
        }
        return true;
    }

    bool destroyShield(PointType pt)
    {
        if (pt == ptHp) {
            if (! hasHpShield_) {
                return false;
            }
            hasHpShield_ = false;
            shlidHp_.reset();
            return true;
        }
        else if (pt == ptMp) {
            if (! hasMpShield_) {
                return false;
            }
            hasMpShield_ = false;
            shlidMp_.reset();
            return true;
        }
        else {
            assert(false && "Invalid type");
        }
        return false;
    }


    bool reduceHp(HitPoint& remainHp, HitPoint hp) {
        HitPoint temp;
        return reduceHp(temp, remainHp, hp);
    }
    
    bool reduceHp(HitPoint& applyPoint, HitPoint& remainHp, HitPoint hp) {
        assert(hp >= hpMin);
        remainHp = hp;
        if (shlidHp_.hp_ == hpMin) {
            return false;
        }
        if (shlidHp_.hp_ < hp) {
            remainHp = toHitPoint(hp - shlidHp_.hp_);
            shlidHp_.hp_ = hpMin;
            applyPoint = toHitPoint(applyPoint + shlidHp_.hp_);
        }
        else {
            shlidHp_.hp_ = toHitPoint(shlidHp_.hp_ - hp);
            applyPoint = toHitPoint(hp);
            remainHp = hpMin;
        }
               
        return true;
    }

    bool reduceMp(ManaPoint & remainMp, ManaPoint mp) {
        ManaPoint temp; 
        reduceMp(temp, remainMp, mp);
    }

    bool reduceMp(ManaPoint& applyPoint, ManaPoint & remainMp, ManaPoint mp) {
        assert(mp >= mpMin);
        remainMp = mp;
        if (shlidMp_.mp_ == mpMin) {
            return false;
        }
        if (shlidMp_.mp_ < mp) {
            applyPoint = toManaPoint(applyPoint + shlidMp_.mp_);
            remainMp = toManaPoint(mp - shlidMp_.mp_);
            shlidMp_.mp_ = mpMin;
        }
        else {
            applyPoint = toManaPoint(applyPoint + mp);
            shlidMp_.mp_ = toManaPoint(shlidMp_.mp_ - mp);
            remainMp =  mpMin;
        }
        return true;
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        const bool isInput = stream.isInput();
        stream & hasHpShield_;
        if (hasHpShield_) {
            stream & shlidHp_;
        }
        else {
            if (isInput) {
                shlidHp_.reset();
            }
        }
        stream & hasMpShield_;
        if (hasMpShield_) {
            stream & shlidMp_;
        }
        else {
            if (isInput) {
                shlidMp_.reset();
            }
        }
    }
};


} // namespace gideon {
