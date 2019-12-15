#pragma once

#include <gideon/cs/Common.h>
#include <sne/core/stream/Streamable.h>

namespace gideon {

/**
 * @enum ExpelReason
 * 강제 퇴장 사유
 */
enum ExpelReason
{
    erUnknown = -1,

    /// 중복 로그인으로 인한 강제 퇴장
    erDuplicatedLogin,

    /// 로그아웃 요청에 따른 강제 접속 해제
    erLogout,
};

} // namespace gideon {


namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::ExpelReason rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::ExpelReason& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::ExpelReason>(value);
    return lhs;
}

}} // namespace sne { namespace core {
