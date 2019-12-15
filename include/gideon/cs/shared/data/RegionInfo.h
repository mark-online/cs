#pragma once

#include "Code.h"
#include <cassert>

namespace gideon {

/**
 * @enum RegionType
 * 지역 타입
 */
enum RegionType
{
    rtUnknown = 0, //< 없음
    rtCharacterSpawn = 1, //< 캐릭터 스폰 지역
    rtGrave = 2, //< 무덤 지역
    rtNpcSpawn = 3, //< 몬스터 스폰 지역
    rtRandomDungeon = 4, //< 랜덤 던전 스폰 지역
    rtPortal = 5, //< 포탈 입구/출구 지역(존 이동, 안전 지역)
    rtSafeRegion = 6, //< 안전 지역(공격 스킬 사용 금지 지역)
	rtHarvest = 7, //< 채집 지역
	rtTreasure = 8, //< 보물
    rtObelisk = 9, //< 오벨리스크(텔레포트)
    rtCaoGrave = 10, //< 범죄자 스폰지역
    rtProbe = 11, //< 탐사지역
    rtBlueTeamSpawn = 12, //< 투기장 블루팀 스폰 지역
    rtRedTeamSpawn = 13, //< 투기장 레드팀 스폰 지역
    // 사용 안함 = 14,
    // 사용 안함 = 15,
    rtRegionSeparator = 16, //< 지역 구분 용
    rtHelpTrigger = 17, //< 도움말 트리거
    rtWorldEvent = 18, //< 월드 이벤트
    rtBoundary
};


template <typename T>
inline RegionType toRegionType(T value)
{
    return static_cast<RegionType>(static_cast<uint8_t>(value));
}


inline bool isValid(RegionType rt)
{
    return (rtUnknown < rt) && (rt < rtBoundary);
}


inline bool isSpawnable(RegionType rt)
{
    return (rtNpcSpawn == rt) || (rtHarvest == rt) || (rtTreasure == rt) ||
        (rtObelisk == rt) || (rtRandomDungeon == rt);
}


inline bool isTeleportable(RegionType rt)
{
    return (rt == rtPortal) && (rt == rtObelisk);
}


/// 공격 스킬 사용 금지 구역?
inline bool isNoAttackableRegion(RegionType rt)
{
    return (rt == rtCharacterSpawn) || (rt == rtGrave) || (rt == rtSafeRegion) || (rt == rtPortal);
}


/**
 * 지역 코드
 * - Category(1B) | RegionType(1B) | 인덱스(2B)
 */
typedef DataCode RegionCode;
const RegionCode invalidRegionCode = invalidDataCode;
const uint16_t maxRegionCodeIndex = (std::numeric_limits<uint16_t>::max)();


/// RegionCode를 만든다
inline RegionCode makeRegionCode(RegionType regionType, uint16_t index)
{
    return getMinGideonCode(ctRegion) + (regionType << 16) + index;
}


inline uint32_t getRegionCodeIndex(RegionCode rc)
{
    assert(getCodeType(rc) == ctRegion);
    return static_cast<uint32_t>(rc & 0x0000FFFF);
}


inline RegionType getRegionType(RegionCode rc)
{
    assert(getCodeType(rc) == ctRegion);
    return static_cast<RegionType>((rc & 0x00FF0000) >> 16);
}


/// RegionCode를 파싱한다
inline bool parseRegionCode(RegionType& regionType, uint32_t& index, RegionCode rc)
{
    const CodeType codeType = getCodeType(rc);
    if (codeType != ctRegion) {
        return false;
    }

    regionType = getRegionType(rc);
    index = getRegionCodeIndex(rc);
    return true;
}


/// 유효한 지역 코드인가?
inline bool isValidRegionCode(RegionCode rc)
{
    RegionType regionType = rtUnknown;
    uint32_t index = 0;
    if (! parseRegionCode(regionType, index, rc)) {
        return false;
    }
    return isValid(regionType) && (index > 0);
}

const RegionCode globalRegionCode = makeRegionCode(rtNpcSpawn, maxRegionCodeIndex);

} // namespace gideon {
