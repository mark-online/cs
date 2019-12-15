#pragma once

#include <gideon/cs/Common.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class EmotionRpc
 */
class EmotionRpc
{
public:
    virtual ~EmotionRpc() {}

    /// 플레이어가 관심 영역 내에서의 행동을 요청한다
    DECLARE_SRPC_METHOD_1(EmotionRpc, notifyEmotion,
        std::string, emotion);

public:
    /// 플레이어가 관심 영역 내에서의 행동을 요청했다
    DECLARE_SRPC_METHOD_2(ChaoRpc, evEmotionNotified,
        ObjectId, playerId, std::string, emotion);
};

}} // namespace gideon { namespace rpc {