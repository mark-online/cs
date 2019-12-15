#pragma once

#include "EffectInfo.h"
#include <sne/srpc/RpcContainers.h>

namespace gideon {
    
/**
 * @struct ItemScriptInfo
 *
 */
struct ItemScriptInfo
{
    EffectScriptType scriptType_;
    int32_t value_;

    ItemScriptInfo(EffectScriptType scriptType = estUnknown, int32_t value = 0) :
        scriptType_(scriptType),
        value_(value)
    {
    }
     
    bool isValid() const {
        return gideon::isValid(scriptType_);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & scriptType_ & value_;
    }
};

typedef sne::srpc::RVector<ItemScriptInfo> ItemScriptInfos;

} // namespace gideon {