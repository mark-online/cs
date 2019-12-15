#pragma once

#include <gideon/cs/datatable/template/npc_buy_table.hxx>
#include <gideon/cs/shared/data/NpcInfo.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>


namespace gideon { namespace datatable {

/**
 * @class QuestTable
 *
 */
class GIDEON_CS_API NpcBuyTable : public boost::noncopyable
{
public:
	SNE_DECLARE_SINGLETON(NpcBuyTable);

public:
    typedef sne::core::HashMap<NpcCode, const gdt::npc_buy_t*> NpcBuyMap;

public:
    virtual ~NpcBuyTable() {}

public:
    virtual const gdt::npc_buy_t* getNpcBuyTemplate(NpcCode code) const = 0;

    virtual const NpcBuyMap& getNpcBuyMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define NPC_BUY_TABLE gideon::datatable::NpcBuyTable::instance()