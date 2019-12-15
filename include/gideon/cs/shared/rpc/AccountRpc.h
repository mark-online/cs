#pragma once

#include <gideon/cs/shared/data/ErrorCode.h>
#include <gideon/cs/shared/data/UserInfo.h>
#include <gideon/cs/shared/data/UnionEntityInfo.h>
#include <gideon/cs/shared/data/UserId.h>
#include <gideon/cs/shared/data/ExpelReason.h>
#include <gideon/cs/shared/data/Time.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class AccountRpc
 * 계정 관련 RPC
 */
class AccountRpc : public boost::noncopyable
{
public:
    virtual ~AccountRpc() {}

public:
    /// 월드 입장 전에 캐릭터를 선택한다
    DECLARE_SRPC_METHOD_1(AccountRpc, selectCharacter,
        ObjectId, characterId);

    /// 월드에 입장한다
    DECLARE_SRPC_METHOD_0(AccountRpc, enterWorld);

public:
    /// 캐릭터 선택 요청에 대한 응답
    DECLARE_SRPC_METHOD_2(AccountRpc, onSelectCharacter,
        ErrorCode, errorCode, FullCharacterInfo, characterInfo);

    /// 월드 입장 요청에 대한 응답
    DECLARE_SRPC_METHOD_4(AccountRpc, onEnterWorld,
        ErrorCode, errorCode, ObjectPosition, spawnPosition, MapCode, mapCode,
        WorldTime, worldTime);

public:
    /// 서버로 부터 강제 퇴장 당했다
    DECLARE_SRPC_METHOD_1(AccountRpc, evExpelled,
        ExpelReason, reason);
};

}} // namespace gideon { namespace rpc {
