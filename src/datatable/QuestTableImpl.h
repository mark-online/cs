#pragma once

#include <gideon/cs/datatable/QuestTable.h>

namespace gideon { namespace datatable {

/**
 * @class QuestTableImpl
 *
 */
class QuestTableImpl : public QuestTable
{
public:
    QuestTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            questTable_ =
                gdt::quest_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::quest_t& quest : questTable_->quest_template()) {
                questMap_.emplace(quest.quest_code(), QuestTemplate(quest));
            }
            isLoaded_ = true;

            QuestTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const QuestTemplate* getQuestTemplate(QuestCode code) const {
        const QuestMap::const_iterator pos = questMap_.find(code);
        if (pos != questMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const QuestMap& getQuestMap() const {
        return questMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::quest_table> questTable_;
    QuestMap questMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
