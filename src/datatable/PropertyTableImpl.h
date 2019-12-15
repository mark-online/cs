#pragma once

#include <gideon/cs/datatable/PropertyTable.h>
#include <gideon/cs/datatable/template/property_table.hxx>

namespace gideon { namespace datatable {

/**
 * @class PropertyTableImpl
 *
 */
class PropertyTableImpl : public PropertyTable
{
public:
    PropertyTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            std::unique_ptr<gdt::property_table> propertyTable =
                gdt::property_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::property_t& property : propertyTable->property_template()) {
                propertyMap_.emplace(property.key(), property.value());
            }
            isLoaded_ = true;

            PropertyTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const std::wstring* getProperty(const std::wstring& key) const {
        const PropertyMap::const_iterator pos = propertyMap_.find(key);
        if (pos != propertyMap_.end()) {
            return &((*pos).second);
        }
        return nullptr;
    }

    virtual const PropertyMap& getPropertyMap() const {
        return propertyMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    PropertyMap propertyMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
