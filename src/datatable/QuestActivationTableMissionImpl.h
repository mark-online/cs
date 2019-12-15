#pragma once

#include <gideon/cs/datatable/QuestActivationMissionTable.h>

namespace gideon { namespace datatable {

/**
 * @class QuestActivationMissionTableImpl
 *
 */
class QuestActivationMissionTableImpl : public QuestActivationMissionTable
{
public:
    QuestActivationMissionTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            questTable_ =
                gdt::quest_activation_mission_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::quest_activation_mission_t& mission :
                questTable_->quest_activation_mission_template()) {
                questActivationMissionMap_.emplace(mission.mission_code(),
                    QuestActivationMissionTemplate(mission));
            }
            isLoaded_ = true;

            QuestActivationMissionTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const QuestActivationMissionTemplate*
        getQuestActivationMissionTemplate(QuestMissionCode code) const {
        const QuestActivationMissionMap::const_iterator pos = questActivationMissionMap_.find(code);
        if (pos != questActivationMissionMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const QuestActivationMissionMap& getQuestQuestActivationMissionMap() const {
        return questActivationMissionMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::quest_activation_mission_table> questTable_;
    QuestActivationMissionMap questActivationMissionMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
