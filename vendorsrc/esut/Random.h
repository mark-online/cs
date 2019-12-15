#pragma once

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/smart_ptr/detail/lwm_win32_cs.hpp>
#include <ctime>

namespace esut {

namespace {

typedef boost::mt19937 RandomNumberGenerator;

RandomNumberGenerator& rngInstance()
{
    static RandomNumberGenerator rng(static_cast<int>(std::clock()));
    return rng;
}


boost::detail::lightweight_mutex& getRngMutex()
{
    static boost::detail::lightweight_mutex randomMutex;
    return randomMutex;
}

} // namespace

inline int random(int begin, int end)
{
    assert(begin <= end);
    if (begin == end) {
        return begin;
    }

    boost::detail::lightweight_mutex::scoped_lock scoped_lock(getRngMutex());

    boost::uniform_int<int> dist(begin, end);
    boost::variate_generator<RandomNumberGenerator&, boost::uniform_int<int> >
        rng(rngInstance(), dist);
    return rng();
}


inline unsigned int random(unsigned int begin, unsigned int end)
{
    assert(begin <= end);
    if (begin == end) {
        return begin;
    }

    boost::detail::lightweight_mutex::scoped_lock scoped_lock(getRngMutex());

    boost::uniform_int<unsigned int> dist(begin, end);
    boost::variate_generator<RandomNumberGenerator&, boost::uniform_int<unsigned int> >
        rng(rngInstance(), dist);
    return rng();
}


inline float random(float begin, float end)
{
    assert(begin <= end);
    if (begin == end) {
        return begin;
    }

    boost::detail::lightweight_mutex::scoped_lock scoped_lock(getRngMutex());

    boost::uniform_real<float> dist(begin, end);
    boost::variate_generator<RandomNumberGenerator&, boost::uniform_real<float> >
        rng(rngInstance(), dist);
    return rng();
}


inline int random()
{
    return random(0, (std::numeric_limits<int>::max)());
}


/// [0.0f, 1.0f]
inline float randomf()
{
    return random(0.0f, 1.0f);
}


/// [0, 1)
inline float randomExclusive()
{
    return float(double(random()) * (1.0 / 4294967296.0));
}


//returns a random in the range -1 < n < 1
inline float randomClamped()
{
    return randomf() - randomf();
}

} // namespace esut {
