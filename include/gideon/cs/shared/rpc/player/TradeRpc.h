#pragma once

#include <gideon/cs/shared/data/TradeInfo.h>
#include <gideon/cs/shared/data/ErrorCode.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {


/**
 * @class TradeRpc
 * 거래 관련 RPC
 */
class TradeRpc
{
public:
    virtual ~TradeRpc() {}

public:
    /// 거래 요청
    DECLARE_SRPC_METHOD_1(TradeRpc, requestTrade,
        ObjectId, playerId);

    /// 거래 응답
    DECLARE_SRPC_METHOD_2(TradeRpc, respondTrade,
        ObjectId, playerId, bool, isAnswer);
    
    /// cencel Trade
    DECLARE_SRPC_METHOD_0(TradeRpc, cancelTrade);


    /// 래디 버튼 활성 비활성
    DECLARE_SRPC_METHOD_1(TradeRpc, toggleTradeReady,
        GameMoney, gameMoney);

    /// 확인 버튼 활성 비활성
    DECLARE_SRPC_METHOD_0(TradeRpc, toggleTradeConform);

    /// 거래 아이템 추가
    DECLARE_SRPC_METHOD_1(TradeRpc, addTradeItem, 
        ObjectId, itemId);
    
    /// 아이템 제거
    DECLARE_SRPC_METHOD_1(TradeRpc, removeTradeItem, 
        ObjectId, itemId);

    /// 아이템 교환
    DECLARE_SRPC_METHOD_2(TradeRpc, switchTradeItem, 
        ObjectId, invenItemId, ObjectId, tradeItemId);

    /**
     * 아이템을 산다.
     * - response: onBuyItem
     */
    DECLARE_SRPC_METHOD_2(TradeRpc, buyItem,
        ObjectId, npcId, BaseItemInfo, itemInfo);


    /**
     * 아이템을 판다.
     * - response: onSellItem
     * - event: evInventoryItemRemoved,
     */
    DECLARE_SRPC_METHOD_3(TradeRpc, sellItem,
        ObjectId, npcId, ObjectId, itemId, uint8_t, itemCount);
    
    /**
     * 다시 살수 있는 아이템 목록 요청.
     * - response: onBuyBackItems
     * - event: evInventoryItemAdded
     */
    DECLARE_SRPC_METHOD_1(TradeRpc, queryBuyBackItemInfos,
        ObjectId, npcId);

    /**
     * 아이템을 다시 산다.
     * - response: onBuyBackItem
     * - event: evInventoryItemAdded or evInventoryItemCountUpdated
     */
    DECLARE_SRPC_METHOD_2(TradeRpc, buyBackItem,
        ObjectId, npcId, uint32_t, index);

public:
    DECLARE_SRPC_METHOD_2(TradeRpc, onRequestTrade,
        ErrorCode, erroCode, ObjectId, playerId);

    DECLARE_SRPC_METHOD_3(TradeRpc, onRespondTrade,
        ErrorCode, erroCode, ObjectId, playerId, bool, isAnswer);

    DECLARE_SRPC_METHOD_1(TradeRpc, onCancelTrade,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_3(TradeRpc, onToggleTradeReady,
        ErrorCode, errorCode, bool, isReady, GameMoney, gameMoney);

    DECLARE_SRPC_METHOD_2(TradeRpc, onToggleTradeConform,
        ErrorCode, errorCode, bool, isConform);

    DECLARE_SRPC_METHOD_2(TradeRpc, onAddTradeItem, 
        ErrorCode, errorCode, ObjectId, itemId);

    DECLARE_SRPC_METHOD_2(TradeRpc, onRemoveTradeItem, 
        ErrorCode, errorCode, ObjectId, itemId);

    DECLARE_SRPC_METHOD_3(TradeRpc, onSwitchTradeItem, 
        ErrorCode, errorCode, ObjectId, invenItemId, ObjectId, tradeItemId);

    // 예외 코스트 정보를 직접 처리한다.
    DECLARE_SRPC_METHOD_5(TradeRpc, onBuyItem,
        ErrorCode, errorCode, ObjectId, npcId, BaseItemInfo, itemInfo,
        CostType, costType, uint64_t, currentCostValue);

    DECLARE_SRPC_METHOD_5(TradeRpc, onSellItem,
        ErrorCode, errorCode, uint32_t, buyBackIndex, BuyBackItemInfo, buyBackInfo, CostType, costType, uint64_t, currentValue);

    DECLARE_SRPC_METHOD_2(TradeRpc, onBuyBackItemInfos,
        ErrorCode, errorCode, BuyBackItemInfoMap, itemMap);

    DECLARE_SRPC_METHOD_4(TradeRpc, onBuyBackItem,
        ErrorCode, errorCode, uint32_t, index, CostType, ct, uint64_t, currentValue);

public:
    DECLARE_SRPC_METHOD_1(TradeRpc, evTradeRequested,
        ObjectId, playerId);

    DECLARE_SRPC_METHOD_2(TradeRpc, evTradeReponded,
        ObjectId, playerId, bool, isAnswer);

    DECLARE_SRPC_METHOD_1(TradeRpc, evTradeCancelled,
        ObjectId, playerId);

    DECLARE_SRPC_METHOD_2(TradeRpc, evTradeReadyToggled,
        bool, isReady, GameMoney, gameMoney);

    DECLARE_SRPC_METHOD_1(TradeRpc, evTradeConformToggled,
        bool, isConform);

    DECLARE_SRPC_METHOD_1(TradeRpc, evTradeItemAdded,
        ItemInfo, itemInfo);

    DECLARE_SRPC_METHOD_1(TradeRpc, evTradeItemRemoved,
        ObjectId, itemId);
};


}} // namespace gideon { namespace rpc {