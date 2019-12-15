#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/datatable/template/npc_table.hxx>
#include <gideon/cs/shared/data/CraftInfo.h>
#include <gideon/cs/shared/data/MonsterInfo.h>
#include <gideon/cs/shared/data/ItemDropInfo.h>
#include <gideon/cs/shared/data/SkillInfo.h>
#include <gideon/cs/shared/data/Money.h>
#include <gideon/cs/shared/data/Rate.h>
#include <gideon/cs/shared/data/CreatureStatusInfo.h>
#include <gideon/cs/shared/data/FactionInfo.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>
#include "esut/Random.h"

namespace gideon { namespace datatable {

/**
 * @struct NpcSpecialSkill
 */
struct NpcSpecialSkill
{
    SkillCode skillCode_;
    permil_t activeRate_;

    NpcSpecialSkill(SkillCode skillCode, permil_t activeRate) :
        skillCode_(skillCode),
        activeRate_(activeRate) {}

    bool shouldActiveSkill() const {
        return isSuccessRate(activeRate_);
    }
};

typedef sne::core::Vector<NpcSpecialSkill> NpcSpecialSkills;


/**
 * @class NpcTemplate
 */
class NpcTemplate
{
public:
    NpcTemplate(const gdt::npc_t& npcInfo) :
        npcInfo_(npcInfo) {
		currentGameStatus_.points_.hp_ = toHitPoint(npcInfo.hp());
		currentGameStatus_.points_.mp_ = toManaPoint(npcInfo.mp());

        currentGameStatus_.attackPowers_[apiMinAttack] = npcInfo.min_attack_power();
        currentGameStatus_.attackPowers_[apiMaxAttack] = npcInfo.max_attack_power();
        currentGameStatus_.attackPowers_[apiPhysical] = npcInfo.physical_attack_power();
        currentGameStatus_.attackPowers_[apiMagic] = npcInfo.magic_attack_power();

        currentGameStatus_.attackStatus_[atsiHitRate] = static_cast<uint16_t>(npcInfo.hit_rate());
        currentGameStatus_.attackStatus_[atsiPhysicalCriticalRate] = static_cast<uint16_t>(npcInfo.physical_critical_rate());
        currentGameStatus_.attackStatus_[atsiMagicCriticalRate] = static_cast<uint16_t>(npcInfo.magic_critical_rate());

        currentGameStatus_.defenceStatus_[dsiDodgeRate] = static_cast<uint16_t>(npcInfo.dodge_rate());
        currentGameStatus_.defenceStatus_[dsiParryRate] = static_cast<uint16_t>(npcInfo.parry_rate());
        currentGameStatus_.defenceStatus_[dsiBlockRate] = static_cast<uint16_t>(npcInfo.block_rate());
        currentGameStatus_.defenceStatus_[dsiDefence] = static_cast<uint16_t>(npcInfo.defence());

        currentGameStatus_.attributes_[abiLight] = static_cast<uint16_t>(npcInfo.light_attribute());
        currentGameStatus_.attributes_[abiDark] = static_cast<uint16_t>(npcInfo.dark_attribute());
        currentGameStatus_.attributes_[abiFire] = static_cast<uint16_t>(npcInfo.fire_attribute());
        currentGameStatus_.attributes_[abiIce] = static_cast<uint16_t>(npcInfo.ice_attribute());
        
        currentGameStatus_.attributeResists_[abiLight] = static_cast<uint16_t>(npcInfo.light_attribute_regist());
        currentGameStatus_.attributeResists_[abiDark] = static_cast<uint16_t>(npcInfo.dark_attribute_regist());
        currentGameStatus_.attributeResists_[abiFire] = static_cast<uint16_t>(npcInfo.fire_attribute_regist());
        currentGameStatus_.attributeResists_[abiIce] = static_cast<uint16_t>(npcInfo.ice_attribute_regist());

        const gdt::float_list_t& scaleList = npcInfo_.scale();
        currentScale_ = scaleList[0];
        modelingRadius_ = npcInfo_.modeling_radius() / 100.0f;
        addSpecialSkill(npcInfo_.special_skill_1(), npcInfo_.special_skill_rate_1());
        addSpecialSkill(npcInfo_.special_skill_2(), npcInfo_.special_skill_rate_2());
        addSpecialSkill(npcInfo_.special_skill_3(), npcInfo_.special_skill_rate_3());
	}

    const gdt::npc_t& getInfo() const {
        return npcInfo_;
    }

public:
    bool isCollisionNpc() const {
        return npcInfo_.npc_mesh_collision_usable();
    }

    bool isContactNormalNpc() const {
        return npcInfo_.npc_contact_object_normal();
    }

    NpcCode getNpcCode() const {
        return static_cast<NpcCode>(npcInfo_.npc_code());
    }

    NpcType getNpcType() const {
        return static_cast<NpcType>(int(npcInfo_.npc_type()));
    }

    const NpcSpecialSkills& getNpcSpecialSkills() const {
        return specialSkills_;
    }

    AiReactiveType getReactiveType() const {
        return static_cast<AiReactiveType>(int(npcInfo_.ai_reactive_type()));
    }

    CreatureLevel getLevel() const {
        return toCreatureLevel(npcInfo_.level());
    }

    MonsterGrade getMonsterGrade() const {
        return static_cast<MonsterGrade>(int(npcInfo_.grade()));
    }
    // TODO skill
    HitPoint getMaxHitPoint() const {
        return toHitPoint(npcInfo_.hp());
    }

    ManaPoint getMaxManaPoint() const {
        return toManaPoint(npcInfo_.mp());
    }

    ExpPoint getExpPoint() const {
        return toExpPoint(npcInfo_.exp());
    }

    permil_t getRandomDungeonExpPct() const {
        return npcInfo_.random_dungeon_exp_pct();
    }

    permil_t getWorldEventExpPct() const {
        return npcInfo_.world_event_exp_pct();
    }

	const CreatureStatusInfo& getCurrentCreatureStatusInfo() const {
		return currentGameStatus_;
	}

    const wchar_t* getDataBlock() const {
        return npcInfo_.datablock_name().c_str();
    }

    FactionCode getFactionCode() const {
        assert(isValidFactionCode(npcInfo_.faction()));
        return npcInfo_.faction();
    }

    WorldDropSuffixId getWorldDropSuffixId1() const {
        return npcInfo_.world_drop_suffix_id_1();
    }

    ItemDropId getItemDropId1() const {
        return npcInfo_.item_drop_id_1();
    }

    WorldDropSuffixId getWorldDropSuffixId2() const {
        return npcInfo_.world_drop_suffix_id_2();
    }

    ItemDropId getItemDropId2() const {
        return npcInfo_.item_drop_id_2();
    }

public:
    const wchar_t* getThreatEffect() const
    {
        return npcInfo_.threat_effect().c_str();
    }

    const wchar_t* getThreatSound() const
    {
        return npcInfo_.aggressive_sound().c_str();
    }

    const wchar_t* getDeathEffect() const
    {
        return npcInfo_.death_effect().c_str();
    }

    uint32_t getDeathDelayTime() const {
        return npcInfo_.death_delay_time();
    }

public:

    const wchar_t* getCombatEffect() const
    {
        return npcInfo_.combat_effect().c_str();
    }

    const wchar_t* getPeaceEffect() const
    {
        return npcInfo_.peace_effect().c_str();
    }
 
public:

    const wchar_t* getRunSound() const
    {
        return npcInfo_.run_sound().c_str();
    }

public:

    const wchar_t* getSubRootEffect(uint32_t index) const
    {
        switch(index)
        {
        case 0:
            return npcInfo_.subRootAnim1_effect().c_str();
        case 1:
            return npcInfo_.subRootAnim2_effect().c_str();
        case 2:
            return npcInfo_.subRootAnim3_effect().c_str();
        case 3:
            return npcInfo_.subRootAnim4_effect().c_str();
        }

        return L"0";
    }

    uint32_t getSubRootChance() const {
        return npcInfo_.subRootAnim_chance();
    }

    uint32_t getSubRootMaxTime() const {
        return npcInfo_.subRootAnim_max_time();
    }

    uint32_t getSubRootMinTime() const {
        return npcInfo_.subRootAnim_min_time();
    }

public:
    bool isMainSkillCode(SkillCode skillCode) const {
        return npcInfo_.main_skill_code() == skillCode;
    }

    bool isSubSkillCode(SkillCode skillCode) const {
        return npcInfo_.sub_skill_code() == skillCode;
    }

public:
    /// @return meter
    float getMaxWanderDistance() const {
        return npcInfo_.ai_wander_distance() / 100.0f;
    }

    /// @return meter
    float getMaxMoveDistance() const {
        return npcInfo_.ai_max_move_distance() / 100.0f;
    }

    /// @return meter
    float getReactiveDistance() const {
        return npcInfo_.ai_reactive_distance() / 100.0f;
    }

    /// @return meter
    float getMinApproachDistance() const {
        return npcInfo_.ai_min_approach_distance() / 100.0f;
    }

    /// @return meter
    float getMaxApproachDistance() const {
        return npcInfo_.ai_max_approach_distance() / 100.0f;
    }

    /// @return m/s
    float getWalkSpeed() const {
        return npcInfo_.ai_walk_speed() / 100.0f;
    }

    /// @return m/s
    float getRunSpeed() const {
        return npcInfo_.ai_run_speed() / 100.0f;
    }


    bool shouldReactiveByDistance() const {
        return npcInfo_.ai_reactive_distance() > 0;
    }

    float getScale() const {
        return currentScale_;
    }

    /// 동료 NPC에게 도움을 요청할 수 있는가?
    bool canCallLink() const {
        return npcInfo_.ai_link_type() == 1;
    }

    /// 대화할 수 있는가?
    bool canDialog() const {
        return hasQuest() || hasBank() || canBuy() || canSell() || hasCraftFunction() || 
            hasGuild() || hasAuction() || canRepaireGlider();
    }

    bool hasQuest() const {
        return npcInfo_.quest_function() != 0;
    }

    bool hasBank() const {
        return npcInfo_.bank_function() != 0;
    }

    bool canBuy() const {
        return npcInfo_.buy_function() != 0;
    }

    bool canSell() const {
        return npcInfo_.sell_function() != 0;
    }

    bool canRepaireGlider() const {
        return npcInfo_.glider_repair_function() != 0;
    }

    bool canRotate() const {
        return npcInfo_.npc_rotate() == 0;
    }

    bool hasMail() const {
        return npcInfo_.mail_function() != 0;
    }

    bool hasAuction() const {
        return npcInfo_.auction_function() != 0;
    }

    bool hasGuild() const {
        return npcInfo_.guild_function() != 0;
    }

    bool hasCraftFunction(CraftType type) const {
        return toCraftType(npcInfo_.craft_function()) == type;
    }

    bool hasCraftFunction() const {
        return isValid(toCraftType(npcInfo_.craft_function()));
    }

    /// 도움을 요청할 수 있는 NPC 수
    uint8_t getAiLinkCount() const {
        assert(canCallLink());
        return static_cast<uint8_t>(
            esut::random(npcInfo_.ai_link_min_count(), npcInfo_.ai_link_max_count()));
    }

    /// @return meter
    float getAiLinkReactiveDistance() const {
        assert(canCallLink());
        return npcInfo_.ai_link_reactive_distance() / 100.0f;
    }

    float getModelingRadius() const {
        return modelingRadius_;
    }

    sec_t getSpawnIntervalSec() const {
        return npcInfo_.spawn_interval_sec();
    }

    const wchar_t* getSpawnEffect() const {
        return npcInfo_.spawn_effect().c_str();
    }

public:
    /// @internal
    void deleteNpcInfo() {
        delete &npcInfo_;
    }	

private:
    void addSpecialSkill(SkillCode skillCode, permil_t activeRate) {
        if (isValidSkillCode(skillCode)) {
            specialSkills_.push_back(NpcSpecialSkill(skillCode, activeRate));
        }
    }

private:    
    const gdt::npc_t& npcInfo_;
	CreatureStatusInfo currentGameStatus_;
    float currentScale_;
    float modelingRadius_;
    NpcSpecialSkills specialSkills_;
};


/**
 * @class NpcTable
 *
 */
class GIDEON_CS_API NpcTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(NpcTable);

public:
    typedef sne::core::HashMap<NpcCode, NpcTemplate> NpcMap;

public:
    virtual ~NpcTable() {}

public:
    virtual const NpcTemplate* getNpcTemplate(NpcCode code) const = 0;

    virtual const NpcMap& getNpcMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define NPC_TABLE gideon::datatable::NpcTable::instance()
