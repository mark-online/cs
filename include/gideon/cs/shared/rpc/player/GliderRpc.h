#pragma once

#include <gideon/cs/shared/data/ObjectInfo.h>
#include <gideon/cs/shared/data/ErrorCode.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class GliderRpc
 * 글라이더 관련 RPC
 */
class GliderRpc : public boost::noncopyable
{
public:
    virtual ~GliderRpc() {}

public:
    /**
     * 글라이더에서 내린다
     * - response: onDismountGlider(실패시에만)
     * - event: evGliderDismounted(성공시에 모두 받음)
     */
    DECLARE_SRPC_METHOD_0(GliderRpc, dismountGlider);

public:

    DECLARE_SRPC_METHOD_2(GliderRpc, onDismountGlider,
        ErrorCode, errorCode, uint32_t, currentDurability);

public:

    /// 관심 영역 내에서 누군가가 글라이더에서 내렸다
    DECLARE_SRPC_METHOD_2(GliderRpc, evGliderDismounted,
        GameObjectInfo, creatureInfo, float, speed);

};



}} // namespace gideon { namespace rpc {