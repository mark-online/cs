#pragma once

#include <gideon/cs/shared/data/ObjectInfo.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class EntityActionRpc
 * NPC Action(애니메이션) 관련 RPC
 */
class EntityActionRpc
{
public:
    virtual ~EntityActionRpc() {}

public:
    /// NPC action을 표현한다
    DECLARE_SRPC_METHOD_2(EntityActionRpc, evActionPlayed,
        GameObjectInfo, entityInfo, uint32_t, actionCode);
};

}} // namespace gideon { namespace rpc {