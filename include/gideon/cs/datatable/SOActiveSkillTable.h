#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/shared/data/SkillInfo.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>


namespace gideon { namespace datatable {

struct SOActiveSkillTemplate;
struct SkillClientEffectTemplate;

/**
 * @class SOActiveSkillTable
 *
 */
class GIDEON_CS_API SOActiveSkillTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(SOActiveSkillTable);

public:
    typedef sne::core::HashMap<SkillCode, SOActiveSkillTemplate> SOSkillMap;

public:
    virtual ~SOActiveSkillTable() {}

public:
    virtual const SOActiveSkillTemplate* getSOSkill(SkillCode code) const = 0;

    virtual const SkillClientEffectTemplate* getClientEffect(SkillCode code) const = 0;

    virtual const SOSkillMap& getSOSkillMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define SO_ACTIVE_SKILL_TABLE gideon::datatable::SOActiveSkillTable::instance()
