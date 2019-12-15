#pragma once

#include "ObjectInfo.h"
#include "UserId.h"
#include "Time.h"
#include "VaultInfo.h"


namespace gideon {

typedef uint32_t GuildEventLogId;
const GuildEventLogId invalidGuildEventLogId = 0;
const GuildEventLogId maxGuildEventLogId = 40;

typedef sne::srpc::RVector<GuildEventLogId> GuildEventLogIds;

/**
 * @enum GuildEventLogType
 */
enum GuildEventLogType
{
    geltUnknown = 0,
    geltDeposit,
    geltWidthdraw,
    geltMaxWidthdraw,
    geltPushInvenItem,
    geltPopInvenItem,
    geltKickMember,
    geltJoinMember, //< 가입
    geltLeaveMember,
    geltCreateGuild, //< 길드 창설
    geltLevelUp, // 길드 레벨 업
    geltActivateSkill, // 길드 스킬 활성화
    geltDeactivateSkills, // 길드 스킬 비활성화
    geltNotUsed_1,
    geltPurchaseVault, 
};


/**
 * @struct GuildEventLogInfo
 */
struct GuildEventLogInfo
{
    GuildEventLogId id_;
    GuildEventLogType logType_;
    ObjectId playerId1_;
    ObjectId playerId2_;
    Nickname nickname1_;
    Nickname nickname2_;
    uint64_t param1_;
    sec_t logTime_;

    GuildEventLogInfo(GuildEventLogId id = invalidGuildEventLogId, 
        GuildEventLogType logType = geltUnknown, ObjectId playerId1 = invalidObjectId,
        ObjectId playerId2 = invalidObjectId, const Nickname& nickname1 = L"", 
        const Nickname& nickname2 = L"", uint64_t param1 = 0, sec_t logTime = 0) :
        id_(id),
        logType_(logType),
        playerId1_(playerId1),
        playerId2_(playerId2),
        nickname1_(nickname1),
        nickname2_(nickname2),
        param1_(param1),
        logTime_(logTime) {}

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & id_ & logType_& playerId1_ & playerId2_ & nickname1_ & nickname2_ & param1_ & logTime_;
    }
};

typedef sne::srpc::RList<GuildEventLogInfo> GuildEventLogInfoList;

/**
 * @struct GuildGameMoneyEventLogInfo
 */
struct GuildGameMoneyEventLogInfo
{
    GuildEventLogId id_;
    GuildEventLogType logType_;
    ObjectId playerId_;
    Nickname nickname_;
    GameMoney gameMoney_;
    sec_t logTime_;

    GuildGameMoneyEventLogInfo(GuildEventLogId id = invalidGuildEventLogId, 
        GuildEventLogType logType = geltUnknown, ObjectId playerId = invalidObjectId,
        const Nickname& nickname = L"",  GameMoney gameMoney = 0,  sec_t logTime = 0) :
        id_(id),
        logType_(logType),
        playerId_(playerId),
        nickname_(nickname),
        gameMoney_(gameMoney),
        logTime_(logTime) {}


    template <typename Stream>
    void serialize(Stream& stream) {
        stream & id_ & logType_ & playerId_ & nickname_ & gameMoney_ & logTime_;
    }
};

typedef sne::srpc::RList<GuildGameMoneyEventLogInfo> GuildGameMoneyEventLogInfoList;

/**
 * @struct GuildBankEventLogInfo
 */
struct GuildBankEventLogInfo
{
    GuildEventLogId id_;
    VaultId vaultId_; 
    GuildEventLogType logType_;
    ObjectId playerId_;
    Nickname nickname_;
    uint32_t param1_;
    uint32_t param2_;
    sec_t logTime_;

    GuildBankEventLogInfo(GuildEventLogId id = invalidGuildEventLogId, VaultId vaultId = invalidVaultId,
        GuildEventLogType logType = geltUnknown, ObjectId playerId = invalidObjectId,
        const Nickname& nickname = L"",  uint32_t param1 = 0, uint32_t param2 = 0, 
        sec_t logTime = 0) :
        id_(id),
        vaultId_(vaultId),
        logType_(logType),
        playerId_(playerId),
        nickname_(nickname),
        param1_(param1),
        param2_(param2),
        logTime_(logTime) {}

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & id_ & vaultId_ & logType_ & playerId_ & nickname_ & param1_ & param2_ & logTime_;
    }
};

typedef sne::srpc::RList<GuildBankEventLogInfo> GuildBankEventLogInfoList;

typedef sne::srpc::RVector<GuildBankEventLogInfoList> GuildBankEventLogInfoLists;


/**
 * @struct GuildGameMoneyEventLogManager
 */
struct GuildGameMoneyEventLogManager
{ 
    GuildEventLogId logId_;
    GuildGameMoneyEventLogInfoList logList_;

    GuildGameMoneyEventLogManager() :
        logId_(invalidGuildEventLogId) {}

    void reset() {
        logList_.clear();
    }

    GuildEventLogId getNextLogId() {
        if (logId_ == maxGuildEventLogId) {
            logId_ = 1;
            return logId_;
        }
        logId_ = (logId_ + 1) % maxGuildEventLogId;
        return logId_; 
    }

    void addLog(const GuildGameMoneyEventLogInfo& log) {
        if (logList_.size() == maxGuildEventLogId) {
            logList_.pop_back();
        }
        logList_.push_front(log);
    }

    void fillPageLogList(GuildGameMoneyEventLogInfoList& pageLogList, uint8_t& totalCount,          
        uint8_t beginLogIndex, uint8_t logCount) const {  
            totalCount = static_cast<uint8_t>(logList_.size());
            if (beginLogIndex >= totalCount) {
                return;
            }
            GuildGameMoneyEventLogInfoList::const_iterator pos = logList_.begin();
            const GuildGameMoneyEventLogInfoList::const_iterator end = logList_.end();
            for (int logIndex = 0; pos != end; ++pos, ++logIndex) {
                if (logIndex >= beginLogIndex) {
                    if (logCount <= 0) {
                        break;
                    }
                    pageLogList.push_back((*pos));
                    --logCount;
                }
            }
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & logId_ & logList_;
    }
};



/**
 * @struct GuildEventLogManager
 */
struct GuildEventLogManager
{ 
    GuildEventLogId logId_;
    GuildEventLogInfoList logList_;

    GuildEventLogManager() :
        logId_(invalidGuildEventLogId) {}

    void reset() {
        logList_.clear();
    }

    GuildEventLogId getNextLogId() {
        if (logId_ == maxGuildEventLogId) {
            logId_ = 1;
            return logId_;
        }
        logId_ = (logId_ + 1) % maxGuildEventLogId;
        return logId_; 
    }

    void addLog(const GuildEventLogInfo& log) {
        if (logList_.size() == maxGuildEventLogId) {
            logList_.pop_back();
        }
        logList_.push_front(log);
    }

    void fillPageLogList(GuildEventLogInfoList& pageLogList, uint8_t& totalCount, 
        uint8_t beginLogIndex, uint8_t logCount) const {
        totalCount = static_cast<uint8_t>(logList_.size());
        if (beginLogIndex >= totalCount) {
            return;
        }
        GuildEventLogInfoList::const_iterator pos = logList_.begin();
        const GuildEventLogInfoList::const_iterator end = logList_.end();
        for (int logIndex = 0; pos != end; ++pos, ++logIndex) {
            if (logIndex >= beginLogIndex) {
                if (logCount <= 0) {
                    break;
                }
                pageLogList.push_back((*pos));
                --logCount;
            }
        }
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & logId_ & logList_;
    }
};


/**
 * @struct GuildBankEventLogManager
 */
struct GuildBankEventLogManager
{ 
    GuildBankEventLogInfoList logList_;
    GuildEventLogId logId_;

    GuildBankEventLogManager() :
        logId_(invalidGuildEventLogId) {}

    void reset() {
        logList_.clear();
    }

    GuildEventLogId getNextLogId() {
        if (logId_ == maxGuildEventLogId) {
            logId_ = 1;
            return logId_;
        }
        logId_ = (logId_ + 1) % maxGuildEventLogId;
        return logId_; 
    }

    void addLog(const GuildBankEventLogInfo& log) {
        if (logList_.size() == maxGuildEventLogId) {
            logList_.pop_back();
        }
        logList_.push_front(log);
    }


    void fillPageLogList(GuildBankEventLogInfoList& pageLogList, uint8_t& totalCount,
        uint8_t beginLogIndex, uint8_t logCount) const {
        totalCount = static_cast<uint8_t>(logList_.size());
        if (beginLogIndex >= totalCount) {
            return;
        }
        GuildBankEventLogInfoList::const_iterator pos = logList_.begin();
        const GuildBankEventLogInfoList::const_iterator end = logList_.end();
        for (int logIndex = 0; pos != end; ++pos, ++logIndex) {
            if (logIndex >= beginLogIndex) {
                if (logCount <= 0) {
                    break;
                }
                pageLogList.push_back((*pos));
                --logCount;
            }
        }
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & logId_ & logList_;
    }
};

} // namespace gideon {

namespace sne { namespace core {


inline OStream& operator<<(OStream& lhs, gideon::GuildEventLogType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::GuildEventLogType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::GuildEventLogType>(value);
    return lhs;
}

}} // namespace sne { namespace core {
