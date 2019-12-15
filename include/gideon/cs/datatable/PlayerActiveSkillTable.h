#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/shared/data/SkillInfo.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>


namespace gideon { namespace datatable {

struct PlayerActiveSkillTemplate;
struct SkillClientEffectTemplate;

/**
 * @class PlayerActiveSkillTable
 *
 */
class GIDEON_CS_API PlayerActiveSkillTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(PlayerActiveSkillTable);

public:
    typedef sne::core::HashMap<SkillCode, PlayerActiveSkillTemplate> PlayerSkillMap;

public:
    virtual ~PlayerActiveSkillTable() {}

public:
    virtual const PlayerActiveSkillTemplate* getPlayerSkill(SkillCode code) const = 0;

    virtual const SkillClientEffectTemplate* getClientEffect(SkillCode code) const = 0;

    virtual const PlayerSkillMap& getPlayerSkillMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define PLAYER_ACTIVE_SKILL_TABLE gideon::datatable::PlayerActiveSkillTable::instance()
