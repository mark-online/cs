#pragma once

#include <gideon/cs/Common.h>
#include <sne/srpc/RpcContainers.h>
#include <sne/core/stream/Streamable.h>

namespace gideon {

/**
 * @enum ObjectType
 * 코드 종류
 */
enum ObjectType
{
    otInvalid = -1,

    otPc = 0, //< 캐릭터(플레이어)
    otNpc = 1, //< NPC
    otMonster = 2, //< Mob
    // 사용 안함//otSummon = 3,

    otItem = 4,
	otGraveStone = 5,

    otDungeon = 6,

	otHarvest = 7, //< 채집물

	otTreasure = 8, //< 보물 상자

    otAnchor = 9, //< 설치물  

    otBuilding = 10, //< 설치물  

    otObelisk = 11, //< 오벨리스크

    otDevice = 12, //< (작동 가능한) 장치

    otBoundary
};


inline bool isValid(ObjectType ot)
{
    return (otInvalid < ot) && (ot < otBoundary);
}


inline bool isPlayer(ObjectType ot)
{
    return otPc == ot;
}


inline bool isNpc(ObjectType ot)
{
    return otNpc == ot;
}


inline bool isPlayerOrNpc(ObjectType ot)
{
    return otPc == ot || otNpc == ot;
}


inline bool isMonster(ObjectType ot)
{
	return otMonster == ot;
}


inline bool isGraveStone(ObjectType ot)
{
	return otGraveStone == ot;
}


inline bool isCreature(ObjectType ot)
{
    return (otPc <= ot) && (ot <= otMonster);
}


inline bool isStaticObject(ObjectType ot)
{
    return (otGraveStone <= ot) && (ot <= otDevice);
}


inline bool isNpcOrMonster(ObjectType ot)
{
    return (otNpc == ot) || (otMonster == ot);
}


inline bool isDungeon(ObjectType ot)
{
    return otDungeon == ot;
}


inline bool isDevice(ObjectType ot)
{
    return otDevice == ot;
}


inline bool isHarvest(ObjectType ot)
{
	return otHarvest == ot;
}


inline bool isTreasure(ObjectType ot)
{
	return otTreasure == ot;
}


inline bool isAnchor(ObjectType ot)
{
    return otAnchor == ot;
}


inline bool isBuilding(ObjectType ot)
{
    return otBuilding == ot;
}


inline bool isAnchorOrBuilding(ObjectType ot) 
{
    return isAnchor(ot) || isBuilding(ot);
}


inline bool isObelisk(ObjectType ot)
{
    return otObelisk == ot;
}


/// 플레이어만 비석을 세울 수 있다
inline bool canStandGraveStone(ObjectType ot)
{
    return otPc == ot;
}


inline const char* toString(ObjectType ot)
{
    switch (ot) {
    case otPc:
        return "PC";
    case otNpc:
        return "NPC";
    case otMonster:
        return "Monster";
    case otItem:
        return "Item";
	case otGraveStone:
		return "GraveStone";
	case otHarvest:
		return "Harvest";
	case otTreasure:
		return "Treasure";
    case otAnchor:
        return "Anchor";
    case otBuilding:
        return "Building";
    case otObelisk:
        return "Obelisk";
	case otDevice:
		return "Device";
    }
    assert(false);
    return "Unknown";
}


/**
 * 월드 상의 객체 ID
 * - 주의! 다른 오브젝트 간에는 ID가 중복될 수 있다.
 *   즉, 월드 상에서 유일한 값이 아님!
 */
typedef uint64_t ObjectId;
const ObjectId invalidObjectId = 0;

inline bool isValidObjectId(ObjectId objId)
{
    return invalidObjectId != objId;
}


typedef sne::srpc::RSet<ObjectId> ObjectIdSet;


/**
 * @class GameObjectInfo
 * 월드 상의 모든 객체 기본 정보
 */
struct GameObjectInfo
{
    ObjectType objectType_;
    ObjectId objectId_;

    explicit GameObjectInfo(ObjectType objectType = otInvalid,
        ObjectId objectId = invalidObjectId) :
        objectType_(objectType),
        objectId_(objectId) {}

    void reset() {
        objectType_ = otInvalid;
        objectId_ = invalidObjectId;
    }

    bool isValid() const {
        return gideon::isValid(objectType_) && isValidObjectId(objectId_);
    }

    bool isCreature() const {
        return gideon::isCreature(objectType_);
    }

    bool isStaticObject() const {
        return gideon::isStaticObject(objectType_);
    }

    bool isPlayer() const {
        return gideon::isPlayer(objectType_);
    }

    bool isHarvest() const {
        return gideon::isHarvest(objectType_);
    }

    bool isTreasure() const {
        return gideon::isTreasure(objectType_);
    }

	bool isGraveStone() const {
		return gideon::isGraveStone(objectType_);
	}

    bool isNpcOrMonster() const {
        return gideon::isNpcOrMonster(objectType_);
    }

    bool isNpc() const {
        return gideon::isNpc(objectType_);
    }

    bool isMonster() const {
        return gideon::isMonster(objectType_);
    }

    bool isAnchor() const {
        return gideon::isAnchor(objectType_);
    }

    bool isBuilding() const {
        return gideon::isBuilding(objectType_);
    }

    bool isAnchorOrBuilding() const {
        return isAnchor() || isBuilding();
    }

    bool operator==(const GameObjectInfo& rhs) const {
        return (objectType_ == rhs.objectType_) && (objectId_ == rhs.objectId_);
    }

    bool operator<(const GameObjectInfo& rhs) const {
        if (objectType_ == rhs.objectType_) {
            return objectId_ < rhs.objectId_;
        }
        return objectType_ < rhs.objectType_;
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & objectType_ & objectId_;
    }

public:
    static const GameObjectInfo& null() {
        static const GameObjectInfo nullInfo;
        return nullInfo;
    }
};


typedef sne::srpc::RVector<GameObjectInfo> GameObjects;

} // namespace gideon {


namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::ObjectType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::ObjectType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::ObjectType>(value);
    return lhs;
}

}} // namespace sne { namespace core {
