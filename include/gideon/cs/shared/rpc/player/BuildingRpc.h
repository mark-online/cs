#pragma once
#include <gideon/cs/shared/data/BuildingInfo.h>
#include <gideon/cs/shared/data/SkillInfo.h>
#include <gideon/cs/shared/data/Certificate.h>
#include <gideon/cs/shared/data/RecipeInfo.h>
#include <gideon/cs/shared/data/MercenaryInfo.h>
#include <sne/srpc/RpcInterface.h>
#include "../../data/ErrorCode.h"

namespace gideon { namespace rpc {

/**
 * @class BuildingRpc
 * 설치물 관련 RPC
 */
class BuildingRpc
{
public:
    virtual ~BuildingRpc() {}

    DECLARE_SRPC_METHOD_2(BuildingRpc, createBuilding,
        ObjectId, itemId, ObjectPosition, position);

    DECLARE_SRPC_METHOD_1(BuildingRpc, buildBuilding,
        ObjectId, buildingId);

    DECLARE_SRPC_METHOD_3(BuildingRpc, fireToTarget,
        GameObjectInfo, anchorInfo, SkillCode, skillCode, GameObjectInfo, targetInfo);

    DECLARE_SRPC_METHOD_3(BuildingRpc, fireToPosition,
        GameObjectInfo, anchorInfo, SkillCode, skillCode, Position, position);

    DECLARE_SRPC_METHOD_0(BuildingRpc, queryWorldMarkBuildings);

    
    DECLARE_SRPC_METHOD_1(BuildingRpc, queryBuildingInfo,
        ObjectId, buildingId);

    DECLARE_SRPC_METHOD_1(BuildingRpc, queryBuildingExpireTime,
        GameObjectInfo, objectInfo);

    DECLARE_SRPC_METHOD_1(BuildingRpc, queryBuildingInvincibleExpireTime,
        GameObjectInfo, objectInfo);
    
    /// 관리자만이 사용할수 있다.
    DECLARE_SRPC_METHOD_1(BuildingRpc, destoryBuildingCommand,
        GameObjectInfo, objectInfo);

	DECLARE_SRPC_METHOD_3(BuildingRpc, teleportToBuliding,
		MapCode, worldMap, ObjectId, fromBuildingId, ObjectId, toBuildingId);

    DECLARE_SRPC_METHOD_3(BuildingRpc, startSelectRecipeProduction,
        ObjectId, buildingId, RecipeCode, recipeCode, uint8_t, count);

    DECLARE_SRPC_METHOD_1(BuildingRpc, toggleBuildingDoor,
        ObjectId, buildingId);

    DECLARE_SRPC_METHOD_3(BuildingRpc, buyBuildingGuard,
        ObjectId, buildingId, BuildingGuardCode, buildingGuardCode, uint8_t, rentDay);

    DECLARE_SRPC_METHOD_3(BuildingRpc, spawnBuildingGuard,
        ObjectId, mercenaryId, ObjectId, buildingId, ObjectPosition, position);


    //DECLARE_SRPC_METHOD_1(BuildingRpc, queryInsideBuildingInfo,
    //    GameObjectInfo, anchorInfo);

    //DECLARE_SRPC_METHOD_3(BuildingRpc, excuteBuildingEffectByPosition,
    //    GameObjectInfo, anchorInfo, uint8_t, index, Position, position);

    //DECLARE_SRPC_METHOD_3(BuildingRpc, excuteBuildingEffectByTarget,
    //    GameObjectInfo, anchorInfo, uint8_t, index, GameObjectInfo, targetInfo);

public:
    DECLARE_SRPC_METHOD_1(BuildingRpc, onCreateBuilding,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_1(BuildingRpc, onBuildBuilding,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_4(BuildingRpc, onFireToTarget,
        ErrorCode, errorCode, GameObjectInfo, anchorInfo, SkillCode, skillCode, GameObjectInfo, targetInfo);

    DECLARE_SRPC_METHOD_4(BuildingRpc, onFireToPosition,
        ErrorCode, errorCode, GameObjectInfo, anchorInfo, SkillCode, skillCode, Position, position);

    DECLARE_SRPC_METHOD_1(BuildingRpc,  onWorldMarkBuildings,
        BuildingMarkInfos, buildingMarkInfos);

    DECLARE_SRPC_METHOD_5(BuildingRpc, onBuildingInfo,
        sec_t, expireIncibleCooltime, BuildingOwnerInfo, ownerInfo,
		BuildingItemTaskInfos, consumeTaskInfos, BuildingItemTaskInfos, resouceTaskInfos,
        BuildingItemTaskInfos, selectProductionTaskInfos);

    DECLARE_SRPC_METHOD_3(BuildingRpc, onBuildingExpireTime,
        ErrorCode, errorCode, GameObjectInfo, objectInfo, sec_t, expireTime);

    DECLARE_SRPC_METHOD_3(BuildingRpc, onBuildingInvincibleExpireTime,
        ErrorCode, errorCode, GameObjectInfo, objectInfo, sec_t, expireTime);

	DECLARE_SRPC_METHOD_1(BuildingRpc, onTeleportToBuliding,
		ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_1(BuildingRpc, onStartSelectRecipeProduction,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_1(BuildingRpc, onToggleBuildingDoor,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_2(BuildingRpc, onBuyBuildingGuard,
        ErrorCode, errorCode, GameMoney, currentGameMoney);

    DECLARE_SRPC_METHOD_1(BuildingRpc, onSpawnBuildingGuard,
        ErrorCode, errorCode);
//
//    DECLARE_SRPC_METHOD_3(BuildingRpc,onQueryInsideBuildingInfo,
//        ErrorCode, errorCode, GameObjectInfo, anchorInfo, ItemMap, itemMap);
//
//    DECLARE_SRPC_METHOD_4(BuildingRpc, onExcuteBuildingEffectByPosition,
//        ErrorCode, errorCode, GameObjectInfo, anchorInfo, uint8_t, index, Position, position);
//
//    DECLARE_SRPC_METHOD_4(BuildingRpc, onExcuteBuildingEffectByTarget,
//        ErrorCode, errorCode, GameObjectInfo, anchorInfo, uint8_t, index, GameObjectInfo, targetInfo);
//
public:
    DECLARE_SRPC_METHOD_2(BuildingRpc, evBuildingStartBuilt,
        GameObjectInfo, buildingInfo, sec_t, startBuildTime);

    DECLARE_SRPC_METHOD_1(BuildingRpc, evBuildingCompleted,
        GameObjectInfo, buildingInfo);

    DECLARE_SRPC_METHOD_1(BuildingRpc, evBuildingToFundationReverted,
        GameObjectInfo, buildingInfo);

    DECLARE_SRPC_METHOD_1(BuildingRpc, evBuildingBroken,
        GameObjectInfo, buildingInfo);

    DECLARE_SRPC_METHOD_1(BuildingRpc, evBuildingDestoryed,
        GameObjectInfo, buildingInfo);

    DECLARE_SRPC_METHOD_2(BuildingRpc, evBuildingInvincibleStateChanged,
        GameObjectInfo, buildingInfo, bool, isActivate);

    DECLARE_SRPC_METHOD_2(BuildingRpc, evBuildingActivateStateChanged,
        GameObjectInfo, buildingInfo, bool, isActivate);

    DECLARE_SRPC_METHOD_1(BuildingRpc, evBuildingTeleportToOrderZoneSuccessed,
        MigrationTicket, ticket);

    DECLARE_SRPC_METHOD_2(BuildingRpc, evBuildingDoorToggled,
        GameObjectInfo, buildingInfo, bool, isOpen);

    DECLARE_SRPC_METHOD_2(BuildingRpc, evSelectProductionTaskAdded,
        GameObjectInfo, buildingInfo, BuildingItemTaskInfo, resouceTaskInfo);

    DECLARE_SRPC_METHOD_2(BuildingRpc, evSelectProductionTaskUpdated,
        GameObjectInfo, buildingInfo, BuildingItemTaskInfo, resouceTaskInfo);

    DECLARE_SRPC_METHOD_2(BuildingRpc, evSelectProductionTaskRemoved,
        GameObjectInfo, buildingInfo, RecipeCode, recipeCode);



//    DECLARE_SRPC_METHOD_1(BuildingRpc, evBuildingReconnaissanced,
//        Positions, positions);
//
//    DECLARE_SRPC_METHOD_3(BuildingRpc, evBuildingPositionFired,
//        GameObjectInfo, anchorInfo, uint8_t, index, Position, position);
//    
//    DECLARE_SRPC_METHOD_3(BuildingRpc, evBuildingTargetFired,
//        GameObjectInfo, anchorInfo, uint8_t, index, GameObjectInfo, targetInfo);
};


}} // namespace gideon { namespace rpc {