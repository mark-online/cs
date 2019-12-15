#pragma once

#include "Code.h"

namespace gideon {

typedef DataCode FunctionCode;

const FunctionCode invalidFunctionCode = 0;

/**
 * @enum FunctionItemScriptType
 * 기능성 타입
 */
enum FunctionItemScriptType
{
    fistUnknown = 0,
    fistExtendFreeInventory = 1,
    fistExtendCashInventory = 2,
    fistBoundery,
};


inline bool isValid(FunctionItemScriptType type)
{
    return fistUnknown< type && type < fistBoundery;
}
  
template <typename T>
inline FunctionItemScriptType toFunctionItemScriptType(T value)
{
    return static_cast<FunctionItemScriptType>(static_cast<uint8_t>(value));
}

} // namespace gideon {
