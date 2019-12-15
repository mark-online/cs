#pragma once

#include "Code.h"
#include "StatusInfo.h"
#include "EntityInfo.h"
#include "GuildInfo.h"
#include "Time.h"

namespace gideon {

typedef DataCode AnchorCode;
const AnchorCode invalidAnchorCode = 0;

inline bool isValidAnchorCode(AnchorCode code)
{
    return getCodeType(code) == ctAnchor;
}


/***
 * @struct AnchorOwnerInfo
 ***/
struct AnchorOwnerInfo
{
    ObjectId ownerId_;
    Nickname nickname_;

    explicit AnchorOwnerInfo(ObjectId ownerId = invalidObjectId,
        const Nickname& nickname = L"") :
        ownerId_(ownerId),
        nickname_(nickname) {}

    void reset() {
        ownerId_ = invalidObjectId;
        nickname_.clear();
    }

    inline bool isCommonAnchor() const {
        return ! isValidObjectId(ownerId_);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & ownerId_;
        if (isValidObjectId(ownerId_)) {
            stream & nickname_;
        }        
    }
};

/***
 * @struct BaseAnchorInfo
 ***/
struct BaseAnchorInfo : public EntityInfo
{
    AnchorCode anchorCode_;
    sec_t expireTime_;

    explicit BaseAnchorInfo(ObjectType objectType = otInvalid,
        ObjectId anchorId = invalidObjectId) :
        EntityInfo(objectType, anchorId) {
        reset();
    }

    void reset() {
        EntityInfo::reset();
        anchorCode_ = invalidAnchorCode;
        expireTime_ = 0;
    }

    bool isValid() const {
        return EntityInfo::isValid() && isValidAnchorCode(anchorCode_);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        EntityInfo::serialize(stream);
        stream & anchorCode_ & expireTime_;
    }
};


/***
 * @struct AnchorInfo
 ***/
struct AnchorInfo : public BaseAnchorInfo
{
    HitPoints points_;
    AnchorOwnerInfo ownerInfo_;

    void reset() {
        BaseAnchorInfo::reset();
        points_.reset();
        ownerInfo_.reset();
    }

    void damage(HitPoint hp) {
        points_.reduce(hp);
    }

    void repair(HitPoint hp) {
        points_.refill(hp);
    }

    bool isMinHp() const {
        return hpMin >= points_.hp_;
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        BaseAnchorInfo::serialize(stream);
        stream & points_ & ownerInfo_;
    }
};

} // namespace gideon {