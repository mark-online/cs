#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/datatable/template/gem_table.hxx>
#include <gideon/cs/shared/data/GemInfo.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @class GemTable
 * 보석 테이블
 */
class GIDEON_CS_API GemTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(GemTable);

public:
    typedef sne::core::HashMap<GemCode, const gdt::gem_t*> GemMap;

public:
    virtual ~GemTable() {}

public:
    virtual const gdt::gem_t* getGem(GemCode code) const = 0;

    virtual const GemMap& getGemMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define GEM_TABLE gideon::datatable::GemTable::instance()
