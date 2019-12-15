#pragma once

#include <gideon/cs/datatable/CharacterDefaultSkillTable.h>
#include <gideon/cs/datatable/template/character_default_skill_table.hxx>
#include <gideon/cs/shared/data/SkillInfo.h>

namespace gideon { namespace datatable {

inline DataCode getDefaultSkillCode(const gdt::character_default_skill_t& defaultSkill, int index)
{
    switch(index) {
    case 1:
        return defaultSkill.skill_code_1();
    case 2:
        return defaultSkill.skill_code_2();
    case 3:
        return defaultSkill.skill_code_3();
    case 4:
        return defaultSkill.skill_code_4();
    case 5:
        return defaultSkill.skill_code_5();
    case 6:
        return defaultSkill.skill_code_6();
    case 7:
        return defaultSkill.skill_code_7();
    case 8:
        return defaultSkill.skill_code_8();
    }
    assert(false);
    return invalidDataCode;
}

inline ActionBarPosition getActionBarPosition(const gdt::character_default_skill_t& defaultSkill, int index)
{
    switch(index) {
    case 1:
        return toActionBarPosition(defaultSkill.action_bar_1());
    case 2:
        return toActionBarPosition(defaultSkill.action_bar_2());
    case 3:
        return toActionBarPosition(defaultSkill.action_bar_3());
    case 4:
        return toActionBarPosition(defaultSkill.action_bar_4());
    case 5:
        return toActionBarPosition(defaultSkill.action_bar_5());
    case 6:
        return toActionBarPosition(defaultSkill.action_bar_6());
    case 7:
        return toActionBarPosition(defaultSkill.action_bar_7());
    case 8:
        return toActionBarPosition(defaultSkill.action_bar_8());
    }
    assert(false);
    return abpCount;
}

inline DefaultSkillInfo getDefaultSkillInfo(const gdt::character_default_skill_t& defaultSkill, int index) 
{
    return DefaultSkillInfo(getDefaultSkillCode(defaultSkill, index), getActionBarPosition(defaultSkill, index));
}

/**
 * @class CharacterDefaultSkillTableImpl
 *
 */
class CharacterDefaultSkillTableImpl : public CharacterDefaultSkillTable
{
public:
    CharacterDefaultSkillTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            defaultSkillTable_ =
                gdt::character_default_skill_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::character_default_skill_t& defaultSkill :
                defaultSkillTable_->character_default_skill_template()) {
                DefaultSkillInfos defaultSkills;
                for (int i = 1; i <= 8; ++i) {
                    DefaultSkillInfo skillInfo(getDefaultSkillInfo(defaultSkill, i));
                    if (skillInfo.isValid()) {
                        defaultSkills.push_back(skillInfo);
                    }
                }
                defaultSkillMap_.emplace(toEquipType(defaultSkill.weapon_type()),
                    CharacterDefaultSkillInfo(defaultSkills));
            }
            isLoaded_ = true;

            CharacterDefaultSkillTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const CharacterDefaultSkillInfo* getCharacterDefaultSkillInfo(EquipType equipType) const {
        const CharacterDefaultSkillInfoMap::const_iterator pos = defaultSkillMap_.find(equipType);
        if (pos != defaultSkillMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const CharacterDefaultSkillInfoMap& getCharacterDefaultSkillInfoMap() const {
        return defaultSkillMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::character_default_skill_table> defaultSkillTable_;
    CharacterDefaultSkillInfoMap defaultSkillMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
