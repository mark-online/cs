#pragma once

#include <gideon/cs/shared/data/Coordinate.h>
#include <gideon/cs/shared/data/ErrorCode.h>
#include <gideon/cs/shared/data/PartyInfo.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class DungeonRpc
 * 던전 관련 RPC
 */
class DungeonRpc : public boost::noncopyable
{
public:
    virtual ~DungeonRpc() {}

public:
    /**
     * 현재 월드맵(존)의 던전에 입장을 요청한다
     * - response: onEnterDungeon
     */
    DECLARE_SRPC_METHOD_1(DungeonRpc, enterDungeon,
        ObjectId, dungeonId);

    /**
     * 입장 중인 던전에서 퇴장을 요청한다
     * - response: onLeaveDungeon
     */
    DECLARE_SRPC_METHOD_0(DungeonRpc, leaveDungeon);

public:
    /// 던전 입장 요청에 대한 응답
    /// @param mapData 랜덤 던전인 경우 맵 정보의 DE format
    DECLARE_SRPC_METHOD_4(DungeonRpc, onEnterDungeon,
        ErrorCode, errorCode, WorldPosition, spawnPosition, std::string, mapData, PartyId, partyId);

    /// 던전 퇴장 요청에 대한 응답
    /// @param spawnPosition 월드맵 스폰 좌표
    /// - 클라이언트는 맵 로딩 후 readyToPlay()를 호출해야 기존 월드맵에 입장한다
    DECLARE_SRPC_METHOD_2(DungeonRpc, onLeaveDungeon,
        ErrorCode, errorCode, WorldPosition, spawnPosition);
};


}} // namespace gideon { namespace rpc {