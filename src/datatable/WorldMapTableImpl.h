#pragma once

#include <gideon/cs/datatable/WorldMapTable.h>

namespace gideon { namespace datatable {

/**
 * @class WorldMapTableImpl
 *
 */
class WorldMapTableImpl : public WorldMapTable
{
public:
    WorldMapTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            worldMapTable_ =
                gdt::world_maps_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::map_t& map : worldMapTable_->map_template()) {
                worldMapMap_.emplace(map.map_code(), &map);
            }
            isLoaded_ = true;

            WorldMapTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const gdt::map_t* getMap(MapCode code) const {
        const WorldMapMap::const_iterator pos = worldMapMap_.find(code);
        if (pos != worldMapMap_.end()) {
            return (*pos).second;
        }
        return nullptr;
    }

    virtual const WorldMapMap& getWorldMapMap() const {
        return worldMapMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::world_maps> worldMapTable_;
    WorldMapMap worldMapMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
