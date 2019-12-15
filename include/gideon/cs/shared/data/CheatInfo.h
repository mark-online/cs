#pragma once

#include "ObjectInfo.h"
#include "UserId.h"
#include "ZoneInfo.h"
#include "WorldInfo.h"
#include "LevelInfo.h"
#include <sne/srpc/RpcContainers.h>

namespace gideon {

/***
 * @struct ZoneUserInfo
 ***/
struct ZoneUserInfo
{
    ObjectId playerId_;
    Nickname nickname_;

    explicit ZoneUserInfo(ObjectId playerId = invalidObjectId, const Nickname& nickname = L"") :
        playerId_(playerId),
        nickname_(nickname) {}

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & playerId_ & nickname_;
    }
};

typedef sne::srpc::RVector<ZoneUserInfo> ZoneUserInfos;


/***
 * @struct WorldUserInfo
 ***/
struct WorldUserInfo : public ZoneUserInfo
{
    CreatureLevel level_;
    MapCode mapCode_;

    explicit WorldUserInfo(ObjectId playerId = invalidObjectId, const Nickname& nickname = L"",
        CreatureLevel level = clInvalidLevel, MapCode mapCode = invalidMapCode) :
        ZoneUserInfo(playerId, nickname),
        level_(level),
        mapCode_(mapCode) {}

    template <typename Stream>
    void serialize(Stream& stream) {
        ZoneUserInfo::serialize(stream);
        stream & level_ & mapCode_;
    }
};

typedef sne::srpc::RVector<WorldUserInfo> WorldUserInfos;

/***
 * @struct CheatValueType
 ***/
enum CheatValueType
{
	cvtUnknown,
	cvtGameMoney,
	cvtArenaPoint,
	cvtEventCoin,
	cvtMercenaryPoint,
	cvtForgeCoin,
	cvtExp,
	cvtSpeed,
	cvtMajorLevel,
	cvtMinerLevel,
	cvtSkillPoint,
	cvtHp,
	cvtMp,
	cvtChao,
	cvtTempChao,
    cvtBuildingHp,
    cvtBuildTime,
    cvtStrength,
    cvtDexterity,
    cvtIntellect,
    cvtEnergy,
    cvtMinAttack,
    cvtMaxAttack,
    cvtMagic,
    cvtPhysical,
    cvtHitRate,
    cvtPhysicalCriticalRate,
    cvtMagicCriticalRate,
    cvtParryRate,
    cvtBlockRate,
    cvtDodgeRate,
    cvtDefence,
    cvtLight,
    cvtDark,
    cvtFire,
    cvtIce,
    cvtLightResist,
    cvtDarkResist,
    cvtFireResist,
    cvtIceResist,
    cvtGuildExp,
};


enum ValueChangetype
{
	vctUp,
	vctDown,
	vctSet,
};

} // namespace gideon {
