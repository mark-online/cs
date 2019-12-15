#pragma once

#include <gideon/cs/shared/data/QuestInfo.h>
#include <gideon/cs/shared/data/InventoryInfo.h>
#include <gideon/cs/shared/data/AccessoryInfo.h>
#include <gideon/cs/shared/data/Money.h>
#include <gideon/cs/shared/data/ErrorCode.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class InventoryRpc
 * 인벤토리 관련 RPC
 */
class InventoryRpc : public boost::noncopyable
{
public:
    virtual ~InventoryRpc() {}

public:

    /**
     * 인벤토리에서 아이템의 위치를 변경한다
     * - @param slotId 특정위치 없으면 invalidSlotId
     * - response: onMoveInventoryItem  (오류가 발생할 경우만 응답)
     * - event: (evInventoryItemCountUpdated, evInventoryItemRemoved)
     */
    DECLARE_SRPC_METHOD_3(InventoryRpc, moveInventoryItem,
        InvenType, invenType, ObjectId, itemId, SlotId, slotId);

    /**
     * 인벤토리에서 아이템들의 위치를 교환한다
     * - response: onSwitchInventoryItem  (오류가 발생할 경우만 응답)
     * - event: (evInventoryItemSwitched, evInventoryItemCountUpdated,
     *           evInventoryItemRemoved)
     */
    DECLARE_SRPC_METHOD_3(InventoryRpc, switchInventoryItem,
        InvenType, invenType, ObjectId, itemId1, ObjectId, itemId2);

    /**
     * 인벤토리에서 아이템을 삭제한다
     * - response: onRemoveInventoryItem  (오류가 발생할 경우만 응답)
     * - event: (evInventoryItemRemoved)
     */
    DECLARE_SRPC_METHOD_2(InventoryRpc, removeInventoryItem,
        InvenType, invenType, ObjectId, itemId);

    /**
     * 장비 장착을 요청한다
     * - response: onEquipItem (오류가 발생할 경우만 응답)
     * - event: evItemEquipped, (evEquipToInventoryReplaced)
     */
    DECLARE_SRPC_METHOD_1(InventoryRpc, equipItem,
        ObjectId, itemId);

    /**
     * 장비 탈착을 요청한다
     * - response: onUnequipItem (오류가 발생할 경우만 응답)
     * - event: evItemUnequipped, (자신만 받는 이벤트들)
     */
    DECLARE_SRPC_METHOD_2(InventoryRpc, unequipItem,
        ObjectId, itemId, SlotId, slotId);


    /**
     * 악세사리 장착을 요청한다
     * - response: onEquipAccessoryItem (오류가 발생할 경우만 응답)
     * - event: evAccessoryItemEquipped, (evAccessoryEquipToInventoryReplaced)
     */
    DECLARE_SRPC_METHOD_2(InventoryRpc, equipAccessoryItem,
        ObjectId, itemId, AccessoryIndex, index);

    /**
     * 장비 탈착을 요청한다
     * - response: onUnequipAccessoryItem (오류가 발생할 경우만 응답)
     * - event: evAccessoryItemUnequipped, (자신만 받는 이벤트들)
     */
    DECLARE_SRPC_METHOD_2(InventoryRpc, unequipAccessoryItem,
        ObjectId, itemId, SlotId, slotId);

    /**
     * 아이템 분활 요청한다
     * - response: onDivideItem (오류가 발생할 경우만 응답)
     * - event: evItemUnequipped, evInventoryItemAdded (자신만 받는 이벤트들)
     */
    DECLARE_SRPC_METHOD_4(InventoryRpc, divideItem,
        InvenType, invenType, ObjectId, itemId, uint8_t, count, SlotId, slotId);


    DECLARE_SRPC_METHOD_3(InventoryRpc, movePlayerInvenItemToBankInvenItem,
        GameObjectInfo, gameObjectInfo, ObjectId, playerItemId, SlotId, bankInvenSlot);

    DECLARE_SRPC_METHOD_3(InventoryRpc, moveBankInvenItemToPlayerInvenItem,
        GameObjectInfo, gameObjectInfo, ObjectId, bankItemId, SlotId, playerInvenSlot);

    DECLARE_SRPC_METHOD_3(InventoryRpc, switchBankInvenItemAndPlayerInvenItem,
        GameObjectInfo, gameObjectInfo, ObjectId, playerItemId, ObjectId, bankItemId);

    DECLARE_SRPC_METHOD_2(InventoryRpc, moveInvenItemToVehicleInvenItem,
        ObjectId, playerItemId, SlotId, vehicleInvenSlot);

    DECLARE_SRPC_METHOD_2(InventoryRpc, moveVehicleInvenItemToPlayerInvenItem,
        ObjectId, vehicleItemId, SlotId, playerInvenSlot);

    DECLARE_SRPC_METHOD_2(InventoryRpc, switchVehicleInvenItemAndPlayerInvenItem,
        ObjectId, playerItemId, ObjectId, vehicleItemId);

    DECLARE_SRPC_METHOD_2(InventoryRpc, depositGameMoney,
        GameObjectInfo, targetInfo, GameMoney, invenGameMoney);

    DECLARE_SRPC_METHOD_2(InventoryRpc, withdrawGameMoney,
        GameObjectInfo, targetInfo, GameMoney, bankGameMoney);
public:
    /// 장비 장착 요청에 대한 응답
    DECLARE_SRPC_METHOD_2(InventoryRpc, onEquipItem,
        ErrorCode, errorCode, ObjectId, itemId);

    /// 장비 탈착 요청에 대한 응답
    /// @param slotId 인벤토리 슬롯 ID
    DECLARE_SRPC_METHOD_3(InventoryRpc, onUnequipItem,
        ErrorCode, errorCode, ObjectId, itemId, SlotId, slotId);

    /// 인벤토리 아이템 위치 변경 요청에 대한 응답
    DECLARE_SRPC_METHOD_4(InventoryRpc, onMoveInventoryItem,
        ErrorCode, errorCode, InvenType, invenType, ObjectId, itemId, SlotId, slotId);

    /// 인벤토리 아이템들 위치 교환 요청에 대한 응답
    DECLARE_SRPC_METHOD_4(InventoryRpc, onSwitchInventoryItem,
        ErrorCode, errorCode, InvenType, invenType, ObjectId, itemId1, ObjectId, itemId2);

    /// 인벤토리 아이템 삭제 요청에 대한 응답
    DECLARE_SRPC_METHOD_3(InventoryRpc, onRemoveInventoryItem,
        ErrorCode, errorCode, InvenType, invenType, ObjectId, itemId);

    /// 아이템 분활 응답
    DECLARE_SRPC_METHOD_4(InventoryRpc, onDivideItem,
        ErrorCode, errorCode, InvenType, invenType, ObjectId, itemId, uint8_t, count);

    /// 악세사리 장착
    DECLARE_SRPC_METHOD_3(InventoryRpc, onEquipAccessoryItem,
        ErrorCode, errorCode, ObjectId, itemId, AccessoryIndex, index);

    /// 악세사리 탈착
    DECLARE_SRPC_METHOD_3(InventoryRpc, onUnequipAccessoryItem,
        ErrorCode, errorCode, ObjectId, itemId, SlotId, slotId);


    DECLARE_SRPC_METHOD_1(InventoryRpc, onMovePlayerInvenItemToBankInvenItem,
        ErrorCode, errorCode);


    DECLARE_SRPC_METHOD_1(InventoryRpc, onMoveBankInvenItemToPlayerInvenItem,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_1(InventoryRpc, onSwitchBankInvenItemAndPlayerInvenItem,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_1(InventoryRpc, onMoveInvenItemToVehicleInvenItem,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_1(InventoryRpc, onMoveVehicleInvenItemToPlayerInvenItem,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_1(InventoryRpc, onSwitchVehicleInvenItemAndPlayerInvenItem,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_3(InventoryRpc, onDepositGameMoney,
        ErrorCode, errorCode, GameMoney, bankGameMoney, GameMoney, invenGameMoney);

    DECLARE_SRPC_METHOD_3(InventoryRpc, onWithdrawGameMoney,
        ErrorCode, errorCode, GameMoney, bankGameMoney, GameMoney, invenGameMoney);


public:
    /// 관심 영역 내에서 누군가가 장비를 장착하였다
    DECLARE_SRPC_METHOD_2(InventoryRpc, evItemEquipped,
        GameObjectInfo, creatureInfo, EquipCode, equipCode);

    /// 관심 영역 내에서 누군가가 장비를 탈착하였다
    DECLARE_SRPC_METHOD_2(InventoryRpc, evItemUnequipped,
        GameObjectInfo, creatureInfo, EquipCode, equipCode);

public:
    /// 자신만 받는 인벤 이벤트 
    DECLARE_SRPC_METHOD_3(InventoryRpc, evInventoryItemCountUpdated,
        InvenType, invenType, ObjectId, itemId, uint8_t, ItemCount);

    DECLARE_SRPC_METHOD_2(InventoryRpc, evInventoryItemAdded,
        InvenType, invenType, ItemInfo,itemInfo);

    DECLARE_SRPC_METHOD_3(InventoryRpc, evInventoryEquipItemChanged,
        ObjectId, itemId, EquipCode, newEquipCode, uint8_t, socketCount);

    DECLARE_SRPC_METHOD_3(InventoryRpc, evEquipItemEnchanted,
        ObjectId, itemId, SocketSlotId, id, EquipSocketInfo, socketInfo);
        
    DECLARE_SRPC_METHOD_2(InventoryRpc, evEquipItemUnenchanted,
        ObjectId, itemId, SocketSlotId, id);

    DECLARE_SRPC_METHOD_2(InventoryRpc, evInventoryItemRemoved,
        InvenType, invenType, ObjectId, itemId);

    DECLARE_SRPC_METHOD_3(InventoryRpc, evInventoryItemMoved,
        InvenType, invenType, ObjectId, itemId, SlotId, slotId);

    DECLARE_SRPC_METHOD_3(InventoryRpc, evInventoryItemSwitched,
        InvenType, invenType, ObjectId, itemId1, ObjectId, itemId2);

    /// 자신만 받는 장착 이벤트
    // equip to invenMoved
    DECLARE_SRPC_METHOD_3(InventoryRpc, evUnequipItemReplaced, 
        ObjectId, itemId, SlotId, slotId, EquipPart, unequipPrt);

    /// inven to equip
    DECLARE_SRPC_METHOD_2(InventoryRpc, evEquipItemReplaced,
        ObjectId, itemId, EquipPart, equipPrt);

    /// switch equip && inven
    DECLARE_SRPC_METHOD_2(InventoryRpc, evInventoryWithEquipItemReplaced,
        ObjectId, itemId1, ObjectId, itemId2);

    /// 자신만 받는 장착 이벤트
    // equip to invenMoved
    DECLARE_SRPC_METHOD_3(InventoryRpc, evUnequipAccessoryItemReplaced, 
        ObjectId, itemId, SlotId, slotId, AccessoryIndex, unequipPrt);

    /// inven to equip
    DECLARE_SRPC_METHOD_2(InventoryRpc, evEquipAccessoryItemReplaced,
        ObjectId, itemId, AccessoryIndex, equipPrt);

    /// switch equip && inven
    DECLARE_SRPC_METHOD_4(InventoryRpc, evInventoryWithAccessoryItemReplaced,
        ObjectId, unequipItemId, AccessoryIndex, unequipIndex,
        ObjectId, equipItemId, AccessoryIndex, equipIndex);

    /// 자신만 받는 인벤 정보변경 이벤트
    // equip to invenMoved
    DECLARE_SRPC_METHOD_3(InventoryRpc, evInventoryInfoUpdated, 
        InvenType, invenTpe, bool, isCashSlot, uint8_t, currentExtendSlot);

private:
    /// = 퀘스트 인벤
    DECLARE_SRPC_METHOD_1(InventoryRpc, evQuestItemAdded, 
        QuestItemInfo, questItemInfo);

    DECLARE_SRPC_METHOD_1(InventoryRpc, evQuestItemRemoved,
        ObjectId, itemId);

    DECLARE_SRPC_METHOD_2(InventoryRpc, evQuestItemUsableCountUpdated,
        ObjectId, itemId, uint8_t, usableCount);
		
    DECLARE_SRPC_METHOD_2(InventoryRpc, evQuestItemCountUpdated,
        ObjectId, itemId, uint8_t, stackCount);

};

}} // namespace gideon { namespace rpc {