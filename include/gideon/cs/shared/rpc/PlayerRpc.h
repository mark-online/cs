#pragma once

#include "player/CheatRpc.h"
#include "player/EntityMovementRpc.h"
#include "player/VehicleRpc.h"
#include "player/GliderRpc.h"
#include "player/SkillRpc.h"
#include "player/InventoryRpc.h"
#include "player/QuestRpc.h"
#include "player/TradeRpc.h"
#include "player/HarvestRpc.h"
#include "player/TreasureRpc.h"
#include "player/GraveStoneRpc.h"
#include "player/ItemRpc.h"
#include "player/GamePlayRpc.h"
#include "player/EntityInterestAreaRpc.h"
#include "player/EntityQueryRpc.h"
#include "player/StatsRpc.h"
#include "player/CreatureSocialRpc.h"
#include "player/TeleportRpc.h"
#include "player/DungeonRpc.h"
#include "player/EntityStatusRpc.h"
#include "player/CreatureReviveRpc.h"
#include "player/ActionBarRpc.h"
#include "player/RewardRpc.h"
#include "player/PartyRpc.h"
#include "player/AnchorRpc.h"
#include "player/ChaoRpc.h"
#include "player/BotCommandRpc.h"
#include "player/EmotionRpc.h"
#include "player/GuildRpc.h"
#include "player/CastingRpc.h"
#include "player/EffectRpc.h"
#include "player/PropertyRpc.h"
#include "player/NpcRpc.h"
#include "player/DeviceRpc.h"
#include "player/EntityActionRpc.h"

namespace gideon { namespace rpc {

/**
 * @class PlayerRpc
 * 플레이어 RPC
 */
class PlayerRpc :
    public CheatRpc,
    public GamePlayRpc,
    public EntityInterestAreaRpc,
    public EntityQueryRpc,
    public EntityMovementRpc,
    public EntityActionRpc,
    public CreatureSocialRpc,
    public VehicleRpc,
    public GliderRpc,
    public SkillRpc,
    public InventoryRpc,
    public ItemRpc,
    public EntityStatusRpc,
    public CreatureReviveRpc,
    public GraveStoneRpc,
    public ActionBarRpc,
    public StatsRpc,
    public TradeRpc,
    public DungeonRpc,
    public QuestRpc,
    public TeleportRpc,
    public RewardRpc,
    public HarvestRpc,
    public TreasureRpc,
    public PartyRpc,
    public AnchorRpc,
    public ChaoRpc,
    public BotCommandRpc,
    public EmotionRpc,
    public GuildRpc,
    public ProperyRpc,
    public NpcDialogRpc,
    public NpcTalkingRpc,
    public CastRpc,
    public EffectRpc,
    public DeviceRpc
{
public:
};

}} // namespace gideon { namespace rpc {
