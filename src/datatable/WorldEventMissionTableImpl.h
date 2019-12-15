#pragma once

#include <gideon/cs/datatable/WorldEventMissionTable.h>

namespace gideon { namespace datatable {

/**
 * @class WorldEventMissionTableImpl
 *
 */
class WorldEventMissionTableImpl : public WorldEventMissionTable
{
public:
    WorldEventMissionTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            worldEventMissionTable_ =
                gdt::world_event_mission_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::world_event_mission_t& mission :
                worldEventMissionTable_->world_event_mission_template()) {
                WorldEventMissionMap::iterator pos = worldEventMissionMap_.find(mission.world_event_code());
                if (pos != worldEventMissionMap_.end()) {
                    WorldEventPhaseMap& phaseMap = (*pos).second;
                    add(phaseMap, mission);
                }
                else {
                    WorldEventPhaseMap phaseMap;
                    add(phaseMap, mission);
                    worldEventMissionMap_.emplace(mission.world_event_code(), phaseMap);
                }
                missionMap_.emplace(mission.mission_code(), &mission);
            }
            WorldEventMissionTable::instance(this);
            isLoaded_ = true;
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const WorldEventPhaseMap* getWorldEventPhaseMap(WorldEventCode code) const {
        const WorldEventMissionMap::const_iterator pos = worldEventMissionMap_.find(code);
        if (pos != worldEventMissionMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }


    virtual const WorldEventMissions* getWorldEventMissions(WorldEventCode code, uint32_t eventPhase) const
    {
        const WorldEventMissionMap::const_iterator pos = worldEventMissionMap_.find(code);
        if (pos != worldEventMissionMap_.end()) {
            const WorldEventPhaseMap& phaseMap = (*pos).second;
            WorldEventPhaseMap::const_iterator pos2 = phaseMap.find(eventPhase);
            if (pos2 != phaseMap.end()) {
                return &(*pos2).second;
            }
        }
        return nullptr;
    }

    virtual const gdt::world_event_mission_t* getWorldEventMissionTemplate(WorldEventMissionCode code) const
    {
        const MissionMap::const_iterator pos = missionMap_.find(code);
        if (pos != missionMap_.end()) {
            return (*pos).second;
        }
        return nullptr;
    }

    virtual const WorldEventMissionMap& getWorldEventMissionsMap() const {
        return worldEventMissionMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    void add(WorldEventPhaseMap& phaseMap, const gdt::world_event_mission_t& mission) {
        WorldEventPhaseMap::iterator pos = phaseMap.find(mission.event_phase());
        if (pos != phaseMap.end()) {
            WorldEventMissions missions;
            missions.push_back(&mission);
        }
        else {
            WorldEventMissions missions;
            missions.push_back(&mission);
            phaseMap.insert(WorldEventPhaseMap::value_type(mission.event_phase(), missions));
        }
    }

private:
    std::unique_ptr<gdt::world_event_mission_table> worldEventMissionTable_;
    WorldEventMissionMap worldEventMissionMap_;
    MissionMap missionMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
