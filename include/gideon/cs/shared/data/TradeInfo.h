#pragma once

#include "ObjectInfo.h"

namespace gideon {

typedef uint32_t TradeId;
const TradeId invalidTradeId = 0;


inline bool isValidTradeId(TradeId tradeId) 
{
	return invalidTradeId != tradeId;
}


} // namespace gideon {
