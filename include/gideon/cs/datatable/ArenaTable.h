#pragma once

#include <gideon/cs/datatable/template/arena_table.hxx>
#include <gideon/cs/shared/data/WorldInfo.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @class ArenaTable
 *
 */
class GIDEON_CS_API ArenaTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(ArenaTable);

public:
    typedef sne::core::HashMap<MapCode, const gdt::arena_t*> ArenaMap;

public:
    virtual ~ArenaTable() {}

public:
    virtual const gdt::arena_t* getArenaTemplate(MapCode code) const = 0;

    virtual const ArenaMap& getArenaMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define ARENA_TABLE gideon::datatable::ArenaTable::instance()
