#pragma once

#include <gideon/cs/datatable/QuestProbeMissionTable.h>

namespace gideon { namespace datatable {

/**
 * @class QuestProbeMissionTableImpl
 *
 */
class QuestProbeMissionTableImpl : public QuestProbeMissionTable
{
public:
    QuestProbeMissionTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            questProbeMissionTable_ =
                gdt::quest_probe_mission_table_(is, ::xml_schema::flags::dont_validate);

            for (gdt::quest_probe_mission_t& mission :
                questProbeMissionTable_->quest_probe_mission_template()) {
                questProbeMissionMap_.emplace(static_cast<QuestMissionCode>(mission.mission_code()),
                    QuestProbeMissionTemplate(mission));
            }
            isLoaded_ = true;

            QuestProbeMissionTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const QuestProbeMissionTemplate* getQuestProbeMission(QuestMissionCode code) const {
        const QuestProbeMissionMap::const_iterator pos = questProbeMissionMap_.find(code);
        if (pos != questProbeMissionMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const QuestProbeMissionMap& getQuestProbeMissionMap() const {
        return questProbeMissionMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::quest_probe_mission_table> questProbeMissionTable_;
    QuestProbeMissionMap questProbeMissionMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
