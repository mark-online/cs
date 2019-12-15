#pragma once

#include <gideon/cs/datatable/DominionRegionTable.h>

namespace gideon { namespace datatable {

/**
 * @class DominionRegionTableImpl
 *
 */
class DominionRegionTableImpl : public DominionRegionTable
{
public:
    DominionRegionTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            dominionRegionTable_ =
                gdt::dominion_region_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::dominion_region_t& dominionRegion : dominionRegionTable_->dominion_region_template()) {
                dominionRegionList_.push_back(&dominionRegion);
            }
            isLoaded_ = true;

            DominionRegionTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }
    virtual ~DominionRegionTableImpl() {
    }

public:
    virtual const DominionRegionsList& getDominionRegionList() const {
        return dominionRegionList_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::dominion_region_table> dominionRegionTable_;
    DominionRegionsList dominionRegionList_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
