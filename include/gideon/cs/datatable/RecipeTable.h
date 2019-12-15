#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/datatable/template/recipe_table.hxx>
#include <gideon/cs/shared/data/RecipeInfo.h>
#include <gideon/cs/shared/data/CraftInfo.h>
#include <gideon/cs/shared/data/NpcInfo.h>
#include <gideon/cs/shared/data/ElementInfo.h>
#include <gideon/cs/shared/data/ItemInfo.h>
#include <gideon/cs/shared/data/Time.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {


/**
 * @class RecipeTemplate
 */
class RecipeTemplate
{
public:
    RecipeTemplate(const gdt::recipe_t& recipeInfo,
        RecipeCode recipeCode, GameTime completeMilSec,
        DataCode completeItemCode, 
        const BaseItemInfos& needItemInfos) :
        recipeInfo_(recipeInfo),
		recipeCode_(recipeCode),
        craftType_(toCraftType(recipeInfo.craft_type())),
        lootingMilSec_(recipeInfo_.looting_mil_sec()),
        completeMilSec_(completeMilSec),
        completeItemCode_(completeItemCode),
		needItemInfos_(needItemInfos) {}

	RecipeCode getRecipeCode() const {
		return recipeCode_;
	}
    
    uint8_t getStackCount() const {
        return static_cast<uint8_t>(recipeInfo_.stack_count());
    }

    GameTime getCompleteMilSec() const {
        return completeMilSec_;
    }

    DataCode getCompleteItemCode() const {
        return completeItemCode_;
    }

    CraftType getCraftType() const {
        return craftType_;
    }

    int32_t getLootingMilSec() const {
        return lootingMilSec_;
    }

    bool isRecipeItem() const {
        return recipeInfo_.is_recipe_item() != 0;
    }

	const BaseItemInfos& getNeedItemInfos() const {
		return needItemInfos_;
	}
    
    const gdt::recipe_t& getInfo() const {
        return recipeInfo_;
    }
private:
    const gdt::recipe_t& recipeInfo_;
    const CraftType craftType_;
    const RecipeCode recipeCode_;
    const GameTime lootingMilSec_;
    const GameTime completeMilSec_;
    const DataCode completeItemCode_;
	const BaseItemInfos needItemInfos_;    
};


typedef sne::core::Vector<RecipeCode> RecipeCodes;

/**
 * @class RecipeTable
 *
 */
class GIDEON_CS_API RecipeTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(RecipeTable);

public:
    typedef sne::core::HashMap<RecipeCode, RecipeTemplate> RecipeMap;
	typedef std::array<RecipeCodes, rgCount> RecipeGradeCodes;
    typedef sne::core::Vector<const RecipeTemplate*> Recipes;
    typedef sne::core::HashMap<uint32_t, Recipes> GradeRecipesMap;

public:
    virtual ~RecipeTable() {}

public:
    virtual const RecipeTemplate* getRecipe(RecipeCode code) const = 0;

    virtual const RecipeMap& getRecipeMap() const = 0;
    
    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;

public:
    /// itemCode를 만들 때 필요한 제조(법)을 리턴한다
    virtual const RecipeTemplate* getRecipeOf(DataCode itemCode) const = 0;

    /// itemCode가 재료가 되는 제조(법) 목록 리턴
    virtual Recipes getRecipesBy(DataCode itemCode) const = 0;
};

}} // namespace gideon { namespace datatable {

#define RECIPE_TABLE gideon::datatable::RecipeTable::instance()
