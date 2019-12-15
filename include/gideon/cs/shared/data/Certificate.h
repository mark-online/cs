#pragma once

#include "AccountId.h"
#include "ServerInfo.h"
#include "RegionInfo.h"
#include "ErrorCode.h"
#include "ServerType.h"
#include "Coordinate.h"
#include "ObjectInfo.h"
#include <sne/srpc/RpcContainers.h>

namespace gideon {

typedef uint32_t AuthId;
const AuthId invalidAuthId = 0;

/**
 * @struct Certificate
 * 인증서
 */
struct Certificate
{
    ServerType serverType_; ///< 인증할 서버
    AccountId accountId_;
    AuthId authId_; ///< 세션 검증에 사용

    static Certificate issue(ServerType serverType, AccountId accountId, AuthId authId) {
        assert(isClientConnectableServer(serverType));
        return Certificate(serverType, accountId, authId);
    }

    explicit Certificate(ServerType serverType = stUnknown,
        AccountId accountId = invalidAccountId,
        AuthId authId = invalidAuthId) :
        serverType_(serverType),
        accountId_(accountId),
        authId_(authId) {}

    void reset() {
        serverType_ = stUnknown;
        accountId_ = invalidAccountId;
        authId_ = invalidAuthId;
    }

    ErrorCode check(const Certificate& certificate) const {
        if (serverType_ != certificate.serverType_) {
            return ecLoginInvalidCertificate;
        }
        if (accountId_ != certificate.accountId_) {
            return ecLoginInvalidCertificate;
        }
        if (authId_ != certificate.authId_) {
            return ecLoginInvalidCertificate;
        }
        return ecOk;
    }

    bool isValid() const {
        return isClientConnectableServer(serverType_) && isValidAccountId(accountId_);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        // TODO: 인증서 암호화
        stream & serverType_ & accountId_ & authId_;
    }
};


typedef sne::srpc::RMap<ServerType, Certificate> CertificateMap;


inline const Certificate* getCertificate(const CertificateMap& map, ServerType serverType)
{
    const CertificateMap::const_iterator pos = map.find(serverType);
    if (pos != map.end()) {
        return &(*pos).second;
    }
    return nullptr;
}


/**
 * @struct MigrationTicket
 * 존 서버 이동 통행권
 */
struct MigrationTicket
{
    ZoneServerInfo zoneServerInfo_; /// 로그인할 존서버 정보
    RegionCode spawnRegionCode_; ///< 스폰될 지역 코드
	ObjectId arenaId_; /// < 투기장 아이디'
    MapCode globalMapCode_; /// 현재 글로발 맵코드 존->투기장
    Position position_; /// 리전 코드를 안사용하고 특정위치로 갈때

    MigrationTicket() :
        arenaId_(invalidObjectId),
        spawnRegionCode_(invalidRegionCode),
        globalMapCode_(invalidMapCode){}

    void reset() {
        zoneServerInfo_.reset();
        arenaId_ = invalidObjectId;
        spawnRegionCode_ = invalidRegionCode;
        globalMapCode_ = invalidMapCode;
        position_.reset();
    }

    bool isValid() const {
		if (isValidObjectId(arenaId_)) {            
			return zoneServerInfo_.isValid() && isValidMapCode(globalMapCode_) &&
                isWorldMap(getMapType(globalMapCode_));
		}        

        return zoneServerInfo_.isValid();
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        const bool isInput = stream.isInput();
        stream & zoneServerInfo_ & spawnRegionCode_ & arenaId_;
        if (isValidObjectId(arenaId_)) {
            stream & globalMapCode_;
        }
        else {
            if (isInput) {
                globalMapCode_ = invalidMapCode;
            }
        }
        if (! isValidRegionCode(spawnRegionCode_)) {
            stream & position_;
        }
        else {
            if (isInput) {
                position_.reset();
            }
        }
    }
};

} // namespace gideon {
