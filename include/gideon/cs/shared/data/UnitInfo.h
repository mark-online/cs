#pragma once

#include "Coordinate.h"
#include <sne/srpc/RpcContainers.h>

namespace gideon {

/**
 * @enum UnitType
 * 유닛(기체) 종류
 */
enum UnitType
{
    utUnknown = -1,

    utRobot = 0, ///< 메카닉 기체
    utShip = 1, ///< 함선

    utCount
};


inline bool isValid(UnitType unitType)
{
    return (utUnknown < unitType) && (unitType < utCount);
}


//template <typename Stream>
//inline Stream& operator&(Stream& lhs, UnitType& rhs) {
//    if (lhs.isOutput()) {
//        lhs << static_cast<int8_t>(rhs);
//    }
//    else {
//        int8_t value;
//        lhs >> value;
//        rhs = static_cast<UnitType>(value);
//    }
//    return lhs;
//}



typedef uint32_t UnitId;
const UnitId invalidUnitId = 0;

inline bool isValidUnitId(UnitId unitId)
{
    return unitId != invalidUnitId;
}


/**
 * @struct UnitInfo
 * 유닛 정보
 * TODO: 플레이어 생성시 position 값을 DB에 저장하고,
 *       사용자 정보 로딩시 position_을 DB에서 읽어온다
 */
struct UnitInfo
{
    UnitId unitId_;
    UnitType unitType_;
    Position position_;

    explicit UnitInfo(UnitId unitId = invalidUnitId,
        UnitType unitType = utUnknown) :
        unitId_(unitId),
        unitType_(unitType) {}

    void reset() {
        unitId_ = invalidUnitId;
        unitType_ = utUnknown;
        position_.reset();
    }

    bool isValid() const {
        return isValidUnitId(unitId_) && gideon::isValid(unitType_);
    }

    bool isRobot() const {
        return utRobot == unitType_;
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & unitId_ & unitType_ & position_;
    }
};


typedef sne::srpc::RHashMap<UnitId, UnitInfo> UnitInfoMap;

} // namespace gideon {
