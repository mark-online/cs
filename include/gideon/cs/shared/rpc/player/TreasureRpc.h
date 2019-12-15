#pragma once

#include <gideon/cs/shared/data/TreasureInfo.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class TreasureRpc
 */
class TreasureRpc
{
public:
    virtual ~TreasureRpc() {}

public:
    /**
     * 보물상자를 닫는다(맵상에서 사라짐).
     * - response: onCloseTreasure     
     * .
     */
    DECLARE_SRPC_METHOD_1(TreasureRpc, closeTreasure,
        ObjectId, treasureId);

public:
    DECLARE_SRPC_METHOD_2(TreasureRpc, onCloseTreasure,
        ErrorCode, errorCode, ObjectId, treasureId);
};

}} // namespace gideon { namespace rpc {