#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/datatable/template/npc_formation_table.hxx>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @class NpcFormationTable
 *
 */
class GIDEON_CS_API NpcFormationTable : public boost::noncopyable
{
	SNE_DECLARE_SINGLETON(NpcFormationTable);

public:
    typedef sne::core::Vector<const gdt::npc_formation_t*> Members;

    /// <leader_npc_code, members>
    typedef sne::core::HashMap<NpcCode, Members> NpcFormationMap;

public:
    virtual ~NpcFormationTable() {}

public:
    virtual const Members* getNpcFormation(NpcCode leaderNpcCode) const = 0;

    virtual const NpcFormationMap& getNpcFormationMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {


#define NPC_FORMATION_TABLE gideon::datatable::NpcFormationTable::instance()