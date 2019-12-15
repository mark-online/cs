#pragma once

#include <gideon/cs/datatable/ItemOptionTable.h>
#include <gideon/cs/datatable/template/item_option_table.hxx>
#include <algorithm>

namespace gideon { namespace datatable {

/**
 * @class ItemOptionTable
 *
 */
class ItemOptionTableImpl : public ItemOptionTable
{
public:
    ItemOptionTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            itemOptionTable_ =
                gdt::item_option_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::item_option_t& item_option : itemOptionTable_->item_option_template()) {
                ItemOptionInfoList optionList;
                EffectScriptType type1 = toEffectScriptType(item_option.effect_script_type_1());
                if (isValid(type1)) {
                    optionList.push_back(ItemOptionInfo(type1, item_option.min_value_1(), item_option.max_value_1()));
                }
                EffectScriptType type2 = toEffectScriptType(item_option.effect_script_type_2());
                if (isValid(type2)) {
                    optionList.push_back(ItemOptionInfo(type2, item_option.min_value_2(), item_option.max_value_2()));
                }
                EffectScriptType type3 = toEffectScriptType(item_option.effect_script_type_3());
                if (isValid(type3)) {
                    optionList.push_back(ItemOptionInfo(type3, item_option.min_value_3(), item_option.max_value_3()));
                }
                EffectScriptType type4 = toEffectScriptType(item_option.effect_script_type_4());
                if (isValid(type4)) {
                    optionList.push_back(ItemOptionInfo(type4, item_option.min_value_4(), item_option.max_value_4()));
                }
                EffectScriptType type5 = toEffectScriptType(item_option.effect_script_type_5());
                if (isValid(type5)) {
                    optionList.push_back(ItemOptionInfo(type5, item_option.min_value_5(), item_option.max_value_5()));
                }
                EffectScriptType type6 = toEffectScriptType(item_option.effect_script_type_6());
                if (isValid(type6)) {
                    optionList.push_back(ItemOptionInfo(type6, item_option.min_value_6(), item_option.max_value_6()));
                }
                itemOptionMap_.emplace(item_option.item_option_id(), optionList);
            }
            isLoaded_ = true;

            ItemOptionTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual ItemOptionInfoList getItemOptionInfoList(ItemOptionId id, uint32_t optionCount)
    {        
        ItemOptionInfoList returnList;
        ItemOptionInfoListMap::iterator pos = itemOptionMap_.find(id);
        if (pos != itemOptionMap_.end()) {
            ItemOptionInfoList& optionList = (*pos).second;
            if (optionList.size() < optionCount) {
                return returnList;
            }
            std::random_shuffle(optionList.begin(), optionList.end());
            for (const ItemOptionInfo& info : optionList) {
                returnList.push_back(info);
                if (optionCount == returnList.size()) {
                    return returnList;
                }
            }
        }
        return returnList;
    }

    virtual const ItemOptionInfoListMap& getItemOptionInfoListMap() const {
        return itemOptionMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::item_option_table> itemOptionTable_;
    ItemOptionInfoListMap itemOptionMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
