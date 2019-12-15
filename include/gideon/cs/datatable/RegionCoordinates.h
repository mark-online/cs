#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/datatable/template/region_coordinates.hxx>
#include <gideon/cs/shared/data/RegionInfo.h>
#include <gideon/cs/shared/data/Coordinate.h>
#include <sne/core/container/Containers.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @struct CoordinatesTemplate
 */
struct CoordinatesTemplate
{
    RegionCode regionCode_;
    Position center_;
    float radius_;
    Position leftTop_;
    Position rightBottom_;

    CoordinatesTemplate(const gdt::coordinates_t& coord) :
        regionCode_(coord.region_code()),
        center_(coord.x(), coord.y(), coord.z()),
        radius_(coord.radius()),
        leftTop_(coord.x1(), coord.y2(), coord.z()),
        rightBottom_(coord.x2(), coord.y2(), coord.z()) {
        if (! isCircle()) {
            center_.x_ = ((leftTop_.x_ + rightBottom_.x_) / 2);
            center_.y_ = ((leftTop_.y_ + rightBottom_.y_) / 2); 
            center_.z_ = leftTop_.z_;
        }
    }

    CoordinatesTemplate(RegionCode regionCode, const Position& center, float radius) :
        regionCode_(regionCode),
        center_(center),
        radius_(radius) {}

    bool isCircle() const {
        return radius_ > 0.0f;
    }

    bool isContainedIn2d(const Position& pos, float delta = 0.0f) const {
        if (isCircle()) {
            const float radiusSq = (radius_ + delta) * (radius_ + delta);
            const float dx = pos.x_ - center_.x_;
            const float dy = pos.y_ - center_.y_;
            const float distanceSq = (dx * dx) + (dy * dy);
            return distanceSq <= radiusSq;
        }
        else {
            const float halfDelta = delta / 2.0f;
            return ((leftTop_.x_ - halfDelta) <= pos.x_) &&
                (pos.x_ <= (rightBottom_.x_ + halfDelta)) &&
                ((leftTop_.y_ - halfDelta) <= pos.y_) &&
                (pos.y_ <= (rightBottom_.y_ + halfDelta));
        }
    }
};

/**
 * @class RegionCoordinates
 *
 */
class GIDEON_CS_API RegionCoordinates : public boost::noncopyable
{
public:
    typedef sne::core::Vector<CoordinatesTemplate> CoordinatesList;
    typedef sne::core::HashMap<RegionCode, CoordinatesList> CoordinatesMap;

public:
    virtual ~RegionCoordinates() {}

public:
    virtual const CoordinatesList* getCoordinates(RegionCode code) const = 0;

    virtual const CoordinatesMap& getCoordinatesMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {
