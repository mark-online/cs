#pragma once

#include <gideon/cs/datatable/GemTable.h>

namespace gideon { namespace datatable {

/**
 * @class GemTableImpl
 *
 */
class GemTableImpl : public GemTable
{
public:
    GemTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            gemTable_ =
                gdt::gem_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::gem_t& gem : gemTable_->gem_template()) {
                gemMap_.emplace(gem.item_code(), &gem);
            }
            isLoaded_ = true;

            GemTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const gdt::gem_t* getGem(GemCode code) const {
        const GemMap::const_iterator pos = gemMap_.find(code);
        if (pos != gemMap_.end()) {
            return (*pos).second;
        }
        return nullptr;
    }

    virtual const GemMap& getGemMap() const {
        return gemMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::gem_table> gemTable_;
    GemMap gemMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
