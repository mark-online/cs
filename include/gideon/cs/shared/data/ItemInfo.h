#pragma once

#include "Code.h"
#include "ObjectInfo.h"
#include "Time.h"
#include "ItemScript.h"
#include "GemInfo.h"

namespace gideon 
{

typedef uint32_t ItemSuffixId;
const ItemSuffixId invalidItemSuffixId = 0;

inline bool isValidItemSuffixId(ItemSuffixId id)
{
    return invalidItemSuffixId != id;
}

typedef uint32_t ItemOptionId;
const ItemOptionId invalidItemOptionId = 0;


inline bool isValidItemOptionId(ItemOptionId id)
{
    return invalidItemOptionId != id;
}

/**
 * @enum CostType
 */
enum CostType
{
	ctNone = 0,
	ctGameMoney = 1,
    ctArenaPoint = 2,
	ctEventCoin = 3,	
	ctForgeCoin = 4,
};


inline bool isValid(CostType ct)
{
	return (ctGameMoney == ct) || (ctArenaPoint == ct) || (ctEventCoin == ct) || (ctEventCoin == ct) || (ctForgeCoin == ct);
}


inline bool isGameMoney(CostType ct)
{
    return ctGameMoney == ct;
}

inline bool isArenaPoint(CostType ct)
{
    return ctArenaPoint == ct;
}

inline bool isEventCoin(CostType ct)
{
    return ctEventCoin == ct;
}

inline bool isForgeCoin(CostType ct)
{
    return ctForgeCoin == ct;
}

template <typename T>
inline CostType toCostType(T value) 
{
	return static_cast<CostType>(static_cast<int32_t>(value));
}



/**
 * @enum ItemGrade
 * 아이템의 등급
 */
enum ItemGrade
{
    igUnknown = -1,
    igNormal,
    igMagic,
    igRare,
    igEpic,
    igCount
};


inline bool isValid(ItemGrade grade)
{
    return (igUnknown < grade) && (grade < igCount);
}


template <typename T>
inline ItemGrade toItemGrade(T value) 
{
    return static_cast<ItemGrade>(static_cast<int32_t>(value));
}


/**
 * @struct DropItemInfo
 * 화면에 보여주는 기본적인 데이타 정보
 */
struct BaseItemInfo
{
    typedef uint8_t count_t;

    DataCode itemCode_;
	count_t count_;

    explicit BaseItemInfo(DataCode itemCode = invalidDataCode,
		uint8_t count = 0) :
		itemCode_(itemCode),
		count_(count)
	{}

	void reset() {
		itemCode_ = invalidDataCode;
		count_ = 0;
	}

    bool isValid() const {
		if (! isValidDataCode(itemCode_)) {
			return false;
		}		
		return count_ > 0;
    }

	bool isEquipment() const {
		return gideon::isEquipmentType(getCodeType(itemCode_));
	}

    bool isAccessory() const {
        return gideon::isAccessoryType(getCodeType(itemCode_));
    }

    bool isGem() const {
        return gideon::isGemType(getCodeType(itemCode_));
    }

	bool isVehicle() const {
		return gideon::isVehicleType(getCodeType(itemCode_));
	}

	bool isGlider() const {
		return gideon::isGliderType(getCodeType(itemCode_));
	}

    bool isBuildingGuard() const {
        return gideon::isBuildingGuardType(getCodeType(itemCode_));
    }

    bool isFunction() const {
        return gideon::isFunctionType(getCodeType(itemCode_));
    }

	bool shouldDelete() const {
		return 0 >= count_ ;
	}

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & itemCode_ & count_;
    }
};

typedef sne::srpc::RVector<BaseItemInfo> BaseItemInfos;



/// 인벤토리 슬롯 ID(1부터 시작, 0이면 장착 중)
typedef int16_t SlotId;
const SlotId invalidSlotId = -1;
const SlotId firstSlotId = 1;
const SlotId equippedSlotId = 0;

inline bool isValidSlotId(SlotId slotId)
{
    return slotId != invalidSlotId;
}


inline bool isEquipped(SlotId slotId)
{
	return slotId == equippedSlotId;
}


typedef uint8_t SocketSlotId;
const SocketSlotId invalidSocketSlotId = 0;
const SocketSlotId startSocketSlotId = 1;

inline bool isValidSocketSlotId(SocketSlotId id)
{
    return invalidSocketSlotId != id;
}

/**
 * @class EquipSocketInfo
 * 캐릭터 장비 내부 정보
 */
struct EquipSocketInfo
{
    GemCode gemCode_; 
    ItemScriptInfos scriptInfos_;

    explicit EquipSocketInfo(GemCode gemCode = invalidGemCode,
        const ItemScriptInfos& scriptInfos = ItemScriptInfos()) :
        gemCode_(gemCode), 
        scriptInfos_(scriptInfos)
    {
    }


    void reset() {
        gemCode_ = invalidGemCode;
        scriptInfos_.clear();
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & gemCode_ & scriptInfos_;
    }
};

// key slot
typedef sne::srpc::RMap<SocketSlotId, EquipSocketInfo> EquipSocketInfoMap;

/**
 * @class EquipItemInfo
 * 캐릭터 장비 내부 정보
 */
struct EquipItemInfo
{
    uint8_t socketCount_;
    ItemScriptInfos addOptions_;
    EquipSocketInfoMap equipSocketInfoMap_;

    explicit EquipItemInfo(uint8_t socketCount = 0,
        const ItemScriptInfos& addOptions = ItemScriptInfos(), 
        const EquipSocketInfoMap equipSocketInfoMap = EquipSocketInfoMap()) :
        socketCount_(socketCount),
        addOptions_(addOptions),
		equipSocketInfoMap_(equipSocketInfoMap)
    {
    }

    void reset() {
        socketCount_ = 0;
        addOptions_.clear();
		equipSocketInfoMap_.clear();
    }

    bool canAddGemItem() const {
        return equipSocketInfoMap_.size() < socketCount_;
    }

    SocketSlotId getEmptySocketSlotId() const {
        for (SocketSlotId i = startSocketSlotId; i <= socketCount_; ++i) {
            if (equipSocketInfoMap_.find(i) == equipSocketInfoMap_.end()) {
                return i;
            }
        }
        return invalidSocketSlotId;
    }

    bool hasSocketOption(SocketSlotId id) const {
        return equipSocketInfoMap_.find(id) != equipSocketInfoMap_.end();
    }

    void addGemItem(SocketSlotId id, const EquipSocketInfo& socketInfo) {
        equipSocketInfoMap_.insert(EquipSocketInfoMap::value_type(id, socketInfo));
    }

    void removeGemItem(SocketSlotId id) {
        equipSocketInfoMap_.erase(id);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & socketCount_ & addOptions_ & equipSocketInfoMap_;
    }
};


/**
 * @class AccessoryItemInfo
 * 캐릭터 악세사리 내부 정보
 */
struct AccessoryItemInfo
{
    ItemScriptInfos addOptions_;
    
    explicit AccessoryItemInfo(const ItemScriptInfos& addOptions = ItemScriptInfos()) :
        addOptions_(addOptions)
    {
    }

    void reset() {
        addOptions_.clear();
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & addOptions_;
    }
};

/**
 * @struct ItemInfo
 * 인벤토리에 저장된 아이템 정보
 */
struct ItemInfo : BaseItemInfo
{
    ObjectId itemId_;
    SlotId slotId_;
    sec_t expireTime_; // 파괴될 시간

    EquipItemInfo equipItemInfo_;
    AccessoryItemInfo accessoryItemInfo_;

    ItemInfo() {
        reset();
    }

    explicit ItemInfo(const BaseItemInfo& baseInfo) :
        BaseItemInfo(baseInfo.itemCode_, baseInfo.count_),
        itemId_(invalidObjectId),
        slotId_(invalidSlotId),
        expireTime_(0)
    {
    }

    explicit ItemInfo(const BaseItemInfo& baseInfo, ObjectId itemId, SlotId slotId, 
        sec_t destoryTime = 0) :
        BaseItemInfo(baseInfo.itemCode_, baseInfo.count_),
        itemId_(itemId),
        slotId_(slotId),
        expireTime_(destoryTime)
    {
    }

    explicit ItemInfo(const BaseItemInfo& baseInfo, ObjectId itemId, SlotId slotId, 
        sec_t destoryTime, const EquipItemInfo& equipItemInfo) :
        BaseItemInfo(baseInfo.itemCode_, baseInfo.count_),
        itemId_(itemId),
        slotId_(slotId),
        expireTime_(destoryTime),
        equipItemInfo_(equipItemInfo) {}

    explicit ItemInfo(const BaseItemInfo& baseInfo, ObjectId itemId, SlotId slotId, 
        sec_t destoryTime, const AccessoryItemInfo& accessoryItemInfo) :
        BaseItemInfo(baseInfo.itemCode_, baseInfo.count_),
        itemId_(itemId),
        slotId_(slotId),
        expireTime_(destoryTime),
        accessoryItemInfo_(accessoryItemInfo) {}


    explicit ItemInfo(DataCode itemCode, uint8_t itemCount,
		ObjectId itemId , SlotId slotId, sec_t destoryTime = 0) :
		BaseItemInfo(itemCode, itemCount),
        itemId_(itemId),
        slotId_(slotId),
        expireTime_(destoryTime) {}


    explicit ItemInfo(DataCode itemCode, uint8_t itemCount,
		ObjectId itemId , SlotId slotId, sec_t destoryTime, const EquipItemInfo& equipItemInfo) :
		BaseItemInfo(itemCode, itemCount),
        itemId_(itemId),
        slotId_(slotId),
        expireTime_(destoryTime),
        equipItemInfo_(equipItemInfo) {}


    explicit ItemInfo(DataCode itemCode, uint8_t itemCount,
		ObjectId itemId , SlotId slotId, sec_t destoryTime, const AccessoryItemInfo& accessoryItemInfo) :
		BaseItemInfo(itemCode, itemCount),
        itemId_(itemId),
        slotId_(slotId),
        expireTime_(destoryTime),
        accessoryItemInfo_(accessoryItemInfo) {}

    void reset() {
		BaseItemInfo::reset();
        itemId_ = invalidObjectId;
        slotId_ = invalidSlotId;
        expireTime_ = 0;
    }

    void setSlotId(SlotId slotId) {
        slotId_ = slotId;
    }

	bool isEquipped() const {
		return gideon::isEquipped(slotId_);
	}

    bool isValid() const {
		if (! BaseItemInfo::isValid()) {
			return false;
		}
        return isValidObjectId(itemId_) && isValidSlotId(slotId_);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
		BaseItemInfo::serialize(stream);
        stream & itemId_ & slotId_ & expireTime_;
        if (isAccessory()) {
            stream & accessoryItemInfo_;
        }
        else if (isEquipment()) {
            stream & equipItemInfo_;
        }
    }
};

typedef sne::srpc::RHashMap<ObjectId, ItemInfo> ItemMap;


/**
 * @struct BuyBackItemInfo
 */
struct BuyBackItemInfo : public BaseItemInfo
{
    EquipItemInfo equipItemInfo_;
    AccessoryItemInfo accessoryItemInfo_;
    CostType costType_;
    uint32_t cost_;

    explicit BuyBackItemInfo(const ItemInfo& itemInfo = ItemInfo(), CostType costType = ctNone,
        uint32_t cost = 0) :
        BaseItemInfo(itemInfo.itemCode_, itemInfo.count_),
        equipItemInfo_(itemInfo.equipItemInfo_),
        accessoryItemInfo_(itemInfo.accessoryItemInfo_),
        costType_(costType),
        cost_(cost)
    {
    }


    template <typename Stream>
    void serialize(Stream& stream) {
        BaseItemInfo::serialize(stream);
        stream & costType_ & cost_;
        if (isAccessory()) {
            stream & accessoryItemInfo_;
        }
        else if (isEquipment()) {
            stream & equipItemInfo_;
        }
    }
};

typedef sne::srpc::RMap<uint32_t, BuyBackItemInfo> BuyBackItemInfoMap;

} // namespace gideon 