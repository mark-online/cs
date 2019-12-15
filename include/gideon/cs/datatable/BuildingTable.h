#pragma once

#include "AnchorTemplate.h"
#include <gideon/cs/datatable/template/building_table.hxx>
#include <gideon/cs/shared/data/BuildingInfo.h>
#include <gideon/cs/shared/data/DominionInfo.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {


struct InvincibleItemInfos
{
    sec_t cashInvincibleSec_;
    BaseItemInfo cashInvincibleInfo_;
    sec_t freeInvincibleSec_;
    BaseItemInfos freeInvincibleInfos_; 

    InvincibleItemInfos() : 
        cashInvincibleSec_(0),
        freeInvincibleSec_(0) 
    {
    }
};


/***
 * @class BuildingTemplate
 ***/
class BuildingTemplate
{
public:
    BuildingTemplate(const gdt::building_t& buildingInfo) :
        buildingInfo_(&buildingInfo)
    {
        initBaseBuildingInfo();
        initCheckInfo();
        initFoundation();
        initMaterials();
        initFuels();
        initInvincibleItemInfos();
        initSkills();
        initFunctionScripts();
    }

    ~BuildingTemplate() {}

    const gdt::building_t& getBuildingInfo() const {
        return *buildingInfo_;
    }

    uint8_t getStackCount() const {
        return static_cast<uint8_t>(buildingInfo_->stack_count());
    }

    bool isCoreBuilding() const {
        return buildingInfo_->is_core_building();
    }

    const wchar_t* getBuildingIcon() const {
        return buildingInfo_->building_icon().c_str();
    }

    const bool canTeleport() const {
        for (const BuildingFunctionScript script : buildingFunctionScripts_) {
            if (script == bfsTeleport) {
                return true;
            }
        }
        return false;
	}

    const bool canToggleDoor() const {
        for (const BuildingFunctionScript script : buildingFunctionScripts_) {
            if (script == bfsDoor) {
                return true;
            }
        }
        return false;
    }

    uint8_t getMercenaryCount() const {
        return buildingInfo_->mercenary_count();
    }

    float getModelingRadius() const {
        return baseBuildingInfo_.modelingRadius_ / 100.0f;
    }

    BuildingCode getBuildingCode() const {
        return baseBuildingInfo_.dataCode_;
    }

	GameTime getCooltime() const {
		return buildingInfo_->cool_time();
	}

    const BaseAnchorInfo& getBaseAnchorInfo() const {
        return baseBuildingInfo_;
    }

    const AnchorSkillInfos& getSkillInfos() const {
        return skillInfos_;
    }

    const CheckAnchorInfo& getCheckAnchorInfo() const {
        return checkInfo_;
    }

    const BuildingFoundationInfo& getBuildingFoundationInfo() const {
        return foundationInfo_;
    }

    const BaseItemInfos& getMaterials() const {
        return materials_;
    }
    
    const BuildingFuelItems& getFuelItems() const {
        return fuelItems_;
    }

    const BuildingFuelItem* getFuelItem(DataCode dataCode) const {
        for (const BuildingFuelItem& item : fuelItems_) {
            if (item.consumeItem_.itemCode_ == dataCode) {
                return &item;
            }
        }
        return nullptr;
    }

    bool isFuelItem(DataCode dataCode) const {
        for (const BuildingFuelItem& item : fuelItems_) {
            if (item.consumeItem_.itemCode_ == dataCode) {
                return true;
            }
        }
        return false;
    }

    bool isInvincibleItem(DataCode dataCode) const {
        if (invincibleItemInfos_.cashInvincibleSec_ > 0) {
            if (invincibleItemInfos_.cashInvincibleInfo_.itemCode_ == dataCode) {
                return true;
            }
        }
        if (invincibleItemInfos_.freeInvincibleSec_ > 0) {
            for (const BaseItemInfo& item : invincibleItemInfos_.freeInvincibleInfos_) {
                if (item.itemCode_ == dataCode) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isMaterials(DataCode dataCode) const {
        for (const BaseItemInfo& item : materials_) {
            if (item.itemCode_ == dataCode) {
                return true;
            }
        }
        return false;
    }

    const InvincibleItemInfos& getInvincibleItemInfos() const {
        return invincibleItemInfos_;
    }

    uint32_t getProduceResourcesCode() const {
        return buildingInfo_->produce_resources_code();
    }

    uint32_t getSelectProduceResourcesCode() const {
        return buildingInfo_->select_produce_resources_code();
    }

    uint8_t getMercenaryInventoryCount() const {
        return static_cast<uint8_t>(buildingInfo_->mercenary_inventory_count());
    }

    uint8_t getBuildingInventoryCount() const {
        return static_cast<uint8_t>(buildingInfo_->inventory_count());
    }

    uint8_t getProductionInventoryCount() const {
        return static_cast<uint8_t>(buildingInfo_->production_inventory_count());
    }

    uint8_t getSelectProductionInventoryCount() const {
        return static_cast<uint8_t>(buildingInfo_->select_production_inventory_count());
    }

    uint8_t getSelectProductionCount() const {
        return static_cast<uint8_t>(buildingInfo_->select_produce_count());
    }

    uint32_t getSelectProducionCode() const {
        return buildingInfo_->select_produce_resources_code();
    }

    bool canBindRecall() const {
        for (const BuildingFunctionScript script : buildingFunctionScripts_) {
            if (script == bfsBindRecall) {
                return true;
            }
        }
        return false;
    }

    bool canManufacture() const {
        for (const BuildingFunctionScript script : buildingFunctionScripts_) {
            if (script == bfsManufacture) {
                return true;
            }
        }
        return false;
    }

    bool canMercenaryStore() const {
        for (const BuildingFunctionScript script : buildingFunctionScripts_) {
            if (script == bfsMercenary) {
                return true;
            }
        }
        return false;
    }

    const AnchorSkillInfo& getSkillInfo(DataCode skillCode) const {
        for (const AnchorSkillInfo& info : skillInfos_) {
            if (info.skillCode_ == skillCode) {
                return info;
            }
        }
        static const AnchorSkillInfo nullObj;
        return nullObj;
    }

    const uint32_t getBuildSec() const {
        return buildingInfo_->build_sec();
    }

    const uint32_t getIncibleCooltimeSec() const {
        return buildingInfo_->invincible_cooltime_sec();
    }

    const uint32_t getFoundationLiveSec() const {
        return buildingInfo_->foundation_live_sec();
    }

    const uint32_t getLimitActiveSec() const {
        return buildingInfo_->limit_active_sec();
    }

    const wchar_t* getModeling() const {
        return buildingInfo_->modeling_name().c_str();
    }

    const wchar_t* getBuildAnimation() const {
        return buildingInfo_->build_animation().c_str();
    }

    const wchar_t* getCompleteModeling() const {
        return buildingInfo_->complete_modeling().c_str();
    }

    const wchar_t* getBrokenAnimation() const {
        return buildingInfo_->broken_animation().c_str();
    }

	const wchar_t* getBuildEffectName() const {
		return buildingInfo_->build_effect().c_str();
	}

	const wchar_t* getBrokenEffectName() const {
		return buildingInfo_->broken_effect().c_str();
	}

    bool canDestory() const {
        return buildingInfo_->can_destory() == 1;
    }

    float getCompleteResistRate() const {
        return static_cast<float>(buildingInfo_->complete_regist());
    }

    float getFoundationResistRate() const {
        return static_cast<float>(buildingInfo_->foundation_regist());
    }

	DominionType getDominionType() const {
		return toDominionType(buildingInfo_->dominon_type());
	}

    bool canForgeFunction() const {
        for (const BuildingFunctionScript script : buildingFunctionScripts_) {
            if (canForge(script)) {
                return true;
            }
        }
        return false;
	}

    bool canAutoForgeFunction() const {
        for (const BuildingFunctionScript script : buildingFunctionScripts_) {
            if (script == bfsAutoForge) {
                return true;
            }
        }
        return false;
    }

    bool canBankFunction() const {
        for (const BuildingFunctionScript script : buildingFunctionScripts_) {
            if (canBank(script)) {
                return true;
            }
        }
        return false;
    }

    bool canAutoBankFunction() const {
        for (const BuildingFunctionScript script : buildingFunctionScripts_) {
            if (script == bfsAutoForge) {
                return true;
            }
        }
        return false;
    }

    bool canMercenaryEmploymentFunction() const {
        for (const BuildingFunctionScript script : buildingFunctionScripts_) {
            if (script == bfsMercenary) {
                return true;
            }
        }
        return false;
    }

    void deleteBuildingInfo() {
        if (buildingInfo_) {
            delete buildingInfo_;
            buildingInfo_ = nullptr;
        }
    }
private:
    void initBaseBuildingInfo() {
        baseBuildingInfo_.dataCode_ = buildingInfo_->building_code();
        baseBuildingInfo_.ownerType_ = toBuildingOwnerType(buildingInfo_->anchor_owner());
        baseBuildingInfo_.modelingRadius_ = buildingInfo_->modeling_radius_size();
        baseBuildingInfo_.comleteRegist_ = buildingInfo_->complete_regist();
        baseBuildingInfo_.liveTime_ = buildingInfo_->limit_active_sec();
        baseBuildingInfo_.completeHp_ = toHitPoint(buildingInfo_->complete_health_point());
    }

    void initCheckInfo() {
        checkInfo_.checkCode1_ = buildingInfo_->check_building_code_1();
        checkInfo_.checkDistance1_ = static_cast<float>(buildingInfo_->check_distance_1() / 100.0f);
        checkInfo_.checkCode2_ = buildingInfo_->check_building_code_2();
        checkInfo_.checkDistance2_ = static_cast<float>(buildingInfo_->check_distance_2() / 100.0f);
    }

    void initFoundation() {
        foundationInfo_.foundationHp_ = toHitPoint(buildingInfo_->foundation_health_point());
        foundationInfo_.regist_ = buildingInfo_->foundation_regist();
        foundationInfo_.foundationLiveTime_ = buildingInfo_->foundation_live_sec();
        foundationInfo_.buildTime_ = buildingInfo_->build_sec();
    }

    void initMaterials() {
        const DataCode materialItemCode1 = buildingInfo_->building_materials_1();
        const DataCode materialItemCode2 = buildingInfo_->building_materials_2();
        const DataCode materialItemCode3 = buildingInfo_->building_materials_3();
        const DataCode materialItemCode4 = buildingInfo_->building_materials_4();
        const DataCode materialItemCode5 = buildingInfo_->building_materials_5();
        if (isValidDataCode(materialItemCode1)) {
            materials_.push_back(BaseItemInfo(materialItemCode1, 
                static_cast<uint8_t>(buildingInfo_->building_materials_count_1())));
        }
        if (isValidDataCode(materialItemCode2)) {
            materials_.push_back(BaseItemInfo(materialItemCode2, 
                static_cast<uint8_t>(buildingInfo_->building_materials_count_2())));
        }
        if (isValidDataCode(materialItemCode3)) {
            materials_.push_back(BaseItemInfo(materialItemCode3, 
                static_cast<uint8_t>(buildingInfo_->building_materials_count_3())));
        }
        if (isValidDataCode(materialItemCode4)) {
            materials_.push_back(BaseItemInfo(materialItemCode4, 
                static_cast<uint8_t>(buildingInfo_->building_materials_count_4())));
        }
        if (isValidDataCode(materialItemCode5)) {
            materials_.push_back(BaseItemInfo(materialItemCode5,
                static_cast<uint8_t>(buildingInfo_->building_materials_count_5())));
        }
    }

    void initFuels() {
        const DataCode fuelItemCode1 = buildingInfo_->consume_item_code_1();
        const DataCode fuelItemCode2 = buildingInfo_->consume_item_code_2();
        const DataCode fuelItemCode3 = buildingInfo_->consume_item_code_3();
        if (isValidDataCode(fuelItemCode1)) {
            fuelItems_.push_back(BuildingFuelItem(BaseItemInfo(fuelItemCode1, 
                static_cast<uint8_t>(buildingInfo_->consume_item_count_1())),
                buildingInfo_->consume_sec_1()));
        }
        if (isValidDataCode(fuelItemCode2)) {
            fuelItems_.push_back(BuildingFuelItem(BaseItemInfo(fuelItemCode2, 
                static_cast<uint8_t>(buildingInfo_->consume_item_count_2())),
                buildingInfo_->consume_sec_2()));
        }
        if (isValidDataCode(fuelItemCode3)) {
            fuelItems_.push_back(BuildingFuelItem(BaseItemInfo(fuelItemCode3, 
                static_cast<uint8_t>(buildingInfo_->consume_item_count_3())),
                buildingInfo_->consume_sec_3()));
        }
    }

    void initSkills() {
        StaticObjectSkillCode skillCode1 = buildingInfo_->so_skill_code_1();
        StaticObjectSkillCode skillCode2 = buildingInfo_->so_skill_code_2();
        StaticObjectSkillCode skillCode3 = buildingInfo_->so_skill_code_3();
        if (isValidStaticObjectSkillCode(skillCode1)) {
            skillInfos_.push_back(AnchorSkillInfo(skillCode1,
				toSoSkillCastType(buildingInfo_->so_skill_cast_type_1()), 
				buildingInfo_->auto_sec_1()));
        }
        if (isValidStaticObjectSkillCode(skillCode2)) {
            skillInfos_.push_back(AnchorSkillInfo(skillCode1,
				toSoSkillCastType(buildingInfo_->so_skill_cast_type_2()),
				buildingInfo_->auto_sec_2()));
        }
        if (isValidStaticObjectSkillCode(skillCode3)) {
            skillInfos_.push_back(AnchorSkillInfo(skillCode1, 
				toSoSkillCastType(buildingInfo_->so_skill_cast_type_2()),
				buildingInfo_->auto_sec_3()));
        }
    }


    void initInvincibleItemInfos() {
        sec_t cashInvincibleSec = buildingInfo_->cash_invincible_min() * 60;
        if (cashInvincibleSec > 0) {
            invincibleItemInfos_.cashInvincibleSec_ = cashInvincibleSec;
            invincibleItemInfos_.cashInvincibleInfo_.itemCode_ = buildingInfo_->cash_invincible_item_code();
            invincibleItemInfos_.cashInvincibleInfo_.itemCode_ = buildingInfo_->cash_invincible_item_count();
        }
        sec_t freeInvincibleSec = buildingInfo_->free_invincible_min() * 60;
        if (freeInvincibleSec > 0) {
            invincibleItemInfos_.freeInvincibleSec_ = freeInvincibleSec;
            DataCode freeInvincibleItemCode1 = buildingInfo_->free_invincible_item_code_1();
            if (isValidDataCode(freeInvincibleItemCode1)) {
                invincibleItemInfos_.freeInvincibleInfos_.push_back(
                    BaseItemInfo(freeInvincibleItemCode1, buildingInfo_->free_invincible_item_count_1()));
            }
            DataCode freeInvincibleItemCode2 = buildingInfo_->free_invincible_item_code_2();
            if (isValidDataCode(freeInvincibleItemCode2)) {
                invincibleItemInfos_.freeInvincibleInfos_.push_back(
                    BaseItemInfo(freeInvincibleItemCode2, buildingInfo_->free_invincible_item_count_2()));
            }
            DataCode freeInvincibleItemCode3 = buildingInfo_->free_invincible_item_code_3();
            if (isValidDataCode(freeInvincibleItemCode3)) {
                invincibleItemInfos_.freeInvincibleInfos_.push_back(
                    BaseItemInfo(freeInvincibleItemCode3, buildingInfo_->free_invincible_item_count_3()));
            }            
        }
    }

    void initFunctionScripts() {
        buildingFunctionScripts_.push_back(toBuildingFunctionScript(buildingInfo_->function_script_1()));
        buildingFunctionScripts_.push_back(toBuildingFunctionScript(buildingInfo_->function_script_2()));
        buildingFunctionScripts_.push_back(toBuildingFunctionScript(buildingInfo_->function_script_3()));
    }

private:
    const gdt::building_t* buildingInfo_;

    BaseAnchorInfo baseBuildingInfo_;
    CheckAnchorInfo checkInfo_;
    BuildingFoundationInfo foundationInfo_;
    BaseItemInfos materials_; // 재료
    BuildingFuelItems fuelItems_; // 운영 연료
    AnchorSkillInfos skillInfos_;
    InvincibleItemInfos invincibleItemInfos_;
    BuildingFunctionScripts buildingFunctionScripts_;

};


/**
 * @class BuildingTable
 *
 */
class GIDEON_CS_API BuildingTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(BuildingTable);

public:
	typedef sne::core::HashMap<BuildingCode, BuildingTemplate> BuildingMap;

public:
    virtual ~BuildingTable() {}

public:
    virtual const BuildingTemplate* getBuildingTemplate(BuildingCode code) const = 0;

    virtual const BuildingMap& getBuildingMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define BUILDING_TABLE gideon::datatable::BuildingTable::instance()
