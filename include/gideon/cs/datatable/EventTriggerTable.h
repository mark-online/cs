#pragma once

#include <gideon/cs/shared/data/Code.h>
#include <gideon/cs/datatable/template/event_trigger_table.hxx>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @class EventTriggerTable
 *
 */
class GIDEON_CS_API EventTriggerTable : public boost::noncopyable
{
	SNE_DECLARE_SINGLETON(EventTriggerTable);
public:
    typedef sne::core::Vector<const gdt::evt_t*> EventTriggerList;
    typedef sne::core::HashMap<DataCode, EventTriggerList> EventTriggerListMap;

public:
    virtual ~EventTriggerTable() {}

public:
    virtual const EventTriggerList* getEventTriggerList(DataCode code) const = 0;

    virtual const EventTriggerListMap& getEventTriggerListMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define EVT_TABLE gideon::datatable::EventTriggerTable::instance()
