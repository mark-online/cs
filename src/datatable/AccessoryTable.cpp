#include "DataTablePCH.h"
#include <gideon/cs/datatable/AccessoryTable.h>
#include <gideon/cs/shared/data/CharacterInfo.h>
#include <gideon/cs/datatable/ApplyItemStatusFunction.h>

namespace gideon { namespace datatable {

namespace {


void applyValue(CreatureStatusInfo& gameStatus, uint32_t index, const gdt::accessory_t& equip)
{
    switch (index) {
    case 1:
        applyStatus(gameStatus, toEffectScriptType(equip.apply_script_1()), equip.apply_value_1(), false);
        return;
    case 2:
        applyStatus(gameStatus, toEffectScriptType(equip.apply_script_2()), equip.apply_value_2(), false);
        return;
    }
}


void unapplyValue(CreatureStatusInfo& gameStatus, uint32_t index, const gdt::accessory_t& equip)
{
    switch (index) {
    case 1:
        applyStatus(gameStatus, toEffectScriptType(equip.apply_script_1()), equip.apply_value_1(), true);
        return;
    case 2:
        applyStatus(gameStatus, toEffectScriptType(equip.apply_script_2()), equip.apply_value_2(), true);
        return;
    }
}
} // namespace {

SNE_DEFINE_SINGLETON(AccessoryTable);


bool AccessoryTable::applyCreatureStatusInfo(CreatureStatusInfo& gameStatus,
    const InventoryInfo& inventory, const CharacterAccessories& accessories)
{
    for (int i = aiFirst; i < aiCount; ++i) {
        const ObjectId itemId = accessories[i];
        if (! isValidObjectId(itemId)) {
            continue;
        }

        const ItemInfo* itemInfo = inventory.getItemInfo(itemId);
        assert(itemInfo != nullptr);
        if (! itemInfo) {
            return false; // TODO: 로깅
        }

        const gdt::accessory_t* accessory = getAccessory(itemInfo->itemCode_);
        assert(accessory != nullptr);
        if (! accessory) {
            return false; // TODO: 로깅
        }

        for (uint32_t s = 1; s <= 2; ++s) {
            applyValue(gameStatus, s, *accessory);
        }

        for (const ItemScriptInfo& info : itemInfo->accessoryItemInfo_.addOptions_) {
            applyStatus(gameStatus, info.scriptType_, info.value_, false);
        }
    }

    return true;
}


bool AccessoryTable::applyCreatureStatusInfoByEquip(CreatureStatusInfo& gameStatus, 
    AccessoryCode accessoryCode, const AccessoryItemInfo& accessoryItemInfo)
{
    const gdt::accessory_t* accessory = getAccessory(accessoryCode);
    assert(accessory != nullptr);
    if (! accessory) {
        return false; // TODO: 로깅
    }


    for (uint32_t i = 1; i <= 2; ++i) {
        applyValue(gameStatus, i, *accessory);
    }

    for (const ItemScriptInfo& info : accessoryItemInfo.addOptions_) {
        applyStatus(gameStatus, info.scriptType_, info.value_, false);
    }

    return true;
}



bool AccessoryTable::applyCreatureStatusInfoByUnequip(CreatureStatusInfo& gameStatus,
    AccessoryCode accessoryCode, const AccessoryItemInfo& accessoryItemInfo)
{
    const gdt::accessory_t* accessory = getAccessory(accessoryCode);
    assert(accessory != nullptr);
    if (! accessory) {
        return false; // TODO: 로깅
    }

    for (uint32_t i = 1; i <= 2; ++i) {
        unapplyValue(gameStatus, i, *accessory);
    }

    for (const ItemScriptInfo& info : accessoryItemInfo.addOptions_) {
        applyStatus(gameStatus, info.scriptType_, info.value_, true);
    }

    return true;
}

}} // namespace gideon { namespace datatable {
