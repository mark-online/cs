#pragma once
#include <gideon/cs/shared/data/AuctionInfo.h>
#include <gideon/cs/shared/data/ErrorCode.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class AuctionRpc
 * 경매 관련 RPC
 */
class AuctionRpc
{
public:
    virtual ~AuctionRpc() {}

    DECLARE_SRPC_METHOD_2(AuctionRpc, createAuction,
        ObjectId, npcId, CreateAuctionInfo, auctionInfo);
    
    DECLARE_SRPC_METHOD_2(AuctionRpc, searchEquipmentByEquipType,
        ObjectId, npcId, EquipType, equipType);

    DECLARE_SRPC_METHOD_2(AuctionRpc, searchEquipmentByEquipPart,
        ObjectId, npcId, EquipPart, equipPart);

    DECLARE_SRPC_METHOD_1(AuctionRpc, searchWeapon,
        ObjectId, npcId);

    DECLARE_SRPC_METHOD_1(AuctionRpc, searchArmor,
        ObjectId, npcId);

    DECLARE_SRPC_METHOD_2(AuctionRpc, searchItemsByCodeType,
        ObjectId, npcId, CodeType, codeType);

    DECLARE_SRPC_METHOD_1(AuctionRpc, querySellingItems,
        ObjectId, npcId);

    DECLARE_SRPC_METHOD_1(AuctionRpc, queryBiddingItems,
        ObjectId, npcId);

    DECLARE_SRPC_METHOD_3(AuctionRpc, bid,
        ObjectId, npcId, AuctionId, auctionId, GameMoney, gameMoney);

    DECLARE_SRPC_METHOD_2(AuctionRpc, buyOut,
        ObjectId, npcId, AuctionId, auctionId);

    DECLARE_SRPC_METHOD_2(AuctionRpc, cancelAuction,
        ObjectId, npcId, AuctionId, auctionId);

public:
    DECLARE_SRPC_METHOD_2(AuctionRpc, onCreateAuction,
        ErrorCode, errorCode, GameMoney, currentMoney);

    DECLARE_SRPC_METHOD_2(AuctionRpc, onSearchEquipmentByEquipType,
        ErrorCode, errorCode, AuctionInfos, infos);

    DECLARE_SRPC_METHOD_2(AuctionRpc, onSearchEquipmentByEquipPart,
        ErrorCode, errorCode, AuctionInfos, infos);

    DECLARE_SRPC_METHOD_2(AuctionRpc, onSearchWeapon,
        ErrorCode, errorCode, AuctionInfos, infos);

    DECLARE_SRPC_METHOD_2(AuctionRpc, onSearchArmor,
        ErrorCode, errorCode, AuctionInfos, infos);

    DECLARE_SRPC_METHOD_2(AuctionRpc, onSearchItemsByCodeType,
        ErrorCode, errorCode, AuctionInfos, infos);

    DECLARE_SRPC_METHOD_2(AuctionRpc, onSellingItems,
        ErrorCode, errorCode, AuctionInfos, infos);

    DECLARE_SRPC_METHOD_2(AuctionRpc, onBiddingItems,
        ErrorCode, errorCode, AuctionInfos, infos);

    DECLARE_SRPC_METHOD_4(AuctionRpc, onBid,
        ErrorCode, errorCode, AuctionId, auctionId, GameMoney, bidMoney, GameMoney, currentMoney);

    DECLARE_SRPC_METHOD_3(AuctionRpc, onBuyOut,
        ErrorCode, errorCode, AuctionId, auctionId, GameMoney, currentMoney);

    DECLARE_SRPC_METHOD_2(AuctionRpc, onCancelAuction,
        ErrorCode, errorCode, AuctionId, auctionId);
};


}} // namespace gideon { namespace rpc {