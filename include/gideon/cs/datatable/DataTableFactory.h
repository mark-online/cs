#pragma once

#include <gideon/cs/Common.h>
#include <boost/noncopyable.hpp>
#include <memory>

namespace gideon { namespace datatable {

class WorldMapTable;
class RegionTable;
class RegionCoordinates;
class EquipTable;
class ReprocessTable;
class NpcActiveSkillTable;
class NpcTable;
class RegionSpawnTable;
class PositionSpawnTable;
class ElementTable;
class FragmentTable;
class GemTable;
class ItemDropTable;
class PropertyTable;
class RecipeTable;
class ExpTable;
class RandomDungeonTable;
class QuestTable;
class QuestItemTable;
class QuestKillMissionTable;
class QuestObtainMissionTable;
class QuestProbeMissionTable;
class QuestTransportMissionTable;
class QuestContentsMissionTable;
class HarvestTable;
class TreasureTable;
class NpcSellTable;
class NpcBuyTable;
class AnchorTable;
class BuildingTable;
class EntityPathTable;
class ArenaTable;
class PlayerActiveSkillTable;
class ItemActiveSkillTable;
class SOActiveSkillTable;
class PlayerPassiveSkillTable;
class SkillEffectTable;
class ResourcesProductionTable;
class L10nTable;
class HelpTable;
class FactionTable;
class EventTriggerTable;
class DeviceTable;
class QuestActivationMissionTable;
class GliderTable;
class VehicleTable;
class HarnessTable;
class ActionTable;
class NpcFormationTable;
class NpcTalkingTable;
class DominionRegionTable;
class WorldDropTable;
class WorldDropSuffixTable;
class SelectRecipeProductionTable;
class BuildingGuardTable;
class BuildingGuardSellTable;
class WorldEventTable;
class WorldEventMissionTable;
class WorldEventInvaderSpawnTable;
class WorldEventMissionSpawnTable;
class DevildomGateTable;
class ItemOptionTable;
class ItemSuffixTable;
class AccessoryTable;
class CharacterStatusTable;
class CharacterDefaultItemTable;
class CharacterDefaultSkillTable;
class CharacterTitleTable;
class AchievementTable;
class GuildLevelTable;
class GuildSkillTable;
class FunctionTable;

/**
 * @class DataTableFactory
 *
 */
class GIDEON_CS_API DataTableFactory : public boost::noncopyable
{
public:
    /// PropertyTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<PropertyTable> createPropertyTable(std::istream& is);

    /// CharacterStatusTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<CharacterStatusTable> createCharacterStatusTable(std::istream& is);

    /// WorldMapTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<WorldMapTable> createWorldMapTable(std::istream& is);

    /// RegionTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<RegionTable> createRegionTable(std::istream& is);

    /// RegionCoordinates 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<RegionCoordinates> createRegionCoordinates(std::istream& is);

    /// RegionSpawnTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<RegionSpawnTable> createRegionSpawnTable(std::istream& is);

    /// RegionSpawnTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<PositionSpawnTable> createPositionSpawnTable(std::istream& is);

    /// EquipTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<EquipTable> createEquipTable(std::istream& is);

    /// ReprocessTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<ReprocessTable> createReprocessTable(std::istream& is);

    /// NpcTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<NpcTable> createNpcTable(std::istream& is);

	/// ElementTable 인스턴스를 생성한다
	/// @param is 입력 스트림
	/// - 호출자는 메모리 소유권을 갖는다
	static std::unique_ptr<ElementTable> createElementTable(std::istream& is);

    /// FragmentTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<FragmentTable> createFragmentTable(std::istream& is);

    /// FragmentTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<AccessoryTable> createAccessoryTable(std::istream& is);

	/// ItemDropTable 인스턴스를 생성한다
	/// @param is 입력 스트림
	/// - 호출자는 메모리 소유권을 갖는다
	static std::unique_ptr<ItemDropTable> createItemDropTable(std::istream& is);

    /// GemTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<GemTable> createGemTable(std::istream& is);

    /// RecipeTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<RecipeTable> createRecipeTable(std::istream& is);

    /// ExpTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<ExpTable> createExpTable(std::istream& is);
    
    /// RandomDungeonTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<RandomDungeonTable> createRandomDungeonTable(std::istream& is);

	/// QuestTable 인스턴스를 생성한다
	/// @param is 입력 스트림
	/// - 호출자는 메모리 소유권을 갖는다
	static std::unique_ptr<QuestTable> createQuestTable(std::istream& is);

    /// QuestItemTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<QuestItemTable> createQuestItemTable(std::istream& is);

	/// QuestKillMissionTable 인스턴스를 생성한다
	/// @param is 입력 스트림
	/// - 호출자는 메모리 소유권을 갖는다
	static std::unique_ptr<QuestKillMissionTable> createQuestKillMissionTable(std::istream& is);

    /// QuestActivationMissionTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<QuestActivationMissionTable> createQuestActivationMissionTable(std::istream& is);

    /// QuestObtainMissionTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<QuestObtainMissionTable> createQuestObtainMissionTable(std::istream& is);

    /// QuestProbeMissionTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<QuestProbeMissionTable> createQuestProbeMissionTable(std::istream& is);

    /// QuestTransportMissionTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<QuestTransportMissionTable> createQuestTransportMissionTable(std::istream& is);

	/// QuestContentsMissionTable 인스턴스를 생성한다
	/// @param is 입력 스트림
	/// - 호출자는 메모리 소유권을 갖는다
	static std::unique_ptr<QuestContentsMissionTable> createQuestContentsMissionTable(std::istream& is);

	/// HarvestTable 인스턴스를 생성한다
	/// @param is 입력 스트림
	/// - 호출자는 메모리 소유권을 갖는다
	static std::unique_ptr<HarvestTable> createHarvestTable(std::istream& is);

	/// TreasureTable 인스턴스를 생성한다
	/// @param is 입력 스트림
	/// - 호출자는 메모리 소유권을 갖는다
	static std::unique_ptr<TreasureTable> createTreasureTable(std::istream& is);

	/// NpcSellTable 인스턴스를 생성한다
	/// @param is 입력 스트림
	/// - 호출자는 메모리 소유권을 갖는다
	static std::unique_ptr<NpcSellTable> createNpcSellTable(std::istream& is);

	/// NpcBuyTable 인스턴스를 생성한다
	/// @param is 입력 스트림
	/// - 호출자는 메모리 소유권을 갖는다
	static std::unique_ptr<NpcBuyTable> createNpcBuyTable(std::istream& is);

    /// AnchorTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<AnchorTable> createAnchorTable(std::istream& is);

    /// BuildingTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<BuildingTable> createBuildingTable(std::istream& is);


    /// SelectRecipeProductionTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<SelectRecipeProductionTable> createSelectRecipeProductionTable(std::istream& is);

    /// ResourcesProduction 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<ResourcesProductionTable> createResourcesProductionTable(std::istream& is);
    

    /// EntityPathTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<EntityPathTable> createEntityPathTable(std::istream& is);

    /// HelpTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<HelpTable> createHelpTable(std::istream& is);

    /// L10nTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<L10nTable> createL10nTable(std::istream& is);

    /// ArenaTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<ArenaTable> createArenaTable(std::istream& is);

    /// SkillTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<NpcActiveSkillTable> createNpcActiveSkillTable(std::istream& is);
    static std::unique_ptr<NpcActiveSkillTable> createNpcActiveSkillTableForServer(std::istream& is);

    /// PlayerActiveSkillTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<PlayerActiveSkillTable> createPlayerActiveSkillTable(std::istream& is);
    static std::unique_ptr<PlayerActiveSkillTable> createPlayerActiveSkillTableForServer(std::istream& is);

    /// ItemActiveSkillTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<ItemActiveSkillTable> createItemActiveSkillTable(std::istream& is);
    static std::unique_ptr<ItemActiveSkillTable> createItemActiveSkillTableForServer(std::istream& is);

    /// PlayerActiveSkillTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<SOActiveSkillTable> createSOActiveSkillTable(std::istream& is);
    static std::unique_ptr<SOActiveSkillTable> createSOActiveSkillTableForServer(std::istream& is);

    /// PassiveSkillTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<PlayerPassiveSkillTable> createPlayerPassiveSkillTable(std::istream& is);
    static std::unique_ptr<PlayerPassiveSkillTable> createPlayerPassiveSkillTableForServer(std::istream& is);

    /// SkillEffectTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<SkillEffectTable> createSkillEffectTable(std::istream& is);

    /// FactionTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<FactionTable> createFactionTable(std::istream& is);

    /// EventTriggerTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<EventTriggerTable> createEventTriggerTable(std::istream& is);

    /// DeviceTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<DeviceTable> createDeviceTable(std::istream& is);

	/// GliderTable 인스턴스를 생성한다
	/// @param is 입력 스트림
	/// - 호출자는 메모리 소유권을 갖는다
	static std::unique_ptr<GliderTable> createGliderTable(std::istream& is);

	/// VehicleTable 인스턴스를 생성한다
	/// @param is 입력 스트림
	/// - 호출자는 메모리 소유권을 갖는다
	static std::unique_ptr<VehicleTable> createVehicleTable(std::istream& is);

	/// HarnessTable 인스턴스를 생성한다
	/// @param is 입력 스트림
	/// - 호출자는 메모리 소유권을 갖는다
	static std::unique_ptr<HarnessTable> createHarnessTable(std::istream& is);

    /// ActionTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<ActionTable> createActionTable(std::istream& is);

    /// NpcFormationTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<NpcFormationTable> createNpcFormationTable(std::istream& is);

    /// NpcTalkingTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<NpcTalkingTable> createNpcTalkingTable(std::istream& is);

    /// NpcTalkingTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<DominionRegionTable> createDominionRegionTable(std::istream& is);

    /// WorldDropTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<WorldDropTable> createWorldDropTable(std::istream& is);

    /// WorldDropSuffixTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<WorldDropSuffixTable> createWorldDropSuffixTable(std::istream& is);

    /// BuildingGuardTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<BuildingGuardTable> createBuildingGuardTable(std::istream& is);

    /// BuildingGuardSellTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<BuildingGuardSellTable> createBuildingGuardSellTable(std::istream& is);

    /// createWorldEventTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<WorldEventTable> createWorldEventTable(std::istream& is);

    
    /// createWorldEventMissionTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<WorldEventMissionTable> createWorldEventMissionTable(std::istream& is);


    /// WorldEventInvaderSpawnTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<WorldEventInvaderSpawnTable> createWorldEventInvaderSpawnTable(std::istream& is);

    /// WorldEventMissionSpawnTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<WorldEventMissionSpawnTable> createWorldEventMissionSpawnTable(std::istream& is);

    /// createDevildomGateTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<DevildomGateTable> createDevildomGateTable(std::istream& is);

    /// ItemOptionTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<ItemOptionTable> creatItemOptionTable(std::istream& is);

    /// temSuffixTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<ItemSuffixTable> createItemSuffixTable(std::istream& is);

    /// CharacterDefaultItemTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<CharacterDefaultItemTable> createCharacterDefaultItemTable(std::istream& is);

    /// CharacterDefaultSkillTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<CharacterDefaultSkillTable> createCharacterDefaultSkillTable(std::istream& is);

    /// CharacterTitleTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<CharacterTitleTable> createCharacterTitleTable(std::istream& is);

    /// AchievementTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<AchievementTable> createAchievementTable(std::istream& is);


    /// GuildLevelTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<GuildLevelTable> createGuildLevelTable(std::istream& is);

    /// GuildSkillTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<GuildSkillTable> createGuildSkillTable(std::istream& is);

    /// FunctionTable 인스턴스를 생성한다
    /// @param is 입력 스트림
    /// - 호출자는 메모리 소유권을 갖는다
    static std::unique_ptr<FunctionTable> createFunctionTable(std::istream& is);    
};



}} // namespace gideon { namespace datatable {
