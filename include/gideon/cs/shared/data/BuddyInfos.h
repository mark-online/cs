#pragma once

#include "AccountId.h"
#include "ObjectInfo.h"
#include "UserId.h"
#include "Chatting.h"
#include "Time.h"

namespace gideon {

/***
 * @struct BuddyInfo
 * 친구
 ***/
struct BuddyInfo
{
	AccountId accountId_;
	ObjectId playerId_;
	Nickname nickname_;
	bool isOnline_;

	explicit BuddyInfo(AccountId accountId = invalidAccountId, 
		ObjectId playerId = invalidObjectId, const Nickname& nickname = L"",
		bool isOnline = false) : 
		accountId_(accountId),
		playerId_(playerId),
		nickname_(nickname),
		isOnline_(isOnline) {}

	void reset() {
		accountId_ = invalidAccountId;
		playerId_ = invalidObjectId;
		nickname_.clear();
		isOnline_ = false;
	}

	bool isValid() const {
		return isValidAccountId(accountId_) && isValidObjectId(playerId_) && ! nickname_.empty();
	}

	template <typename Stream>
	void serialize(Stream& stream) {
		stream & accountId_ & playerId_ & nickname_ & isOnline_;
	}
};


typedef sne::srpc::RVector<BuddyInfo> BuddyInfos;


/***
 * @struct BlockInfo
 * 차단
 ***/
struct BlockInfo
{
	AccountId accountId_;
	ObjectId playerId_;
	Nickname nickname_;

	explicit BlockInfo(AccountId accountId = invalidAccountId, 
		ObjectId playerId = invalidObjectId, const Nickname& nickname = L"") : 
		accountId_(accountId),
		playerId_(playerId),
		nickname_(nickname) {}

	void reset() {
		accountId_ = invalidAccountId;
		playerId_ = invalidObjectId;
		nickname_.clear();
	}

	bool isValid() const {
		return isValidAccountId(accountId_) && isValidObjectId(playerId_) && ! nickname_.empty();
	}

	template <typename Stream>
	void serialize(Stream& stream) {
		stream & accountId_ & playerId_ & nickname_;
	}
};

typedef sne::srpc::RVector<BlockInfo> BlockInfos;

} // namespace gideon 