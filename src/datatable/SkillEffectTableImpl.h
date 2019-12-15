#pragma once

#include <gideon/cs/datatable/SkillEffectTable.h>

namespace gideon { namespace datatable {

/**
 * @class SkillEffectTableImpl
 *
 */
class SkillEffectTableImpl : public SkillEffectTable
{
public:
    SkillEffectTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            skillEffectTable_ =
                gdt::skill_effect_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::skill_effect_t& skillEffect : skillEffectTable_->skill_effect_template()) {
                skillEffectMap_.emplace(skillEffect.skill_effect_index(), SkillEffectTemplate(&skillEffect));
            }
            isLoaded_ = true;

            SkillEffectTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const SkillEffectTemplate* getSkillEffectTemplate(uint16_t skillEffectIndex) const {
        const SkillEffectMap::const_iterator pos = skillEffectMap_.find(skillEffectIndex);
        if (pos != skillEffectMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const SkillEffectMap& getSkillEffectMap() const {
        return skillEffectMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::skill_effect_table> skillEffectTable_;
    SkillEffectMap skillEffectMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
