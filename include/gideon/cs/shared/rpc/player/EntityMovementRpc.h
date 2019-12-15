#pragma once

#include <gideon/cs/shared/data/ObjectInfo.h>
#include <gideon/cs/shared/data/Coordinate.h>
#include <gideon/cs/shared/data/RegionInfo.h>
#include <gideon/cs/shared/data/EnvironmentInfo.h>
#include <gideon/cs/shared/data/StatusInfo.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class EntityMovementRpc
 * Entity 이동 관련 RPC
 */
class EntityMovementRpc : public boost::noncopyable
{
public:
    virtual ~EntityMovementRpc() {}

public:
    /// Entity를 해당 위치로 이동 시작을 요청한다
    DECLARE_SRPC_METHOD_1(EntityMovementRpc, goToward,
        ObjectPosition, destination);

    /// Entity를 이동한다(서버와의 위치 동기화)
    DECLARE_SRPC_METHOD_1(EntityMovementRpc, move,
        ObjectPosition, position);

    /// Entity의 이동을 중지한다(서버와의 위치 동기화)
    DECLARE_SRPC_METHOD_1(EntityMovementRpc, stop,
        ObjectPosition, position);

    /// Entity의 (제 자리에서의) 방향 전환을 요청한다
    DECLARE_SRPC_METHOD_1(EntityMovementRpc, turn,
        Heading, heading);

    /// Entity의 점프를 요청한다(move와 같은 원리)
    DECLARE_SRPC_METHOD_1(EntityMovementRpc, jump,
        ObjectPosition, position);

    /// 뛴다
    DECLARE_SRPC_METHOD_0(EntityMovementRpc, run);


    DECLARE_SRPC_METHOD_0(EntityMovementRpc, walk);

    /// 이동 불가 상황일때 강제로 보정할때 쓰임
    DECLARE_SRPC_METHOD_1(EntityMovementRpc, correctionPosition,
        ObjectPosition, position);

    /// 플레이어가 지역 내에 입장했다
    DECLARE_SRPC_METHOD_1(EntityMovementRpc, regionEntered,
        RegionCode, regionCode);

    /// 플레이어가 지역에서 퇴장하였다
    DECLARE_SRPC_METHOD_1(EntityMovementRpc, regionLeft,
        RegionCode, regionCode);

    /// 응답 없음(낙하 시작)
    DECLARE_SRPC_METHOD_0(EntityMovementRpc, fallen);
    /// 응답 없음(낙하 종료)
    DECLARE_SRPC_METHOD_0(EntityMovementRpc, landing);

    DECLARE_SRPC_METHOD_1(EntityMovementRpc, environmentEntered,
        EnvironmentType, type);

    DECLARE_SRPC_METHOD_0(EntityMovementRpc, environmentLeft);

public:
    DECLARE_SRPC_METHOD_1(EntityMovementRpc, onLanding,
        HitPoint, damage);

public:
    /// Entity가 내 가시영역 내에서 이동을 시작했다
    DECLARE_SRPC_METHOD_2(EntityMovementRpc, evEntityGoneToward,
        GameObjectInfo, entityInfo, ObjectPosition, position);

    /// Entity가 내 가시영역 내에서 이동했다
    DECLARE_SRPC_METHOD_2(EntityMovementRpc, evEntityMoved,
        GameObjectInfo, entityInfo, ObjectPosition, position);

    /// Entity가 내 가시영역 내에서 이동 중지했다
    DECLARE_SRPC_METHOD_2(EntityMovementRpc, evEntityStopped,
        GameObjectInfo, entityInfo, ObjectPosition, position);

    /// Entity가 내 가시영역 내에서 순간 이동했다
    DECLARE_SRPC_METHOD_2(EntityMovementRpc, evEntityTeleported,
        GameObjectInfo, entityInfo, ObjectPosition, position);

    /// Entity가 방향 전환을 했다
    DECLARE_SRPC_METHOD_2(EntityMovementRpc, evEntityTurned,
        GameObjectInfo, entityInfo, Heading, heading);

    /// Entity가 점프를 했다
    DECLARE_SRPC_METHOD_2(EntityMovementRpc, evEntityJumped,
        GameObjectInfo, entityInfo, ObjectPosition, position);

    /// Entity가 뛴다
    DECLARE_SRPC_METHOD_1(EntityMovementRpc, evRun,
        GameObjectInfo, entityInfo);

    /// Entity가 걷는다
    DECLARE_SRPC_METHOD_1(EntityMovementRpc, evWalked,
        GameObjectInfo, entityInfo);


};

}} // namespace gideon { namespace rpc {