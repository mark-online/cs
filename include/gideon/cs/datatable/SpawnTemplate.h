#pragma once

#include <gideon/cs/shared/data/Code.h>
#include <gideon/cs/shared/data/Coordinate.h>
#include <gideon/cs/shared/data/RegionInfo.h>
#include <gideon/cs/shared/data/EntityPathInfo.h>
#include <esut/Random.h>

namespace gideon {

/**
 * @enum SpawnType
 */
enum SpawnType
{
    sptUnknown = -1,

    sptNormal = 0,
    sptSummon = 1, //< 소환에 의한 스폰
    sptTransform = 2, //< 변이에 의한 스폰
    sptSummonByCheat = 3, //< 치트에 의한 스폰

    sptBoundary
};


inline bool isValid(SpawnType value)
{
    return (sptUnknown < value) && (value < sptBoundary);
}


/// 팩션을 계승 받아야 하는가?
inline bool shouldInheritFaction(SpawnType value)
{
    return (value == sptSummon);
}


/**
 * @struct SpawnTemplate
 */
struct SpawnTemplate
{
    SpawnType spawnType_;
    msec_t minSpawnDelay_;
    msec_t maxSpawnDelay_;
    msec_t minSpawnInterval_;
    msec_t maxSpawnInterval_;
    msec_t minDespawnInterval_;
    msec_t maxDespawnInterval_;

    SpawnTemplate() :
        spawnType_(sptNormal),
        minSpawnDelay_(0),
        maxSpawnDelay_(0),
        minSpawnInterval_(0),
        maxSpawnInterval_(0),
        minDespawnInterval_(0),
        maxDespawnInterval_(0) {}

    msec_t getSpawnDelay() const {
        return esut::random(int(minSpawnDelay_), int(maxSpawnDelay_));
    }

    msec_t getSpawnInterval() const {
        return esut::random(int(minSpawnInterval_), int(maxSpawnInterval_));
    }

    msec_t getDespawnDelay() const {
        assert(shouldDespawn());
        return esut::random(int(minDespawnInterval_), int(maxDespawnInterval_));
    }

    bool shouldDespawn() const {
        return (minDespawnInterval_ > 0) && (maxDespawnInterval_ > 0);
    }

    bool isSpawnNoneTime() const {
        return minSpawnDelay_ == 0 && maxSpawnDelay_ == 0 && minSpawnInterval_ == 0 &&
            maxSpawnInterval_ == 0 && minDespawnInterval_ == 0 && maxDespawnInterval_ == 0;
    }
};


/**
 * @struct PositionSpawnTemplate
 * 특정 위치(x,y,z)에서 스폰
 */
struct PositionSpawnTemplate : SpawnTemplate
{
    DataCode entityCode_;
    ObjectPosition position_;
    RegionCode regionCode_; ///< Public quest 전용
    EntityPathCode entityPathCode_;

    PositionSpawnTemplate() :
        entityCode_(invalidDataCode),
        regionCode_(invalidRegionCode),
        entityPathCode_(invalidEntityPathCode) {}
};


/**
 * @struct RegionSpawnTemplate
 * 특정 영역에서 스폰
 */
struct RegionSpawnTemplate : SpawnTemplate
{
    DataCode entityCode_;
    RegionCode regionCode_;
    uint16_t pool_;

    RegionSpawnTemplate() :
        entityCode_(invalidDataCode),
        regionCode_(invalidRegionCode),
        pool_(0) {}
};

} // namespace gideon {
