#pragma once

#include "ItemInfo.h"
#include "Money.h"
#include "LevelInfo.h"

namespace gideon {

/***
 * enum LootInvenItemType
 ***/
enum LootInvenItemType
{
	liitUnknown,
	liitGameMoney,
	liitExp,
	liitItem,
    liitCount,
};


inline bool isValid(LootInvenItemType type)
{
    return liitUnknown < type && type < liitCount;
}


/**
 * @enum LootInvenId
 */
enum LootInvenId
{
    invalidLootInvenId = 0,
    firstLootInvenId = 1
};


inline bool isValid(LootInvenId id)
{
	return firstLootInvenId < id;
}


template <typename T>
inline LootInvenId toLootInvenId(T value)
{
	return static_cast<LootInvenId>(value);
}

/***
 * struct LootInvenItemInfo
 ***/
struct LootInvenItemInfo
{
	LootInvenItemType type_;
	GameMoney money_;
	ExpPoint exp_;
	BaseItemInfo baseItemInfo_;
	EquipItemInfo equipItemInfo_;
    AccessoryItemInfo accessoryInfo_;    

    explicit LootInvenItemInfo(LootInvenItemType type = liitUnknown) :
		type_(type),
        money_(0),
        exp_(ceMin) {}

	void reset() {
		type_ = liitUnknown;
		money_ = 0;
		exp_ = ceMin;
		baseItemInfo_.reset();
		equipItemInfo_.reset();
        equipItemInfo_.reset();
	}

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & type_;
		if (type_ == liitGameMoney) {
			stream & money_;
		}
		else if (type_ == liitExp) {
			stream & exp_;
		}
		else if (type_ == liitItem) {
			stream & baseItemInfo_;
			if (baseItemInfo_.isEquipment()) {
				stream & equipItemInfo_;
			} 
            else if (baseItemInfo_.isAccessory()) {
                stream & accessoryInfo_;
            }
		}

	}
};

typedef sne::srpc::RHashMap<LootInvenId, LootInvenItemInfo> LootInvenItemInfoMap;

} // namespace gideon {


namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::LootInvenItemType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::LootInvenItemType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::LootInvenItemType>(value);
    return lhs;
}

inline OStream& operator<<(OStream& lhs, gideon::LootInvenId rhs)
{
	lhs << static_cast<uint8_t>(rhs);
	return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::LootInvenId& rhs)
{
	uint8_t value;
	lhs >> value;
	rhs = static_cast<gideon::LootInvenId>(value);
	return lhs;
}


}} // namespace sne { namespace core {
