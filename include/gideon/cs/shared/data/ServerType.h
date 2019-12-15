#pragma once

#include <gideon/cs/Common.h>

namespace gideon {

enum {
    /// 서버 이름 최대 길이
    maxServerNameLength = 30,
};


/**
 * @enum ServerType
 * 서버 유형
 */
enum ServerType
{
    stUnknown = -1,

    stDatabaseProxyServer = 0,
    stLoginServer = 1,
    stZoneServer = 2,
    stCommunityServer = 3,

    stBoundary
};


inline bool isValid(ServerType st)
{
    return (stUnknown < st) && (st < stBoundary);
}


inline bool isZoneServer(ServerType st)
{
    return stZoneServer == st;
}


inline bool isCommunityServer(ServerType st)
{
    return stCommunityServer == st;
}


inline bool isClientConnectableServer(ServerType st)
{
    return (stLoginServer == st) || (stZoneServer == st) || (stCommunityServer == st);
}

} // namespace gideon {


namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::ServerType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::ServerType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::ServerType>(value);
    return lhs;
}

}} // namespace sne { namespace core {
