#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/shared/data/SkillInfo.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>


namespace gideon { namespace datatable {

struct NpcActiveSkillTemplate;
struct SkillClientEffectTemplate;

/**
 * @class NpcActiveSkillTable
 *
 */
class GIDEON_CS_API NpcActiveSkillTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(NpcActiveSkillTable);

public:
    typedef sne::core::HashMap<SkillCode, NpcActiveSkillTemplate> NpcSkillMap;

public:
    virtual ~NpcActiveSkillTable() {}

public:
    virtual const NpcActiveSkillTemplate* getNpcSkill(SkillCode code) const = 0;

    virtual const SkillClientEffectTemplate* getClientEffect(SkillCode code) const = 0;

    virtual const NpcSkillMap& getNpcSkillMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define NPC_ACTIVE_SKILL_TABLE gideon::datatable::NpcActiveSkillTable::instance()
