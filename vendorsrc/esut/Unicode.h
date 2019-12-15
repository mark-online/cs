#pragma once

#include <windows.h>
#include <string>

namespace esut
{

/**
@param codepage CP_ACP or CP_UTF8
*/
inline std::wstring toUnicode(const char* in, UINT codepage)
{
    assert(in != 0);

    if (*in == '\0') {
        return L"";
    }

    std::wstring out;

    const int neededSize = MultiByteToWideChar(codepage, 0, in, -1, NULL, 0);
    out.resize(neededSize);
    const int realSize =
        MultiByteToWideChar(codepage, 0, in, -1, &out[0], int(out.size()));
    assert(realSize > 0);
    if (realSize > 0) {
        out.resize(realSize-1);
    }

    return out;
}

/**
@param codepage CP_ACP or CP_UTF8
*/
inline std::string fromUnicode(const wchar_t* in, UINT codepage)
{
    assert(in != 0);

    if (*in == 0) {
        return "";
    }

    std::string out;

    const int neededSize =
        WideCharToMultiByte(codepage, 0, in, -1, NULL, 0, NULL, NULL);
    out.resize(neededSize);
    const int realSize =
        WideCharToMultiByte(codepage, 0, in, -1, &out[0], int(out.size()),
        NULL, NULL);
    assert(realSize > 0);
    if (realSize > 0) {
        out.resize(realSize-1);
    }

    return out;
}


/// UCS-4 -> UTF-8
inline std::string unicodeToUtf8(const wchar_t* in)
{
    return fromUnicode(in, CP_UTF8);
}


/// MBCS -> UCS-4 -> UTF-8
inline std::string mbcsToUtf8(const char* in)
{
    return unicodeToUtf8(toUnicode(in, CP_ACP).c_str());
}


inline std::wstring utf8ToUnicode(const char* in)
{
    return toUnicode(in, CP_UTF8);
}


/// UTF-8 -> UCS-4 -> MBCS
inline std::string utf8ToMbcs(const char* in)
{
    return fromUnicode(utf8ToUnicode(in).c_str(), CP_ACP);
}

} // namespace esut
