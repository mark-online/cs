#pragma once

#include <gideon/cs/shared/data/ChannelInfo.h>
#include <gideon/cs/shared/data/WorldInfo.h>
#include <gideon/cs/shared/data/Chatting.h>
#include <gideon/cs/shared/data/PartyInfo.h>
#include <gideon/cs/shared/data/PlayerInfo.h>
#include <gideon/cs/shared/data/DominionInfo.h>
#include <gideon/cs/shared/data/BuddyInfos.h>
#include <gideon/cs/shared/data/ErrorCode.h>
#include <sne/srpc/RpcInterface.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace rpc {

/**
 * @class ShardChannelRpc
 * 샤드 전체 채팅 채널 관련 RPC
 */
class ShardChannelRpc : public boost::noncopyable
{
public: 
    virtual ~ShardChannelRpc() {}

public:
    /**
     * Shard에서 채팅을 한다
     * - event: evShardSaid
     */
    DECLARE_SRPC_METHOD_1(ShardChannelRpc, sayInShard,
        ChatMessage, message);

public:
    /// 누군가 Shard 범위의 채팅을 하였다
    DECLARE_SRPC_METHOD_3(ShardChannelRpc, evShardSaid,
        ObjectId, playerId, Nickname, nickname, ChatMessage, message);
};


/**
 * @class WorldMapChannelRpc
 * 채팅 채널 관련 RPC
 */
class WorldMapChannelRpc : public boost::noncopyable
{
public:
    virtual ~WorldMapChannelRpc() {}

public:
    /**
     * 월드맵에서 채팅을 한다
     * - event: evWorldMapSaid
     */
    DECLARE_SRPC_METHOD_1(WorldMapChannelRpc, sayInWorldMap,
        ChatMessage, message);

public:
    /// 월드맵 채널에 입장했다
    DECLARE_SRPC_METHOD_1(WorldMapChannelRpc, evWorldMapChannelEntered,
        MapCode, worldMapCode);

    /// 월드맵 채널에서 퇴장했다
    DECLARE_SRPC_METHOD_1(WorldMapChannelRpc, evWorldMapChannelLeft,
        MapCode, worldMapCode);

    /// 누군가 월드맵 범위의 채팅을 하였다
    DECLARE_SRPC_METHOD_3(WorldMapChannelRpc, evWorldMapSaid,
        ObjectId, playerId, Nickname, nickname, ChatMessage, message);
};


/**
 * @class NoticeRpc
 * 공지 관련 RPC
 */
class NoticeRpc : public boost::noncopyable
{
public:
    virtual ~NoticeRpc() {}

public:
    /**
     * 샤드 전체에 공지 메세지를 전송한다
     * - event: evShardNoticed
     */
    DECLARE_SRPC_METHOD_1(NoticeRpc, noticeToShard,
        ChatMessage, message);

public:
    /// 샤드 전체 공지
    DECLARE_SRPC_METHOD_1(NoticeRpc, evShardNoticed,
        ChatMessage, message);
};


/**
 * @class CommunityPartyRpc
 * Community Party RPC
 */
class CommunityPartyRpc
{
public:
    /**
     * 파티 요청
     * - response: onInviteParty
     * - event: evPartyInvited
     */
    DECLARE_SRPC_METHOD_1(CommunityPartyRpc, inviteParty,
        Nickname, nickname);
    /**
     * 파티 응답
     * - response: onRespondPartyInvitation
     * - event: evPartyInvitationReponded
     */
    
    DECLARE_SRPC_METHOD_2(CommunityPartyRpc, respondPartyInvitation,
        Nickname, nickname, bool, isAnswer);

    /**
     * 파티 탈퇴
     * - response: onLeaveParty
     * - event: evPartyLeft
     */
    DECLARE_SRPC_METHOD_0(CommunityPartyRpc, leaveParty);

    /**
     * 파티 멤버 강퇴
     * - response: onKickPartyMember
     * - event: evPartyLeft
     */
    DECLARE_SRPC_METHOD_1(CommunityPartyRpc, kickPartyMember,
        ObjectId, playerId);


    DECLARE_SRPC_METHOD_1(CommunityPartyRpc, sayPartyMember,
        ChatMessage, message);

    DECLARE_SRPC_METHOD_1(CommunityPartyRpc, setWaypoint,
        Waypoint, waypoint);

    /**
     * 파티 마스터 위임
     * - response: onDelegatePartyMaster(실패일때만 온다)
     * - event: evPartyMasterChanged(성공일때)
     */
    DECLARE_SRPC_METHOD_1(CommunityPartyRpc, delegatePartyMaster,
        ObjectId, newMasterId);
        

    DECLARE_SRPC_METHOD_1(CommunityPartyRpc, responsePublicParty,
        PartyId, partyId);

    /**
     * 파티 <-> 레이드 파티로 전환 시킨다.
     * - response: onChangePartyType(실패일때만 온다)
     * - event: evPartyTypeChanged(성공일때 파티원 전원 받음)
     */
    DECLARE_SRPC_METHOD_1(CommunityPartyRpc, changePartyType,
        PartyType, partyType);

    /**
     * 래이드 파티 그룹위치를 옮긴다
     * - response: onMoveRaidPartyGroupPosition(실패일때만 온다)
     * - event: evRaidPartyGroupPositionMoved(성공일때 파티원 전원 받음)
     */
    DECLARE_SRPC_METHOD_2(CommunityPartyRpc, moveRaidPartyGroupPosition,
        ObjectId, playerId, PartyPosition, position); 

    /**
     * 래이드 파티 그룹위치를 교환한다.
     * - response: onSwitchRaidPartyGroupPosition(실패일때만 온다)
     * - event: evRaidPartyGroupPositionSwitched(성공일때 파티원 전원 받음)
     */
    DECLARE_SRPC_METHOD_2(CommunityPartyRpc, switchRaidPartyGroupPosition,
        ObjectId, srcId, ObjectId, descId); 
public:
    DECLARE_SRPC_METHOD_2(CommunityPartyRpc, onInviteParty,
        ErrorCode, errorCode, Nickname, nickname);

    DECLARE_SRPC_METHOD_1(CommunityPartyRpc, onRespondPartyInvitation,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_1(CommunityPartyRpc, onLeaveParty,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_1(CommunityPartyRpc, onKickPartyMember,
        ErrorCode, errorCode);
    
    DECLARE_SRPC_METHOD_1(CommunityPartyRpc, onDelegatePartyMaster,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_2(CommunityPartyRpc, onResponsePublicParty,
        ErrorCode, errorCode, PartyId, partyId);

    DECLARE_SRPC_METHOD_2(CommunityPartyRpc, onChangePartyType,
        ErrorCode, errorCode, PartyType, partyType);

    DECLARE_SRPC_METHOD_3(CommunityPartyRpc, onMoveRaidPartyGroupPosition,
        ErrorCode, errorCode, ObjectId, playerId, PartyPosition, position);

    DECLARE_SRPC_METHOD_3(CommunityPartyRpc, onSwitchRaidPartyGroupPosition,
        ErrorCode, errorCode, ObjectId, srcId, ObjectId, descId); 
public:
    DECLARE_SRPC_METHOD_1(CommunityPartyRpc, evPartyInvited,
        Nickname, nickname);

    DECLARE_SRPC_METHOD_2(CommunityPartyRpc, evPartyInvitationReponded,
        Nickname, nickname, bool, isAnswer);

    DECLARE_SRPC_METHOD_1(CommunityPartyRpc, evPartyMeberAdded,
        PartyMemberInfo, memberInfo);
    
    DECLARE_SRPC_METHOD_2(CommunityPartyRpc, evPartyMemberInfos,
        PartyMemberInfos, memberInfos, PartyType, partyType);

    DECLARE_SRPC_METHOD_1(CommunityPartyRpc, evPartyMemberLeft,
        ObjectId, playerId);

    DECLARE_SRPC_METHOD_1(CommunityPartyRpc, evPartyMemberKicked,
        ObjectId, playerId);

    DECLARE_SRPC_METHOD_1(CommunityPartyRpc, evPartyMasterChanged,
        ObjectId, masterId);

    DECLARE_SRPC_METHOD_3(CommunityPartyRpc, evPartyMemberMapMoved,
        ObjectId, memberId, MapCode, worldMapCode, MapCode, subMapCode);

    DECLARE_SRPC_METHOD_3(CommunityPartyRpc, evPartyMemberSaid,
        ObjectId, playerId, Nickname, nickname, ChatMessage, message);

    DECLARE_SRPC_METHOD_2(CommunityPartyRpc, evWaypointSet,
        ObjectId, playerId, Waypoint, waypoint);

    DECLARE_SRPC_METHOD_1(CommunityPartyRpc, evPartyTypeChanged,
        PartyType, partyType);

    DECLARE_SRPC_METHOD_2(CommunityPartyRpc, evRaidPartyGroupPositionMoved,
        ObjectId, playerId, PartyPosition, position); 

    DECLARE_SRPC_METHOD_2(CommunityPartyRpc, evRaidPartyGroupPositionSwitched,
        ObjectId, srcId, ObjectId, descId); 

    DECLARE_SRPC_METHOD_1(CommunityPartyRpc, evPartyGroupPositionInitialized,
        PartyPositionMap, positionMap);
};

/**
 * @class WhisperRpc
 * Community Whisper RPC
 */
class WhisperRpc
{
public:
    /**
     * 귓속말
     * - response: onWhisper
     * - event: evWhispered
     */
    DECLARE_SRPC_METHOD_2(WhisperRpc, whisper,
        Nickname, nickname, ChatMessage, message);

public:
    DECLARE_SRPC_METHOD_3(WhisperRpc, onWhisper,
        ErrorCode, errorCode, Nickname, nickname, ChatMessage, message);

public:
    DECLARE_SRPC_METHOD_3(WhisperRpc, evWhispered,
        ObjectId, playerId, Nickname, nickname, ChatMessage, message);
};

/**
 * @class CommunityGuildRpc
 * Community Guild RPC
 */
class CommunityGuildRpc
{
public:
    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, createGuild,
        GuildName, guildName, GuildMarkCode, guildMarkCode);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, inviteGuild,
        Nickname, nickname);

    DECLARE_SRPC_METHOD_0(CommunityGuildRpc, leaveGuild);

    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, respondGuildInvitation,
        Nickname, nickname, bool, isAnswer);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, sayGuildMember,
        ChatMessage, message);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, kickGuildMember,
        ObjectId, playerId);

    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, addGuildRelationship,
        GuildId, targetGuildId, GuildRelatioshipType, type);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, removeGuildRelationship,
        GuildId, targetGuildId);

    // 길드 서칭
    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, searchGuildInfo,
        GuildName, searchGuildName);

    // 길드 지원
    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, signupGuild,
        GuildId, guildId);

    // 길드 지원자 정보 요구
    // response: onGuildApplicants
    DECLARE_SRPC_METHOD_0(CommunityGuildRpc, queryGuildApplicants);

    // 길드 지원자 처리
    // event: evGuildSignUpResponded
    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, confirmGuildApplicant,
        ObjectId, playerId, bool, isAccept);

    // 길드 맴버 정보 요구
    // response: onGuildMemberInfos
    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, queryGuildMember,
        GuildId, guildId);
    
    // 현재 지원 하고 있는 길드 아이디 요청
    // response: onMyGuildApplicantId
    DECLARE_SRPC_METHOD_0(CommunityGuildRpc, queryMyGuildApplicantId);

    // response: onDetailSearchGuildInfo
    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, queryDetailSearchGuildInfo,
        GuildId, guildId);

    DECLARE_SRPC_METHOD_0(CommunityGuildRpc, cancelGuildApplicant);


    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, modifyGuildIntroduction,
        GuildIntroduction, introduction);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, modifyGuildNotice,
        GuildNotice, notice);
    // response: evGuildInfo
    DECLARE_SRPC_METHOD_0(CommunityGuildRpc, queryMyGuildInfo);  
    
    // response: evGuildSkillInfo
    DECLARE_SRPC_METHOD_0(CommunityGuildRpc, queryMyGuildSkillInfo);

    // response: evGuildLevelInfo
    DECLARE_SRPC_METHOD_0(CommunityGuildRpc, queryMyGuildLevelInfo);

    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, queryGuildEventLogs, 
        uint8_t, beginLogIndex, uint8_t, logCount);

    /// 길드 등급 추가
    /// - response: onAddGuildRank
    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, addGuildRank, 
        GuildRankName, rankName);

    /// 길드 등급 삭제
    /// - response: onDeleteGuildRank
    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, deleteGuildRank, 
        GuildRankId, rankId);

    /// 길드 등급 순위 변경
    /// - response: onSwapGuildRank
    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, swapGuildRank,
        GuildRankId, rankId1, GuildRankId, rankId2);

    /// 길드 등급 이름 변경
    /// - response: onSetGuildRankName
    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, setGuildRankName, 
        GuildRankId, rankId, GuildRankName, rankName);

    /// 길드 등급 권한 변경
    /// - response: onUpdateGuildRankRights
    DECLARE_SRPC_METHOD_3(CommunityGuildRpc, updateGuildRankRights, 
        GuildRankId, rankId, uint32_t, rights, uint32_t, goldWithdrawalPerDay);

    /// 길드 등급 권한 변경
    /// - response: onUpdateGuildBankRights
    DECLARE_SRPC_METHOD_4(CommunityGuildRpc, updateGuildBankRights,
        GuildRankId, rankId, VaultId, vaultId, uint32_t, rights, uint32_t, itemWithdrawalPerDay);

    /// 길드 등급 변경
    /// - response: onUpdateGuildRank
    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, updateGuildRank,
        ObjectId, memberId, GuildRankId, rankId);

public:
    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, onCreateGuild,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, onInviteGuild,
        ErrorCode, errorCode, Nickname, nickname);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, onLeaveGuild,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, onRespondGuildInvitation,
        ErrorCode, errorCode, GuildId, guildId);

    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, onKickGuildMember,
        ErrorCode, errorCode, ObjectId, playerId);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, onAddGuildRelationship,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, onRemoveGuildRelationship,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, onSearchGuildInfo,
        ErrorCode, errorCode, SearchGuildInfos, searchGuildInfos);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, onSignupGuild,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, onGuildApplicants,
        ErrorCode, errorCode, GuildApplicantInfoMap, guildApplicantInfoMap);

    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, onConfirmGuildApplicant,
        ErrorCode, errorCode, ObjectId, playerId);

    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, onGuildMemberInfos,
        ErrorCode, errorCode, GuildMemberInfoMap, guildMemberInfoMap);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, onMyGuildApplicantId,
        GuildId, guildId);

    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, onDetailSearchGuildInfo,
        ErrorCode, errorCode, DetailSearchGuildInfo, info);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, onCancelGuildApplicant,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, onModifyGuildIntroduction,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, onModifyGuildNotice,
        ErrorCode, errorCode);
    
    DECLARE_SRPC_METHOD_5(CommunityGuildRpc, onGuildEventLogs, 
        ErrorCode, errorCode, uint8_t, pageIndex,
        uint8_t, pageCount, uint8_t, totalLogCount, GuildEventLogInfoList, logList);

    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, onAddGuildRank,
        ErrorCode, errorCode, GuildRankInfo, rankInfo);
    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, onDeleteGuildRank,
        ErrorCode, errorCode, GuildRankId, rankId);
    DECLARE_SRPC_METHOD_3(CommunityGuildRpc, onSwapGuildRank, 
        ErrorCode, errorCode, GuildRankId, rankId1, GuildRankId, rankId2);
    DECLARE_SRPC_METHOD_3(CommunityGuildRpc, onSetGuildRankName, 
        ErrorCode, errorCode, GuildRankId, rankId, GuildRankName, rankName);
    DECLARE_SRPC_METHOD_4(CommunityGuildRpc, onUpdateGuildRankRights, 
        ErrorCode, errorCode, GuildRankId, rankId, uint32_t, rights, uint32_t, goldWithdrawalPerDay);
    DECLARE_SRPC_METHOD_5(CommunityGuildRpc, onUpdateGuildBankRights, 
        ErrorCode, errorCode, GuildRankId, rankId, VaultId, vaultId, uint32_t, rights, uint32_t, itemWithdrawalPerDay);
    DECLARE_SRPC_METHOD_3(CommunityGuildRpc, onUpdateGuildRank, 
        ErrorCode, errorCode, ObjectId, memberId, GuildRankId, rankId);

public:
    DECLARE_SRPC_METHOD_7(CommunityGuildRpc, evGuildInfo,
        BaseGuildInfo, guildInfo, GuildMemberInfoMap, guildMembers,
        GuildRelationshipInfoMap, relaytionMap,
        GuildIntroduction, introduction, GuildNotice, guildNotice,
        GuildRankInfos, rankInfos, GuildLevelInfo, guildLevelInfo);

    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, evGuildSkillInfos,
        GuildId, guildId, SkillCodes, guildSkills);

    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, evGuildLevelInfo,
        GuildId, guildId, GuildLevelInfo, guildLevelInfo);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, evGuildInvited,
        Nickname, nickname);

    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, evGuildInvitationResponded,
        Nickname, nickname, bool, isAnswer);

    DECLARE_SRPC_METHOD_3(CommunityGuildRpc, evGuildMemberSaid,
        ObjectId, playerId, Nickname, nickname, ChatMessage, message);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, evGuildMemberJoined,
        GuildMemberInfo, guildMemberInfo);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, evGuildMemberLeft,
        ObjectId, playerId);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, evGuildMemberKicked,
        ObjectId, playerId);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, evGuildMemberOnline,
        ObjectId, playerId);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, evGuildMemberOffline,
        ObjectId, playerId);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, evGuildRelationshipAdded,
        GuildRelationshipInfo, relationshipInfo);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, evGuildRelationshipRemoved,
        GuildId, targetGuildId);

    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, evGuildMemberPositionChanged,
        ObjectId, playerId, GuildMemberPosition, position);


    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, evGuildIntroductionModified,
        GuildIntroduction, introduction);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, evGuildNoticeModified,
         GuildNotice, notice);

    // 신청한 사람만 받음
    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, evGuildSignUpResponded,
        GuildName, guildName, bool, isAccept);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, evGuildMasterChanged,
        ObjectId, masterId);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, evGuildRankAdded,
        GuildRankInfo, rankInfo);

    DECLARE_SRPC_METHOD_1(CommunityGuildRpc, evGuildRankDeleted,
        GuildRankId, rankId);

    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, evGuildRankSwapped,
        GuildRankId, rankId1, GuildRankId, rankId2);

    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, evGuildRankNameUpdated,
        GuildRankId, rankId, GuildRankName, rankName);

    DECLARE_SRPC_METHOD_3(CommunityGuildRpc, evGuildRankRightsUpdated,
        GuildRankId, rankId, uint32_t, rights, uint32_t, goldWithdrawalPerDay);

    DECLARE_SRPC_METHOD_4(CommunityGuildRpc, evGuildBankRightsUpdated,
        GuildRankId, rankId, VaultId, vaultId, uint32_t, rights, uint32_t, itemWithdrawalPerDay);

    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, evGuildMemberRankUpdated,
        ObjectId, memberId, GuildRankId, rankId);

    DECLARE_SRPC_METHOD_2(CommunityGuildRpc, evGuildMemberLevelUpdated,
        ObjectId, memberId, CreatureLevel, level);
};


/**
 * @class CommunityDominionRpc
 * Community Guild RPC
 */
class CommunityDominionRpc
{
public:
	DECLARE_SRPC_METHOD_0(CommunityDominionRpc, queryWorldDominion);
	DECLARE_SRPC_METHOD_1(CommunityDominionRpc, queryZoneDominion,
		MapCode, worldMapCode);

public:
	DECLARE_SRPC_METHOD_1(CommunityDominionRpc, onWorldDominion,
		DominionWorldInfoMap, infoMap);
	DECLARE_SRPC_METHOD_1(CommunityDominionRpc, onZoneDominion,
		BuildingDominionInfos, infos);
};


/**
 * @class CommunityMessengerRpc
 * Community Messenger RPC
 */
class CommunityMessengerRpc
{
public:
	DECLARE_SRPC_METHOD_1(CommunityMessengerRpc, requestBuddy,
		Nickname, nickname);

	DECLARE_SRPC_METHOD_2(CommunityMessengerRpc, repsonseBuddy,
		Nickname, requester, bool, isAnswer);

	DECLARE_SRPC_METHOD_1(CommunityMessengerRpc, removeBuddy,
		ObjectId, playerId);

    DECLARE_SRPC_METHOD_1(CommunityMessengerRpc, addBlock,
		Nickname, nickname);

	DECLARE_SRPC_METHOD_1(CommunityMessengerRpc, removeBlock,
		ObjectId, playerId);

public:
	DECLARE_SRPC_METHOD_2(CommunityMessengerRpc, onRequestBuddy,
		ErrorCode, errorCode, Nickname, nickname);

	DECLARE_SRPC_METHOD_2(CommunityMessengerRpc, onRepsonseBuddy,
		ErrorCode, errorCode, BuddyInfo, buddyInfo);

	DECLARE_SRPC_METHOD_2(CommunityMessengerRpc, onRemoveBuddy,
		ErrorCode, errorCode, ObjectId, playerId);

    DECLARE_SRPC_METHOD_2(CommunityMessengerRpc, onAddBlock,
        ErrorCode, errorCode, BlockInfo, blockInfo);

    DECLARE_SRPC_METHOD_2(CommunityMessengerRpc, onRemoveBlock,
        ErrorCode, errorCode, ObjectId, playerId);


public:
	DECLARE_SRPC_METHOD_2(CommunityMessengerRpc, evBuddyInfos,
		BuddyInfos, buddyInfos, BlockInfos, blockInfos);

	DECLARE_SRPC_METHOD_1(CommunityMessengerRpc, evBuddyRequested,
		Nickname, nickname);

	DECLARE_SRPC_METHOD_1(CommunityMessengerRpc, evBuddyAdded,
		BuddyInfo, buddy);

	DECLARE_SRPC_METHOD_2(CommunityMessengerRpc, evBuddyOnlineStateChanged,
		ObjectId, playerId, bool, isOnline);

	DECLARE_SRPC_METHOD_1(CommunityMessengerRpc, evBuddyRemoved,
		ObjectId, playerId);
};

/**
 * @class CommunityGuildInventoryRpc
 * Community Messenger RPC
 */
class CommunityGuildInventoryRpc
{
public:
    /// 금고 목록 요청
    DECLARE_SRPC_METHOD_0(CommunityGuildInventoryRpc, queryGuildBankInfo);

    // = 길드 인벤토리를 열때
    // = response: onOpenGuildInventory
    DECLARE_SRPC_METHOD_1(CommunityGuildInventoryRpc, openGuildInventory,
        VaultId, vaultId);
    // = response: X
    DECLARE_SRPC_METHOD_0(CommunityGuildInventoryRpc, closeGuildInventory);

    // = 길드 인벤토리에 아이템을 옮길때
    // = response: onMoveGuildInventoryItem(실패할때만)
    // = event: onMoveGuildInventoryItem, evGuildInventoryItemRemoved
    DECLARE_SRPC_METHOD_3(CommunityGuildInventoryRpc, moveGuildInventoryItem,
        VaultId, vaultId, ObjectId, itemId, SlotId, slotId);
    // = 길드 인벤토리에 아이템을 교환할때
    // = response: onMoveInventoryItem(실패할때만)
    // = event: evGuildInventoryItemSwitched, evGuildInventoryItemCountUpdated
    DECLARE_SRPC_METHOD_3(CommunityGuildInventoryRpc, switchGuildInventoryItem,
        VaultId, vaultId, ObjectId, itemId1, ObjectId, itemId2);

    DECLARE_SRPC_METHOD_2(CommunityGuildInventoryRpc, queryGuildGameMoneyEventLogs, 
        uint8_t, beginLogIndex, uint8_t, logCount);

    DECLARE_SRPC_METHOD_2(CommunityGuildInventoryRpc, queryGuildBankEventLogs, 
        uint8_t, beginLogIndex, uint8_t, logCount);

    DECLARE_SRPC_METHOD_2(CommunityGuildInventoryRpc, updateGuildVaultName,
        VaultId, vaultId, VaultName, name);

public:
    DECLARE_SRPC_METHOD_3(CommunityGuildInventoryRpc, onGuildBankInfo,
        ErrorCode, errorCode, BaseVaultInfos, infos, GameMoney, gameMoney);

    DECLARE_SRPC_METHOD_3(CommunityGuildInventoryRpc, onOpenGuildInventory,
        ErrorCode, errorCode, VaultId, vaultId, InventoryInfo, inventoryInfo);
    DECLARE_SRPC_METHOD_1(CommunityGuildInventoryRpc, onMoveGuildInventoryItem,
        ErrorCode, errorCode);
    DECLARE_SRPC_METHOD_1(CommunityGuildInventoryRpc, onSwitchGuildInventoryItem,
        ErrorCode, errorCode);


    DECLARE_SRPC_METHOD_5(CommunityGuildInventoryRpc, onGuildGameMoneyEventLogs, 
        ErrorCode, errorCode, uint8_t, pageIndex,
        uint8_t, pageCount, uint8_t, totalLogCount, GuildGameMoneyEventLogInfoList, logList);

    DECLARE_SRPC_METHOD_5(CommunityGuildInventoryRpc, onGuildBankEventLogs, 
        ErrorCode, errorCode, uint8_t, pageIndex, 
        uint8_t, pageCount, uint8_t, totalLogCount, GuildBankEventLogInfoList, bankLogList);

    DECLARE_SRPC_METHOD_1(CommunityGuildInventoryRpc, onUpdateGuildVaultName,
        ErrorCode, errorCode);

public:
    DECLARE_SRPC_METHOD_1(CommunityGuildInventoryRpc, evGuildVaultAdded,
        BaseVaultInfo, vaultInfo);
    DECLARE_SRPC_METHOD_3(CommunityGuildInventoryRpc, evGuildInventoryItemCountUpdated,
        VaultId, vaultId, ObjectId, itemId, uint8_t, ItemCount);
    DECLARE_SRPC_METHOD_2(CommunityGuildInventoryRpc, evGuildInventoryItemAdded,
        VaultId, vaultId, ItemInfo, itemInfo);
    DECLARE_SRPC_METHOD_2(CommunityGuildInventoryRpc, evGuildInventoryItemRemoved,
        VaultId, vaultId, ObjectId, itemId);
    DECLARE_SRPC_METHOD_3(CommunityGuildInventoryRpc, evGuildInventoryItemMoved,
        VaultId, vaultId, ObjectId, itemId, SlotId, slotId);
    DECLARE_SRPC_METHOD_3(CommunityGuildInventoryRpc, evGuildInventoryItemSwitched,
        VaultId, vaultId, ObjectId, itemId1, ObjectId, itemId2);
    DECLARE_SRPC_METHOD_1(CommunityGuildInventoryRpc, evGuildGameMoneyUpdated,
        GameMoney, currentGameMoney);
    DECLARE_SRPC_METHOD_2(CommunityGuildInventoryRpc, evGuildVaultNameUpdated,
        VaultId, vaultId, VaultName, name);
};

/**
 * @class CommunityRpc
 * Community RPC
 */
class CommunityRpc :
    public ShardChannelRpc,
    public WorldMapChannelRpc,
    public NoticeRpc,
    public CommunityPartyRpc,
    public WhisperRpc,
    public CommunityGuildRpc,
	public CommunityDominionRpc,
	public CommunityMessengerRpc,
    public CommunityGuildInventoryRpc
{};


}} // namespace gideon { namespace rpc {
