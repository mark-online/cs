#pragma once

#include <gideon/cs/shared/data/CharacterTitleInfo.h>
#include <gideon/cs/datatable/template/character_title_table.hxx>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @class CharacterTitleTable
 *
 */
class GIDEON_CS_API CharacterTitleTable : public boost::noncopyable
{
	SNE_DECLARE_SINGLETON(CharacterTitleTable);

public:
    typedef sne::core::HashMap<CharacterTitleCode, const gdt::character_title_t*> CharacterTitleMap;

public:
    virtual ~CharacterTitleTable() {}

public:
    virtual const gdt::character_title_t* getCharacterTitleTemplate(CharacterTitleCode titleCode) const = 0;

    virtual const CharacterTitleMap& getCharacterTitleMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define CHARACTER_TITLE_TABLE gideon::datatable::CharacterTitleTable::instance()
