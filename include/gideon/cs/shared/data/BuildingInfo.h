#pragma once

#include "GuildInfo.h"
#include "RecipeInfo.h"
#include "BuildingGuardInfo.h"

namespace gideon {

typedef DataCode BuildingCode;

const BuildingCode invalidBuildingCode = 0;

inline bool isValidBuildingCode(BuildingCode code)
{
    return getCodeType(code) == ctBuilding;
}



/**
 * @enum BuildingOwnerType
 */
enum BuildingOwnerType
{
    botUnknown = 0,    
    botPrivate,
    botGuild,
    botCommon,
    botBoundery
};


inline bool isValid(BuildingOwnerType type)
{
    return botUnknown < type && type < botBoundery;
}

template <typename T>
inline BuildingOwnerType toBuildingOwnerType(T value)
{
    return static_cast<BuildingOwnerType>(static_cast<uint8_t>(value));
}


inline bool isPrivateOwnerType(BuildingOwnerType ownerType)
{
    return botPrivate == ownerType;
}


inline bool isGuildOwnerType(BuildingOwnerType ownerType)
{
    return botGuild == ownerType;
}

inline bool isCommonOwnerType(BuildingOwnerType ownerType)
{
    return botCommon == ownerType;
}


/***
 * @struct BuildingState
 ***/
enum BuildingStateType
{
    bstUnknown,
    bstFoundation,
    bstBuilding,
    bstComplete,
    bstWreckage,
};


/***
 * @struct BuildingFunctionScript
 ***/
enum BuildingFunctionScript
{
    bfsUnknown,
    bfsBank,
    bfsAutoBank,
    bfsForge,
    bfsAutoForge,
    bfsBindRecall,
    bfsTeleport,
    bfsManufacture,
    bfsAuction,
    bfsAutoAuction,
    bfsDoor,
    bfsMercenary,
    bfsAutoInterface, // 클라에서만
    bfsBoundary
};

inline bool isValid(BuildingFunctionScript script)
{
    return bfsUnknown <= script && script < bfsBoundary;
}


template <typename T>
inline BuildingFunctionScript toBuildingFunctionScript(T value)
{
    const int32_t intValue = static_cast<int32_t>(value);
    const BuildingFunctionScript bfs = static_cast<BuildingFunctionScript>(intValue);
    assert(isValid(bfs));
    return bfs;
}

inline bool canBank(BuildingFunctionScript script)
{
    return script == bfsBank || script == bfsAutoBank;
}

inline bool canForge(BuildingFunctionScript script)
{
    return script == bfsForge || script == bfsAutoForge;
}

inline bool canAuction(BuildingFunctionScript script)
{
    return script == bfsAuction || script == bfsAutoAuction;
}


typedef sne::core::Vector<BuildingFunctionScript> BuildingFunctionScripts;

/***
 * @struct BuildingItemTaskInfo
 ***/
struct BuildingItemTaskInfo
{
	BaseItemInfo baseItemInfo_;
	sec_t completeTaskTime_;
	
	BuildingItemTaskInfo(const BaseItemInfo& baseItemInfo = BaseItemInfo(),
		sec_t completeTaskTime = 0) :
		baseItemInfo_(baseItemInfo),
		completeTaskTime_(completeTaskTime)
	{
	}

	template <typename Stream>
	void serialize(Stream& stream) {
		stream & baseItemInfo_ & completeTaskTime_;
	}
};

typedef sne::srpc::RVector<BuildingItemTaskInfo> BuildingItemTaskInfos;

/***
 * @struct BuildingState
 ***/ 
struct BuildingMarkInfo
{
    ObjectId buildingId_;
    BuildingCode buildingCode_;
    Position position_;

    BuildingMarkInfo(ObjectId buildingId = invalidObjectId,
        BuildingCode buildingCode = invalidBuildingCode,
        const Position& position = Position()) :
        buildingId_(buildingId),
        buildingCode_(buildingCode),
        position_(position)
    {
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & buildingId_ & buildingCode_ & position_;
    }
};

typedef sne::srpc::RVector<BuildingMarkInfo> BuildingMarkInfos;
typedef sne::core::HashMap<ObjectId, BuildingMarkInfo> BuildingMarkInfoMap;

/***
 * @struct BaseBuildingInfo
 ***/
struct BaseBuildingInfo : public EntityInfo
{
    BuildingCode buildingCode_;
    BuildingStateType state_;
    sec_t startBuildTime_; // 빌드 시작시간
    bool isInvincible_;

    explicit BaseBuildingInfo(ObjectType objectType = otInvalid,
        ObjectId anchorId = invalidObjectId) :
        EntityInfo(objectType, anchorId) {
        reset();
    }

    void reset() {
        EntityInfo::reset();
        state_ = bstUnknown;
        buildingCode_ = invalidBuildingCode;
        startBuildTime_ = 0;
        isInvincible_ = false;
    }

    bool isFoundationState() const {
        return bstFoundation == state_;
    }

    bool isWreckageState() const {
        return bstWreckage == state_;
    }

    bool isBuildingState() const {
        return bstBuilding == state_;
    }

    bool isCompleteState() const {
        return bstComplete == state_;
    }

    bool isValid() const {
        return EntityInfo::isValid() && isValidBuildingCode(buildingCode_);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        EntityInfo::serialize(stream);
        stream & buildingCode_ & state_ & startBuildTime_ & isInvincible_;
    }
};

/***
 * @struct BuildingSelectProductionInfo
 ***/
struct BuildingSelectProductionInfo
{
    RecipeCode recipeCode_;
    uint8_t completeCount_;
    sec_t completeTime_;

    BuildingSelectProductionInfo(RecipeCode recipeCode = invalidRecipeCode,
        uint8_t completeCount = 0, sec_t completeTime = 0) :
        recipeCode_(recipeCode),
        completeCount_(completeCount),
        completeTime_(completeTime)
    {
    }

    void reset() {
        recipeCode_ = invalidRecipeCode;
        completeCount_ = 0;
        completeTime_ = 0;
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        if (stream.isInput()) {
            reset();
        }
        stream & recipeCode_;
        if (isValidRecipeCode(recipeCode_)) {            
            stream & completeCount_ & completeTime_;
        }
    }
};


typedef sne::srpc::RVector<BuildingSelectProductionInfo> BuildingSelectProductionInfos;

/***
 * @struct BuildingPlayerOwnerInfo
 ***/
struct BuildingPlayerOwnerInfo
{

    ObjectId objectId_;
    Nickname nickname_;

    explicit BuildingPlayerOwnerInfo(ObjectId objectId = invalidObjectId, const Nickname& nickname = L"") :
        objectId_(objectId),
        nickname_(nickname) {}


    bool isValid() const {
        return isValidObjectId(invalidObjectId);
    }

    void reset() {
        objectId_ = invalidObjectId;
        nickname_.clear();
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & objectId_ & nickname_;        
    }

};


/***
 * @struct BuildingOwnerInfo
 ***/
struct BuildingOwnerInfo
{
    BuildingOwnerType ownerType_;
    BaseGuildInfo guildInfo_;
    BuildingPlayerOwnerInfo playerOwnerInfo_;
    
    explicit BuildingOwnerInfo() {
        reset();
    }

    explicit BuildingOwnerInfo(const BaseGuildInfo& guildInfo) :
        guildInfo_(guildInfo)
    {
    }
    
    explicit BuildingOwnerInfo(const BuildingPlayerOwnerInfo& playerOwnerInfo) :
        playerOwnerInfo_(playerOwnerInfo)
    {
    }

    bool isValid() const {
        if (! gideon::isValid(ownerType_)) {
            return false;
        }
        if (ownerType_ == botPrivate) {
            return playerOwnerInfo_.isValid();
        }
        else if (ownerType_ == botGuild) {
            return guildInfo_.isValid();
        }

        return botCommon == ownerType_;
    }

    void reset() {
        ownerType_ = botUnknown;
        guildInfo_.reset();
        playerOwnerInfo_.reset();
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & ownerType_ & guildInfo_ & playerOwnerInfo_;        
    }
};


/***
 * @struct BuildingInfo
 ***/
struct BuildingInfo : public BaseBuildingInfo
{
    sec_t fundationExpireTime_; // 파괴되는 시간
    sec_t createTime_ ;
    HitPoints points_;
    BuildingOwnerInfo ownerInfo_;
    
    InventoryInfo buildingInventory_;
    InventoryInfo mercenaryInventory_;
    InventoryInfo productionInventory_;
    InventoryInfo selectProductionInventory_;
    InventoryInfo fundationInventory_;
    BuildingSelectProductionInfos selectProducionInfos_;

    BuildingGuardInfos buildingGuardInfos_;

	BuildingInfo() {
		reset();
	}

    void reset() {
        BaseBuildingInfo::reset();
        fundationExpireTime_ = 0;
        createTime_ = 0;
        ownerInfo_.reset();
        points_.reset();
        buildingInventory_.reset();
        mercenaryInventory_.reset();
        productionInventory_.reset();
        selectProductionInventory_.reset();
        fundationInventory_.reset();
        selectProducionInfos_.clear();
        buildingGuardInfos_.clear();
    }

    void damage(HitPoint hp) {
        points_.reduce(hp);
    }

    void repair(HitPoint hp) {
        points_.refill(hp);
    }

    bool isMinHp() const {
        return hpMin >= points_.hp_;
    }

    ItemInfo* getItemInfo(ObjectId itemId) {
        ItemInfo* itemInfo = buildingInventory_.getItemInfo(itemId);
        
        if (! itemInfo) {
            itemInfo = mercenaryInventory_.getItemInfo(itemId);
        }
        if (! itemInfo) {
            itemInfo = productionInventory_.getItemInfo(itemId);
        }
        if (! itemInfo) {
            itemInfo = selectProductionInventory_.getItemInfo(itemId);
        }
        if (! itemInfo) {
            itemInfo = fundationInventory_.getItemInfo(itemId);
        }
        return itemInfo;
    }

    void addItemInfo(InvenType invenType, const ItemInfo& itemInfo) {
        if (itBuilding == invenType) {
            buildingInventory_.addItem(itemInfo);
        }
        else if (itMercenary == invenType) {
            mercenaryInventory_.addItem(itemInfo);
        }
        else if (itBuildingProduction == invenType) {
            productionInventory_.addItem(itemInfo);
        }
        else if (itBuildingSelectProduction == invenType) {
            selectProductionInventory_.addItem(itemInfo);
        }
        else if (itBuildingFoundation == invenType) {
            fundationInventory_.addItem(itemInfo);
        }
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        BaseBuildingInfo::serialize(stream);
        stream & fundationExpireTime_ & createTime_ & points_ & ownerInfo_& 
            buildingInventory_ & mercenaryInventory_ & productionInventory_ &
            selectProductionInventory_ & selectProducionInfos_ & fundationInventory_ &
            buildingGuardInfos_;
    }
};

typedef sne::srpc::RMap<ObjectId, BuildingInfo> BuildingInfoMap;

} // namespace gideon {


namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::BuildingStateType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::BuildingStateType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::BuildingStateType>(value);
    return lhs;
}


}} // namespace sne { namespace core {