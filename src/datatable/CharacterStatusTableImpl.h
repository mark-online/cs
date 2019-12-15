#pragma once

#include <gideon/cs/datatable/CharacterStatusTable.h>

namespace gideon { namespace datatable {

/**
 * @class CharacterStatusTableImpl
 *
 */
class CharacterStatusTableImpl : public CharacterStatusTable
{
public:
    CharacterStatusTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            characterStatusTable_ =
                gdt::character_status_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::character_status_t& characterStatus : characterStatusTable_->character_status_template()) {
                CharacterClassStatusMap::iterator pos = characterClassStatusMap_.find(toCharacterClass(characterStatus.character_class()));
                if (pos != characterClassStatusMap_.end()) {
                    CharacterStatusMap& statusMap = (*pos).second;                    
                    statusMap.emplace(characterStatus.level(), &characterStatus);
                }
                else {
                    CharacterStatusMap statusMap;
                    statusMap.insert(CharacterStatusMap::value_type(characterStatus.level(), &characterStatus));
                    characterClassStatusMap_.emplace(
                        toCharacterClass(characterStatus.character_class()), statusMap);
                }    
            }
            isLoaded_ = true;

            CharacterStatusTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const gdt::character_status_t* getCharacterStatus(CharacterClass cc, CreatureLevel cl, LevelStep ls) const {
        
        const CharacterClassStatusMap::const_iterator pos = characterClassStatusMap_.find(cc);
        if (pos != characterClassStatusMap_.end()) {
            const CharacterStatusMap statusMap = (*pos).second;
            uint32_t level = (cl * 10) + ls;
            const CharacterStatusMap::const_iterator statusPos = statusMap.find(level);
            if (statusPos != statusMap.end()) {
                return (*statusPos).second;
            }
        }
        
        return nullptr;
    }

    virtual const CharacterClassStatusMap& getCharacterClassStatusMap() const {
        return characterClassStatusMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:    
    std::unique_ptr<gdt::character_status_table> characterStatusTable_;
    CharacterClassStatusMap characterClassStatusMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
