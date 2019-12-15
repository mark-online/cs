#pragma once

#include <gideon/cs/datatable/PlayerActiveSkillTable.h>
#include <gideon/cs/datatable/SkillTemplate.h>
#include <gideon/cs/datatable/template/player_active_skill_table.hxx>

namespace gideon { namespace datatable {
/**
 * @class PlayerActiveSkillTableImpl
 *
 */
class PlayerActiveSkillTableImpl : public PlayerActiveSkillTable
{
public:
    PlayerActiveSkillTableImpl(std::istream& is, bool isClientLoading)  :
        isLoaded_(false) {
        try {
            playerActiveSkillTable_ =
                gdt::player_active_skill_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::player_active_skill_t& playerActiveSkill : playerActiveSkillTable_->player_active_skill_template()) {
                playerActiveSkillMap_.emplace(playerActiveSkill.skill_code(),
                    PlayerActiveSkillTemplate(playerActiveSkill));
                if (isClientLoading) {
                    playerActiveSkillEffectMap_.emplace(playerActiveSkill.skill_code(),
                        SkillClientEffectTemplate(playerActiveSkill));
                }
            }
            isLoaded_ = true;

            PlayerActiveSkillTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const PlayerActiveSkillTemplate* getPlayerSkill(SkillCode code) const {
        const PlayerSkillMap::const_iterator pos = playerActiveSkillMap_.find(code);
        if (pos != playerActiveSkillMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const SkillClientEffectTemplate* getClientEffect(SkillCode code) const {
        const SkillEffectMap::const_iterator pos = playerActiveSkillEffectMap_.find(code);
        if (pos != playerActiveSkillEffectMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const PlayerSkillMap& getPlayerSkillMap() const {
        return playerActiveSkillMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::player_active_skill_table> playerActiveSkillTable_;
    PlayerSkillMap playerActiveSkillMap_;
    SkillEffectMap playerActiveSkillEffectMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
