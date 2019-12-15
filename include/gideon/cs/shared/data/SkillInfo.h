#pragma once

#include "EffectInfo.h"
#include "StatusInfo.h"
#include "CharacterClass.h"
#include <sne/srpc/RpcContainers.h>
#include <cassert>

namespace gideon {

/// 1000을 기준으로 한다.
const uint32_t defaultSkillDelayPercent = 1000;

/**
 * @enum CheckMezType
 * 메즈류 스킵체크
 */
enum CheckMezType
{
    cmtUnknown = 0,
    cmtStun = 1,
    cmtSleep = 2,
    cmtParalyse = 3,
    cmtMutation = 4,
};


inline bool isValid(CheckMezType type) 
{
    return cmtStun <= type && type <= cmtMutation;
}

template <typename T>
inline CheckMezType toCheckMezType(T value)
{
    return static_cast<CheckMezType>(static_cast<uint8_t>(value));
}


/**
 * @enum SkillTableType
 * 스킬 참조 테이블
 */
enum SkillTableType
{
    sttUnknown = 0,
    sttActivePlayer,
    sttPassivePlayer,
    sttActiveNpc,
    sttActiveItem,
    sttActiveSo,
    sttGuild,
    sttCount,
};


inline bool isValid(SkillTableType type)
{
    return sttUnknown < type && type < sttCount;
}


inline bool isActiveSkillTable(SkillTableType type)
{
    return sttActivePlayer == type || sttActiveNpc == type ||
        sttActiveItem == type || sttActiveSo == type;
}

/**
 * @enum SkillEffectNum
 * 이펙트 숫자
 */
enum SkillEffectNum
{
    senEffect_1 = 0,
    senEffect_2,
    senEffect_3,
    senCount
};


inline bool isValid(SkillEffectNum value)
{
    return (senEffect_1 <= value) && (value <= senEffect_3);
}



typedef uint8_t SkillLevel;
const SkillLevel invalidSkillLevel = 0;
const SkillLevel minSkillLevel = 1;


/**
 * 스킬 인덱스 인덱스
 */
typedef uint16_t SkillIndex;
const SkillIndex invalidSkillIndex = 0;

typedef sne::core::HashMap<SkillIndex, SkillLevel> SpellPackageLevelMap;

inline bool isValidSkillIndex(SkillIndex spi)
{
    return spi > invalidSkillIndex;
}

template <typename T>
inline SkillIndex toSkillIndex(T value)
{
    return static_cast<SkillIndex>(value);
}


/**
 * 스킬 코드
 * - Category(1B) | SkillIndex(2B) | SkillTableType(4Bit) | Level(4bit)
 */
typedef DataCode SkillCode;
const SkillCode invalidSkillCode = invalidDataCode;
const SkillCode anySkillCode = invalidSkillCode;


typedef sne::srpc::RVector<SkillCode> SkillCodes;

/// SkillCode를 만든다
inline SkillCode makeSkillCode(SkillTableType skillTableType, SkillIndex spi, SkillLevel level)
{  
    return getMinGideonCode(ctSkill) + (skillTableType << 20) + (spi << 4) + level;
}


inline uint32_t makeSkillTableTypeAndIndexKey(SkillTableType skillTableType, SkillIndex spi)
{
    return (skillTableType << 16) + (spi);
}


inline SkillIndex getSkillIndex(SkillCode sc)
{
    return static_cast<SkillIndex>((sc & 0x000FFFF0) >> 4);
}


inline SkillTableType getSkillTableType(SkillCode sc)
{
    return static_cast<SkillTableType>((sc & 0x00F00000) >> 20);
}


inline SkillLevel getSkillLevel(SkillCode sc)
{
    return static_cast<SkillLevel>(sc & 0x0000000F);
}


/// SkillCode를 파싱한다
inline bool parseSkillCode(SkillTableType& skillTableType, SkillIndex& spi, SkillLevel& level, SkillCode sc)
{
    const CodeType codeType = getCodeType(sc);
    if (! isValid(codeType)) {
        return false;
    }

    skillTableType = getSkillTableType(sc);
    if (! isValid(skillTableType)) {
        return false;
    }

    spi = getSkillIndex(sc);
    level = getSkillLevel(sc);
    return true;
}


/// 유효한 스킬 코드인가?
inline bool isValidSkillCode(SkillCode sc)
{
    SkillIndex spi = invalidSkillIndex;
    SkillTableType skillTableType = sttUnknown;
    SkillLevel level = invalidSkillLevel;
    if (! parseSkillCode(skillTableType, spi, level, sc)) {
        return false;
    }
    return isValidSkillIndex(spi) && isValid(skillTableType);
}


/// Creature가 배운 스킬 정보
typedef sne::srpc::RSet<SkillCode> CreatureSkills;


inline bool isValid(const CreatureSkills& skills)
{
    for (const SkillCode code : skills) {
        if (! isValidSkillCode(code)) {
            return false;
        }
    }
    return true;
}


/**
 * @enum CastType
 * 시전 형태
 */
enum CastType
{
    catDefault = 0, //< 디폴트
    catDirect = 1, //< 바로 시전
    catProjectile = 2, //< 프로젝타일(발사체) 시전
    catConcentration = 3, //< 정신 집중

    catBoundary
};


inline bool isValid(CastType ct)
{
    return (catDefault <= ct) && (ct < catBoundary);
}


inline bool isProjectileCastSkill(CastType ct)
{
    return ct == catProjectile;
}


inline bool isDirectCastSkill(CastType ct)
{
    return ct == catDirect;
}


inline bool isConcentrationSkill(CastType ct)
{
    return ct == catConcentration;
}


template <typename T>
inline CastType toCastType(T value)
{
    return static_cast<CastType>(static_cast<uint8_t>(value));
}

/**
 * @enum SkillType
 * 스킬 계열
 */
enum SkillType
{
    sktGeneral = 0, //< 일반
    sktAttackMagic = 1, //< 공격 마법계열
    sktBuffMagic = 2, //< 버프 마법계열(버프 마법 효능 올리는 스킬들 등등)
    sktDebuffMagic = 3, //< 디버프 마법계열(디버프 마법 효능 올리는 스킬들 등등)
    sktAttackMelee = 4, //< 공격 전사계열
    sktBuffMelee = 5, //< 버프 전사계열
    sktDebuffMelee = 6, //< 디버프 전사계열
    sktAttackRange = 7, //< 공격 궁수계열
    sktBuffRange = 8, //< 버프 궁수계열
    sktDebuffRange = 9, //< 디버프 궁수계열

    sktBoundary
};

template <typename T>
inline SkillType toSkillType(T value)
{
    return static_cast<SkillType>(static_cast<uint8_t>(value));
}


inline bool isValid(SkillType skt)
{
    return (sktGeneral <= skt) && (skt < sktBoundary);
}

inline bool isGeneralSkillType(SkillType skt)
{
    return sktGeneral == skt;
}


inline bool isMagicSkillType(SkillType skt)
{
    return (sktAttackMagic == skt) || (sktBuffMagic == skt) ||
        (sktDebuffMagic == skt);
}


inline bool isAttackSkillType(SkillType skt)
{
    return (sktAttackMagic == skt) || (sktAttackMelee == skt) ||
        (sktAttackRange == skt);
}


inline bool isDebuffSkillType(SkillType skt) 
{
    return (sktDebuffMagic == skt) || (sktDebuffMelee == skt) ||
        (sktDebuffRange == skt); 
}


inline bool isAttackOrDebuffSkillType(SkillType skt)
{
    return isAttackSkillType(skt) || isDebuffSkillType(skt);
}


inline bool isBuffSkillType(SkillType skt) 
{
    return (sktBuffMagic == skt) || (sktBuffMelee == skt) ||
        (sktBuffRange == skt); 
}


inline bool isPhysicalAttack(SkillType skt)
{
    return (sktAttackMelee == skt) || (sktAttackRange == skt);
}

// 최대값의 퍼센트
inline bool isPercentByBuf(SkillType type)
{
    switch (type)
    {
    case sktBuffMagic:
    case sktBuffMelee:
    case sktBuffRange:
        return true;
    }
    return false;
}

// 현재값의 퍼센트
inline bool isPercentByAttackAndDebuf(SkillType type)
{
    switch (type)
    {
    case sktAttackMagic:
    case sktDebuffMagic:
    case sktAttackMelee:
    case sktDebuffMelee:
    case sktAttackRange:
    case sktDebuffRange:
        return true;
    }
    return false;

}


inline bool isMagicalAttack(SkillType skt)
{
    switch (skt) {
    case sktAttackMagic:
        return true;
    }
    return false;
}


/**
 * @enum UseType
 */
enum UseType
{
    utPassive = 1,
    utActive = 2
};


template <typename T>
inline UseType toUseType(T value)
{
    return static_cast<UseType>(static_cast<uint8_t>(value));
}


inline bool isValid(UseType value)
{
    return (utPassive <= value) && (value <= utActive);
}

inline bool isTargetingSkill(TargetingType tt)
{
    return (ttSelf == tt) || (ttSelfArea == tt) || (ttTarget == tt) ||
        (ttTargetArea == tt);
}


inline bool isAreaSkill(TargetingType tt)
{
    return ttArea == tt;
}


inline bool isAreaEffectSkill(TargetingType tt)
{
    return (ttSelfArea == tt) || (ttTargetArea == tt) || (ttArea == tt);
}


inline bool isToIndividualEffectSkill(TargetingType tt)
{
    return (ttSelf == tt) || (ttTarget == tt);
}


inline bool isTargetCastSkill(TargetingType tt)
{
	return (ttSelf == tt) || (ttTarget == tt) || (ttTargetArea == tt);
}


/**
 * @enum SkillUseableState
 * 스킬 사용 가능한 상태
 */
enum SkillUseableState
{
    susInvalid = -1,
    susAlaways = 0,
    susPeace = 1,
    susCombat = 2,
    susNotCast = 3,
    susHidden = 4,
    /// TODO: 현재 사용안함.
    // susSelfBufCheck = 4,
    // susEnemyBufCheck = 5,
};


inline bool isValid(SkillUseableState value)
{
    return (susAlaways <= value) && (value <= susNotCast);
}


template <typename T>
inline SkillUseableState toSkillUseableState(T value)
{
    return static_cast<SkillUseableState>(static_cast<uint8_t>(value));
}


/**
 * @enum SkillTransitionState
 * 스킬 상태 변화
 */
enum SkillTransitionState
{
    stsInvalid = -1,
    stsNone = 0,
    stsPeace = 1,
    stsCombat = 2,
};


inline bool isValid(SkillTransitionState value)
{
    return (stsNone <= value) && (value <= stsCombat);
}


template <typename T>
inline SkillTransitionState toSkillTransitionState(T value)
{
    return static_cast<SkillTransitionState>(static_cast<uint8_t>(value));
}


/**
 * @enum keepConcentration
 * 스킬 유지 최대치 감소
 */
enum keepConcentration
{
	kcNone = 0,
	kcCp = 1,
};


inline bool shouldKeepConcentration(keepConcentration kc)
{
	return kcCp == kc;
}


template <typename T>
inline keepConcentration tokeepConcentration(T value)
{
	return static_cast<keepConcentration>(static_cast<uint8_t>(value));
}


/***
 * @enum EffectType
 ***/
enum EffectType 
{
    etNone = 0,
    etAttack = 1,
    etSpell = 2,
};


inline bool isUseAttackPower(EffectType type)
{
    return etAttack == type;
}

inline bool isUseSpellPower(EffectType type)
{
    return etSpell == type;
}

inline bool isEffective(EffectType type)
{
    return isUseAttackPower(type) || isUseSpellPower(type);
}

template <typename T>
inline EffectType toEffectType(T value)
{
    return static_cast<EffectType>(static_cast<uint8_t>(value));
}

/**
 * @struct SkillResult
 * 스킬 사용 결과
 */
struct SkillResult
{
    SkillCode skillCode_;
    bool isDefenced_;   
    bool isCriticalDamage_;

    SkillResult(SkillCode skillCode = invalidSkillCode,
        bool successDeffence = false, bool occurrenceCriticalDamage = false) :
        skillCode_(skillCode),
        isDefenced_(successDeffence),
        isCriticalDamage_(occurrenceCriticalDamage) {}

    template <typename Stream>
    void serialize(Stream& stream) {
        const bool isInput = stream.isInput();
        stream & skillCode_ & isDefenced_;
        if (! isDefenced_) {
            stream & isCriticalDamage_;
        }
        else {
            if (isInput) {
                isCriticalDamage_ = false;
            }
        }
    }
};

/**
 * @struct CheckStatTargetType
 */
enum CheckStatTargetType
{
    csttNone,
    csttCaster,
    csttCastee,
};

inline bool isValid(CheckStatTargetType type)
{
    return csttNone <= type && type <= csttCastee;
}


template <typename T>
inline CheckStatTargetType toCheckStatTargetType(T value)
{
    return static_cast<CheckStatTargetType>(static_cast<uint8_t>(value));
}


/**
 * @enum SkillPoint
 */
enum SkillPoint
{
    spUnknown = -1,
    spMin = 0,
    spLevelStepupRewardPoint = 3,
    spOneCreatureLevelSkillPoint = 30,
    spMax = SHRT_MAX
};


inline bool isValid(SkillPoint sp)
{
    return (spMin <= sp) && (sp <= spMax);
}


template <typename T>
inline SkillPoint toSkillPoint(T value)
{
    const int32_t point = static_cast<int32_t>(value);
    const SkillPoint sp = static_cast<SkillPoint>(point);
    assert(isValid(sp));
    return sp;
}


inline SkillPoint getLearnSkillPoint(CharacterClass myClass, CharacterClass learnClass,
    SkillPoint needSkillPoint)
{
    if (! isCommonClass(learnClass)) {
        if (toFirstClass(myClass) != toFirstClass(learnClass)) {
            return toSkillPoint(needSkillPoint * 2);
        }
    } 

    return needSkillPoint;
}


/**
 * @struct CharacterSkillManager
 * 케릭터가 익힐수 있는 시킬들을 관리 한다(!!! 장비 슬롯에 장착된 스킬은 제외)
 */
class CharacterSkillManager
{
    enum { maxLearnSkillLevel = 5 };

public:
    typedef sne::core::HashMap<uint32_t, SkillCode> SkillIndexMap;

    void initialize(const CreatureSkills& skills) {
        for (SkillCode skillCode : skills) {
            updateSkill(skillCode);
        }
    }

    void initialize(const SkillCodes& skills) {
        for (SkillCode skillCode : skills) {
            updateSkill(skillCode);
        }
    }

    void finalize() {
        skillIndexMap.clear();
    }
   
    SkillCode generateSkillCode(SkillTableType skillTableType, SkillIndex index) const {
        const SkillCode skillCode = getSkillCode(skillTableType, index);
        if (! isValidSkillCode(skillCode)) {
            return makeSkillCode(skillTableType, index, minSkillLevel);
        }

        const SkillLevel skillLevel = getSkillLevel(skillCode);
        if (skillLevel >= maxLearnSkillLevel) {
            return invalidSkillCode;
        }
        return makeSkillCode(skillTableType, index, skillLevel + 1);
    }

    void updateSkill(SkillCode skillCode) {
        if (! isValidSkillCode(skillCode)) {
            return;
        }
        const SkillLevel skillLevel = getSkillLevel(skillCode);
        const SkillIndex index = getSkillIndex(skillCode);
        const SkillTableType skillTableType = getSkillTableType(skillCode);
        const uint32_t key  = makeKey(skillTableType, index);
        if (skillLevel >= maxLearnSkillLevel) {
            skillIndexMap[key] = makeSkillCode(skillTableType, index, maxLearnSkillLevel);
        } 
        else {
            skillIndexMap[key] = skillCode;
        }
    }

    void removeSkill(SkillTableType skillTableType, SkillIndex index) {
        const uint32_t key  = makeKey(skillTableType, index);
        skillIndexMap.erase(key);
    }

    void removeSkill(SkillCode skillCode) {
        const SkillIndex index = getSkillIndex(skillCode);
        const SkillTableType skillTableType = getSkillTableType(skillCode);

        const uint32_t key  = makeKey(skillTableType, index);
        skillIndexMap.erase(key);
    }

public:
    bool isLearned(SkillCode skillCode) const {
        const SkillCode learnedSkillCode = getCurrentSkillCode(getSkillTableType(skillCode), getSkillIndex(skillCode));
        if (! isValidSkillCode(learnedSkillCode)) {
            return false;
        }
        return getSkillLevel(learnedSkillCode) >= getSkillLevel(skillCode);
    }

    SkillCode getCurrentSkillCode(SkillTableType skillTableType, SkillIndex index) const {
        return getSkillCode(skillTableType, index);
    }

    SkillLevel getCurrentSkillLevel(SkillTableType skillTableType, SkillIndex index) const {
        return getSkillLevel(getSkillCode(skillTableType, index));
    }

    const SkillIndexMap& getSkillIndexMap() const {
        return skillIndexMap;
    }

private:
    SkillCode getSkillCode(SkillTableType skillTableType, SkillIndex index) const {
        const uint32_t key  = makeKey(skillTableType, index);
        SkillIndexMap::const_iterator pos = skillIndexMap.find(key);
        if (pos != skillIndexMap.end()) {
            return (*pos).second;
        }
        return invalidSkillCode;
    }

    uint32_t makeKey(SkillTableType skillTableType, SkillIndex spi) const
    {  
        return (skillTableType << 16) + spi;
    }


private:
    SkillIndexMap skillIndexMap;
};



} // namespace gideon {
