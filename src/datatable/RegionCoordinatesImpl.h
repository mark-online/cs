#pragma once

#include <gideon/cs/datatable/RegionCoordinates.h>

namespace gideon { namespace datatable {

/**
 * @class RegionCoordinatesImpl
 *
 */
class RegionCoordinatesImpl : public RegionCoordinates
{
public:
    RegionCoordinatesImpl(std::istream& is)  :
        isLoaded_(false) {
        try {
            std::unique_ptr<gdt::region_coordinates> regionCoordinates =
                gdt::region_coordinates_(is, ::xml_schema::flags::dont_validate);

            for (const gdt::coordinates_t& coordinates :
                regionCoordinates->coordinates()) {
                coordinatesMap_[coordinates.region_code()].emplace_back(coordinates);
            }
            isLoaded_ = true;
        }
        catch (const xml_schema::exception& e) {
            lastError_ = e.what();
        }
    }

public:
    virtual const CoordinatesList* getCoordinates(RegionCode code) const {
        const CoordinatesMap::const_iterator pos = coordinatesMap_.find(code);
        if (pos != coordinatesMap_.end()) {
            return &(*pos).second;
        }
        return nullptr;
    }

    virtual const CoordinatesMap& getCoordinatesMap() const {
        return coordinatesMap_;
    }

    virtual const std::string& getLastError() const {
        return lastError_;
    }

    virtual bool isLoaded() const {
        return isLoaded_;
    }

private:
    CoordinatesMap coordinatesMap_;
    std::string lastError_;
    bool isLoaded_;
};

}} // namespace gideon { namespace datatable {
