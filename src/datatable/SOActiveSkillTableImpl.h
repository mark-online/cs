#pragma once

#include <gideon/cs/datatable/SOActiveSkillTable.h>
#include <gideon/cs/datatable/SkillTemplate.h>
#include <gideon/cs/datatable/template/so_active_skill_table.hxx>

namespace gideon { namespace datatable {

/**
 * @class SOActiveSkillTableImpl
 *
 */
class SOActiveSkillTableImpl : public SOActiveSkillTable
{
public:
    SOActiveSkillTableImpl(std::istream& is, bool isClientLoading)  :
        isLoaded_(false) {
        try {
            soActiveSkillTable_ =
                gdt::so_active_skill_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::so_active_skill_t& soActiveSkill : soActiveSkillTable_->so_active_skill_template()) {
                soActiveSkillMap_.emplace(soActiveSkill.skill_code(),
                    SOActiveSkillTemplate(soActiveSkill));
                if (isClientLoading) {
                    soActiveSkillEffectMap_.emplace(soActiveSkill.skill_code(),
                        SkillClientEffectTemplate(soActiveSkill));
                }
            }
            isLoaded_ = true;

            SOActiveSkillTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const SOActiveSkillTemplate* getSOSkill(SkillCode code) const {
        const SOSkillMap::const_iterator pos = soActiveSkillMap_.find(code);
        if (pos != soActiveSkillMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const SkillClientEffectTemplate* getClientEffect(SkillCode code) const {
        const SkillEffectMap::const_iterator pos = soActiveSkillEffectMap_.find(code);
        if (pos != soActiveSkillEffectMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const SOSkillMap& getSOSkillMap() const {
        return soActiveSkillMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::so_active_skill_table> soActiveSkillTable_;
    SOSkillMap soActiveSkillMap_;
    SkillEffectMap soActiveSkillEffectMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
