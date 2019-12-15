#pragma once

#include <gideon/cs/datatable/HelpTable.h>

namespace gideon { namespace datatable {

/**
 * @class HelpTableImpl
 *
 */
class HelpTableImpl : public HelpTable
{
public:
    HelpTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            helpTable_ =
                gdt::help_table_(is, ::xml_schema::flags::dont_validate);
            isLoaded_ = true;
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const gdt::help_table::help_template_sequence& getHelpTemplates() const {
        return helpTable_->help_template();
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::help_table> helpTable_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
