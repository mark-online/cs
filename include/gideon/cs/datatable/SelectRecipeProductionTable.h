#pragma once

#include <gideon/cs/shared/data/RecipeInfo.h>
#include <gideon/cs/shared/data/BuildingInfo.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/***
 * @struct SelectRecipeProductionInfo
 ***/
struct SelectRecipeProductionInfo
{
    RecipeCode recipeCode_;
    uint8_t productionCreateCount_;

    SelectRecipeProductionInfo(RecipeCode recipeCode = invalidRecipeCode,
        uint8_t productionCreateCount = 0) :
        recipeCode_(recipeCode),
        productionCreateCount_(productionCreateCount)
    {
    }

};

typedef sne::core::Vector<SelectRecipeProductionInfo> SelectRecipeProductionInfos;


/***
 * @class SelectRecipeProductionTable
 ***/
class GIDEON_CS_API SelectRecipeProductionTable  : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(SelectRecipeProductionTable);
public:
    typedef sne::core::HashMap<uint32_t, SelectRecipeProductionInfos> SelectRecipeProductionInfosMap;

public:
    virtual ~SelectRecipeProductionTable() {}
    
    virtual const SelectRecipeProductionInfos* getSelectRecipeProductionInfos(uint32_t code) const = 0;

    virtual const SelectRecipeProductionInfosMap& getSelectRecipeProductionInfosMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define SELECT_RECIPE_PRODUCTION_TABLE gideon::datatable::SelectRecipeProductionTable::instance()
