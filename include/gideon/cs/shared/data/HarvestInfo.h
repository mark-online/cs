#pragma once

#include "EntityInfo.h"

namespace gideon {

typedef DataCode HarvestCode;

const HarvestCode invalidHarvestCode = 0;

inline bool isValidHarvestCode(HarvestCode code)
{
    return getCodeType(code) == ctHarvest;
}


/**
 * @struct HarvestInfo
 * 
 **/
struct HarvestInfo : EntityInfo
{
    explicit HarvestInfo(ObjectType objectType = otInvalid,
        ObjectId objectId = invalidObjectId) :
        EntityInfo(objectType, objectId) {}

    void reset() {
        EntityInfo::reset();
    }

    bool isValid() const {
        return EntityInfo::isValid();         
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        EntityInfo::serialize(stream);
    }
};


/**
 * @struct FullHarvestInfo
 * 
 **/
struct FullHarvestInfo : HarvestInfo
{
    uint8_t maxCount_;
	uint8_t count_;

    explicit FullHarvestInfo(ObjectType objectType = otInvalid,
        ObjectId objectId = invalidObjectId) :
        HarvestInfo(objectType, objectId) {}

    void reset() {
        HarvestInfo::reset();
        count_ = 0;
    }

    bool isValid() const {
        if (! HarvestInfo::isValid()) {
            return false;
        }
		return count_ > 0 && maxCount_ > 0;
    }
};

} // namespace gideon {