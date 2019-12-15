#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/datatable/template/dominion_region_table.hxx>
#include <gideon/cs/shared/data/DeviceInfo.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @class RegionCoordinates
 *
 */
class GIDEON_CS_API DominionRegionTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(DominionRegionTable);

public:
    typedef sne::core::Vector< const gdt::dominion_region_t* > DominionRegionsList;

public:
    virtual ~DominionRegionTable() {}

public:
    virtual const DominionRegionsList& getDominionRegionList() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define DOMINION_REGION_TABLE gideon::datatable::DominionRegionTable::instance()