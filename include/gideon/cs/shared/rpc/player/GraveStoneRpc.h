#pragma once

#include <gideon/cs/shared/data/GraveStoneInfo.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class GraveStoneRpc
 * 비석 관련 RPC
 */
class GraveStoneRpc : public boost::noncopyable
{
public:
    virtual ~GraveStoneRpc() {}	

    // 자기 자신의 무덤이 사라진걸 알려준다.
    DECLARE_SRPC_METHOD_0(GraveStoneRpc, evSelfGraveStoneRemoved);    
};

}} // namespace gideon { namespace rpc {