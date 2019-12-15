#pragma once

#include <gideon/cs/datatable/ActionTable.h>

namespace gideon { namespace datatable {

/**
 * @class ActionTableImpl
 *
 */
class ActionTableImpl : public ActionTable
{
public:
    ActionTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            actionTable_ =
                gdt::action_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::action_t& action : actionTable_->action_template()) {
                actionMap_.emplace(action.action_code(), &action);
            }
			ActionTable::instance(this);
            isLoaded_ = true;
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const gdt::action_t* getAction(ActionCode code) const {
        const ActionMap::const_iterator pos = actionMap_.find(code);
        if (pos != actionMap_.end()) {
            return (*pos).second;
        }
        return nullptr;
    }

    virtual const ActionMap& getActionMap() const {
        return actionMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::action_table> actionTable_;
    ActionMap actionMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
