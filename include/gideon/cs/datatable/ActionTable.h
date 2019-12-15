#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/datatable/template/action_table.hxx>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

typedef uint32_t ActionCode;

/**
 * @class ActionTable
 *
 */
class GIDEON_CS_API ActionTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(ActionTable);

public:
    typedef sne::core::HashMap<ActionCode, const gdt::action_t*> ActionMap;

public:
    virtual ~ActionTable() {}

public:
    virtual const gdt::action_t* getAction(ActionCode actionCode) const = 0;

    virtual const ActionMap& getActionMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define ACTION_TABLE gideon::datatable::ActionTable::instance()
