#pragma once

#include <gideon/cs/Common.h>

namespace gideon {

/// Chatting Channel Id.
typedef uint32_t ChannelId;
const ChannelId invalidChannelId = 0;

/// is valid ChannelId
inline bool isValidChannelId(ChannelId accountId)
{
    return invalidChannelId != accountId;
}

} // namespace gideon {
