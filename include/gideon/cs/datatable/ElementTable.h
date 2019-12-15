 #pragma once

#include <gideon/cs/datatable/template/element_table.hxx>
#include <gideon/cs/shared/data/ElementInfo.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @class ElementTable
 * 재료 테이블
 */
class GIDEON_CS_API ElementTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(ElementTable);

public:
    typedef sne::core::HashMap<ElementCode, const gdt::element_t*> ElementMap;

public:
    virtual ~ElementTable() {}

public:
    virtual const gdt::element_t* getElement(ElementCode code) const = 0;

    virtual const ElementMap& getElementMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define ELEMENT_TABLE gideon::datatable::ElementTable::instance()
