#pragma once

#include <gideon/cs/datatable/ActivationObjectTable.h>
#include <boost/foreach.hpp>
#include <boost/scoped_ptr.hpp>
#include <iosfwd>

namespace gideon { namespace datatable {

/**
 * @class ActivationObjectTableImpl
 *
 */
class ActivationObjectTableImpl : public ActivationObjectTable
{
public:
    ActivationObjectTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            activationObjectTable_.reset(
                gdt::activation_object_table_(is, ::xml_schema::flags::dont_validate).release());

            BOOST_FOREACH(const gdt::activation_object_t& activationObject, activationObjectTable_->activation_object_template()) {
                activationObjectMap_.insert(ActivationObjectMap::value_type(static_cast<ActivationObjectCode>(activationObject.object_code()),
					ActivationObjectTemplate(activationObject)));
            }
            isLoaded_ = true;

            ActivationObjectTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }
	virtual ~ActivationObjectTableImpl() {
	}

public:
    virtual const ActivationObjectTemplate* getActivationObjectTemplate(ActivationObjectCode code) const {
        const ActivationObjectMap::const_iterator pos = activationObjectMap_.find(code);
        if (pos != activationObjectMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const ActivationObjectMap& getActivationObjectMap() const {
        return activationObjectMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    boost::scoped_ptr<gdt::activation_object_table> activationObjectTable_;
    ActivationObjectMap activationObjectMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
