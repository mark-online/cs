#pragma once

#include <gideon/cs/shared/data/Code.h>
#include <gideon/cs/shared/data/ObjectInfo.h>
#include <gideon/cs/shared/data/Coordinate.h>
#include <gideon/cs/shared/data/CastInfo.h>
#include <gideon/cs/shared/data/ErrorCode.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class CastRpc
 */
class CastRpc
{
public:
    virtual ~CastRpc() {}

    // 시전시간을 알린다.
    DECLARE_SRPC_METHOD_1(CastRpc, startCasting,
        StartCastInfo, startInfo);    
    // 응답은 이벤트로 떨이짐
    DECLARE_SRPC_METHOD_0(CastRpc, cancelCasting);

public:
    DECLARE_SRPC_METHOD_2(CastRpc, onStartCasting,
        ErrorCode, errorCode, StartCastInfo, startInfo);

public:
    // = 모두 받는 이벤트들
    // 캐스팅이 시작됐다 
    DECLARE_SRPC_METHOD_1(CastRpc, evCasted,
        StartCastResultInfo, startInfo);

    // 캐스팅이 취소됐다 
    DECLARE_SRPC_METHOD_1(CastRpc, evCastCanceled,
        CancelCastResultInfo, cancelInfo);

    // 캐스팅이 완료됐다 
    DECLARE_SRPC_METHOD_1(CastRpc, evCastCompleted,
        CompleteCastResultInfo, completeInfo);

    // 캐스팅이 완료 실패 됐다 
    DECLARE_SRPC_METHOD_1(CastRpc, evCastCompleteFailed,
        FailCompletedCastResultInfo, failInfo);

};

}} // namespace gideon { namespace rpc {