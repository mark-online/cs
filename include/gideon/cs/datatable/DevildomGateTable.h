#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/datatable/template/devildom_gate_table.hxx>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @class DevildomGateTable
 * 재료 테이블
 */
class GIDEON_CS_API DevildomGateTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(DevildomGateTable);

public:
    typedef sne::core::HashMap<DataCode, const gdt::devildom_gate_t*> DevildomGateMap;

public:
    virtual ~DevildomGateTable() {}

public:
    virtual const gdt::devildom_gate_t* getDevildomGate(DataCode code) const = 0;

    virtual const DevildomGateMap& getDevildomGateMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define DEVILDOM_GATE_TABLE gideon::datatable::DevildomGateTable::instance()