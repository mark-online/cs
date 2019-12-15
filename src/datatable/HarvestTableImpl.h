#pragma once

#include <gideon/cs/datatable/HarvestTable.h>

namespace gideon { namespace datatable {

/**
 * @class HarvestTableImpl
 *
 */
class HarvestTableImpl : public HarvestTable
{
public:
    HarvestTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            harvestTable_ =
                gdt::harvest_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::harvest_t& harvest : harvestTable_->harvest_template()) {
                harvestMap_.emplace(static_cast<HarvestCode>(harvest.harvest_code()), &harvest);
            }
            isLoaded_ = true;

            HarvestTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }
	virtual ~HarvestTableImpl() {
	}

public:
    virtual const gdt::harvest_t* getHarvest(HarvestCode code) const {
        const HarvestMap::const_iterator pos = harvestMap_.find(code);
        if (pos != harvestMap_.end()) {
            return (*pos).second;
        }
        return nullptr;
    }

    virtual const HarvestMap& getHarvestMap() const {
        return harvestMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::harvest_table> harvestTable_;
    HarvestMap harvestMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
