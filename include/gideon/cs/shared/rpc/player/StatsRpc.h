#pragma once

#include <gideon/cs/shared/data/SkillInfo.h>
#include <gideon/cs/shared/data/StatusInfo.h>
#include <gideon/cs/shared/data/EffectStatusInfo.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {


/**
 * @class StatsRpc
 * 성장 관련 RPC
 */
class StatsRpc
{
public:
    virtual ~StatsRpc() {}

public:
    /// 포인트를 변경 시킨다(옵저버 받는다, 이걸로 자기자신도 처리, 파티원도 받느다.).
    DECLARE_SRPC_METHOD_3(StatsRpc, evPointChanged,
        GameObjectInfo, entityInfo, PointType, pointType, 
        uint32_t, currentPoint);

    /// 포인트를 변경 시킨다((옵저버 받는다, 이걸로 자기자신도 처리, 파티원도 받느다.).
    DECLARE_SRPC_METHOD_4(StatsRpc, evMaxPointChanged,
        GameObjectInfo, entityInfo, PointType, pointType, 
        uint32_t, currentPoint, uint32_t, maxPoint);

    /// 확율을 변경(자기 자신만 받는다)
    //DECLARE_SRPC_METHOD_2(StatsRpc, evAttributeRateChanged,
    //    AttributeRateIndex, rateType, AttributeRate, rate);

    // 능력치 변경(자기 자신만 받는다)
    DECLARE_SRPC_METHOD_2(StatsRpc, evCreatureStatusChanged,
        EffectStatusType, effectStatusType, int32_t, currentValue);
    
    // 모든 속성값 변경(자기 자신만 받는다)
    DECLARE_SRPC_METHOD_2(StatsRpc, evAllAttributeChanged,
        AttributeRates, rates, bool, isRegist);

    /// 포인트(HP/MP/CP)가 가득 찼다.(모든 사람이 받는다, 이걸로 자기자신도 처리, 파티원도 받느다.).
    DECLARE_SRPC_METHOD_1(StatsRpc, evPointsRestored,
        GameObjectInfo, entityInfo);

    /// 라이프 포인트가 변경 -- 자기 자신만 받는다.(초기화, 장착, 탈착)
    DECLARE_SRPC_METHOD_1(StatsRpc, evFullCreatureStatusInfoChanged,
        FullCreatureStatusInfo, stats); 

    /// 생명체 라이프 스테이츠 변경(나를 제외한)
    DECLARE_SRPC_METHOD_2(StatsRpc, evLifeStatusChanged,
        GameObjectInfo, entityInfo, LifeStats, stats);
    
    /// 생명체 쉴드가 생성될때(파티원도 받느다.)
    DECLARE_SRPC_METHOD_3(StatsRpc, evShieldCreated,
        GameObjectInfo, entityInfo, PointType, pointType, 
        uint32_t, ShieldPoint);

    /// 생명체 쉴드가 소멸될때(파티원도 받느다.)    
    DECLARE_SRPC_METHOD_2(StatsRpc, evShieldDestroyed,
        GameObjectInfo, entityInfo, PointType, pointType);
    
    /// 생명체 쉴드 수치가 변할때(파티원도 받느다.)
    DECLARE_SRPC_METHOD_3(StatsRpc, evShieldPointChanged,
        GameObjectInfo, entityInfo, PointType, pointType, 
        uint32_t, currentPoint);

};

}} // namespace gideon { namespace rpc {