#pragma once

#include "EntityInfo.h"
#include "RegionInfo.h"
#include "Money.h"

namespace gideon {

/// 오벨리스크 이용료
const GameMoney teleportFee = 10; // 10 copper


typedef DataCode ObeliskCode;
const ObeliskCode invalidObeliskCode = invalidDataCode;

inline bool isValidObeliskCode(ObeliskCode code)
{
    return getCodeType(code) == ctObelisk;
}


inline ObeliskCode makeObeliskCode(uint16_t index)
{
    return getMinGideonCode(ctObelisk) + index;
}


/// FYI: 현재는 오벨리스크가 하나 밖에 없으므로 하드 코딩!!!
const ObeliskCode uniqueObeliskCode = makeObeliskCode(ctObelisk);


/***
 * struct ObeliskInfo
 ***/
struct ObeliskInfo : public EntityInfo
{
	explicit ObeliskInfo(ObjectType objectType = otInvalid,
		ObjectId obeliskId = invalidObjectId) :
		EntityInfo(objectType, obeliskId) {}

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

} // namespace gideon {