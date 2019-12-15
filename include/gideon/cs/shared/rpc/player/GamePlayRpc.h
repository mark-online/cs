#pragma once

#include <gideon/cs/shared/data/Time.h>
#include <gideon/cs/shared/data/ErrorCode.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class GamePlayRpc
 * 게임 플레이 관련 RPC
 */
class GamePlayRpc : public boost::noncopyable
{
public:
    virtual ~GamePlayRpc() {}

public:
    /**
     * 플레이 준비가 완료됬음을 알린다
     * - response: onReadyToPlay
     */
    DECLARE_SRPC_METHOD_0(GamePlayRpc, readyToPlay);

    DECLARE_SRPC_METHOD_0(GamePlayRpc, queryServerTime);

public:
    DECLARE_SRPC_METHOD_1(GamePlayRpc, onReadyToPlay,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_1(GamePlayRpc, onQueryServerTime,
        sec_t, serverTime);
};

}} // namespace gideon { namespace rpc {
