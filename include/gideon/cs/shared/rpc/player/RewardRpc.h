#pragma once
#include <gideon/cs/shared/data/Money.h>
#include <gideon/cs/shared/data/LevelInfo.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {


/**
 * @class RewardRpc
 * 성장 관련 RPC
 */
class RewardRpc
{
public:
    virtual ~RewardRpc() {}

public:
    // 돈을 보상한다.
    DECLARE_SRPC_METHOD_1(RewardRpc, evMoneyRewarded, 
        GameMoney, money);
    // 케릭터 레벨 성장을 알린다(자신만 받는다)
    DECLARE_SRPC_METHOD_4(RewardRpc, evPlayerLeveledUpInfo,
        CurrentLevel, levelInfo, ExpPoint, exp, ExpPoint, rewardExp, SkillPoint, skillPoint);
    // 현제 경험치 업데이트(자신만 받는다)
    DECLARE_SRPC_METHOD_1(RewardRpc, evExpPointUpdated,
        ExpPoint, currentExp);
    // 케릭터 레벨 성장을 알린다.
    DECLARE_SRPC_METHOD_2(RewardRpc, evPlayerLeveledUp,
        GameObjectInfo, playerInfo, bool, isMajorLevelUp);

    // 케릭터 클래스 변화를 알린다.(자신과 파티원이 받는다)
    DECLARE_SRPC_METHOD_2(RewardRpc, evCharacterClassChanged,
        ObjectId, playerId, CharacterClass, characterClass);
};

}} // namespace gideon { namespace rpc {