#pragma once

#include <gideon/cs/shared/data/SkillEffectInfo.h>
#include <gideon/cs/shared/data/MesmerizationInfo.h>
#include <gideon/cs/shared/data/ItemEffectInfo.h>
#include <gideon/cs/shared/data/UnionEntityInfo.h>
#include <gideon/cs/shared/data/ErrorCode.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {


/**
 * @class EffectRpc
 * 스킬 관련 RPC
 */
class EffectRpc : public boost::noncopyable
{
public:
    virtual ~EffectRpc() {}
public:

    /// 자신과 상대방에서 스킬영향을 받았다(target, source만 받는다 스킬 뷰용)
    DECLARE_SRPC_METHOD_3(EffectRpc, evEffectApplied,
        GameObjectInfo, targetInfo, GameObjectInfo, sourceInfo,
        SkillEffectResult, skillEffectResult);

    /// 자신과 상대방에서 스킬영향을 받았다(target, source만 받는다 스킬 뷰용)
    DECLARE_SRPC_METHOD_3(EffectRpc, evItemEffected,
        GameObjectInfo, targetInfo, GameObjectInfo, sourceInfo,
        ItemEffectResult, itemEffectResult);


    /// 잠탱이 됐다.(자신도 받는다)
    DECLARE_SRPC_METHOD_3(EffectRpc, evMesmerizationEffected,
        GameObjectInfo, entityInfo, MesmerizationType, mezt, bool, isActivate);

    /// 변신 됐다.(자신도 받는다)
    DECLARE_SRPC_METHOD_3(EffectRpc, evCreatureTransformed,
        GameObjectInfo, entityInfo, NpcCode, npcCode, bool, isActivate);

    /// 변이 됐다.(자신도 받는다)
    DECLARE_SRPC_METHOD_3(EffectRpc, evCreatureMutated,
        GameObjectInfo, entityInfo, NpcCode, npcCode, bool, isActivate);
         
    /// 은신 해제.(자신 제외)
    DECLARE_SRPC_METHOD_1(EffectRpc, evCreatureReleaseHidden,
        UnionEntityInfo, entityInfo);

    /// 속도 변경.(자신도 받는다)
    DECLARE_SRPC_METHOD_2(EffectRpc, evCreatureMoveSpeedChanged,
        GameObjectInfo, entityInfo, float, currentSpeed);

    /// 광분 됐다.(자신도 받는다)
    DECLARE_SRPC_METHOD_3(EffectRpc, evCreatureFrenzied,
        GameObjectInfo, entityInfo, float, currnetScale, bool, isActivate);

    /// 넉백 (자신도 받는다)
    DECLARE_SRPC_METHOD_2(EffectRpc, evCreatureKnockbacked,
        GameObjectInfo, entityInfo, Position, position);

    /// 넉백 해재(자신도 받는다)
    DECLARE_SRPC_METHOD_1(EffectRpc, evCreatureKnockbackReleased,
        GameObjectInfo, entityInfo);

    /// 대쉬 시작
    DECLARE_SRPC_METHOD_2(EffectRpc, evCreatureDashing,
        GameObjectInfo, entityInfo, Position, position);

    DECLARE_SRPC_METHOD_1(EffectRpc, evPlayerGraveStoneStood,
        GraveStoneInfo, graveStoneInfo);

    DECLARE_SRPC_METHOD_3(EffectRpc, evReviveEffected,
        GameObjectInfo, entityInfo, HitPoint, currentPoint, ObjectPosition, position);

public:
    // 스킬 효과 추가
    DECLARE_SRPC_METHOD_2(EffectRpc, evEffectAdded,
        GameObjectInfo, entityInfo, DebuffBuffEffectInfo, info);

    // 스킬 효과 삭제
    DECLARE_SRPC_METHOD_3(EffectRpc, evEffectRemoved,
        GameObjectInfo, entityInfo, DataCode, dataCode, bool, isCaster);

    // 방어에 성공하다
    DECLARE_SRPC_METHOD_3(EffectRpc, evEffectHit,
        GameObjectInfo, casterInfo, GameObjectInfo, targetInfo, DataCode, dataCode);
};

}} // namespace gideon { namespace rpc {