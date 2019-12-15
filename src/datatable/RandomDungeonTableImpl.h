#pragma once

#include <gideon/cs/datatable/RandomDungeonTable.h>

namespace gideon { namespace datatable {

/**
 * @class RandomDungeonTableImpl
 *
 */
class RandomDungeonTableImpl : public RandomDungeonTable
{
public:
    RandomDungeonTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            dungeonTable_ =
                gdt::random_dungeon_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::random_dungeon_t& dungeonTemplate :
                dungeonTable_->random_dungeon_template()) {
                randomDungeonMap_.emplace(dungeonTemplate.map_code(),
                    RandomDungeonTemplate(dungeonTemplate));
            }
            isLoaded_ = true;

            RandomDungeonTableImpl::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const RandomDungeonTemplate* getRandomDungeonTemplate(MapCode mapCode) const {
        const RandomDungeonMap::const_iterator pos = randomDungeonMap_.find(mapCode);
        if (pos != randomDungeonMap_.end()) {
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
    std::unique_ptr<gdt::random_dungeon_table> dungeonTable_;
    RandomDungeonMap randomDungeonMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
