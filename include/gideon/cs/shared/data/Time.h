#pragma once

#include <gideon/cs/Common.h>

namespace gideon {

/// 초 단위 시간
typedef __time64_t sec_t;


inline sec_t getTime()
{
    return _time64(0);
}


inline sec_t getDaySec() 
{
    return 60 * 60 * 24;
}

// 일일 시작 시간
inline sec_t getDayStartSec(sec_t timeSec)
{
    return timeSec / getDaySec() * getDaySec();
}


/// 게임 시간(밀리초 단위)
typedef msec_t GameTime;
const GameTime maxGameTime = (std::numeric_limits<GameTime>::max)();

inline GameTime getGameTimeDiff(GameTime oldTime, GameTime newTime)
{
    if (oldTime > newTime) {
        // overflow
        return (maxGameTime - oldTime) + newTime;
    }
    return newTime - oldTime;
}


enum {
    minutesInSec = 3600,
    minutesInHour = 60,
    minutesInDay = minutesInHour * 24
};


/// 월드 시간(분 단위)
typedef uint16_t WorldTime;

const WorldTime minWorldTime = 0;
const WorldTime maxWorldTime = minutesInDay;


inline void increaseWorldTime(WorldTime& worldTime)
{
    if (worldTime < maxWorldTime) {
        ++worldTime;
    }
    else {
        worldTime = minWorldTime;
    }
}


/// Gets the hour in the game, 0-23
inline uint32_t getHour(WorldTime worldTime)
{
	return (worldTime % minutesInDay) / minutesInHour;
}


/// Gets the minute in the game, 0-59
inline uint32_t getMinute(WorldTime worldTime)
{
	return worldTime % minutesInHour;
}


inline uint32_t convertToSecond(WorldTime worldTime)
{
    return worldTime * minutesInSec;
}


/**
 * @enum DayTime
 */
enum DayTime
{
    dtMorning,      // 00 ~ 06 시 - 낮
    dtAfternoon,    // 06 ~ 12 시 - 낮
    dtEvening,      // 12 ~ 18 시 - 낮
    dtNight         // 18 ~ 24 시 - 밤
};

inline bool isDayTime(DayTime dayTime)
{
    if(dayTime == dtMorning || dayTime == dtAfternoon || dayTime == dtEvening)
        return true;

    return false;
}

inline bool isNightTime(DayTime dayTime)
{
    if(dayTime == dtNight)
        return true;

    return false;
}

inline DayTime getDayTime(WorldTime worldTime)
{
    const int hour = getHour(worldTime);
    if ((hour == 0) || (hour <= 6)) {
        return dtMorning;
    }

    if (hour >= 18) {
        return dtNight;
    }

    if (hour >= 12) {
        return dtEvening;
    }

    return dtAfternoon;
}

inline float getDayTimeRate(WorldTime worldTime) // only client
{
    //const DayTime dayTime = getDayTime(worldTime);
    //if(isDayTime(dayTime)) {
    //    const float second = float(convertToSecond(worldTime));
    //    return (second / (18.0f * 60.0f * 3600.0f)) / 2.0f; // daytime
    //}
    //else if(isNightTime(dayTime)) {
    //    const float second = float(convertToSecond(worldTime)) - (18.0f * 60.0f * 3600.0f);
    //    return (second / (6.0f * 60.0f * 3600.0f)) / 2.0f + 0.5f; // night Time
    //}
    //return 0.0f;

	const float second = float(convertToSecond(worldTime));
	return (second / (24.0f * 60.0f * 3600.0f)); // daytime
}


} // namespace gideon {
