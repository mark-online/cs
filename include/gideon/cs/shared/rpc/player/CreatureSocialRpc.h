#pragma once
#include <gideon/cs/shared/data/Chatting.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class CreatureSocialRpc
 * Creature Social interaction 관련 RPC
 */
class CreatureSocialRpc : public boost::noncopyable
{
public:
    virtual ~CreatureSocialRpc() {}

public:
    /// Creature가 관심 영역 내에서의 채팅을 요청한다
    DECLARE_SRPC_METHOD_1(CreatureSocialRpc, say,
        ChatMessage, message);

public:
    /// Creature가 관심 영역 내에서의 채팅을 하였다
    DECLARE_SRPC_METHOD_2(CreatureSocialRpc, evCreatureSaid,
        Nickname, nickname, ChatMessage, message);
};



}} // namespace gideon { namespace rpc {