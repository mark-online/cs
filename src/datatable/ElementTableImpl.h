#pragma once

#include <gideon/cs/datatable/ElementTable.h>

namespace gideon { namespace datatable {

/**
 * @class ElementTableImpl
 *
 */
class ElementTableImpl : public ElementTable
{
public:
    ElementTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            elementTable_ =
                gdt::element_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::element_t& element : elementTable_->element_template()) {
                elementMap_.emplace(element.element_code(), &element);
            }
            isLoaded_ = true;

            ElementTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const gdt::element_t* getElement(ElementCode code) const{
        const ElementMap::const_iterator pos = elementMap_.find(code);
        if (pos != elementMap_.end()) {
            return (*pos).second;
        }
        return nullptr;
    }

    virtual const ElementMap& getElementMap() const {
        return elementMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::element_table> elementTable_;
    ElementMap elementMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
