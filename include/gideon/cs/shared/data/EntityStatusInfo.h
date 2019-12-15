#pragma once

#include "CreatureStatusInfo.h"
#include "EffectInfo.h"

namespace gideon {


/**
 * @struct EntityStatusInfo
 * 필드 상에서 작동 오브젝트 정보를 표시하기 위해 사용
 */
struct EntityStatusInfo
{
private:
	HitPoints hitPoints_;
	CreatureShields creatureShields_;
	DebuffBuffEffectInfoSet debuffBuffEffectInfos_;
	//BuildingOwnerInfo ownerInfo_;

public:
    GameObjectInfo targetInfo_;

	explicit EntityStatusInfo(const GameObjectInfo& targetInfo = GameObjectInfo::null()) :
        targetInfo_(targetInfo) {}

	void reset() {
		hitPoints_.reset();
		creatureShields_.reset();
        debuffBuffEffectInfos_.clear();
		//ownerInfo_.reset();
		targetInfo_.reset();
	}

	void set(const HitPoints& hitPoints, const DebuffBuffEffectInfoSet& debuffBuffEffectInfos,
		const CreatureShields& creatureShields) {
		assert(targetInfo_.isCreature());
		hitPoints_ = hitPoints;
		creatureShields_ = creatureShields;
		debuffBuffEffectInfos_ = debuffBuffEffectInfos;
	}

	//void set(const HitPoints& hitPoints, const AnchorOwnerInfo& ownerInfo) {
	//	assert(targetInfo_.isAnchorOrBuilding());
	//	hitPoints_ = hitPoints;
	//	ownerInfo_ = ownerInfo;
	//}

	void set(const HitPoints& hitPoints) {
		assert(targetInfo_.isStaticObject());
		hitPoints_ = hitPoints;
	}

	const HitPoints& getHitPoints() const {
		return hitPoints_;
	}
	
	const CreatureShields& getCreatureShields() const {
		assert(targetInfo_.isCreature());
		return creatureShields_;
	}
	
    const DebuffBuffEffectInfoSet& getDebuffBuffEffectInfoSet() const {
        assert(targetInfo_.isCreature());
        return debuffBuffEffectInfos_;
    }
	
	//const AnchorOwnerInfo& getAnchorOwnerInfo() const {
	//	assert(targetInfo_.isAnchorOrBuilding());
	//	return ownerInfo_; 
	//}


	template <typename Stream>
	void serialize(Stream& stream) {
		const bool isInput = stream.isInput();
		if (isInput) {
			reset();
		}

		stream & targetInfo_;
		if (targetInfo_.isCreature()) {
			stream & hitPoints_ & creatureShields_ & debuffBuffEffectInfos_;
		}
		//else if (targetInfo_.isAnchorOrBuilding()) {
		//	stream & hitPoints_ &  ownerInfo_;
		//}
		else if (targetInfo_.isStaticObject()) {
			stream & hitPoints_;
		}
	}	
};

} // namespace gideon {
