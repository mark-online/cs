#pragma once
#include <gideon/cs/shared/data/Coordinate.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class CreatureReviveRpc
 * Creature revive 관련 RPC
 */
class CreatureReviveRpc : public boost::noncopyable
{
public:
    virtual ~CreatureReviveRpc() {}

public:
    /**
     * 캐릭터 소생을 요청한다
     * - response: onRevive
     */
    DECLARE_SRPC_METHOD_0(CreatureReviveRpc, revive);

public:
    /// 소생 요청이 실패하였다
    DECLARE_SRPC_METHOD_2(CreatureReviveRpc, onRevive,
        ErrorCode, errorCode, ObjectPosition, position);

public:
	/// 소생 이벤트 (자신은 안받는다.)
    DECLARE_SRPC_METHOD_2(CreatureReviveRpc, evPlayerRevived,
        ObjectId, reviverId, ObjectPosition, position);
};


}} // namespace gideon { namespace rpc {