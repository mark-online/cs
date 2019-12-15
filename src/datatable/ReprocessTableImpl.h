#pragma once

#include <gideon/cs/datatable/ReprocessTable.h>
#include <gideon/cs/datatable/template/reprocess_table.hxx>

namespace gideon { namespace datatable {

/**
 * @class ReprocessTableImpl
 *
 */
class ReprocessTableImpl : public ReprocessTable
{
public:
    ReprocessTableImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            reprocessTable_ =
                gdt::reprocess_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::reprocess_t& reprocess : reprocessTable_->reprocess_template()) {
                ReprocessDropItemInfos infos;
                if (isValidDataCode(reprocess.item_code_1())) {
                    infos.emplace_back(reprocess.item_code_1(), reprocess.min_item_count_1(),
                        reprocess.max_item_count_1(), reprocess.drop_rate_1());
                }
                if (isValidDataCode(reprocess.item_code_2())) {
                    infos.emplace_back(reprocess.item_code_2(), reprocess.min_item_count_2(),
                        reprocess.max_item_count_2(), reprocess.drop_rate_2());
                }
                if (isValidDataCode(reprocess.item_code_3())) {
                    infos.emplace_back(reprocess.item_code_3(), reprocess.min_item_count_3(),
                        reprocess.max_item_count_3(), reprocess.drop_rate_3());
                }
                if (isValidDataCode(reprocess.item_code_4())) {
                    infos.emplace_back(reprocess.item_code_4(), reprocess.min_item_count_4(),
                        reprocess.max_item_count_4(), reprocess.drop_rate_4());
                }
                reprocessMap_.emplace(reprocess.item_code(),
                    ReprocessInfo(toCraftType(reprocess.craft_type()), reprocess.drop_count(), infos));
            }
            isLoaded_ = true;

            ReprocessTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const ReprocessInfo* getReprocessInfo(DataCode itemCode) const {
        const ReprocessMap::const_iterator pos = reprocessMap_.find(itemCode);
        if (pos != reprocessMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const ReprocessMap& getReprocessMap() const {
        return reprocessMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::reprocess_table> reprocessTable_;
    ReprocessMap reprocessMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
