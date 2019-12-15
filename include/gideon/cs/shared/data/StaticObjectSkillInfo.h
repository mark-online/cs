#pragma once

#include "SkillInfo.h"

namespace gideon {

typedef DataCode StaticObjectSkillCode;
const StaticObjectSkillCode invalidStaticObjectSkillCode = invalidSkillCode;

inline bool isValidStaticObjectSkillCode(StaticObjectSkillCode code)
{
    return invalidStaticObjectSkillCode != code;
}

} // namespace gideon {
