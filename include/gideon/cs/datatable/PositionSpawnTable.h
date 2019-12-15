#pragma once

#include "SpawnTemplate.h"
#include <gideon/cs/shared/data/NpcInfo.h>
#include <sne/core/container/Containers.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @class PositionSpawnTable
 *
 */
class GIDEON_CS_API PositionSpawnTable : public boost::noncopyable
{
public:
    typedef sne::core::Vector<PositionSpawnTemplate> Spawns;

public:
    virtual ~PositionSpawnTable() {}

public:
    virtual const Spawns* getSpawns(RegionCode regionCode) const = 0;
    virtual const Spawns getEntitySpawns(DataCode entityCode) const = 0;

    /// 테이블 상에서 가장 마지막 NPC를 얻는다
    virtual const PositionSpawnTemplate* getPositionSpawnTemplate(RegionCode regionCode,
        NpcCode npcCode) const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {
