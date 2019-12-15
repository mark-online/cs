#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/shared/data/SkillInfo.h>
#include <gideon/cs/shared/data/EffectInfo.h>
#include <gideon/cs/shared/data/EffectStatusInfo.h>
#include <gideon/cs/datatable/template/skill_effect_table.hxx>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>


namespace gideon { namespace datatable {

/**
 * @struct EffectInfo
 */
struct EffectInfo
{
    bool shouldCritical_;
    EffectScriptType script_;
    UseTargetStatusType target_;
    bool isPercent_;
    EffectStatusType statusType_;
    
    EffectInfo(bool shouldCritical = false, EffectScriptType script = estUnknown,
        UseTargetStatusType target = utstNone, bool isPercent = false, EffectStatusType statusType = esttNone) :
        shouldCritical_(shouldCritical),
        script_(script),
        target_(target),
        isPercent_(isPercent),
        statusType_(statusType)
    {
    }

    bool isValid() const {
        return gideon::isValid(script_);
    }
};


typedef std::array<EffectInfo, eanCount> EffectInfos;


/**
 * @struct CheckEffectInfo
 */
struct CheckEffectInfo
{
    TargetingType targetingType_;
    AvailableTarget availableTarget_;
    ExceptTarget exceptTarget_;
    TargetDirection targetDirection_;
    TargetOrientation targetOrientation_;
    EffectRangeDirection effectRangeDirection_; // 범위 스킬일때 사용
    float effectDistance_; // 범위 스킬일때 사용

    CheckEffectInfo(TargetingType targetingType = ttNoneTarget,
        AvailableTarget availableTarget = atNoneTaget,
        ExceptTarget exceptTarget = etNoneTaget,
        TargetDirection targetDirection = tdNone,
        TargetOrientation targetOrientation = toNone,
        EffectRangeDirection effectRangeDirection = erdNone,
        float effectDistance = 0.0f) :
        targetingType_(targetingType),
        availableTarget_(availableTarget),
        exceptTarget_(exceptTarget),
        targetDirection_(targetDirection),
        targetOrientation_(targetOrientation),
        effectRangeDirection_(effectRangeDirection),
        effectDistance_(effectDistance)
    {}
};

/**
 * @struct SkillEffectTemplate
 */
struct SkillEffectTemplate
{
    const gdt::skill_effect_t* effect_;
    EffectIndex effectIndex_;
    EffectStackCategory category_;
    AttributeRateType attribute_;
    CheckEffectInfo checkInfo_;
    EffectInfos casterEffects_;
    EffectInfos casteeEffects_;

    SkillEffectTemplate(const gdt::skill_effect_t* effect) :
        effect_(effect),
        effectIndex_(effect->skill_effect_index()),
        category_(toEffectStackCategory(effect->effect_stack_category())),
        attribute_(toAttributeRateType(effect->attack_attribute())),
        checkInfo_(toTargetingType(effect->targeting_type()), toAvailableTarget(effect->available_target()),
            toExceptTarget(effect->except_target()), toTargetDirection(effect->target_direction()), 
            toTargetOrientation(effect->target_orientation()), toEffectRangeDirection(effect->effect_range_direction()), 
            static_cast<float>(effect->effect_range_value() / 100.0f))
    {
        initEffectInfos();
    }

    bool hasKnockbackEffect() const {
        for (int i = eanStart; i < eanCount; i++) {
            if (isKnockbackScript(casteeEffects_[i].script_)) {
                return true;
            }
        }
        return false;
    }
        
    bool hasDashEffect() const {
        for (int i = eanStart; i < eanCount; i++) {
            if (isDashScript(casterEffects_[i].script_)) {
                return true;
            }
        }
        return false;
    }

    bool hasExecutionEffect() const {
        for (int i = eanStart; i < eanCount; i++) {
            if (isExecutionScript(casteeEffects_[i].script_)) {
                return true;
            }
        }
        return false;
    }

    bool hasReviveEffect() const {
        for (int i = eanStart; i < eanCount; i++) {
            if (isReviveEffect(casteeEffects_[i].script_)) {
                return true;
            }
        }
        return false;
    }

    bool hasCasteeEffect() const {
        for (int i = eanStart; i < eanCount; i++) {
            if (isValid(casteeEffects_[i].script_)) {
                return true;
            }
        }
        return false;
    }

    bool hasHPDamageEffect() const {
        for (int i = eanStart; i < eanCount; i++) {
            if (casteeEffects_[i].script_ == estHpDown || casteeEffects_[i].script_ == estHpAbsorb) {
                return true;
            }
        }
        return false;
    }

    bool hasCasterHealEffect() const {
        for (int i = eanStart; i < eanCount; i++) {
            if ((casterEffects_[i].script_ == estHpUp) || (casterEffects_[i].script_ == estHpMpUp) ||
                (casterEffects_[i].script_ == estHpGive)) {
                return true;
            }
        }
        return false;
    }

    bool hasCasteeHealEffect() const {
        for (int i = eanStart; i < eanCount; i++) {
            if ((casteeEffects_[i].script_ == estHpUp) || (casteeEffects_[i].script_ == estHpMpUp) ||
                (casteeEffects_[i].script_ == estHpAbsorb)) {
                return true;
            }
        }
        return false;
    }

    bool hasCasterUtilityEffect() const {
        for (int i = eanStart; i < eanCount; i++) {
            if (isUtilityType(casterEffects_[i].script_)) {
                return true;
            }
        }
        return false;
    }

    bool hasCasteeUtilityEffect() const {
        for (int i = eanStart; i < eanCount; i++) {
            if (isUtilityType(casteeEffects_[i].script_)) {
                    return true;
            }
        }
        return false;
    }

    bool hasCasterManaRegenEffect() const {
        for (int i = eanStart; i < eanCount; i++) {
            if (casteeEffects_[i].script_ == estMpUp) {
                return true;
            }
        }
        return false;
    }

    bool hasCasteeManaRegenEffect() const {
        for (int i = eanStart; i < eanCount; i++) {
            if (casteeEffects_[i].script_ == estMpUp) {
                return true;
            }
        }
        return false;
    }

    bool hasPlayerRecallScript() const {
        for (int i = eanStart; i < eanCount; i++) {
            if (casteeEffects_[i].script_ == estPlayerRecall) {
                return true;
            }
        }
        return false;
    }

    TargetingType getTargetingType() const {
        return checkInfo_.targetingType_;
    }

    TargetDirection getTargetDirection() const {
        return checkInfo_.targetDirection_;
    }

    TargetOrientation getTargetOrientation() const {
        return checkInfo_.targetOrientation_;
    }

    bool isTargetAreaSkill() const {
        return checkInfo_.targetingType_ == ttTargetArea;
    }

    bool isTargetSkill() const {
        return checkInfo_.targetingType_ == ttTarget || checkInfo_.targetingType_ == ttTargetArea;
    }

    bool isSelfSkill() const {
        return checkInfo_.targetingType_ == ttSelf;
    }

    bool isSelfAreaSkill() const {
        return checkInfo_.targetingType_ == ttSelfArea;
    }

    bool isAreaSkill() const {
        return checkInfo_.targetingType_ == ttArea;
    }

    bool hasEffects(bool isCaster) const {
        for (int i = 0; i < eanCount; ++i) {
            const bool result = isCaster ? isValid(casterEffects_[i].script_) : isValid(casteeEffects_[i].script_); 
            if (result) {
                return true;
            }
        }
        return false;
    }
    
public:
    bool isAreaEffectSkill() const {
        return isTargetAreaSkill() || isSelfAreaSkill() || isAreaSkill();
    }

    bool isCrowdControlSkill() const {
        for (int i = eanStart; i < eanCount; i++) {
            if (isCrowdControlSkillType(casteeEffects_[i].script_)) {
                return true;
            }
        }
        return false;
    }

    bool isUtilitySkill() const {
        for (int i = eanStart; i < eanCount; i++) {
            if (isUtilityType(casterEffects_[i].script_) || isUtilityType(casteeEffects_[i].script_)) {
                return true;
            }
        }
        return false;
    }

    bool isPvPSkill() const {
        return hasExecutionEffect();
    }

private:
    void initEffectInfos() {
        casterEffects_[eanEffect_1].shouldCritical_ = effect_->caster_should_critical_1();
        casterEffects_[eanEffect_1].script_ = toEffectScriptType(effect_->caster_effect_script_1());
        casterEffects_[eanEffect_1].target_ = toUseTargetStatusType(effect_->caster_use_target_status_type_1());
        casterEffects_[eanEffect_1].isPercent_ = effect_->caster_effect_value_percent_1();
        casterEffects_[eanEffect_1].statusType_ = toEffectStatusType(effect_->caster_usable_status_type_1());

        casterEffects_[eanEffect_2].shouldCritical_ = effect_->caster_should_critical_2();
        casterEffects_[eanEffect_2].script_ = toEffectScriptType(effect_->caster_effect_script_2());
        casterEffects_[eanEffect_2].target_ = toUseTargetStatusType(effect_->caster_use_target_status_type_2());
        casterEffects_[eanEffect_2].isPercent_ = effect_->caster_effect_value_percent_2();
        casterEffects_[eanEffect_2].statusType_ = toEffectStatusType(effect_->caster_usable_status_type_2());


        casteeEffects_[eanEffect_1].shouldCritical_ = effect_->castee_should_critical_1();
        casteeEffects_[eanEffect_1].script_ = toEffectScriptType(effect_->castee_effect_script_1());
        casteeEffects_[eanEffect_1].target_ = toUseTargetStatusType(effect_->castee_use_target_status_type_1());
        casteeEffects_[eanEffect_1].isPercent_ = effect_->castee_effect_value_percent_1();
        casteeEffects_[eanEffect_1].statusType_ = toEffectStatusType(effect_->castee_usable_status_type_1());

        casteeEffects_[eanEffect_2].shouldCritical_ = effect_->castee_should_critical_2();
        casteeEffects_[eanEffect_2].script_ = toEffectScriptType(effect_->castee_effect_script_2());
        casteeEffects_[eanEffect_2].target_ = toUseTargetStatusType(effect_->castee_use_target_status_type_2());
        casteeEffects_[eanEffect_2].isPercent_ = effect_->castee_effect_value_percent_2();
        casteeEffects_[eanEffect_2].statusType_ = toEffectStatusType(effect_->castee_usable_status_type_2());
    }   
};


/**
 * @class SkillEffectTable
 *
 */
class GIDEON_CS_API SkillEffectTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(SkillEffectTable);

public:
    typedef sne::core::HashMap<SkillCode, SkillEffectTemplate> SkillEffectMap;

public:
    virtual ~SkillEffectTable() {}

public:
    virtual const SkillEffectTemplate* getSkillEffectTemplate(EffectIndex effectIndex) const = 0;

    virtual const SkillEffectMap& getSkillEffectMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define SKILL_EFFECT_TABLE gideon::datatable::SkillEffectTable::instance()
