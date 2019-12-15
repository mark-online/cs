#pragma once

#include "Code.h"
#include <cassert>

namespace gideon {

typedef uint32_t WorldDropSuffixId;
const WorldDropSuffixId invalidWorldDropSuffixId= 0;

inline bool isValidWorldDropSuffixId(WorldDropSuffixId id)
{
    return invalidWorldDropSuffixId != id;
}

typedef uint32_t WorldDropId;
const WorldDropId invalidWorldDropId = 0;

inline bool isValidWorldDropId(WorldDropId id)
{
    return invalidWorldDropId != id;
}

typedef sne::core::Vector<WorldDropId> WorldDropIds;

typedef uint32_t ItemDropId;
const ItemDropId invalidItemDropId = invalidDataCode;

inline bool isValidItemDropId(ItemDropId id)
{
    return invalidItemDropId != id;
}


/// 유효한 ItemDrop 코드인가?
enum ItemDropType
{
    idtNone,
    idtItem,
    idtExp,
    idtGameMoney,
    idtCount,
};

template <typename T>
inline ItemDropType toItemDropType(T value)
{
    return static_cast<ItemDropType>(static_cast<uint8_t>(value));
}


inline bool isValid(ItemDropType type)
{
    return idtNone < type && type < idtCount;
}
     

} // namespace gideon {
