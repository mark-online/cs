#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/datatable/template/fragment_table.hxx>
#include <gideon/cs/shared/data/FragmentInfo.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @class RegionTable
 *
 */
class GIDEON_CS_API FragmentTable : public boost::noncopyable
{
	SNE_DECLARE_SINGLETON(FragmentTable);
public:
    typedef sne::core::HashMap<FragmentCode, const gdt::fragment_t*> FragmentMap;

public:
    virtual ~FragmentTable() {}

public:
    virtual const gdt::fragment_t* getFragment(FragmentCode code) const = 0;

    virtual const FragmentMap& getFragmentMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {


#define FRAGMENT_TABLE gideon::datatable::FragmentTable::instance()