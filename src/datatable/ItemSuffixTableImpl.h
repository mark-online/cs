#pragma once

#include <gideon/cs/datatable/ItemSuffixTable.h>
#include <gideon/cs/datatable/template/item_suffix_table.hxx>

namespace gideon { namespace datatable {

/**
 * @class ItemSuffixTableImpl
 *
 */
class ItemSuffixTableImpl : public ItemSuffixTable
{
public:
    ItemSuffixTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            itemSuffixTable_ =
                gdt::item_suffix_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::item_suffix_t& item_suffix : itemSuffixTable_->item_suffix_template()) {
                ItemSuffixInfo::ItemOptionIds optionIds;
                if (isValidItemOptionId(item_suffix.item_option_id_1())) {
                    optionIds.push_back(item_suffix.item_option_id_1());
                }
                if (isValidItemOptionId(item_suffix.item_option_id_2())) {
                    optionIds.push_back(item_suffix.item_option_id_2());
                }
                if (isValidItemOptionId(item_suffix.item_option_id_3())) {
                    optionIds.push_back(item_suffix.item_option_id_3());
                }
                ItemSuffixInfo suffixInfo(item_suffix.item_option_count(), optionIds);
                itemSuffixMap_.emplace(item_suffix.item_suffix_id(), suffixInfo);
            }
            isLoaded_ = true;

            ItemSuffixTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const ItemSuffixInfo* getItemSuffixInfo(ItemSuffixId suffixId) {
        ItemSuffixMap::iterator pos = itemSuffixMap_.find(suffixId);
        if (pos != itemSuffixMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const ItemSuffixMap& getItemSuffixMap() const {
        return itemSuffixMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::item_suffix_table> itemSuffixTable_;
    ItemSuffixMap itemSuffixMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
