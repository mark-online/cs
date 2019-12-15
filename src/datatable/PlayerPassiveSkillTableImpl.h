#pragma once

#include <gideon/cs/datatable/SkillTemplate.h>
#include <gideon/cs/datatable/PlayerPassiveSkillTable.h>
#include <gideon/cs/datatable/template/player_passive_skill_table.hxx>

namespace gideon { namespace datatable {

/**
 * @class PlayerPassiveSkillTableImpl
 *
 */
class PlayerPassiveSkillTableImpl : public PlayerPassiveSkillTable
{
public:
    PlayerPassiveSkillTableImpl(std::istream& is, bool isClientLoading)  :
        isLoaded_(false) {
        try {
            playerPassiveSkillTable_ =
                gdt::player_passive_skill_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::player_passive_skill_t& playerPassiveSkill :
                playerPassiveSkillTable_->player_passive_skill_template()) {
                playerPassiveSkillMap_.emplace(playerPassiveSkill.skill_code(),
                    PassiveSkillTemplate(playerPassiveSkill));
                if (isClientLoading) {
                    playerPassiveSkillEffectMap_.emplace(playerPassiveSkill.skill_code(),
                        SkillClientEffectTemplate(playerPassiveSkill));
                }
            }
            isLoaded_ = true;

            PlayerPassiveSkillTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const PassiveSkillTemplate* getPlayerSkill(SkillCode code) const {
        const PlayerSkillMap::const_iterator pos = playerPassiveSkillMap_.find(code);
        if (pos != playerPassiveSkillMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const SkillClientEffectTemplate* getClientEffect(SkillCode code) const {
        const SkillEffectMap::const_iterator pos = playerPassiveSkillEffectMap_.find(code);
        if (pos != playerPassiveSkillEffectMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const PlayerSkillMap& getPlayerSkillMap() const {
        return playerPassiveSkillMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::player_passive_skill_table> playerPassiveSkillTable_;
    EffectValues casterValues_;
    EffectValues casteeValues_;
    PlayerSkillMap playerPassiveSkillMap_;
    SkillEffectMap playerPassiveSkillEffectMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
