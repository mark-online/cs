/**
* Copyright (c) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#ifndef _ESUT_BASE64_H_
#define _ESUT_BASE64_H_

#include "Singleton.h"
#include <boost/scoped_array.hpp>
#include <string>

namespace esut
{

/**
* @class Base64
*
* @brief Encode/Decode a stream of bytes according to Base64 encoding.
*
* This class provides methods to encode or decode a stream of bytes
* to/from Base64 encoding. It doesn't convert the input stream to a
* canonical form before encoding.
*
* - ACE_Base64 코드를 훔침!!
*/
class Base64 : public Singleton<Base64>
{
public:
    Base64();

    //@{

    /**
    * Encodes a stream of bytes to Base64 data
    *
    * @param input Binary data in byte stream.
    * @param input_len Length of the byte stream.
    * @param output_len Length of the encoded Base64 byte stream.
    * @return Encoded Base64 data in byte stream or NULL if input data cannot
    *         be encoded.
    */
    unsigned char* encode(const unsigned char* input,
        const size_t input_len,
        size_t* output_len);

    std::string encode(const std::string input) {
        size_t output_len = 0;
        boost::scoped_array<unsigned char> output(
            encode(reinterpret_cast<const unsigned char*>(input.c_str()),
                input.size(), &output_len));
        if (output.get() != 0) {
            return std::string(reinterpret_cast<const char*>(output.get()),
                output_len);
        }
        return "";
    }

    /**
    * Decodes a stream of Base64 to bytes data
    *
    * @param input Encoded Base64 data in byte stream.
    * @param output_len Length of the binary byte stream.
    * @return Binary data in byte stream or NULL if input data cannot
    *         be encoded.
    */
    unsigned char* decode(const unsigned char* input,
        size_t* output_len);

    std::string decode(const std::string input) {
        size_t output_len = 0;
        boost::scoped_array<unsigned char> output(
            decode(reinterpret_cast<const unsigned char*>(input.c_str()),
                &output_len));
        if (output.get() != 0) {
            return std::string(reinterpret_cast<const char*>(output.get()),
                output_len);
        }
        return "";
    }

    /**
    * Return the length of the encoded input data
    *
    * @param input Encoded Base64 data in byte stream.
    * @return Length of the encoded Base64 data.
    *
    */
    size_t length(const unsigned char* input) const;

    //@}

private:

    /// Initialize the tables for encoding/decoding.
    void init();

private:

    /// Alphabet used for decoding i.e decoder_[alphabet_[i = 0..63]] = i
    static unsigned char decoder_[];

    /// Alphabet used to check valid range of encoded input i.e
    /// member_[alphabet_[0..63]] = 1
    static unsigned char member_[];

};

} // namespace esut

#endif // _ESUT_BASE64_H_
