#pragma once

#include <gideon/cs/datatable/RegionSpawnTable.h>
#include <gideon/cs/datatable/template/region_spawn_table.hxx>

namespace gideon { namespace datatable {

namespace {

inline RegionSpawnTemplate toRegionSpawnTemplate(const gdt::region_spawn_t& spawnTemplate)
{
    RegionSpawnTemplate rst;
    rst.regionCode_ = spawnTemplate.region_code();
    rst.entityCode_ = spawnTemplate.entity_code();
    rst.pool_ = spawnTemplate.pool();
    rst.minSpawnDelay_ = spawnTemplate.min_spawn_delay();
    rst.maxSpawnDelay_ = spawnTemplate.max_spawn_delay();
    rst.minSpawnInterval_ = spawnTemplate.min_spawn_interval();
    rst.maxSpawnInterval_ = spawnTemplate.max_spawn_interval();
    rst.minDespawnInterval_ = spawnTemplate.min_despawn_interval();
    rst.maxDespawnInterval_ = spawnTemplate.max_despawn_interval();
    return rst;
}

} // namespace {

/**
 * @class RegionSpawnTableImpl
 *
 */
class RegionSpawnTableImpl : public RegionSpawnTable
{
    typedef sne::core::HashMap<RegionCode, Spawns> RegionSpawnMap;

public:
    RegionSpawnTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            spawnTable_ =
                gdt::region_spawn_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::region_spawn_t& spawnTemplate :
                spawnTable_->region_spawn_template()) {
                Spawns& spawns = spawns_[spawnTemplate.region_code()];
                spawns.push_back(toRegionSpawnTemplate(spawnTemplate));
            }
            isLoaded_ = true;
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const Spawns* getSpawns(RegionCode regionCode) const {
        const RegionSpawnMap::const_iterator pos = spawns_.find(regionCode);
        if (pos != spawns_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::region_spawn_table> spawnTable_;
    RegionSpawnMap spawns_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
