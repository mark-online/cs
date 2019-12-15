#pragma once

#include <gideon/cs/shared/data/ChaoInfo.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class ChaoRpc
 */
class ChaoRpc
{
public:
    virtual ~ChaoRpc() {}

    DECLARE_SRPC_METHOD_2(ChaoRpc, evChaoChanged,
        ObjectId, playerId, bool, isChao);

    DECLARE_SRPC_METHOD_2(ChaoRpc, evTempChaoChanged,
        ObjectId, playerId, bool, isChao);


    DECLARE_SRPC_METHOD_1(ChaoRpc, evChaoticUpdated,
        Chaotic, chaotic);
};

}} // namespace gideon { namespace rpc {