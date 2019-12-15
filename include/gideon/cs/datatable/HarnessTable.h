#pragma once

#include <gideon/cs/datatable/template/Harness_table.hxx>
#include <gideon/cs/shared/data/VehicleInfo.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>


namespace gideon { namespace datatable {

/**
 * @class HarnessTable
 *
 */
class GIDEON_CS_API HarnessTable : public boost::noncopyable
{
public:
	SNE_DECLARE_SINGLETON(HarnessTable);

public:
    typedef sne::core::HashMap<HarnessCode, const gdt::harness_t*> HarnessMap;

public:
    virtual ~HarnessTable() {}

public:										 
    virtual const gdt::harness_t* getHarness(HarnessCode code) const = 0;

    virtual const HarnessMap& getHarnessMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define HARNESS_TABLE gideon::datatable::HarnessTable::instance()