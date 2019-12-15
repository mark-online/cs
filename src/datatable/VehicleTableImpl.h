#pragma once

#include <gideon/cs/datatable/VehicleTable.h>

namespace gideon { namespace datatable {

/**
 * @class VehicleTableImpl
 *
 */
class VehicleTableImpl : public VehicleTable
{
public:
    VehicleTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            vehicleTable_ =
                gdt::vehicle_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::vehicle_t& vehicle : vehicleTable_->vehicle_template()) {
                vehicleMap_.emplace(vehicle.vehicle_code(), &vehicle);
            }
            VehicleTable::instance(this);
            isLoaded_ = true;
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const gdt::vehicle_t* getVehicle(VehicleCode code) const {
        const VehicleMap::const_iterator pos = vehicleMap_.find(code);
        if (pos != vehicleMap_.end()) {
            return (*pos).second;
        }
        return nullptr;
    }

    virtual const VehicleMap& getVehicleMap() const {
        return vehicleMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::vehicle_table> vehicleTable_;
    VehicleMap vehicleMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
