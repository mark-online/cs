#pragma once
#include <gideon/cs/shared/data/WorldInfo.h>
#include <gideon/cs/shared/data/RegionInfo.h>
#include <gideon/cs/shared/data/Coordinate.h>
#include <gideon/cs/shared/data/BindRecallInfo.h>
#include <gideon/cs/shared/data/Certificate.h>
#include <gideon/cs/shared/data/UserId.h>
#include <gideon/cs/shared/data/Money.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {
/**
 * @class TeleportRpc
 * 텔레포트 관련 RPC
 */
class TeleportRpc
{
public:
    virtual ~TeleportRpc() {}

public:
    // 특정 지역에 텔레포트 요청
    DECLARE_SRPC_METHOD_2(TeleportRpc, teleportToRegion,
        MapCode, worldMapCode, RegionCode, spawnRegionCode);

    // 특정 위치에 텔레포트 요청
    DECLARE_SRPC_METHOD_2(TeleportRpc, teleportToPosition,
        MapCode, worldMapCode, Position, position);

    // 귀환위치 저장
    DECLARE_SRPC_METHOD_1(TeleportRpc, addBindRecall,
        ObjectId, bindlingId);

    // 귀환위치 삭제
    DECLARE_SRPC_METHOD_1(TeleportRpc, removeBindRecall,
        ObjectId, bindlingId);

	// 닉네임 설정
	DECLARE_SRPC_METHOD_1(TeleportRpc, setRecallToPlayer,
		Nickname, nickname);

	DECLARE_SRPC_METHOD_1(TeleportRpc, responseRecall,
		bool, isAnswer);

public:
    // 텔레포트 요청에 대한 응답
    DECLARE_SRPC_METHOD_5(TeleportRpc, onTeleportTo,
        ErrorCode, errorCode, MapCode, worldMapCode, ObjectPosition, spawnPosition,
        MigrationTicket, migrationTicket, GameMoney, currentGameMoney);


    // 귀환위치 저장
    DECLARE_SRPC_METHOD_2(TeleportRpc, onAddBindRecall,
        ErrorCode, errorCode, BindRecallInfo, bindRecallInfo);

    // 귀환위치 삭제
    DECLARE_SRPC_METHOD_2(TeleportRpc, onRemoveBindRecall,
        ErrorCode, errorCode, ObjectId, linkId);

	DECLARE_SRPC_METHOD_1(TeleportRpc, onSetRecallToPlayer,
		ErrorCode, errorCode);

	DECLARE_SRPC_METHOD_2(TeleportRpc, onResponseRecall,
		ErrorCode, errorCode, MigrationTicket, migrationTicket);


public:
	// 자신만 받는다.(케스팅 완료시)
    DECLARE_SRPC_METHOD_2(TeleportRpc, evBindRecallTicket,
		ErrorCode, errorCode, MigrationTicket, migrationTicket);

	// 리콜 준비가 됐다 (닉네임 입력 UI나옴)
    DECLARE_SRPC_METHOD_1(TeleportRpc, evRecallRequested,
		Nickname, callerNickname);
};

}} // namespace gideon { namespace rpc {