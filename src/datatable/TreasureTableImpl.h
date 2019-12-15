#pragma once

#include <gideon/cs/datatable/TreasureTable.h>

namespace gideon { namespace datatable {

/**
 * @class TreasureTableImpl
 *
 */
class TreasureTableImpl : public TreasureTable
{
public:
    TreasureTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            treasureTable_ =
                gdt::treasure_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::treasure_t& treasure : treasureTable_->treasure_template()) {
                treasureMap_.emplace(static_cast<TreasureCode>(treasure.treasure_code()), &treasure);
            }
            isLoaded_ = true;

            TreasureTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }
    virtual ~TreasureTableImpl() {
    }

public:
    virtual const gdt::treasure_t* getTreasure(TreasureCode code) const {
        const TreasureMap::const_iterator pos = treasureMap_.find(code);
        if (pos != treasureMap_.end()) {
            return (*pos).second;
        }
        return nullptr;
    }

    virtual const TreasureMap& getTreasureMap() const {
        return treasureMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::treasure_table> treasureTable_;
    TreasureMap treasureMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
