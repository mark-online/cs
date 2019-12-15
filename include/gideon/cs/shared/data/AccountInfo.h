#pragma once

#include "AccountId.h"
#include "UserId.h"
#include "WorldInfo.h"
#include "ServerInfo.h"

namespace gideon {

/***
 * @enum AccountGrade
 ***/
enum AccountGrade
{
	agPlayer = 0,
	agModerator,
	agGameMaster,
	agAdmin,
};


inline bool canCheat(AccountGrade value)
{
    return value > agPlayer;
}


/***
 * @struct AccountInfo
 ***/
struct AccountInfo
{
	AccountId accountId_;
	UserId userId_;
	AccountGrade accountGrade_;
    ShardId lastAccessShardId_;

	explicit AccountInfo(AccountId accountId = invalidAccountId, const UserId& userId = L"",
		AccountGrade accountGrade = agPlayer, ShardId lastAccessShardId = invalidShardId) :
		accountId_(accountId),
		userId_(userId),
		accountGrade_(accountGrade),
        lastAccessShardId_(lastAccessShardId) {}

    void reset() {
        accountId_ = invalidAccountId;
        userId_.clear();
        accountGrade_ = agPlayer;
        lastAccessShardId_ = invalidShardId;
    }

	bool isValid() const {
		return isValidAccountId(accountId_);
	}

	template <typename Stream>
	void serialize(Stream& stream) {
		stream & accountId_ & userId_ & accountGrade_ & lastAccessShardId_;
	}
};

} // namespace gideon {

namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::AccountGrade rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::AccountGrade& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::AccountGrade>(value);
    return lhs;
}

}} // namespace sne { namespace core {