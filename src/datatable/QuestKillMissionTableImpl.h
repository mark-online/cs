#pragma once

#include <gideon/cs/datatable/QuestKillMissionTable.h>

namespace gideon { namespace datatable {

/**
 * @class QuestKillMissionTableImpl
 *
 */
class QuestKillMissionTableImpl : public QuestKillMissionTable
{
public:
    QuestKillMissionTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            questKillMissionTable_ =
                gdt::quest_kill_mission_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::quest_kill_mission_t& mission :
                questKillMissionTable_->quest_kill_mission_template()) {
                questKillMissionMap_.emplace(mission.mission_code(), QuestKillMissionTemplate(mission));
            }
            isLoaded_ = true;

            QuestKillMissionTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const QuestKillMissionTemplate* getQuestKillMissionTemplate(QuestMissionCode code) const {
        const QuestKillMissionMap::const_iterator pos = questKillMissionMap_.find(code);
        if (pos != questKillMissionMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const QuestKillMissionMap& getQuestKillMissionMap() const {
        return questKillMissionMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::quest_kill_mission_table> questKillMissionTable_;
    QuestKillMissionMap questKillMissionMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
