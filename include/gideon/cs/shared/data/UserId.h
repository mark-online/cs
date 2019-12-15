#pragma once

#include <sne/core/utility/CppUtils.h>
#include <sne/srpc/RpcTypes.h>

namespace gideon {

enum UserProperties
{
    minUserIdLength = 4,
    maxUserIdLength = 10,

    minUserPasswordLength = 6,
    maxUserPasswordLength = 10,

    minNicknameLength = 2,
    maxNicknameLength = 10,

    maxUserEmailLength = 320
};


/// RPC type for user-id (UNICODE supported)
typedef sne::srpc::RpcStringType<std::wstring, maxUserIdLength> UserId;

/// RPC type for user-password
typedef sne::srpc::RpcStringType<std::string, maxUserPasswordLength> UserPassword;

/// RPC type for user-nickname (UNICODE supported)
class Nickname : public sne::srpc::RpcStringType<std::wstring, maxNicknameLength>
{
public:
    Nickname() {}
    Nickname(const wchar_t* nickname) :
        sne::srpc::RpcStringType<std::wstring, maxNicknameLength>(nickname) {}
    Nickname(const std::wstring& nickname) :
        sne::srpc::RpcStringType<std::wstring, maxNicknameLength>(nickname) {}
};


// http://www.secureprogramming.com/?action=view&feature=recipes&recipeid=3
inline bool isValidEmail(const std::string& address)
{
    int count = 0;
    const char *c, *domain;
    static char *rfc822_specials = "()<>@,;:\\\"[]";

    /* first we validate the name portion (name@domain) */
    for (c = address.c_str();  *c != '\0';  ++c) {
        if (*c == '\"' && (c == address || *(c - 1) == '.' || *(c - 1) == '\"')) {
            while (*++c) {
                if (*c == '\"') break;
                if (*c == '\\' && (*++c == ' ')) continue;
                if (*c < ' ' || *c >= 127) return 0;
            }
            if (!*c++) return 0;
            if (*c == '@') break;
            if (*c != '.') return 0;
            continue;
        }
        if (*c == '@') break;
        if (*c <= ' ' || *c >= 127) return 0;
        if (strchr(rfc822_specials, *c)) return 0;
    }
    if (c == address || *(c - 1) == '.') return 0;

    /* next we validate the domain portion (name@domain) */
    if (!*(domain = ++c)) return 0;
    do {
        if (*c == '.') {
            if (c == domain || *(c - 1) == '.') return 0;
            count++;
        }
        if (*c <= ' ' || *c >= 127) return 0;
        if (strchr(rfc822_specials, *c)) return 0;
    } while (*++c);

    return (count >= 1);
}

} // namespace gideon {


inline bool operator==(const gideon::Nickname& left, const gideon::Nickname& right)
{
    return (left.size() == right.size()) && (_wcsicmp(left.c_str(), right.c_str()) == 0);
}


inline bool operator!=(const gideon::Nickname& left, const gideon::Nickname& right)
{
    return _wcsicmp(left.c_str(), right.c_str()) != 0;
}


template <>
struct std::equal_to<gideon::Nickname> :
    public sne::core::iequal_to<gideon::Nickname>
{
};


namespace std {

    template <>
    struct hash<gideon::Nickname>
    {
        size_t operator()(gideon::Nickname const& v) const {
            std::hash<gideon::Nickname::NativeType> h;
            return h(v.c_str());
        }
    };

} // namespace std {
