#pragma once

#include "WorldInfo.h"
#include <sne/srpc/RpcContainers.h>
#include <boost/math/constants/constants.hpp>

namespace gideon {

/**
 * @class Position
 * 3D 좌표
 * - -x: 왼쪽, +x: 오른쪽
 * - -z: 아래, +z: 위
 * - -y: 전방, +y: 후방
 * - 주의! endian 고려하지 않음
 */
struct Position
{
    float x_;
    float y_;
    float z_;

    Position() {
        reset();
    }

    Position(float x, float y, float z) :
        x_(x),
        y_(y),
        z_(z) {}

    void reset() {
        x_ = 0.0f;
        y_ = 0.0f;
        z_ = 0.0f;
    }

    bool isZero() const {
        return (x_ == 0.0f) && (y_ == 0.0f) && (z_ == 0.0f);
    }

    bool operator==(const Position& p) const {
        return (x_ == p.x_) && (y_ == p.y_) && (z_ == p.z_);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & x_ & y_ & z_;
    }
};

typedef sne::srpc::RVector<Position> Positions;


/// 캐릭터가 바라 보는 방향 각도
/// - 패킷 크기를 줄이기 위해 반값을 사용(예, 90도 == 45)
typedef uint8_t Heading;
const uint8_t minHeading = 0;
const uint8_t maxHeading = 360 / 2;

inline bool isValidHeading(int h)
{
    return (minHeading <= h) && (h <= maxHeading);
}


template <typename T>
inline Heading fixHeading(T heading)
{
    return static_cast<Heading>(heading % maxHeading);
}


template <typename T>
inline Heading toHeading(T degree)
{
    int heading = (int(degree) / 2) % maxHeading;
    if (heading < 0) {
        heading += maxHeading;
    }
    assert(isValidHeading(heading));
    return Heading(heading);
}


inline int toDegrees(Heading h)
{
    assert(isValidHeading(h));
    return h * 2;
}


/// @pre isValidHeading(h) == true
inline float toRadian(Heading h)
{
    static const float radianTable[maxHeading + 1] =
    {
        0.0000f, 0.0349f, 0.0698f, 0.1047f, 0.1396f,
        0.1745f, 0.2094f, 0.2443f, 0.2793f, 0.3142f,
        0.3491f, 0.3840f, 0.4189f, 0.4538f, 0.4887f,
        0.5236f, 0.5585f, 0.5934f, 0.6283f, 0.6632f,
        0.6981f, 0.7330f, 0.7679f, 0.8029f, 0.8378f,
        0.8727f, 0.9076f, 0.9425f, 0.9774f, 1.0123f,
        1.0472f, 1.0821f, 1.1170f, 1.1519f, 1.1868f,
        1.2217f, 1.2566f, 1.2915f, 1.3265f, 1.3614f,
        1.3963f, 1.4312f, 1.4661f, 1.5010f, 1.5359f,
        1.5708f, 1.6057f, 1.6406f, 1.6755f, 1.7104f,
        1.7453f, 1.7802f, 1.8151f, 1.8500f, 1.8850f,
        1.9199f, 1.9548f, 1.9897f, 2.0246f, 2.0595f,
        2.0944f, 2.1293f, 2.1642f, 2.1991f, 2.2340f,
        2.2689f, 2.3038f, 2.3387f, 2.3736f, 2.4086f,
        2.4435f, 2.4784f, 2.5133f, 2.5482f, 2.5831f,
        2.6180f, 2.6529f, 2.6878f, 2.7227f, 2.7576f,
        2.7925f, 2.8274f, 2.8623f, 2.8972f, 2.9322f,
        2.9671f, 3.0020f, 3.0369f, 3.0718f, 3.1067f,
        3.1416f, 3.1765f, 3.2114f, 3.2463f, 3.2812f,
        3.3161f, 3.3510f, 3.3859f, 3.4208f, 3.4558f,
        3.4907f, 3.5256f, 3.5605f, 3.5954f, 3.6303f,
        3.6652f, 3.7001f, 3.7350f, 3.7699f, 3.8048f,
        3.8397f, 3.8746f, 3.9095f, 3.9444f, 3.9794f,
        4.0143f, 4.0492f, 4.0841f, 4.1190f, 4.1539f,
        4.1888f, 4.2237f, 4.2586f, 4.2935f, 4.3284f,
        4.3633f, 4.3982f, 4.4331f, 4.4680f, 4.5029f,
        4.5379f, 4.5728f, 4.6077f, 4.6426f, 4.6775f,
        4.7124f, 4.7473f, 4.7822f, 4.8171f, 4.8520f,
        4.8869f, 4.9218f, 4.9567f, 4.9916f, 5.0265f,
        5.0615f, 5.0964f, 5.1313f, 5.1662f, 5.2011f,
        5.2360f, 5.2709f, 5.3058f, 5.3407f, 5.3756f,
        5.4105f, 5.4454f, 5.4803f, 5.5152f, 5.5501f,
        5.5851f, 5.6200f, 5.6549f, 5.6898f, 5.7247f,
        5.7596f, 5.7945f, 5.8294f, 5.8643f, 5.8992f,
        5.9341f, 5.9690f, 6.0039f, 6.0388f, 6.0737f,
        6.1087f, 6.1436f, 6.1785f, 6.2134f, 6.2483f,
        6.2832f
    };

    assert(isValidHeading(h));
    return radianTable[h];

    //return (toDegrees(h) / 180.0f) * boost::math::constants::pi<float>();
}


/**
 * @struct ObjectPosition
 * 맵 상의 오브젝트 위치 좌표
 */
struct ObjectPosition : public Position
{
    Heading heading_;

    ObjectPosition() {
        reset();
    }

    ObjectPosition(const Position& position, Heading heading) :
        Position(position),
        heading_(heading) {}

    ObjectPosition(float x, float y, float z, Heading heading) :
        Position(x, y, z),
        heading_(heading) {}

    void reset() {
        Position::reset();
        heading_ = minHeading;
    }

    bool operator==(const ObjectPosition& p) const {
        if (! Position::operator==(p)) {
            return false;
        }
        return heading_ == p.heading_;
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        Position::serialize(stream);
        stream & heading_;
    }
};


/**
 * @struct WorldPosition
 * 월드 상의 오브젝트 위치 좌표
 */
struct WorldPosition : public ObjectPosition
{
    MapCode mapCode_;

    WorldPosition() {
        reset();
    }

    WorldPosition(float x, float y, float z, Heading heading,
        MapCode mapCode) :
        ObjectPosition(x, y, z, heading),
        mapCode_(mapCode) {}

    WorldPosition(const ObjectPosition& position, MapCode mapCode) :
        ObjectPosition(position),
        mapCode_(mapCode) {}

    void reset() {
        ObjectPosition::reset();
        mapCode_ = invalidMapCode;
    }

    bool isValid() const {
        return isValidMapCode(mapCode_);
    }

    bool operator==(const WorldPosition& p) const {
        if (! ObjectPosition::operator==(p)) {
            return false;
        }
        return mapCode_ == p.mapCode_;
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        ObjectPosition::serialize(stream);
        stream & mapCode_;
    }
};

/**
 * @struct Waypoint
 * 미니맵상의 웨이 포인트
 */
struct Waypoint
{
    float x_;
    float y_;
    MapCode mapCode_;

    Waypoint(float x, float y, MapCode mapCode) :
        x_(x),
        y_(y),
        mapCode_(mapCode) {}

    Waypoint() {
        reset();
    }

    void reset() {
        x_ = 0.0f;
        y_ = 0.0f;
        mapCode_ = invalidMapCode;
    }

    bool isValid() const {
        return (x_ != 0.0f) && (y_ != 0.0f) && isValidMapCode(mapCode_);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & x_ & y_ & mapCode_;
    }
};

} // namespace gideon {
