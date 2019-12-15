#pragma once

#include "Code.h"

namespace gideon {

/**
 * NPC 잡담 코드
 * - Category(1B) | Subcategory(2B) | Index(1B)
 */
typedef DataCode NpcTalkingCode;
const NpcTalkingCode invalidNpcTalkingCode = invalidDataCode;


inline bool isValidNpcTalkingCode(NpcTalkingCode code)
{
    return getCodeType(code) == ctNpcTalking;
}

} // namespace gideon {
