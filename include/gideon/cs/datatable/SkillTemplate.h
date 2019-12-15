#pragma once

#include "SkillCommonInfo.h"
#include <gideon/cs/shared/data/Rate.h>
#include <gideon/cs/Common.h>

namespace gdt {

class player_passive_skill_t;
class player_active_skill_t;
class npc_active_skill_t;
class item_active_skill_t;
class so_active_skill_t;

} // namespace gdt {


namespace gideon { namespace datatable {

enum ComboCount{
    ccNull = -1,
    ccFirst = 0,
    ccSecond = 1,
    ccThird = 2,
    ccEnd = 3
};

inline bool isValid(ComboCount value)
{
    return (ccFirst <= value) && (value <= ccThird);
}

template<typename T>
ComboCount toComboCount(T value){
    return static_cast<ComboCount>(static_cast<uint32_t>(value));
}

typedef std::array<const wchar_t*, ccEnd> ComboStringArray;
typedef std::array<uint32_t, ccEnd> ComboIntgArray;


/**
 * @struct SkillClientEffectTemplate
 **/
struct GIDEON_CS_API SkillClientEffectTemplate
{
    const wchar_t* iconName;

    const wchar_t* castingAnimationName;
    const wchar_t* castingDrawAnimationName;

    const wchar_t* castingEffectName;

    uint32_t animationTransitionTime;
    const wchar_t* casterAnimationName;
    const wchar_t* casterEffect;
    const wchar_t* trailEffect;

    const wchar_t* casterEffectName_1;
    const wchar_t* casterEffectName_2;

    const wchar_t* casteeAnimationName;
    uint32_t casteeIntervalTime;

    const wchar_t* casteeEffectName_1;
    const wchar_t* casteeEffectName_2;

    const wchar_t* areaEffectName;

    const wchar_t* projectileName;
    const wchar_t* projectileParticle;
    const wchar_t* projectileSound;

    const wchar_t* projectileStartingPoint;
    const wchar_t* projectileEndPoint;

    const wchar_t* projectileTrailParticle;

    float projectileLightR;
    float projectileLightG;
    float projectileLightB;

    float projectileLightValue;
    float projectileLightRangeValue;

    ComboStringArray comboCasterAnimationName;
    ComboStringArray comboCasterEffect;
    ComboStringArray comboCasteeAnimationName;
    ComboStringArray comboCasteeEffect;
    ComboIntgArray comboCasteeIntervalTime;

    explicit SkillClientEffectTemplate(const gdt::player_passive_skill_t& playerSkill);
    explicit SkillClientEffectTemplate(const gdt::player_active_skill_t& playerSkill);
    explicit SkillClientEffectTemplate(const gdt::npc_active_skill_t& playerSkill);
    explicit SkillClientEffectTemplate(const gdt::item_active_skill_t& playerSkill);
    explicit SkillClientEffectTemplate(const gdt::so_active_skill_t& playerSkill);

    const wchar_t* getCasterEffectName(gideon::EffectApplyNum num) const {
        if(num == eanEffect_1)
            return casterEffectName_1;
        else
            return casterEffectName_2;
    }

    const wchar_t* getCasteeEffectName(gideon::EffectApplyNum num) const {
        if(num == eanEffect_1)
            return casteeEffectName_1;
        else
            return casteeEffectName_2;
    }

    const wchar_t* getComboCasterAnimationName(ComboCount comboCount) const {
        if(isValid(comboCount) && (comboCasterAnimationName[comboCount] != nullptr))
            return comboCasterAnimationName[comboCount];
        else
            return casterAnimationName;
    }

    const wchar_t* getComboCasteeAnimationName(ComboCount comboCount) const {
        if(isValid(comboCount) && (comboCasteeAnimationName[comboCount] != nullptr))
            return comboCasteeAnimationName[comboCount];
        else
            return casteeAnimationName;
    }
    
    const wchar_t* getComboCasterEffectName(ComboCount comboCount) const {
        if(isValid(comboCount) && (comboCasterEffect[comboCount] != nullptr))
            return comboCasterEffect[comboCount];
        else
            return casteeEffectName_1;
    }

    const wchar_t* getComboCasteeEffectName(ComboCount comboCount) const {
        if(isValid(comboCount) && (comboCasteeEffect[comboCount] != nullptr))
            return comboCasteeEffect[comboCount];
        else
            return casteeEffectName_1;
    }

    uint32_t getComboCasteeIntervalTime(ComboCount comboCount) const {
        if(isValid(comboCount) && (comboCasteeIntervalTime[comboCount] > 0))
            return comboCasteeIntervalTime[comboCount];
        else
            return casteeIntervalTime;
    }
};

typedef sne::core::HashMap<SkillCode, SkillClientEffectTemplate> SkillEffectMap;


/***
 * @struct PassiveSkillTemplate
 ***/
struct GIDEON_CS_API PassiveSkillTemplate
{
    SkillCode skillCode_;
    EffectLevel effectLevel_;
    permil_t topThreadApplyValue_;
    SkillType skillType_;
    SkillUseableState skillUseableState_;
    SkillLearnInfo learnInfo_;
    SkillCastCheckPointInfo checkPoint_;
    SkillCheckEquipItemInfo checkEquipItem_;
    SkillCoolTimeInfo cooltimeInfo_;
    EffectIndex effectIndex_;
    SkillActivateTimeInfos casterSkillActivateTimeInfos_;
    SkillActivateTimeInfos casteeSkillActivateTimeInfos_;
    EffectValues casterEffectValues_;
    EffectValues casteeEffectValues_;

    explicit PassiveSkillTemplate(const gdt::player_passive_skill_t& playerSkill);

    bool shouldCheckSelfPoints() const {
        return checkPoint_.isValid() && checkPoint_.checkStatTarget_ == csttCaster;
    }

    bool shouldCheckUsableState() const {
        return isValid(skillUseableState_);
    }

    bool shouldCheckEquip() const {
        return checkEquipItem_.isValid();
    }

    bool shouldCheckLeanedSkill() const {
        return isValidSkillCode(learnInfo_.needLearnSkillCode1_) ||
            isValidSkillCode(learnInfo_.needLearnSkillCode2_);
    }

    bool hasCooldown() const {
        return cooltimeInfo_.cooldownMilSec_ > 0;
    }

    bool hasGlobalCooldown() const {
        return cooltimeInfo_.globalCooldownTimeIndex_ > 0;
    }
};


/***
 * @struct ActiveSkillTemplate
 ***/
struct GIDEON_CS_API ActiveSkillTemplate
{
    SkillCode skillCode_;
    EffectLevel effectLevel_;
    permil_t topThreadApplyValue_;
    SkillType skillType_;
    SkillCastingInfo castingInfo_;
    bool canCastOnMoving_;
    float projectileSpeed_;    
    DistanceRangeInfo skillCastCheckDistanceInfo_;
    SkillCoolTimeInfo coolTimeInfo_;

    SkillActivateTimeInfos casterSkillActivateTimeInfos_;
    SkillActivateTimeInfos casteeSkillActivateTimeInfos_;

    EffectIndex effectIndex_;
    EffectValues casterEffectValues_;
    EffectValues casteeEffectValues_;

    template <typename T>
    explicit ActiveSkillTemplate(const T& skillTemplate) : 
        skillCode_(skillTemplate.skill_code()),
        effectLevel_(static_cast<EffectLevel>(skillTemplate.effect_level())),
        topThreadApplyValue_(static_cast<permil_t>(skillTemplate.top_threat_apply_value())),
        skillType_(toSkillType(skillTemplate.skill_type())),
        castingInfo_(toCastType(skillTemplate.cast_type()), skillTemplate.cast_time()),
        canCastOnMoving_(skillTemplate.can_cast_on_moving()),
        skillCastCheckDistanceInfo_(skillTemplate.min_distance() / 100.0f,
            skillTemplate.max_distance() / 100.0f),
        projectileSpeed_(skillTemplate.projectile_speed() / 100.0f),
        coolTimeInfo_(static_cast<uint8_t>(skillTemplate.global_cooldown_time_index()),
            skillTemplate.global_cooldown_time(), skillTemplate.cooldown_time()),
        effectIndex_(static_cast<EffectIndex>(skillTemplate.skill_effect_index()))
    {
        casterEffectValues_[eanEffect_1] = skillTemplate.caster_effect_value_1();
        casterEffectValues_[eanEffect_2] = skillTemplate.caster_effect_value_2();
        casteeEffectValues_[eanEffect_1] = skillTemplate.castee_effect_value_1();
        casteeEffectValues_[eanEffect_2] = skillTemplate.castee_effect_value_2();
        casterSkillActivateTimeInfos_[eanEffect_1].activateMilSec_ =
            skillTemplate.caster_activate_mil_sec_1();
        casterSkillActivateTimeInfos_[eanEffect_1].activateIntervalMilSec_ =
            skillTemplate.caster_activate_interval_mil_sec_1();
        casterSkillActivateTimeInfos_[eanEffect_2].activateMilSec_ =
            skillTemplate.caster_activate_mil_sec_2();
        casterSkillActivateTimeInfos_[eanEffect_2].activateIntervalMilSec_ =
            skillTemplate.caster_activate_interval_mil_sec_2();
        casteeSkillActivateTimeInfos_[eanEffect_1].activateMilSec_ =
            skillTemplate.castee_activate_mil_sec_1();
        casteeSkillActivateTimeInfos_[eanEffect_1].activateIntervalMilSec_ =
            skillTemplate.castee_activate_interval_mil_sec_1();
        casteeSkillActivateTimeInfos_[eanEffect_2].activateMilSec_ =
            skillTemplate.castee_activate_mil_sec_2();
        casteeSkillActivateTimeInfos_[eanEffect_2].activateIntervalMilSec_ =
            skillTemplate.castee_activate_interval_mil_sec_2();
    }

    SkillCode getSkillCode() const {
        return skillCode_;
    }

    bool isBuffSkill() const {
        return isBuffSkillType(skillType_);
    }

    bool isDebuffSkill() const {
        return isDebuffSkillType(skillType_);
    }

    bool isAttackSkill() const {
        return isAttackSkillType(skillType_);
    }

    bool isAttackable(float distanceToTargetSq) const {
        return (skillCastCheckDistanceInfo_.getMinDistanceSq() <= distanceToTargetSq) &&
            (distanceToTargetSq <= skillCastCheckDistanceInfo_.getMaxDistanceSq());
    }

    bool isMovingSkill() const {
        return canCastOnMoving_;
    }
    
    bool isConcentrationSkill() const {
        return castingInfo_.castType_ == catConcentration;
    }

    bool isProjectileSkill() const {
        return castingInfo_.castType_ == catProjectile;
    }

    bool isCommonProgectileAttackMagicSkill() const {
        return isProjectileSkill() && isCommonEffectLevel(effectLevel_) &&
            (sktAttackMagic == skillType_);
    }
};


/***
 * @struct ItemActiveSkillTemplate
 ***/
struct GIDEON_CS_API ItemActiveSkillTemplate : public ActiveSkillTemplate
{
    SkillUseableState skillUseableState_;
    SkillTransitionState transitionState_;

    explicit ItemActiveSkillTemplate(const gdt::item_active_skill_t& itemSkill);
};



/***
 * @struct SOActiveSkillTemplate
 ***/
struct GIDEON_CS_API SOActiveSkillTemplate : public ActiveSkillTemplate
{
    Points consumePoints_;
    SkillCastCheckPointInfo castCheckPoint_;

    explicit SOActiveSkillTemplate(const gdt::so_active_skill_t& soSkill);
};


/***
 * @struct CreatureActiveSkillTemplate
 ***/
struct GIDEON_CS_API CreatureActiveSkillTemplate : public ActiveSkillTemplate
{
    SkillUseableState skillUseableState_;
    SkillTransitionState transitionState_;
    Points consumePoints_;
    ChannelSkillTimeInfo channelSkillTimeInfo_;
    SkillCastCheckPointInfo castCheckPoint_;

    template <class T>
    CreatureActiveSkillTemplate(const T& skillTemplate) :
        ActiveSkillTemplate(skillTemplate),
        skillUseableState_(toSkillUseableState(skillTemplate.usable_state())),
        transitionState_(toSkillTransitionState(skillTemplate.transition_state())),
        consumePoints_(toHitPoint(skillTemplate.consumed_hp()), toManaPoint(skillTemplate.consumed_mp())),
        channelSkillTimeInfo_(skillTemplate.channel_casting_time(), skillTemplate.channel_tick()),
        castCheckPoint_(toCheckStatTargetType(skillTemplate.check_point_target_type()), toPointType(skillTemplate.check_point_type()),
            skillTemplate.check_point_up_down() > 0, skillTemplate.check_point_value_by_percent() > 0, skillTemplate.check_point_value())
    {
    }

    bool isSkillTransitionToCombatState() const {
        return transitionState_ == stsCombat;
    }
};


/***
 * @struct NpcActiveSkillTemplate
 ***/
struct GIDEON_CS_API NpcActiveSkillTemplate : public CreatureActiveSkillTemplate
{
    explicit NpcActiveSkillTemplate(const gdt::npc_active_skill_t& npcSkill);
};


/***
 * @struct PlayerActiveSkillTemplate
 ***/
struct GIDEON_CS_API PlayerActiveSkillTemplate : public CreatureActiveSkillTemplate
{
    SkillLearnInfo learnInfo_;
    BaseItemInfo consumeItemInfo_;

    EffectStackCategory checkCategory_;
    SkillCheckEquipItemInfo castableCheckEquip_;

    explicit PlayerActiveSkillTemplate(const gdt::player_active_skill_t& playerSkill);
};

}} // namespace gideon { namespace datatable {
