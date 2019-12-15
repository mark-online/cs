#pragma once

#include "ObjectInfo.h"
#include "UserId.h"
#include "Money.h"
#include "InventoryInfo.h"
#include "Time.h"
#include "Code.h"
#include <sne/srpc/RpcContainers.h>

namespace gideon {

typedef ObjectId MailId;

const MailId invalidMailId = 0;

inline bool isValidMailId(MailId mailId)
{
    return invalidMailId != mailId;
}

const GameMoney payMailFee = 10;

/***
* @enum MailProperties
***/
enum MailProperties
{
    minMailTitle = 1,
    maxMailTitle = 25,

    minMailBody = 0,
    maxMailBody = 100,
};


typedef sne::srpc::RpcStringType<std::wstring, maxMailTitle> MailTitle;
typedef sne::srpc::RpcStringType<std::wstring, maxMailBody> MailBody;

/***
* @enum MailType
***/
enum MailType
{
    mtNormal = 0,
    mtReturnMail = 1,
    mtAuctionSuccessfulBid = 2, // 낙찰 되었습니다. buyer
    mtAuctionFailedBid = 3, // 반송되었습니다. buyer
    mtAuctionSucceeded = 4, // 팔렸습니다. seller
    mtAuctionFailed = 5, // 안 팔렸습니다 serller
    mtAuctionCancelled = 6, // 경매 취소 했습니다
    mtAchievementCompleteReward = 7, // 보상
};


inline bool isAuctionMail(MailType mailType)
{
    return (mtReturnMail <= mailType) && (mailType <= mtAuctionCancelled);
}


/***
* @struct MailTitleInfo
***/
struct MailTitleInfo
{
    MailId mailId_;
    ObjectId objectId_;
    Nickname nickname_;
    DataCode dataCode_; // Npc코드및 업적등등..
    MailTitle title_;
    sec_t time_;
    bool isRead_;
    bool hasAttachment_;
    MailType mailType_;

    explicit MailTitleInfo(MailId mailId = invalidMailId, ObjectId objectId = invalidObjectId, 
        const Nickname& nickname = L"", DataCode dataCode = invalidDataCode, const MailTitle& title = L"", 
        sec_t time = 0, bool isRead = false, bool hasAttachment = false, MailType mailType = mtNormal) :
        mailId_(mailId),
        objectId_(objectId),
        nickname_(nickname),
        dataCode_(dataCode),
        title_(title),
        time_(time),
        isRead_(isRead),
        hasAttachment_(hasAttachment),
        mailType_(mailType)
    {
    }

    bool isValid() const {
        if (isValidDataCode(dataCode_)) {
            return isValidMailId(mailId_);
        }
        return isValidMailId(mailId_) && isValidObjectId(objectId_) &&
            ! nickname_.empty() && ! title_.empty() && time_ > 0;
    }

    bool operator<(const MailTitleInfo& info) const {
        return time_ > info.time_; // 시간의 역순
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & mailId_ & objectId_ & nickname_ & dataCode_ & title_ & time_ & isRead_ & hasAttachment_ & mailType_;
    }
};


typedef sne::srpc::RVector<MailTitleInfo> MailTitleInfos;

/***
* @struct MailContentInfo
***/
struct MailContentInfo
{
    MailBody mailBody_;
    GameMoney gameMoney_;
    InventoryInfo mailInventory_;

    explicit MailContentInfo(const MailBody& mailContent = L"",
        GameMoney gameMoney = 0, const InventoryInfo& mailInventory = InventoryInfo()) : 
        mailBody_(mailContent),
        gameMoney_(gameMoney),
        mailInventory_(mailInventory)
    {
    }
        
    template <typename Stream>
    void serialize(Stream& stream) {
        stream & mailBody_ & gameMoney_ & mailInventory_;
    }
};

/***
* @struct MailInfo
***/
struct MailInfo
{
    MailTitleInfo titleInfo_;
    MailContentInfo contentInfo_;

    bool isValid() const {
        return titleInfo_.isValid();
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & titleInfo_ & contentInfo_;
    }
};

typedef sne::srpc::RHashMap<ObjectId, MailInfo> MailInfos;

/***
* @struct SendMailInfo
***/
struct SendMailInfo
{
    Nickname nickname_;
    MailTitle title_;
    MailBody mailBody_;
    GameMoney gameMoney_;
    ObjectIdSet itemIds_;

    explicit SendMailInfo(const Nickname& nickname =L"", const MailTitle& title =L"",
        const MailBody& mailContent = L"", GameMoney gameMoney = 0,
        const ObjectIdSet& itemIds = ObjectIdSet()) :
        nickname_(nickname),
        title_(title),
        mailBody_(mailContent),
        gameMoney_(gameMoney),
        itemIds_(itemIds) {}

    bool isValid() const {
        return (! nickname_.empty() && nickname_.size() <= maxUserIdLength) &&
            (minMailTitle <= title_.size() && title_.size() <= maxMailTitle) &&
            (minMailBody <= mailBody_.size() && mailBody_.size() <= maxMailBody);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & nickname_ & title_ & mailBody_& gameMoney_ & itemIds_;
    }
};


} // namespace gideon {


namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::MailType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::MailType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::MailType>(value);
    return lhs;
}

}} // namespace sne { namespace core {