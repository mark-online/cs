#pragma once

#include <gideon/cs/shared/data/AchievementInfo.h>
#include <gideon/cs/shared/data/CharacterTitleInfo.h>
#include <gideon/cs/shared/data/ErrorCode.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class AchievementRpc
 * 업적 관련 RPC
 */
class AchievementRpc
{
public:
    virtual ~AchievementRpc() {}

public:
    // = 초기화시에 정보를 요청한
    // response: onQueryAchievements
    DECLARE_SRPC_METHOD_0(AchievementRpc, queryAchievements);

public:
    DECLARE_SRPC_METHOD_3(AchievementRpc, onQueryAchievements,
        ErrorCode, errorCode, ProcessAchievementInfoMap, processMap,
        CompleteAchievementInfoMap, completeMap);

public:
    DECLARE_SRPC_METHOD_2(AchievementRpc, evAchievementUpdated,
        AchievementCode, code, ProcessAchievementInfo, missionInfo);

    DECLARE_SRPC_METHOD_3(AchievementRpc, evAchievementCompleted,
        AchievementCode, code, AchievementPoint, point, sec_t, now);
};

}} // namespace gideon { namespace rpc {