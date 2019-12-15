#pragma once

#include <gideon/cs/datatable/ItemDropTable.h>
#include <gideon/cs/datatable/RecipeTable.h>
#include <gideon/cs/shared/data/ElementInfo.h>
#include "esut/Random.h"

namespace gideon { namespace datatable {

namespace {

/**
 * @class RecipeHelper
 */
class RecipeHelper
{
public:
    enum {
        componentCount = 3
    };

public:
    RecipeHelper(const gdt::recipe_t& recipe) :
        recipe_(recipe) {}

    BaseItemInfos getNeedElementInfos() const {
        BaseItemInfos needComponentInfos;
        needComponentInfos.reserve(RecipeHelper::componentCount);
        for (int i = 1; i <= RecipeHelper::componentCount; ++i) {
            const BaseItemInfo needComponentInfo = getItemDropInfo(i);
            if (isValidDataCode(needComponentInfo.itemCode_) && needComponentInfo.count_ > 0) {
                needComponentInfos.push_back(needComponentInfo);
            }
        }
        return needComponentInfos;
    }

    bool hasIngredient(DataCode itemCode) const {
        for (int i = 1; i <= RecipeHelper::componentCount; ++i) {
            const BaseItemInfo needComponentInfo = getItemDropInfo(i);
            if (needComponentInfo.itemCode_ == itemCode) {
                return true;
            }
        }
        return false;
    }

private:
    BaseItemInfo getItemDropInfo(int num) const {
        return BaseItemInfo(element_code(num), need_count(num));
    }

    ElementCode element_code(int num) const {
        switch (num) {
        case 1:
            return recipe_.need_item_1();
        case 2:
            return recipe_.need_item_2();
        case 3:
            return recipe_.need_item_3();
        default:
            assert(false);
        }
        return invalidElementCode;
    }

    uint8_t need_count(int num) const {
        switch (num) {
        case 1:
            return recipe_.need_item_count_1();
        case 2:
            return recipe_.need_item_count_2();
        case 3:
            return recipe_.need_item_count_3();
        default:
            assert(false);
        }
        return invalidElementCode;
    }

private:
    const gdt::recipe_t& recipe_;
};

} // namespace {

/**
 * @class RecipeTableImpl
 *
 */
class RecipeTableImpl : public RecipeTable
{
public:
    RecipeTableImpl(std::istream& is) :
        isLoaded_(false) {
        try {
            recipeTable_ =
                gdt::recipe_table_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::recipe_t& recipe : recipeTable_->recipe_template()) {
                const RecipeHelper recipeHelper(recipe);
                const BaseItemInfos needElementInfos = recipeHelper.getNeedElementInfos();

                const RecipeCode recipeCode = recipe.recipe_code();
                const GameTime complateMilSec = recipe.complete_mil_sec();
                const DataCode complateItemCode = recipe.complete_item_code();

                recipeMap_.emplace(recipeCode,
                    RecipeTemplate(recipe, recipeCode, complateMilSec, complateItemCode, needElementInfos));
            }
            isLoaded_ = true;

            RecipeTable::instance(this);
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

private:
    virtual const RecipeTemplate* getRecipe(RecipeCode code) const {
        const RecipeMap::const_iterator pos = recipeMap_.find(code);
        if (pos != recipeMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const RecipeMap& getRecipeMap() const {
        return recipeMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    virtual const RecipeTemplate* getRecipeOf(DataCode itemCode) const {
        for (const RecipeMap::value_type& value : recipeMap_) {
            const RecipeTemplate& recipeTemplate = value.second;
            if (recipeTemplate.getCompleteItemCode() == itemCode) {
                return &recipeTemplate;
            }
        }
        return nullptr;
    }

    virtual Recipes getRecipesBy(DataCode itemCode) const {
        Recipes recipes;
        recipes.reserve(10);
        for (const RecipeMap::value_type& value : recipeMap_) {
            const RecipeTemplate& recipeTemplate = value.second;
            if (RecipeHelper(recipeTemplate.getInfo()).hasIngredient(itemCode)) {
                recipes.push_back(&recipeTemplate);
            }
        }
        return recipes;
    }

private:
    std::unique_ptr<gdt::recipe_table> recipeTable_;
    RecipeMap recipeMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
