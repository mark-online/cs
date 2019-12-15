#pragma once

#include <gideon/cs/Common.h>
#include <sne/srpc/RpcTypes.h>

namespace gideon {

/**
 * @enum ChatProperties
 */
enum ChatProperties
{
    maxChatMessageLength = 100 ///< maximum length of chat message
};

/**
 * @enum ChatType
 */
enum ChatType
{
	ctUnknown,
    ctNotice, ///< 공지 사항
	ctWorld, ///< 전체 월드(존서버)
    ctWorldMap, ///< 현재 스폰된 월드맵
	ctParty,
	ctGuild,
};


/// RPC type for chat message (UNICODE supported)
typedef sne::srpc::RpcStringType<std::wstring, maxChatMessageLength> ChatMessage;

} // namespace gideon {

namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::ChatType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::ChatType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::ChatType>(value);
    return lhs;
}

}} // namespace sne { namespace core {