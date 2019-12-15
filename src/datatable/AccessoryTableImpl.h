#pragma once

#include <gideon/cs/datatable/AccessoryTable.h>

namespace gideon { namespace datatable {

/**
 * @class AccessoryTable
 *
 */
class AccessoryTableImpl : public AccessoryTable
{
public:
    AccessoryTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            accessoryTable_ =
                gdt::accessory_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::accessory_t& accessory : accessoryTable_->accessory_template()) {
                accessoryMap_.emplace(accessory.accessory_code(), &accessory);
            }
            isLoaded_ = true;

            AccessoryTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const gdt::accessory_t* getAccessory(AccessoryCode code) const {
        const AccessoryMap::const_iterator pos = accessoryMap_.find(code);
        if (pos != accessoryMap_.end()) {
            return (*pos).second;
        }
        return nullptr;
    }

    virtual const AccessoryMap& getAccessoryMap() const {
        return accessoryMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::accessory_table> accessoryTable_;
    AccessoryMap accessoryMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
