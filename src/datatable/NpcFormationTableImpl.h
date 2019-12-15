#pragma once

#include <gideon/cs/datatable/NpcFormationTable.h>

namespace gideon { namespace datatable {

/**
 * @class NpcFormationTableImpl
 *
 */
class NpcFormationTableImpl : public NpcFormationTable
{
public:
    NpcFormationTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            npcFormationTable_ =
                gdt::npc_formation_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::npc_formation_t& npcFormation : npcFormationTable_->npc_formation_template()) {
                Members& members = npcFormationMap_[npcFormation.leader_npc_code()];
                members.push_back(&npcFormation);
            }
            isLoaded_ = true;

            NpcFormationTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const Members* getNpcFormation(NpcCode leaderNpcCode) const {
        const NpcFormationMap::const_iterator pos = npcFormationMap_.find(leaderNpcCode);
        if (pos != npcFormationMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const NpcFormationMap& getNpcFormationMap() const {
        return npcFormationMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::npc_formation_table> npcFormationTable_;
    NpcFormationMap npcFormationMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
