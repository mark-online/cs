#pragma once

#include <gideon/cs/datatable/EntityPathTable.h>

namespace gideon { namespace datatable {

/**
 * @class EntityPathTableImpl
 *
 */
class EntityPathTableImpl : public EntityPathTable
{
public:
    EntityPathTableImpl(std::istream& is) :
        isLoaded_(false) {
            try {
                entityPathTable_ =
                    gdt::entity_path_table_(is, ::xml_schema::flags::dont_validate);

                for (const gdt::entity_path_t& path : entityPathTable_->entity_path_template()) {
                    entityPathMap_.emplace(path.entity_path_code(), &path);
                }
                isLoaded_ = true;
            }
            catch (const xml_schema::exception& e) {
                lastError_ = e.what();
            }
    }

public:
    virtual const gdt::entity_path_t* getEntityPath(EntityPathCode code) const  {
        const EntityPathMap::const_iterator pos = entityPathMap_.find(code);
        if (pos != entityPathMap_.end()) {
            return (*pos).second;
        }
        return nullptr;
    }

    virtual const EntityPathMap& getEntityPathMap() const {
        return entityPathMap_;
    }

    const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::entity_path_table> entityPathTable_;
    EntityPathMap entityPathMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
