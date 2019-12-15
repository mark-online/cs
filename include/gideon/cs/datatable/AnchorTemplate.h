#pragma once

#include <gideon/cs/shared/data/BuildingInfo.h>
#include <gideon/cs/shared/data/StaticObjectSkillInfo.h>
#include <gideon/cs/shared/data/Time.h>

namespace gideon { namespace datatable {

/**
 * @class BaseAnchorInfo
 */
struct BaseAnchorInfo
{
    DataCode dataCode_;
    BuildingOwnerType ownerType_;
    float modelingRadius_;
    float comleteRegist_;
    sec_t liveTime_;
    HitPoint completeHp_;

    BaseAnchorInfo(DataCode dataCode = invalidDataCode, BuildingOwnerType ownerType = botUnknown,    
        float modelingRadius = 0.0f, float comleteRegist = 0.0f,
        sec_t liveTime = 0, HitPoint completeHp = hpMin) :
        dataCode_(dataCode),
        ownerType_(ownerType),
        modelingRadius_(modelingRadius),
        comleteRegist_(comleteRegist),
        liveTime_(liveTime),
        completeHp_(completeHp)
    {
    }

    bool isOwnerCommon() const {
        return ownerType_ == botCommon;
    }
};

/**
 * @class CheckAnchorInfo
 */
struct CheckAnchorInfo
{
    DataCode checkCode1_;
    float checkDistance1_;
    DataCode checkCode2_;
    float checkDistance2_;

    CheckAnchorInfo(DataCode checkCode1 = invalidDataCode, float checkDistance1 = 0.0f,
        DataCode checkCode2 = invalidDataCode, float checkDistance2 = 0.0f) :
        checkCode1_(checkCode1),
        checkDistance1_(checkDistance1),
        checkCode2_(checkCode2),
        checkDistance2_(checkDistance2) {}

    bool isValid() const {
        return isValidDataCode(checkCode1_) || isValidDataCode(checkCode2_); 
    }

    bool hasCheckCode(DataCode checkCode) const {
        return checkCode1_ == checkCode || checkCode2_ == checkCode;
    }
    
    float getCheckDistance(DataCode checkCode) const {
        if (checkCode1_ == checkCode) {
            return checkDistance1_;
        }
        else if (checkCode2_ == checkCode) {
            return checkDistance2_;
        }
        return 0.0f;
    }
};

/**
 * @enum SoSkillCastType
 */
enum SoSkillCastType
{
	ssctControll = 0, // 유저가 조정한다.
	ssctAutoActivate = 1, // 완성되고 활성화 되어 있을때
	ssctAutoComplete = 2, // 완성되기만 할때
};

template <typename T>
inline SoSkillCastType toSoSkillCastType(T value)
{
	return static_cast<SoSkillCastType>(static_cast<uint8_t>(value));
}


/**
 * @struct AnchorSkillInfo
 */
struct AnchorSkillInfo
{
    StaticObjectSkillCode skillCode_; // 설치물 스킬 코드  
    SoSkillCastType castType_;
    sec_t autoCastTime_;

    AnchorSkillInfo(StaticObjectSkillCode skillCode = invalidStaticObjectSkillCode,
        SoSkillCastType castType = ssctControll, sec_t autoCastTime = 0) :
        skillCode_(skillCode),
        castType_(castType),
        autoCastTime_(autoCastTime)
    {
    }


    bool isValid() const {
        return isValidDataCode(skillCode_);
    }
};

typedef sne::core::Vector<AnchorSkillInfo> AnchorSkillInfos;



/***
 * @struct BuildingFuelItem
 ***/
struct BuildingFuelItem
{
    BaseItemInfo consumeItem_;
    sec_t supportConsumeTime_;

    BuildingFuelItem(const BaseItemInfo& consumeItem,
        uint32_t supportConsumeTime) :
        consumeItem_(consumeItem),
        supportConsumeTime_(supportConsumeTime)
    {
    }
};

typedef sne::core::Vector<BuildingFuelItem> BuildingFuelItems;


/***
 * @struct BuildingFoundationInfo
 ***/
struct BuildingFoundationInfo
{
    HitPoint foundationHp_;
    float regist_;
    sec_t foundationLiveTime_;
    sec_t buildTime_;

    BuildingFoundationInfo(HitPoint foundationHp = hpMin,
        float regist = 0.0f, sec_t foundationLiveTime = 0, sec_t buildTime = 0) :
        foundationHp_(foundationHp),
        regist_(regist),
        foundationLiveTime_(foundationLiveTime),
        buildTime_(buildTime)
    {
    }

};


}} // namespace gideon { namespace datatable {