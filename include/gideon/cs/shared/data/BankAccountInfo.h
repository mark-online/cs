#pragma once

#include "InventoryInfo.h"
#include "Money.h"

namespace gideon {

const SlotId maxBankSlotId = 40;

inline bool isBankStorable(SlotId slotId)
{
	return firstSlotId <= slotId && slotId <= maxBankSlotId;
}

/***
 * @struct BankAccountInfo
 ***/
struct BankAccountInfo : public InventoryInfo
{
	GameMoney gameMoney_;
	
	BankAccountInfo() {}

	void reset() {
		InventoryInfo::reset();
		gameMoney_ = gameMoneyMin;
	}

	template <typename Stream>
	void serialize(Stream& stream) {
		InventoryInfo::serialize(stream);
		stream & gameMoney_;
	}
};

} // namespace gideon {
