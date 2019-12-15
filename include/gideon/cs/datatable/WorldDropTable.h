#pragma once

#include <gideon/cs/shared/data/ItemDropInfo.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>


namespace gideon { namespace datatable {
    

/**
 * @class WorldDropTable
 *
 */
class GIDEON_CS_API WorldDropTable : public boost::noncopyable
{
public:
	SNE_DECLARE_SINGLETON(WorldDropTable);

public:
    typedef sne::core::HashMap<WorldDropId, DataCodes> WorldDropMap;

public:
    virtual ~WorldDropTable() {}

public:
    virtual DataCode getRandomCode(WorldDropId index) = 0;

    virtual const WorldDropMap& getWorldDropMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define WORLD_DROP_TABLE gideon::datatable::WorldDropTable::instance()
