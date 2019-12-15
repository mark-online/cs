#pragma once

#include <gideon/cs/datatable/template/help_table.hxx>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @class HelpTable
 * 도움말 테이블
 */
class GIDEON_CS_API HelpTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(HelpTable);

public:
    virtual ~HelpTable() {}

public:
    virtual const gdt::help_table::help_template_sequence& getHelpTemplates() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define HELP_TABLE gideon::datatable::HelpTable::instance()
