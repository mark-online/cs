#pragma once

#include "Code.h"
#include <cassert>

namespace gideon {

/**
 * @enum WorldType
 */
enum WorldType
{
    wtUnknown = -1,
    wtDummy = 0, //< 아무런 의미도 없음 (던전 등에서 사용)
    wtBeginner = 1, //< 초보자 용 월드
    wtEmpire = 2, //< 제국령 월드
    wtOuter = 3, //< 아우터 월드

    wtBoundary
};


inline bool isValid(WorldType value)
{
    return (wtUnknown < value) && (value < wtBoundary);
}


/// 제국령/아우터 월드로 갈 경우 초보자 보호를 해제한다
inline bool shouldReleaseBeginnerProtection(WorldType value)
{
    return (value == wtEmpire) || (value == wtOuter);
}

/**
 * @enum MapType
 * 맵 타입
 */
enum MapType
{
    mtUnknown = 0, //< 없음
    mtGlobalWorld = 1, //< 글로벌 월드
    mtInstanceDundeon = 2, //< 인스턴스 던전
    mtRandomDundeon = 3, //< 랜덤 던전
    mtArena = 4, //< 투기장

    mtBoundary
};


template <typename T>
inline MapType toMapType(T value)
{
    return static_cast<MapType>(static_cast<uint8_t>(value));
}


inline bool isValid(MapType mt)
{
    return (mtUnknown < mt) && (mt < mtBoundary);
}


inline bool isDungeon(MapType mt)
{
    return (mtInstanceDundeon == mt) || (mtRandomDundeon == mt);
}


inline bool isWorldMap(MapType mt)
{
    return mtGlobalWorld == mt;
}


inline bool isArenaMap(MapType mt)
{
    return mtArena == mt;
}

inline bool canDrawMap(MapType mt)
{
    return isWorldMap(mt) || (mt == mtArena);
}

/// 채팅 채널을 가질 수 있는가?
inline bool hasChatChannel(MapType mt)
{
    return isWorldMap(mt) || isDungeon(mt);
}

/**
 * 맵 코드
 * - Category(1B) | MapType(1B) | 인덱스(2B)
 */
typedef DataCode MapCode;
const MapCode invalidMapCode = invalidDataCode;


/// MapCode를 만든다
inline MapCode makeMapCode(MapType mapType, uint32_t index)
{
    return getMinGideonCode(ctMap) + (mapType << 16) + index;
}


inline uint32_t getMapCodeIndex(MapCode mc)
{
    assert(getCodeType(mc) == ctMap);
    return static_cast<uint32_t>(mc & 0x0000FFFF);
}


inline MapType getMapType(MapCode mc)
{
    assert(getCodeType(mc) == ctMap);
    return static_cast<MapType>((mc & 0x00FF0000) >> 16);
}


/// MapCode를 파싱한다
inline bool parseMapCode(MapType& mapType, uint32_t& index, MapCode mc)
{
    const CodeType codeType = getCodeType(mc);
    if (codeType != ctMap) {
        return false;
    }

    mapType = getMapType(mc);
    index = getMapCodeIndex(mc);
    return true;
}


/// 유효한 맵 코드인가?
inline bool isValidMapCode(MapCode mc)
{
    MapType mapType = mtUnknown;
    uint32_t index = 0;
    if (! parseMapCode(mapType, index, mc)) {
        return false;
    }
    return isValid(mapType) && (index > 0);
}


/**
 * @struct MapInfo
 * 맵 기본 정보
 */
struct MapInfo
{
    MapCode mapCode_;

    int32_t originX_;
    int32_t originY_;
    int32_t originZ_;
    int32_t xSectorCount_; //< x축 섹터 갯수(수평)
    int32_t ySectorCount_; //< y축 섹터 갯수(깊이, 전방/후방)
    int32_t zSectorCount_; //< z축 섹터 갯수(높이)
    uint16_t sectorLength_; //< 섹터 크기(미터)
    uint8_t aggressiveLevelDiff_; //< 선공 레벨 차이

    MapInfo() {
        reset();
    }

    void reset() {
        mapCode_ = invalidMapCode;
        originX_ = 0;
        originY_ = 0;
        originZ_ = 0;
        xSectorCount_ = 0;
        ySectorCount_ = 0;
        zSectorCount_ = 0;
        sectorLength_ = 0;
        aggressiveLevelDiff_ = 0;
    }

    bool isValid() const {
        return isValidMapCode(mapCode_) && isValidCoordinates();
    }

    bool isValidCoordinates() const {
        return ((xSectorCount_ >= 3) && (ySectorCount_ >= 3) && (zSectorCount_ >= 3)) &&
            ((xSectorCount_ % 2) != 0) && ((ySectorCount_ % 2) != 0) && ((zSectorCount_ % 2) != 0) &&
            (sectorLength_ > 0);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & mapCode_ & originX_ & originY_ & originZ_ &
            xSectorCount_ & ySectorCount_ & zSectorCount_ & sectorLength_ & aggressiveLevelDiff_;
    }
};


} // namespace gideon {
