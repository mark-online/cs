#pragma once
#include <gideon/cs/shared/data/MailInfo.h>
#include <gideon/cs/shared/data/ErrorCode.h>
#include <sne/srpc/RpcInterface.h>

namespace gideon { namespace rpc {

/**
 * @class MailRpc
 * 메일 관련 RPC
 */
class MailRpc
{
public:
    virtual ~MailRpc() {}

    DECLARE_SRPC_METHOD_1(MailRpc, sendMail,
        SendMailInfo, mailInfo);

    DECLARE_SRPC_METHOD_0(MailRpc, synchronizeMail);

    DECLARE_SRPC_METHOD_1(MailRpc, queryMailTitle,
        ObjectId, mailId);

    DECLARE_SRPC_METHOD_1(MailRpc, queryMailContent,
        ObjectId, mailId);

    DECLARE_SRPC_METHOD_1(MailRpc, aquireItemInMail,
        ObjectId, mailId);

    DECLARE_SRPC_METHOD_1(MailRpc, deleteMail,
        ObjectId, mailId);

public:
    DECLARE_SRPC_METHOD_3(MailRpc, onSendMail,
        ErrorCode, errorCode, SendMailInfo, mailInfo, GameMoney, gameMoney);

    DECLARE_SRPC_METHOD_1(MailRpc, onSynchronizeMail,
        ErrorCode, errorCode);

    DECLARE_SRPC_METHOD_2(MailRpc, onMailTitle,
        ErrorCode, errorCode, MailTitleInfo, mailTitleInfo);    

    DECLARE_SRPC_METHOD_2(MailRpc, onMailContent,
        ErrorCode, errorCode, MailContentInfo, mailContentInfo);    

    DECLARE_SRPC_METHOD_2(MailRpc, onAquireItemInMail,
        ErrorCode, errorCode, ObjectId, mailId);

    DECLARE_SRPC_METHOD_2(MailRpc, onDeleteMail,
        ErrorCode, errorCode, ObjectId, mailId);

public:
    DECLARE_SRPC_METHOD_1(MailRpc, evMailSynchronized,
        MailTitleInfos, mailTitleInfos);
    
    DECLARE_SRPC_METHOD_1(MailRpc, evMailReceived,
        ObjectId, mailId);

};


}} // namespace gideon { namespace rpc {