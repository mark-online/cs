#pragma once

#include <gideon/cs/datatable/GuildSkillTable.h>

namespace gideon { namespace datatable {

/**
 * @class GuildSkillTableImpl
 *
 */
class GuildSkillTableImpl : public GuildSkillTable
{
public:
    GuildSkillTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            guildSkillTable_ =
                gdt::guild_skill_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::guild_skill_t& guildSkill : guildSkillTable_->guild_skill_template()) {
                guildSkillMap_.emplace(guildSkill.skill_code(), &guildSkill);
            }
            isLoaded_ = true;

            GuildSkillTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const gdt::guild_skill_t* getGuildSkill(SkillCode skillCode) const {
        const GuildSkillMap::const_iterator pos = guildSkillMap_.find(skillCode);
        if (pos != guildSkillMap_.end()) {
            return (*pos).second;
        }
        return nullptr;
    }

    virtual const GuildSkillMap& getGuildSkillMap() const {
        return guildSkillMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::guild_skill_table> guildSkillTable_;
    GuildSkillMap guildSkillMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
