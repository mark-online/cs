#pragma once

#include "ObjectInfo.h"
#include "Coordinate.h"

namespace gideon {

/**
 * @struct EntityInfo
 * 월드 상에 존재하는 엔티티 정보
 */
struct EntityInfo : GameObjectInfo
{
    ObjectPosition position_;

    explicit EntityInfo(ObjectType objectType = otInvalid,
        ObjectId objectId = invalidObjectId) :
        GameObjectInfo(objectType, objectId) {}

    void reset() {
        GameObjectInfo::reset();
        position_.reset();
    }

    bool isValid() const {
        return GameObjectInfo::isValid();
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        GameObjectInfo::serialize(stream);
        stream & position_;
    }
};

} // namespace gideon {
