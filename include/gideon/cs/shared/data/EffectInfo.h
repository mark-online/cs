#pragma once

#include "Code.h"
#include "Time.h"
#include <sne/srpc/RpcContainers.h>

namespace gideon {

typedef uint16_t EffectIndex;

const EffectIndex invalidEffectIndex = 0;

typedef uint8_t EffectLevel;

const EffectLevel invalidEffectLevel = 0;
const EffectLevel minEffectLevel = 1;
const EffectLevel maxCommonEffectLevel = 30;

inline bool isCommonEffectLevel(EffectLevel effectLevel)
{
    return minEffectLevel <= effectLevel && effectLevel <= maxCommonEffectLevel;
}

/**
 * @enum TargetingType
 * 타겟팅 형태
 */
enum TargetingType
{
    ttNoneTarget = 0, //< 타켓 없음(대부분 패시브의 경우)
    ttSelf = 1, //< 캐릭터(Self)
    ttSelfArea = 2, //< 캐릭터 에어리어(Self Area)
    ttTarget = 3, //< 타켓 캐릭터
    ttTargetArea = 4, //< 타켓 에어리어(TargetArea)
    ttArea = 5 //< 에어리어(Area)
};


inline bool isValid(TargetingType tt)
{
    return (ttNoneTarget <= tt) && (tt <= ttArea);
}


inline bool isAreaTargetingType(TargetingType tt)
{
    return tt == ttSelfArea || tt == ttTargetArea || tt == ttArea;
}


template <typename T>
inline TargetingType toTargetingType(T value)
{
    return static_cast<TargetingType>(static_cast<uint8_t>(value));
}


/**
 * @enum AvailableTarget
 * 시전가능 대상
 */
enum AvailableTarget
{
	atNoneTaget = 0,
    atAll,
    atSelf,
	atParty,
	atGuild,
	atGuildOrParty,
	atMoster,
};



template <typename T>
inline AvailableTarget toAvailableTarget(T value)
{
	return static_cast<AvailableTarget>(static_cast<uint8_t>(value));
}


/**
 * @enum ExceptTarget
 * 효과 제외 체크
 */
enum ExceptTarget
{
    etNoneTaget = 0,   // 제외 대상 없음
    etSelf = 1, // 자신 제외
    etParty = 2, // 파티 제외
    etGuild = 3, // 길드 제외
    etPartyOrGuild = 4, // 파티 또는 길드 제외
    etNpcOrMonster = 5, // Npc 또는 몬스터
    etNpcOrMosterOrSelf = 6, // Npc or 몬스터 or 자신   
};


template <typename T>
inline ExceptTarget toExceptTarget(T target)
{
    return static_cast<ExceptTarget>(static_cast<uint8_t>(target));
}


/**
 * @enum TargetDirection
 * 상대방 방향 체크
 */
enum TargetDirection
{
    tdNone,
    tdFront,   // 전방
    tdRear,    // 후방
};


inline bool shouldCheckTargetDirection(TargetDirection td)
{
    return (tdFront == td) || (tdRear == td);
}

template <typename T>
inline TargetDirection toTargetDirection(T target)
{
    return static_cast<TargetDirection>(static_cast<uint8_t>(target));
}


/**
 * @enum TargetOrientation
 * 상대방 방향 체크
 */
enum TargetOrientation
{
    toNone,     // 없음
    toFront,    // 전방
    toRear,     // 후방
};


inline bool shouldCheckTargetOrientation(TargetOrientation to)
{
    return (toFront == to) || (toRear == to);
}


template <typename T>
inline TargetOrientation toTargetOrientation(T target)
{
    return static_cast<TargetOrientation>(static_cast<uint8_t>(target));
}


/**
 * @enum EffectRangeDirection
 * 효과 범위 방향
 */
enum EffectRangeDirection
{
    erdNone = 0, //< 체크 안함
    erdForward = 1, //< 전방 체크
    erdBackward = 2, //< 후방 체크
};


inline bool shouldCheckEffectDirection(EffectRangeDirection td)
{
    return (erdForward == td) || (erdBackward == td);
}


template <typename T>
inline EffectRangeDirection toEffectRangeDirection(T value)
{
    return static_cast<EffectRangeDirection>(static_cast<uint8_t>(value));
}


/**
 * @enum EffectStackCategory
 */
enum EffectStackCategory
{
    escNone = 0,
    escCare = 1, //< 치료
    escRecovery = 2, //< 회복
    escShied = 3, //< 쉴드
    escMagic = 4, //< 마법
    escPhysical = 5, //< 타격 
    escIncrease = 6, //< 증가
    escDecrease = 7, //< 감소
    escPoison = 8, //< 독
    escHoly = 9, //< 신성  
    escCurse = 10, //< 저주
    escBodyReinforce = 11, //< 육체 강화 
    escBodyWeaken= 12, //< 육체 약화
    escMentalReinfoce = 13, //< 정신력 강화 
    escMentalWeaken = 14, //< 정신력 약화 
    escCrowdControl = 15, //< 상태이상 계열
    escSeal = 16, //< 봉인
    escSpeedUp = 17, //< 속도 향상
    escSpeedDown = 18, //< 속도 감소 계열
    escHide = 19, //< 은신
    escAbsorb = 20, //< 흡수
    escStun = 21, //< 스턴
    escMutation = 22, //< 변이 해제 
    escAttackImpossibe = 23, // 공격 불가 계열
    escSkipMezCheck = 24, // 메즈 체크 검사를 안하도록한다(!!! 좀 특별한)
}; 

template <typename T>
inline EffectStackCategory toEffectStackCategory(T value) {
    return static_cast<EffectStackCategory>(static_cast<uint8_t>(value));
}

/**
 * @enum EffectScriptType
 * TODO: 영문 수정
 */
enum EffectScriptType
{
    estUnknown = 0, //< 없음
    estHpUp = 1, //< HP 회복
    estHpCapacityUp = 2, //< HP 최대치 증가
    estHpDown = 3, //< HP 감소
    estHpCapacityDown = 4, //< HP 최대치 감소
    estMpUp = 5, //< MP 회복
    estMpCapacityUp = 6, //< MP 최대치 증가
    estMpDown = 7, //< MP 감소
    estMpCapacityDown = 8, //< MP 최대치 감소
    estHpAbsorb = 9, //< HP 흡수
    estMpAbsorb = 10, //< MP 흡수
    estHpGive = 11, //< HP 주다
    estMpGive = 12, //< MP 주다
    estHpMpUp = 13, //< HP MP 증가
    estHpShield = 14, //< HP 쉴드
    estMpShield= 15, //< MP 쉴드
    estKnockback = 16, //< 넉백 ( 날라감 )
    estDash = 17, //< 대쉬
    estShackles = 18, //< 이동불가 
    estAttackImpossible = 19, //< 공격 불가능
    estFighterAttackImpossible = 20, // 전사 공격 불가능
    estRogueAttackImpossible = 21, // 도적 공격 불가능
    estMageAttackImpossible = 22, // 법사 공격 불가능
    estSleep = 23, //< 잠들게 하기
    estMutation = 24, //< 상대방을 변이
    estParalyze = 25, //< 마비
    estPanic = 26, //< 공포
    estCombatChange = 27, //< 전투전환
    estPeaceChange = 28, //< 병화전환
    estMinAttackUp = 29,
    estMinAttackDown = 30,
    estMaxAttackUp = 31,
    estMaxAttackDown = 32,
    estFrenzy = 33, //< 광분
    estTransformation = 34, //< 변신
    estHide = 35, // 은신
    estExecution = 36, //< 집행
    estBindRecall = 37, //< 바인드 리콜
    estPlayerRecall = 38, //< 플레이어 소환
    estStrengthUp = 39, //< 힘
    estDexterityUp = 40,  //< 민첩
    estIntellectUp = 41, //< 지혜
    estEnergyUp = 42, //< 활력
    estPhysicalUp = 43, //< 물리
    estMagicUp = 44, //< 마법
    estHitRateUp = 45, //< 명중율  
    estPhysicalCriticalRateUp = 46, //< 클리티컬 확율
    estBlockRateUp = 47, // 막기 확율
    estDodgeRateUp = 48, // 피하기 확율
    estDefenceUp = 49, // 방어력
    estLightUp =50, // 빛속성
    estDarkUp = 51, // 어둠속성
    estFireUp= 52, // 불속성
    estIceUp = 53, // 얼음속성
    estAllAttributeUp = 54, // 모든 속성
    estLightResistUp = 55, // 빛속성 저항
    estDarkResistUp = 56, // 어둠속성 저항
    estFireResistUp= 57, // 불속속성 저항
    estIceResistUp = 58, // 얼음속성 저항
    estAllAttributeResistUp = 59, // 모든속성 저항
    estStrengthDown = 60, //< 힘 
    estDexterityDown = 61,  //< 민첩
    estIntellectDown = 62, //< 지혜
    estEnergyDown = 63, //< 활력
    estPhysicalDown = 64, //< 물리
    estMagicDown = 65,        //< 마법
    estHitRateDown = 66,
    estPhysicalCriticalRateDown = 67,
    estBlockRateDown = 68,
    estDodgeRateDown = 69,
    estDefenceDown = 70,
    estLightDown =71,
    estDarkDown = 72,
    estFireDown= 73,
    estIceDown = 74,
    estAllAttributeDown = 75,
    estLightResistDown = 76,
    estDarkResistDown = 77,
    estFireResistDown = 78,
    estIceResistDown = 79,
    estAllAttributeResistDown = 80,
    estMoveSpeedUp = 81,
    estMoveSpeedDown = 82,
    estCastTimeUp = 83, // < 캐스팅 딜레이 업
    estCastTimeDown = 84, // < 캐스팅 딜레이 다운
    estBuildingPerHp = 85, // 건물 HP% 증가
    estDisableMagic = 86,
    estInvincible = 87,
    estStun = 88,
    estRelease = 89, // 해제 
    estRevive = 90,
    estSpawnProtection = 91, // 무적
    estDirectThreatUp = 92, // NPC용 어그로 수치 증가 NPC용
    estDirectThreatDown = 93, // NPC용 어그로 수치 다운 Target 
    estThreatUp = 94, // 플레이어용 특정시간 결과값을 %로 증가
    estThreatDown = 95, // 플레이어용 특정시간 결과값을 %로 감소
    estThreatApplyAvoid = 96, // NPC용 특정 플레이어에게 특정확율로 Threat발생 
    estForceVictim = 97, // Npc용 특정 시간동안 자기를 공격하도록 한다.
    estMagicCriticalRateUp = 98, //< 클리티컬 확율
    estMagicCriticalRateDown = 99,

    estGuildGameMoneyBonus = 100, // 길드 게임머니로 간다.
    estExpBonus = 101, // 경험치 보너스
    estMountSpeedUp = 102, // 탈것 이동 속도 증가  
    estStoreItemSale = 103, // 상점 이용시 가격 세일 
    estArenaPointBonus = 104, // 투기장 포인트 업
    estReviveTimeDown = 105, // 부활시간 감소

    estBackStep = 106,
    estBoundary
};

template <typename T>
inline EffectScriptType toEffectScriptType(T value) 
{
    return static_cast<EffectScriptType>(static_cast<uint8_t>(value));
}


inline bool isValid(EffectScriptType type)
{
    return estUnknown < type && type < estBoundary;
}

inline bool canImmune(EffectScriptType type)
{
    return estKnockback == type || estShackles == type || estStun == type || 
        estParalyze == type || estSleep == type || estMutation == type;
}

inline bool isKnockbackScript(EffectScriptType type)
{
    return estKnockback == type;
}


inline bool isDashScript(EffectScriptType type)
{
    return estDash == type;
}


inline bool isExecutionScript(EffectScriptType type)
{
    return estExecution == type;
}

inline bool isDownPointTypeScript(EffectScriptType type)
{
    return estHpDown == type || estMpDown == type;
}

inline bool isHpSkillEffect(EffectScriptType type)
{
    return estHpDown == type;
}

inline bool isMpSkillEffect(EffectScriptType type)
{
    return estMpDown == type;
}

inline bool isHpUpDownSkillEffect(EffectScriptType type)
{
    return estHpDown == type || estHpUp == type;
}

inline bool isMpUpDownSkillEffect(EffectScriptType type)
{
    return estMpDown == type || estMpUp == type;
}

inline bool isDirectThreatEffect(EffectScriptType type)
{
    return estDirectThreatDown == type || estDirectThreatUp == type;
}


inline bool isReviveEffect(EffectScriptType type)
{
    return estRevive == type;
}


inline bool isBuffSkillType(EffectScriptType type)
{
    switch(type)
    {
    case estHpUp:
    case estHpCapacityUp:
    case estMpUp:
    case estHpAbsorb:
    case estMpAbsorb:
    case estMpCapacityUp:
    case estHpGive:
    case estMpGive:
    case estHpMpUp:
    case estHpShield:
    case estMpShield:
    case estMinAttackUp:
    case estMaxAttackUp:
    case estStrengthUp:
    case estDexterityUp:
    case estIntellectUp:
    case estEnergyUp:
    case estPhysicalUp:
    case estMagicUp:
    case estHitRateUp:
    case estPhysicalCriticalRateUp:
    case estMagicCriticalRateUp:
    case estBlockRateUp:
    case estDodgeRateUp:
    case estDefenceUp:
    case estLightUp:
    case estDarkUp:
    case estFireUp:
    case estIceUp:
    case estAllAttributeUp:
    case estLightResistUp:
    case estDarkResistUp:
    case estFireResistUp:
    case estIceResistUp:
    case estAllAttributeResistUp:
    case estCastTimeDown:
    case estSpawnProtection:
    case estInvincible:
    case estFrenzy:
    case estTransformation:
    case estHide:
    case estMoveSpeedUp:
        return true;
    }
    return false;
}

inline bool isDebuffSkillType(EffectScriptType type)
{
    switch(type)
    {
    case estHpDown:
    case estHpCapacityDown:
    case estMpDown:
    case estMpCapacityDown:
    case estKnockback:
    case estShackles:
    case estAttackImpossible:
    case estFighterAttackImpossible:
    case estRogueAttackImpossible:
    case estMageAttackImpossible:
    case estSleep:
    case estMutation:
    case estParalyze:
    case estPanic:
    case estMinAttackDown:
    case estMaxAttackDown:
    case estStrengthDown:
    case estDexterityDown:
    case estIntellectDown:
    case estEnergyDown:
    case estPhysicalDown:
    case estMagicDown:
    case estHitRateDown:
    case estPhysicalCriticalRateDown:
    case estMagicCriticalRateDown:
    case estBlockRateDown:
    case estDodgeRateDown:
    case estDefenceDown:
    case estLightDown:
    case estDarkDown:
    case estFireDown:
    case estIceDown:
    case estAllAttributeDown:
    case estLightResistDown:
    case estDarkResistDown:
    case estFireResistDown:
    case estIceResistDown:
    case estAllAttributeResistDown:
    case estMoveSpeedDown:
    case estCastTimeUp:
    case estDisableMagic:
    case estStun:
        return true;
    }
    return false;
}


inline bool isCrowdControlSkillType(EffectScriptType type)
{
    switch (type) {
    case estKnockback:
    case estShackles:
    case estSleep:
    case estMutation:
    case estParalyze:
    case estPanic:
    case estStun:
        return true;
    }
    return false;
}


inline bool isUtilityType(EffectScriptType type)
{
    switch (type) {
    case estHpCapacityUp:
    case estHpCapacityDown:
    case estMpCapacityUp:
    case estMpCapacityDown:
    case estHpShield:
    case estMpShield:
    case estAttackImpossible:
    case estFighterAttackImpossible:
    case estRogueAttackImpossible:
    case estMageAttackImpossible:
    case estMinAttackUp:
    case estMinAttackDown:
    case estMaxAttackUp:
    case estMaxAttackDown:
    case estFrenzy:
    case estTransformation:
    case estHide:
    case estBindRecall:
    case estPlayerRecall:
    case estStrengthUp:
    case estDexterityUp:
    case estIntellectUp:
    case estEnergyUp:
    case estPhysicalUp:
    case estMagicUp:
    case estHitRateUp:
    case estPhysicalCriticalRateUp:
    case estMagicCriticalRateUp:
    case estBlockRateUp:
    case estDodgeRateUp:
    case estDefenceUp:
    case estLightUp:
    case estDarkUp:
    case estFireUp:
    case estIceUp:
    case estAllAttributeUp:
    case estLightResistUp:
    case estDarkResistUp:
    case estFireResistUp:
    case estIceResistUp:
    case estAllAttributeResistUp:
    case estMoveSpeedUp:
    case estCastTimeUp:
    case estBuildingPerHp:
    case estDisableMagic:
    case estSpawnProtection:
    case estInvincible:
    case estRelease:
    case estRevive:
    case estBackStep:
        return true;
    }
    return false;
}

/**
 * @enum EffectApplyNum
 * 이펙트 적용 숫자
 */
enum EffectApplyNum
{
    eanInvalidCount = -1,
    eanStart = 0,
    eanEffect_1 = eanStart,
    eanEffect_2,
    eanCount,
};


inline bool isValid(EffectApplyNum num)
{
    return (eanStart <= num && num < eanCount);
}


template <typename T>
inline EffectApplyNum toEffectApplyNum(T value)
{
    return static_cast<EffectApplyNum>(static_cast<uint8_t>(value));
}


typedef sne::srpc::RArray<int32_t, eanCount> EffectValues;

/**
 * @enum UseTargetStatusType
 * 스탯 대상자
 */
enum UseTargetStatusType
{
    utstNone,
    utstCaster,
    utstCastee,
};

template <typename T>
inline UseTargetStatusType toUseTargetStatusType(T value)
{
    return static_cast<UseTargetStatusType>(static_cast<uint8_t>(value));
}


/**
 * @enum DebuffBuffEffectInfo
 * 버프 디버프 정보
 */
struct DebuffBuffEffectInfo
{
    DataCode code_;
    bool isCaster_;
    sec_t startTime_;
    EffectValues effectValues_;

    DebuffBuffEffectInfo(DataCode code = invalidDataCode, bool isCaster = true,
        sec_t startTime = 0, int32_t value1 = 0, int32_t value2 = 0) :
        code_(code),
        isCaster_(isCaster),
        startTime_(startTime)
    {
        effectValues_[eanEffect_1] = value1;
        effectValues_[eanEffect_2] = value2;
    }

    bool operator<(const DebuffBuffEffectInfo& rhs) const {
        if (code_ == rhs.code_) {
            return isCaster_ < rhs.isCaster_;
        }
        return code_ < rhs.code_;
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & code_ & isCaster_ & startTime_ & effectValues_;
    }
};

typedef sne::srpc::RSet<DebuffBuffEffectInfo> DebuffBuffEffectInfoSet;
} //namespace gideon {



namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::EffectScriptType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::EffectScriptType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::EffectScriptType>(value);
    return lhs;
}

}} // namespace sne { namespace core {