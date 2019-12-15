#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/shared/data/SkillInfo.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>


namespace gideon { namespace datatable {

struct ItemActiveSkillTemplate;
struct SkillClientEffectTemplate;

/**
 * @class ItemActiveSkillTable
 *
 */
class GIDEON_CS_API ItemActiveSkillTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(ItemActiveSkillTable);

public:
    typedef sne::core::HashMap<SkillCode, ItemActiveSkillTemplate> ItemSkillMap;

public:
    virtual ~ItemActiveSkillTable() {}

public:
    virtual const ItemActiveSkillTemplate* getItemSkill(SkillCode code) const = 0;

    virtual const SkillClientEffectTemplate* getClientEffect(SkillCode code) const = 0;

    virtual const ItemSkillMap& getItemSkillMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define ITEM_ACTIVE_SKILL_TABLE gideon::datatable::ItemActiveSkillTable::instance()
