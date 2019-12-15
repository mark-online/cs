#pragma once

#include <gideon/cs/datatable/FragmentTable.h>

namespace gideon { namespace datatable {

/**
 * @class FragmentTableImpl
 *
 */
class FragmentTableImpl : public FragmentTable
{
public:
    FragmentTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            fragmentTable_ =
                gdt::fragment_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::fragment_t& fragment : fragmentTable_->fragment_template()) {
                fragmentMap_.emplace(fragment.item_code(), &fragment);
            }
            isLoaded_ = true;

            FragmentTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const gdt::fragment_t* getFragment(FragmentCode code) const {
        const FragmentMap::const_iterator pos = fragmentMap_.find(code);
        if (pos != fragmentMap_.end()) {
            return (*pos).second;
        }
        return nullptr;
    }

    virtual const FragmentMap& getFragmentMap() const {
        return fragmentMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::fragment_table> fragmentTable_;
    FragmentMap fragmentMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
