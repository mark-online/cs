#pragma once

#include <gideon/cs/shared/data/PartyInfo.h>
#include <gideon/cs/shared/data/CharacterInfo.h>
#include <gideon/cs/shared/data/Coordinate.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class PartyRpc
 * 파티 관련 RPC
 */
class PartyRpc : public boost::noncopyable
{
public:
    virtual ~PartyRpc() {}

public:    
    DECLARE_SRPC_METHOD_1(PartyRpc, queryPartyMemberSubInfo,
        ObjectId, memberId);

public:
    DECLARE_SRPC_METHOD_6(PartyRpc, onPartyMemberSubInfo,
        ObjectId, memberId, CharacterClass, characterClass,
        CreatureLevel, level, HitPoints, hitPoints, ManaPoints, manaPoints, Position, position);

public:
    DECLARE_SRPC_METHOD_2(PartyRpc, evPartyMemberLevelup,
        ObjectId, objectId, CreatureLevel, level);

    DECLARE_SRPC_METHOD_2(PartyRpc, evPartyMemberMoved,
        ObjectId, objectId, Position, position);
};

}} // namespace gideon { namespace rpc {