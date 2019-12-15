#include "DataTablePCH.h"
#include <gideon/cs/datatable/EquipTable.h>
#include <gideon/cs/datatable/ApplyItemStatusFunction.h>
#include <gideon/cs/shared/data/CharacterInfo.h>

namespace gideon { namespace datatable {

namespace {


void applyValue(CreatureStatusInfo& gameStatus, uint32_t index, const gdt::equip_t& equip)
{
    switch (index) {
    case 1:
        applyStatus(gameStatus, toEffectScriptType(equip.apply_script_1()), equip.apply_value_1(), false);
        return;
    case 2:
        applyStatus(gameStatus, toEffectScriptType(equip.apply_script_2()), equip.apply_value_2(), false);
        return;
    case 3:
        applyStatus(gameStatus, toEffectScriptType(equip.apply_script_3()), equip.apply_value_3(), false);
        return;
    case 4:
        applyStatus(gameStatus, toEffectScriptType(equip.apply_script_4()), equip.apply_value_4(), false);
        return;
    }
}


void unapplyValue(CreatureStatusInfo& gameStatus, uint32_t index, const gdt::equip_t& equip)
{
    switch (index) {
    case 1:
        applyStatus(gameStatus, toEffectScriptType(equip.apply_script_1()), equip.apply_value_1(), true);
        return;
    case 2:
        applyStatus(gameStatus, toEffectScriptType(equip.apply_script_2()), equip.apply_value_2(), true);
        return;
    case 3:
        applyStatus(gameStatus, toEffectScriptType(equip.apply_script_3()), equip.apply_value_3(), true);
        return;
    case 4:
        applyStatus(gameStatus, toEffectScriptType(equip.apply_script_4()), equip.apply_value_4(), true);
        return;
    }
}

} // namespace {

SNE_DEFINE_SINGLETON(EquipTable);


bool EquipTable::applyCreatureStatusInfo(CreatureStatusInfo& gameStatus,
    const InventoryInfo& inventory, const CharacterEquipments& equipments)
{
    for (int i = epFirst; i < epCount; ++i) {
        const ObjectId itemId = equipments[i];
        if (! isValidObjectId(itemId)) {
            continue;
        }

        const ItemInfo* itemInfo = inventory.getItemInfo(itemId);
        assert(itemInfo != nullptr);
        if (! itemInfo) {
            return false; // TODO: 로깅
        }

        const gdt::equip_t* equip = getEquip(itemInfo->itemCode_);
        assert(equip != nullptr);
        if (! equip) {
            return false; // TODO: 로깅
        }
        
        for (uint32_t s = 1; s <= 4; ++s) {
            applyValue(gameStatus, s, *equip);
        }

        for (const ItemScriptInfo& info : itemInfo->equipItemInfo_.addOptions_) {
            applyStatus(gameStatus, info.scriptType_, info.value_, false);
        }
        
        for (const EquipSocketInfoMap::value_type& value : itemInfo->equipItemInfo_.equipSocketInfoMap_) {
            const EquipSocketInfo& socketInfo = value.second;
            for (const ItemScriptInfo& info : socketInfo.scriptInfos_) {
                applyStatus(gameStatus, info.scriptType_, info.value_, false);
            }
        }
    }

    return true;
}


bool EquipTable::applyCreatureStatusInfoByEquip(CreatureStatusInfo& gameStatus,
    EquipCode equipCode, const EquipItemInfo& equipItemInfo)
{
    const gdt::equip_t* equip = getEquip(equipCode);
    assert(equip != nullptr);
    if (! equip) {
        return false; // TODO: 로깅
    }


    for (uint32_t i = 1; i <= 4; ++i) {
        applyValue(gameStatus, i, *equip);
    }

    for (const ItemScriptInfo& info : equipItemInfo.addOptions_) {
        applyStatus(gameStatus, info.scriptType_, info.value_, false);
    }

    for (const EquipSocketInfoMap::value_type& value : equipItemInfo.equipSocketInfoMap_) {
        const EquipSocketInfo& socketInfo = value.second;
        for (const ItemScriptInfo& info : socketInfo.scriptInfos_) {
            applyStatus(gameStatus, info.scriptType_, info.value_, false);
        }
    }
    return true;
}



bool EquipTable::applyCreatureStatusInfoByUnequip(CreatureStatusInfo& gameStatus,
    EquipCode equipCode, const EquipItemInfo& equipItemInfo)
{
    const gdt::equip_t* equip = getEquip(equipCode);
    assert(equip != nullptr);
    if (! equip) {
        return false; // TODO: 로깅
    }

    for (uint32_t i = 1; i <= 4; ++i) {
        unapplyValue(gameStatus, i, *equip);
    }

    for (const ItemScriptInfo& info : equipItemInfo.addOptions_) {
        applyStatus(gameStatus, info.scriptType_, info.value_, true);
    }

    for (const EquipSocketInfoMap::value_type& value : equipItemInfo.equipSocketInfoMap_) {
        const EquipSocketInfo& socketInfo = value.second;
        for (const ItemScriptInfo& info : socketInfo.scriptInfos_) {
            applyStatus(gameStatus, info.scriptType_, info.value_, true);
        }
    }
    return true;
}

}} // namespace gideon { namespace datatable {
