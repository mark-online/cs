#include "DataTablePCH.h"
#include <gideon/cs/datatable/SkillTemplate.h>
#include <gideon/cs/datatable/template/player_active_skill_table.hxx>
#include <gideon/cs/datatable/template/player_passive_skill_table.hxx>
#include <gideon/cs/datatable/template/item_active_skill_table.hxx>
#include <gideon/cs/datatable/template/npc_active_skill_table.hxx>
#include <gideon/cs/datatable/template/so_active_skill_table.hxx>

namespace gideon { namespace datatable {

// = SkillClientEffectTemplate

SkillClientEffectTemplate::SkillClientEffectTemplate(const gdt::player_passive_skill_t& playerSkill) :
    iconName(playerSkill.icon_name().c_str()),
    castingAnimationName(playerSkill.casting_animation_name().c_str()),
    castingDrawAnimationName(playerSkill.casting_draw_animation_name().c_str()),
    castingEffectName(playerSkill.casting_effect().c_str()),
    animationTransitionTime(playerSkill.animation_transition_time()),
    casterAnimationName(playerSkill.caster_animation_name().c_str()),
    casterEffect(playerSkill.caster_effect().c_str()),
    trailEffect(playerSkill.trail_effect().c_str()),
    casterEffectName_1(playerSkill.attacker1_caster_effect().c_str()),
    casterEffectName_2(playerSkill.attacker2_caster_effect().c_str()),
    casteeAnimationName(playerSkill.castee_animation_name().c_str()),
    casteeIntervalTime(playerSkill.castee_interval_time()),
    casteeEffectName_1(playerSkill.attacked1_castee_effect().c_str()),
    casteeEffectName_2(playerSkill.attacked2_castee_effect().c_str()),
    areaEffectName(playerSkill.area_effect().c_str()),
    projectileName(playerSkill.projectile_name().c_str()),
    projectileParticle(playerSkill.projectile_particle().c_str()),
    projectileSound(playerSkill.projectile_sound().c_str()),
    projectileStartingPoint(playerSkill.projectile_starting_point().c_str()),
    projectileEndPoint(playerSkill.projectile_end_point().c_str()),
    projectileTrailParticle(playerSkill.projectile_trail_particle().c_str()),
    projectileLightValue(playerSkill.projectile_light_value()),
    projectileLightRangeValue(playerSkill.projectile_light_range_value())
{
    comboCasterAnimationName.fill(nullptr);
    comboCasterEffect.fill(nullptr);
    comboCasteeAnimationName.fill(nullptr);
    comboCasteeEffect.fill(nullptr);
    comboCasteeIntervalTime.fill(0);

    const gdt::float_list_t& rgb = playerSkill.projectile_light_rgb_value();

    if (rgb.size() < 3) {
        projectileLightR = 0;
        projectileLightG = 0;
        projectileLightB = 0;
    }
    else {
        projectileLightR = rgb[0];
        projectileLightG = rgb[1];
        projectileLightB = rgb[2];
    }
}


SkillClientEffectTemplate::SkillClientEffectTemplate(const gdt::player_active_skill_t& playerSkill) :
    iconName(playerSkill.icon_name().c_str()),
    castingAnimationName(playerSkill.casting_animation_name().c_str()),
    castingDrawAnimationName(playerSkill.casting_draw_animation_name().c_str()),
    castingEffectName(playerSkill.casting_effect().c_str()),
    animationTransitionTime(playerSkill.animation_transition_time()),
    casterAnimationName(playerSkill.caster_animation_name().c_str()),
    casterEffect(playerSkill.caster_effect().c_str()),
    trailEffect(playerSkill.trail_effect().c_str()),
    casterEffectName_1(playerSkill.attacker1_caster_effect().c_str()),
    casterEffectName_2(playerSkill.attacker2_caster_effect().c_str()),
    casteeAnimationName(playerSkill.castee_animation_name().c_str()),
    casteeIntervalTime(playerSkill.castee_interval_time()),
    casteeEffectName_1(playerSkill.attacked1_castee_effect().c_str()),
    casteeEffectName_2(playerSkill.attacked2_castee_effect().c_str()),
    areaEffectName(playerSkill.area_effect().c_str()),
    projectileName(playerSkill.projectile_name().c_str()),
    projectileParticle(playerSkill.projectile_particle().c_str()),
    projectileSound(playerSkill.projectile_sound().c_str()),
    projectileStartingPoint(playerSkill.projectile_starting_point().c_str()),
    projectileEndPoint(playerSkill.projectile_end_point().c_str()),
    projectileTrailParticle(playerSkill.projectile_trail_particle().c_str()),
    projectileLightValue(playerSkill.projectile_light_value()),
    projectileLightRangeValue(playerSkill.projectile_light_range_value())
{
    comboCasterAnimationName[ccFirst] = playerSkill.combo_1_caster_animation_name().c_str();
    comboCasterEffect[ccFirst] = playerSkill.combo_1_caster_effect().c_str();
    comboCasteeAnimationName[ccFirst] = playerSkill.combo_1_castee_animation_name().c_str();
    comboCasteeEffect[ccFirst] = playerSkill.combo_1_castee_effect().c_str();
    comboCasteeIntervalTime[ccFirst] = playerSkill.combo_1_castee_interval_time();
    comboCasterAnimationName[ccSecond] = playerSkill.combo_2_caster_animation_name().c_str();
    comboCasterEffect[ccSecond] = playerSkill.combo_2_caster_effect().c_str();
    comboCasteeAnimationName[ccSecond] = playerSkill.combo_2_castee_animation_name().c_str();
    comboCasteeEffect[ccSecond] = playerSkill.combo_2_castee_effect().c_str();
    comboCasteeIntervalTime[ccSecond] = playerSkill.combo_2_castee_interval_time();
    comboCasterAnimationName[ccThird] = playerSkill.combo_3_caster_animation_name().c_str();
    comboCasterEffect[ccThird] = playerSkill.combo_3_caster_effect().c_str();
    comboCasteeAnimationName[ccThird] = playerSkill.combo_3_castee_animation_name().c_str();
    comboCasteeEffect[ccThird] = playerSkill.combo_3_castee_effect().c_str();
    comboCasteeIntervalTime[ccThird] = playerSkill.combo_3_castee_interval_time();

    const gdt::float_list_t& rgb = playerSkill.projectile_light_rgb_value();

    if (rgb.size() < 3) {
        projectileLightR = 0;
        projectileLightG = 0;
        projectileLightB = 0;
    }
    else {
        projectileLightR = rgb[0];
        projectileLightG = rgb[1];
        projectileLightB = rgb[2];
    }
}


SkillClientEffectTemplate::SkillClientEffectTemplate(const gdt::npc_active_skill_t& playerSkill) :
    iconName(nullptr),
    castingAnimationName(playerSkill.casting_animation_name().c_str()),
    castingDrawAnimationName(playerSkill.casting_draw_animation_name().c_str()),
    castingEffectName(playerSkill.casting_effect().c_str()),
    animationTransitionTime(playerSkill.animation_transition_time()),
    casterAnimationName(playerSkill.caster_animation_name().c_str()),
    casterEffect(playerSkill.caster_effect().c_str()),
    trailEffect(playerSkill.trail_effect().c_str()),
    casterEffectName_1(playerSkill.attacker1_caster_effect().c_str()),
    casterEffectName_2(playerSkill.attacker2_caster_effect().c_str()),
    casteeAnimationName(playerSkill.castee_animation_name().c_str()),
    casteeIntervalTime(playerSkill.castee_interval_time()),
    casteeEffectName_1(playerSkill.attacked1_castee_effect().c_str()),
    casteeEffectName_2(playerSkill.attacked2_castee_effect().c_str()),
    areaEffectName(playerSkill.area_effect().c_str()),
    projectileName(playerSkill.projectile_name().c_str()),
    projectileParticle(playerSkill.projectile_particle().c_str()),
    projectileSound(playerSkill.projectile_sound().c_str()),
    projectileStartingPoint(playerSkill.projectile_starting_point().c_str()),
    projectileEndPoint(playerSkill.projectile_end_point().c_str()),
    projectileTrailParticle(playerSkill.projectile_trail_particle().c_str()),
    projectileLightValue(playerSkill.projectile_light_value()),
    projectileLightRangeValue(playerSkill.projectile_light_range_value())
{
    comboCasterAnimationName.fill(nullptr);
    comboCasterEffect.fill(nullptr);
    comboCasteeAnimationName.fill(nullptr);
    comboCasteeEffect.fill(nullptr);
    comboCasteeIntervalTime.fill(0);

    const gdt::float_list_t& rgb = playerSkill.projectile_light_rgb_value();

    if (rgb.size() < 3) {
        projectileLightR = 0;
        projectileLightG = 0;
        projectileLightB = 0;
    }
    else {
        projectileLightR = rgb[0];
        projectileLightG = rgb[1];
        projectileLightB = rgb[2];
    }
}


SkillClientEffectTemplate::SkillClientEffectTemplate(const gdt::item_active_skill_t& playerSkill) :
    iconName(nullptr),
    castingAnimationName(playerSkill.casting_animation_name().c_str()),
    castingDrawAnimationName(playerSkill.casting_draw_animation_name().c_str()),
    castingEffectName(playerSkill.casting_effect().c_str()),
    animationTransitionTime(playerSkill.animation_transition_time()),
    casterAnimationName(playerSkill.caster_animation_name().c_str()),
    casterEffect(playerSkill.caster_effect().c_str()),
    trailEffect(playerSkill.trail_effect().c_str()),
    casterEffectName_1(playerSkill.attacker1_caster_effect().c_str()),
    casterEffectName_2(playerSkill.attacker2_caster_effect().c_str()),
    casteeAnimationName(playerSkill.castee_animation_name().c_str()),
    casteeIntervalTime(playerSkill.castee_interval_time()),
    casteeEffectName_1(playerSkill.attacked1_castee_effect().c_str()),
    casteeEffectName_2(playerSkill.attacked2_castee_effect().c_str()),
    areaEffectName(playerSkill.area_effect().c_str()),
    projectileName(playerSkill.projectile_name().c_str()),
    projectileParticle(playerSkill.projectile_particle().c_str()),
    projectileSound(playerSkill.projectile_sound().c_str()),
    projectileStartingPoint(playerSkill.projectile_starting_point().c_str()),
    projectileEndPoint(playerSkill.projectile_end_point().c_str()),
    projectileTrailParticle(playerSkill.projectile_trail_particle().c_str()),
    projectileLightValue(playerSkill.projectile_light_value()),
    projectileLightRangeValue(playerSkill.projectile_light_range_value())
{
    comboCasterAnimationName.fill(nullptr);
    comboCasterEffect.fill(nullptr);
    comboCasteeAnimationName.fill(nullptr);
    comboCasteeEffect.fill(nullptr);
    comboCasteeIntervalTime.fill(0);

    const gdt::float_list_t& rgb = playerSkill.projectile_light_rgb_value();

    if (rgb.size() < 3) {
        projectileLightR = 0;
        projectileLightG = 0;
        projectileLightB = 0;
    }
    else {
        projectileLightR = rgb[0];
        projectileLightG = rgb[1];
        projectileLightB = rgb[2];
    }
}


SkillClientEffectTemplate::SkillClientEffectTemplate(const gdt::so_active_skill_t& playerSkill) :
    iconName(nullptr),
    castingAnimationName(playerSkill.casting_animation_name().c_str()),
    castingDrawAnimationName(playerSkill.casting_draw_animation_name().c_str()),
    castingEffectName(playerSkill.casting_effect().c_str()),
    animationTransitionTime(playerSkill.animation_transition_time()),
    casterAnimationName(playerSkill.caster_animation_name().c_str()),
    casterEffect(playerSkill.caster_effect().c_str()),
    trailEffect(playerSkill.trail_effect().c_str()),
    casterEffectName_1(playerSkill.attacker1_caster_effect().c_str()),
    casterEffectName_2(playerSkill.attacker2_caster_effect().c_str()),
    casteeAnimationName(playerSkill.castee_animation_name().c_str()),
    casteeIntervalTime(playerSkill.castee_interval_time()),
    casteeEffectName_1(playerSkill.attacked1_castee_effect().c_str()),
    casteeEffectName_2(playerSkill.attacked2_castee_effect().c_str()),
    areaEffectName(playerSkill.area_effect().c_str()),
    projectileName(playerSkill.projectile_name().c_str()),
    projectileParticle(playerSkill.projectile_particle().c_str()),
    projectileSound(playerSkill.projectile_sound().c_str()),
    projectileStartingPoint(playerSkill.projectile_starting_point().c_str()),
    projectileEndPoint(playerSkill.projectile_end_point().c_str()),
    projectileTrailParticle(playerSkill.projectile_trail_particle().c_str()),
    projectileLightValue(playerSkill.projectile_light_value()),
    projectileLightRangeValue(playerSkill.projectile_light_range_value())
{
    comboCasterAnimationName.fill(nullptr);
    comboCasterEffect.fill(nullptr);
    comboCasteeAnimationName.fill(nullptr);
    comboCasteeEffect.fill(nullptr);
    comboCasteeIntervalTime.fill(0);

    const gdt::float_list_t& rgb = playerSkill.projectile_light_rgb_value();

    if (rgb.size() < 3) {
        projectileLightR = 0;
        projectileLightG = 0;
        projectileLightB = 0;
    }
    else {
        projectileLightR = rgb[0];
        projectileLightG = rgb[1];
        projectileLightB = rgb[2];
    }
}

// = PassiveSkillTemplate

PassiveSkillTemplate::PassiveSkillTemplate(const gdt::player_passive_skill_t& playerSkill) :
    skillCode_(playerSkill.skill_code()),
    effectLevel_(static_cast<EffectLevel>(playerSkill.effect_level())),
    topThreadApplyValue_(static_cast<permil_t>(playerSkill.top_threat_apply_value())),
    skillType_(toSkillType(playerSkill.skill_type())),
    skillUseableState_(toSkillUseableState(playerSkill.usable_state())),
    learnInfo_(toCharacterClass(playerSkill.learn_character_class()), playerSkill.need_learn_skill_code_1(), playerSkill.need_learn_skill_code_2(),
        playerSkill.next_skill_code_1(), playerSkill.next_skill_code_2(), toSkillPoint(playerSkill.need_skill_point())),
    checkPoint_(toCheckStatTargetType(playerSkill.check_point_target_type()), toPointType(playerSkill.check_point_type()),
        playerSkill.check_point_up_down() > 0, playerSkill.check_point_value_by_percent() > 0, playerSkill.check_point_value()),
    checkEquipItem_(toEquipPart(playerSkill.check_equip_part()), toSkillCastableEquipType(playerSkill.check_castable_equip_type())),
    cooltimeInfo_(static_cast<uint32_t>(playerSkill.global_cooldown_time_index()),
        static_cast<GameTime>(playerSkill.global_cooldown_time()),
        static_cast<GameTime>(playerSkill.cooldown_time())),
    effectIndex_(static_cast<EffectIndex>(playerSkill.skill_effect_index()))
{
    casterEffectValues_[eanEffect_1] = playerSkill.caster_effect_value_1();
    casterEffectValues_[eanEffect_2] = playerSkill.caster_effect_value_2();
    casteeEffectValues_[eanEffect_1] = playerSkill.castee_effect_value_1();
    casteeEffectValues_[eanEffect_2] = playerSkill.castee_effect_value_2();
    casterSkillActivateTimeInfos_[eanEffect_1].activateMilSec_ = playerSkill.caster_activate_mil_sec_1();
    casterSkillActivateTimeInfos_[eanEffect_1].activateIntervalMilSec_ = playerSkill.caster_activate_interval_mil_sec_1();
    casterSkillActivateTimeInfos_[eanEffect_2].activateMilSec_ = playerSkill.caster_activate_mil_sec_2();
    casterSkillActivateTimeInfos_[eanEffect_2].activateIntervalMilSec_ = playerSkill.caster_activate_interval_mil_sec_2();
    casteeSkillActivateTimeInfos_[eanEffect_1].activateMilSec_ = playerSkill.castee_activate_mil_sec_1();
    casteeSkillActivateTimeInfos_[eanEffect_1].activateIntervalMilSec_ = playerSkill.castee_activate_interval_mil_sec_1();
    casteeSkillActivateTimeInfos_[eanEffect_2].activateMilSec_ = playerSkill.castee_activate_mil_sec_2();
    casteeSkillActivateTimeInfos_[eanEffect_2].activateIntervalMilSec_ = playerSkill.castee_activate_interval_mil_sec_2();
}

// = ItemActiveSkillTemplate

ItemActiveSkillTemplate::ItemActiveSkillTemplate(const gdt::item_active_skill_t& itemSkill) :
    ActiveSkillTemplate(itemSkill),
    skillUseableState_(toSkillUseableState(itemSkill.usable_state())),
    transitionState_(toSkillTransitionState(itemSkill.transition_state()))
{
}

// = SOActiveSkillTemplate

SOActiveSkillTemplate::SOActiveSkillTemplate(const gdt::so_active_skill_t& soSkill) :
    ActiveSkillTemplate(soSkill),
    consumePoints_(toHitPoint(soSkill.consumed_hp()), toManaPoint(soSkill.consumed_mp())),
    castCheckPoint_(toCheckStatTargetType(soSkill.check_point_target_type()), toPointType(soSkill.check_point_type()),
        soSkill.check_point_up_down() > 0, soSkill.check_point_value_by_percent() > 0, soSkill.check_point_value())
{
}

// = NpcActiveSkillTemplate

NpcActiveSkillTemplate::NpcActiveSkillTemplate(const gdt::npc_active_skill_t& npcSkill) :
    CreatureActiveSkillTemplate(npcSkill)
{
}

// = PlayerActiveSkillTemplate

PlayerActiveSkillTemplate::PlayerActiveSkillTemplate(const gdt::player_active_skill_t& playerSkill) :
    CreatureActiveSkillTemplate(playerSkill),
    learnInfo_(toCharacterClass(playerSkill.learn_character_class()), playerSkill.need_learn_skill_code_1(), playerSkill.need_learn_skill_code_2(),
        playerSkill.next_skill_code_1(), playerSkill.next_skill_code_2(), toSkillPoint(playerSkill.need_skill_point())),
    consumeItemInfo_(playerSkill.consume_item_code(), playerSkill.consume_item_count()),
    checkCategory_(toEffectStackCategory(playerSkill.check_mez_type())),
    castableCheckEquip_(toEquipPart(playerSkill.check_equip_part()), toSkillCastableEquipType(playerSkill.check_castable_equip_type()))
{
}

}} // namespace gideon { namespace datatable {
