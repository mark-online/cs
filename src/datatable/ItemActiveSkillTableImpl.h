#pragma once

#include <gideon/cs/datatable/ItemActiveSkillTable.h>
#include <gideon/cs/datatable/SkillTemplate.h>
#include <gideon/cs/datatable/template/item_active_skill_table.hxx>

namespace gideon { namespace datatable {

/**
 * @class ItemActiveSkillTableImpl
 *
 */
class ItemActiveSkillTableImpl : public ItemActiveSkillTable
{
public:
    ItemActiveSkillTableImpl(std::istream& is, bool isClientLoading)  :
        isLoaded_(false) {
        try {
            itemActiveSkillTable_ =
                gdt::item_active_skill_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::item_active_skill_t& itemActiveSkill : itemActiveSkillTable_->item_active_skill_template()) {
                itemActiveSkillMap_.emplace(itemActiveSkill.skill_code(),
                    ItemActiveSkillTemplate(itemActiveSkill));
                if (isClientLoading) {
                    itemActiveSkillEffectMap_.emplace(itemActiveSkill.skill_code(),
                        SkillClientEffectTemplate(itemActiveSkill));
                }
            }
            isLoaded_ = true;

            ItemActiveSkillTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const ItemActiveSkillTemplate* getItemSkill(SkillCode code) const {
        const ItemSkillMap::const_iterator pos = itemActiveSkillMap_.find(code);
        if (pos != itemActiveSkillMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const SkillClientEffectTemplate* getClientEffect(SkillCode code) const {
        const SkillEffectMap::const_iterator pos = itemActiveSkillEffectMap_.find(code);
        if (pos != itemActiveSkillEffectMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const ItemSkillMap& getItemSkillMap() const {
        return itemActiveSkillMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::item_active_skill_table> itemActiveSkillTable_;
    ItemSkillMap itemActiveSkillMap_;
    SkillEffectMap itemActiveSkillEffectMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
