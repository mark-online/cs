#pragma once

#include "EntityInfo.h"

namespace gideon {

/**
 * @struct DungeonInfo
 * 던전 정보 (인스턴스 던전, 랜덤 던전)
 **/
struct DungeonInfo : EntityInfo
{
    MapCode mapCode_;

    explicit DungeonInfo(ObjectType objectType = otInvalid,
        ObjectId objectId = invalidObjectId) :
        EntityInfo(objectType, objectId),
        mapCode_(invalidMapCode) {}

    void reset() {
        EntityInfo::reset();
        mapCode_ = invalidMapCode;
    }

    bool isValid() const {
        if (! EntityInfo::isValid()) {
            return false;
        }
        return isDungeon(objectType_) && isValidMapCode(mapCode_) &&
            isDungeon(getMapType(mapCode_));
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        EntityInfo::serialize(stream);
        stream & mapCode_;
    }
};

} // namespace gideon
