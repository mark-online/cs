#pragma once

#include <gideon/cs/datatable/template/resources_production_table.hxx>
#include <gideon/cs/shared/data/ItemInfo.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/// ResourcesProduction Code.
typedef uint32_t ResourcesProductionCode;
const ResourcesProductionCode invalidResourcesProductionCode = 0;

/// is valid AccountId
inline bool isValidResourcesProductionCode(ResourcesProductionCode resourcesProductionCode)
{
    return invalidResourcesProductionCode != resourcesProductionCode;
}

/***
 * @class ResourcesProductionInfo
 ***/
struct ResourcesProductionInfo
{
    BaseItemInfo itemInfo_;
    sec_t produceTime_;

    ResourcesProductionInfo(const BaseItemInfo& itemInfo,
        sec_t produceTime) :
        itemInfo_(itemInfo),
        produceTime_(produceTime)
    {
    }
};

typedef sne::core::Vector<ResourcesProductionInfo> ResourcesProductionInfos;

/***
 * @class ResourcesProductionTemplate
 ***/
class ResourcesProductionTemplate
{
public:
    ResourcesProductionTemplate(const gdt::resources_production_t& resourcesProduction) :
        resourcesProduction_(&resourcesProduction)        
    {
        initResourcesProductionInfos();
    }

    ~ResourcesProductionTemplate() {}
    
    const ResourcesProductionInfos& getResourcesProductionInfos() const {
        return resourcesProductionInfos_;
    }

    const ResourcesProductionInfo* getResourcesProductionInfo(DataCode dataCode) const {
        ResourcesProductionInfos::const_iterator pos = resourcesProductionInfos_.begin();
        const ResourcesProductionInfos::const_iterator end = resourcesProductionInfos_.end();
        while( pos != end )
        {
            const ResourcesProductionInfo& info = (*pos);

            if(info.itemInfo_.itemCode_ == dataCode)
                return &info;
            else 
                ++pos;
        }

        return nullptr;
    }

private:
    void initResourcesProductionInfos() {
        DataCode itemCode1 = resourcesProduction_->produce_item_code_1();
        DataCode itemCode2 = resourcesProduction_->produce_item_code_2();
        DataCode itemCode3 = resourcesProduction_->produce_item_code_3();
        DataCode itemCode4 = resourcesProduction_->produce_item_code_4();
        DataCode itemCode5 = resourcesProduction_->produce_item_code_5();
        if (isValidDataCode(itemCode1)) {
            resourcesProductionInfos_.push_back(ResourcesProductionInfo(BaseItemInfo(itemCode1,
                static_cast<uint8_t>(resourcesProduction_->produce_count_1())), resourcesProduction_->produce_sec_1()));
        }
        if (isValidDataCode(itemCode2)) {
            resourcesProductionInfos_.push_back(ResourcesProductionInfo(BaseItemInfo(itemCode2,
                static_cast<uint8_t>(resourcesProduction_->produce_count_2())), resourcesProduction_->produce_sec_2()));
        }
        if (isValidDataCode(itemCode3)) {
            resourcesProductionInfos_.push_back(ResourcesProductionInfo(BaseItemInfo(itemCode3,
                static_cast<uint8_t>(resourcesProduction_->produce_count_3())), resourcesProduction_->produce_sec_3()));
        }
        if (isValidDataCode(itemCode4)) {
            resourcesProductionInfos_.push_back(ResourcesProductionInfo(BaseItemInfo(itemCode4,
                static_cast<uint8_t>(resourcesProduction_->produce_count_4())), resourcesProduction_->produce_sec_4()));
        }
        if (isValidDataCode(itemCode5)) {
            resourcesProductionInfos_.push_back(ResourcesProductionInfo(BaseItemInfo(itemCode5,
                static_cast<uint8_t>(resourcesProduction_->produce_count_5())), resourcesProduction_->produce_sec_5()));
        }
    }

private:
    const gdt::resources_production_t* resourcesProduction_;
    ResourcesProductionInfos resourcesProductionInfos_;  
};


/**
 * @class AnchorTable
 *
 */
class GIDEON_CS_API ResourcesProductionTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(ResourcesProductionTable);

public:
    typedef sne::core::HashMap<ResourcesProductionCode, ResourcesProductionTemplate> ResourcesProductionMap;

public:
    virtual ~ResourcesProductionTable() {}

public:
    virtual const ResourcesProductionTemplate* getResourcesProductionTemplate(ResourcesProductionCode code) const = 0;

    virtual const ResourcesProductionMap& getResourcesProductionMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define RESOURCES_PRODUCTION_TABLE gideon::datatable::ResourcesProductionTable::instance()
