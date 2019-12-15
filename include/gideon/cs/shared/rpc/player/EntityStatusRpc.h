#pragma once
#include <gideon/cs/shared/data/GraveStoneInfo.h>
#include <gideon/cs/shared/data/Coordinate.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {


/**
 * @class EntityStatusRpc
 * Entity 상태 관련 RPC
 */
class EntityStatusRpc : public boost::noncopyable
{
public:
    virtual ~EntityStatusRpc() {}

    // 플레이어가 자살을 한다.
    DECLARE_SRPC_METHOD_0(EntityStatusRpc, commitSuicide);

    DECLARE_SRPC_METHOD_0(EntityStatusRpc, releaseBeginnerProtection);

public:
    /// 플레이어가 사망하였다
    DECLARE_SRPC_METHOD_3(EntityStatusRpc, evPlayerDied,
        GameObjectInfo, creatureInfo, GameObjectInfo, killerInfo, ObjectPosition, playerInfo);

    /// NPC가 사망하였다
    DECLARE_SRPC_METHOD_3(EntityStatusRpc, evNpcDied,
        GameObjectInfo, creatureInfo, GameObjectInfo, killerInfo, GraveStoneInfo, graveStoneInfo);

public:
    /// Entity가 위협을 감지하였다
    DECLARE_SRPC_METHOD_1(EntityStatusRpc, evThreated,
        GameObjectInfo, entityInfo);

    /// Entity가 (공격) 대상을 선택하였다
    DECLARE_SRPC_METHOD_3(EntityStatusRpc, evTargetSelected,
        GameObjectInfo, entityInfo, GameObjectInfo, targetInfo, bool, isAggressive);

    /// 현재 선택 중인 대상(Entity)의 대상이 변경되었다
    DECLARE_SRPC_METHOD_2(EntityStatusRpc, evTargetChanged,
        GameObjectInfo, entityInfo, EntityStatusInfo, targetStatusInfo);

public:
    /// 초보자 보호 해재
    DECLARE_SRPC_METHOD_1(EntityStatusRpc, evBeginnerProtectionReleased,
        ObjectId, playerId);

    /// 초보자 보호 해재
    DECLARE_SRPC_METHOD_2(EntityStatusRpc, evCombatStateChanged,
        ObjectId, playerId, bool, isCombatState);
};


}} // namespace gideon { namespace rpc {