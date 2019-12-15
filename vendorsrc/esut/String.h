/**
* Copyright (c) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#ifndef _ESUT_STRING_H_
#define _ESUT_STRING_H_

#include <string>

namespace esut
{

/**
 * @struct String
 *
 * String utility
 */
struct String
{

    /// search를 input으로 바꾼다
    static std::string& replace_all(std::string& str,
        std::string::value_type search, std::string::value_type input) {
        std::string::iterator pos = str.begin();
        const std::string::iterator end = str.end();
        for (; pos != end; ++pos) {
            if (*pos == search) {
                *pos = input;
            }
        }
        return str;
    }

    /// search를 input으로 바꾼다
    static std::string replace_all_copy(const std::string& str,
        std::string::value_type search, std::string::value_type input) {
        std::string copied(str);
        return String::replace_all(copied, search, input);
    }

    /// search를 input으로 바꾼다
    static std::wstring& replacew_all(std::wstring& str,
        std::wstring::value_type search, std::wstring::value_type input) {
            std::wstring::iterator pos = str.begin();
            const std::wstring::iterator end = str.end();
            for (; pos != end; ++pos) {
                if (*pos == search) {
                    *pos = input;
                }
            }
            return str;
    }

    /// search를 input으로 바꾼다
    static std::wstring replacew_all_copy(const std::wstring& str,
        std::wstring::value_type search, std::wstring::value_type input) {
            std::wstring copied(str);
            return String::replacew_all(copied, search, input);
    }

    static std::string sprintf(const char* format, ...);
    static void sprintf(std::string& str, const char* format, ...);
    static void vprintf(std::string& str, const char* format, va_list& arg);

    static std::wstring wsprintf(const wchar_t* format, ...);
    static void wsprintf(std::wstring& str, const wchar_t* format, ...);
    static void wvprintf(std::wstring& str, const wchar_t* format, va_list& arg);

    static int toInteger(const std::string& str) {
        return atoi(str.c_str());
    }

    static float toFloat(const std::string& str) {
        return static_cast<float>(atof(str.c_str()));
    }

    /// replace sring "\n" to \n, same with "\r"
    static std::wstring& fixLineBreak(std::wstring& input) {
        std::wstring::size_type posN = 0;
        while ((posN = input.find(L"\\n")) != std::wstring::npos) {
            input.replace(posN, 2, L"\n");
        }

        std::wstring::size_type posR = 0;
        while ((posR = input.find(L"\\r")) != std::wstring::npos) {
            input.replace(posR, 2, L"\r");
        }

        return input;
    }


    /// "999 B", "1023 B", "3 KB", "1023 KB", "100 MB", "9999 GB"
    static std::string getRatePerSecond(size_t size);

    /// hh:mm:nn
    static std::string GetCurrentTimeString();

    /// yyyyMMdd_hhmmnn
    static std::string GetCurrentTimeString2();

};

} // namespace esut

#endif    //_ESUT_STRING_H_
