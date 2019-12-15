#include "DataTablePCH.h"
#include <gideon/cs/datatable/CharacterStatusTable.h>

namespace gideon { namespace datatable {


SNE_DEFINE_SINGLETON(CharacterStatusTable);


bool CharacterStatusTable::applyCreatureStatusInfo(CharacterClass characterClass, BaseStatus& baseStatus, CreatureLevel cl, LevelStep ls)
{
    // TODO: 2차 직업 스탯 추가
    CharacterClass convertedcharacterClass = characterClass;
    if (isSecondClass(characterClass)) {
        convertedcharacterClass = toFirstClass(characterClass);
    }

    const gdt::character_status_t* characterStatus = getCharacterStatus(convertedcharacterClass, cl, ls);
    if (! characterStatus) {
        //assert(false);
        return false;
    }

    baseStatus[bsiStrength] = characterStatus->strength();
    baseStatus[bsiDexterity] = characterStatus->agility();
    baseStatus[bsiIntellect] = characterStatus->intellect();
    baseStatus[bsiEnergy] = characterStatus->energy();
    
    return true;
}


bool CharacterStatusTable::applyCreatureStatusInfo(CharacterClass characterClass,
    BaseStatus& baseStatus, CreatureLevel orgCl, LevelStep orgLs, CreatureLevel newCl, LevelStep newLs)
{
    // TODO: 2차 직업 스탯 추가
    CharacterClass convertedcharacterClass = characterClass;
    if (isSecondClass(characterClass)) {
        convertedcharacterClass = toFirstClass(characterClass);
    }

    const gdt::character_status_t* orgCharacterStatus =
        getCharacterStatus(convertedcharacterClass, orgCl, orgLs);
    if (! orgCharacterStatus) {
        assert(false);
        return false;
    }

    const gdt::character_status_t* newCharacterStatus =
        getCharacterStatus(convertedcharacterClass, newCl, newLs);
    if (! newCharacterStatus) {
        assert(false);
        return false;
    }

    baseStatus[bsiStrength] += newCharacterStatus->strength();
    baseStatus[bsiDexterity] += newCharacterStatus->agility();
    baseStatus[bsiIntellect] += newCharacterStatus->intellect();
    baseStatus[bsiEnergy] += newCharacterStatus->energy();

    baseStatus[bsiStrength] -= orgCharacterStatus->strength();
    baseStatus[bsiDexterity] -= orgCharacterStatus->agility();
    baseStatus[bsiIntellect] -= orgCharacterStatus->intellect();
    baseStatus[bsiEnergy] -= orgCharacterStatus->energy();

    return true;
}

bool CharacterStatusTable::applyCreatureStatusInfo(CharacterClass orgClass, 
    CharacterClass newClass, BaseStatus& baseStatus, CreatureLevel cl, LevelStep ls)
{
    // TODO: 2차 직업 스탯 추가
    CharacterClass convertedOrgClass = orgClass;
    if (isSecondClass(orgClass)) {
        convertedOrgClass = toFirstClass(orgClass);
    }
    CharacterClass convertedNewClass = newClass;
    if (isSecondClass(newClass)) {
        convertedNewClass = toFirstClass(newClass);
    }

    const gdt::character_status_t* orgCharacterStatus = getCharacterStatus(convertedOrgClass, cl, ls);
    if (! orgCharacterStatus) {
        assert(false);
        return false;
    }

    const gdt::character_status_t* newCharacterStatus = getCharacterStatus(convertedNewClass, cl, ls);
    if (! newCharacterStatus) {
        assert(false);
        return false;
    }

    baseStatus[bsiStrength] += newCharacterStatus->strength();
    baseStatus[bsiDexterity] += newCharacterStatus->agility();
    baseStatus[bsiIntellect] += newCharacterStatus->intellect();
    baseStatus[bsiEnergy] += newCharacterStatus->energy();

    baseStatus[bsiStrength] -= orgCharacterStatus->strength();
    baseStatus[bsiDexterity] -= orgCharacterStatus->agility();
    baseStatus[bsiIntellect] -= orgCharacterStatus->intellect();
    baseStatus[bsiEnergy] -= orgCharacterStatus->energy();

    return true;
}

}} // namespace gideon { namespace datatable {
