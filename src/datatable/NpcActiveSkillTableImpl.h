#pragma once

#include <gideon/cs/datatable/NpcActiveSkillTable.h>
#include <gideon/cs/datatable/SkillTemplate.h>
#include <gideon/cs/datatable/template/npc_active_skill_table.hxx>

namespace gideon { namespace datatable {

/**
 * @class NpcActiveSkillTableImpl
 *
 */
class NpcActiveSkillTableImpl : public NpcActiveSkillTable
{
public:
    NpcActiveSkillTableImpl(std::istream& is, bool isClientLoading)  :
        isLoaded_(false) {
        try {
            npcActiveSkillTable_ =
                gdt::npc_active_skill_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::npc_active_skill_t& npcActiveSkill :
                npcActiveSkillTable_->npc_active_skill_template()) {
                npcActiveSkillMap_.emplace(npcActiveSkill.skill_code(),
                    NpcActiveSkillTemplate(npcActiveSkill));
                if (isClientLoading) {
                    npcActiveSkillEffectMap_.emplace(npcActiveSkill.skill_code(),
                        SkillClientEffectTemplate(npcActiveSkill));
                }
            }
            isLoaded_ = true;

            NpcActiveSkillTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const NpcActiveSkillTemplate* getNpcSkill(SkillCode code) const {
        const NpcSkillMap::const_iterator pos = npcActiveSkillMap_.find(code);
        if (pos != npcActiveSkillMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const SkillClientEffectTemplate* getClientEffect(SkillCode code) const {
        const SkillEffectMap::const_iterator pos = npcActiveSkillEffectMap_.find(code);
        if (pos != npcActiveSkillEffectMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const NpcSkillMap& getNpcSkillMap() const {
        return npcActiveSkillMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::npc_active_skill_table> npcActiveSkillTable_;
    NpcSkillMap npcActiveSkillMap_;
    SkillEffectMap npcActiveSkillEffectMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
