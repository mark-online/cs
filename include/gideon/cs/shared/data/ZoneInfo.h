#pragma once

#include "WorldInfo.h"
#include <sne/srpc/RpcContainers.h>

namespace gideon {

typedef uint32_t ShardId;
const ShardId invalidShardId = 0;

inline bool isValidShardId(ShardId id)
{
	return invalidShardId != id;
}


typedef uint16_t ZoneId;
const ZoneId invalidZoneId = 0;


inline bool isValidZoneId(ZoneId id)
{
    return id > invalidZoneId;
}


inline uint64_t getMinZoneObjectId(ZoneId zoneId) 
{
    return uint64_t(zoneId) << (64 - 8);
}


inline uint64_t getMaxZoneObjectId(ZoneId zoneId) 
{
    return (uint64_t(zoneId + 1) << (64 - 8)) -1;
}

/**
 * @struct ZoneInfo
 * 존 기본 정보
 */
struct ZoneInfo
{
    ZoneId zoneId_;
    std::string name_;
    MapInfo globalMapInfo_;
    ShardId shardId_;
    bool isFirstZone_;

    ZoneInfo() {
        reset();
    }

    void reset() {
        zoneId_ = invalidZoneId;
        name_.clear();
        globalMapInfo_.reset();
        shardId_ = invalidShardId;
        isFirstZone_ = false;
    }

    bool isValid() const {
        return isValidZoneId(zoneId_) && globalMapInfo_.isValid() && isValidShardId(shardId_);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & zoneId_ & name_ & globalMapInfo_ & shardId_ & isFirstZone_;
    }
};


typedef sne::srpc::RVector<ZoneInfo> ZoneInfos;

} // namespace gideon {
