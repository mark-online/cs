#pragma once

#include "ObjectInfo.h"
#include "Code.h"

namespace gideon 
{

typedef DataCode GliderCode;

const GliderCode invalidGliderCode = 0;

inline bool isValidGliderCode(GliderCode code)
{
	if (! isGliderType(getCodeType(code))) {
		return false;
	}
	return true;
}

/***
 * @struct GliderInfo
 ***/
struct GliderInfo
{
	ObjectId objectId_;
	GliderCode gliderCode_;
	uint32_t durability_;

	explicit GliderInfo(ObjectId objectId = invalidObjectId,
		GliderCode gliderCode = invalidGliderCode, uint32_t durability = 0) :
		objectId_(objectId),
		gliderCode_(gliderCode),
		durability_(durability)
	{
	}

	void reset() {
		objectId_ = invalidObjectId;
		gliderCode_ = invalidGliderCode;
		durability_ = 0;
	}

	void decreaseDurability(uint32_t value) {
		if (durability_ > value) {
			durability_ -= value;
		}
		else {
			durability_ = 0;
		}
	}

	void repaireDurability(uint32_t maxTime) {
		durability_ = maxTime;
	}

	template <typename Stream>
	void serialize(Stream& stream) {
		stream & objectId_ & gliderCode_ & durability_;
	}
};

typedef sne::srpc::RMap<ObjectId, GliderInfo> GliderInfoMap;

/***
 * @struct GliderInventory
 ***/
struct GliderInventory
{
	GliderInfoMap infos_;
	ObjectId selectId_;

	GliderInventory() {
		reset();
	}

	void reset() {
		infos_.clear();
	}

	bool isExist(ObjectId gliderId) const {
		return infos_.find(gliderId) != infos_.end();
	}

	bool setSelect(ObjectId selectGliderId) {
		if (! isExist(selectGliderId)) {
			return false;
		}
		selectId_ = selectGliderId;
		return true;
	}

	bool remove(ObjectId id) {
		if (! isExist(id)) {
			return false;
		}
		if (selectId_ == invalidObjectId) {
			selectId_ = invalidObjectId;
		}
		infos_.erase(id);
		return true;
	}

	bool add(const GliderInfo& info) {
		if (isExist(info.objectId_)) {
			return false;
		}
		
		infos_.insert(GliderInfoMap::value_type(info.objectId_, info));
		return true;
	}

	const GliderInfo* getGliderInfo(ObjectId gliderId) const {
		GliderInfoMap::const_iterator pos = infos_.find(gliderId);
		if (pos != infos_.end()) {
			return &(*pos).second;
		}
		return nullptr;
	}

	GliderInfo* getGliderInfo(ObjectId gliderId) {
		GliderInfoMap::iterator pos = infos_.find(gliderId);
		if (pos != infos_.end()) {
			return &(*pos).second;
		}
		return nullptr;
	}

	const GliderInfo* getCurrentGliderInfo() const {
		GliderInfoMap::const_iterator pos = infos_.find(selectId_);
		if (pos != infos_.end()) {
			return &(*pos).second;
		}
		return nullptr;
	}

	GliderInfo* getCurrentGliderInfo() {
		GliderInfoMap::iterator pos = infos_.find(selectId_);
		if (pos != infos_.end()) {
			return &(*pos).second;
		}
		return nullptr;
	}


	const GliderInfoMap& getGliderInfoMap() const {
		return infos_;
	}

	template <typename Stream>
	void serialize(Stream& stream) {
		stream & infos_ & selectId_;
	}

};

} // namespace gideon  {