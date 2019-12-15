#pragma once

#include <gideon/cs/datatable/QuestContentsMissionTable.h>

namespace gideon { namespace datatable {

/**
 * @class QuestContentsMissionTableImpl
 *
 */
class QuestContentsMissionTableImpl : public QuestContentsMissionTable
{
public:
    QuestContentsMissionTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            questContentsMissionTable_ =
                gdt::quest_contents_mission_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::quest_contents_mission_t& mission :
                questContentsMissionTable_->quest_contents_mission_template()) {
                questContentsMissionMap_.emplace(
                    mission.mission_code(), QuestContentMissionTemplate(mission));
            }
            QuestContentsMissionTable::instance(this);
            isLoaded_ = true;
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const QuestContentMissionTemplate* getQuestContentsMission(QuestMissionCode code) const {
        const QuestContentsMissionMap::const_iterator pos = questContentsMissionMap_.find(code);
        if (pos != questContentsMissionMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const QuestContentsMissionMap& getQuestContentsMissionMap() const {
        return questContentsMissionMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::quest_contents_mission_table> questContentsMissionTable_;
    QuestContentsMissionMap questContentsMissionMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
