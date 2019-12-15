#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/shared/data/SkillInfo.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>


namespace gideon { namespace datatable {

struct PassiveSkillTemplate;
struct SkillClientEffectTemplate;

/**
 * @class PassiveSkillTable
 *
 */
class GIDEON_CS_API PlayerPassiveSkillTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(PlayerPassiveSkillTable );

public:
    typedef sne::core::HashMap<SkillCode, PassiveSkillTemplate> PlayerSkillMap;
    typedef std::array<int32_t, eanCount> EffectValues;

public:
    virtual ~PlayerPassiveSkillTable () {}

public:
    virtual const PassiveSkillTemplate* getPlayerSkill(SkillCode code) const = 0;

    virtual const SkillClientEffectTemplate* getClientEffect(SkillCode code) const = 0;

    virtual const PlayerSkillMap& getPlayerSkillMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define PLAYER_PASSIVE_SKILL_TABLE gideon::datatable::PlayerPassiveSkillTable::instance()
