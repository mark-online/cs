/**
* Copyright (c) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#include "stdafx.h"
#include "esut/Base64.h"

namespace esut
{

namespace
{
    // Just in case ...
#undef alphabet
#undef pad
#undef max_columns

// Symbols which form the Base64 alphabet (Defined as per RFC 2045)
const unsigned char alphabet[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// The padding character used in the encoding
const unsigned char pad = '=';

// Number of columns per line of encoded output (Can have a maximum
// value of 76).
const int max_columns = 72;

} // namespace

unsigned char Base64::decoder_[256];
unsigned char Base64::member_[256];

Base64::Base64()
{
    Base64::init();
}


unsigned char* Base64::encode(const unsigned char* input,
    const size_t input_len, size_t* output_len)
{
    if (! input)
        return 0;

    unsigned char* result = 0;

    size_t length = ((input_len + 2) / 3) * 4;
    size_t num_lines = length / max_columns + 1;
    length += num_lines + 1;
    result = new unsigned char[length];

    int char_count = 0;
    int bits = 0;
    size_t pos = 0;
    int cols = 0;

    for (size_t i = 0; i < input_len; ++i) {
        bits += input[i];
        ++char_count;

        if (char_count == 3) {
            result[pos++] = alphabet[bits >> 18];
            result[pos++] = alphabet[(bits >> 12) & 0x3f];
            result[pos++] = alphabet[(bits >> 6) & 0x3f];
            result[pos++] = alphabet[bits & 0x3f];
            cols += 4;
            if (cols == max_columns) {
                result[pos++] = '\n';
                cols = 0;
            }
            bits = 0;
            char_count = 0;
        }
        else {
            bits <<= 8;
        }
    }

    if (char_count != 0) {
        bits <<= (16 - (8 * char_count));
        result[pos++] = alphabet[bits >> 18];
        result[pos++] = alphabet[(bits >> 12) & 0x3f];
        if (char_count == 1) {
            result[pos++] = pad;
            result[pos++] = pad;
        }
        else {
            result[pos++] = alphabet[(bits >> 6) & 0x3f];
            result[pos++] = pad;
        }
        if (cols > 0) {
            result[pos++] = '\n';
        }
    }
    result[pos] = 0;
    *output_len = pos;
    return result;
}


size_t Base64::length(const unsigned char* input) const
{
    unsigned char* ptr = const_cast<unsigned char*> (input);
    while (*ptr != 0 &&
        (member_[*(ptr)] == 1 || *ptr == pad
        || isspace(*ptr)))
        ++ptr;
    size_t len = ptr - input;
    len = ((len + 3) / 4) * 3 + 1 ;
    return len;
}


unsigned char* Base64::decode(const unsigned char* input, size_t* output_len)
{
    if (!input)
        return 0;

    size_t result_len = Base64::length(input);
    unsigned char* result = 0;
    result = new unsigned char[result_len];

    unsigned char* ptr = const_cast<unsigned char*>(input);
    while (*ptr != 0 &&
        (member_[*(ptr)] == 1 || *ptr == pad
        || isspace(*ptr)))
        ++ptr;
    size_t input_len = ptr - input;

    int char_count = 0;
    int bits = 0;
    size_t pos = 0;

    size_t i = 0;
    for (; i < input_len; ++i) {
        if (input[i] == pad)
            break;
        if (!Base64::member_[input[i]])
            continue;
        bits += decoder_[input[i]];
        ++char_count;

        if (char_count == 4) {
            result[pos++] = static_cast<unsigned char> (bits >> 16);
            result[pos++] = static_cast<unsigned char> ((bits >> 8) & 0xff);
            result[pos++] = static_cast<unsigned char> (bits & 0xff);
            bits = 0;
            char_count = 0;
        }
        else {
            bits <<= 6;
        }
    }

    int errors = 0;
    if (i == input_len) {
        if (char_count) {
            //assert(false && "Decoding incomplete: atleast ? bits truncated");
                //(4 - char_count) * 6)
            ++errors;
        }
    }
    else {
        switch (char_count) {
        case 1:
            //assert(false && "Decoding incomplete: atleast 2 bits missing");
            ++errors;
            break;
        case 2:
            result[pos++] = static_cast<unsigned char> (bits >> 10);
            break;
        case 3:
            result[pos++] = static_cast<unsigned char> (bits >> 16);
            result[pos++] = static_cast<unsigned char> ((bits >> 8) & 0xff);
            break;
        }
    }

    if (errors) {
        delete[] result;
        return 0;
    }
    result[pos] = 0;
    *output_len = pos;
    return result;
}


void Base64::init()
{
    for (unsigned char i = 0; i < sizeof (alphabet); ++i) {
        Base64::decoder_[alphabet[i]] = i;
        Base64::member_ [alphabet[i]] = 1;
    }
}

} // namespace esut
