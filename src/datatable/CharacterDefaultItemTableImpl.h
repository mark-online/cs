#pragma once

#include <gideon/cs/datatable/CharacterDefaultItemTable.h>
#include <gideon/cs/datatable/template/character_default_item_table.hxx>
#include <gideon/cs/shared/data/EquipmentInfo.h>

namespace gideon { namespace datatable {

namespace {

inline DataCode getDefenceItemCode(const gdt::character_default_item_t& defaultItem, int index)
{
    switch(index) {
    case 1:
        return defaultItem.defence_item_code_1();
    case 2:
        return defaultItem.defence_item_code_2();
    case 3:
        return defaultItem.defence_item_code_3();
    case 4:
        return defaultItem.defence_item_code_4();
    }
    assert(false);
    return invalidDataCode;
}

inline DataCode getMainWeaponItemCode(const gdt::character_default_item_t& defaultItem, int index)
{
    switch(index) {
    case 1:
        return defaultItem.main_weapon_item_code_1();
    case 2:
        return defaultItem.main_weapon_item_code_2();
    case 3:
        return defaultItem.main_weapon_item_code_3();
    case 4:
        return defaultItem.main_weapon_item_code_4();
    }
    assert(false);
    return invalidDataCode;
}

inline DataCode getSubWeaponItemCode(const gdt::character_default_item_t& defaultItem, int index)
{
    switch(index) {
    case 1:
        return defaultItem.sub_weapon_item_code_1();
    }
    assert(false);
    return invalidDataCode;
}
}

/**
 * @class CharacterDefaultItemTableImpl
 *
 */
class CharacterDefaultItemTableImpl : public CharacterDefaultItemTable
{
public:
    CharacterDefaultItemTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            defaultItemTable_ =
                gdt::character_default_item_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::character_default_item_t& defaultItem :
                defaultItemTable_->character_default_item_template()) {
                DataCodes defaultDefenceItems;
                DataCodes defaultMainWeaponItems;
                DataCodes defaultSubWeaponItems;
                for (int i = 1; i <= 4; ++i) {
                    EquipCode itemCode = getDefenceItemCode(defaultItem, i);
                    if (isValidEquipCode(itemCode)) {
                        defaultDefenceItems.push_back(itemCode);
                    }
                }
                for (int i = 1; i <= 4; ++i) {
                    EquipCode itemCode = getMainWeaponItemCode(defaultItem, i);
                    if (isValidEquipCode(itemCode)) {
                        defaultMainWeaponItems.push_back(itemCode);
                    }
                }
                
                const EquipCode itemCode = getSubWeaponItemCode(defaultItem, 1);
                                    
                defaultItemMap_.emplace(toCharacterClass(defaultItem.character_class()),
                    CharacterDefaultItemInfo(defaultDefenceItems, defaultMainWeaponItems, itemCode));
            }
            isLoaded_ = true;

            CharacterDefaultItemTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const CharacterDefaultItemInfo* getCharacterDefaultItemInfo(CharacterClass characterClass) const {
        const CharacterDefaultItemInfoMap::const_iterator pos = defaultItemMap_.find(characterClass);
        if (pos != defaultItemMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const CharacterDefaultItemInfoMap& getCharacterDefaultItemInfoMap() const {
        return defaultItemMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::character_default_item_table> defaultItemTable_;
    CharacterDefaultItemInfoMap defaultItemMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
