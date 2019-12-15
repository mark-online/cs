#pragma once

#include "Code.h"
#include <sne/srpc/RpcContainers.h>

namespace gideon {

typedef DataCode CharacterTitleCode;
const CharacterTitleCode invalidCharacterTitleCode = 0;

typedef sne::srpc::RSet<CharacterTitleCode> CharacterTitleCodeSet;


inline bool isValidCharacterTitleCode(CharacterTitleCode code)
{
    const CodeType ct = getCodeType(code);
    return isCharacterTitleType(ct);
}

} // namespace gideon {
