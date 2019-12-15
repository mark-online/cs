#pragma once

#include <gideon/cs/shared/data/EntityStatusInfo.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {


/**
 * @class EntityQueryRpc
 * Entity 질의 관련 RPC
 */
class EntityQueryRpc : public boost::noncopyable
{
public:
    virtual ~EntityQueryRpc() {}

public:
    /**
     * Entity를 대상으로 선택한다
     * - response: onSelectTarget
     */
    DECLARE_SRPC_METHOD_1(EntityQueryRpc, selectTarget,
        GameObjectInfo, entityInfo);

public:
    /// Entity 대상 선택 요청에 대한 응답
    DECLARE_SRPC_METHOD_3(EntityQueryRpc, onSelectTarget,
        ErrorCode, errorCode, EntityStatusInfo, targetInfo, EntityStatusInfo, targetOfTargetInfo);
};

}} // namespace gideon { namespace rpc {