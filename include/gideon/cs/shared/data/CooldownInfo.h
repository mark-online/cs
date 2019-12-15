#pragma once

#include "Time.h"
#include "Code.h"
#include "EffectInfo.h"

namespace gideon {

/**
* @struct CooltimeInfo
* 쿨타임 정보
*/
struct CooltimeInfo
{
    DataCode dataCode_;
    sec_t endTime_;

    CooltimeInfo(DataCode dataCode = invalidDataCode,
        sec_t endTime = 0) :
        dataCode_(dataCode),
        endTime_(endTime)
    {
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & dataCode_ & endTime_;
    }
};

typedef sne::srpc::RVector<CooltimeInfo> CooltimeInfos;

const sec_t cooldownSaveTime = 50;

/**
* @struct RemainEffectInfo
* 이펙트 적용 정보
*/
struct RemainEffectInfo
{  
    struct Effect
    {
        sec_t expireActivateTime_;
        int32_t effectValue_;

        template <typename Stream>
        void serialize(Stream& stream) {
            stream & expireActivateTime_ & effectValue_;
        }
    };

    typedef sne::srpc::RArray<Effect, eanCount> Effects;
    DataCode dataCode_;
    UseTargetStatusType useTargetStatusType_;
    bool isCaster_;
    Effects effects_; 
    
    RemainEffectInfo(DataCode dataCode = 0, UseTargetStatusType useTargetStatusType = utstNone,
        bool isCaster = false, const RemainEffectInfo::Effects& effects = RemainEffectInfo::Effects()) :
        dataCode_(dataCode),            
        useTargetStatusType_(useTargetStatusType),
        isCaster_(isCaster),
        effects_(effects)
    {
    }

    bool canExcute(sec_t now) const {
        for (int i = 0; i < eanCount; ++i) {
            if (now < effects_[i].expireActivateTime_) {
                return true;
            }
        }
        return false;
    }
 
    template <typename Stream>
    void serialize(Stream& stream) {
        stream & dataCode_ & useTargetStatusType_ & isCaster_ & effects_;
    }
};

typedef sne::srpc::RVector<RemainEffectInfo> RemainEffectInfos;

} // namespace gideon {
