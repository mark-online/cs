#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/shared/data/CharacterInfo.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @class ExpTable
 *
 */
class GIDEON_CS_API ExpTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(ExpTable);

public:
    typedef std::array<ExpPoint, lsCount> LevelStepExpPoints;
    typedef std::array<LevelStepExpPoints, clMaxPlayerCount> ExpPoints;

public:
    virtual ~ExpTable() {}

public:
    virtual ExpPoint getExpPoint(CreatureLevel cl, LevelStep ls) const = 0;

    virtual const ExpPoints& getExpPoints() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define EXP_TABLE gideon::datatable::ExpTable::instance()
