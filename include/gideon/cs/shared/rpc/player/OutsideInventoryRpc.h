#pragma once
#include <gideon/cs/shared/data/ObjectInfo.h>
#include <gideon/cs/shared/data/InventoryInfo.h>
#include <gideon/cs/shared/data/VaultInfo.h>
#include <gideon/cs/shared/data/Money.h>
#include <sne/srpc/RpcInterface.h>
#include "../../data/ErrorCode.h"

namespace gideon { namespace rpc {

/**
 * @class OutsideInventoryRpc
 * 플레이어 외부 인벤토리 관련 RPC
 */
class OutsideInventoryRpc
{
public:
    virtual ~OutsideInventoryRpc() {}

public:
    DECLARE_SRPC_METHOD_4(OutsideInventoryRpc, movePlayerInvenItemToOutsideInvenItem,
        GameObjectInfo, gameObjectInfo, ObjectId, playerItemId, InvenType, buildInvenType,
        SlotId, buildInvenSlot);
    DECLARE_SRPC_METHOD_4(OutsideInventoryRpc, moveOutsideInvenItemToPlayerInvenItem,
        GameObjectInfo, gameObjectInfo, ObjectId, buildingItemId, InvenType, buildInvenType,
        SlotId, playerInvenSlot);
    DECLARE_SRPC_METHOD_4(OutsideInventoryRpc, switchOutsideInvenItemAndPlayerInvenItem,
        GameObjectInfo, gameObjectInfo, ObjectId, playerItemId, InvenType, buildInvenType,
        ObjectId, buildingItemId);

    DECLARE_SRPC_METHOD_4(OutsideInventoryRpc, moveItemOutsideInventory,
        GameObjectInfo, gameObjectInfo, InvenType, invenType, ObjectId, itemId,
        SlotId, moveSlotId);
    DECLARE_SRPC_METHOD_4(OutsideInventoryRpc, switchOutsideInventoryItem,
        GameObjectInfo, gameObjectInfo, InvenType, invenType, ObjectId, itemId1, ObjectId, itemId2);
    DECLARE_SRPC_METHOD_3(OutsideInventoryRpc, removeOutsideInventoryItem,
        GameObjectInfo, gameObjectInfo, InvenType, invenType, ObjectId, itemId);
    DECLARE_SRPC_METHOD_5(OutsideInventoryRpc, divideOutsideInventoryItem,
        GameObjectInfo, gameObjectInfo, InvenType, invenType, ObjectId, itemId, uint8_t, count, SlotId, slotId);
    DECLARE_SRPC_METHOD_2(OutsideInventoryRpc, openOutsideInventory,
        GameObjectInfo, gameObjectInfo, InvenType, invenType);
    DECLARE_SRPC_METHOD_1(OutsideInventoryRpc, closeOutsideInventory,
        InvenType, invenType);

    DECLARE_SRPC_METHOD_4(OutsideInventoryRpc, pushGuildInventoryItem,
        GameObjectInfo, gameObjectInfo, ObjectId, myItemId, VaultId, vaultId, SlotId, guildSlotId);
    DECLARE_SRPC_METHOD_5(OutsideInventoryRpc, popGuildInventoryItem,
        GameObjectInfo, gameObjectInfo, VaultId, vaultId, ObjectId, guildItemId, SlotId, mySlotId, BaseItemInfo, baseItemInfo);
    DECLARE_SRPC_METHOD_4(OutsideInventoryRpc, switchGuildInventoryItem,
        GameObjectInfo, gameObjectInfo, VaultId, vaultId, ObjectId, guildItemId, ObjectId, myItemId);
    DECLARE_SRPC_METHOD_2(OutsideInventoryRpc, depositGuildGameMoney,
        GameObjectInfo, gameObjectInfo, GameMoney, gameMoney);
    DECLARE_SRPC_METHOD_2(OutsideInventoryRpc, withdrawGuildGameMoney,
        GameObjectInfo, gameObjectInfo, GameMoney, gameMoney);


public:
    DECLARE_SRPC_METHOD_1(OutsideInventoryRpc, onMovePlayerInvenItemToOutsideInvenItem,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_1(OutsideInventoryRpc, onMoveOutsideInvenItemToPlayerInvenItem,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_1(OutsideInventoryRpc, onSwitchOutsideInvenItemAndPlayerInvenItem,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_1(OutsideInventoryRpc, onMoveItemOutsideInventory,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_1(OutsideInventoryRpc, onSwitchOutsideInventoryItem,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_1(OutsideInventoryRpc, onRemoveOutsideInventoryItem,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_1(OutsideInventoryRpc, onDivideOutsideInventoryItem,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_4(OutsideInventoryRpc, onOpenOutsideInventory,
        ErrorCode, errorCode, GameObjectInfo, gameObjectInfo, InvenType, invenType,
        InventoryInfo, inventoryInfo);

    DECLARE_SRPC_METHOD_1(OutsideInventoryRpc, onPushGuildInventoryItem,
        ErrorCode, errorCode);
    DECLARE_SRPC_METHOD_1(OutsideInventoryRpc, onPopGuildInventoryItem,
        ErrorCode, errorCode);
    DECLARE_SRPC_METHOD_1(OutsideInventoryRpc, onSwitchGuildInventoryItem,
        ErrorCode, errorCode);
    DECLARE_SRPC_METHOD_2(OutsideInventoryRpc, onDepositGuildGameMoney,
        ErrorCode, errorCode, GameMoney, gameMoney);
    // todayWithdraw 길드 멤버에 24시간 동안 빼낸돈
    DECLARE_SRPC_METHOD_4(OutsideInventoryRpc, onWithdrawGuildGameMoney,
        ErrorCode, errorCode, sec_t, resetDayWithdrawTime, GameMoney, todayWithdraw, GameMoney, gameMoney);
};


}} // namespace gideon { namespace rpc {