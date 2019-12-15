#pragma once

#include <gideon/cs/datatable/BuildingGuardSellTable.h>
#include <gideon/cs/datatable/template/building_guard_sell_table.hxx>

namespace gideon { namespace datatable {

namespace {

DataCode createCostInfo(int index, const gdt::building_guard_sell_t& buildingGuard)
{
	switch (index) {
	case 1:
		return buildingGuard.building_guard_code_1();
	case 2:
		return buildingGuard.building_guard_code_2();
	case 3:
		return buildingGuard.building_guard_code_3();
	case 4:
		return buildingGuard.building_guard_code_4();
	case 5:
		return buildingGuard.building_guard_code_5();
	case 6:
		return buildingGuard.building_guard_code_6();
	case 7:
		return buildingGuard.building_guard_code_7();
	case 8:
		return buildingGuard.building_guard_code_8();
	case 9:
		return buildingGuard.building_guard_code_9();
	case 10:
		return buildingGuard.building_guard_code_10();	
	}
	return invalidDataCode;
}


inline void insertCostInfo(GuardSellList& sellList, const gdt::building_guard_sell_t& buildingGuard)
{
	for (int i = 1; i <= 10; ++i) {
		DataCode itemCode = createCostInfo(i, buildingGuard);
		if (! isValidDataCode(itemCode)) {
			continue;
		}
		sellList.insert(itemCode);
	}
}

} // namespace {


/**
 * @class BuildingGuardSellTableImpl
 *
 */
class BuildingGuardSellTableImpl : public BuildingGuardSellTable
{
public:
    BuildingGuardSellTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            buildingGuardSellTable_ =
                gdt::building_guard_sell_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::building_guard_sell_t& buildingGuard :
                buildingGuardSellTable_->building_guard_sell_template()) {
				SellListMap::iterator pos = sellListMap_.find(buildingGuard.building_code());
				if (pos != sellListMap_.end()) {
					SellList& sellList = (*pos).second;
					insertCostInfo(sellList, buildingGuard);
				}
				else {
					GuardSellList sellList;
					insertCostInfo(sellList, buildingGuard);
					sellListMap_.emplace(buildingGuard.building_code(), sellList);
				}        
            }
            isLoaded_ = true;

            BuildingGuardSellTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }
	virtual ~BuildingGuardSellTableImpl() {
	}

public:
    virtual const GuardSellList* getSellList(BuildingCode code) const {
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
    std::unique_ptr<gdt::building_guard_sell_table> buildingGuardSellTable_;
    SellListMap sellListMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
