#pragma once

#include <gideon/cs/datatable/L10nTable.h>

namespace gideon { namespace datatable {

/**
 * @class L10nTableImpl
 *
 */
class L10nTableImpl : public L10nTable
{
public:
    L10nTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            l10nTable_ =
                gdt::l10n_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::l10n_t& l10n : l10nTable_->l10n_template()) {
                l10nMap_.emplace(l10n.data_code(), &l10n);
            }
            isLoaded_ = true;
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const gdt::l10n_t* getL10n(DataCode code) const {
        const L10nMap::const_iterator pos = l10nMap_.find(code);
        if (pos != l10nMap_.end()) {
            return (*pos).second;
        }
        return nullptr;
    }

    virtual const L10nMap& getL10nMap() const {
        return l10nMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::l10n_table> l10nTable_;
    L10nMap l10nMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
