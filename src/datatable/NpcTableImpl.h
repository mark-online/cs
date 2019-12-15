#pragma once

#include <gideon/cs/datatable/NpcTable.h>

namespace gideon { namespace datatable {

/**
 * @class NpcTableImpl
 *
 */
class NpcTableImpl : public NpcTable
{
public:
    NpcTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            npcTable_ =
                gdt::npc_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::npc_t& npc : npcTable_->npc_template()) {
                npcMap_.emplace(npc.npc_code(), NpcTemplate(npc));
            }
            isLoaded_ = true;

            NpcTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const NpcTemplate* getNpcTemplate(NpcCode code) const {
        const NpcMap::const_iterator pos = npcMap_.find(code);
        if (pos != npcMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const NpcMap& getNpcMap() const {
        return npcMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::npc_table> npcTable_;
    NpcMap npcMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
