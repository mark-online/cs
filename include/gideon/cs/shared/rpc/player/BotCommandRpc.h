#pragma once
#include <gideon/cs/shared/data/Coordinate.h>
#include <gideon/cs/shared/data/SkillInfo.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class BotCommandRpc
 * 봇 명령어
 */
class BotCommandRpc
{
public:
    virtual ~BotCommandRpc() {}

    DECLARE_SRPC_METHOD_2(BotCommandRpc, evBotMovePosition,
        Position, position, bool, shouldStopDestination);

    DECLARE_SRPC_METHOD_0(BotCommandRpc, evBotCastingSkill);
};


}} // namespace gideon { namespace rpc {