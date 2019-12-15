#pragma once

#include <gideon/cs/shared/data/SkillInfo.h>
#include <gideon/cs/shared/data/SkillCastableEquipItemTypeInfo.h>
#include <gideon/cs/shared/data/CharacterClass.h>
#include <gideon/cs/shared/data/EquipmentInfo.h>
#include <gideon/cs/shared/data/Time.h>

namespace gideon { namespace datatable {

/***
 * @struct SkillCastingInfo
 ***/
struct SkillCastingInfo
{
    CastType castType_;
    GameTime castTime_;
    
    explicit SkillCastingInfo(CastType castType = catDefault, GameTime castTime = 0) :
        castType_(castType),
        castTime_(castTime)
    {
    }

    bool hasCastingTime() const {
        return castTime_ > 0;
    }
};

/***
 * @struct DistanceRangeInfo
 ***/
struct DistanceRangeInfo
{
    float minDistance_;
    float maxDistance_;

    explicit DistanceRangeInfo(float minDistance = 0.0f, float maxDistance = 0.0f) :
        minDistance_(minDistance),
        maxDistance_(maxDistance)
    {
    }

    float getMinDistanceSq() const {
        return minDistance_ * minDistance_;
    }

    float getMaxDistanceSq() const {
        return maxDistance_ * maxDistance_;
    }
};


/***
 * @struct SkillCastCheckPointInfo
 ***/
struct SkillCastCheckPointInfo
{
    CheckStatTargetType checkStatTarget_;
    PointType pointType_;
    bool isUpCheckValue_;
    bool isUsePercent_;
    uint32_t checkValue_;

    explicit SkillCastCheckPointInfo(CheckStatTargetType checkStatTarget = csttNone, PointType pointType = ptUnknown,
        bool isUpCheckValue = false, bool isUsePercent = false, uint32_t checkValue = 0) :
        checkStatTarget_(checkStatTarget),
        pointType_(pointType),
        isUpCheckValue_(isUpCheckValue),
        isUsePercent_(isUsePercent),
        checkValue_(checkValue)
    {
    }

    bool isValid() const {
        return (checkStatTarget_ == csttCaster  || checkStatTarget_ == csttCastee) && 
            gideon::isValid(pointType_);
    }
};


/***
 * @struct SkillCoolTimeInfo
 ***/
struct SkillCoolTimeInfo
{
    uint32_t globalCooldownTimeIndex_;
    GameTime globalCooldownMilSec_;
    GameTime cooldownMilSec_;

    explicit SkillCoolTimeInfo(uint32_t globalCooldownTimeIndex = 0, 
        GameTime globalCooldownMilSec = 0, GameTime cooldownMilSec = 0) :
        globalCooldownTimeIndex_(globalCooldownTimeIndex),
        globalCooldownMilSec_(globalCooldownMilSec),
        cooldownMilSec_(cooldownMilSec)
    {
    }

    bool hasGlobalCooldown() const {
        return globalCooldownTimeIndex_ > 0;
    }

    bool hasCooldown() const {
        return cooldownMilSec_ > 0;
    }
};


/***
 * @struct SkillActivateTimeInfo
 ***/
struct SkillActivateTimeInfo
{
    GameTime activateMilSec_;
    GameTime activateIntervalMilSec_;

    explicit SkillActivateTimeInfo(GameTime activateMilSec = 0, GameTime activateIntervalMilSec = 0) :
        activateMilSec_(activateMilSec),
        activateIntervalMilSec_(activateIntervalMilSec)
    {
    }

    bool isDot() const {
        return 0 < activateMilSec_ && 0 < activateIntervalMilSec_;
    }
};


typedef std::array<SkillActivateTimeInfo, eanCount> SkillActivateTimeInfos;

/***
 * @struct ChannelSkillTimeInfo
 ***/
struct ChannelSkillTimeInfo
{
    GameTime channelCastingMilSec_;
    GameTime channelIntervalMilSec_;
    GameTime channelApplyCount_;

    explicit ChannelSkillTimeInfo(GameTime channelCastingMilSec = 0, GameTime channelIntervalMilSec = 0) :
        channelCastingMilSec_(channelCastingMilSec),
        channelIntervalMilSec_(channelIntervalMilSec)
    {        
        if (channelCastingMilSec_ > 0 && channelIntervalMilSec_ > 0) {
            channelApplyCount_ = channelCastingMilSec_ / channelIntervalMilSec_;
        }
        else if (channelCastingMilSec_ > 0 && channelIntervalMilSec_ == 0) {
            channelApplyCount_ = 1;
        }
        else {
            channelApplyCount_ = 0;
        }
    }

    bool isValid() const {
        return channelApplyCount_ > 0;
    }
};


/***
 * @struct SkillCheckEquipItemInfo
 ***/
struct SkillCheckEquipItemInfo
{
    EquipPart equipPart_;
    SkillCastableEquipType castableEquipType_;

    explicit SkillCheckEquipItemInfo(EquipPart equipPart = epInvalid,
        SkillCastableEquipType castableEquipType = scetAny) :        
        equipPart_(equipPart),
        castableEquipType_(castableEquipType)
    {
    }

    bool isValid() const {
        return gideon::isValid(equipPart_) || shouldCheckable(castableEquipType_);
    }
};


/***
 * @struct SkillLearnInfo
 ***/
struct SkillLearnInfo
{
    CharacterClass learnCharacterClass_;
    SkillCode needLearnSkillCode1_;
    SkillCode needLearnSkillCode2_;
    SkillCode nextSkillCode1_;
    SkillCode nextSkillCode2_;
    SkillPoint needSp_;

    explicit SkillLearnInfo(CharacterClass learnCharacterClass = ccAny,  
        SkillCode needLearnSkillCode1 = invalidSkillCode,
        SkillCode needLearnSkillCode2 = invalidSkillCode,
        SkillCode nextSkillCode1 = invalidSkillCode,
        SkillCode nextSkillCode2 = invalidSkillCode,
        SkillPoint needSp = spMax) :
        learnCharacterClass_(learnCharacterClass),
        needLearnSkillCode1_(needLearnSkillCode1),
        needLearnSkillCode2_(needLearnSkillCode2),
        nextSkillCode1_(nextSkillCode1),
        nextSkillCode2_(nextSkillCode2),
        needSp_(needSp)
    {
    }

    bool canLearnCharacterClass(CharacterClass cc) const {
        if (learnCharacterClass_ == ccAny) {
            return true;
        }        
                
        if (! isLastCharacterClassGroup(learnCharacterClass_)) {
            return true;    
        }
                
        return cc == learnCharacterClass_;
    }
};


}} // namespace gideon { namespace datatable {
