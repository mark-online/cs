#pragma once

#include "EffectInfo.h"
#include "Time.h"

namespace gideon {

/**
 * @struct ItemEffectResult
 * 아이템 사용 결과
 */
struct ItemEffectResult
{
    ///**
    // * @struct Effect
    // * 스킬 효과
    // */
    //struct Effect {
    //    

    //    Effect() :
    //        spellGroup_(sgNone),
    //        scriptType_(estUnknown),
    //        value_(0),
    //        activateTimer_(0),
    //        tickTimer_(0),
    //        param_(invalidDataCode) {}
    //
    //    bool isTimeSkill() const {
    //        return activateTimer_ > 0;
    //    }
    //    
    //    template <typename Stream>
    //    void serialize(Stream& stream) {
    //        stream & scriptType_;
    //        if (isChangeAppearanceSkill(scriptType_)) {
    //            stream & param_;
    //        }
    //        else {
    //            stream & value_;            

    //        }
    //    }
    //};

    //typedef sne::srpc::RArray<Effect, eanCount> Effects;

    DataCode itemCode_;
    //Effects effects_; //< 피격 효과 #1

    explicit ItemEffectResult(DataCode itemCode = invalidDataCode) :
        itemCode_(itemCode) {}

    //bool isValid() const {
    //    return gideon::isValid(effects_[0].scriptType_) || 
    //        gideon::isValid(effects_[1].scriptType_);
    //}

    //bool isAttackSkill(int index) const {
    //    if (index > 1) {
    //        return false;
    //    }
    //    return effects_[0].scriptType_ == estHpDamage;
    //}

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & itemCode_;
    }
};

} // namespace gideon {
