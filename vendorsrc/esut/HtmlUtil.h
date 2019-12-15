#if !defined(ESUT_HTMLUTIL_H)
#define ESUT_HTMLUTIL_H

#include "Unicode.h"

namespace esut
{

/**
 * @struct HtmlUtil
 * HTML 관련 유틸리티 모음
 */
struct HtmlUtil
{

    // Translates all the characters that are not in url_ok_chars string into
    // %xx sequences. %xx specifies the character ascii code in hexadecimal
    static std::string escapeUrl(const std::string& in, bool useUtf8)
    {
        static const std::string validChars =
            "*-./0123456789:@ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz";
        static char hex_digits[17] = "0123456789ABCDEF";

        const std::string escaped = useUtf8 ? mbcsToUtf8(in.c_str()) : in;

        std::string out;
        out.reserve(escaped.size() * 2);
        for (size_t i = 0; i < escaped.size(); ++i) {
            const char c = escaped[i];
            if (validChars.find(c) != std::string::npos) {
                out += c;
            }
            else {
                out += '%';
                out += hex_digits[static_cast<unsigned char>(c) >> 4];
                out += hex_digits[c & 0x0F];
            }
        }
        return out;
    }

};

} // namespace esut

#endif // !defined(ESUT_HTMLUTIL_H)
