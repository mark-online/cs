#pragma once

#include <gideon/cs/datatable/FactionTable.h>

namespace gideon { namespace datatable {

/**
 * @class FactionTableImpl
 *
 */
class FactionTableImpl : public FactionTable
{
public:
    FactionTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            std::unique_ptr<gdt::faction_table> factionTable =
                gdt::faction_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::faction_t& faction : factionTable->faction_template()) {
                factionMap_.emplace(faction.faction_code(), faction);
            }
            isLoaded_ = true;

            FactionTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const FactionTemplate* getFaction(FactionCode code) const {
        const FactionMap::const_iterator pos = factionMap_.find(code);
        if (pos != factionMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const FactionMap& getFactionMap() const {
        return factionMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    FactionMap factionMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
