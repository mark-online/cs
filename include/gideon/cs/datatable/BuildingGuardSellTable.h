#pragma once

#include <gideon/cs/shared/data/BuildingInfo.h>
#include <gideon/cs/shared/data/BuildingGuardInfo.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

typedef sne::core::Set<BuildingGuardCode> GuardSellList;

/**
 * @class BuildingGuardSellTable
 *
 */
class GIDEON_CS_API BuildingGuardSellTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(BuildingGuardSellTable);

public:
    typedef sne::core::HashMap<BuildingCode, GuardSellList> SellListMap;

public:
    virtual ~BuildingGuardSellTable() {}

public:
    virtual const GuardSellList* getSellList(BuildingCode code) const = 0;

    virtual const SellListMap& getSellListMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define BUILDING_GUARD_SELL_TABLE gideon::datatable::BuildingGuardSellTable::instance()
