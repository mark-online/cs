#pragma once

#include "EntityInfo.h"
#include "CreatureStatusInfo.h"
#include "LevelInfo.h"
#include "CreatureStates.h"

namespace gideon {


/**
 * @struct CreatureInfo
 * 월드 상에 존재하는 생물체 정보
 * - PC, NPC, Monster, Summon, ...
 */
struct CreatureInfo : EntityInfo
{
    // TODO: 길드 기본 정보
    Points currentPoints_;
    CreatureStateInfo stateInfo_;

    explicit CreatureInfo(ObjectType objectType = otInvalid,
        ObjectId objectId = invalidObjectId) :
        EntityInfo(objectType, objectId) {}

    void refillPoints(const Points& maxPoints) {
        currentPoints_ = maxPoints;
    }

    void reset() {
        EntityInfo::reset();
        currentPoints_.reset();
        stateInfo_.reset();
    }

    bool isValid() const {
        return EntityInfo::isValid() &&
            currentPoints_.isValid();
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        EntityInfo::serialize(stream);
        stream  & currentPoints_ & stateInfo_;
    }
};

} // namespace gideon {
