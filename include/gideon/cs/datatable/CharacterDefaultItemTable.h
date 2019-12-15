#pragma once

#include <gideon/cs/shared/data/CharacterClass.h>
#include <gideon/cs/shared/data/Code.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @class CharacterDefaultItemInfo
 *
 */
class CharacterDefaultItemInfo
{
public:
    CharacterDefaultItemInfo(const DataCodes& defaultDefenceItems,
        const DataCodes& defaultMainWeaponItems, const DataCode defaultSubWeaponItem) :
        defaultDefenceItems_(defaultDefenceItems),
        defaultMainWeaponItems_(defaultMainWeaponItems),
        defaultSubWeaponItem_(defaultSubWeaponItem) {}

    const DataCodes& getDefaultDefenceItems() const {
        return defaultDefenceItems_;
    }

    const DataCodes& getDefaultMainWeaponItems() const {
        return defaultMainWeaponItems_;
    }

    const bool hasMainWeapon(DataCode mainWeaponCode) const {
        for (DataCode itemCode : defaultMainWeaponItems_) {
            if (itemCode == mainWeaponCode) {
                return true;
            }
        }
        return false;
    }

    DataCode getDefaultSubWeaponItem() const {
        return defaultSubWeaponItem_;
    }
    
private:
    DataCodes defaultDefenceItems_;
    DataCodes defaultMainWeaponItems_;
    DataCode defaultSubWeaponItem_;
};

/**
 * @class CharacterDefaultItemTable
 *
 */
class GIDEON_CS_API CharacterDefaultItemTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(CharacterDefaultItemTable);

public:
    typedef sne::core::HashMap<CharacterClass, CharacterDefaultItemInfo> CharacterDefaultItemInfoMap;

public:
    virtual ~CharacterDefaultItemTable() {}

public:
    virtual const CharacterDefaultItemInfo* getCharacterDefaultItemInfo(CharacterClass characterClass) const = 0;

    virtual const CharacterDefaultItemInfoMap& getCharacterDefaultItemInfoMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define CHARACTER_DEFAULT_ITEM_TABLE gideon::datatable::CharacterDefaultItemTable::instance()
