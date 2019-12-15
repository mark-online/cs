#pragma once

#include <gideon/cs/datatable/NpcBuyTable.h>

namespace gideon { namespace datatable {

/**
 * @class NpcBuyTableImpl
 *
 */
class NpcBuyTableImpl : public NpcBuyTable
{
public:
    NpcBuyTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            npcBuyTable_ =
                gdt::npc_buy_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::npc_buy_t& npcBuy : npcBuyTable_->npc_buy_template()) {
                npcBuyMap_.emplace(npcBuy.npc_code(), &npcBuy);
            }
            isLoaded_ = true;

            NpcBuyTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const gdt::npc_buy_t* getNpcBuyTemplate(NpcCode code) const {
        const NpcBuyMap::const_iterator pos = npcBuyMap_.find(code);
        if (pos != npcBuyMap_.end()) {
            return (*pos).second;
        }
        return nullptr;
    }

    virtual const NpcBuyMap& getNpcBuyMap() const {
        return npcBuyMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::npc_buy_table> npcBuyTable_;
    NpcBuyMap npcBuyMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
