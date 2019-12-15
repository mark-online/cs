#pragma once

#include <gideon/cs/datatable/DeviceTable.h>

namespace gideon { namespace datatable {

/**
 * @class DeviceTableImpl
 *
 */
class DeviceTableImpl : public DeviceTable
{
public:
    DeviceTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            deviceTable_ =
                gdt::device_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::device_t& device : deviceTable_->device_template()) {
                deviceMap_.emplace(static_cast<DeviceCode>(device.device_code()),
                    DeviceTemplate(device));
            }
            isLoaded_ = true;

            DeviceTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }
    virtual ~DeviceTableImpl() {
    }

public:
    virtual const DeviceTemplate* getDeviceTemplate(DeviceCode code) const {
        const DeviceMap::const_iterator pos = deviceMap_.find(code);
        if (pos != deviceMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const DeviceMap& getDeviceMap() const {
        return deviceMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::device_table> deviceTable_;
    DeviceMap deviceMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
