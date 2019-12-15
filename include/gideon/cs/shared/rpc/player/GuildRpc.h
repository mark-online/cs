#pragma once
#include <gideon/cs/shared/data/GuildInfo.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class GuildRpc
 * 길드 관련 RPC
 */
class GuildRpc
{
public:
    virtual ~GuildRpc() {}

public:
    /// 금고 구매
    /// - response: onPurchaseVault
    DECLARE_SRPC_METHOD_1(GuildRpc, purchaseVault,
        BaseVaultInfo, vaultInfo);
    
    /// 길드 스킬 활성화
    /// - response: onActivateGuildSkill
    /// - event: evGuildSkillActivated 다받는다
    DECLARE_SRPC_METHOD_1(GuildRpc, activateGuildSkill,
        SkillCode, skillCode);

    /// 길드 스킬 초기화
        /// - response: onDeactivateGuildSkills
        /// - event: evGuildSkillsDeactivated 다받는다
    DECLARE_SRPC_METHOD_0(GuildRpc, deactivateGuildSkills);

public:
    DECLARE_SRPC_METHOD_2(GuildRpc, onPurchaseVault,
        ErrorCode, errorCode, BaseVaultInfo, vaultInfo);

    DECLARE_SRPC_METHOD_2(GuildRpc, onActivateGuildSkill,
        ErrorCode, errorCode, SkillCode, skillCode);

    DECLARE_SRPC_METHOD_1(GuildRpc, onDeactivateGuildSkills,
        ErrorCode, errorCode);

public:
    /// 길드에 가입됐다.
    DECLARE_SRPC_METHOD_2(GuildRpc, evGuildCreated,
        ObjectId, characterId, BaseGuildInfo, guildInfo);

    /// 길드에 가입됐다.
    DECLARE_SRPC_METHOD_2(GuildRpc, evGuildJoined,
        ObjectId, characterId, BaseGuildInfo, guildInfo);

    /// 길드에 탈퇴됐다.
    DECLARE_SRPC_METHOD_1(GuildRpc, evGuildLeft,
        ObjectId, characterId);

    DECLARE_SRPC_METHOD_1(GuildRpc, evGuildSkillActivated,
        SkillCode, skillCode);

    DECLARE_SRPC_METHOD_0(GuildRpc, evGuildSkillsDeactivated);

};

}} // namespace gideon { namespace rpc {