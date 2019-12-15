#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/shared/data/ItemDropInfo.h>
#include <gideon/cs/shared/data/Rate.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

struct ItemDropInfo
{
    ItemDropType itemDropType_;
	DataCode itemCode_;
	uint32_t minValue_;
	uint32_t maxValue_;
    uint16_t dropPct_;
	
	ItemDropInfo(ItemDropType itemDropType = idtNone, DataCode itemCode = invalidDataCode,
		uint32_t minValue = 0, uint32_t maxValue = 0, uint16_t dropPct = 0) :
        itemDropType_(itemDropType),
		itemCode_(itemCode),
		minValue_(minValue),
		maxValue_(maxValue),
        dropPct_(dropPct)
	{
	}

	bool isValid() const {
        if (! gideon::isValid(itemDropType_)) {
            return false;
        }

        if (itemDropType_ == idtItem && ! isValidDataCode(itemCode_)) {
            assert(false);
            return false;
        }

        if (dropPct_ <= 0 && minValue_ <= 0 && maxValue_ <= 0) {
            assert(false);
            return false;
        }

		if( minValue_ > maxValue_) {
            assert(false);
            return false;
        }
        return true;
	}

    bool shouldDrop() const {
        return isSuccessRate(dropPct_);
    }

    uint32_t getRandomValue() const {
        uint32_t value = esut::random(minValue_, maxValue_);
        return value > 0 ? value : 1;
    }
    
};

typedef sne::core::Vector<ItemDropInfo> ItemDropInfos;


/**
 * @class ItemDropTemplate
 */
class ItemDropTemplate
{
public:
    ItemDropTemplate(ItemDropId itemDropCode, const ItemDropInfos& itemDropInfos) :
		itemDropCode_(itemDropCode),
        itemDropInfos_(itemDropInfos) {}

	ItemDropId getItemDropId() const {
		return itemDropCode_;
	}

    const ItemDropInfos& getItemDropInfos() const {
        return itemDropInfos_;
    }

private:	
	ItemDropId itemDropCode_;
    ItemDropInfos itemDropInfos_;
};


/**
 * @class ItemDropTable
 *
 */
class GIDEON_CS_API ItemDropTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(ItemDropTable);

public:
    typedef sne::core::HashMap<ItemDropId, ItemDropTemplate> ItemDropMap;

public:
    virtual ~ItemDropTable() {}

public:
    virtual const ItemDropTemplate* getItemDrop(ItemDropId code) const = 0;

    virtual const ItemDropMap& getItemDropMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define ITEM_DROP_TABLE gideon::datatable::ItemDropTable::instance()
