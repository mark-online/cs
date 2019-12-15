#pragma once

#include <gideon/cs/shared/data/TreasureInfo.h>
#include <gideon/cs/datatable/template/treasure_table.hxx>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @class TreasureTable
 *
 */
class GIDEON_CS_API TreasureTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(TreasureTable);

public:
	typedef sne::core::HashMap<TreasureCode, const gdt::treasure_t*> TreasureMap;

public:
    virtual ~TreasureTable() {}

public:
    virtual const gdt::treasure_t* getTreasure(TreasureCode code) const = 0;

    virtual const TreasureMap& getTreasureMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define TREASURE_TABLE gideon::datatable::TreasureTable::instance()
