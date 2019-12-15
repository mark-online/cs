#pragma once

#include <gideon/cs/datatable/AnchorTable.h>

namespace gideon { namespace datatable {

/**
 * @class AnchorTableImpl
 *
 */
class AnchorTableImpl : public AnchorTable
{
public:
    AnchorTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            anchorTable_ =
                gdt::anchor_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::anchor_t& anchor : anchorTable_->anchor_template()) {
                anchorMap_.emplace(static_cast<AnchorCode>(anchor.anchor_code()),
					AnchorTemplate(anchor));
            }
            isLoaded_ = true;

            AnchorTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }
	virtual ~AnchorTableImpl() {
	}

public:
    virtual const AnchorTemplate* getAnchorTemplate(AnchorCode code) const {
        const AnchorMap::const_iterator pos = anchorMap_.find(code);
        if (pos != anchorMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const AnchorMap& getAnchorMap() const {
        return anchorMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::anchor_table> anchorTable_;
    AnchorMap anchorMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
