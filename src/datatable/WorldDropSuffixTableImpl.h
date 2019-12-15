#pragma once

#include <gideon/cs/datatable/WorldDropSuffixTable.h>
#include <gideon/cs/datatable/template/world_drop_suffix_table.hxx>

namespace gideon { namespace datatable {

WorldDropId getWorldDropId(const gdt::world_drop_suffix_t& worldDrop, int i)
{
    switch (i) {
    case 1:
        return worldDrop.world_drop_id_1();
    case 2:
        return worldDrop.world_drop_id_2();
    case 3:
        return worldDrop.world_drop_id_3();
    case 4:
        return worldDrop.world_drop_id_4();
    case 5:
        return worldDrop.world_drop_id_5();
    }
    return invalidWorldDropId;
}

/**
 * @class WorldDropSuffixTableImpl
 *
 */
class WorldDropSuffixTableImpl : public WorldDropSuffixTable
{
public:
    WorldDropSuffixTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            worldDropSuffixTable_ =
                gdt::world_drop_suffix_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::world_drop_suffix_t& worldDropSuffix :
                worldDropSuffixTable_->world_drop_suffix_template()) {
                WorldDropIds worldDropIds;
                worldDropIds.reserve(5);
                for (int i = 1; i <= 5; ++i) {
                    WorldDropId worldDropId = getWorldDropId(worldDropSuffix, i);
                    if (isValidWorldDropId(worldDropId)) {
                        worldDropIds.push_back(worldDropId);
                    }
                }
                if (worldDropIds.empty()) {
                    assert(false);
                }

                worldDropSuffixMap_.emplace(worldDropSuffix.index(),
                    WorldDropSuffixTemplate(worldDropIds, worldDropSuffix.loop_count(),
                        static_cast<uint16_t>(worldDropSuffix.drop_pct())));
            }
            WorldDropSuffixTable::instance(this);
            isLoaded_ = true;
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual WorldDropSuffixTemplate getWorldDropSuffixTemplate(WorldDropSuffixId index) {
        WorldDropSuffixMap::iterator pos = worldDropSuffixMap_.find(index);
        if (pos != worldDropSuffixMap_.end()) {
            return (*pos).second;
        }
        return WorldDropSuffixTemplate();
    }

    virtual const WorldDropSuffixMap& getWorldDropSuffixMap() const {
        return worldDropSuffixMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::world_drop_suffix_table> worldDropSuffixTable_;
    WorldDropSuffixMap worldDropSuffixMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
