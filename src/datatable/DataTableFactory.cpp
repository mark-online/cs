#include "DataTablePCH.h"
#include <gideon/cs/datatable/DataTableFactory.h>
#include "PropertyTableImpl.h"
#include "CharacterStatusTableImpl.h"
#include "WorldMapTableImpl.h"
#include "RegionTableImpl.h"
#include "RegionCoordinatesImpl.h"
#include "RegionSpawnTableImpl.h"
#include "PositionSpawnTableImpl.h"
#include "EquipTableImpl.h"
#include "AccessoryTableImpl.h"
#include "PlayerActiveSkillTableImpl.h"
#include "ItemActiveSkillTableImpl.h"
#include "SOActiveSkillTableImpl.h"
#include "PlayerPassiveSkillTableImpl.h"
#include "NpcActiveSkillTableImpl.h"
#include "SkillEffectTableImpl.h"
#include "ReprocessTableImpl.h"
#include "NpcTableImpl.h"
#include "ElementTableImpl.h"
#include "FragmentTableImpl.h"
#include "ItemDropTableImpl.h"
#include "GemTableImpl.h"
#include "RecipeTableImpl.h"
#include "ExpTableImpl.h"
#include "WorldDropTableImpl.h"
#include "WorldDropSuffixTableImpl.h"
#include "RandomDungeonTableImpl.h"
#include "QuestTableImpl.h"
#include "QuestItemTableImpl.h"
#include "QuestKillMissionTableImpl.h"
#include "QuestObtainMissionTableImpl.h"
#include "QuestProbeMissionTableImpl.h"
#include "QuestTransportMissionTableImpl.h"
#include "HarvestTableImpl.h"
#include "TreasureTableImpl.h"
#include "NpcSellTableImpl.h"
#include "NpcBuyTableImpl.h"
#include "QuestContentsMissionTableImpl.h"
#include "AnchorTableImpl.h"
#include "BuildingTableImpl.h"
#include "EntityPathTableImpl.h"
#include "ResourcesProductionTableImpl.h"
#include "HelpTableImpl.h"
#include "ArenaTableImpl.h"
#include "DeviceTableImpl.h"
#include "QuestActivationTableMissionImpl.h"
#include "FactionTableImpl.h"
#include "L10nTableImpl.h"
#include "EventTriggerTableImpl.h"
#include "GliderTableImpl.h"
#include "VehicleTableImpl.h"
#include "HarnessTableImpl.h"
#include "ActionTableImpl.h"
#include "NpcFormationTableImpl.h"
#include "NpcTalkingTableImpl.h"
#include "DominionRegionTableImpl.h"
#include "SelectRecipeProductionTableImpl.h"
#include "BuildingGuardTableImpl.h"
#include "BuildingGuardSellTableImpl.h"
#include "WorldEventTableImpl.h"
#include "WorldEventMissionTableImpl.h"
#include "WorldEventInvaderSpawnTableImpl.h"
#include "WorldEventMissionSpawnTableImpl.h"
#include "DevildomGateTableImpl.h"
#include "ItemOptionTableImpl.h"
#include "ItemSuffixTableImpl.h"
#include "CharacterDefaultItemTableImpl.h"
#include "CharacterDefaultSkillTableImpl.h"
#include "CharacterTitleTableImpl.h"
#include "AchievementTableImpl.h"
#include "GuildLevelTableImpl.h"
#include "GuildSkillTableImpl.h"
#include "FunctionTableImpl.h"

namespace gideon { namespace datatable {

SNE_DEFINE_SINGLETON(PropertyTable);
SNE_DEFINE_SINGLETON(WorldMapTable);
SNE_DEFINE_SINGLETON(ReprocessTable);
SNE_DEFINE_SINGLETON(NpcTable);
SNE_DEFINE_SINGLETON(ElementTable);
SNE_DEFINE_SINGLETON(ItemDropTable);
SNE_DEFINE_SINGLETON(FragmentTable);
SNE_DEFINE_SINGLETON(GemTable);
SNE_DEFINE_SINGLETON(RecipeTable);
SNE_DEFINE_SINGLETON(ExpTable);
SNE_DEFINE_SINGLETON(RandomDungeonTable);
SNE_DEFINE_SINGLETON(QuestTable);
SNE_DEFINE_SINGLETON(QuestItemTable);
SNE_DEFINE_SINGLETON(QuestKillMissionTable);
SNE_DEFINE_SINGLETON(QuestObtainMissionTable);
SNE_DEFINE_SINGLETON(QuestProbeMissionTable);
SNE_DEFINE_SINGLETON(QuestTransportMissionTable);
SNE_DEFINE_SINGLETON(HarvestTable);
SNE_DEFINE_SINGLETON(TreasureTable);
SNE_DEFINE_SINGLETON(NpcSellTable);
SNE_DEFINE_SINGLETON(NpcBuyTable);
SNE_DEFINE_SINGLETON(AnchorTable);
SNE_DEFINE_SINGLETON(BuildingTable);
SNE_DEFINE_SINGLETON(SelectRecipeProductionTable);
SNE_DEFINE_SINGLETON(ResourcesProductionTable);
SNE_DEFINE_SINGLETON(HelpTable);
SNE_DEFINE_SINGLETON(ArenaTable);
SNE_DEFINE_SINGLETON(FactionTable);
SNE_DEFINE_SINGLETON(EventTriggerTable);
SNE_DEFINE_SINGLETON(DeviceTable);
SNE_DEFINE_SINGLETON(QuestActivationMissionTable);
SNE_DEFINE_SINGLETON(GliderTable);
SNE_DEFINE_SINGLETON(VehicleTable);
SNE_DEFINE_SINGLETON(HarnessTable);
SNE_DEFINE_SINGLETON(ActionTable);
SNE_DEFINE_SINGLETON(NpcFormationTable);
SNE_DEFINE_SINGLETON(NpcTalkingTable);
SNE_DEFINE_SINGLETON(QuestContentsMissionTable);
SNE_DEFINE_SINGLETON(DominionRegionTable);
SNE_DEFINE_SINGLETON(WorldDropTable);
SNE_DEFINE_SINGLETON(WorldDropSuffixTable);
SNE_DEFINE_SINGLETON(BuildingGuardTable)
SNE_DEFINE_SINGLETON(BuildingGuardSellTable)
SNE_DEFINE_SINGLETON(WorldEventTable)
SNE_DEFINE_SINGLETON(WorldEventMissionTable)
SNE_DEFINE_SINGLETON(WorldEventInvaderSpawnTable)
SNE_DEFINE_SINGLETON(WorldEventMissionSpawnTable)
SNE_DEFINE_SINGLETON(DevildomGateTable);
SNE_DEFINE_SINGLETON(NpcActiveSkillTable);
SNE_DEFINE_SINGLETON(PlayerActiveSkillTable);
SNE_DEFINE_SINGLETON(ItemActiveSkillTable);
SNE_DEFINE_SINGLETON(SOActiveSkillTable);
SNE_DEFINE_SINGLETON(PlayerPassiveSkillTable)
SNE_DEFINE_SINGLETON(SkillEffectTable);
SNE_DEFINE_SINGLETON(ItemOptionTable)
SNE_DEFINE_SINGLETON(ItemSuffixTable);
SNE_DEFINE_SINGLETON(CharacterDefaultItemTable);
SNE_DEFINE_SINGLETON(CharacterDefaultSkillTable);
SNE_DEFINE_SINGLETON(CharacterTitleTable);
SNE_DEFINE_SINGLETON(AchievementTable);
SNE_DEFINE_SINGLETON(GuildLevelTable);
SNE_DEFINE_SINGLETON(GuildSkillTable);
SNE_DEFINE_SINGLETON(FunctionTable);


std::unique_ptr<PropertyTable> DataTableFactory::createPropertyTable(std::istream& is)
{
    return std::make_unique<PropertyTableImpl>(is);
}


std::unique_ptr<CharacterStatusTable> DataTableFactory::createCharacterStatusTable(std::istream& is)
{
    return std::make_unique<CharacterStatusTableImpl>(is);
}


std::unique_ptr<WorldMapTable> DataTableFactory::createWorldMapTable(std::istream& is)
{
    return std::make_unique<WorldMapTableImpl>(is);
}


std::unique_ptr<RegionTable> DataTableFactory::createRegionTable(std::istream& is)
{
    return std::make_unique<RegionTableImpl>(is);
}


std::unique_ptr<RegionCoordinates> DataTableFactory::createRegionCoordinates(std::istream& is)
{
    return std::make_unique<RegionCoordinatesImpl>(is);
}


std::unique_ptr<RegionSpawnTable> DataTableFactory::createRegionSpawnTable(std::istream& is)
{
    return std::make_unique<RegionSpawnTableImpl>(is);
}


std::unique_ptr<PositionSpawnTable> DataTableFactory::createPositionSpawnTable(std::istream& is)
{
    return std::make_unique<PositionSpawnTableImpl>(is);
}


std::unique_ptr<EquipTable> DataTableFactory::createEquipTable(std::istream& is)
{
    return std::make_unique<EquipTableImpl>(is);
}


std::unique_ptr<ReprocessTable> DataTableFactory::createReprocessTable(std::istream& is)
{
    return std::make_unique<ReprocessTableImpl>(is);
}


std::unique_ptr<NpcTable> DataTableFactory::createNpcTable(std::istream& is)
{
    return std::make_unique<NpcTableImpl>(is);
}


std::unique_ptr<ElementTable> DataTableFactory::createElementTable(std::istream& is)
{
	return std::make_unique<ElementTableImpl>(is);
}


std::unique_ptr<FragmentTable> DataTableFactory::createFragmentTable(std::istream& is)
{
    return std::make_unique<FragmentTableImpl>(is);
}


std::unique_ptr<AccessoryTable> DataTableFactory::createAccessoryTable(std::istream& is)
{
    return std::make_unique<AccessoryTableImpl>(is);
}


std::unique_ptr<ItemDropTable> DataTableFactory::createItemDropTable(std::istream& is)
{
	return std::make_unique<ItemDropTableImpl>(is);
}



std::unique_ptr<GemTable> DataTableFactory::createGemTable(std::istream& is)
{
    return std::make_unique<GemTableImpl>(is);
}


std::unique_ptr<RecipeTable> DataTableFactory::createRecipeTable(std::istream& is)
{
    return std::make_unique<RecipeTableImpl>(is);
}


std::unique_ptr<ExpTable> DataTableFactory::createExpTable(std::istream& is)
{
    return std::make_unique<ExpTableImpl>(is); 
}


std::unique_ptr<RandomDungeonTable> DataTableFactory::createRandomDungeonTable(std::istream& is)
{
    return std::make_unique<RandomDungeonTableImpl>(is);
}


std::unique_ptr<QuestTable> DataTableFactory::createQuestTable(std::istream& is)
{
	return std::make_unique<QuestTableImpl>(is); 
}



std::unique_ptr<QuestItemTable> DataTableFactory::createQuestItemTable(std::istream& is)
{
    return std::make_unique<QuestItemTableImpl>(is); 
}


std::unique_ptr<QuestKillMissionTable> DataTableFactory::createQuestKillMissionTable(std::istream& is)
{
	return std::make_unique<QuestKillMissionTableImpl>(is);
}


std::unique_ptr<QuestActivationMissionTable> DataTableFactory::createQuestActivationMissionTable(std::istream& is)
{
    return std::make_unique<QuestActivationMissionTableImpl>(is); 
}


std::unique_ptr<QuestObtainMissionTable> DataTableFactory::createQuestObtainMissionTable(std::istream& is)
{
    return std::make_unique<QuestObtainMissionTableImpl>(is);
}


std::unique_ptr<QuestProbeMissionTable> DataTableFactory::createQuestProbeMissionTable(std::istream& is)
{
    return std::make_unique<QuestProbeMissionTableImpl>(is);
}


std::unique_ptr<QuestTransportMissionTable> DataTableFactory::createQuestTransportMissionTable(std::istream& is)
{
    return std::make_unique<QuestTransportMissionTableImpl>(is);
}


std::unique_ptr<QuestContentsMissionTable> DataTableFactory::createQuestContentsMissionTable(std::istream& is)
{
    return std::make_unique<QuestContentsMissionTableImpl>(is);
}


std::unique_ptr<HarvestTable> DataTableFactory::createHarvestTable(std::istream& is)
{
	return std::make_unique<HarvestTableImpl>(is); 
}


std::unique_ptr<TreasureTable> DataTableFactory::createTreasureTable(std::istream& is)
{
	return std::make_unique<TreasureTableImpl>(is); 
}


std::unique_ptr<NpcSellTable> DataTableFactory::createNpcSellTable(std::istream& is)
{
	return std::make_unique<NpcSellTableImpl>(is); 
}


std::unique_ptr<NpcBuyTable> DataTableFactory::createNpcBuyTable(std::istream& is)
{
	return std::make_unique<NpcBuyTableImpl>(is); 
}


std::unique_ptr<AnchorTable> DataTableFactory::createAnchorTable(std::istream& is)
{
    return std::make_unique<AnchorTableImpl>(is); 
}


std::unique_ptr<BuildingTable> DataTableFactory::createBuildingTable(std::istream& is)
{
    return std::make_unique<BuildingTableImpl>(is); 
}


std::unique_ptr<SelectRecipeProductionTable> DataTableFactory::createSelectRecipeProductionTable(std::istream& is)
{
    return std::make_unique<SelectRecipeProductionTableImpl>(is); 
}


std::unique_ptr<ResourcesProductionTable> DataTableFactory::createResourcesProductionTable(std::istream& is)
{
    return std::make_unique<ResourcesProductionTableImpl>(is);
}


std::unique_ptr<EntityPathTable> DataTableFactory::createEntityPathTable(std::istream& is)
{
    return std::make_unique<EntityPathTableImpl>(is); 
}


std::unique_ptr<HelpTable> DataTableFactory::createHelpTable(std::istream& is)
{
    return std::make_unique<HelpTableImpl>(is); 
}


std::unique_ptr<L10nTable> DataTableFactory::createL10nTable(std::istream& is)
{
    return std::make_unique<L10nTableImpl>(is); 
}


std::unique_ptr<ArenaTable> DataTableFactory::createArenaTable(std::istream& is)
{
    return std::make_unique<ArenaTableImpl>(is); 
}


std::unique_ptr<NpcActiveSkillTable> DataTableFactory::createNpcActiveSkillTable(std::istream& is)
{
    return std::make_unique<NpcActiveSkillTableImpl>(is, true);
}


std::unique_ptr<NpcActiveSkillTable> DataTableFactory::createNpcActiveSkillTableForServer(std::istream& is)
{
    return std::make_unique<NpcActiveSkillTableImpl>(is, false); 
}


std::unique_ptr<PlayerActiveSkillTable> DataTableFactory::createPlayerActiveSkillTable(std::istream& is)
{
    return std::make_unique<PlayerActiveSkillTableImpl>(is, true); 
}


std::unique_ptr<PlayerActiveSkillTable> DataTableFactory::createPlayerActiveSkillTableForServer(std::istream& is)
{
    return std::make_unique<PlayerActiveSkillTableImpl>(is, false); 
}


std::unique_ptr<ItemActiveSkillTable> DataTableFactory::createItemActiveSkillTable(std::istream& is)
{
    return std::make_unique<ItemActiveSkillTableImpl>(is, true); 
}


std::unique_ptr<ItemActiveSkillTable> DataTableFactory::createItemActiveSkillTableForServer(std::istream& is)
{
    return std::make_unique<ItemActiveSkillTableImpl>(is, false); 
}


std::unique_ptr<SOActiveSkillTable> DataTableFactory::createSOActiveSkillTable(std::istream& is)
{
    return std::make_unique<SOActiveSkillTableImpl>(is, true); 
}


std::unique_ptr<SOActiveSkillTable> DataTableFactory::createSOActiveSkillTableForServer(std::istream& is)
{
    return std::make_unique<SOActiveSkillTableImpl>(is, false); 
}


std::unique_ptr<PlayerPassiveSkillTable> DataTableFactory::createPlayerPassiveSkillTable(std::istream& is)
{
    return std::make_unique<PlayerPassiveSkillTableImpl>(is, true); 
}


std::unique_ptr<PlayerPassiveSkillTable> DataTableFactory::createPlayerPassiveSkillTableForServer(std::istream& is)
{
    return std::make_unique<PlayerPassiveSkillTableImpl>(is, false); 
}


std::unique_ptr<SkillEffectTable> DataTableFactory::createSkillEffectTable(std::istream& is)
{
    return std::make_unique<SkillEffectTableImpl>(is); 
}


std::unique_ptr<FactionTable> DataTableFactory::createFactionTable(std::istream& is)
{
    return std::make_unique<FactionTableImpl>(is); 
}


std::unique_ptr<EventTriggerTable> DataTableFactory::createEventTriggerTable(std::istream& is)
{
    return std::make_unique<EventTriggerTableImpl>(is); 
}


std::unique_ptr<DeviceTable> DataTableFactory::createDeviceTable(std::istream& is)
{
    return std::make_unique<DeviceTableImpl>(is); 
}


std::unique_ptr<GliderTable> DataTableFactory::createGliderTable(std::istream& is)
{
    return std::make_unique<GliderTableImpl>(is); 
}


std::unique_ptr<VehicleTable> DataTableFactory::createVehicleTable(std::istream& is)
{
	return std::make_unique<VehicleTableImpl>(is); 
}


std::unique_ptr<HarnessTable> DataTableFactory::createHarnessTable(std::istream& is)
{
	return std::make_unique<HarnessTableImpl>(is); 
}


std::unique_ptr<ActionTable> DataTableFactory::createActionTable(std::istream& is)
{
    return std::make_unique<ActionTableImpl>(is); 
}


std::unique_ptr<NpcFormationTable> DataTableFactory::createNpcFormationTable(std::istream& is)
{
    return std::make_unique<NpcFormationTableImpl>(is); 
}


std::unique_ptr<NpcTalkingTable> DataTableFactory::createNpcTalkingTable(std::istream& is)
{
    return std::make_unique<NpcTalkingTableImpl>(is); 
}


std::unique_ptr<DominionRegionTable> DataTableFactory::createDominionRegionTable(std::istream& is)
{
    return std::make_unique<DominionRegionTableImpl>(is); 
}


std::unique_ptr<WorldDropTable> DataTableFactory::createWorldDropTable(std::istream& is)
{
    return std::make_unique<WorldDropTableImpl>(is);
}


std::unique_ptr<WorldDropSuffixTable> DataTableFactory::createWorldDropSuffixTable(std::istream& is)
{
    return std::make_unique<WorldDropSuffixTableImpl>(is);
}


std::unique_ptr<BuildingGuardTable> DataTableFactory::createBuildingGuardTable(std::istream& is)
{
    return std::make_unique<BuildingGuardTableImpl>(is);
}


std::unique_ptr<BuildingGuardSellTable> DataTableFactory::createBuildingGuardSellTable(std::istream& is)
{
    return std::make_unique<BuildingGuardSellTableImpl>(is);
}


std::unique_ptr<WorldEventTable> DataTableFactory::createWorldEventTable(std::istream& is)
{
    return std::make_unique<WorldEventTableImpl>(is);
}


std::unique_ptr<WorldEventMissionTable> DataTableFactory::createWorldEventMissionTable(std::istream& is)
{
    return std::make_unique<WorldEventMissionTableImpl>(is);
}


std::unique_ptr<WorldEventInvaderSpawnTable> DataTableFactory::createWorldEventInvaderSpawnTable(std::istream& is)
{
    return std::make_unique<WorldEventInvaderSpawnTableImpl>(is);
}


std::unique_ptr<WorldEventMissionSpawnTable> DataTableFactory::createWorldEventMissionSpawnTable(std::istream& is)
{
    return std::make_unique<WorldEventMissionSpawnTableImpl>(is);
}


std::unique_ptr<DevildomGateTable> DataTableFactory::createDevildomGateTable(std::istream& is)
{
    return std::make_unique<DevildomGateTableImpl>(is);
}


std::unique_ptr<ItemOptionTable> DataTableFactory::creatItemOptionTable(std::istream& is)
{
    return std::make_unique<ItemOptionTableImpl>(is);
}


std::unique_ptr<ItemSuffixTable> DataTableFactory::createItemSuffixTable(std::istream& is)
{
    return std::make_unique<ItemSuffixTableImpl>(is);
}


std::unique_ptr<CharacterDefaultItemTable> DataTableFactory::createCharacterDefaultItemTable(std::istream& is)
{
    return std::make_unique<CharacterDefaultItemTableImpl>(is);
}


std::unique_ptr<CharacterDefaultSkillTable> DataTableFactory::createCharacterDefaultSkillTable(std::istream& is)
{
    return std::make_unique<CharacterDefaultSkillTableImpl>(is);
}


std::unique_ptr<CharacterTitleTable> DataTableFactory::createCharacterTitleTable(std::istream& is)
{
    return std::make_unique<CharacterTitleTableImpl>(is);
}


std::unique_ptr<AchievementTable> DataTableFactory::createAchievementTable(std::istream& is)
{
    return std::make_unique<AchievementTableImpl>(is);

}


std::unique_ptr<GuildLevelTable> DataTableFactory::createGuildLevelTable(std::istream& is)
{
    return std::make_unique<GuildLevelTableImpl>(is);
}


std::unique_ptr<GuildSkillTable> DataTableFactory::createGuildSkillTable(std::istream& is)
{
    return std::make_unique<GuildSkillTableImpl>(is);
}


std::unique_ptr<FunctionTable> DataTableFactory::createFunctionTable(std::istream& is)
{
    return std::make_unique<FunctionTableImpl>(is);
}


}} // namespace gideon { namespace datatable {
