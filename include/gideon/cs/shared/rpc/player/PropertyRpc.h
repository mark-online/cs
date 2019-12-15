#pragma once

#include <gideon/cs/Common.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {


/**
 * @class ProperyRpc
 * 플레이어 속성 관련 RPC
 */
class ProperyRpc
{
public:
    virtual ~ProperyRpc() {}

public:
    /**
     * Config/Prefs를 요청한다
     * - response: onLoadProperties
     */
    DECLARE_SRPC_METHOD_0(ProperyRpc, loadProperties);

    /**
     * Config/Prefs를 저장한다
     * - response: None
     */
    DECLARE_SRPC_METHOD_2(ProperyRpc, saveProperties,
        std::string, config, std::string, prefs);

public:
    DECLARE_SRPC_METHOD_2(ProperyRpc, onLoadProperties,
        std::string, config, std::string, prefs);
};


}} // namespace gideon { namespace rpc {