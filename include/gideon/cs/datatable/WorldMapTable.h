#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/datatable/template/world_map_table.hxx>
#include <gideon/cs/shared/data/WorldInfo.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @class WorldMapTable
 *
 */
class GIDEON_CS_API WorldMapTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(WorldMapTable);

public:
    typedef sne::core::HashMap<MapCode, const gdt::map_t*> WorldMapMap;

public:
    virtual ~WorldMapTable() {}

public:
    virtual const gdt::map_t* getMap(MapCode code) const = 0;

    virtual const WorldMapMap& getWorldMapMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define WORLDMAP_TABLE gideon::datatable::WorldMapTable::instance()
