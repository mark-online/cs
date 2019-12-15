#pragma once

#include <gideon/cs/datatable/NpcTalkingTable.h>
#include <boost/foreach.hpp>
#include <boost/scoped_ptr.hpp>
#include <iosfwd>
#include <fstream>

namespace gideon { namespace datatable {

/**
 * @class NpcTalkingTableImpl
 *
 */
class NpcTalkingTableImpl : public NpcTalkingTable
{
    typedef sne::core::HashMap<NpcTalkingCode, NpcTalkingTemplate> NpcTalkingMap;

public:
    NpcTalkingTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            npcTalkingTable_ =
                gdt::npc_talking_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::npc_talking_t& talking :
                npcTalkingTable_->npc_talking_template()) {
                const NpcTalkingCode talkingCode = talking.npc_talking_code();
                npcTalkingMap_.emplace(talkingCode, NpcTalkingTemplate(talking));
                npcTalkingListMap_[talking.npc_code()].push_back(
                    getNpcTalkingTemplate(talkingCode));
            }
            isLoaded_ = true;

            NpcTalkingTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const NpcTalkingTemplate* getNpcTalkingTemplate(NpcTalkingCode talkingCode) const {
        const NpcTalkingMap::const_iterator pos = npcTalkingMap_.find(talkingCode);
        if (pos != npcTalkingMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const NpcTalkingList* getNpcTalkingList(NpcCode code) const {
        const NpcTalkingListMap::const_iterator pos = npcTalkingListMap_.find(code);
        if (pos != npcTalkingListMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const NpcTalkingListMap& getNpcTalkingListMap() const {
        return npcTalkingListMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::npc_talking_table> npcTalkingTable_;
    NpcTalkingMap npcTalkingMap_;
    NpcTalkingListMap npcTalkingListMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
