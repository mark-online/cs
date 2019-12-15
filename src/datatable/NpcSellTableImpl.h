#pragma once

#include <gideon/cs/datatable/NpcSellTable.h>
#include <gideon/cs/datatable/template/npc_sell_table.hxx>

namespace gideon { namespace datatable {

namespace {

DataCode createCostInfo(int index, const gdt::npc_sell_t& npcSell)
{
    switch (index) {
    case 1:
        return npcSell.item_code_1();
    case 2:
        return npcSell.item_code_2();
    case 3:
        return npcSell.item_code_3();
    case 4:
        return npcSell.item_code_4();
    case 5:
        return npcSell.item_code_5();
    case 6:
        return npcSell.item_code_6();
    case 7:
        return npcSell.item_code_7();
    case 8:
        return npcSell.item_code_8();
    case 9:
        return npcSell.item_code_9();
    case 10:
        return npcSell.item_code_10();	
    }
    return invalidDataCode;
}


inline void insertCostInfo(SellList& sellList, const gdt::npc_sell_t& npcSell)
{
    for (int i = 1; i <= 10; ++i) {
        DataCode itemCode = createCostInfo(i, npcSell);
        if (! isValidDataCode(itemCode)) {
            continue;
        }
        sellList.insert(itemCode);
    }
}

} // namespace {


/**
 * @class NpcSellTableImpl
 *
 */
class NpcSellTableImpl : public NpcSellTable
{
public:
    NpcSellTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            npcSellTable_ =
                gdt::npc_sell_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::npc_sell_t& npcSell : npcSellTable_->npc_sell_template()) {
                SellListMap::iterator pos = sellListMap_.find(npcSell.npc_code());
                if (pos != sellListMap_.end()) {
                    SellList& sellList = (*pos).second;
                    insertCostInfo(sellList, npcSell);
                }
                else {
                    SellList sellList;
                    insertCostInfo(sellList, npcSell);
                    sellListMap_.emplace(npcSell.npc_code(), sellList);
                }        
            }
            isLoaded_ = true;

            NpcSellTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }
    virtual ~NpcSellTableImpl() {
    }

public:
    virtual const SellList* getSellList(NpcCode code) const {
        const SellListMap::const_iterator pos = sellListMap_.find(code);
        if (pos != sellListMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const SellListMap& getSellListMap() const {
        return sellListMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::npc_sell_table> npcSellTable_;
    SellListMap sellListMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
