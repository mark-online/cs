#pragma once

#include <gideon/cs/shared/data/SkillEffectInfo.h>
#include <gideon/cs/shared/data/GraveStoneInfo.h>
#include <gideon/cs/shared/data/UnionEntityInfo.h>
#include <gideon/cs/shared/data/ErrorCode.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {


/**
 * @class SkillRpc
 * 스킬 관련 RPC
 */
class SkillRpc : public boost::noncopyable
{
public:
    virtual ~SkillRpc() {}

public:
    /***
     * 스킬을 배운다
     ***/
    DECLARE_SRPC_METHOD_1(SkillRpc, learnSkills,
       SkillCodes, skillCodes);

    /***
     * 모든 배운 스킬을 초기화한다
     ***/
    DECLARE_SRPC_METHOD_0(SkillRpc, resetLearnedSkills);

public:
    DECLARE_SRPC_METHOD_2(SkillRpc, onLearnSkills,
        ErrorCode, errorCode, SkillPoint, currentSkillPoint);

    // 스킬을 취소한다.
    DECLARE_SRPC_METHOD_3(SkillRpc, onResetLearnedSkills,
        ErrorCode, errorCode, GameMoney, currentGameMoney, SkillPoint, currentSkillPoint);

public:

    /// 관심 영역 내에서 누군가가 집중 시킬 활성화를 취소하였다
    DECLARE_SRPC_METHOD_2(SkillRpc, evConcentrationSkillCancelled,
        GameObjectInfo, entityInfo, SkillCode, skillCode);

    /// 관심 영역 내에서 누군가가 집중 시킬 활성화를 완료하였다
    DECLARE_SRPC_METHOD_2(SkillRpc, evConcentrationSkillCompleted,
        GameObjectInfo, entityInfo, SkillCode, skillCode);


    /// 스킬이 추가 됐다.(자신만 받는다)
    DECLARE_SRPC_METHOD_2(SkillRpc, evSkillLearned,
        SkillCode, removeSkillCode, SkillCode, addSkillCode);


    /// 패시브 타이머 스킬이 발동됐다.(자신도 받는다)
    DECLARE_SRPC_METHOD_2(SkillRpc, evPassiveSkillActivated,
        GameObjectInfo, entityInfo, SkillCode, skillCode);

    /// 스킬이 추가 됐다.(자신만 받는다)
    DECLARE_SRPC_METHOD_0(SkillRpc, evAllSkillRemoved);

};

}} // namespace gideon { namespace rpc {