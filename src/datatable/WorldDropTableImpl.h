#pragma once

#include <gideon/cs/datatable/WorldDropTable.h>
#include <gideon/cs/datatable/template/world_drop_table.hxx>

namespace gideon { namespace datatable {

DataCode getDataCode(const gdt::world_drop_t& worldDrop, int i)
{
    switch (i) {
    case 1:
        return worldDrop.item_code_1();
    case 2:
        return worldDrop.item_code_2();
    case 3:
        return worldDrop.item_code_3();
    case 4:
        return worldDrop.item_code_4();
    case 5:
        return worldDrop.item_code_5();
    case 6:
        return worldDrop.item_code_6();
    case 7:
        return worldDrop.item_code_7();
    case 8:
        return worldDrop.item_code_8();
    case 9:
        return worldDrop.item_code_9();
    case 10:
        return worldDrop.item_code_10();
    case 11:
        return worldDrop.item_code_11();
    case 12:
        return worldDrop.item_code_12();
    case 13:
        return worldDrop.item_code_13();
    case 14:
        return worldDrop.item_code_14();
    case 15:
        return worldDrop.item_code_15();
    case 16:
        return worldDrop.item_code_16();
    case 17:
        return worldDrop.item_code_17();
    case 18:
        return worldDrop.item_code_18();
    case 19:
        return worldDrop.item_code_19();
    case 20:
        return worldDrop.item_code_20();
    }
    return invalidDataCode;
}

/**
 * @class WorldDropTableImpl
 *
 */
class WorldDropTableImpl : public WorldDropTable
{
public:
    WorldDropTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            worldDropTable_ =
                gdt::world_drop_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::world_drop_t& worldDrop : worldDropTable_->world_drop_template()) {
                DataCodes dataCodes;
                dataCodes.reserve(20);
                for (int i = 1; i <= 20; ++i) {
                    DataCode itemCode = getDataCode(worldDrop, i);
                    if (isValidDataCode(itemCode)) {
                        dataCodes.push_back(itemCode);
                    }
                }
                if (dataCodes.empty()) {
                    assert(false);
                }
                worldDropMap_.emplace(worldDrop.index(), dataCodes);
            }
            WorldDropTable::instance(this);
            isLoaded_ = true;
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual DataCode getRandomCode(WorldDropId index) {
        WorldDropMap::iterator pos = worldDropMap_.find(index);
        if (pos != worldDropMap_.end()) {
            DataCodes& dataCodes = (*pos).second;
            if (dataCodes.empty()) {
                return invalidDataCode;
            }
            const int maxRandValue = static_cast<uint32_t>(dataCodes.size() - 1);
            uint32_t randIndex = esut::random(0, maxRandValue);
            return dataCodes[randIndex];

        }
        return invalidDataCode;
    }

    virtual const WorldDropMap& getWorldDropMap() const {
        return worldDropMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::world_drop_table> worldDropTable_;
    WorldDropMap worldDropMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
