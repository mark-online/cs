/**
* Copyright (c) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#ifndef _ESUT_ILESS_H_
#define _ESUT_ILESS_H_

#include <functional>
#include <string>

namespace esut
{

/**
 * @struct iless
 * 대소문자 구분없이 비교한다!!!
 */
struct iless :
    public std::binary_function<std::string, std::string, bool>
{
    bool operator()(const std::string& left,
        const std::string& right) const {
        // _stricmp가 훨씬 빠름!!!
        //return boost::ilexicographical_compare(left, right);
        return _stricmp(left.c_str(), right.c_str()) < 0;
    }
};

} // namespace esut

#endif    //_ESUT_ILESS_H_
