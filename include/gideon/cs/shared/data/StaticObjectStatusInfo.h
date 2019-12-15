#pragma once

#include "StatusInfo.h"

namespace gideon {

/**
 * @struct StaticObjectStatus
 */
struct StaticObjectStatusInfo
{
    HitPoints hitPoints_;

    int16_t defence_;
    AttackPowers attackPowers_;
    AttributeRates attributes_;
    AttributeRates attributeResists_;

    explicit StaticObjectStatusInfo(const HitPoints& hitPoints = HitPoints(),
        int16_t defence = 0, const AttackPowers& attackPowers = AttackPowers(),
        const AttributeRates& attributes = AttributeRates(),
        const AttributeRates& attributeResists = AttributeRates()) :
        hitPoints_(hitPoints),
        defence_(defence),
        attackPowers_(attackPowers),
        attributes_(attributes),
        attributeResists_(attributeResists)
    {
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream& hitPoints& & defence_ & attackPowers_ & attributes_ & attributeResists_;
    }

};

} // namespace gideon {