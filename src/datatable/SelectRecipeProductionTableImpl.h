#pragma once

#include <gideon/cs/datatable/SelectRecipeProductionTable.h>
#include <gideon/cs/datatable/template/select_recipe_production_table.hxx>

namespace gideon { namespace datatable {

/**
 * @class SelectRecipeProductionTableImpl
 *
 */
class SelectRecipeProductionTableImpl : public SelectRecipeProductionTable
{
public:
    SelectRecipeProductionTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            selectRecipeProductionTable_ =
                gdt::select_recipe_production_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::select_recipe_production_t& production :
                selectRecipeProductionTable_->select_recipe_production_template()) {
                SelectRecipeProductionInfos infos;
                if (production.recipe_code_1() != invalidRecipeCode) {
                    infos.emplace_back(production.recipe_code_1(),
                        production.max_count_1());
                }
                if (production.recipe_code_2() != invalidRecipeCode) {
                    infos.emplace_back(production.recipe_code_2(),
                        production.max_count_2());
                }
                if (production.recipe_code_3() != invalidRecipeCode) {
                    infos.emplace_back(production.recipe_code_3(),
                        production.max_count_3());
                }
                if (production.recipe_code_4() != invalidRecipeCode) {
                    infos.emplace_back(production.recipe_code_4(),
                        production.max_count_4());
                }
                if (production.recipe_code_5() != invalidRecipeCode) {
                    infos.emplace_back(production.recipe_code_5(),
                        production.max_count_5());
                }
                selectRecipeProductionMap_.emplace(production.select_resources_production_code(),
                    infos);
            }
            isLoaded_ = true;

            SelectRecipeProductionTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

    virtual ~SelectRecipeProductionTableImpl() {}

private:
    virtual const SelectRecipeProductionInfos* getSelectRecipeProductionInfos(uint32_t index) const {
        const SelectRecipeProductionInfosMap::const_iterator pos = selectRecipeProductionMap_.find(index);
        if (pos != selectRecipeProductionMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const SelectRecipeProductionInfosMap& getSelectRecipeProductionInfosMap() const {
        return selectRecipeProductionMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    std::unique_ptr<gdt::select_recipe_production_table> selectRecipeProductionTable_;
    SelectRecipeProductionInfosMap selectRecipeProductionMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
