#pragma once

#include <gideon/cs/shared/data/GuildInfo.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @class GuildLevelTable
 *
 */
class GIDEON_CS_API GuildLevelTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(GuildLevelTable);

public:
    typedef std::array<GuildExp, glCount> GuildExps;

public:
    virtual ~GuildLevelTable() {}

public:
    virtual GuildLevel getGuildLevel(GuildExp exp) const = 0;

    virtual GuildExp getGuildLevelExp(GuildLevel level) const = 0;

    virtual uint32_t getGuildMemberCount(GuildLevel level) const = 0;

    virtual const GuildExps& getGuildExps() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define GUILD_LEVEL_TABLE gideon::datatable::GuildLevelTable::instance()
