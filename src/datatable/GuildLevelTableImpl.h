#pragma once

#include <gideon/cs/datatable/GuildLevelTable.h>
#include <gideon/cs/datatable/template/guild_level_table.hxx>

namespace gideon { namespace datatable {

/**
 * @class GuildLevelTableImpl
 *
 */
class GuildLevelTableImpl : public GuildLevelTable
{
public:
    GuildLevelTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            guildLevelTable_ =
                gdt::guild_level_table_(is, ::xml_schema::flags::dont_validate);
            guildExps_.fill(0);
            for (const gdt::guild_level_t& guildLevelTemplate : guildLevelTable_->guild_level_template()) {
                GuildLevel guildLevel = toGuildLevel(guildLevelTemplate.guild_level());
                if (! isValid(guildLevel)) {
                    assert(false);
                    return;
                }
                guildExps_[guildLevel] = guildLevelTemplate.exp();
                guildMemberCounts_[guildLevel] = guildLevelTemplate.guild_member_count();
            }
            isLoaded_ = true;

            GuildLevelTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual GuildLevel getGuildLevel(GuildExp exp) const {
        GuildExp preExp = 0;
        for (int i = glStart; i < glCount; ++i) {
            if (preExp <= exp && exp < guildExps_[i]) {
                return toGuildLevel(i);
            }
            preExp = guildExps_[i];
        }
        return glMaxLevel;
    }

    virtual GuildExp getGuildLevelExp(GuildLevel level) const {
        return guildExps_[level];
    }

    virtual uint32_t getGuildMemberCount(GuildLevel level) const {
        return guildMemberCounts_[level];
    }

    virtual const GuildExps& getGuildExps() const {
        return guildExps_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    typedef std::array<uint32_t, glCount> GuildMemberCounts;
    std::unique_ptr<gdt::guild_level_table> guildLevelTable_;
    GuildExps guildExps_;
    GuildMemberCounts guildMemberCounts_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
