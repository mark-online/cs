#pragma once


namespace gideon {

/**
 * @enum EnvironmentType
 * 지형의 환경 타입
 */
enum EnvironmentType
{
    evtUnknown = 0,
    evtGround = 1, // 땅
    evtWarter = 2, // 물
    evtLava = 3,       // 용암
    evtBoundery
};


inline bool isValid(EnvironmentType type)
{
    return evtUnknown < type && type < evtLava;
}


template <typename T>
EnvironmentType toEnvironmentType(T craftType)
{
    return static_cast<EnvironmentType>(static_cast<uint8_t>(craftType));
}


} // namespace gideon {
