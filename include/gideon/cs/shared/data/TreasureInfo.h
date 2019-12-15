#pragma once

#include "EntityInfo.h"
#include "ItemInfo.h"
#include "Money.h"
#include "LevelInfo.h"


namespace gideon {

typedef DataCode TreasureCode;

const TreasureCode invalidTreasureCode= 0;

inline bool isValidTreasureCode(TreasureCode code)
{
	return getCodeType(code) == ctTreasure;
}

/***
 * struct TreasureInfo
 ***/
struct TreasureInfo : public EntityInfo
{
    TreasureCode treasureCode_;
	bool isOpen_;

	explicit TreasureInfo(ObjectType objectType = otInvalid,
		ObjectId treasureId = invalidObjectId) :
		EntityInfo(objectType, treasureId)
		{}

	void reset() {
		EntityInfo::reset();
        treasureCode_ = invalidDataCode;
        isOpen_ = false;
	}

	bool isValid() const {
		return EntityInfo::isValid();
	}

	template <typename Stream>
	void serialize(Stream& stream) {
		EntityInfo::serialize(stream);
		stream & treasureCode_ & isOpen_;
	}
};


} // namespace gideon {
