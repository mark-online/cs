#pragma once

#include <gideon/cs/datatable/ArenaTable.h>

namespace gideon { namespace datatable {

/**
 * @class ArenaTableImpl
 *
 */
class ArenaTableImpl : public ArenaTable
{
public:
    ArenaTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            arenaTable_ =
                gdt::arenas_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::arena_t& arena : arenaTable_->arena_template()) {
                arenaMap_.emplace(arena.arena_map_code(), &arena);
            }
            isLoaded_ = true;

            ArenaTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const gdt::arena_t* getArenaTemplate(MapCode code) const {
        const ArenaMap::const_iterator pos = arenaMap_.find(code);
        if (pos != arenaMap_.end()) {
            return (*pos).second;
        }
        return nullptr;
    }

    virtual const ArenaMap& getArenaMap() const {
        return arenaMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::arenas> arenaTable_;
    ArenaMap arenaMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
