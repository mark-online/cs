#pragma once

#include <gideon/cs/datatable/template/world_event_mission_spawn_table.hxx>
#include <gideon/cs/shared/data/WorldEventInfo.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>


namespace gideon { namespace datatable {

/**
 * @class WorldEventMissionSpawnTable
 *
 */
class GIDEON_CS_API WorldEventMissionSpawnTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(WorldEventMissionSpawnTable);
public:
    typedef sne::core::Vector<const gdt::world_event_mission_spawn_t*> Spawns;
    typedef sne::core::HashMap<uint32_t, Spawns> SpawnsMap;
    typedef sne::core::HashMap<WorldEventMissionCode, SpawnsMap> PhaseSpawnMap;

public:
    virtual ~WorldEventMissionSpawnTable() {}

public:
    virtual const Spawns* getSpawns(WorldEventMissionCode mission, uint32_t missionPhase) const = 0;

    virtual const PhaseSpawnMap& getPhaseSpawnMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define WORLD_EVENT_MISSION_SPAWN_TABLE gideon::datatable::WorldEventMissionSpawnTable::instance()