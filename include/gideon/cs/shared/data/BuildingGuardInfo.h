#pragma once

#include "NpcInfo.h"
#include "Time.h"

namespace gideon {

typedef DataCode BuildingGuardCode;

const BuildingGuardCode invalidBuildingGuardCode = 0;

inline bool isValidBuildingGuardCode(BuildingGuardCode bc)
{
    if (! isBuildingGuardType(getCodeType(bc))) {
        return false;
    }
    return true;
}

/***
 * @struct BuildingGuardInfo
 ***/
struct BuildingGuardInfo
{
    NpcCode npcCode_;
    ObjectId objectId_; // db에서 쓰이는 아이디
    ObjectPosition position_;
    sec_t expireTime_;

    BuildingGuardInfo(NpcCode npcCode = invalidNpcCode, 
        ObjectId objectId = invalidObjectId, sec_t expireTime = 0,
        const ObjectPosition& position = ObjectPosition()) :
        npcCode_(npcCode),
        objectId_(objectId),
        expireTime_(expireTime),
        position_(position)
    {
    }

    void reset() {
        npcCode_ = invalidNpcCode;
        objectId_ = invalidObjectId;
        expireTime_ = 0;
        position_.reset();
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & npcCode_ & objectId_ & expireTime_ & position_;
    }
 
};

typedef sne::srpc::RVector<BuildingGuardInfo> BuildingGuardInfos;

} // namespace gideon {
