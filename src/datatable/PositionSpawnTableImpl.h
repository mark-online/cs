#pragma once

#include <gideon/cs/datatable/PositionSpawnTable.h>
#include <gideon/cs/datatable/template/position_spawn_table.hxx>

namespace gideon { namespace datatable {

namespace {

inline PositionSpawnTemplate toPositionSpawnTempalte(const gdt::position_spawn_t& spawnTemplate)
{
    PositionSpawnTemplate pst;
    pst.position_.x_ = spawnTemplate.x();
    pst.position_.y_ = spawnTemplate.y();
    pst.position_.z_ = spawnTemplate.z();
    pst.position_.heading_ = fixHeading(spawnTemplate.heading());
    pst.entityCode_ = spawnTemplate.entity_code();
    pst.regionCode_ = spawnTemplate.region_code();
    pst.entityPathCode_ = spawnTemplate.entity_path_code();
    pst.minSpawnDelay_ = spawnTemplate.min_spawn_delay();
    pst.maxSpawnDelay_ = spawnTemplate.max_spawn_delay();
    pst.minSpawnInterval_ = spawnTemplate.min_spawn_interval();
    pst.maxSpawnInterval_ = spawnTemplate.max_spawn_interval();
    pst.minDespawnInterval_ = spawnTemplate.min_despawn_interval();
    pst.maxDespawnInterval_ = spawnTemplate.max_despawn_interval();
    return pst;
}

} // namespace {

/**
 * @class PositionSpawnTableImpl
 *
 */
class PositionSpawnTableImpl : public PositionSpawnTable
{
    typedef sne::core::HashMap<RegionCode, Spawns> RegionSpawnMap;
    typedef sne::core::HashMap<NpcCode, PositionSpawnTemplate> RegionNpcSpawnTemplateMap;
    typedef sne::core::HashMap<RegionCode, RegionNpcSpawnTemplateMap> RegionNpcSpawnTemplateMapMap;

public:
    PositionSpawnTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            spawnTable_ =
                gdt::position_spawn_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::position_spawn_t& spawnTemplate :
                spawnTable_->position_spawn_template()) {
                const PositionSpawnTemplate posSpawnTemplate(toPositionSpawnTempalte(spawnTemplate));
                Spawns& spawns = spawnMap_[spawnTemplate.region_code()];
                spawns.push_back(posSpawnTemplate);

                if (isValidNpcCode(posSpawnTemplate.entityCode_)) {
                    (npcSpawnMap_[spawnTemplate.region_code()])[posSpawnTemplate.entityCode_] = posSpawnTemplate;
                }
            }
            isLoaded_ = true;
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const Spawns* getSpawns(RegionCode regionCode) const {
        if (regionCode == globalRegionCode) {
            regionCode = invalidRegionCode;
        }
        const RegionSpawnMap::const_iterator pos = spawnMap_.find(regionCode);
        if (pos != spawnMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const Spawns getEntitySpawns(DataCode entityCode) const {
        Spawns spawns;
        for (const gdt::position_spawn_t& spawnTemplate : spawnTable_->position_spawn_template())
        {
            if( spawnTemplate.entity_code() != entityCode)
                continue;

            const PositionSpawnTemplate posSpawnTemplate(toPositionSpawnTempalte(spawnTemplate));
            spawns.push_back(posSpawnTemplate);
        }
        return spawns;
    }

    virtual const PositionSpawnTemplate* getPositionSpawnTemplate(RegionCode regionCode,
        NpcCode npcCode) const {
        if (regionCode == globalRegionCode) {
            regionCode = invalidRegionCode;
        }
        const RegionNpcSpawnTemplateMapMap::const_iterator pos = npcSpawnMap_.find(regionCode);
        if (pos == npcSpawnMap_.end()) {
            return nullptr;
        }
        const RegionNpcSpawnTemplateMap& spawnTemplateMap = (*pos).second;
        const RegionNpcSpawnTemplateMap::const_iterator posSpawn = spawnTemplateMap.find(npcCode);
        if (posSpawn == spawnTemplateMap.end()) {
            return nullptr;
        }
        return &(*posSpawn).second;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::position_spawn_table> spawnTable_;
    RegionSpawnMap spawnMap_;
    RegionNpcSpawnTemplateMapMap npcSpawnMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
