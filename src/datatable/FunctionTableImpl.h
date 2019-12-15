#pragma once

#include <gideon/cs/datatable/FunctionTable.h>

namespace gideon { namespace datatable {

/**
 * @class FunctionTableImpl
 *
 */
class FunctionTableImpl : public FunctionTable
{
public:
    FunctionTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            functionTable_ =
                gdt::function_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::function_t& function : functionTable_->function_template()) {
                functionMap_.emplace(function.item_code(), &function);
            }
            FunctionTable::instance(this);
            isLoaded_ = true;
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const gdt::function_t* getFunction(FunctionCode code) const {
        const FunctionMap::const_iterator pos = functionMap_.find(code);
        if (pos != functionMap_.end()) {
            return (*pos).second;
        }
        return nullptr;
    }

    virtual const FunctionMap& getFunctionMap() const {
        return functionMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::function_table> functionTable_;
    FunctionMap functionMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
