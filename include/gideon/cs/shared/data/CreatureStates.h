#pragma once

#include "Code.h"

namespace gideon {

/**
 * @enum CreatureStateType 
 */
enum CreatureStateType
{
    cstNormal = 0x00000000,  
    cstCombat = 0x00000001, // 전투 중
    cstDead = 0x00000002, // 죽음
    cstCasting = 0x00000004, // 캐스팅..
    cstStun = 0x00000008, // 스턴
    cstItemLooting = 0x00000010, // 아이템 루팅 중
    cstRequestTrade = 0x00000020, // 거래 요청 중
    cstTrade = 0x00000040, // 거래 중
    cstFieldDuel = 0x00000080, // 1:1 대전중
    cstPanic = 0x00000100, // 공포상태
    cstTransformation = 0x00000200, // 변신(자신이 변신)
    cstMutation = 0x00000400, // 상대방이 변이 시킴  
    cstSleep = 0x00000800,   // 수면
    cstHide = 0x00001000, // 은신
    cstGliderMountReady = 0x00002000, // 글라이더 타는 중
    cstGliderMount = 0x00004000, // 글라이더 타는 중
    cstVehicleMount = 0x00008000, // 말타는중
    cstFrenzie = 0x00010000, // 광분
    cstParalyse = 0x00020000, // 마비
    cstDisableMagic = 0x00040000, // 매직 불가능
    cstShackle = 0x00080000, // 족쇠
    cstWalk = 0x00100000, // 걷는다.
    cstKnockBack = 0x00200000, // 넉백
    cstChao = 0x00400000, // 카오
    cstTempChao = 0x00800000, // 임시카오
    cstConcentrationSkill = 0x01000000, // 집중스킬 시전 중
    cstInvincible = 0x02000000, // 무적
    cstSpawnProtection = 0x04000000, // 스폰 보호
    cstBindRecallCasting = 0x08000000, // 귀환 캐스팅 중
    cstEvading = 0x10000000, // 전투 회피(스폰 위치 복귀 중)
    cstFleeing = 0x20000000, // 겁 먹고 도망 중
    //cstDashing = 0x40000000, //< 대쉬
};


template <typename T>
inline bool toBool(T value)
{ 
    return value > 0;
}


/**
 * @enum CreatureStateInfo
 * 
 * 생명체 행동 정의
 **/
struct CreatureStateInfo
{
    uint32_t states_;
	DataCode castCode_;

    CreatureStateInfo() :
        states_(cstNormal) {}

    void reset() {
        states_ = cstNormal;
    }

	void setCastCode(DataCode dataCode) {
		castCode_ = dataCode;
	}

    void toggleState(CreatureStateType cst) {
        states_ ^= cst;
    }

    void setState(CreatureStateType cst) {
        states_ |= cst;
    }

    void unsetState(CreatureStateType cst) {
        states_ &= ~cst;
    }

    bool hasState(CreatureStateType cst) const {
        return toBool(states_ & cst);
    }

    bool isNormalState() const {
        return states_ == cstNormal;
    }

    bool hasForceToUnmountState() const {
        if( toBool(states_ & cstStun) || toBool(states_ & cstMutation) || toBool(states_ & cstSleep) || toBool(states_ & cstParalyse) || toBool(states_ & cstKnockBack))
            return true;

        return false;
    }

    bool isCrowdControl() const {
        return hasState(cstStun) || hasState(cstPanic) || hasState(cstParalyse) || hasState(cstMutation) || hasState(cstSleep) || hasState(cstShackle) || hasState(cstKnockBack);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & states_ & castCode_;
    }
};


} // namespace gideon {
