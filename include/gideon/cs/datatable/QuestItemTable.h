#pragma once

#include "EffectApplyInfo.h"
#include <gideon/cs/datatable/template/quest_item_table.hxx>
#include <gideon/cs/shared/data/QuestInfo.h>
#include <gideon/cs/shared/data/SkillInfo.h>
#include <gideon/cs/shared/data/Time.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {


/**
 * @class QuestItemTemplate
 */
class QuestItemTemplate
{
public:
    QuestItemTemplate(const gdt::quest_item_t& questItemInfo) :
        questItemInfo_(&questItemInfo),
        questItemCode_(questItemInfo.quest_item_code()),
        usableCount_(questItemInfo.usable_count()),
        skillCode_(questItemInfo.skill_code())
    {
        isUsable_ = skillCode_ > 0;
    }

    QuestItemCode getQuestItemCode() const {
        return questItemCode_;
    }

    SkillCode getSkillCode() const {
        return skillCode_;
    }

    uint8_t getUsableCount() const {
        return usableCount_;
    }
     
    bool isUsable() const {
        return isUsable_;
    }
    
    void deleteQuestItemInfo() {
        if (questItemInfo_) {
            delete questItemInfo_;
        }
    }
    
    const wchar_t* getIconName() const {
        return questItemInfo_->icon_name().c_str();
    }

    uint8_t getQuestStackCount() const {
        return questItemInfo_->stack_count();
    }

private:
    const gdt::quest_item_t* questItemInfo_;
    QuestItemCode questItemCode_;
    SkillCode skillCode_;
    uint8_t usableCount_;
    bool isUsable_;
};


typedef sne::core::Vector<QuestItemCode> QuestItemCodes;

/**
 * @class QuestItemTable
 *
 */
class GIDEON_CS_API QuestItemTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(QuestItemTable);

public:
    typedef sne::core::HashMap<QuestItemCode, QuestItemTemplate> QuestItemMap;
public:
    virtual ~QuestItemTable() {}

public:
    virtual const QuestItemTemplate* getQuestItemTemplate(QuestItemCode code) const = 0;

    virtual const QuestItemMap& getQuestItemMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define QUEST_ITEM_TABLE gideon::datatable::QuestItemTable::instance()
