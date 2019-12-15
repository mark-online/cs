#pragma once

#include <gideon/cs/datatable/QuestObtainMissionTable.h>

namespace gideon { namespace datatable {

/**
 * @class QuestObtainMissionTableImpl
 *
 */
class QuestObtainMissionTableImpl : public QuestObtainMissionTable
{
public:
    QuestObtainMissionTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            questObtainMissionTable_ =
                gdt::quest_obtain_mission_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::quest_obtain_mission_t& mission :
                questObtainMissionTable_->quest_obtain_mission_template()) {
                questObtainMissionMap_.emplace(mission.mission_code(),
                    QuestObtainMissionTemplate(mission));
            }
            isLoaded_ = true;

            QuestObtainMissionTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const QuestObtainMissionTemplate* getQuestObtainMissionTemplate(QuestMissionCode code) const {
        const QuestObtainMissionMap::const_iterator pos = questObtainMissionMap_.find(code);
        if (pos != questObtainMissionMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const QuestObtainMissionMap& getQuestObtainMissionMap() const {
        return questObtainMissionMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::quest_obtain_mission_table> questObtainMissionTable_;
    QuestObtainMissionMap questObtainMissionMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
