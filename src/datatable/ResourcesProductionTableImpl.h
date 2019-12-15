#pragma once

#include <gideon/cs/datatable/ResourcesProductionTable.h>

namespace gideon { namespace datatable {

/**
 * @class ResourcesProductionTableImpl
 *
 */
class ResourcesProductionTableImpl : public ResourcesProductionTable
{
public:
    ResourcesProductionTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            resourcesProductionTable_ =
                gdt::resources_production_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::resources_production_t& resourcesProduction :
                resourcesProductionTable_->resources_production_template()) {
                resourcesProductionMap_.emplace(
                    static_cast<ResourcesProductionCode>(resourcesProduction.resources_production_code()),
                    ResourcesProductionTemplate(resourcesProduction));
            }
            isLoaded_ = true;

            ResourcesProductionTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }
    virtual ~ResourcesProductionTableImpl() {
    }

public:
    virtual const ResourcesProductionTemplate*
        getResourcesProductionTemplate(ResourcesProductionCode code) const {
        const ResourcesProductionMap::const_iterator pos = resourcesProductionMap_.find(code);
        if (pos != resourcesProductionMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const ResourcesProductionMap& getResourcesProductionMap() const {
        return resourcesProductionMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::resources_production_table> resourcesProductionTable_;
    ResourcesProductionMap resourcesProductionMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
