#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/datatable/template/equip_table.hxx>
#include <gideon/cs/shared/data/EquipmentInfo.h>
#include <gideon/cs/shared/data/CreatureStatusInfo.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>
#include "../shared/data/NpcTalkingInfo.h"

namespace gideon {
struct CharacterInfo;
struct CreatureStatusInfo;
} // namespace gideon {

namespace gideon { namespace datatable {

/**
 * @class EquipTable
 *
 */
class GIDEON_CS_API EquipTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(EquipTable);

public:
    typedef sne::core::HashMap<EquipCode, const gdt::equip_t*> EquipMap;

public:
    virtual ~EquipTable() {}

public:
    virtual const gdt::equip_t* getEquip(EquipCode code) const = 0;

    virtual const EquipMap& getEquipMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;

public:
    /// 장착 장비에 스텟 능력치를 적용한다.
    bool applyCreatureStatusInfo(CreatureStatusInfo& gameStats, 
        const InventoryInfo& inventory, const CharacterEquipments& equipments);

    /// 특정 장비의 스탯을 적용한다
    bool applyCreatureStatusInfoByEquip(CreatureStatusInfo& gameStats,
        EquipCode equipCode, const EquipItemInfo& equipItemInfo);

    /// 특정 장비의 스탯을 적용한다
    bool applyCreatureStatusInfoByUnequip(CreatureStatusInfo& gameStats,
        EquipCode equipCode, const EquipItemInfo& equipItemInfo);

};

}} // namespace gideon { namespace datatable {

#define EQUIP_TABLE gideon::datatable::EquipTable::instance()
