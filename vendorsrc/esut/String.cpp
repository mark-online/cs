/**
* Copyright (c) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#include "stdafx.h"
#include "esut/String.h"
#include <cstdarg>
#include <ctime>
#include <cassert>

#pragma warning (disable: 4996)

namespace esut
{

std::string String::sprintf(const char* format, ...)
{
    assert(format != 0);

    std::string str;

    va_list argptr;
    va_start(argptr, format);
    String::vprintf(str, format, argptr);
    va_end(argptr);

    return str;
}


void String::sprintf(std::string& str, const char* format, ...)
{
    assert(format != 0);

    va_list argptr;
    va_start(argptr, format);
    vprintf(str, format, argptr);
    va_end(argptr);
}


void String::vprintf(std::string& str, const char* format, va_list & arg)
{
    assert(format);

    const int neededBytes = _vsnprintf(NULL, 0, format, arg) + 1;
    assert(neededBytes > 1);

    str.resize(neededBytes);

    _vsnprintf(&str[0], neededBytes, format, arg);

    str.resize(neededBytes - 1); // 1 == '\0';
}


std::wstring String::wsprintf(const wchar_t* format, ...)
{
    assert(format != 0);

    std::wstring str;

    va_list argptr;
    va_start(argptr, format);
    String::wvprintf(str, format, argptr);
    va_end(argptr);

    return str;
}


void String::wsprintf(std::wstring& str, const wchar_t* format, ...)
{
    assert(format != 0);

    va_list argptr;
    va_start(argptr, format);
    String::wvprintf(str, format, argptr);
    va_end(argptr);
}


void String::wvprintf(std::wstring& str, const wchar_t* format, va_list& arg)
{
    assert(format);

    const int neededBytes = _vsnwprintf(NULL, 0, format, arg) + 1;
    assert(neededBytes > 1);

    str.resize(neededBytes);

    _vsnwprintf(&str[0], neededBytes, format, arg);

    str.resize(neededBytes - 1); // 1 == '\0';
}



std::string String::getRatePerSecond(size_t size)
{
    const size_t kilo = 1024;
    const size_t mega = kilo * kilo;
    const size_t giga = mega * kilo;

    DWORD unit = 1;
    const char* suffix = "";
    if (size >= giga) {
        unit = giga;
        suffix = "G";
    }
    else if (size >= mega) {
        unit = mega;
        suffix = "M";
    }
    else if (size >= kilo) {
        unit = kilo;
        suffix = "K";
    }

    return String::sprintf("%.2f %sB/s",
        (static_cast<float>(size) / unit), suffix);
}


std::string String::GetCurrentTimeString()
{
    const time_t now = time(0);
    struct tm* nowTm = localtime(&now);
    assert(nowTm != 0);

    return sprintf("%02d:%02d:%02d",
        nowTm->tm_hour, nowTm->tm_min, nowTm->tm_sec);
}


std::string String::GetCurrentTimeString2()
{
    const time_t now = time(0);
    struct tm * nowTm = localtime(&now);
    assert(nowTm != 0);

    return sprintf("%04d%02d%02d_%02d%02d%02d",
        nowTm->tm_year+1900, nowTm->tm_mon+1, nowTm->tm_mday,
        nowTm->tm_hour, nowTm->tm_min, nowTm->tm_sec);
}

} // namespace esut
