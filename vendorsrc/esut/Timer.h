/**
* Copyright (c) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#ifndef _ESUT_TIMER_H_
#define _ESUT_TIMER_H_

#include "Singleton.h"
#ifndef GetTickCount
#  include <windows.h>
#endif
#include <limits>

namespace esut
{

/**
 * @class SimpleTimer
 * 단순히 경과 시간을 ms 단위로 유지하는 유틸리티
 */
class SimpleTimer
{
public:
    SimpleTimer() {
        reset();
    }

    void reset() {
        m_startTime = GetTickCount();
        m_isEnabled = true;
    }

    void stop() {
        m_isEnabled = false;
    }

    DWORD getElapsed() const {
        const DWORD now = GetTickCount();
        if (now < m_startTime) {
            return ((std::numeric_limits<DWORD>::max)() - m_startTime) + now + 1;
        }
        return now - m_startTime;
    }

    bool isEnabled() const {
        return m_isEnabled;
    }

private:
    DWORD m_startTime;
    bool m_isEnabled;
};


enum TimerId {
    tiInvalid = -1
};

inline bool isValid(TimerId id)
{
    return id > tiInvalid;
}


/**
 * @class TimerListener
 */
class TimerListener
{
public:
    virtual ~TimerListener() {}

    /// @return 타이머를 종료시킬려면 false
    virtual bool timerExpired(TimerId id) = 0;
};


/**
* @class TimerManager
* @warning GetTickCount()를 사용하므로 49.7 days wrapping 문제가 있다
*/
class TimerManager : public Singleton<TimerManager>
{
    /**
     * @struct Timer
     */
    struct Timer
    {
        DWORD m_timeout;
        DWORD m_interval;
        TimerListener* m_listener;

        Timer(DWORD delay, DWORD interval, TimerListener* listener) :
            m_timeout(GetTickCount() + delay),
            m_interval(interval),
            m_listener(listener) {}

        bool isTimeout(DWORD now) const {
            return m_timeout >= now;
        }

        bool fire(TimerId id) {
            if (! m_listener->timerExpired(id)) {
                return false;
            }

            if (m_interval <= 0) {
                return false;
            }

            m_timeout += m_interval;
            return true;
        }
    };

    typedef std::map<TimerId, Timer> TimerMap;

public:
    TimerManager() :
        m_lastTimerId(tiInvalid) {}

    /**
     * @param delay Time interval after which the timer will expire
     * @param interval Time interval after which the timer will be
     *                 automatically rescheduled
     */
    TimerId schedule(TimerListener* listener, DWORD delay,
        DWORD interval = 0) {
        m_lastTimerId = static_cast<TimerId>(m_lastTimerId + 1);
        m_timers.insert(
            TimerMap::value_type(
                m_lastTimerId,
                Timer(delay, interval, listener)));
        return m_lastTimerId;
    }

    void cancel(TimerId id) {
        m_timers.erase(id);
    }

    void poll() {
        const DWORD now = GetTickCount();

        TimerMap::iterator pos = m_timers.begin();
        const TimerMap::iterator end = m_timers.end();
        for (; pos != end;) {
            const TimerId id = (*pos).first;
            Timer& timer = (*pos).second;
            if (timer.isTimeout(now)) {
                if (! timer.fire(id)) {
                    m_timers.erase(pos++);
                }
                else {
                    ++pos;
                }
            }
            else {
                ++pos;
            }
        }
    }

private:
    TimerId m_lastTimerId;
    TimerMap m_timers;
};


} // namespace esut

#endif    //_ESUT_TIMER_H_
