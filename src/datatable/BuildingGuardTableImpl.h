#pragma once

#include <gideon/cs/datatable/BuildingGuardTable.h>

namespace gideon { namespace datatable {

/**
 * @class BuildingGuardTableImpl
 *
 */
class BuildingGuardTableImpl : public BuildingGuardTable
{
public:
    BuildingGuardTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            buildingGuardTable_  =
                gdt::building_guard_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::building_guard_t& guard : buildingGuardTable_->building_guard_template()) {
                buildingGuardMap_.emplace(guard.building_guard_code(), &guard);
            }
            BuildingGuardTable::instance(this);
            isLoaded_ = true;
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const gdt::building_guard_t* getBuildingGuard(BuildingGuardCode code) const {
        const BuildingGuardMap::const_iterator pos = buildingGuardMap_.find(code);
        if (pos != buildingGuardMap_.end()) {
            return (*pos).second;
        }
        return nullptr;
    }

    virtual const BuildingGuardMap& getBuildingGuardMap() const {
        return buildingGuardMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::building_guard_table> buildingGuardTable_;
    BuildingGuardMap buildingGuardMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
