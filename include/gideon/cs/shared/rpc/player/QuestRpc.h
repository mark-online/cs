#pragma once

#include <gideon/cs/shared/data/QuestInfo.h>
#include <gideon/cs/shared/data/Money.h>
#include <gideon/cs/shared/data/MercenaryInfo.h>
#include <gideon/cs/shared/data/ErrorCode.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class QuestRpc
 * 퀘스트 관련 RPC
 */
class QuestRpc
{
public:
    virtual ~QuestRpc() {}

public:
    // 퀘스트 수락 요청
    DECLARE_SRPC_METHOD_2(QuestRpc, acceptQuest,
        QuestCode, questCode, GameObjectInfo, objectInfo);

    DECLARE_SRPC_METHOD_1(QuestRpc, cancelQuest,
        QuestCode, questCode);

    DECLARE_SRPC_METHOD_2(QuestRpc, completeTransportMission,
        QuestCode, questCode, QuestMissionCode, questMissionCode);

    DECLARE_SRPC_METHOD_3(QuestRpc, completeQuest,
        QuestCode, questCode, ObjectId, npcId, DataCode, selectItemCode);

    DECLARE_SRPC_METHOD_4(QuestRpc, completeTransportQuest,
        QuestCode, questCode, QuestMissionCode, questMissionCode, ObjectId, npcId, DataCode, selectItemCode);

    // 응답 없음.
    // event : evQuestMissionUpdated
    DECLARE_SRPC_METHOD_2(QuestRpc, doContentsQuest, 
        QuestContentMissionType, contentMissionType, DataCode, dataCode);

    // 파티 공유 - 같은 존에만 해당된다 -
    // response: onPushQuestToParty
    // event : evQuestToPartyPushed, evQuestToPartyPushResult
    DECLARE_SRPC_METHOD_1(QuestRpc, pushQuestToParty, 
        QuestCode, questCode);

    // 파티 공유 응답 - 같은 존에만 해당된다 -
    // response: onResponsePushQuestToParty
    // event : evQuestToPartyPushResult
    DECLARE_SRPC_METHOD_3(QuestRpc, responsePushQuestToParty, 
        QuestCode, questCode, GameObjectInfo, pusherInfo, bool, isAccept);

public:
    // 퀘스트 수락 요청 응답
    DECLARE_SRPC_METHOD_2(QuestRpc, onAcceptQuest,
        ErrorCode, errorCode, QuestCode, questCode);

    DECLARE_SRPC_METHOD_2(QuestRpc, onCancelQuest,
        ErrorCode, errorCode, QuestCode, questCode);

    DECLARE_SRPC_METHOD_3(QuestRpc, onCompleteTransportMission,
        ErrorCode, errorCode, QuestCode, questCode, QuestMissionCode, questMissionCode);

    DECLARE_SRPC_METHOD_3(QuestRpc, onCompleteQuest,
        ErrorCode, errorCode, QuestCode, questCode, DataCode, selectItemCode);

    DECLARE_SRPC_METHOD_5(QuestRpc, onCompleteTransportQuest,
        ErrorCode, errorCode, QuestCode, questCode, QuestMissionCode, questMissionCode,
        ObjectId, npcId, DataCode, selectItemCode);

    DECLARE_SRPC_METHOD_2(QuestRpc, onPushQuestToParty, 
        ErrorCode, errorCode, QuestCode, questCode);

    DECLARE_SRPC_METHOD_3(QuestRpc, onResponsePushQuestToParty, 
        ErrorCode, errorCode, QuestCode, questCode, bool, isAccept);

public:
    // 퀘스트 상태 변경
    DECLARE_SRPC_METHOD_3(QuestRpc, evQuestMissionUpdated,
        QuestCode, questCode, QuestMissionCode, missionCode,
        QuestGoalInfo, questGoalInfo);

    DECLARE_SRPC_METHOD_2(QuestRpc, evQuestToPartyPushed, 
        QuestCode, questCode, GameObjectInfo, pusherInfo);

    DECLARE_SRPC_METHOD_3(QuestRpc, evQuestToPartyPushResult, 
        QuestCode, questCode, GameObjectInfo, member, QuestToPartyResultType, resultType);
};

}} // namespace gideon { namespace rpc {