#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/shared/data/ItemInfo.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @class ItemSuffixInfo
 *
 */
class ItemSuffixInfo
{
public:
    typedef sne::core::Vector<ItemOptionId> ItemOptionIds;
public:    
    ItemSuffixInfo(uint32_t optionCount = 0, const ItemOptionIds& optionIds = ItemOptionIds()) :
        optionCount_(optionCount),
        optionIds_(optionIds)
    {
    }

    bool isValid() const {
        return (! optionIds_.empty()) && optionCount_ > 0; 
    }

    ItemOptionId getRandomItemOptionId() const {
        if (optionIds_.empty()) {
            return invalidItemOptionId;
        }
        const int maxRandValue = static_cast<uint32_t>(optionIds_.size() - 1);
        uint32_t randIndex = esut::random(0, maxRandValue);
        return optionIds_[randIndex];
    }

    uint32_t getOptionCount() const {
        return optionCount_;
    }
private:
    ItemOptionIds optionIds_;
    const uint32_t optionCount_;

};


/**
 * @class ItemSuffixTable
 */
class GIDEON_CS_API ItemSuffixTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(ItemSuffixTable);

public:    
    typedef sne::core::HashMap<ItemSuffixId, ItemSuffixInfo> ItemSuffixMap;

public:
    virtual ~ItemSuffixTable() {}

public:
    virtual const ItemSuffixInfo* getItemSuffixInfo(ItemSuffixId suffixId) = 0;

    virtual const ItemSuffixMap& getItemSuffixMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
    
};

}} // namespace gideon { namespace datatable {

#define ITEM_SUFFIX_TABLE gideon::datatable::ItemSuffixTable::instance()
