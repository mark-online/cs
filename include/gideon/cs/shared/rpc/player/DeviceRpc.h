#pragma once

#include <gideon/cs/shared/data/DeviceInfo.h>
#include <gideon/cs/shared/data/ObjectInfo.h>
#include <gideon/cs/shared/data/ErrorCode.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/***
 * @class DeviceRpc
 ***/
class DeviceRpc
{
public:
    virtual ~DeviceRpc() {}

public:
    /// Device의 비활성화(비작동) 되었다
    DECLARE_SRPC_METHOD_1(DeviceRpc, evDeviceDeactivated,
        ObjectId, deviceId);
};

}} // namespace gideon { namespace rpc {