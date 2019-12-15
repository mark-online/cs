#pragma once

#include <gideon/cs/shared/data/CharacterTitleInfo.h>
#include <gideon/cs/shared/data/ErrorCode.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class AchievementRpc
 * 업적 관련 RPC
 */
class CharacterTitleRpc
{
public:
    virtual ~CharacterTitleRpc() {}

public:
    // = 초기화시에 정보를 요청한
    // response: onQueryCharacterTitles
    DECLARE_SRPC_METHOD_0(CharacterTitleRpc, queryCharacterTitles);

    // response: onSelectCharacterTitle
    // event: evCharacterTitleSelected(자신 제외
    DECLARE_SRPC_METHOD_1(CharacterTitleRpc, selectCharacterTitle,
        CharacterTitleCode, selectTitleCode);

public:
    DECLARE_SRPC_METHOD_2(CharacterTitleRpc, onQueryCharacterTitles,
        ErrorCode, errorCode, CharacterTitleCodeSet, titleCodeSet);

    DECLARE_SRPC_METHOD_2(CharacterTitleRpc, onSelectCharacterTitle,
        ErrorCode, errorCode, CharacterTitleCode, selectTitleCode);


public:
    DECLARE_SRPC_METHOD_1(CharacterTitleRpc, evCharacterTitleAdded,
        CharacterTitleCode, titleCode);

    DECLARE_SRPC_METHOD_2(CharacterTitleRpc, evCharacterTitleSelected,
        ObjectId, playerId, CharacterTitleCode, titleCode);
};

}} // namespace gideon { namespace rpc {