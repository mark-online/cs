#pragma once

#include "esut/Random.h"

namespace gideon {

/// 천분율(http://en.wikipedia.org/wiki/Per_mil)
typedef int permil_t;

/// @param perMil 1000분율(0~1000)
template <typename T>
inline bool isSuccessRate(T perMil)
{
    return esut::random(0, 1000) <= permil_t(perMil);
}

inline permil_t clampPermil(permil_t value, permil_t min = 0, permil_t max = 1000)
{
    return (std::min)((std::max)(value, min), max);
}


inline float toPercentageFromPermil(permil_t permil)
{
    return permil / 10.0f;
}


/// 만분율(http://en.wikipedia.org/wiki/Basis_point)
typedef int bips_t;

inline bips_t clampBips(bips_t value, bips_t min = 0, bips_t max = 10000)
{
    if (value < min) {
        return min;
    }
    if (value > max) {
        return max;
    }
    return value;
}


inline float toPercentageFromBips(bips_t bips)
{
    return bips / 100.0f;
}

} // namespace gideon {