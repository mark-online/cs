#pragma once

#include <gideon/cs/shared/data/HarvestInfo.h>
#include <gideon/cs/datatable/template/harvest_table.hxx>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>


namespace gideon { namespace datatable {

/**
 * @class HarvestTable
 *
 */
class GIDEON_CS_API HarvestTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(HarvestTable);

public:
	typedef sne::core::HashMap<HarvestCode, const gdt::harvest_t*> HarvestMap;

public:
    virtual ~HarvestTable() {}

public:
    virtual const gdt::harvest_t* getHarvest(HarvestCode code) const = 0;

    virtual const HarvestMap& getHarvestMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define HARVEST_TABLE gideon::datatable::HarvestTable::instance()
