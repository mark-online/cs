#pragma once

#include <gideon/cs/shared/data/StatusInfo.h>
#include <gideon/cs/shared/data/EffectInfo.h>


namespace gideon { namespace datatable {

inline void applyStatus(CreatureStatusInfo& gameStatus, EffectScriptType script, uint32_t value, bool isUnapply)
{
    value = isUnapply ? value * -1 : value;
    switch (script) {
    case estStrengthUp:
        gameStatus.baseStatus_[bsiStrength] += value; 
        break;
    case estStrengthDown:
        gameStatus.baseStatus_[bsiStrength] -= value;
        break;
    case estDexterityUp:
        gameStatus.baseStatus_[bsiDexterity] += value;
        break;
    case estDexterityDown:
        gameStatus.baseStatus_[bsiDexterity] -= value;
        break;
    case estIntellectUp:
        gameStatus.baseStatus_[bsiIntellect] += value;
        break;
    case estIntellectDown:
        gameStatus.baseStatus_[bsiIntellect] -= value;
        break;
    case estEnergyUp:
        gameStatus.baseStatus_[bsiEnergy] += value;
        break;
    case estEnergyDown:
        gameStatus.baseStatus_[bsiEnergy] -= value;
        break;
    case estMinAttackUp:
        gameStatus.attackPowers_[apiMinAttack] += value;
        break;
    case estMinAttackDown:
        gameStatus.attackPowers_[apiMinAttack] -= value;
        break;
    case estMaxAttackUp:
        gameStatus.attackPowers_[apiMaxAttack] += value;
        break;
    case estMaxAttackDown:
        gameStatus.attackPowers_[apiMaxAttack] -= value;
        break;
    case estHpCapacityUp:
        gameStatus.points_.hp_ = toHitPoint(gameStatus.points_.hp_ + value);
        break;
    case estHpCapacityDown:
        gameStatus.points_.hp_ = toHitPoint(gameStatus.points_.hp_ - value);
        break;
    case estMpCapacityUp:
        gameStatus.points_.mp_ = toManaPoint(gameStatus.points_.mp_ + value);
        break;
    case estMpCapacityDown:
        gameStatus.points_.mp_ = toManaPoint(gameStatus.points_.mp_ - value);
        break;
    case estPhysicalUp:
        gameStatus.attackPowers_[apiPhysical] += value;
        break;
    case estPhysicalDown:
        gameStatus.attackPowers_[apiPhysical] -= value;
        break;
    case estMagicUp:
        gameStatus.attackPowers_[apiMagic] += value;
        break;
    case estMagicDown:
        gameStatus.attackPowers_[apiMagic] -= value;
        break;
    case estHitRateUp:
        gameStatus.attackStatus_[atsiHitRate] += static_cast<int16_t>(value);
        break;
    case estHitRateDown:
        gameStatus.attackStatus_[atsiHitRate] -= static_cast<int16_t>(value);
        break;
    case estPhysicalCriticalRateUp:
        gameStatus.attackStatus_[atsiPhysicalCriticalRate] += static_cast<int16_t>(value);
        break;
    case estPhysicalCriticalRateDown:
        gameStatus.attackStatus_[atsiPhysicalCriticalRate] -= static_cast<int16_t>(value);
        break;
    case estMagicCriticalRateUp:
        gameStatus.attackStatus_[atsiMagicCriticalRate] += static_cast<int16_t>(value);
        break;
    case estMagicCriticalRateDown:
        gameStatus.attackStatus_[atsiMagicCriticalRate] -= static_cast<int16_t>(value);
        break;
    case estBlockRateUp:
        gameStatus.defenceStatus_[dsiBlockRate] += static_cast<int16_t>(value);
        break;
    case estBlockRateDown:
        gameStatus.defenceStatus_[dsiBlockRate] -= static_cast<int16_t>(value);
        break;
    case estDodgeRateUp:
        gameStatus.defenceStatus_[dsiDodgeRate] += static_cast<int16_t>(value);
        break;
    case estDodgeRateDown:
        gameStatus.defenceStatus_[dsiDodgeRate] -= static_cast<int16_t>(value);
        break;
    case estDefenceUp:
        gameStatus.defenceStatus_[dsiDefence] += static_cast<int16_t>(value);
        break;
    case estDefenceDown:
        gameStatus.defenceStatus_[dsiDefence] -= static_cast<int16_t>(value);
        break;
    case estLightUp:
        gameStatus.attributes_[abiLight] += static_cast<int16_t>(value);
        break;
    case estDarkUp:
        gameStatus.attributes_[abiDark] += static_cast<int16_t>(value);
        break;
    case estFireUp:
        gameStatus.attributes_[abiFire] += static_cast<int16_t>(value);
        break;
    case estIceUp:
        gameStatus.attributes_[abiIce] += static_cast<int16_t>(value);
        break;
    case estLightDown:
        gameStatus.attributes_[abiLight] -= static_cast<int16_t>(value);
        break;
    case estDarkDown:
        gameStatus.attributes_[abiDark] -= static_cast<int16_t>(value);
        break;
    case estFireDown:
        gameStatus.attributes_[abiFire] -= static_cast<int16_t>(value);
        break;
    case estIceDown:
        gameStatus.attributes_[abiIce] -= static_cast<int16_t>(value);
        break;
    case estAllAttributeUp:
        gameStatus.attributes_[abiLight] += static_cast<int16_t>(value);;
        gameStatus.attributes_[abiDark] += static_cast<int16_t>(value);
        gameStatus.attributes_[abiFire] += static_cast<int16_t>(value);
        gameStatus.attributes_[abiIce] += static_cast<int16_t>(value);
        break;
    case estAllAttributeDown:
        gameStatus.attributes_[abiLight] -= static_cast<int16_t>(value);;
        gameStatus.attributes_[abiDark] -= static_cast<int16_t>(value);
        gameStatus.attributes_[abiFire] -= static_cast<int16_t>(value);
        gameStatus.attributes_[abiIce] -= static_cast<int16_t>(value);
        break;
    case estLightResistUp:
        gameStatus.attributeResists_[abiLight] += static_cast<int16_t>(value);
        break;
    case estDarkResistUp:
        gameStatus.attributeResists_[abiDark] += static_cast<int16_t>(value);
        break;
    case estFireResistUp:
        gameStatus.attributeResists_[abiFire] += static_cast<int16_t>(value);
        break;
    case estIceResistUp:
        gameStatus.attributeResists_[abiIce] += static_cast<int16_t>(value);
        break;
    case estAllAttributeResistUp:
        gameStatus.attributeResists_[abiLight] += static_cast<int16_t>(value);
        gameStatus.attributeResists_[abiDark] += static_cast<int16_t>(value);
        gameStatus.attributeResists_[abiFire] += static_cast<int16_t>(value);
        gameStatus.attributeResists_[abiIce] += static_cast<int16_t>(value);
        break;
    case estLightResistDown:
        gameStatus.attributeResists_[abiLight] -= static_cast<int16_t>(value);
        break;
    case estDarkResistDown:
        gameStatus.attributeResists_[abiDark] -= static_cast<int16_t>(value);
        break;
    case estFireResistDown:
        gameStatus.attributeResists_[abiFire] -= static_cast<int16_t>(value);
        break;
    case estIceResistDown:
        gameStatus.attributeResists_[abiIce] -= static_cast<int16_t>(value);
        break;
    case estAllAttributeResistDown:
        gameStatus.attributeResists_[abiLight] -= static_cast<int16_t>(value);
        gameStatus.attributeResists_[abiDark] -= static_cast<int16_t>(value);
        gameStatus.attributeResists_[abiFire] -= static_cast<int16_t>(value);
        gameStatus.attributeResists_[abiIce] -= static_cast<int16_t>(value);
        break;
    }
}


}} // namespace gideon { namespace datatable {