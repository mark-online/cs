#pragma once

#include "SpawnTemplate.h"
#include <sne/core/container/Containers.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @class RegionSpawnTable
 *
 */
class GIDEON_CS_API RegionSpawnTable : public boost::noncopyable
{
public:
    typedef sne::core::Vector<RegionSpawnTemplate> Spawns;

public:
    virtual ~RegionSpawnTable() {}

public:
    virtual const Spawns* getSpawns(RegionCode regionCode) const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {
