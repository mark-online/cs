/**
* Copyright (c) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#include "stdafx.h"
#include "esut/Registry.h"

namespace
{

inline std::string getSoftwareKeyName(const std::string& companyName,
    const std::string& softwareName)
{
    return "Software\\" + companyName + "\\" + softwareName;
}

} // namespace

namespace esut
{

void Registry::setHomepage(const std::string& url)
{
    Registry::setString("Microsoft", "Internet Explorer\\Main",
        "Start Page", url);
}


HKEY Registry::getSoftwareKey(const std::string& companyName,
    const std::string& softwareName, bool useHKLM)
{
    const std::string keyName = getSoftwareKeyName(companyName, softwareName);

    const HKEY rootKey = useHKLM ? HKEY_LOCAL_MACHINE : HKEY_CURRENT_USER;

    HKEY hSoftwareKey;
    if (ERROR_SUCCESS != ::RegOpenKeyEx(rootKey,
        keyName.c_str(), 0, KEY_WRITE | KEY_READ, &hSoftwareKey)) {
        return NULL;
    }
    return hSoftwareKey;
}


/// HKCU\Software\companyName\softwareName
HKEY Registry::createSoftwareKey(const std::string& companyName,
    const std::string& softwareName, bool useHKLM)
{
    const std::string keyName = getSoftwareKeyName(companyName, softwareName);

    const HKEY rootKey = useHKLM ? HKEY_LOCAL_MACHINE : HKEY_CURRENT_USER;

    HKEY hSoftwareKey;
    if (ERROR_SUCCESS != ::RegCreateKeyEx(rootKey, keyName.c_str(),
        0, REG_NONE, REG_OPTION_NON_VOLATILE, KEY_WRITE | KEY_READ, NULL,
        &hSoftwareKey, NULL)) {
        return NULL;
    }
    return hSoftwareKey;
}


bool Registry::setString(const std::string& companyName,
    const std::string& softwareName,
    const std::string& entry, const std::string& value,
    bool useHKLM)
{
    RegKeyGuard softwareKey(
        createSoftwareKey(companyName, softwareName, useHKLM));
    if (NULL == softwareKey.get()) {
        return false;
    }

    const void* valuePtr = value.c_str();
    const LONG lResult = ::RegSetValueEx(softwareKey.get(), entry.c_str(),
        NULL, REG_SZ, static_cast<const BYTE*>(valuePtr),
        static_cast<DWORD>((value.size() + 1) * sizeof(TCHAR)));

    return lResult == ERROR_SUCCESS;
}


bool Registry::getString(std::string& value, const std::string& companyName,
    const std::string& softwareName, const std::string& entry,
    const std::string& defaultValue, bool useHKLM)
{
    value = defaultValue;

    RegKeyGuard softwareKey(getSoftwareKey(companyName, softwareName, useHKLM));
    if (NULL == softwareKey.get()) {
        return false;
    }

    std::string parameter;
    DWORD dwType, dwCount;
    LONG lResult = ::RegQueryValueEx(softwareKey.get(), entry.c_str(), NULL,
        &dwType, NULL, &dwCount);
    if (lResult != ERROR_SUCCESS) {
        return false;
    }

    assert(dwType == REG_SZ);
    parameter.resize(dwCount, 0);
    void* parameterPtr = &(parameter[0]);
    if (ERROR_SUCCESS != ::RegQueryValueEx(softwareKey.get(), entry.c_str(),
        NULL, &dwType, static_cast<LPBYTE>(parameterPtr), &dwCount))  {
        return false;
    }

    assert(dwType == REG_SZ);
    value = parameter;
    return true;
}


bool Registry::setDword(const std::string& companyName,
    const std::string& softwareName, const std::string& entry, DWORD value,
    bool useHKLM)
{
    RegKeyGuard softwareKey(
        createSoftwareKey(companyName, softwareName, useHKLM));
    if (NULL == softwareKey.get()) {
        return false;
    }

    const LONG lResult = ::RegSetValueEx(softwareKey.get(), entry.c_str(),
        NULL, REG_DWORD, reinterpret_cast<const BYTE*>(&value), sizeof(DWORD));
    return lResult == ERROR_SUCCESS;
}


bool Registry::getDword(DWORD& value, const std::string& companyName,
    const std::string& softwareName, const std::string& entry,
    DWORD defaultValue, bool useHKLM)
{
    value = defaultValue;

    RegKeyGuard softwareKey(getSoftwareKey(companyName, softwareName, useHKLM));
    if (NULL == softwareKey.get()) {
        return false;
    }

    ULONG nBytes = sizeof(DWORD);
    DWORD dwValue, dwType;
    const LONG lRes = ::RegQueryValueEx(softwareKey.get(), entry.c_str(), NULL,
        &dwType, reinterpret_cast<LPBYTE>(&dwValue), &nBytes);
    if (lRes != ERROR_SUCCESS) {
        return false;
    }
    if (dwType != REG_DWORD) {
        return false;
    }

    value = dwValue;
    return true;
}

} // namespace esut
