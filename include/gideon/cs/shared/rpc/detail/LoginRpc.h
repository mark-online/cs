#pragma once

#include <gideon/cs/shared/data/Certificate.h>
#include <gideon/cs/shared/data/ErrorCode.h>
#include <gideon/cs/shared/data/RegionInfo.h>
#include <gideon/cs/shared/data/AccountInfo.h>
#include <gideon/cs/shared/data/UserInfo.h>
#include <gideon/cs/shared/data/ExpelReason.h>
#include <gideon/cs/shared/data/CreateCharacterInfo.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class LoginSessionRpc
 * Client <-> Login Server messages
 */
class LoginSessionRpc : public boost::noncopyable
{
public:
    virtual ~LoginSessionRpc() {}

public:
    /// 로그인을 한다
    /// - return c2l_onLogin
    DECLARE_SRPC_METHOD_2(LoginSessionRpc, c2l_login,
    UserId, userId, UserPassword, userPassword);

    /// 인증서로 인증(로그인)을 한다
    /// - return c2l_onRelogin
    DECLARE_SRPC_METHOD_1(LoginSessionRpc, c2l_relogin,
		Certificate, certificate);

    /// Shard 정보를 요청한다
    DECLARE_SRPC_METHOD_0(LoginSessionRpc, c2l_queryShardInfo);

    /// Shard 선택을 요청한다
    DECLARE_SRPC_METHOD_1(LoginSessionRpc, c2l_selectShard,
		ShardId, shardId);

    /// 닉네임 예약을 요청한다.
    DECLARE_SRPC_METHOD_1(LoginSessionRpc, c2l_reserveNickname,
		Nickname, nickname);

    /// 캐릭터 생성을 요청한다
    DECLARE_SRPC_METHOD_1(LoginSessionRpc, c2l_createCharacter,
		CreateCharacterInfo, createCharacterInfo);

    /// 캐릭터 삭제를 요청한다
    DECLARE_SRPC_METHOD_1(LoginSessionRpc, c2l_deleteCharacter,
		ObjectId, characterId);

    /// Shard 입장을 요청한다
    DECLARE_SRPC_METHOD_1(LoginSessionRpc, c2l_enterShard,
		ObjectId, characterId);

public:
    /**
    * 로그인 요청에 대한 응답
    * @param errorCode 실패할 경우, 아래의 값들은 유효하지 않다
    */
    DECLARE_SRPC_METHOD_4(LoginSessionRpc, c2l_onLogin,
		ErrorCode, errorCode, AccountInfo, accountInfo,
        CommunityServerInfo, communityServerInfo, CertificateMap, certificateMap);

    /**
    * 인증(로그인) 요청에 대한 응답
    * @param errorCode 실패할 경우, 아래의 값들은 유효하지 않다
    */
    DECLARE_SRPC_METHOD_2(LoginSessionRpc, c2l_onRelogin,
		ErrorCode, errorCode, Certificate, reissuedCertificate);

    /**
    * Shard 정보 요청에 대한 응답
    * @param errorCode 실패할 경우, 아래의 값들은 유효하지 않다
    */
    DECLARE_SRPC_METHOD_4(LoginSessionRpc, c2l_onQueryShardInfo,
		ErrorCode, errorCode, ShardInfoList, shardInfos, ZoneMapCodeMap, zoneMapCodeMap,
        CharacterCountPerShardMap, characterCounts);

    /// Shard 선택 요청에 대한 응답
    DECLARE_SRPC_METHOD_2(LoginSessionRpc, c2l_onSelectShard,
		ErrorCode, errorCode, FullUserInfo, userInfo);

    /// 닉네임 예약에 대한 응답
    DECLARE_SRPC_METHOD_2(LoginSessionRpc, c2l_onReserveNickname,
		ErrorCode, errorCode, Nickname, nickname);


    /// 캐릭터 생성 요청에 대한 응답
    DECLARE_SRPC_METHOD_2(LoginSessionRpc, c2l_onCreateCharacter,
		ErrorCode, errorCode, FullCharacterInfo, characterInfo);

    /// 캐릭터 삭제 요청에 대한 응답
    DECLARE_SRPC_METHOD_2(LoginSessionRpc, c2l_onDeleteCharacter,
		ErrorCode, errorCode, ObjectId, characterId);

    /// Shard 입장 요청에 대한 응답
    DECLARE_SRPC_METHOD_2(LoginSessionRpc, c2l_onEnterShard,
		ErrorCode, errorCode, ZoneServerInfo, zoneServerInfo);

public:
    /// 강제 퇴장 당했다
    DECLARE_SRPC_METHOD_1(LoginSessionRpc, c2l_evExpelled,
		ExpelReason, reason);
};


/**
* @class ZoneSessionRpc
* Client <-> Zone Server messages about login
*/
class ZoneSessionRpc : boost::noncopyable
{
public:
    virtual ~ZoneSessionRpc() {}

public:
    /**
    * 존 서버에 로그인한다
    * - Response: c2z_onLogin
    */
    DECLARE_SRPC_METHOD_5(ZoneSessionRpc, c2z_login,
        Certificate, certificate, RegionCode, spawnRegionCode, ObjectId, arenaId,
        MapCode, preGlobalMapCode, Position, position);

    /**
     * 존 서버에 로그아웃을 요청한다
     * - Response: None
     */
    DECLARE_SRPC_METHOD_0(ZoneSessionRpc, c2z_reserveLogout);

    /**
     * 존 서버에 로그아웃을 요청을 취소한다
     * - Response: None
     */
    DECLARE_SRPC_METHOD_0(ZoneSessionRpc, c2z_cancelLogout);

public:
    /**
     * 사용자 로그인 요청에 대한 응답.
     * - 이 응답을 받기 전에 다른 요청을 보낼 경우 서버에서 접속을 해제한다
     * @param reissuedCertificate 재발급 받은 인증서
     */
    DECLARE_SRPC_METHOD_2(ZoneSessionRpc, c2z_onLogin,
        ErrorCode, errorCode, Certificate, reissuedCertificate);
};


/**
 * @class CommunitySessionRpc
 * Client <-> Community Server messages about login
 */
class CommunitySessionRpc : boost::noncopyable
{
public:
    virtual ~CommunitySessionRpc() {}

public:
    /**
     * 커뮤니티 서버에 로그인한다
     * - Response: c2m_onLogin
     */
    DECLARE_SRPC_METHOD_1(CommunitySessionRpc, c2m_login,
        Certificate, certificate);

    /**
     * 사용자 로그인 요청에 대한 응답.
     * - 이 응답을 받기 전에 다른 요청을 보낼 경우 서버에서 접속을 해제한다
     * @param reissuedCertificate 재발급 받은 인증서
     */
    DECLARE_SRPC_METHOD_2(CommunitySessionRpc, c2m_onLogin,
        ErrorCode, errorCode, Certificate, reissuedCertificate);
};

}} // namespace gideon { namespace rpc {
