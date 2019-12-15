#pragma once

#include "Code.h"
#include <cassert>

namespace gideon {
/**
 * RecipeCode 코드
 * - Category(1B) | empty(1B) | index(2B)
 */
typedef DataCode RecipeCode;
const RecipeCode invalidRecipeCode = invalidDataCode;


/// RecipeCode를 만든다
inline RecipeCode makeRecipeCode(uint16_t index)
{
    return getMinGideonCode(ctRecipe) + index;
}


inline uint16_t getRecipeCodeIndex(RecipeCode sc)
{
    assert(getCodeType(sc) == ctRecipe);
    return static_cast<uint16_t>(sc & 0x0000FFFF);
}


/// RecipeCode를 파싱한다
inline bool parseRecipeCode(uint16_t& index, RecipeCode sc)
{
    const CodeType codeType = getCodeType(sc);
    if (codeType != ctRecipe) {
        return false;
    }

    index = getRecipeCodeIndex(sc);
    return true;
}


/// 유효한 Recipe 코드인가?
inline bool isValidRecipeCode(RecipeCode sc)
{
    uint16_t index = 0;
    if (! parseRecipeCode(index, sc)) {
        return false;
    }
    return index > 0;
}

/***
 * @enum RecipeGrade
 ***/
enum RecipeGrade
{
	rgNone = 0,
	rgShabby,
	rgNormal,
	rgRare,
	rgUnique,
	rgEpic,
	rgLegend,
	rgCount,
};


inline bool isValid(RecipeGrade grade)
{
	return rgNone <= grade && grade < rgCount;
}
} // namespace gideon {
