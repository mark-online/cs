#pragma once

#include <gideon/cs/shared/data/ObjectInfo.h>
#include <gideon/cs/shared/data/ErrorCode.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class VehicleRpc
 * 탈 것 관련 RPC
 */
class VehicleRpc : public boost::noncopyable
{
public:
    virtual ~VehicleRpc() {}

public:
    /**
     * 탈 것에서 내린다
     * - response: onDismountVehicle(실패시에만)
     * - event: evVehicleDismounted(성공시에 모든 요저 받음)
     */
    DECLARE_SRPC_METHOD_1(VehicleRpc, dismountVehicle,
        bool, isForce);

public:
    DECLARE_SRPC_METHOD_1(VehicleRpc, onDismountVehicle,
        ErrorCode, errorCode);

    /// 관심 영역 내에서 누군가가 탈 것에서 내렸다
    DECLARE_SRPC_METHOD_3(VehicleRpc, evVehicleDismounted,
        GameObjectInfo, creatureInfo, float, speed, bool, isForce);
};


}} // namespace gideon { namespace rpc {