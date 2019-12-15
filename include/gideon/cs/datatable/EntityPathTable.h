#pragma once

#include <gideon/cs/datatable/template/entity_path_table.hxx>
#include <gideon/cs/shared/data/EntityPathInfo.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @class EntityPathTable
 *
 */
class GIDEON_CS_API EntityPathTable : public boost::noncopyable
{
public:
    typedef sne::core::HashMap<EntityPathCode, const gdt::entity_path_t*> EntityPathMap;

public:
    virtual ~EntityPathTable() {}

public:
    virtual const gdt::entity_path_t* getEntityPath(EntityPathCode code) const = 0;

    virtual const EntityPathMap& getEntityPathMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {
