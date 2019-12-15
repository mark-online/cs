#pragma once

#include "Code.h"
#include "ObjectInfo.h"
#include "itemInfo.h"
#include "EquipmentInfo.h"
#include <sne/srpc/RpcContainers.h>

namespace gideon {

enum InvenType 
{
    itNULL = 0,
	itPc = 1,
	itBank = 2,
    itBuilding = 3,
    itQuest = 4,
    itMercenary = 5,
	itVehicle = 6,
    itBuildingProduction = 7,
    itBuildingSelectProduction = 8,
    itBuildingFoundation = 9,
};

inline bool isBuildingInvenType(InvenType invenType)
{
    return invenType == itBuildingFoundation || invenType == itBuilding || invenType == itMercenary || invenType == itBuildingProduction || invenType == itBuildingSelectProduction;
}

const SlotId defultInvenSlotId = 8 * 4; //< 32 칸
const SlotId maxFreeExtendSlotId = 8 * 2;
const SlotId maxCashExtendSlotId = 8 * 2;
const uint8_t maxFundationBuildingSlotId = 128;

/**
 * @struct InventoryInfo
 * 캐릭터의 인벤토리
 */
struct InventoryInfo
{
    uint8_t defaultInvenCount_;
    uint8_t freeSlotCount_;
	uint8_t cashSlotCount_;
    ItemMap items_;

    InventoryInfo() {
        reset();
	}

    void reset() {
        items_.clear();
		freeSlotCount_ = 0;
        cashSlotCount_ = 0;
        defaultInvenCount_ = 0;
    }
    
    bool canExtendSlot(bool isCashSlot, uint8_t count) const {
        if (isCashSlot) {
            return maxCashExtendSlotId >= count + cashSlotCount_;
        }
        return maxFreeExtendSlotId >= count + freeSlotCount_;
    }

    void extendSlot(bool isCashSlot, uint8_t count) {
        if (! canExtendSlot(isCashSlot, count)) {
            assert(false);
            return;
        }
        if (isCashSlot) {
            cashSlotCount_ += count;
        }
        else {
            freeSlotCount_ += count;
        }
    }

    uint8_t getTotalSlotCount() const {
        return defaultInvenCount_ + freeSlotCount_ + cashSlotCount_;
    }

	bool isStorable(SlotId slotId) const {
		return (slotId >= firstSlotId) && (slotId <= getTotalSlotCount());
	}

    void addItem(const ItemInfo& item) {
        assert(items_.find(item.itemId_) == items_.end());
        if (item.isAccessory()) {
            items_.insert(ItemMap::value_type(item.itemId_, ItemInfo(item, item.itemId_, item.slotId_,  item.expireTime_, item.accessoryItemInfo_)));
        }
        else if (item.isEquipment()) {
            items_.insert(ItemMap::value_type(item.itemId_, ItemInfo(item, item.itemId_, item.slotId_,  item.expireTime_, item.equipItemInfo_)));
        }
        else {
            items_.insert(ItemMap::value_type(item.itemId_, item));
        }
    }


	ObjectId getHasMaxId() const {
		ObjectId objectId = invalidObjectId;
		for (const ItemMap::value_type& value : items_) {
			if ((value.first) > objectId) {
				objectId = value.first;
			}
		}
		return objectId;
	}

    void removeItem(ObjectId itemId) {
        assert(items_.find(itemId) != items_.end());
        items_.erase(itemId);
    }

    bool moveItem(const ObjectId itemId, const SlotId slotId) {
        const ItemMap::iterator pos = items_.find(itemId);
        if (pos == items_.end()) {
            return false;
        }

		if (isOccupiedSlot(slotId)) {
			return false;
		}

        ((*pos).second).slotId_ = slotId;
        return true;
    }

    bool switchItem(const ObjectId itemId1,const ObjectId itemId2) {
        const ItemMap::iterator pos1 = items_.find(itemId1);
        if (pos1 == items_.end()) {
            return false;
        }
        const ItemMap::iterator pos2 = items_.find(itemId2);
        if (pos2 == items_.end()) {
            return false;
        }

        SlotId tempSlotId = ((*pos1).second).slotId_;
        ((*pos1).second).slotId_ = ((*pos2).second).slotId_;
        ((*pos2).second).slotId_ = tempSlotId;
        return true;
    }

    bool isValid() const {
        // TODO: 무엇을 검사할 것인가?
        return true;
    }

    SlotId getFirstEmptySlotId() const {
        for (SlotId slotId = firstSlotId; slotId <= getTotalSlotCount(); ++slotId) {
            if (! isOccupiedSlot(slotId)) {
                return slotId;
            }
        }
        return invalidSlotId;
    }

    bool isOccupiedSlot(SlotId slotId) const {
        assert(isStorable(slotId));
        for (const ItemMap::value_type& value : items_) {
            if ((value.second).slotId_ == slotId) {
                return true;
            }
        }
        return false;
    }

	bool hasSameKindItem(DataCode itemCode) const {
		for (const ItemMap::value_type& value : items_) {
			if ((value.second).itemCode_ == itemCode) {
				return true;
			}
		}
		return false;
	}

    bool hasEnoughItem(DataCode itemCode, uint8_t itemCount) const {
        int stackCount = 0;
        for (const ItemMap::value_type& value : items_) {	
            if ((value.second).itemCode_ == itemCode) {
                stackCount += (value.second).count_;
                if (stackCount >= itemCount) {
                    return true;
                }
            }
        }
        return false;
    }

	uint8_t getEmptySlotCount() const {
		uint8_t count = 0;
		for (const ItemMap::value_type& value : items_) {			
			if ((value.second).slotId_ != equippedSlotId) {
				++count;
			}
		}
		return getTotalSlotCount() - count; 
	}

    uint8_t getEquippedCount() const {
        uint8_t count = 0;
        for (const ItemMap::value_type& value : items_) {			
            if ((value.second).slotId_ == equippedSlotId) {
                ++count;
            }
        }
        return count;
    }

    const ItemInfo* getItemInfo(ObjectId itemId) const {
        const ItemMap::const_iterator pos = items_.find(itemId);
        if (pos == items_.end()) {
            return nullptr;
        }
        return &((*pos).second);
    }

    ItemInfo* getItemInfo(ObjectId itemId) {
        const ItemMap::iterator pos = items_.find(itemId);
        if (pos == items_.end()) {
            return nullptr;
        }
        return &((*pos).second);
    }

    
    const ItemInfo* getFirstItemInfo(DataCode itemCode) const {
        for (const ItemMap::value_type& value : items_) {	
            if ((value.second).itemCode_ == itemCode) {
                return &(value.second);
            }
        }
        return nullptr;
    }

    ItemInfo* getFirstItemInfo(DataCode itemCode) {
        for (ItemMap::value_type& value : items_) {	
            if ((value.second).itemCode_ == itemCode) {
                return &(value.second);
            }
        }
        return nullptr;
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & defaultInvenCount_ & freeSlotCount_ & cashSlotCount_ & items_;
    }
};

} // namespace gideon {

namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::InvenType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::InvenType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::InvenType>(value);
    return lhs;
}

}} // namespace sne { namespace core {