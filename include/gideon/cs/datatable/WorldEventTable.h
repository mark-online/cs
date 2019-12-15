#pragma once

#include <gideon/cs/datatable/template/world_event_table.hxx>
#include <gideon/cs/shared/data/WorldEventInfo.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>


namespace gideon { namespace datatable {

/**
 * @class QuestTable
 *
 */
class GIDEON_CS_API WorldEventTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(WorldEventTable);
public:
    typedef sne::core::HashMap<WorldEventCode, const gdt::world_event_t*> WorldEventMap;

public:
    virtual ~WorldEventTable() {}

public:
    virtual const gdt::world_event_t* getWorldEventTemplate(WorldEventCode code) const = 0;

    virtual const WorldEventMap& getWorldEventMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {


#define WORLD_EVENT_TABLE gideon::datatable::WorldEventTable::instance()