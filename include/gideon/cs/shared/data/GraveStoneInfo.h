#pragma once

#include "ItemInfo.h"
#include "UnionGraveStoneName.h"
#include "Money.h"
#include "LootInvenItemInfo.h"

namespace gideon {

/**
 * @struct GraveStoneInfo
 **/
struct GraveStoneInfo : EntityInfo
{
	UnionGraveStoneName graveStoneName_;

    explicit GraveStoneInfo(ObjectType objectType = otInvalid,
        ObjectId objectId = invalidObjectId) :
        EntityInfo(objectType, objectId) {}

    void reset() {
        EntityInfo::reset();
        graveStoneName_.reset();
    }

    bool isValid() const {
        if (! EntityInfo::isValid()) {
            return false;
        }
		return isGraveStone() &&  graveStoneName_.isValid();
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        EntityInfo::serialize(stream);
        stream & graveStoneName_;
    }
};


} // namespace gideon