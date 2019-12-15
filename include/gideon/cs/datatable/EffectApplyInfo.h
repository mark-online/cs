#pragma once

#include <gideon/cs/shared/data/Time.h>
#include <gideon/cs/shared/data/EffectInfo.h>
#include <gideon/cs/shared/data/ItemEffectInfo.h>

namespace gideon { namespace datatable {
//
///***
// * @struct BaseCastInfo
// ***/
//struct BaseCastInfo
//{
//    DataCode dataCode_;
//    TargetingType targetingType_;
//    CastType castType_;
//    AvailableTarget availableTarget_;
//    ExceptTarget exceptTarget_;
//    float minDistance_;
//    float maxDistance_;
//    EffectRangeDirection effectRangeDirection_;
//    float effectRangeValue_;	
//    GameTime castingTime_;
//    bool canCastOnMoving_;
//    GameTime coolTime_;
//    uint8_t useGlobalTimeIndex_;
//    GameTime globalCooldownTime_;
//
//    BaseCastInfo(DataCode dataCode = invalidDataCode, TargetingType targetingType = ttNoTarget,
//        CastType castType = catDefault, AvailableTarget availableTarget = atNone,
//		ExceptTarget exceptTarget = setNoExcept, float minDistance = 0,
//		float maxDistance= 0, EffectRangeDirection effectRangeDirection = erdInvalid,
//		float effectRangeValue = 0,  bool canCastOnMoving = false,
//		GameTime castingTime = 0, GameTime coolTime = 0, uint8_t useGlobalTimeIndex = 0,
//		GameTime globalCooldownTime = 0) :
//		dataCode_(dataCode),
//		targetingType_(targetingType),
//		castType_(castType),
//        canCastOnMoving_(canCastOnMoving),
//		availableTarget_(availableTarget),
//		exceptTarget_(exceptTarget),
//		minDistance_(minDistance),
//		maxDistance_(maxDistance),
//		effectRangeDirection_(effectRangeDirection),
//		effectRangeValue_(effectRangeValue),	
//		castingTime_(castingTime),
//		coolTime_(coolTime),
//		useGlobalTimeIndex_(useGlobalTimeIndex),
//		globalCooldownTime_(globalCooldownTime)
//	{
//	}
//
//    bool shouldUseGlobalCooldownTime() const {
//        return useGlobalTimeIndex_ > 0;
//    }
//
//    float getMinDistanceSq() const {
//        return minDistance_ * minDistance_;
//    }
//
//    float getMaxDistanceSq() const {
//        return maxDistance_ * maxDistance_;
//    }
//
//    bool hasCastingTime() const {
//        return castingTime_ > 0;
//    }
//
//};
//
//
///***
// * @struct BaseEffectInfo
// ***/
//struct BaseEffectInfo
//{
//    EffectStackCategory category_;
//    EffectScriptType scriptType_;
//    GameTime activateTime_;
//    GameTime tickTime_;
//    bool isPercentByValue_;
//    uint32_t effectValue_;
//
//    BaseEffectInfo(EffectStackCategory category = escNone, EffectScriptType scriptType = estUnknown, 
//        GameTime activateTime = 0, GameTime tickTime = 0, bool isPercentByValue = false,
//        uint32_t effectValue = 0) :
//        category_(category),
//        scriptType_(scriptType),
//        activateTime_(activateTime),
//        tickTime_(tickTime),
//        isPercentByValue_(isPercentByValue),
//        effectValue_(effectValue)
//    {
//    }
//
//    bool isValid() const {
//        return gideon::isValid(scriptType_);
//    }
//
//    bool isUseEffectValueByPercent() const {
//        return isPercentByValue_;
//    }
//};
//
//typedef sne::core::Vector<BaseEffectInfo> BaseEffectInfos;
//
//
///***
// * @struct ItemEffectCalculator
// ***/
//struct ItemEffectCalculator
//{
//    void applyItemEffect(const BaseEffectInfo& effectInfo, ItemEffectResult::Effect& effect,
//        const Points& targetPoints, const CreatureStatusInfo& targetCurrentCreatureStatusInfo) const
//    {
//        if (! effectInfo.isValid()) {
//            return;
//        }
//        effect.category_ = effectInfo.category_;
//        effect.scriptType_ = effectInfo.scriptType_;
//        effect.activateTimer_ = effectInfo.activateTime_;
//        effect.tickTimer_ = effectInfo.tickTime_;
//
//        if (effectInfo.effectValue_ == 0.0f) {
//            return;
//        }        
//
//        if (isMoveSpeedSkill(effect.scriptType_)) {
//            assert(effectInfo.isUseEffectValueByPercent() && "percent only");
//            effect.value_ = static_cast<float>(effectInfo.effectValue_);
//        }
//        else if (isFrenzySkill(effect.scriptType_)) {
//            // 광분은 %이기는 하지만 모델에서 계산한다.
//            effect.value_ = static_cast<float>(effectInfo.effectValue_);            
//        }
//        else {
//            float gameStatValue = 0.0f;
//            if (effectInfo.isUseEffectValueByPercent()) {                
//                gameStatValue = getGameStatValue(effectInfo.scriptType_, targetCurrentCreatureStatusInfo, targetPoints);                                                                
//                effect.value_ = (effectInfo.effectValue_ * (gameStatValue / 1000.0f));
//            }
//            else {
//                effect.value_ = static_cast<float>(effectInfo.effectValue_); 
//            }
//        }
//    }
//
//    float getGameStatValue(EffectScriptType sciptType, const CreatureStatusInfo& gameStats,
//        const Points& targetPoints) const {
//        const bool isListStat = isLifeStatNeeded(sciptType);
//        if (isListStat) {
//            if (isNeedMaxLifeStat(sciptType)) {
//                return getCreatureStatusEffectValue(sciptType, gameStats.points_);
//            }
//            else{
//                return getCreatureStatusEffectValue(sciptType, targetPoints);
//            }
//        }
//
//        return getCurrentCreatureStatusInfoEffectValue(sciptType, gameStats);;
//    }
//};

}} // namespace gideon { namespace datatable {
