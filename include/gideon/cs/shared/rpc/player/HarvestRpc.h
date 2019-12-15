#pragma once

#include <gideon/cs/shared/data/HarvestInfo.h>
#include <gideon/cs/shared/data/ItemInfo.h>
#include <gideon/cs/shared/data/QuestInfo.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {


/***
 * @class HarvestRpc
 ***/
class HarvestRpc
{
public:
    virtual ~HarvestRpc() {}

    /**
     * 체집한 아이템을 획득.
     * - response: onAcquireHarvest
     */
    DECLARE_SRPC_METHOD_1(HarvestRpc, acquireHarvest,
        DataCode, itemCode);

public:
    DECLARE_SRPC_METHOD_2(HarvestRpc, onAcquireHarvest,
        ErrorCode, errorCode, DataCode, itemCode);

public:
    DECLARE_SRPC_METHOD_3(HarvestRpc, evHarvestRewarded,
        ObjectId, haravestId, BaseItemInfos, itemInfos,
        QuestItemInfos, questItemInfos);

};



}} // namespace gideon { namespace rpc {