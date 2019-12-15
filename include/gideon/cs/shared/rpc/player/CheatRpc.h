#pragma once

#include <gideon/cs/shared/data/Chatting.h>
#include <gideon/cs/shared/data/CheatInfo.h>
#include <gideon/cs/shared/data/ErrorCode.h>
#include <gideon/cs/shared/data/QuestInfo.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class CheatRpc
 * 치트 관련 RPC
 */
class CheatRpc
{
public:
    virtual ~CheatRpc() {}

public:
    DECLARE_SRPC_METHOD_1(CheatRpc, cheat,
        ChatMessage, cheatMessage);

public:
	DECLARE_SRPC_METHOD_2(CheatRpc, onCheat,
		ErrorCode, errorCode, ChatMessage, cheatMessage);

public:
    DECLARE_SRPC_METHOD_1(CheatRpc, evZoneInUsers,
        ZoneUserInfos, infos);

    DECLARE_SRPC_METHOD_1(CheatRpc, evWorldInUsers,
        WorldUserInfos, infos);

    DECLARE_SRPC_METHOD_2(CheatRpc, evCheatValueTypeUpdated,
        CheatValueType, cheatType, uint64_t, currentValue);
    DECLARE_SRPC_METHOD_1(CheatRpc, evCheatCompleteQuestRemoved,
        QuestCode, questCode);
};

}} // namespace gideon { namespace rpc {