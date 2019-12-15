#pragma once

#include <gideon/cs/shared/data/EquipmentInfo.h>
#include <gideon/cs/shared/data/SkillInfo.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {
    

/**
 * @class DefaultSkillInfo
 *
 */
struct DefaultSkillInfo
{
    SkillCode skillCode_;
    ActionBarPosition position_;

    explicit DefaultSkillInfo(DataCode skillCode,
        ActionBarPosition position) :
        skillCode_(skillCode),
        position_(position)
    {
    }

    bool isValid() const {
        return isValidSkillCode(skillCode_);
    }
};


typedef sne::core::Vector<DefaultSkillInfo> DefaultSkillInfos;

/**
 * @class CharacterDefaultSkillInfo
 *
 */
class CharacterDefaultSkillInfo
{
public:
    CharacterDefaultSkillInfo(const DefaultSkillInfos& defaultSkills) :
        defaultSkills_(defaultSkills)
    {
    }

    const DefaultSkillInfos& getCharacterDefaultSkills() const {
        return defaultSkills_;
    }

    bool hasOnlyDefaultSkill(CreatureSkills& creatureSkills) const {
        for (SkillCode skillCode : creatureSkills) {
            if (! isExist(skillCode)) {
                return false;
            }
        }
        return true;
    }

private:
    bool isExist(SkillCode skillCode) const {
        for (const DefaultSkillInfo& info : defaultSkills_) {
            if (info.skillCode_ == skillCode) {
                return true;
            }
        }
        return false;
    }
private:
    DefaultSkillInfos defaultSkills_;
};

/**
 * @class CharacterDefaultSkillTable
 *
 */
class GIDEON_CS_API CharacterDefaultSkillTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(CharacterDefaultSkillTable);

public:
    typedef sne::core::HashMap<EquipType, CharacterDefaultSkillInfo> CharacterDefaultSkillInfoMap;

public:
    virtual ~CharacterDefaultSkillTable() {}

public:
    virtual const CharacterDefaultSkillInfo* getCharacterDefaultSkillInfo(EquipType equipType) const = 0;

    virtual const CharacterDefaultSkillInfoMap& getCharacterDefaultSkillInfoMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define CHARACTER_DEFAULT_SKILL_TABLE gideon::datatable::CharacterDefaultSkillTable::instance()
