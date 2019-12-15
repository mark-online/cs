#pragma once

#include <gideon/cs/datatable/template/glider_table.hxx>
#include <gideon/cs/shared/data/GliderInfo.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>


namespace gideon { namespace datatable {

/**
 * @class QuestTable
 *
 */
class GIDEON_CS_API GliderTable : public boost::noncopyable
{
public:
	SNE_DECLARE_SINGLETON(GliderTable);

public:
    typedef sne::core::HashMap<GliderCode, const gdt::glider_t*> GliderMap;

public:
    virtual ~GliderTable() {}

public:
    virtual const gdt::glider_t* getGlider(GliderCode code) const = 0;

    virtual const GliderMap& getGliderMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define GLIDER_TABLE gideon::datatable::GliderTable::instance()