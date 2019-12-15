/**
* Copyright (c) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#ifndef _ESUT_SINGLETON_H_
#define _ESUT_SINGLETON_H_

#include <boost/noncopyable.hpp>

namespace esut
{

/**
 * @class Singleton
 * class Singleton has the same goal as all singletons: create one instance of
 * a class on demand, then dish it out as requested.
 */
template <class T>
class Singleton : public boost::noncopyable
{
public:
    static T& instance() {
        // function-local static to force this to work correctly at static
        // initialization time.
        static T s_instance;
        return s_instance;
    }
};


/**
 * @class ChangableSingleton
 * this class DON'T have ownership.
 */
template <class T>
class ChangableSingleton : public boost::noncopyable
{
    static T* anInstance;
public:
    static void instance(T* instance) {
        ChangableSingleton<T>::anInstance = instance;
    }

    static T& instance() {
        return *ChangableSingleton<T>::anInstance;
    }
};

template <class T>
T* ChangableSingleton<T>::anInstance = 0;

} // namespace esut

#endif // _ESUT_SINGLETON_H_
