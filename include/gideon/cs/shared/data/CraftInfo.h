#pragma once


namespace gideon {

/**
 * @enum CraftType
 * 아이템의 제작 또는 분해의 종류
 */
enum CraftType
{
    crtUnknown,
    crtCook,
    crtSundries,
    crtGem,
    crtBlackSmith,
    crtBoundery,
};

inline bool isValid(CraftType type)
{
    return crtUnknown < type && type < crtBoundery;
}

template <typename T>
CraftType toCraftType(T craftType)
{
    return static_cast<CraftType>(static_cast<uint8_t>(craftType));
}

// player의 레시피아이템을 사용하는가?
inline bool useByPlayerRecipe(CraftType craftType)
{
    return crtBlackSmith == craftType;
}

} // namespace gideon {
