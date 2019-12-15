#pragma once

#include <gideon/cs/datatable/EventTriggerTable.h>

namespace gideon { namespace datatable {

/**
 * @class EventTriggerTableImpl
 *
 */
class EventTriggerTableImpl : public EventTriggerTable
{
public:
    EventTriggerTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            eventTriggerTable_ =
                gdt::evt_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::evt_t& evt : eventTriggerTable_->evt_template()) {
                eventTriggerListMap_[evt.entity_code()].push_back(&evt);
            }
            isLoaded_ = true;

            EventTriggerTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const EventTriggerList* getEventTriggerList(DataCode code) const {
        const EventTriggerListMap::const_iterator pos = eventTriggerListMap_.find(code);
        if (pos != eventTriggerListMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const EventTriggerListMap& getEventTriggerListMap() const {
        return eventTriggerListMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::evt_table> eventTriggerTable_;
    EventTriggerListMap eventTriggerListMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
