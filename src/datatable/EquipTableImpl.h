#pragma once

#include <gideon/cs/datatable/EquipTable.h>

namespace gideon { namespace datatable {

/**
 * @class EquipTableImpl
 *
 */
class EquipTableImpl : public EquipTable
{
public:
    EquipTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            equipTable_ =
                gdt::equip_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::equip_t& equip : equipTable_->equip_template()) {
                equipMap_.emplace(equip.item_code(), &equip);
            }
            isLoaded_ = true;

            EquipTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const gdt::equip_t* getEquip(EquipCode code) const {
        const EquipMap::const_iterator pos = equipMap_.find(code);
        if (pos != equipMap_.end()) {
            return (*pos).second;
        }
        return nullptr;
    }

    virtual const EquipMap& getEquipMap() const {
        return equipMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::equip_table> equipTable_;
    EquipMap equipMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
