#pragma once

#include "ObjectInfo.h"
#include "Code.h"
#include "Time.h"
#include "InventoryInfo.h"

namespace gideon 
{

typedef DataCode VehicleCode;

const VehicleCode invalidVehicleCode = 0;

inline bool isValidVehicleCode(VehicleCode code)
{
	if (! isVehicleType(getCodeType(code))) {
		return false;
	}
	return true;
}


typedef DataCode HarnessCode;

const HarnessCode invalidHarnessCode = 0;

inline bool isValidHarnessCode(HarnessCode code)
{
	if (! isHarnessType(getCodeType(code))) {
		return false;
	}
	return true;
}


/***
 * @struct HarnessInfo
 ***/
struct HarnessInfo
{
	HarnessCode harnessCode_;
	sec_t expireTime_;

	explicit HarnessInfo(HarnessCode harnessCode = invalidVehicleCode, sec_t expireTime = 0) :
		harnessCode_(harnessCode),
		expireTime_(expireTime)
	{
	}

	void reset() {
		harnessCode_ = invalidVehicleCode;
	}

	bool isValid() const {
		return isValidHarnessCode(harnessCode_);
	}

	template <typename Stream>
	void serialize(Stream& stream) {
		stream & harnessCode_ & expireTime_;
	}
};



/**
 * @struct EntityVehicleInfo
 * 필드 상에서 탈 것의 외형정보
 */
struct EntityVehicleInfo
{
	VehicleCode vehicleCode_; 
	HarnessCode harnessCode_;

	EntityVehicleInfo() :
		vehicleCode_(invalidVehicleCode),
		harnessCode_(invalidHarnessCode) {}
    
	void reset() {
		vehicleCode_ = invalidVehicleCode;
		harnessCode_ = invalidHarnessCode;
    }

	bool isValid() const {
		return isValidVehicleCode(vehicleCode_);
	}

    template <typename Stream>
	void serialize(Stream& stream) {
        stream & vehicleCode_ & harnessCode_;
	}
};



/***
 * @struct VehicleInfo
 ***/
struct VehicleInfo
{
	ObjectId objectId_;
	VehicleCode vehicleCode_;
	sec_t birthDay_;
	uint8_t peakAge_;
	HarnessInfo harnessInfo_;

	explicit VehicleInfo(ObjectId objectId = invalidObjectId,
		VehicleCode vehicleCode = invalidVehicleCode,
		const HarnessInfo& harnessInfo = HarnessInfo()) :
		objectId_(objectId),
		vehicleCode_(vehicleCode),
		harnessInfo_(harnessInfo)
	{
	}

	void reset() {
		objectId_ = invalidObjectId;
		vehicleCode_ = invalidVehicleCode;
	}

	uint32_t getAge() const {
		sec_t ageSec = getTime() - birthDay_;
		const sec_t oneDay = 60 * 60 * 24;
		return static_cast<uint32_t>(ageSec / oneDay);
	}

	float getCurrentSpeed(float orgSpeed, float apply_speed_value) const {
		uint32_t currentAge = getAge();
		if (currentAge <= peakAge_) {
			return orgSpeed + (apply_speed_value * currentAge);
		}
		return orgSpeed + (apply_speed_value * peakAge_);
	}

	template <typename Stream>
	void serialize(Stream& stream) {
		stream & objectId_ & vehicleCode_ & birthDay_ & peakAge_ & harnessInfo_;
	}
};


typedef sne::srpc::RMap<ObjectId, VehicleInfo> VehicleInfoMap;


/***
 * @struct VehicleInventory
 ***/
struct VehicleInventory
{
	VehicleInfoMap infos_;
	ObjectId selectId_;
	HarnessInfo commonHarnessInfo_;
	InventoryInfo inventory_;

public:
	VehicleInventory() {
		reset();
	}

	void reset() {
		infos_.clear();
	}

	bool isExist(ObjectId VehicleId) const {
		return infos_.find(VehicleId) != infos_.end();
	}


	bool remove(ObjectId id) {
		if (! isExist(id)) {
			return false;
		}
		if (selectId_ == id) {
			selectId_ = invalidObjectId;
		}
		infos_.erase(id);
		return true;
	}

	bool add(const VehicleInfo& info) {
		if (isExist(info.objectId_)) {
			return false;
		}
		
		infos_.insert(VehicleInfoMap::value_type(info.objectId_, info));
		return true;
	}

	const VehicleInfo* getVehicleInfo(ObjectId VehicleId) const {
		VehicleInfoMap::const_iterator pos = infos_.find(VehicleId);
		if (pos != infos_.end()) {
			return &(*pos).second;
		}
		return nullptr;
	}

	VehicleInfo* getVehicleInfo(ObjectId VehicleId) {
		VehicleInfoMap::iterator pos = infos_.find(VehicleId);
		if (pos != infos_.end()) {
			return &(*pos).second;
		}
		return nullptr;
	}

	const VehicleInfo* getCurrentVehicleInfo() const {
		VehicleInfoMap::const_iterator pos = infos_.find(selectId_);
		if (pos != infos_.end()) {
			return &(*pos).second;
		}
		return nullptr;
	}

	VehicleInfo* getCurrentVehicleInfo() {
		VehicleInfoMap::iterator pos = infos_.find(selectId_);
		if (pos != infos_.end()) {
			return &(*pos).second;
		}
		return nullptr;
	}

	const VehicleInfoMap& getVehicleInfoMap() const {
		return infos_;
	}

	template <typename Stream>
	void serialize(Stream& stream) {
		stream & infos_ & selectId_ & commonHarnessInfo_  & inventory_;
	}

};


} // namespace gideon {