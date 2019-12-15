#pragma once

#include "Code.h"
#include "ObjectInfo.h"
#include "ItemInfo.h"
#include "Money.h"
#include <sne/srpc/RpcContainers.h>

namespace gideon {

typedef int8_t VaultId;
const VaultId invalidVaultId = -1;
const VaultId startVaultId = 0;
const VaultId maxVaultId = 4;

inline bool isValidVaultId(VaultId id)
{
    return (startVaultId <= id) && (id <= maxVaultId);
}

enum VaultProperties
{
    maxGuildVaultCount = maxVaultId + 1, //< 최대 구매 가능한 금고 수
    maxGuildVaultNameLength = 12,
};

/// RPC type for vault name (UNICODE supported)
typedef sne::srpc::RpcStringType<std::wstring, maxGuildVaultNameLength> VaultName;


/// 길드 금고 슬롯 최대 갯수
const uint8_t maxGuildVaultSlotCount = 10 * 6;


inline VaultId getVaultId(SlotId slotId)
{
    return static_cast<VaultId>(slotId >> 8);
}

inline SlotId getVaultSlotId(SlotId slotId)
{
    return static_cast<VaultId>(slotId & 0x00FF);
}


inline GameMoney getGuildVaultCost(VaultId vaultId)
{
    switch (vaultId) {
    case startVaultId:
        return byGold(10);
    case startVaultId + 1:
        return byGold(25);
    case startVaultId + 2:
        return byGold(50);
    case startVaultId + 3:
        return byGold(100);
    case startVaultId + 4:
        return byGold(250);
    }
    return 0;
}

/**
 * @struct BaseVaultInfo
 * 길드 은행 금고 기본 정보
 */
struct BaseVaultInfo
{
    VaultId id_;
    VaultName name_;

    explicit BaseVaultInfo(VaultId id = invalidVaultId, const VaultName& name = L"") :
        id_(id),
        name_(name) {}

    void reset() {
        id_ = invalidVaultId;
        name_.clear();
    }

    bool isValid() const {
        return BaseVaultInfo::isValid();
        return isValidVaultId(id_);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & id_ & name_;
    }
};


typedef sne::srpc::RVector<BaseVaultInfo> BaseVaultInfos;

/**
 * @struct VaultInfo
 * 길드 은행 금고 정보
 */
struct VaultInfo : BaseVaultInfo
{
    ItemMap itemMap_;

    explicit VaultInfo(VaultId id = invalidVaultId, const VaultName& name = L"") :
        BaseVaultInfo(id, name) {}

    VaultInfo(const BaseVaultInfo& vaultInfo) :
        BaseVaultInfo(vaultInfo) {}

    void reset() {
        BaseVaultInfo::reset();
        itemMap_.clear();
    }

    void addItem(const ItemInfo& item) {
        assert(itemMap_.find(item.itemId_) == itemMap_.end());
        itemMap_.insert(ItemMap::value_type(item.itemId_, item));
    }

    void removeItem(ObjectId itemId) {
        assert(itemMap_.find(itemId) != itemMap_.end());
        itemMap_.erase(itemId);
    }

    bool moveItem(ObjectId itemId, SlotId moveSlotId) {
        ItemInfo* itemInfo = getItemInfo(itemId);
        if (! itemInfo) {
            return false;
        }

        if (isOccupiedSlot(moveSlotId)) {
            return false;
        }

        itemInfo->slotId_ = moveSlotId;
        return true;
    }

    bool switchItem(ObjectId itemId1, ObjectId itemId2) {
        ItemInfo* itemInfo1 = getItemInfo(itemId1);
        if (! itemInfo1) {
            return false;
        }
        ItemInfo* itemInfo2 = getItemInfo(itemId2);
        if (! itemInfo2) {
            return false;
        }

        std::swap(itemInfo1->slotId_, itemInfo2->slotId_);
        return true;
    }

    bool hasItem(ObjectId itemId) const {
        return getItemInfo(itemId) != nullptr;
    }

    ItemInfo* getItemInfo(ObjectId itemId) {
        const ItemMap::iterator pos = itemMap_.find(itemId);
        return (pos != itemMap_.end()) ? &(*pos).second : nullptr;
    }

    const ItemInfo* getItemInfo(ObjectId itemId) const {
        const ItemMap::const_iterator pos = itemMap_.find(itemId);
        return (pos != itemMap_.end()) ? &(*pos).second : nullptr;
    }


    SlotId getFirstEmptySlotId() const {
        for (SlotId slotId = firstSlotId; slotId <= maxGuildVaultSlotCount; ++slotId) {
            if (! isOccupiedSlot(slotId)) {
                return slotId;
            }
        }
        return invalidSlotId;
    }

    bool hasSameKindItem(DataCode itemCode) const {
        for (const ItemMap::value_type& value : itemMap_) {
            const ItemInfo& itemInfo = value.second;
            if (itemInfo.itemCode_ == itemCode) {
                return true;
            }
        }
        return false;
    }

    bool isOccupiedSlot(SlotId slotId) const {
        assert(isStorable(slotId));
        for (const ItemMap::value_type& value : itemMap_) {
            const ItemInfo& itemInfo = value.second;
            if (itemInfo.slotId_ == slotId) {
                return true;
            }
        }
        return false;
    }

    bool isStorable(SlotId slotId) const {
        return (slotId >= firstSlotId) && (slotId <= maxGuildVaultSlotCount);
    }

    bool isValid() const {
        return isValidVaultId(id_);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        BaseVaultInfo::serialize(stream);
        stream & itemMap_;
    }
};

typedef sne::srpc::RVector<VaultInfo> VaultInfos;

} // namespace gideon {

