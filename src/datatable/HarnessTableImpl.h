#pragma once

#include <gideon/cs/datatable/HarnessTable.h>

namespace gideon { namespace datatable {

/**
 * @class HarnessTableImpl
 *
 */
class HarnessTableImpl : public HarnessTable
{
public:
    HarnessTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            harnessTable_ =
                gdt::harness_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::harness_t& harness : harnessTable_->harness_template()) {
                harnessMap_.emplace(harness.harness_code(), &harness);
            }
            HarnessTable::instance(this);
            isLoaded_ = true;
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const gdt::harness_t* getHarness(HarnessCode code) const {
        const HarnessMap::const_iterator pos = harnessMap_.find(code);
        if (pos != harnessMap_.end()) {
            return (*pos).second;
        }
        return nullptr;
    }

    virtual const HarnessMap& getHarnessMap() const {
        return harnessMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::harness_table> harnessTable_;
    HarnessMap harnessMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
