#pragma once

#include <gideon/cs/datatable/template/character_status_table.hxx>
#include <gideon/cs/shared/data/LevelInfo.h>
#include <gideon/cs/shared/data/CreatureStatusInfo.h>
#include <gideon/cs/shared/data/CharacterClass.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon {
struct CreatureStatusInfo;
} // namespace gideon {

namespace gideon { namespace datatable {

/**
 * @class CharacterStatusTable
 *
 */
class GIDEON_CS_API CharacterStatusTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(CharacterStatusTable);

public:
    typedef sne::core::HashMap<uint32_t, const gdt::character_status_t*> CharacterStatusMap;
    typedef sne::core::HashMap<CharacterClass, CharacterStatusMap> CharacterClassStatusMap;
public:
    virtual ~CharacterStatusTable() {}

public:
    virtual const gdt::character_status_t* getCharacterStatus(CharacterClass cc, CreatureLevel cl, LevelStep ls) const = 0;

    virtual const CharacterClassStatusMap& getCharacterClassStatusMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;

public:
    /// 스텟 능력치를 적용한다(초기).
    bool applyCreatureStatusInfo(CharacterClass characterClass, BaseStatus& baseStatus,
        CreatureLevel cl, LevelStep ls);
    
    // 렙 변경시
    bool applyCreatureStatusInfo(CharacterClass characterClass, BaseStatus& baseStatus,
        CreatureLevel orgCl, LevelStep orgLs, CreatureLevel newCl, LevelStep newLs);

    // 클래스가 바뀌었을때
    bool applyCreatureStatusInfo(CharacterClass orgClass, CharacterClass newClass,
        BaseStatus& baseStatus, CreatureLevel cl, LevelStep ls);
};

}} // namespace gideon { namespace datatable {

#define CHARACTER_STATUS_TABLE gideon::datatable::CharacterStatusTable::instance()
