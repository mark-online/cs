#pragma once

#include <gideon/cs/datatable/BuildingTable.h>

namespace gideon { namespace datatable {

/**
 * @class BuildingTableImpl
 *
 */
class BuildingTableImpl : public BuildingTable
{
public:
    BuildingTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            buildingTable_ =
                gdt::building_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::building_t& building : buildingTable_->building_template()) {
                buildingMap_.emplace(static_cast<AnchorCode>(building.building_code()),
					BuildingTemplate(building));
            }
            isLoaded_ = true;

            BuildingTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }
	virtual ~BuildingTableImpl() {}

public:
    virtual const BuildingTemplate* getBuildingTemplate(AnchorCode code) const {
        const BuildingMap::const_iterator pos = buildingMap_.find(code);
        if (pos != buildingMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const BuildingMap& getBuildingMap() const {
        return buildingMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::building_table> buildingTable_;
    BuildingMap buildingMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
