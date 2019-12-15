#pragma once

#include <gideon/cs/datatable/template/guild_skill_table.hxx>
#include <gideon/cs/shared/data/SkillInfo.h>
#include <sne/core/utility/Singleton.h>
#include <sne/core/container/Containers.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @class GuildSkillTable
 *
 */
class GIDEON_CS_API GuildSkillTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(GuildSkillTable);

public:
    typedef sne::core::HashMap<SkillCode, const gdt::guild_skill_t*> GuildSkillMap;
public:
    virtual ~GuildSkillTable() {}

public:
    virtual const gdt::guild_skill_t* getGuildSkill(SkillCode skillCode) const = 0;

    virtual const GuildSkillMap& getGuildSkillMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define GUILD_SKILL_TABLE gideon::datatable::GuildSkillTable::instance()
