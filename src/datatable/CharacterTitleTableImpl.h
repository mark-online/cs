#pragma once

#include <gideon/cs/datatable/CharacterTitleTable.h>

namespace gideon { namespace datatable {

/**
 * @class CharacterTitleTableImpl
 *
 */
class CharacterTitleTableImpl : public CharacterTitleTable
{
public:
    CharacterTitleTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            characterTitleTable_ =
                gdt::character_title_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::character_title_t& gem : characterTitleTable_->character_title_template()) {
                characterTitleMap_.emplace(gem.character_title_code(), &gem);
            }
            isLoaded_ = true;

            CharacterTitleTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const gdt::character_title_t* getCharacterTitleTemplate(CharacterTitleCode titleCode) const {
        const CharacterTitleMap::const_iterator pos = characterTitleMap_.find(titleCode);
        if (pos != characterTitleMap_.end()) {
            return (*pos).second;
        }
        return nullptr;
    }

    virtual const CharacterTitleMap& getCharacterTitleMap() const {
        return characterTitleMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::character_title_table> characterTitleTable_;
    CharacterTitleMap characterTitleMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
