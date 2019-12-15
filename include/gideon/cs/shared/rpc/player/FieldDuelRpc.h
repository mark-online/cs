#pragma once

#include <gideon/cs/shared/data/Coordinate.h>
#include <gideon/cs/shared/data/UserId.h>
#include <gideon/cs/shared/data/DuelInfo.h>
#include <gideon/cs/shared/data/ErrorCode.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class FieldDuelRpc
 * 1:1 필드에서
 */
class FieldDuelRpc : public boost::noncopyable
{
public:
    virtual ~FieldDuelRpc() {}	
    // 1:1 대결 신청을 한다.
    DECLARE_SRPC_METHOD_1(FieldDuelRpc, requestFieldDuel,
        ObjectId, playerId);

    // 1:1 대결 신청 응답을 한다
    // event: evFieldDuelReponded,(신청한사람만)
    // event: evFieldDuelReadied(양쪽 다받는다)
    DECLARE_SRPC_METHOD_2(FieldDuelRpc, responseFieldDuel,
        ObjectId, playerId, bool, isAnswer);

    // 1:1 취소
    DECLARE_SRPC_METHOD_0(FieldDuelRpc, cancelFieldDuel);

public:
    // 1:1 대결 신청을 한다.
    DECLARE_SRPC_METHOD_1(FieldDuelRpc, onRequestFieldDuel,
        ErrorCode, errorCode);

    // 1:1 대결 신청 응답을 한다
    DECLARE_SRPC_METHOD_2(FieldDuelRpc, onResponseFieldDuel,
        ErrorCode, errorCode, bool, isAnswer);

public:

    DECLARE_SRPC_METHOD_2(FieldDuelRpc, evFieldDuelRequested,
        ObjectId, playerId, Nickname, nickname);

    DECLARE_SRPC_METHOD_2(FieldDuelRpc, evFieldDuelReponded,
        ObjectId, playerId, bool, isAnswer);

    // evFieldDuelReadied 이후 evFieldDuelStarted(양쪽 받음)
    DECLARE_SRPC_METHOD_1(FieldDuelRpc, evFieldDuelReadied,
        Position, centerPosition);

    DECLARE_SRPC_METHOD_0(FieldDuelRpc, evFieldDuelStarted);

    /// 대결자 둘만 받아 처리 한다
    DECLARE_SRPC_METHOD_1(FieldDuelRpc, evFieldDuelStopped,
        FieldDuelResultType, type);

    /// 브로드 케스팅용(텍스트용)
    DECLARE_SRPC_METHOD_4(FieldDuelRpc, evFieldDuelResult,
        ObjectId, winnerId, Nickname, winerNickname, ObjectId, loserId, Nickname, loseNickname);

};

}} // namespace gideon { namespace rpc {