#pragma once

#include <gideon/cs/datatable/WorldEventInvaderSpawnTable.h>

namespace gideon { namespace datatable {

/**
 * @class WorldEventInvaderSpawnTableImpl
 *
 */
class WorldEventInvaderSpawnTableImpl : public WorldEventInvaderSpawnTable
{
public:
    WorldEventInvaderSpawnTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            worldEventPositionSpawnTable_ =
                gdt::world_event_invader_spawn_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::world_event_invader_spawn_t& spawn :
                worldEventPositionSpawnTable_->world_event_invader_spawn_template()) {
                PhaseSpawnMap::iterator pos = phaseSpawnMap_.find(spawn.mission_code());
                if (pos != phaseSpawnMap_.end()) {
                    SpawnsMap& spawnsMap = (*pos).second;
                    add(spawnsMap, spawn);
                }
                else {
                    SpawnsMap spawnsMap;
                    add(spawnsMap, spawn);
                    phaseSpawnMap_.emplace(spawn.mission_code(), spawnsMap);
                }
            }
            WorldEventInvaderSpawnTable::instance(this);
            isLoaded_ = true;
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const Spawns* getSpawns(WorldEventMissionCode missionCode, uint32_t missionPhase) const {
        const PhaseSpawnMap::const_iterator pos = phaseSpawnMap_.find(missionCode);
        if (pos != phaseSpawnMap_.end()) {
            const SpawnsMap& spawnMap = (*pos).second;
            SpawnsMap::const_iterator pos2 = spawnMap.find(missionPhase);
            if (pos2 != spawnMap.end()) {
                return &(*pos2).second;
            }
            return nullptr;
        }
        return nullptr;
    }

    virtual const PhaseSpawnMap& getPhaseSpawnMap() const {
        return phaseSpawnMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    void add(SpawnsMap& spawnsMap, const gdt::world_event_invader_spawn_t& spawn) {
        SpawnsMap::iterator pos = spawnsMap.find(spawn.mission_phase());
        if (pos != spawnsMap.end()) {
            Spawns& spawns = (*pos).second;
            spawns.push_back(&spawn);
        }
        else {
            Spawns spawns;
            spawns.push_back(&spawn);
            spawnsMap.insert(SpawnsMap::value_type(spawn.mission_phase(), spawns));
        }
    }


private:
    std::unique_ptr<gdt::world_event_invader_spawn_table> worldEventPositionSpawnTable_;
    PhaseSpawnMap phaseSpawnMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
