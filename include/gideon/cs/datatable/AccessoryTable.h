#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/datatable/template/accessory_table.hxx>
#include <gideon/cs/shared/data/AccessoryInfo.h>
#include <gideon/cs/shared/data/CreatureStatusInfo.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon {
struct CharacterInfo;
struct CreatureStatusInfo;
} // namespace gideon {

namespace gideon { namespace datatable {

/**
 * @class AccessoryTable
 *
 */
class GIDEON_CS_API AccessoryTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(AccessoryTable);

public:
    typedef sne::core::HashMap<AccessoryCode, const gdt::accessory_t*> AccessoryMap;

public:
    virtual ~AccessoryTable() {}

public:
    virtual const gdt::accessory_t* getAccessory(AccessoryCode code) const = 0;

    virtual const AccessoryMap& getAccessoryMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;

public:
    /// 장착 장비에 스텟 능력치를 적용한다.
    bool applyCreatureStatusInfo(CreatureStatusInfo& gameStatus,
        const InventoryInfo& inventory, const CharacterAccessories& accessories);

    /// 특정 장비의 스탯을 적용한다
    bool applyCreatureStatusInfoByEquip(CreatureStatusInfo& gameStats,
        AccessoryCode accessoryCode, const AccessoryItemInfo& accessoryItemInfo);

    /// 특정 장비의 스탯을 적용한다
    bool applyCreatureStatusInfoByUnequip(CreatureStatusInfo& gameStats,
        AccessoryCode accessoryCode, const AccessoryItemInfo& accessoryItemInfo);

};

}} // namespace gideon { namespace datatable {

#define ACCESSORY_TABLE gideon::datatable::AccessoryTable::instance()
