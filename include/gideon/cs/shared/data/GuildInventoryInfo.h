#pragma once

#include "VaultInfo.h"

namespace gideon {

/**
 * @struct GuildInventoryInfo
 * 캐릭터의 인벤토리
 */
struct GuildInventoryInfo
{
    VaultInfos vaultInfos_;

    GuildInventoryInfo() {
        reset();
	}

    void reset() {
        vaultInfos_.clear();
    }

    void addVault(const BaseVaultInfo& vaultInfo) {
        vaultInfos_.push_back(vaultInfo);
    }

    void addItem(VaultId vaultId, const ItemInfo& item) {
        VaultInfo* vaultInfo = getVaultInfo(vaultId);
        if (! vaultInfo) {
            assert(false);
            return;
        }
        vaultInfo->addItem(item);
    }

    void removeItem(VaultId vaultId, ObjectId itemId) {
        VaultInfo* vaultInfo = getVaultInfo(vaultId);
        if (! vaultInfo) {
            assert(false);
            return;
        }
        vaultInfo->removeItem(itemId);
    }

    /// 금고간 아이템 이동은 지원하지 않는다
    bool moveItem(VaultId vaultId, ObjectId itemId, SlotId moveSlotId) {
        VaultInfo* vaultInfo = getVaultInfo(vaultId);
        if (! vaultInfo) {
            return false;
        }
        return vaultInfo->moveItem(itemId, moveSlotId);
    }

    /// 금고간 아이템 교환은 지원하지 않는다
    bool switchItem(VaultId vaultId, ObjectId itemId1, ObjectId itemId2) {
        VaultInfo* vaultInfo = getVaultInfo(vaultId);
        if (! vaultInfo) {
            return false;
        }
        return vaultInfo->switchItem(itemId1, itemId2);
    }

    bool canAddVault() const {
        return getVaultCount() < maxGuildVaultCount;
    }

    bool hasVault(VaultId vaultId) const {
        if (! isValidVaultId(vaultId)) {
            return false;
        }
        return vaultId < int8_t(vaultInfos_.size());
    }

    size_t getVaultCount() const {
        return vaultInfos_.size();
    }

    VaultId getNextVaultId() const {
        return VaultId(vaultInfos_.size());
    }

    VaultInfo* getVaultInfo(VaultId vaultId) {
        if (! hasVault(vaultId)) {
            return nullptr;
        }
        return &vaultInfos_[vaultId];
    }

    const VaultInfo* getVaultInfo(VaultId vaultId) const {
        if (! hasVault(vaultId)) {
            return nullptr;
        }
        return &vaultInfos_[vaultId];
    }

    SlotId getFirstEmptySlotId(VaultId vaultId) const {
        const VaultInfo* vaultInfo = getVaultInfo(vaultId);
        if (! vaultInfo) {
            return invalidSlotId;
        }
        return vaultInfo->getFirstEmptySlotId();
    }

    const ItemInfo* getItemInfo(VaultId vaultId, ObjectId itemId) const {
        const VaultInfo* vaultInfo = getVaultInfo(vaultId);
        if (! vaultInfo) {
            return nullptr;
        }
        return vaultInfo->getItemInfo(itemId);
    }

    ItemInfo* getItemInfo(VaultId vaultId, ObjectId itemId) {
        VaultInfo* vaultInfo = getVaultInfo(vaultId);
        if (! vaultInfo) {
            return nullptr;
        }
        return vaultInfo->getItemInfo(itemId);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & vaultInfos_;
    }
};

} // namespace gideon {