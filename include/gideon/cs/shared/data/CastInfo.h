#pragma once

#include "ObjectInfo.h"
#include "SkillInfo.h"
#include "Coordinate.h"
#include "TreasureInfo.h"
#include "GraveStoneInfo.h"
#include "RecipeInfo.h"
#include "ErrorCode.h"
#include "SkillEffectInfo.h"

namespace gideon {

/***
 * @enum UnionCastType
 * 시작 캐스팅 타입
 ***/
enum UnionCastType
{
    uctUnknown,
    uctSkillTo,
    uctSkillAt,
    uctItemTo,
    uctItemAt,
    uctHavest,
    uctTreasure,
    uctVehicle,
    uctGlider,
	uctDeviceActivation,
    uctItemLooting,
	uctBindRecall,
    uctBuildingItemLooting,
    uctNpcCraft,
    uctPlayerCraft,
    uctReprocess,
    uctEquipUpgrade,
    uctEquipEnchant,
    uctFunctionItem,
	uctBoundery,
};


inline bool isValid(const UnionCastType castType)
{
	return uctUnknown < castType && castType < uctBoundery;
}


inline bool isCastToType(const UnionCastType castType)
{
    return castType == uctSkillTo;
}


inline bool isCastAtType(const UnionCastType castType)
{
    return castType == uctSkillAt;
}


inline bool isItemToType(const UnionCastType castType) 
{
    return castType == uctItemTo;
}


inline bool isItemAtType(const UnionCastType castType)
{
    return castType == uctItemAt;
}

inline bool isBuildingItemAtType(const UnionCastType castType)
{
    return castType == uctBuildingItemLooting;
}


inline bool isHarvestType(const UnionCastType castType)
{
    return castType == uctHavest;
}


inline bool isTreasureType(const UnionCastType castType) 
{
    return castType == uctTreasure;
}


inline bool isVehicleType(const UnionCastType castType) 
{
    return castType == uctVehicle;
}


inline bool isGliderType(const UnionCastType castType) 
{
    return castType == uctGlider;
}


inline bool isItemLootingType(const UnionCastType castType) 
{    
    return castType == uctItemLooting;
}


inline bool isSkillType(const UnionCastType castType)
{
    return isCastToType(castType) || isCastAtType(castType);
}


inline bool isItemType(const UnionCastType castType)
{
    return isItemToType(castType) || isItemAtType(castType);
}


inline bool isBindRecall(const UnionCastType castType)
{
	return castType == uctBindRecall;
}


inline bool isDeviceActivation(const UnionCastType castType)
{
    return castType == uctDeviceActivation;
}


inline bool isBuildingItemLootingType(const UnionCastType castType) 
{    
    return castType == uctBuildingItemLooting;
}


inline bool isNpcCraft(const UnionCastType castType)
{
    return uctNpcCraft == castType;
}


inline bool isPlayerCraft(const UnionCastType castType)
{
    return uctPlayerCraft == castType;
}


inline bool isReprocessItem(const UnionCastType castType)
{
    return uctReprocess == castType;
}


inline bool isEquipUpgrade(const UnionCastType castType)
{
    return uctEquipUpgrade == castType;
}


inline bool isEquipEnchant(const UnionCastType castType)
{
    return uctEquipEnchant == castType;
}

inline bool isUseFunctionItem(const UnionCastType castType)
{
    return uctFunctionItem == castType;
}

/***
 * @enum CommonCastCodeType
 * 캐스팅 상태를 알아볼때(코드가 없는 경우 Ex:아이디로 사용하는경우)
 ***/
enum CastStateType
{
	cstUnkonwn = 0,
	cstBindRecall = 1,
    cstBuildingItemLooting = 2,
};


typedef DataCode CastStateCode;


inline CastStateCode makeCastStateCode(CastStateType type)
{
	return getMinGideonCode(ctCastState) + (type << 16) ;
}

inline CastStateType getCastStateType(CastStateCode cst)
{
	assert(getCodeType(cst) == ctCastState);
	return static_cast<CastStateType>((cst & 0x00FF0000) >> 16);
}


const CastStateCode bindRecallCode = makeCastStateCode(cstBindRecall);

/***
 * @struct StartCastInfo
 * request info
 ***/
struct StartCastInfo
{
private:
	ObjectId objectId1_;
    ObjectId objectId2_;
	DataCode dataCode_;
	GameObjectInfo targetInfo_;
	Position targetPosition_;
	LootInvenId itemIndex_; // 비석 아이템 인덱스
    InvenType invenType_;

public:
    UnionCastType castType_;

    explicit StartCastInfo() {
		reset();
	}

    void reset() {
        castType_ = uctUnknown;
		objectId1_ = invalidObjectId;
		dataCode_ = invalidDataCode;
		targetInfo_.reset();
		targetPosition_.reset();
	}

    void set(UnionCastType type, const GameObjectInfo& targetInfo, DataCode dataCode) {
        assert(uctSkillTo == type || uctNpcCraft == type);
        castType_ = type;
        dataCode_ = dataCode;
		targetInfo_ = targetInfo;
    }

    void set(const GameObjectInfo& targetInfo, ObjectId equipItemId, ObjectId gemItemId) {
        castType_ = uctEquipEnchant;
        targetInfo_ = targetInfo;
        objectId1_ = equipItemId;
        objectId2_ = gemItemId;
    }

    void set(const Position& targetPosition, DataCode skillCode) {
        castType_ = uctSkillAt;
		dataCode_ = skillCode;
        targetPosition_ = targetPosition;
	}

    void set(UnionCastType type, ObjectId itemId, const GameObjectInfo& targetInfo) {
        assert(uctEquipUpgrade == type || uctItemTo == type || uctPlayerCraft == type || uctReprocess == type );
        castType_ = type;
        objectId1_ = itemId;
		targetInfo_ = targetInfo;
    }

    void set(ObjectId itemId, const Position& targetPosition) {
        castType_ = uctItemAt;
        objectId1_ = itemId;
        targetPosition_ = targetPosition;
    }

    void set(UnionCastType type, const GameObjectInfo& targetInfo) {
        assert(uctHavest == type || uctTreasure == type || uctDeviceActivation == type);
        castType_ = type;
        targetInfo_ = targetInfo;
    }

	void set(UnionCastType type) {
		assert(uctVehicle == type || uctGlider == type);
        castType_ = type;
	}

    void set(UnionCastType type, ObjectId id) {
        assert(uctBindRecall == type);
        castType_ = type;
        objectId1_ = id;
    }

	void set(LootInvenId itemIndex, const GameObjectInfo& targetInfo) {
		castType_ = uctItemLooting;
		itemIndex_ = itemIndex;
		targetInfo_ = targetInfo;
	}

    void set(const GameObjectInfo& targetInfo, ObjectId itemId, InvenType invenType) {
        castType_ = uctBuildingItemLooting;
        targetInfo_ = targetInfo;
        objectId1_ = itemId;
        invenType_ = invenType;
    }

    void set(ObjectId itemId) {
        castType_ = uctFunctionItem;
        objectId1_ = itemId;
    }

	const GameObjectInfo& getTargetInfo() const {
		assert(uctPlayerCraft == castType_ || uctNpcCraft == castType_ || uctSkillTo == castType_ || uctItemTo == castType_ || 
			uctHavest == castType_ || uctTreasure == castType_ || uctDeviceActivation == castType_ ||
			uctItemLooting == castType_ || uctBuildingItemLooting == castType_ || uctNpcCraft == castType_ || 
            uctPlayerCraft == castType_ || uctReprocess == castType_ || uctEquipUpgrade == castType_ || uctEquipEnchant == castType_ );
		return targetInfo_;
	}

	const Position& getTargetPosition() const {
		assert(uctSkillAt == castType_ || uctItemAt == castType_);
		return targetPosition_;
	}


    SkillCode getCastSkillCode() const {
		assert(isCastToType(castType_) || isCastAtType(castType_) );
		return dataCode_;
	}

    RecipeCode getRecipeCode() const {
        assert(isNpcCraft(castType_));
        return dataCode_;
    }

    ObjectId getItemId() const {
        assert (isItemToType(castType_) || isItemAtType(castType_) || 
            isBuildingItemAtType(castType_) || isPlayerCraft(castType_) ||
            isReprocessItem(castType_) || isUseFunctionItem(castType_));
        return objectId1_;
	}


	ObjectId getBindRecallId() const {
		assert (isBindRecall(castType_));
		return objectId1_;
	}

	LootInvenId getLootInvenId() const {
		assert(uctItemLooting == castType_);
		return itemIndex_;
	}

    InvenType getInvenType() const {
        assert(uctBuildingItemLooting == castType_);
        return invenType_;
    }

    ObjectId getEquipItemId() const {
        assert(uctEquipUpgrade == castType_ || uctEquipEnchant == castType_);
        return objectId1_;
    }

    ObjectId getGemItemId() const {
        assert(uctEquipEnchant == castType_);
        return objectId2_;
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        const bool isInput = stream.isInput();
        if (isInput) {
            reset();
        }
        stream & castType_;
        switch(castType_) {
        case uctSkillTo:
        case uctNpcCraft:
            stream & dataCode_ & targetInfo_;
            break;
        case uctSkillAt:
            stream & dataCode_ & targetPosition_;
            break;
        case uctItemTo:
        case uctPlayerCraft:
        case uctReprocess:
            stream & objectId1_ & targetInfo_;
            break;
        case uctItemAt:
            stream & objectId1_ & targetPosition_;
			break;
        case uctHavest:
        case uctTreasure:
		case uctDeviceActivation:
            stream & targetInfo_;
        case uctVehicle:
        case uctGlider:
            break;
		case uctBindRecall:
			stream & objectId1_;
			break;
		case uctItemLooting:
			stream & targetInfo_ & itemIndex_;
            break;
        case uctBuildingItemLooting:
            stream & targetInfo_ & objectId1_ & invenType_;
            break;
        case uctEquipEnchant:
            stream & targetInfo_ & objectId1_ & objectId2_;
            break;
        case uctEquipUpgrade:
            stream & targetInfo_ & objectId1_ ;
            break;;
        case uctFunctionItem:
            stream & objectId1_;
            break;
        default:
            assert(false);
            break;
        }
    }
};


/***
 * @struct StartCastResultInfo
 * event info
 * 현재는 스킬이나 아이템 모두 At, To상관없이 to로 보낸다.
 ***/
struct StartCastResultInfo
{
private:
	GameObjectInfo casterInfo_;
	GameObjectInfo targetInfo_;
	DataCode dataCode1_; // 기본적인 코드
	DataCode dataCode2_; // 현재 마갑의 외형 코드만 쓴다.

public:
	UnionCastType castType_;

	void reset() {
		castType_ = uctUnknown;
		casterInfo_.reset();
		targetInfo_.reset();
		dataCode1_ = invalidDataCode;
		dataCode2_ = invalidDataCode;
	}

	void set(UnionCastType castType, const GameObjectInfo& casterInfo, const GameObjectInfo& targetInfo, DataCode dataCode) {
		assert(castType == uctSkillTo || castType == uctItemTo || castType == uctItemLooting || castType == uctBuildingItemLooting ||
            castType == uctNpcCraft || castType == uctPlayerCraft || castType == uctReprocess || castType == uctEquipUpgrade);            
		castType_ = castType; 
		casterInfo_ = casterInfo;
		targetInfo_ = targetInfo;
		dataCode1_ = dataCode;
	}

    void set(const GameObjectInfo& casterInfo, const GameObjectInfo& targetInfo, DataCode dataCode1, DataCode dataCode2) {
        castType_ = uctEquipEnchant; 
        casterInfo_ = casterInfo;
        targetInfo_ = targetInfo;
        dataCode1_ = dataCode1;
        dataCode2_ = dataCode2;
    }

    void set(UnionCastType castType, const GameObjectInfo& casterInfo, const GameObjectInfo& targetInfo) {
        assert(castType == uctHavest || castType == uctTreasure || castType == uctDeviceActivation);            
        castType_ = castType; 
		casterInfo_ = casterInfo;
		targetInfo_ = targetInfo;
    }

	void set(UnionCastType castType, const GameObjectInfo& casterInfo, DataCode itemCode) {
        assert(castType == uctGlider || castType == uctFunctionItem);
        castType_ = castType; 
		casterInfo_ = casterInfo;
		dataCode1_ = itemCode;
	}

	void set(const GameObjectInfo& casterInfo, DataCode vehicleCode, DataCode harnessCode) {
		castType_ = uctVehicle; 
		casterInfo_ = casterInfo;
		dataCode1_ = vehicleCode;
		dataCode2_ = harnessCode;
	}

	void set(const GameObjectInfo& casterInfo) {
		castType_ = uctBindRecall; 
		casterInfo_ = casterInfo;
	}

    bool isUseDataCodeType () const {
        return castType_ == uctGlider || castType_ == uctVehicle || castType_ == uctSkillTo || castType_ == uctItemTo ||
            castType_ == uctNpcCraft || castType_ == uctPlayerCraft || castType_ == uctReprocess || castType_ == uctEquipUpgrade ||
            castType_ == uctEquipEnchant || castType_  == uctFunctionItem;
    }

    bool isLooting() const {
        return (castType_ == uctItemLooting) || (castType_ == uctBuildingItemLooting);            
    }

    DataCode getDataCode1() const {
		assert(isUseDataCodeType() || isLooting());
        return dataCode1_;
    }

	DataCode getDataCode2() const {
		assert(castType_ == uctVehicle || castType_ == uctEquipEnchant);
        return dataCode2_;
	}

    const GameObjectInfo& getCaster() const {
        return casterInfo_;
    }

    const GameObjectInfo& getTarget() const {		
        return targetInfo_;
    }


    template <typename Stream>
    void serialize(Stream& stream) {
		const bool isInput = stream.isInput();
		if (isInput) {
			reset();
		}
        stream & castType_;		
        switch(castType_) {
        case uctSkillTo:
        case uctItemTo:
        case uctItemLooting:
        case uctBuildingItemLooting:
        case uctNpcCraft:
        case uctPlayerCraft:
        case uctReprocess:
        case uctEquipUpgrade:
            stream & casterInfo_ & targetInfo_ & dataCode1_;
            break;
        case uctEquipEnchant:
            stream & casterInfo_ & targetInfo_ & dataCode1_ & dataCode2_;
            break;
        case uctHavest:
        case uctTreasure:
		case uctDeviceActivation:
            stream & casterInfo_ & targetInfo_;
            break;
        case uctVehicle:
			stream & casterInfo_ & dataCode1_ & dataCode2_;
			break;
        case uctGlider:
        case uctFunctionItem:
			stream & casterInfo_ & dataCode1_;
            break;
		case uctBindRecall:
			stream & casterInfo_;
        default:
            assert(false);
            break;
        }		
    }
};


/***
 * @struct CancelCastResultInfo
 * event info
 ***/
struct CancelCastResultInfo
{
    DataCode dataCode_;
    GameObjectInfo objectInfo_;

    CancelCastResultInfo(DataCode dataCode = invalidDataCode,
        const GameObjectInfo& objectInfo = GameObjectInfo()) :
        dataCode_(dataCode),
        objectInfo_(objectInfo)
    {}

    void reset() {
        dataCode_ = invalidDataCode;
        objectInfo_.reset();
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & dataCode_ & objectInfo_;
    }
};


/***
 * @struct FailCompletedCastResultInfo
 * event info
 ***/
struct FailCompletedCastResultInfo
{
    UnionCastType castType_;
    ErrorCode errorCode_;
    GameObjectInfo objectInfo_;
    DataCode dataCode_;

    void reset() {
        castType_ = uctUnknown;
    }

    void setDataInfo(UnionCastType castType, ErrorCode errorCode,
        const GameObjectInfo& objectInfo, DataCode dataCode) {
        castType_ = castType;
        errorCode_ = errorCode;
        objectInfo_ = objectInfo;
        dataCode_ = dataCode;        
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & castType_ & errorCode_ & objectInfo_ & dataCode_;
    }
};


/***
 * @struct CompleteCastResultInfo
 ***/
struct CompleteCastResultInfo
{
private:
	GameObjectInfo casterInfo_;
	GameObjectInfo targetInfo_;
	Position targetPosition_;
	DataCode dataCode1_;
	DataCode dataCode2_;
	uint8_t count_; // 체집 가능한 현재 횟수
	float speed_; // 말을 타거나 글라이더를 타면 현재 스피드가 변한다.
	LootInvenId graveStoneItemId_;
    ObjectId objectId_;
    EffectDefenceType effectDefenceType_;
    bool isSucceeded_;

public:
    UnionCastType castType_;

    CompleteCastResultInfo() :
        castType_(uctUnknown)
    {
    }
 
    void reset() {
        castType_ = uctUnknown;
		casterInfo_.reset();
		targetInfo_.reset();
		targetPosition_.reset();
		dataCode1_ = invalidDataCode;
		dataCode2_ = invalidDataCode;
		count_ = 0;
        objectId_ = invalidObjectId;
        effectDefenceType_ = edtNone;
        speed_ = 0.0f;
        isSucceeded_ = false;
    }

	void set(UnionCastType castType, const GameObjectInfo& casterInfo,
		const GameObjectInfo& targetInfo, DataCode dataCode, EffectDefenceType effectDefenceType) {
		assert(castType == uctSkillTo || castType == uctItemTo);
        castType_ = castType;
		casterInfo_ = casterInfo;
		targetInfo_ = targetInfo;
		dataCode1_ = dataCode;
        effectDefenceType_ = effectDefenceType;
	}

	void set(UnionCastType castType, const GameObjectInfo& casterInfo,
		const Position& targetPosition, DataCode dataCode) {
		assert(castType == uctSkillAt || castType == uctSkillAt);
        castType_ = castType;
		casterInfo_ = casterInfo;
		dataCode1_ = dataCode;
		targetPosition_ = targetPosition;
    }

	void set(const GameObjectInfo& casterInfo, const GameObjectInfo& targetInfo, uint8_t count) {
        castType_ = uctHavest;
		casterInfo_ = casterInfo;
		targetInfo_ = targetInfo;
		count_ = count;
    }

	void set(UnionCastType castType, const GameObjectInfo& casterInfo,
		const GameObjectInfo& targetInfo) {
        assert(castType == uctTreasure || castType == uctDeviceActivation);
        castType_ = castType;
		casterInfo_ = casterInfo;
		targetInfo_ = targetInfo;
    }

	void set(const GameObjectInfo& casterInfo, DataCode gliderCode, float speed) { 
		castType_ = uctGlider; 
		casterInfo_ = casterInfo;
		dataCode1_ = gliderCode;
		speed_ = speed;
	}

	void set(const GameObjectInfo& casterInfo, DataCode vehicleCode, DataCode harnessCode, float speed) {
		castType_ = uctVehicle; 
		casterInfo_ = casterInfo;
		dataCode1_ = vehicleCode;
		dataCode2_ = harnessCode;
		speed_ = speed;
	}

	void set(const GameObjectInfo& casterInfo) {
		castType_ = uctBindRecall;
		casterInfo_ = casterInfo;
	}

	void set(const GameObjectInfo& casterInfo, const GameObjectInfo& targetInfo, LootInvenId graveStoneItemId) {
		castType_ = uctItemLooting;
		casterInfo_ = casterInfo;
		targetInfo_ = targetInfo;
		graveStoneItemId_ = graveStoneItemId;
	}

    void set(ObjectId itemId, const GameObjectInfo& casterInfo, const GameObjectInfo& targetInfo) {
        castType_ = uctBuildingItemLooting;
        casterInfo_ = casterInfo;
        targetInfo_ = targetInfo;
        objectId_ = itemId;
    }

    void set(UnionCastType castType, ObjectId itemId, const GameObjectInfo& casterInfo) {
        assert(castType == uctNpcCraft || castType == uctPlayerCraft || castType == uctEquipEnchant || castType == uctEquipUpgrade);
        castType_ = castType;
        casterInfo_ = casterInfo;
        objectId_ = itemId;
    }

    void set(const GameObjectInfo& casterInfo, bool isSucceeded, DataCode reprocessItemCode) {
        castType_ = uctReprocess;
        casterInfo_ = casterInfo;
        isSucceeded_ = isSucceeded;
        dataCode1_ = reprocessItemCode;
    }

    void set(UnionCastType castType, const GameObjectInfo& casterInfo, bool isSucceeded, ObjectId equipItemId) {
        assert(castType == uctEquipUpgrade || castType == uctEquipEnchant);
        castType_ = castType;
        casterInfo_ = casterInfo;
        isSucceeded_ = isSucceeded;
        objectId_ = equipItemId;
    }


    void set(const GameObjectInfo& casterInfo, ObjectId functionItemId, DataCode itemCode) {
        castType_ = uctFunctionItem;
        casterInfo_ = casterInfo;
        objectId_ = functionItemId;
        dataCode1_ = itemCode;
    }

	const GameObjectInfo& getCasterInfo() const {
		assert(isValid(castType_));
		return casterInfo_;
	}

	const GameObjectInfo& getTargetInfo() const {
		assert(uctSkillTo == castType_ || uctItemTo == castType_ ||
			uctHavest == castType_ || uctTreasure == castType_ || uctDeviceActivation == castType_ ||
			uctDeviceActivation == castType_ || uctItemLooting == castType_ || uctBuildingItemLooting == castType_);
		return targetInfo_;
	}

	const Position& getTargetPosition() const {
		assert(uctSkillAt == castType_ || uctItemAt == castType_);
		return targetPosition_;
	}


	bool isUseDataCodeType() const {
		return castType_ == uctGlider || castType_ == uctVehicle || castType_ == uctSkillTo || castType_ == uctItemTo ||
			castType_ == uctSkillAt || castType_ == uctItemAt || castType_ == uctReprocess || castType_ == uctFunctionItem;
	}

	DataCode getDataCode1() const {
		assert(isUseDataCodeType());
		return dataCode1_;
	}

	DataCode getDataCode2() const {
		assert(castType_ == uctVehicle);
		return dataCode2_;
	}

	uint8_t getHarvestCount() const {
		assert(castType_ == uctHavest);
		return count_;
	}

    EffectDefenceType getEffectDefenceType() const {
        assert(isSkillInfo());
        return effectDefenceType_;
    }

	float getCurrentSpeed() const {
		assert(castType_ == uctVehicle || castType_ == uctGlider);
		return speed_;
	}

    bool isSkillInfo() const {        
        return castType_ == uctSkillTo || castType_ == uctItemTo || castType_ == uctSkillAt || castType_ == uctSkillAt;
    }

    bool isTargetSkillInfo() const {        
        return castType_ == uctSkillTo || castType_ == uctItemTo;
    }

    bool isPositionSkillInfo() const {        
        return castType_ == uctSkillAt || castType_ == uctItemAt;
    }

    bool isCraftInfo() const {
        return castType_ == uctNpcCraft || castType_ == uctPlayerCraft;
    }

    bool isReprocessItem() const {
        return castType_ == uctReprocess;
    }

	LootInvenId getGraveStoneItemId() const {
		assert(castType_ == uctItemLooting);
		return graveStoneItemId_;
	}

    ObjectId getItemId() const {
        assert(castType_ == uctBuildingItemLooting || castType_ == uctNpcCraft || castType_ == uctPlayerCraft ||
            castType_ == uctEquipUpgrade || castType_ == uctEquipEnchant || castType_ == uctFunctionItem);
        return objectId_;
    }

    bool isSucceeded() const {
        assert((castType_ == uctReprocess) || (castType_ == uctEquipUpgrade) || (castType_ == uctEquipEnchant));
        return isSucceeded_;
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        const bool isInput = stream.isInput();
        if (isInput) {
            reset();
        }
        stream & castType_;
        switch(castType_) {
        case uctSkillTo:
        case uctItemTo:
			stream & casterInfo_ & targetInfo_ & dataCode1_ & effectDefenceType_;    
            break;
        case uctSkillAt:
        case uctItemAt:
            stream & casterInfo_ & targetPosition_ & dataCode1_;
			break;
        case uctHavest:
            stream & casterInfo_ & targetInfo_ & count_;
            break;
        case uctNpcCraft:
        case uctPlayerCraft:
            stream & casterInfo_ & objectId_;
            break;
        case uctEquipEnchant:
        case uctEquipUpgrade:
            stream & casterInfo_ & objectId_ & isSucceeded_;
            break;
        case uctReprocess:
            stream & casterInfo_ & isSucceeded_ & dataCode1_;
            break;
        case uctTreasure:
		case uctDeviceActivation:
		    stream & casterInfo_ & targetInfo_;			
            break;
        case uctVehicle:
			stream  & casterInfo_ & dataCode1_ & dataCode2_ & speed_;
			break;
        case uctGlider:
			stream & casterInfo_ & dataCode1_ & speed_;
            break;
		case uctBindRecall:
			stream & casterInfo_;
			break;
		case uctItemLooting:
			stream & casterInfo_ & targetInfo_ & graveStoneItemId_;	
			break;
        case uctBuildingItemLooting:
            stream & casterInfo_ & targetInfo_ & objectId_;	
            break;
        case uctFunctionItem:
            stream & casterInfo_ & objectId_ & dataCode1_;
            break;                 
		default:
            assert(false && "invalid");
        }
    }
};

} // namespace gideon {

namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::UnionCastType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::UnionCastType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::UnionCastType>(value);
    return lhs;
}

}} // namespace sne { namespace core {
