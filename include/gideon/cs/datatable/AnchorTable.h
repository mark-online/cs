#pragma once
#include "AnchorTemplate.h"
#include <gideon/cs/datatable/template/anchor_table.hxx>
#include <gideon/cs/shared/data/AnchorInfo.h>
#include <gideon/cs/shared/data/StaticObjectStatusInfo.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {



/***
 * @class AnchorTemplate
 ***/
class AnchorTemplate
{
public:
    AnchorTemplate(const gdt::anchor_t& anchorInfo) :
        anchorInfo_(&anchorInfo),
        modelingRadius_(100.0f)
    {
        intializeStatus();
    }

    ~AnchorTemplate() {
        //deleteAnchorInfo();
    }

    float getModelingRadius() const {
        return modelingRadius_;
    }
    
    const StaticObjectStatusInfo& getStaticObjectStatusInfo() const {
        return status_;
    }

    SkillCode getSkillCode() const {
        return anchorInfo_->skill_code();
    }
    
    sec_t getLiveSec() const {        
        return anchorInfo_->live_sec();
    }

    GameTime getActiveInterval() const {
        return anchorInfo_->active_interval_mil_sec();
    }

    uint8_t getStackCount() const {
        return static_cast<uint8_t>(anchorInfo_->stack_count());
    }

    const gdt::anchor_t& getAnchorInfo() const {
        return *anchorInfo_;
    }

    void deleteAnchorInfo() {
        if (anchorInfo_) {
            delete anchorInfo_;
            anchorInfo_ = 0;
        }
    }

    const wchar_t* getBuildAnimation() const {
        return anchorInfo_->build_animation().c_str();
    }

    const wchar_t* getCompleteModeling() const {
        return anchorInfo_->complete_modeling().c_str();
    }

    const wchar_t* getBrokenAnimation() const {
        return anchorInfo_->broken_animation().c_str();
    }

    const wchar_t* getBuildEffectName() const {
        return anchorInfo_->build_effect().c_str();
    }

    const wchar_t* getBrokenEffectName() const {
        return anchorInfo_->broken_effect().c_str();
    }

    const wchar_t* getBuildModeling() const {
        return anchorInfo_->build_modeling().c_str();
    }

    const wchar_t* getAnchorIcon() const {
        return anchorInfo_->icon_name().c_str();
    }

private:
    void intializeStatus() {
        status_.hitPoints_.maxHp_ = toHitPoint(anchorInfo_->hp());
        status_.hitPoints_.hp_ = toHitPoint(anchorInfo_->hp());
        status_.defence_ = static_cast<int16_t>(anchorInfo_->defence());
        status_.attackPowers_[apiMinAttack] = anchorInfo_->min_attack_power();
        status_.attackPowers_[apiMaxAttack] = anchorInfo_->max_attack_power();
        status_.attackPowers_[apiPhysical] = anchorInfo_->physical_attack_power();
        status_.attackPowers_[apiMagic] = anchorInfo_->magic_attack_power();

        status_.attributes_[abiLight] = anchorInfo_->light_attribute();
        status_.attributes_[abiDark] = anchorInfo_->dark_attribute();
        status_.attributes_[abiFire] = anchorInfo_->fire_attribute();
        status_.attributes_[abiIce] = anchorInfo_->ice_attribute();
        status_.attributeResists_[abiLight] = anchorInfo_->light_attribute_regist();
        status_.attributeResists_[abiDark] = anchorInfo_->dark_attribute_regist();
        status_.attributeResists_[abiFire] = anchorInfo_->fire_attribute_regist();
        status_.attributeResists_[abiIce] = anchorInfo_->ice_attribute_regist();
    }
private:
	const gdt::anchor_t* anchorInfo_;
    HitPoint hp_;
    int16_t defence_;
    AttackPowers attackPowers_;
    AttributeRates attributes_;
    AttributeRates attributeResists_;
    float modelingRadius_;
    StaticObjectStatusInfo status_;
};


/**
 * @class AnchorTable
 *
 */
class GIDEON_CS_API AnchorTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(AnchorTable);

public:
	typedef sne::core::HashMap<AnchorCode, AnchorTemplate> AnchorMap;

public:
    virtual ~AnchorTable() {}

public:
    virtual const AnchorTemplate* getAnchorTemplate(AnchorCode code) const = 0;

    virtual const AnchorMap& getAnchorMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define ANCHOR_TABLE gideon::datatable::AnchorTable::instance()
