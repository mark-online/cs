#pragma once

#include "CreatureInfo.h"
#include <cassert>

namespace gideon {

/**
 * NPC 코드
 * - Category(1B) | NpcType(1B) | Level(2B)
 */
typedef DataCode NpcCode;
const NpcCode invalidNpcCode = invalidDataCode;


/**
 * @enum NpcType
 * NPC 형태
 */
enum NpcType
{
    ntUnknown = 0,

    ntNpc = 1, //< NPC
    ntMonster = 2, //< Monster
    ntStaticNpc = 3, //< 고정 NPC(편지함, 경매장)
    ntCritter = 4, //< 가축류 NPC(쥐, 닭, 젖소 등)
    ntHireableNpc = 5, //< 고용 가능 NPC(건물 경비병)
    ntInvader = 6, //< 침략자(monster)

    ntBoundary
};


template <typename T>
NpcType toNpcType(T value)
{
    return static_cast<NpcType>(static_cast<uint8_t>(value));
}


inline bool isValid(NpcType npcType)
{
    return (ntUnknown < npcType) && (npcType < ntBoundary);
}

inline bool isNpc(NpcType npcType)
{
    return (ntNpc == npcType) || (ntStaticNpc == npcType) || (ntCritter == npcType) || (ntHireableNpc == npcType); 
}

inline bool isMonster(NpcType npcType)
{
    return (ntMonster == npcType) || (ntInvader == npcType);
}

inline bool isStaticNpc(NpcType npcType)
{
    return ntStaticNpc == npcType;
}

inline bool isCritter(NpcType npcType)
{
    return ntCritter == npcType;
}

inline bool isHireableNpc(NpcType npcType)
{
    return ntHireableNpc == npcType;
}

inline bool isInvader(NpcType npcType)
{
    return ntInvader == npcType;
}


/// NpcCode를 만든다
inline NpcCode makeNpcCode(NpcType npcType, uint16_t index)
{
    return getMinGideonCode(ctNpc) + (npcType << 16) + index;
}


inline NpcType getNpcType(NpcCode sc)
{
    assert(getCodeType(sc) == ctNpc);
    return static_cast<NpcType>((sc & 0x00FF0000) >> 16);
}


inline uint16_t getNpcCodeIndex(NpcCode sc)
{
    assert(getCodeType(sc) == ctNpc);
    return static_cast<uint16_t>(sc & 0x0000FFFF);
}


/// NpcCode를 파싱한다
inline bool parseNpcCode(NpcType& npcType, uint16_t& index, NpcCode sc)
{
    const CodeType codeType = getCodeType(sc);
    if (codeType != ctNpc) {
        return false;
    }

    npcType = getNpcType(sc);
    index = getNpcCodeIndex(sc);
    return true;
}


/// 유효한 NPC 코드인가?
inline bool isValidNpcCode(NpcCode sc)
{
    NpcType npcType = ntUnknown;
    uint16_t index = 0;
    if (! parseNpcCode(npcType, index, sc)) {
        return false;
    }
    return isValid(npcType) && (index > 0);
}


inline ObjectType toObjectType(NpcCode npcCode)
{
    if (isValidNpcCode(npcCode)) {
        switch (getNpcType(npcCode)) {
        case ntNpc:
        case ntStaticNpc:
        case ntCritter:
        case ntHireableNpc:
            return otNpc;
        case ntMonster:
        case ntInvader:
            return otMonster;
        default:
            assert(false && "invalid NpcType");
        }
    }
    return otInvalid;
}


/**
 * @enum ReactiveType
 * (반응 거리 내에 있는 엔티티에 대한) AI 반응 성향
 * - bit-mask
 */
enum AiReactiveType
{
    artUnknown = -1,

    artDefensive = 0, //< 비선공
    artAggressive = 1, //< 선공
    artChaoAggressive = 2, //< 선공+카오에 적대 반응
    artFlee = 3, //< 적대 회피
    artNothing = 4, //< 아무런 반응도 하지 않음

    artBoundary
};


inline bool isValid(AiReactiveType value)
{
    return (artUnknown < value) && (value < artBoundary);
}


/// 먼저 반응?
inline bool isProactive(AiReactiveType value)
{
    return (artAggressive <= value) && (value <= artFlee);
}

/// 반응 후 반응?
inline bool isReactive(AiReactiveType value)
{
    return artDefensive == value;
}


inline bool isAggressive(AiReactiveType value)
{
    return (value == artAggressive) || (value == artChaoAggressive);
}


inline bool isAggressiveToChao(AiReactiveType value)
{
    return value == artChaoAggressive;
}


inline bool shouldFlee(AiReactiveType value)
{
    return value == artFlee;
}


/// 반격할 수 있는가?
inline bool canStrikeBack(AiReactiveType value)
{
    return isAggressive(value) || isReactive(value);
}


/**
 * @struct NpcInfo
 * NPC 기본 정보
 */
struct NpcInfo : CreatureInfo
{
    NpcCode npcCode_;
    CreatureLevel level_;

    explicit NpcInfo(ObjectType objectType = otInvalid,
        ObjectId npcId = invalidObjectId) :
        CreatureInfo(objectType, npcId),
        npcCode_(invalidNpcCode) {}

    void reset() {
        CreatureInfo::reset();
        npcCode_ = invalidNpcCode;
        level_ = clInvalidLevel;
    }

    bool isValid() const {
        return CreatureInfo::isValid() && gideon::isValidNpcLevel(level_) &&
            isValidNpcCode(npcCode_) && isNpcOrMonster();
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        CreatureInfo::serialize(stream);
        stream & npcCode_ & level_;
    }
};


/**
 * @struct FullNpcInfo
 * NPC 전체 정보
 */
struct FullNpcInfo : NpcInfo
{
    explicit FullNpcInfo(ObjectType objectType = otInvalid,
        ObjectId npcId = invalidObjectId) :
        NpcInfo(objectType, npcId) {}

    void reset() {
        NpcInfo::reset();
    }

    bool isValid() const {
        return NpcInfo::isValid();
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        NpcInfo::serialize(stream);
    }
};

} // namespace gideon {
