#pragma once

#include "ZoneInfo.h"
#include <sne/core/utility/CppUtils.h>
#include <sne/srpc/RpcTypes.h>

namespace gideon {

/***
 * @enum ZoneServerType
 ***/
enum ZoneServerType
{
	zstUnknown = 0,
	zstNormal = 1,
	zstArena = 2,
};

inline bool isValid(ZoneServerType type)
{
	return zstNormal == type || zstArena == type;
}

enum ServerProperties
{
	maxShardNameLength = 20, ///< maximum length of server-id
};


/// RPC type for user-id (UNICODE supported)
typedef sne::srpc::RpcStringType<std::wstring, maxShardNameLength> ShardName;

/***
 * @struct ZoneServerInfo
 ***/
struct ZoneServerInfo
{
	MapCode mapCode_;
	std::string zoneServerIp_;
	uint16_t zoneServerPort_;
    bool isFirstZone_; ///< 최초 스폰 존?
    bool isEnabled_; ///< 존서버가 활성화되었는가?

	ZoneServerInfo(const MapCode mapCode = invalidMapCode,
		const std::string& zoneServerIp = "", uint16_t zoneServerPort = 0,
        bool isFirstZone = false) :
		mapCode_(mapCode),
		zoneServerIp_(zoneServerIp),
		zoneServerPort_(zoneServerPort),
        isFirstZone_(isFirstZone),
        isEnabled_(true) {}

    void reset() {
        mapCode_ = invalidMapCode;
        zoneServerIp_.clear();
        zoneServerPort_ = 0;
        isFirstZone_ = false;
        isEnabled_ = true;
    }

    bool isValid() const {
        return isValidMapCode(mapCode_) && (! zoneServerIp_.empty()) && (zoneServerPort_ > 0);

    }

	template <typename Stream>
	void serialize(Stream& stream) {
		stream & mapCode_ & zoneServerIp_ & zoneServerPort_ & isFirstZone_ & isEnabled_;
	}
};

typedef sne::srpc::RHashMap<ZoneId, ZoneServerInfo> ZoneServerInfoMap;


typedef sne::srpc::RHashMap<ZoneId, MapCode> ZoneMapCodeMap;


/**
 * @enum ShardStatus
 */
enum ShardStatus
{
    ssOffline = 0,
    ssOnline
};


/**
 * @struct ShardInfo
 */
struct ShardInfo
{
    ShardId shardId_;
	ShardName name_;
    uint16_t currentUserCount_;
    uint16_t maxUserCount_;
    ShardStatus status_;

    ShardInfo() :
        shardId_(invalidShardId),
        currentUserCount_(0),
        maxUserCount_(0),
        status_(ssOffline) {}

    void increaseUserCount(uint16_t currentCount, uint16_t maxCount) {
        currentUserCount_ += currentCount;
        maxUserCount_ += maxCount;
    }

    void decreaseUserCount(uint16_t currentCount, uint16_t maxCount) {
        if (currentUserCount_ >= currentCount) {
            currentUserCount_ -= currentCount;
        }
        else {
            currentUserCount_ = 0;
        }

        if (maxUserCount_ >= maxCount) {
            maxUserCount_ -= maxCount;
        }
        else {
            maxUserCount_ = 0;
        }
    }

    bool isValid() const {
        return isValidShardId(shardId_);
    }

    bool isOnline() const {
        return status_ == ssOnline;
    }

	template <typename Stream>
	void serialize(Stream& stream) {
		stream & shardId_ & name_ & currentUserCount_ & maxUserCount_ & status_;
	}
};


typedef sne::srpc::RVector<ShardInfo> ShardInfoList;


inline const ShardInfo* getShardInfo(const ShardInfoList& shards, ShardId shardId)
{
    for (const ShardInfo& shard : shards) {
        if (shard.shardId_ == shardId) {
            return &shard;
        }
    }
    return nullptr;
}


inline ShardInfo* getShardInfo(ShardInfoList& shards, ShardId shardId)
{
    for (ShardInfo& shard : shards) {
        if (shard.shardId_ == shardId) {
            return &shard;
        }
    }
    return nullptr;
}


typedef sne::srpc::RHashMap<ShardId, uint8_t> CharacterCountPerShardMap;


/***
 * @struct CommunityServerInfo
 ***/
struct CommunityServerInfo
{
	std::string communityServerIp_;
	uint16_t communityServerPort_;

	CommunityServerInfo(const std::string& communityServerIp = "", uint16_t communityServerPort = 0) :
		communityServerIp_(communityServerIp),
		communityServerPort_(communityServerPort) {}

    void reset() {
        communityServerIp_.clear();
        communityServerPort_ = 0;
    }

    bool isValid() const {
        return (! communityServerIp_.empty()) && (communityServerPort_ > 0);

    }

	template <typename Stream>
	void serialize(Stream& stream) {
		stream & communityServerIp_ & communityServerPort_;
	}
};

} // namespace gideon {


namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::ShardStatus rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::ShardStatus& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::ShardStatus>(value);
    return lhs;
}


}} // namespace sne { namespace core {
