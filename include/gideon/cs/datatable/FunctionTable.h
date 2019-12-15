#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/shared/data/FunctionItemInfo.h>
#include <gideon/cs/datatable/template/function_table.hxx>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @class FunctionTable
 *
 */
class GIDEON_CS_API FunctionTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(FunctionTable);

public:
    typedef sne::core::HashMap<FunctionCode, const gdt::function_t*> FunctionMap;

public:
    virtual ~FunctionTable() {}

public:
    virtual const gdt::function_t* getFunction(FunctionCode functionCode) const = 0;

    virtual const FunctionMap& getFunctionMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define FUNCTION_TABLE gideon::datatable::FunctionTable::instance()
