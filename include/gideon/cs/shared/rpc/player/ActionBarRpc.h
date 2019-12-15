#pragma once
#include <gideon/cs/shared/data/ActionBar.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class ActionBarRpc
 * 액션바 관련 RPC
 */
class ActionBarRpc
{
public:
    virtual ~ActionBarRpc() {}

    /**
     * 액션바에 코드를 저장한다.
     * - response: onSaveActionBar
     */
    DECLARE_SRPC_METHOD_3(ActionBarRpc, saveActionBar,
        ActionBarIndex, abiIndex, ActionBarPosition, abpIndex, DataCode, code);

    DECLARE_SRPC_METHOD_1(ActionBarRpc, lockActionBar,
        bool, isLocked);

public:
    DECLARE_SRPC_METHOD_4(ActionBarRpc, onSaveActionBar,
        ErrorCode, errorCode, ActionBarIndex, abiIndex,
        ActionBarPosition, abpIndex, DataCode, code);
};


}} // namespace gideon { namespace rpc {