#pragma once

#include <gideon/cs/datatable/QuestItemTable.h>

namespace gideon { namespace datatable {

/**
 * @class QuestItemTableImpl
 *
 */
class QuestItemTableImpl : public QuestItemTable
{
public:
    QuestItemTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            questItemTable_ =
                gdt::quest_item_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::quest_item_t& quest : questItemTable_->quest_item_template()) {
                questItemMap_.emplace(quest.quest_item_code(), quest);
            }
            isLoaded_ = true;

            QuestItemTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }
    virtual ~QuestItemTableImpl() {
    }

public:
    virtual const QuestItemTemplate* getQuestItemTemplate(QuestItemCode code) const {
        const QuestItemMap::const_iterator pos = questItemMap_.find(code);
        if (pos != questItemMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const QuestItemMap& getQuestItemMap() const {
        return questItemMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::quest_item_table> questItemTable_;
    QuestItemMap questItemMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
