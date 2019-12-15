#pragma once

#include "ItemInfo.h"
#include "Money.h"
#include "Time.h"
#include "NpcInfo.h"

namespace gideon {

/// 최소한의 경매 수수료
const int minimumDepositFree = 10; // 10 copper

/// 낙찰 수수료(cutFee rate)
const int cutFeeRate = 5; // 5%

typedef ObjectId AuctionId;

const AuctionId invalidAuctionId = 0;

inline bool isValidAuctionId(AuctionId id)
{
    return invalidAuctionId != id;
}

/***
 *@enum AutionDurationType
 ***/
enum AutionDurationType
{
    adtUnknown = 0,
    adt12Hour = 1,
    adt24Hour = 2,
    adt48Hour = 3,
};


inline bool isValid(AutionDurationType type)
{
    return adt12Hour <= type && type <= adt48Hour;
}

inline sec_t getAuctionDurationSec(AutionDurationType type)
{
    if (! isValid(type)) {
        assert(false);
        return 0;
    }

    if (adt12Hour == type) {
        return 12 * 60 * 60;
    }
    else if (adt24Hour == type) {
        return 24 * 60 * 60;
    }
    return 48 * 60 * 60;       
}


inline GameMoney calculateDepositFree(GameMoney baseMoney, AutionDurationType duration)
{
    if (! isValid(duration)) {
        return baseMoney;
    }
    return baseMoney * duration;
}


inline GameMoney calculateAuctionCommission(GameMoney currentBidMoney)
{
    return (currentBidMoney * cutFeeRate) / 100;
}
 

/***
 * @struct CreateAuctionInfo
 ***/
struct CreateAuctionInfo
{
    ObjectId itemId_;
    GameMoney bidPrice_;
    GameMoney buyoutPrice_;
    AutionDurationType duration_;    

    explicit CreateAuctionInfo(ObjectId itemId = invalidObjectId, GameMoney bidPrice = 0,
        GameMoney buyoutPrice = 0, AutionDurationType duration = adtUnknown) :
        itemId_(itemId),
        bidPrice_(bidPrice),
        buyoutPrice_(buyoutPrice),
        duration_(duration)
    {
    }

    bool isValid() const {
        if (bidPrice_ <= 0) {
            return false;
        }
        if (buyoutPrice_ > 0 && buyoutPrice_ < bidPrice_) {
            return false;
        }
        return isValidObjectId(itemId_) && gideon::isValid(duration_);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & itemId_ & bidPrice_ & buyoutPrice_ & duration_;        
    }
};


/***
 *@struct AuctionInfo
 ***/
struct AuctionInfo
{
    AuctionId auctionId_;
    sec_t expireTime_;
    GameMoney currentBidMoney_;
    GameMoney buyoutMoney_;
    ItemInfo itemInfo_;

    explicit AuctionInfo(AuctionId auctionId = invalidObjectId,
        sec_t expireTime = 0, GameMoney currentBidMoney = 0,
        GameMoney buyoutMoney = 0, const ItemInfo& itemInfo = ItemInfo()) :
        auctionId_(auctionId),
        expireTime_(expireTime),
        currentBidMoney_(currentBidMoney),
        buyoutMoney_(buyoutMoney),
        itemInfo_(itemInfo) {}

    bool isValid() const {
        return isValidObjectId(auctionId_) && expireTime_ > 0 &&
            itemInfo_.isValid();
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & auctionId_ & expireTime_ & currentBidMoney_ & buyoutMoney_ & itemInfo_;
    }
};

typedef sne::srpc::RVector<AuctionInfo> AuctionInfos;

/***
 *@struct FullAuctionInfo
 ***/
struct FullAuctionInfo : public AuctionInfo
{
    ObjectId sellerId_;
    ObjectId buyerId_;
    GameMoney depositFee_;

    explicit FullAuctionInfo(ObjectId autionId = invalidObjectId,
        sec_t expireTime = 0, GameMoney currentBidMoney = 0,
        GameMoney buyoutMoney = 0, const ItemInfo& itemInfo = ItemInfo(),
        ObjectId sellerId = invalidObjectId, ObjectId buyerId = invalidObjectId,
        GameMoney depositFee = 0) :
        AuctionInfo(autionId, expireTime, currentBidMoney, buyoutMoney, itemInfo),    
        sellerId_(sellerId),
        buyerId_(buyerId),
        depositFee_(depositFee)
    {
    }

    bool isValid() const {
        if (! AuctionInfo::isValid()) {
            return false;
        }
        return isValidObjectId(sellerId_);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        AuctionInfo::serialize(stream);
        stream & sellerId_ & buyerId_ & depositFee_;
    }
};


typedef sne::srpc::RHashMap<AuctionId, FullAuctionInfo> FullAuctionInfoMap;

// = @서버용
typedef sne::srpc::RHashMap<NpcCode, FullAuctionInfoMap> ServerAuctionInfoMap;

} // namespace gideon {

namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::AutionDurationType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::AutionDurationType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::AutionDurationType>(value);
    return lhs;
}

}} // namespace sne { namespace core {