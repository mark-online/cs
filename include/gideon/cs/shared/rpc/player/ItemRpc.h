#pragma once

#include <gideon/cs/shared/data/ItemInfo.h>
#include <gideon/cs/shared/data/QuestInfo.h>
#include <gideon/cs/shared/data/SkillInfo.h>
#include <gideon/cs/shared/data/ErrorCode.h>
#include <gideon/cs/shared/data/ElementInfo.h>
#include <gideon/cs/shared/data/VehicleInfo.h>
#include <gideon/cs/shared/data/GliderInfo.h>
#include <gideon/cs/shared/data/LootInvenItemInfo.h>
#include <sne/srpc/RpcInterface.h>
#include "../../data/Money.h"

namespace gideon { namespace rpc {

/**
 * @class ItemRpc
 * Item 관련 RPC
 */
class ItemRpc
{
public:
    virtual ~ItemRpc() {}

    /***
     * 언인체트
     * event: 
     ***/
    DECLARE_SRPC_METHOD_3(ItemRpc, unenchantEquip,
        GameObjectInfo, checkObjectInfo, ObjectId, equipItemId, SocketSlotId, openSlotIndex);
    /***

	/***
     * 탈것 아이템 사용
     * - response: onUseVehicleItem
     * event: evInventoryItemRemoved 
     ***/
	DECLARE_SRPC_METHOD_1(ItemRpc, useVehicleItem,
		ObjectId, itemId);

	/***
     * 글라이더 아이템 사용
     * - response: onReprocessItem
     * event: evInventoryItemRemoved 
     ***/
	DECLARE_SRPC_METHOD_1(ItemRpc, useGliderItem,
		ObjectId, itemId);

	/***
     * 탈것 아이템 선택
     * - response: onSelectVehicleItem
     * 
     ***/
	DECLARE_SRPC_METHOD_1(ItemRpc, selectVehicleItem,
		ObjectId, itemId);

	/***
     * 탈것 아이템 선택
     * - response: onSelectGliderItem      
     ***/
	DECLARE_SRPC_METHOD_1(ItemRpc, selectGliderItem,
		ObjectId, itemId);

	/***
     * 글라이더 아이템 내구도 강화
     * - response: onRepairGliderItem      
     ***/
	DECLARE_SRPC_METHOD_1(ItemRpc, repairGliderItem,
		ObjectId, itemId);


	DECLARE_SRPC_METHOD_1(ItemRpc, queryLootItemInfoMap,
		GameObjectInfo, targetInfo);

public:

    DECLARE_SRPC_METHOD_4(ItemRpc, onUnenchantEquip,
        ErrorCode, errorCode, ObjectId, equipItemId, uint8_t, openSlotIndex, GameMoney, currentGameMoney);

	DECLARE_SRPC_METHOD_2(ItemRpc, onUseVehicleItem,
		ErrorCode, errorCode, VehicleInfo, info);
	
	DECLARE_SRPC_METHOD_2(ItemRpc, onUseGliderItem,
		ErrorCode, errorCode, GliderInfo, info);

	DECLARE_SRPC_METHOD_2(ItemRpc, onSelectVehicleItem,
		ErrorCode, errorCode, ObjectId, itemId);

	DECLARE_SRPC_METHOD_2(ItemRpc, onSelectGliderItem,
		ErrorCode, errorCode, ObjectId, itemId);

	DECLARE_SRPC_METHOD_3(ItemRpc, onRepairGliderItem,
		ErrorCode, errorCode, ObjectId, itemId, GameMoney, currentGameMoney);

	DECLARE_SRPC_METHOD_3(ItemRpc, onLootItemInfoMap,
		ErrorCode, errorCode, GameObjectInfo, targetInfo, LootInvenItemInfoMap, infoMap);
};


}} // namespace gideon { namespace rpc {