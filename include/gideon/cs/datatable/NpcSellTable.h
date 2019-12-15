#pragma once

#include <gideon/cs/shared/data/NpcInfo.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

typedef sne::core::Set<DataCode> SellList;

/**
 * @class NpcSellTable
 *
 */
class GIDEON_CS_API NpcSellTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(NpcSellTable);

public:
    typedef sne::core::HashMap<NpcCode, SellList> SellListMap;

public:
    virtual ~NpcSellTable() {}

public:
    virtual const SellList* getSellList(NpcCode code) const = 0;

    virtual const SellListMap& getSellListMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define NPC_SELL_TABLE gideon::datatable::NpcSellTable::instance()
