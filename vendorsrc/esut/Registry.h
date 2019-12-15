/**
* Copyright (c) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#ifndef _ESUT_REGISTRY_H_
#define _ESUT_REGISTRY_H_

#include <winreg.h>
#include <string>
#include <cassert>

namespace esut
{

/**
 * @class RegKeyGuard
 *
 * registry key 가드 클래스
 */
class RegKeyGuard
{
public:
    RegKeyGuard(HKEY key) :
        key_(key) {}
    ~RegKeyGuard() {
        if (NULL != key_) {
            ::RegCloseKey(key_);
        }
    }

    HKEY get() const {
        return key_;
    }
private:
    HKEY key_;
};

/**
 * @struct Registry
 *
 * 레지스트리 관련 유틸리티
 */
struct Registry
{

    /// IE 홈페이지를 설정한다
    static void setHomepage(const std::string& url);

    /// HKCU or HKLM\Software\companyName\softwareName
    static HKEY getSoftwareKey(const std::string& companyName,
        const std::string& softwareName, bool useHKLM = false);

    /// HKCU or HKLM\Software\companyName\softwareName
    static HKEY createSoftwareKey(const std::string& companyName,
        const std::string& softwareName, bool useHKLM = false);

    static bool setString(const std::string& companyName,
        const std::string& softwareName,
        const std::string& entry, const std::string& value,
        bool useHKLM = false);

    static bool getString(std::string& value, const std::string& companyName,
        const std::string& softwareName, const std::string& entry,
        const std::string& defaultValue = "",
        bool useHKLM = false);

    static bool setDword(const std::string& companyName,
        const std::string& softwareName, const std::string& entry,
        DWORD value, bool useHKLM = false);

    static bool getDword(DWORD& value, const std::string& companyName,
        const std::string& softwareName, const std::string& entry,
        DWORD defaultValue, bool useHKLM = false);

};

} // namespace esut

#endif // _ESUT_REGISTRY_H_
