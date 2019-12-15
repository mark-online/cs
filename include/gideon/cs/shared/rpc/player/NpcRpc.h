#pragma once

#include <gideon/cs/shared/data/ObjectInfo.h>
#include <gideon/cs/shared/data/NpcTalkingInfo.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class NpcDialogRpc
 * NPC 대화 관련 RPC
 */
class NpcDialogRpc
{
public:
    virtual ~NpcDialogRpc() {}

    /// NPC와의 대화 시작 요청
    /// - event: evDialogOpened
    DECLARE_SRPC_METHOD_1(NpcDialogRpc, openDialog,
        GameObjectInfo, npcInfo);

    /// NPC와의 대화 종료 요청
    /// - event: evDialogClosed
    DECLARE_SRPC_METHOD_1(NpcDialogRpc, closeDialog,
        GameObjectInfo, npcInfo);

public:
    /// NPC와 대화가 시작되었다
    DECLARE_SRPC_METHOD_2(NpcDialogRpc, evDialogOpened,
        GameObjectInfo, npc, GameObjectInfo, requester);

    /// NPC와 대화가 종료되었다
    DECLARE_SRPC_METHOD_2(NpcDialogRpc, evDialogClosed,
        GameObjectInfo, npc, GameObjectInfo, requester);
};


/**
 * @class NpcTalkingRpc
 */
class NpcTalkingRpc
{
public:
    virtual ~NpcTalkingRpc() {}

    /// NPC가 잡담을 하였다
    DECLARE_SRPC_METHOD_2(NpcTalkingRpc, evTalkedFrom,
        GameObjectInfo, talker, NpcTalkingCode, talkingCode);
};

}} // namespace gideon { namespace rpc {