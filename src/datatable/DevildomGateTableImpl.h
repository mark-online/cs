#pragma once

#include <gideon/cs/datatable/DevildomGateTable.h>

namespace gideon { namespace datatable {

/**
 * @class DevildomGateTableImpl
 *
 */
class DevildomGateTableImpl : public DevildomGateTable
{
public:
    DevildomGateTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            devildomGateTable_ =
                gdt::devildom_gate_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::devildom_gate_t& devildomGate : devildomGateTable_->devildom_gate_template()) {
                DevildomGateMap_.emplace(devildomGate.devildom_gate_code(), &devildomGate);
            }
            isLoaded_ = true;

            DevildomGateTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const gdt::devildom_gate_t* getDevildomGate(DataCode code) const {
        const DevildomGateMap::const_iterator pos = DevildomGateMap_.find(code);
        if (pos != DevildomGateMap_.end()) {
            return (*pos).second;
        }
        return nullptr;
    }

    virtual const DevildomGateMap& getDevildomGateMap() const {
        return DevildomGateMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::devildom_gate_table> devildomGateTable_;
    DevildomGateMap DevildomGateMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
