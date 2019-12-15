/**
* Copyright (c) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#ifndef ESUT_THREAD_H
#define ESUT_THREAD_H

#include "Mutex.h"

namespace esut
{

/**
 * @class AbstractThread
 * 'portable' thread framework
 */
class AbstractThread
{
public:
    virtual ~AbstractThread() {}

    virtual bool create() = 0;
    virtual void run() = 0;
    virtual void join() = 0;
};


#if !defined(BOOST_HAS_PTHREADS) && defined(BOOST_HAS_WINTHREADS)

#include <windows.h>
#include <process.h>

typedef HANDLE pthread_t;

inline unsigned __stdcall commonThreadRoutine(void * pv)
{
    AbstractThread* pt = static_cast<AbstractThread*>(pv);
    pt->run();
    return 0;
}


inline int pthread_create(pthread_t* thread, void const *,
    unsigned (__stdcall * start_routine) (void*), void* arg)
{
    const HANDLE h = (HANDLE)_beginthreadex(0, 0, start_routine, arg, 0, 0);
    if (h != NULL) {
        *thread = h;
        return 0;
    }
    else {
        return 1; // return errno;
    }
}


inline int pthread_join(pthread_t thread, void** /*value_ptr*/)
{
    ::WaitForSingleObject(thread, INFINITE);
    ::CloseHandle(thread);
    return 0;
}

#else

#include <pthread.h>

extern "C" void * commonThreadRoutine(void * pv)
{
    AbstractThread * pt = static_cast<AbstractThread *>(pv);
    pt->run();
    return 0;
}

#endif

/**
 * @class Thread
 */
template<class Func>
class Thread : public AbstractThread
{
public:
    explicit Thread(Func f):
        func_(f),
        threadId_(0) {}

    virtual bool create() {
        if (pthread_create(&threadId_, 0, commonThreadRoutine, this) != 0) {
            return false;
        }

        return true;
    }

    virtual void join() {
        if (threadId_ != 0) {
            pthread_join(threadId_, 0);
        }
    }

private:
    virtual void run() {
        func_();
    }

private:
    Func func_;
    pthread_t threadId_;
};


template<class Func>
inline std::auto_ptr<AbstractThread> createThread(Func f)
{
    std::auto_ptr<AbstractThread> p(new Thread<Func>(f));

    if (! p->create()) {
        return 0;
    }

    return p;
}

} // namespace esut

#endif // ESUT_THREAD_H
