#pragma once

#include <gideon/cs/shared/data/UnionEntityInfo.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {


/**
 * @class EntityInterestAreaRpc
 * Entity 관심영역 RPC
 */
class EntityInterestAreaRpc : public boost::noncopyable
{
public:
    virtual ~EntityInterestAreaRpc() {}

public:
    /// Entity들이 내 가시영역에 나타났다
    DECLARE_SRPC_METHOD_1(EntityInterestAreaRpc, evEntitiesAppeared,
        UnionEntityInfos, entityInfos);

    /// Entity가 내 가시영역에 나타났다
    DECLARE_SRPC_METHOD_1(EntityInterestAreaRpc, evEntityAppeared,
        UnionEntityInfo, entityInfo);

    /// Entity들이 내 가시영역에서 사라졌다
    DECLARE_SRPC_METHOD_1(EntityInterestAreaRpc, evEntitiesDisappeared,
        GameObjects, entities);

    /// Entity가 내 가시영역에서 사라졌다
    DECLARE_SRPC_METHOD_1(EntityInterestAreaRpc, evEntityDisappeared,
        GameObjectInfo, entityInfo);
};


}} // namespace gideon { namespace rpc {