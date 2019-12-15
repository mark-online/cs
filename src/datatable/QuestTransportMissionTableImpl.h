#pragma once

#include <gideon/cs/datatable/QuestTransportMissionTable.h>

namespace gideon { namespace datatable {

/**
 * @class QuestTransportMissionTableImpl
 *
 */
class QuestTransportMissionTableImpl : public QuestTransportMissionTable
{
public:
    QuestTransportMissionTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            transportMissionTable_ =
                gdt::quest_transport_mission_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::quest_transport_mission_t& mission :
                transportMissionTable_->quest_transport_mission_template()) {
                questTransportMissionMap_.emplace(mission.mission_code(),
                    QuestTransportMissionTemplate(mission));
            }
            isLoaded_ = true;

            QuestTransportMissionTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const QuestTransportMissionTemplate* getQuestTransportMissionTemplate(QuestMissionCode code) const {
        const QuestTransportMissionMap::const_iterator pos = questTransportMissionMap_.find(code);
        if (pos != questTransportMissionMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const QuestTransportMissionMap& getQuestTransportMissionMap() const {
        return questTransportMissionMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::quest_transport_mission_table> transportMissionTable_;
    QuestTransportMissionMap questTransportMissionMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
