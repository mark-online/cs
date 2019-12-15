#pragma once
#include <gideon/cs/shared/data/ArenaInfo.h>
#include <gideon/cs/shared/data/RegionInfo.h>
#include <gideon/cs/shared/data/Certificate.h>
#include <gideon/cs/shared/data/Chatting.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class ArenaRpc
 * 투기장 관련 RPC
 */
class ArenaRpc
{
public:
    virtual ~ArenaRpc() {}

    /**
     * 투가장(솔로) 참가 예약을 한다.
     * - response: onChallengeSolo
     */
    DECLARE_SRPC_METHOD_1(ArenaRpc, challengeSolo,
        MapCode, mapCode);

    /**
     * 투가장(파티) 참가 예약을 한다.
     * - response: onChallengeParty
     */
    DECLARE_SRPC_METHOD_1(ArenaRpc, challengeParty,
        MapCode, modeMapCode);

	/**
     * 투가장 참가 예약을 취소 한다.
     * - response: cancelChallengeParty
     */
    DECLARE_SRPC_METHOD_1(ArenaRpc, cancelChallenge,
        MapCode, modeMapCode);
	/**
     * 투가장 참가를 결정한다.
     * - response: cancelChallengeParty
     */
	DECLARE_SRPC_METHOD_2(ArenaRpc, joinArena,
		ObjectId, arenaId, MapCode, arenaWorldMapCode);

    DECLARE_SRPC_METHOD_0(ArenaRpc, leaveArena);


    DECLARE_SRPC_METHOD_1(ArenaRpc, sayInArena,
        ChatMessage, message);

    DECLARE_SRPC_METHOD_1(ArenaRpc, setArenaWaypoint,
        Waypoint, waypoint);
public:
	// 투기장 참가 예약 응답.
	DECLARE_SRPC_METHOD_2(ArenaRpc, onChallengeSolo,
		ErrorCode, errorCode, MapCode, modeMapCode);

	// 투기장 참가 예약 응답.
	DECLARE_SRPC_METHOD_2(ArenaRpc, onChallengeParty,
		ErrorCode, errorCode, MapCode, modeMapCode);

	// 투기장 참가 예약 응답.
	DECLARE_SRPC_METHOD_2(ArenaRpc, onCancelChallenge,
		ErrorCode, errorCode, MapCode, modeMapCode);

	// 투기장 참가 응답
	DECLARE_SRPC_METHOD_3(ArenaRpc, onJoinArena,
		ErrorCode, errorCode, MigrationTicket, migrationTicket, ArenaPoint, arenaPoint);

    DECLARE_SRPC_METHOD_2(ArenaRpc, onLeaveArena,
        ErrorCode, errorCode, MigrationTicket, migrationTicket);

public:
	DECLARE_SRPC_METHOD_3(ArenaRpc, evArenaMatched,
		ObjectId, arenaId, MapCode, modeMapCode, MapCode, arenaWorldMapCode);

    /// 투기장에 같은 편이 입장했을때(도전자를 제외한 모두 받는다)
    DECLARE_SRPC_METHOD_2(ArenaRpc, evArenaMatchMemberEntered,
        ArenaTeamType, teamType, ArenaPlayerInfo, playerInfo);

    /// 투기장 최초 입장했을때 이벤트(도전자만 받는다)
    DECLARE_SRPC_METHOD_5(ArenaRpc, evArenaMatchInfos,
        ArenaMatchModeInfo, matchInfo, ArenaTeamType, myTeam,
        ArenaPlayerInfos, teamInfos, ArenaPlayerInfos, enemyInfos, RegionCode, regionCode);

    /// 투기장에서 도전자가 퇴장 할때
    DECLARE_SRPC_METHOD_2(ArenaRpc, evArenaMatchMemberLeft,
        ArenaTeamType, teamType, ObjectId, playerId);

    DECLARE_SRPC_METHOD_1(ArenaRpc, evArenaCountdownStarted,
        sec_t, startTime);

    DECLARE_SRPC_METHOD_2(ArenaRpc, evArenaPlayerKilled,
        GameObjectInfo, killerId, GameObjectInfo, deadManId);

    DECLARE_SRPC_METHOD_2(ArenaRpc, evArenaMatchScoreUpdated,
        uint32_t, blueScore, uint32_t, redScore);

    /// 투기장 종료
    DECLARE_SRPC_METHOD_2(ArenaRpc, evArenaStopped,
        ArenaPoint, rewardPoint, ArenaResultType, resultType);

    /// 투기장에서 살아날때(모두 받음)
    DECLARE_SRPC_METHOD_2(ArenaRpc, evArenaPlayerRevived,
        ObjectId, playerId, ObjectPosition, position);

    /// 환생 시간(죽은 사람만 받음)
    DECLARE_SRPC_METHOD_1(ArenaRpc, evReviveLeftTimeInfo,
        sec_t, leftTime);

    /// 플레이어 스코어가 업데이트 됨(천체 받음)
    DECLARE_SRPC_METHOD_2(ArenaRpc, evArenaPlayerScoreUpdated,
        ObjectId, playerId, uint32_t, scoreId);

    /// 채팅(팀만 받음)
    DECLARE_SRPC_METHOD_2(ArenaRpc, evArenaPlayerSaid,
        ObjectId, playerId, ChatMessage, message);

    /// 웨이포인트(팀만 받음)
    DECLARE_SRPC_METHOD_2(ArenaRpc, evArenaWaypointSetted,
        ObjectId, playerId, Waypoint, waypoint);
    
    /// 맵상에서 표시용으로 사용한다.
    DECLARE_SRPC_METHOD_3(ArenaRpc, evArenaTeamPlayerMoved,
        ObjectId, playerId, float, x, float, y);
};


}} // namespace gideon { namespace rpc {