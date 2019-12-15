#pragma once

#include "Code.h"
#include "ObjectInfo.h"
#include <sne/srpc/RpcContainers.h>

namespace gideon {

typedef DataCode AccessoryCode;

const AccessoryCode invalidAccessoryCode = 0;

/***
 * @enum AccessoryPart
 *
 ***/
enum AccessoryPart
{
    apInvalid = 0,
    apFirst = 1,

    apNecklace = apFirst,
    apBracelet = 2,
    apRing = 3,
    apCount
};


inline bool isValid(AccessoryPart part)
{
    return apInvalid < part && part < apCount;
}

/// AccessoryCode를 만든다
inline AccessoryCode makeAccessoryCode(AccessoryPart ap, uint16_t index)
{
    return getMinGideonCode(ctAccessory) + (ap << 16) + index;
}

inline AccessoryPart getAccessoryPart(AccessoryCode ac)
{
    assert(getCodeType(ac) == ctAccessory);
    return static_cast<AccessoryPart>((ac & 0x00FF0000) >> 16);
}


inline uint16_t getAccessoryCodeIndex(AccessoryCode ac)
{
    assert(getCodeType(ac) == ctAccessory);
    return static_cast<uint16_t>(ac & 0x0000FFFF);
}


/// AccessoryCode를 파싱한다
inline bool parseAccessoryCode(AccessoryPart& ap, uint16_t& index, AccessoryCode ac)
{
    ap = apInvalid;
    index = 0;

    const CodeType codeType = getCodeType(ac);
    if (codeType != ctAccessory) {
        return false;
    }

    ap = getAccessoryPart(ac);
    index = getAccessoryCodeIndex(ac);
    return true;
}


/// 유효한 장비 코드인가?
inline bool isValidAccessoryCode(AccessoryCode ac)
{
    AccessoryPart ap = apInvalid;
    uint16_t index = 0;
    if (! parseAccessoryCode(ap, index, ac)) {
        return false;
    }
    return isValid(ap) && (index > 0);
}


/***
 * @enum AccessoryIndex
 *
 ***/
enum AccessoryIndex
{
    aiInvalid = -1,
    aiFirst = 0,
    aiNecklace = aiFirst,
    aiBracelet1 = 1,
    aiBracelet2 = 2,
    aiRing1 = 3,
    aiRing2 = 4,
    aiCount
};


inline bool isValid(AccessoryIndex index)
{
    return aiInvalid < index && index < aiCount;
}


inline bool isEquiipAccessoryPart(AccessoryIndex index, AccessoryPart part)
{
    if (part == apNecklace && index == aiNecklace) {
        return true;
    }
    else if (part == apBracelet && (index == aiBracelet1 || index == aiBracelet2)) {
        return true;
    }
    else if (part == apRing && (index == aiRing1 || index == aiRing2)) {
        return true;
    }
    return false;
}

template <typename T>
inline AccessoryIndex toAccessoryIndex(T index)
{
    return static_cast<AccessoryIndex>(index);
}

/**
 * @class CharacterAccessories
 * 케릭터 악세사리 장착 정보
 */
class CharacterAccessories : public sne::srpc::RArray<ObjectId, aiCount>
{
public:
    CharacterAccessories() {
        reset();
    }

    void reset() {
        fill(invalidObjectId);
    }    
};

} // namespace gideon {
