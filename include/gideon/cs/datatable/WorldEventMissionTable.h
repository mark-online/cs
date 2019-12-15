#pragma once

#include <gideon/cs/datatable/template/world_event_mission_table.hxx>
#include <gideon/cs/shared/data/WorldEventInfo.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>


namespace gideon { namespace datatable {

/**
 * @class QuestTable
 *
 */
class GIDEON_CS_API WorldEventMissionTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(WorldEventMissionTable);
public:
    typedef sne::core::Vector<const gdt::world_event_mission_t*> WorldEventMissions;
    typedef sne::core::HashMap<uint32_t, WorldEventMissions> WorldEventPhaseMap;
    typedef sne::core::HashMap<WorldEventCode, WorldEventPhaseMap> WorldEventMissionMap;
    typedef sne::core::HashMap<WorldEventMissionCode, const gdt::world_event_mission_t*> MissionMap;

public:
    virtual ~WorldEventMissionTable() {}

public:
    virtual const WorldEventPhaseMap* getWorldEventPhaseMap(WorldEventCode code) const = 0;

    virtual const WorldEventMissions* getWorldEventMissions(WorldEventCode code, uint32_t eventPhase) const = 0;

    virtual const gdt::world_event_mission_t* getWorldEventMissionTemplate(WorldEventMissionCode code) const = 0;

    virtual const WorldEventMissionMap& getWorldEventMissionsMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define WORLD_EVENT_MISSION_TABLE gideon::datatable::WorldEventMissionTable::instance()