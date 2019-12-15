#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/datatable/template/random_dungeon_table.hxx>
#include <gideon/cs/shared/data/WorldInfo.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

class RandomDungeonTemplate
{
public:
    RandomDungeonTemplate(const gdt::random_dungeon_t& randomDungeon) :
    randomDungeonInfo_(&randomDungeon)
    {}

    const wchar_t* getEffectName() const
    {
		return randomDungeonInfo_->object_effect().c_str();
    }

    const gdt::random_dungeon_t* getInfo() const
    {
        return randomDungeonInfo_;
    }

private:
   const gdt::random_dungeon_t* randomDungeonInfo_;
};

/**
 * @class RandomDungeonTable
 *
 */
class GIDEON_CS_API RandomDungeonTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(RandomDungeonTable);

public:
    typedef sne::core::HashMap<MapCode, RandomDungeonTemplate> RandomDungeonMap;

public:
    virtual ~RandomDungeonTable() {}

public:
    /// 해당 지역에 존재하는 던전 목록 요청
    virtual const RandomDungeonTemplate* getRandomDungeonTemplate(MapCode mapCode) const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define RANDOM_DUNGEON_TABLE gideon::datatable::RandomDungeonTable::instance()
