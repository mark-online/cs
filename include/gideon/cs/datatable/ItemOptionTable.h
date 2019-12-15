#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/shared/data/EffectInfo.h>
#include <gideon/cs/shared/data/ItemScript.h>
#include <gideon/cs/shared/data/Rate.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>


namespace gideon { namespace datatable {

/**
 * @struct ItemOptionInfo
 *
 */
struct ItemOptionInfo
{
    EffectScriptType script_;
    int32_t minValue_;
    int32_t maxValue_;

    explicit ItemOptionInfo(EffectScriptType script = estUnknown,
        int32_t minValue = 0, int32_t maxValue = 0) :
        script_(script),
        minValue_(minValue),
        maxValue_(maxValue)
    {
    }
        
    ItemScriptInfo getRandomItemScriptInfo() const {
        return ItemScriptInfo(script_, esut::random(minValue_, maxValue_));
    }

};


typedef sne::core::Vector<ItemOptionInfo> ItemOptionInfoList;

/**
 * @class ItemOptionTable
 *
 */
class GIDEON_CS_API ItemOptionTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(ItemOptionTable);

public:    
    typedef sne::core::HashMap<ItemOptionId, ItemOptionInfoList> ItemOptionInfoListMap;

public:
    virtual ~ItemOptionTable() {}

public:
    virtual ItemOptionInfoList getItemOptionInfoList(ItemOptionId id, uint32_t optionCount) = 0;

    virtual const ItemOptionInfoListMap& getItemOptionInfoListMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;

};

}} // namespace gideon { namespace datatable {

#define ITEM_OPTION_TABLE gideon::datatable::ItemOptionTable::instance()
