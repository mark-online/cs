#pragma once

#include "SkillInfo.h"
#include "Coordinate.h"
#include "ElementInfo.h"
#include "QuestInfo.h"

namespace gideon {


/**
 * @enum EffectDefenceType
 */
enum EffectDefenceType
{
    edtNone = 0, //< 방어 못함
    edtMissed, //< 공격 실패
    edtDodged, //< 회피
    edtParried, //< 무기 막기
    edtBlocked, //< 방패 막기
    edtResisted, //< 마법 저항(막기)

    edtBoundary
};


inline bool isValid(EffectDefenceType value)
{
    return (edtNone <= value) && (value < edtBoundary);
}


inline bool shouldApplyEffect(EffectDefenceType value)
{
    return value == edtNone || value == edtBlocked || value == edtResisted;
}

/**
 * @struct SkillEffectResult
 * 스킬 사용 결과
 */
struct SkillEffectResult
{
    /**
     * @struct Effect
     * 스킬 효과
     */
    struct Effect {
        int32_t value_;
        bool isCritical_;
        Position position_;
        int32_t decreaseValue_;
        bool isImmune_;

        Effect() :
            value_(0),
            isCritical_(false),
            decreaseValue_(0),
            isImmune_(false) {}
    
        template <typename Stream>
        void serialize(Stream& stream) {
            stream & value_ & isCritical_ & position_ & decreaseValue_ & isImmune_;
        }
    };

    typedef sne::srpc::RArray<Effect, eanCount> Effects;

    DataCode dataCode_;
    bool isCasterEffect_;
    Effects effects_;

    explicit SkillEffectResult(DataCode dataCode = invalidDataCode, 
        bool isCasterEffect = false) :
        dataCode_(dataCode),
        isCasterEffect_(isCasterEffect) 
    {
    }

    inline bool isValid() const {
        return isValidSkillCode(dataCode_);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & dataCode_ & isCasterEffect_ & effects_;        
    }
};

} // namespace gideon {


namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::EffectDefenceType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::EffectDefenceType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::EffectDefenceType>(value);
    return lhs;
}

}} // namespace sne { namespace core {