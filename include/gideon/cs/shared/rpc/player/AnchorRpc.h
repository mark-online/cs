#pragma once
#include <gideon/cs/shared/data/AnchorInfo.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class AnchorRpc
 * 설치물 관련 RPC
 */
class AnchorRpc
{
public:
    virtual ~AnchorRpc() {}
    
    DECLARE_SRPC_METHOD_2(AnchorRpc, createAnchor,
        ObjectId, itemId, ObjectPosition, position);

    //DECLARE_SRPC_METHOD_1(AnchorRpc, buildAnchor,
    //    GameObjectInfo, anchorInfo);

    //DECLARE_SRPC_METHOD_3(AnchorRpc, putfuelItem,
    //    GameObjectInfo, anchorInfo, ObjectId, itemId, SlotId, ancorInvenId);

    //DECLARE_SRPC_METHOD_3(AnchorRpc, popfuelItem,
    //    GameObjectInfo, anchorInfo, ObjectId, itemId, SlotId, invenId);

    //DECLARE_SRPC_METHOD_1(AnchorRpc, queryInsideAnchorInfo,
    //    GameObjectInfo, anchorInfo);

    //DECLARE_SRPC_METHOD_3(AnchorRpc, excuteAnchorEffectByPosition,
    //    GameObjectInfo, anchorInfo, uint8_t, index, Position, position);

    //DECLARE_SRPC_METHOD_3(AnchorRpc, excuteAnchorEffectByTarget,
    //    GameObjectInfo, anchorInfo, uint8_t, index, GameObjectInfo, targetInfo);

public:
    DECLARE_SRPC_METHOD_1(AnchorRpc, onCreateAnchor,
        ErrorCode, errorCode);

//    DECLARE_SRPC_METHOD_2(AnchorRpc, onBuildAnchor,
//        ErrorCode, errorCode, GameObjectInfo, anchorInfo);
//
//    DECLARE_SRPC_METHOD_3(AnchorRpc, onPutfuelItem,
//        ErrorCode, errorCode, GameObjectInfo, anchorInfo, ItemInfo, itemInfo);
//
//    DECLARE_SRPC_METHOD_3(AnchorRpc, onPopfuelItem,
//        ErrorCode, errorCode, GameObjectInfo, anchorInfo, ObjectId, itemId);
//
//    DECLARE_SRPC_METHOD_3(AnchorRpc,onQueryInsideAnchorInfo,
//        ErrorCode, errorCode, GameObjectInfo, anchorInfo, ItemMap, itemMap);
//
//    DECLARE_SRPC_METHOD_4(AnchorRpc, onExcuteAnchorEffectByPosition,
//        ErrorCode, errorCode, GameObjectInfo, anchorInfo, uint8_t, index, Position, position);
//
//    DECLARE_SRPC_METHOD_4(AnchorRpc, onExcuteAnchorEffectByTarget,
//        ErrorCode, errorCode, GameObjectInfo, anchorInfo, uint8_t, index, GameObjectInfo, targetInfo);
//
//public:
//    DECLARE_SRPC_METHOD_3(AnchorRpc, evAnchorStartBuilt,
//        GameObjectInfo, anchorInfo, ObjectId, ownerId, sec_t, startBuildTime);
//
//    DECLARE_SRPC_METHOD_1(AnchorRpc, evAnchorBroken,
//        GameObjectInfo, anchorInfo);
//
//    DECLARE_SRPC_METHOD_1(AnchorRpc, evAnchorReconnaissanced,
//        Positions, positions);
//
//    DECLARE_SRPC_METHOD_3(AnchorRpc, evAnchorPositionFired,
//        GameObjectInfo, anchorInfo, uint8_t, index, Position, position);
//    
//    DECLARE_SRPC_METHOD_3(AnchorRpc, evAnchorTargetFired,
//        GameObjectInfo, anchorInfo, uint8_t, index, GameObjectInfo, targetInfo);
};


}} // namespace gideon { namespace rpc {