#pragma once

#include <gideon/cs/datatable/template/building_guard_table.hxx>
#include <gideon/cs/shared/data/BuildingGuardInfo.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>


namespace gideon { namespace datatable {

/**
 * @class BuildingGuardTable
 *
 */
class GIDEON_CS_API BuildingGuardTable : public boost::noncopyable
{
public:
	SNE_DECLARE_SINGLETON(BuildingGuardTable);

public:
    typedef sne::core::HashMap<BuildingGuardCode, const gdt::building_guard_t*> BuildingGuardMap;

public:
    virtual ~BuildingGuardTable() {}

public:
    virtual const gdt::building_guard_t* getBuildingGuard(BuildingGuardCode code) const = 0;

    virtual const BuildingGuardMap& getBuildingGuardMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define BUILDING_GUARD_TABLE gideon::datatable::BuildingGuardTable::instance()