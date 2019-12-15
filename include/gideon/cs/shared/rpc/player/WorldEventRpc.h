#pragma once
#include <gideon/cs/shared/data/WorldEventInfo.h>
#include <gideon/cs/shared/data/PartyInfo.h>
#include <gideon/cs/shared/data/ItemInfo.h>
#include <gideon/cs/shared/data/Coordinate.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {


/**
 * @class WorldEventRpc
 * 월드 이벤트 관련 RPC
 */
class WorldEventRpc
{
public:
    virtual ~WorldEventRpc() {}
    // 존에 입장시에 정보를 요청한다.
    DECLARE_SRPC_METHOD_0(WorldEventRpc, queryWorldEventInfo);

    // 랭킹 정보를 요청한다.
    DECLARE_SRPC_METHOD_1(WorldEventRpc, queryWorldEventRankingScoreInfo,
        WorldEventCode, worldEventCode);

public:
    DECLARE_SRPC_METHOD_1(WorldEventRpc, onWorldEventInfo,
        WorldEventInfos, infos);

    DECLARE_SRPC_METHOD_2(WorldEventRpc, onWorldEventRankingScoreInfo,
        WorldEventRankerInfos, infos, uint32_t, myScore);

public:
    // 월드에서 이벤트가 열렸을때
    DECLARE_SRPC_METHOD_1(WorldEventRpc, evWorldEventOpened,
        WorldEventCode, worldEventCode);

    // 파티에 참가할때
    DECLARE_SRPC_METHOD_4(WorldEventRpc, evWorldEventMissionJoined,
        WorldEventCode, worldEventCode, WorldEventMissionCode, missionCode,
        uint8_t, currentPhase, PartyId, partyId);

    // 존에 있는 사람들 전부가 받는다.
    DECLARE_SRPC_METHOD_2(WorldEventRpc, evWorldEventPhaseChanged,
        WorldEventCode, worldEventCode, uint8_t, currentEventPhase);

    /// 리전안에 있는 사람만 이벤트를 받는다.
    DECLARE_SRPC_METHOD_3(WorldEventRpc, evWorldEventMissionPhaseChanged,
        WorldEventCode, worldEventCode, WorldEventMissionCode, missionCode, uint8_t, currentMissionPhase);

    DECLARE_SRPC_METHOD_3(WorldEventRpc, evWorldEventMissionResult,
        WorldEventCode, worldEventCode, WorldEventMissionCode, missionCode,
        WorldEventMissionStateType, missionStateType);

    DECLARE_SRPC_METHOD_1(WorldEventRpc, evWorldEventClosed,
        WorldEventCode, worldEventCode);

    DECLARE_SRPC_METHOD_2(WorldEventRpc, evWorldEventResult,
        WorldEventCode, worldEventCode, WorldEventStateType, stateType);

    // 월드 이벤트가 성공했을때만 날라온다.
    DECLARE_SRPC_METHOD_2(WorldEventRpc, evWorldEventTopRankerRewardInfo, 
        WorldEventCode, worldEventCode, RankingRewardInfos, rakingRewardInfos);

    // 자깃것만 이벤트로 받는다.
    DECLARE_SRPC_METHOD_3(WorldEventRpc, evWorldEventRewarded,
        WorldEventCode, worldEventCode, CostType, costType, uint64_t, currentValue);

    // 월드 이벤트에 이동 알림이 있는 entity만 알린다
    DECLARE_SRPC_METHOD_3(WorldEventRpc, evWorldEventEntityMoved,
        GameObjectInfo, objectInfo, DataCode, entityCode, Position, position);

    // 월드 이벤트에 이동 알림이 있는 entity만 알린다
    DECLARE_SRPC_METHOD_1(WorldEventRpc, evWorldEventEntityDespawned,
        GameObjectInfo, objectInfo);

    DECLARE_SRPC_METHOD_4(WorldEventRpc, evWorldEventKillMissionInfo,
        WorldEventCode, worldEventCode, WorldEventMissionCode, missionCode,
        uint8_t, currentMissionPhase, WorldEventKillMissionInfoMap, infoMap);

    DECLARE_SRPC_METHOD_4(WorldEventRpc, evWorldEventKillMissionInfoUpdated,
        WorldEventCode, worldEventCode, WorldEventMissionCode, missionCode,
        DataCode, entityCode, uint8_t, currentCount);
};

}} // namespace gideon { namespace rpc {