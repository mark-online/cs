#pragma once

#include <gideon/cs/datatable/template/Vehicle_table.hxx>
#include <gideon/cs/shared/data/VehicleInfo.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>


namespace gideon { namespace datatable {

/**
 * @class VehicleTable
 *
 */
class GIDEON_CS_API VehicleTable : public boost::noncopyable
{
public:
	SNE_DECLARE_SINGLETON(VehicleTable);

public:
    typedef sne::core::HashMap<VehicleCode, const gdt::vehicle_t*> VehicleMap;

public:
    virtual ~VehicleTable() {}

public:										 
    virtual const gdt::vehicle_t* getVehicle(VehicleCode code) const = 0;

    virtual const VehicleMap& getVehicleMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define VEHICLE_TABLE gideon::datatable::VehicleTable::instance()