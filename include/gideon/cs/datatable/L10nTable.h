#pragma once

#include <gideon/cs/datatable/template/l10n_table.hxx>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @class L10nTable
 * 데이터 언어(지역화) 테이블
 */
class GIDEON_CS_API L10nTable : public boost::noncopyable
{
public:
    typedef sne::core::HashMap<DataCode, const gdt::l10n_t*> L10nMap;

public:
    virtual ~L10nTable() {}

public:
    virtual const gdt::l10n_t* getL10n(DataCode code) const = 0;

    virtual const L10nMap& getL10nMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {
