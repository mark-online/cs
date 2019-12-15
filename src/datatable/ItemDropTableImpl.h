#pragma once

#include <gideon/cs/datatable/ItemDropTable.h>
#include <gideon/cs/datatable/template/item_drop_table.hxx>

namespace gideon { namespace datatable {

namespace {

/**
 * @class ItemDropHelper
 */
class ItemDropHelper
{
    enum { dropItemCount = 5 };
public:
    ItemDropHelper(const gdt::item_drop_t& itemDrop) :
        itemDrop_(itemDrop) {}

    ItemDropInfos getItemDropInfos() const {
        ItemDropInfos itemDropInfos;
        itemDropInfos.reserve(dropItemCount);
        for (int i = 1; i <= dropItemCount; ++i) {
            const ItemDropInfo itemDropInfo(getItemDropType(i), getItemCode(i), getMinValue(i), getMaxValue(i), getDropPct(i));
            if (itemDropInfo.isValid()) {
                itemDropInfos.push_back(itemDropInfo);
            }                    
        }
        return itemDropInfos;
    }

private:
    ItemDropType getItemDropType(int num) const {
        switch (num) {
        case 1:
            return toItemDropType(itemDrop_.drop_type_1());
        case 2:
            return toItemDropType(itemDrop_.drop_type_2());
        case 3:
            return toItemDropType(itemDrop_.drop_type_3());
        case 4:
            return toItemDropType(itemDrop_.drop_type_4());
        case 5:
            return toItemDropType(itemDrop_.drop_type_5());
        default:
            assert(false);
            break;
        }
        return idtNone;
    }

    DataCode getItemCode(int num) const {
        switch (num) {
        case 1:
            return itemDrop_.item_code_1();
        case 2:
            return itemDrop_.item_code_2();
        case 3:
            return itemDrop_.item_code_3();
        case 4:
            return itemDrop_.item_code_4();
        case 5:
            return itemDrop_.item_code_5();
        default:
            assert(false);
            break;
        }
        return invalidDataCode;
    }

    uint32_t getMinValue(int num) const {
        switch (num) {
        case 1:
            return itemDrop_.min_value_1();
        case 2:
            return itemDrop_.min_value_2();
        case 3:
            return itemDrop_.min_value_3();
        case 4:
            return itemDrop_.min_value_4();
        case 5:
            return itemDrop_.min_value_5();
        default:
            assert(false);
            break;
        }
        return invalidDataCode;
    }

    uint32_t getMaxValue(int num) const {
        switch (num) {
        case 1:
            return itemDrop_.max_value_1();
        case 2:
            return itemDrop_.max_value_2();
        case 3:
            return itemDrop_.max_value_3();
        case 4:
            return itemDrop_.max_value_4();
        case 5:
            return itemDrop_.max_value_5();
        default:
            assert(false);
            break;
        }
        return invalidDataCode;
    }

    uint16_t getDropPct(int num) const {
        switch (num) {
        case 1:
            return static_cast<uint16_t>(itemDrop_.drop_pct_1());
        case 2:
            return static_cast<uint16_t>(itemDrop_.drop_pct_2());
        case 3:
            return static_cast<uint16_t>(itemDrop_.drop_pct_3());
        case 4:
            return static_cast<uint16_t>(itemDrop_.drop_pct_4());
        case 5:
            return static_cast<uint16_t>(itemDrop_.drop_pct_5());
        default:
            assert(false);
            break;
        }
        return invalidDataCode;
    }

private:
    const gdt::item_drop_t& itemDrop_;
};

} // namespace {

/**
 * @class ItemDropTableImpl
 *
 */
class ItemDropTableImpl : public ItemDropTable
{
public:
    ItemDropTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            itemDropTable_ =
                gdt::item_drop_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::item_drop_t& drop : itemDropTable_->item_drop_template()) {
                const ItemDropHelper dropHelper(drop);                
                itemDropMap_.emplace(drop.item_drop_id(), 
                    ItemDropTemplate(drop.item_drop_id(), dropHelper.getItemDropInfos()));
            }
            isLoaded_ = true;

            ItemDropTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const ItemDropTemplate* getItemDrop(ItemDropId code) const {
        const ItemDropMap::const_iterator pos = itemDropMap_.find(code);
        if (pos != itemDropMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const ItemDropMap& getItemDropMap() const {
        return itemDropMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::item_drop_table> itemDropTable_;
    ItemDropMap itemDropMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
