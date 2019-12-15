#pragma once

#include <gideon/cs/shared/data/MercenaryInfo.h>
#include <gideon/cs/datatable/GliderTable.h>

namespace gideon { namespace datatable {

/**
 * @class GliderTableImpl
 *
 */
class GliderTableImpl : public GliderTable
{
public:
    GliderTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            gliderTable_ =
                gdt::glider_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::glider_t& glider : gliderTable_->glider_template()) {
                gliderMap_.emplace(glider.glider_code(), &glider);
            }
            GliderTable::instance(this);
            isLoaded_ = true;
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const gdt::glider_t* getGlider(GliderCode code) const {
        const GliderMap::const_iterator pos = gliderMap_.find(code);
        if (pos != gliderMap_.end()) {
            return (*pos).second;
        }
        return nullptr;
    }

    virtual const GliderMap& getGliderMap() const {
        return gliderMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::glider_table> gliderTable_;
    GliderMap gliderMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
