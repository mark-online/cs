#pragma once

#include <gideon/cs/datatable/WorldEventTable.h>

namespace gideon { namespace datatable {

/**
 * @class WorldEventTableImpl
 *
 */
class WorldEventTableImpl : public WorldEventTable
{
public:
    WorldEventTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            worldEventTable_ =
                gdt::world_event_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::world_event_t& quest : worldEventTable_->world_event_template()) {
                worldEventMap_.emplace(quest.world_event_code(), &quest);
            }
            isLoaded_ = true;
            
            WorldEventTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const gdt::world_event_t* getWorldEventTemplate(RegionCode code) const {
        const WorldEventMap::const_iterator pos = worldEventMap_.find(code);
        if (pos != worldEventMap_.end()) {
            return (*pos).second;
        }
        return nullptr;
    }

    virtual const WorldEventMap& getWorldEventMap() const {
        return worldEventMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::world_event_table> worldEventTable_;
    WorldEventMap worldEventMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
