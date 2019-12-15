#pragma once

#include "CharacterInfo.h"
#include "ItemInfo.h"
#include "GraveStoneInfo.h"
#include "DungeonInfo.h"
#include "HarvestInfo.h"
#include "TreasureInfo.h"
#include "AnchorInfo.h"
#include "ObeliskInfo.h"
#include "BuildingInfo.h"
#include "DeviceInfo.h"
#include "CharacterTitleInfo.h"

namespace gideon {


/**
 * @struct EntityMovementInfo
 * Entity의 이동 관련 정보
 */
struct EntityMovementInfo
{
public:
    bool isMoving_; ///< destination_으로 이동 중인가(goToward)?
    float speed_;
    ObjectPosition destination_; ///< 이동 목적지

    EntityMovementInfo() :
        isMoving_(false) {}

    void reset() {
        isMoving_ = false;
        destination_.reset();
        speed_ = 0.0f;
    }

    bool isValid() const {
        return true;
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        const bool isInput = stream.isInput();
        stream & isMoving_ & speed_;
        if (isMoving_) {
            stream & destination_;
        }
        else {
            if (isInput) {
                destination_.reset();
            }
        }
    }
};


/**
 * @struct MoreCharacterInfo
 * 필드 상에서 캐릭터 정보를 표시하기 위해 사용
 */
struct MoreCharacterInfo : CharacterInfo
{
    EntityMovementInfo movementInfo_;
    CreatureEquipments equipments_;
    float scale_; // 외형 사이즈
    GuildName guildName_;
    GuildMarkCode guildMarkCode_;
	EntityVehicleInfo entityVehicleInfo_;
	DataCode gliderCode_;
    CharacterTitleCode selectTitleCode_;

    explicit MoreCharacterInfo(ObjectId characterId = invalidObjectId,
        GuildMarkCode guildMarkCode = invalidGuildMarkCode) :
        CharacterInfo(characterId),
        guildMarkCode_(guildMarkCode),
        selectTitleCode_(invalidCharacterTitleCode) {}

    void reset() {
        CharacterInfo::reset();
        selectTitleCode_ = invalidCharacterTitleCode;
        movementInfo_.reset();
		entityVehicleInfo_.reset();
        equipments_.reset();
        scale_ = 0.0f;
        guildName_.clear();
        guildMarkCode_ = invalidGuildMarkCode;
		gliderCode_ = invalidGliderCode;
    }

    bool isValid() const {
        return CharacterInfo::isValid() && movementInfo_.isValid() &&
            equipments_.isValid();
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        const bool isInput = stream.isInput();
        CharacterInfo::serialize(stream);
        stream & movementInfo_ & equipments_ & scale_ & selectTitleCode_;
        if (isValidGuildId(guildId_)) {
            stream & guildName_ & guildMarkCode_;
        }
        else {
            if (isInput) {
                guildName_.clear();
                guildMarkCode_ = invalidGuildMarkCode;
            }
        }

		if (stateInfo_.hasState(cstVehicleMount)) {
			stream & entityVehicleInfo_;
		}
		else {
			if (isInput) {
				entityVehicleInfo_.reset();
			}
		}

		if (stateInfo_.hasState(cstGliderMount) ) {
			stream & gliderCode_;
		}
		else {
			if (isInput) {
				gliderCode_ = invalidGliderCode;
			}
		}
    }
};


/**
 * @struct MoreNpcInfo
 * 필드 상에서 NPC 정보를 표시하기 위해 사용
 */
struct MoreNpcInfo : NpcInfo
{
    EntityMovementInfo movementInfo_;
    bool isAggressive_; //< 공격적인가? (이동 속도를 높혀야 함)
    float scale_; // 외형 사이즈
    sec_t startSpawnTime_;

    explicit MoreNpcInfo(ObjectType objectType = otInvalid,
        ObjectId npcId = invalidObjectId) :
        NpcInfo(objectType, npcId),
        isAggressive_(false),
        startSpawnTime_(0) {}

    void reset() {
        NpcInfo::reset();
        movementInfo_.reset();
        isAggressive_ = false;
        scale_ = 0.0f;
        startSpawnTime_ = 0;
    }

    bool isValid() const {
        return NpcInfo::isValid() && movementInfo_.isValid();
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        NpcInfo::serialize(stream);
        stream & movementInfo_ & isAggressive_ & scale_;
        if (stateInfo_.hasState(cstSpawnProtection)) {
            stream & startSpawnTime_;
        }
        else {
            startSpawnTime_ = 0;
        }
    }
};


/**
 * @struct MoreGraveStoneInfo
 * 필드 상에서 GraveStone 정보를 표시하기 위해 사용
 */
struct MoreGraveStoneInfo : GraveStoneInfo
{
    explicit MoreGraveStoneInfo(ObjectType objectType = otInvalid,
        ObjectId npcId = invalidObjectId) :
        GraveStoneInfo(objectType, npcId) {}

    void reset() {
        GraveStoneInfo::reset();
    }

    bool isValid() const {
        return GraveStoneInfo::isValid();
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        GraveStoneInfo::serialize(stream);
    }
};


/**
 * @struct MoreDungeonInfo
 * 필드 상에서 Dungeon (입구) 정보를 표시하기 위해 사용
 */
struct MoreDungeonInfo : DungeonInfo
{
    explicit MoreDungeonInfo(ObjectType objectType = otInvalid,
        ObjectId npcId = invalidObjectId) :
        DungeonInfo(objectType, npcId) {}

    void reset() {
        DungeonInfo::reset();
    }

    bool isValid() const {
        return DungeonInfo::isValid();
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        DungeonInfo::serialize(stream);
    }
};


/**
 * @struct HarvestInfo
 * 필드 상에서 채집 정보를 표시하기 위해 사용
 */
struct MoreHarvestInfo : HarvestInfo
{
    HarvestCode harvestCode_;
    uint8_t currentCount_;

    explicit MoreHarvestInfo(ObjectType objectType = otInvalid,
        ObjectId harvestId = invalidObjectId) :
        HarvestInfo(objectType, harvestId),
        harvestCode_(invalidDataCode) {}

    void reset() {
        HarvestInfo::reset();
    }

    bool isValid() const {
        return HarvestInfo::isValid() && isValidDataCode(harvestCode_);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        HarvestInfo::serialize(stream);
        stream & harvestCode_ & currentCount_;
    }
};


/**
 * @struct MoreTreasureInfo
 * 필드 상에서 보물 박스 정보를 표시하기 위해 사용
 */
struct MoreTreasureInfo : TreasureInfo
{
    explicit MoreTreasureInfo(ObjectType objectType = otInvalid,
        ObjectId treasureId = invalidObjectId) :
        TreasureInfo(objectType, treasureId) {}

    void reset() {
        TreasureInfo::reset();
    }

    bool isValid() const {
        return TreasureInfo::isValid();
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        TreasureInfo::serialize(stream);
    }
}; 


/**
 * @struct MoreAnchorInfo
 * 필드 상에서 설치물 표시를 위해 사용
 */
struct MoreAnchorInfo : BaseAnchorInfo
{
    explicit MoreAnchorInfo(ObjectType objectType = otInvalid,
        ObjectId anchorId = invalidObjectId) :
        BaseAnchorInfo(objectType, anchorId) {}

    void reset() {
        BaseAnchorInfo::reset();
    }

    bool isValid() const {
        return BaseAnchorInfo::isValid();
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        BaseAnchorInfo::serialize(stream);
    }
}; 


/**
 * @struct MoreBuildingInfo
 * 필드 상에서 건물 표시를 위해 사용
 */
struct MoreBuildingInfo : BaseBuildingInfo
{
	bool isActivate_;
    bool isOpen_;

    explicit MoreBuildingInfo(ObjectType objectType = otInvalid,
        ObjectId anchorId = invalidObjectId) :
        BaseBuildingInfo(objectType, anchorId) {}

    void reset() {
        BaseBuildingInfo::reset();
        isActivate_ = false;
        isOpen_ = true;
    }

    bool isValid() const {
        return BaseBuildingInfo::isValid();
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        BaseBuildingInfo::serialize(stream);
		stream & isActivate_ & isOpen_;
    }
}; 



/**
 * @struct MoreObeliskInfo
 * 필드 상에서 오벨리스크 정보를 표시하기 위해 사용
 */
struct MoreObeliskInfo : ObeliskInfo
{
    explicit MoreObeliskInfo(ObjectType objectType = otInvalid,
        ObjectId treasureId = invalidObjectId) :
        ObeliskInfo(objectType, treasureId) {}

    void reset() {
        ObeliskInfo::reset();
    }

    bool isValid() const {
        return ObeliskInfo::isValid();
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        ObeliskInfo::serialize(stream);
    }
}; 

/**
 * @struct MoreDeviceInfo
 * 필드 상에서 작동 오브젝트 정보를 표시하기 위해 사용
 */
struct MoreDeviceInfo : DeviceInfo
{
    template <typename Stream>
    void serialize(Stream& stream) {
        DeviceInfo::serialize(stream);
    }
};


/**
 * @class UnionEntityInfo
 * 복합 EntityInfo
 * - 클라이언트에서 관심 영역 내의 Entity를 표시하기 위한 정보
 * - objectType_에 따라 실제 정보가 달라진다
 */
struct UnionEntityInfo
{
private:
    MoreCharacterInfo characterInfo_;
    MoreNpcInfo npcInfo_;
	MoreGraveStoneInfo graveStoneInfo_;
    MoreDungeonInfo dungeonInfo_;
	MoreHarvestInfo harvestInfo_;
	MoreTreasureInfo treasureInfo_;
    MoreAnchorInfo anchorInfo_;
    MoreBuildingInfo buildingInfo_;
    MoreObeliskInfo obeliskInfo_;
    MoreDeviceInfo deviceInfo_;

public:
    ObjectType objectType_;

    explicit UnionEntityInfo(ObjectType objectType = otInvalid) :
        objectType_(objectType) {}

    void reset() {
        objectType_ = otInvalid;
        characterInfo_.reset();
        npcInfo_.reset();
        graveStoneInfo_.reset();
        dungeonInfo_.reset();
		harvestInfo_.reset();
		treasureInfo_.reset();
        anchorInfo_.reset();
        obeliskInfo_.reset();
        buildingInfo_.reset();
        deviceInfo_.reset();
    }

    ObjectId getObjectId() const {
        switch (objectType_) {
        case otPc:
            return characterInfo_.objectId_;
        case otNpc:
        case otMonster:
            return npcInfo_.objectId_;
		case otGraveStone:
			return graveStoneInfo_.objectId_;
        case otDungeon:
            return dungeonInfo_.objectId_;
		case otHarvest:
			return harvestInfo_.objectId_;
		case otTreasure:
			return treasureInfo_.objectId_;
        case otAnchor:
            return anchorInfo_.objectId_;
        case otBuilding:
            return buildingInfo_.objectId_;
        case otObelisk:
            return obeliskInfo_.objectId_;
        case otDevice:
            return deviceInfo_.objectId_;
        }
        assert(false);
        return invalidObjectId;
    }

    const EntityInfo& asEntityInfo() const {
        switch (objectType_) {
        case otPc:
            return characterInfo_;
        case otNpc:
        case otMonster:
            return npcInfo_;
		case otGraveStone:
			return graveStoneInfo_;
        case otDungeon:
            return dungeonInfo_;
		case otHarvest:
			return harvestInfo_;
		case otTreasure:
			return treasureInfo_;
        case otAnchor:
            return anchorInfo_;
        case otBuilding:
            return buildingInfo_;
        case otObelisk:
            return obeliskInfo_;
        case otDevice:
            return deviceInfo_;
        }
        assert(false && "TODO:");
        static const EntityInfo nullEntityInfo;
        return nullEntityInfo;
    }

    EntityInfo& asEntityInfo() {
        switch (objectType_) {
        case otPc:
            return characterInfo_;
        case otNpc:
        case otMonster:
            return npcInfo_;
		case otGraveStone:
			return graveStoneInfo_;
        case otDungeon:
            return dungeonInfo_;
		case otHarvest:
			return harvestInfo_;
		case otTreasure:
			return treasureInfo_;
        case otAnchor:
            return anchorInfo_;
        case otBuilding:
            return buildingInfo_;
        case otObelisk:
            return obeliskInfo_;
        case otDevice:
            return deviceInfo_;
        }
        assert(false && "TODO:");
        static EntityInfo nullEntityInfo;
        return nullEntityInfo;
    }

    const CreatureInfo& asCreatureInfo() const {
        switch (objectType_) {
        case otPc:
            return characterInfo_;
        case otNpc:
        case otMonster:
            return npcInfo_;
        }
        assert(false && "TODO:");
        static const CreatureInfo nullCreatureInfo;
        return nullCreatureInfo;
    }

    CreatureInfo& asCreatureInfo() {
        switch (objectType_) {
        case otPc:
            return characterInfo_;
        case otNpc:
        case otMonster:
            return npcInfo_;
        }
        assert(false && "TODO:");
        static CreatureInfo nullCreatureInfo;
        return nullCreatureInfo;
    }

    float& asCreatureMoveSpeed() {
        switch (objectType_) {
        case otPc:
            return characterInfo_.movementInfo_.speed_;
        case otNpc:
        case otMonster:
            return npcInfo_.movementInfo_.speed_;
        }
        static float nullValue = 0.0f;
        return nullValue;
    }

    const float& asCreatureMoveSpeed() const {
        switch (objectType_) {
        case otPc:
            return characterInfo_.movementInfo_.speed_;
        case otNpc:
        case otMonster:
            return npcInfo_.movementInfo_.speed_;
        }
        static float nullValue = 0.0f;
        return nullValue;
    }

    float& asCreatureScale() {
        switch (objectType_) {
        case otPc:
            return characterInfo_.scale_;
        case otNpc:
        case otMonster:
            return npcInfo_.scale_;
        }
        static float nullValue = 0.0f;
        return nullValue;
    }

    const float& asCreatureScale() const {
        switch (objectType_) {
        case otPc:
            return characterInfo_.scale_;
        case otNpc:
        case otMonster:
            return npcInfo_.scale_;
        }
        static float nullValue = 0.0f;
        return nullValue;
    }
	

    const MoreCharacterInfo& asCharacterInfo() const {
        assert(isPlayer(objectType_));
        return characterInfo_;
    }

    MoreCharacterInfo& asCharacterInfo() {
        assert(isPlayer(objectType_));
        return characterInfo_;
    }

    const MoreNpcInfo& asNpcInfo() const {
        assert(isNpcOrMonster(objectType_));
        return npcInfo_;
    }

    MoreNpcInfo& asNpcInfo() {
        assert(isNpcOrMonster(objectType_));
        return npcInfo_;
    }

	const MoreHarvestInfo& asHarvestInfo() const {
		assert(isHarvest(objectType_));
		return harvestInfo_;
	}

	MoreHarvestInfo& asHarvestInfo() {
		assert(isHarvest(objectType_));
		return harvestInfo_;
	}

	const MoreGraveStoneInfo& asGraveStoneInfo() const {
		assert(isGraveStone(objectType_));
		return graveStoneInfo_;
	}


	MoreGraveStoneInfo& asGraveStoneInfo() {
		assert(isGraveStone(objectType_));
		return graveStoneInfo_;
	}

	const MoreTreasureInfo& asTreasureInfo() const {
		assert(isTreasure(objectType_));
		return treasureInfo_;
	}

	MoreTreasureInfo& asTreasureInfo() {
		assert(isTreasure(objectType_));
		return treasureInfo_;
	}

    const MoreDungeonInfo& asDungeonInfo() const {
        assert(isDungeon(objectType_));
        return dungeonInfo_;
    }

    MoreDungeonInfo& asDungeonInfo() {
        assert(isDungeon(objectType_));
        return dungeonInfo_;
    }

    const MoreAnchorInfo& asAnchorInfo() const {
        assert(isAnchor(objectType_) || isBuilding(otBuilding));
        return anchorInfo_;
    }

    MoreAnchorInfo& asAnchorInfo() {
        assert(isAnchor(objectType_) || isBuilding(otBuilding));
        return anchorInfo_;
    }

    const MoreBuildingInfo& asBuildingInfo() const {
        assert(isBuilding(objectType_));
        return buildingInfo_;
    }

    MoreBuildingInfo& asBuildingInfo() {
        assert(isBuilding(otBuilding));
        return buildingInfo_;
    }

    const MoreObeliskInfo& asObeliskInfo() const {
        assert(isObelisk(objectType_));
        return obeliskInfo_;
    }

    MoreObeliskInfo& asObeliskInfo() {
        assert(isObelisk(objectType_));
        return obeliskInfo_;
    }

    const MoreDeviceInfo& asDeviceInfo() const {
        assert(isDevice(objectType_));
        return deviceInfo_;
    }

    MoreDeviceInfo& asDeviceInfo() {
        assert(isDevice(objectType_));
        return deviceInfo_;
    }
   
    EntityMovementInfo& asEntityMovementInfo() {
        switch (objectType_) {
        case otPc:
            return characterInfo_.movementInfo_;
        case otNpc:
        case otMonster:
            return npcInfo_.movementInfo_;
        }
        assert(false && "TODO:");
        static EntityMovementInfo nullEntityMovementInfo;
        return nullEntityMovementInfo;
    }

    const EntityMovementInfo& asEntityMovementInfo() const {
        switch (objectType_) {
        case otPc:
            return characterInfo_.movementInfo_;
        case otNpc:
        case otMonster:
            return npcInfo_.movementInfo_;
        }
        assert(false && "TODO:");
        static const EntityMovementInfo nullEntityMovementInfo;
        return nullEntityMovementInfo;
    }

    const Points& getCurrentPoints() const {
        switch (objectType_) {
        case otPc:
            return characterInfo_.currentPoints_;
        case otNpc:
        case otMonster:
            return npcInfo_.currentPoints_;
        //TODO: case otGraveStone:
        }
        assert(false && "TODO:");
        static const Points nullPoints;
        return nullPoints;
    }


    bool isValid() const {
        return isValidEntityInfo();
    }

    bool isValidEntityInfo() const {
        switch (objectType_) {
        case otPc:
            return characterInfo_.isValid();
        case otNpc:
        case otMonster:
            return npcInfo_.isValid();
        case otGraveStone:
            return graveStoneInfo_.isValid();
        case otDungeon:
            return dungeonInfo_.isValid();
		case otHarvest:
			return harvestInfo_.isValid();
		case otTreasure:
			return treasureInfo_.isValid();
        case otAnchor:
            return anchorInfo_.isValid();
        case otBuilding:
            return buildingInfo_.isValid();
        case otObelisk:
            return obeliskInfo_.isValid();
        case otDevice:
            return deviceInfo_.isValid();
        }
        assert(false && "TODO:");
        return false;
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & objectType_;
        switch (objectType_) {
        case otPc:
            stream & characterInfo_;
            break;
        case otNpc:
        case otMonster:
            stream & npcInfo_;
            break;
        case otGraveStone:
            stream & graveStoneInfo_;
            break;
        case otDungeon:
            stream & dungeonInfo_;
            break;
		case otHarvest:
			stream & harvestInfo_;
			break;
		case otTreasure:
			stream & treasureInfo_;
			break;
        case otAnchor:
            stream & anchorInfo_;
            break;
        case otBuilding:
            stream & buildingInfo_;
            break;
        case otObelisk:
            stream & obeliskInfo_;
            break;
        case otDevice:
            stream & deviceInfo_;
            break;
        default:
            assert(false && "TODO:");
        }
    }
};


/// UnionEntityInfo list
typedef sne::srpc::RVector<UnionEntityInfo> UnionEntityInfos;

} // namespace gideon {
