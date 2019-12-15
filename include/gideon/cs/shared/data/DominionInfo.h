#pragma once

#include "GuildInfo.h"
#include "BuildingInfo.h"

namespace gideon {


enum DominionType
{
	dtNone = 0,
	dtWorld = 1,
	dtZone = 2,
};

template <typename T>
inline DominionType toDominionType(T value)
{
	return static_cast<DominionType>(static_cast<uint8_t>(value));
}

/***
 * @struct BuildingDominionInfo  
***/
struct BuildingDominionInfo
{
	ObjectId buildingId_;
	ObjectPosition position_;
	BuildingCode buildingCode_;
	BaseGuildInfo guildInfo_;
	Nickname masterName_;
	bool isActivate_;
	bool canTeleport_;

	explicit BuildingDominionInfo(ObjectId buildingId = invalidObjectId,
		const ObjectPosition position = ObjectPosition(),
		BuildingCode buildingCode = invalidBuildingCode,
		const BaseGuildInfo& guildInfo = BaseGuildInfo(),
		const Nickname& masterName = L"", bool isActivate = false, bool canTeleport = false) :
		buildingId_(buildingId),
		position_(position),		
		buildingCode_(buildingCode),
		guildInfo_(guildInfo),
		masterName_(masterName),
		isActivate_(isActivate),
		canTeleport_(canTeleport)
	{}

	template <typename Stream>
	void serialize(Stream& stream) {
		stream & buildingId_ & position_ & buildingCode_ & guildInfo_ & masterName_ & isActivate_ & canTeleport_;
	}
};


typedef sne::srpc::RVector<BuildingDominionInfo> BuildingDominionInfos;


struct MoreBuildingDominionInfo : public BuildingDominionInfo
{
	DominionType dominionType_;

	explicit MoreBuildingDominionInfo(ObjectId buildingId = invalidObjectId,
		const ObjectPosition position = ObjectPosition(),
		BuildingCode buildingCode = invalidBuildingCode,
		const BaseGuildInfo& guildInfo = BaseGuildInfo(),
		const Nickname& masterName = L"", bool isActivate = false, bool canTeleport = false,
		DominionType dominionType = dtNone) :
		BuildingDominionInfo(buildingId, position, buildingCode, guildInfo, masterName, isActivate, canTeleport),
		dominionType_(dominionType)
	{}

	template <typename Stream>
	void serialize(Stream& stream) {
		BuildingDominionInfo::serialize(stream);
		stream & dominionType_;
	}
};


/***
 * @struct DominionWorldInfo  
***/
struct DominionWorldInfo
{	
	MapCode worldMapCode_;
	BaseGuildInfo guildInfo_;
	Nickname masterName_;
	bool isActivate_;

	DominionWorldInfo(MapCode worldMapCode = invalidMapCode, 
		const BaseGuildInfo& guildInfo = BaseGuildInfo(), 
		const Nickname masterName = L"", bool isActivate = false) :
		worldMapCode_(worldMapCode),
		guildInfo_(guildInfo),
		masterName_(masterName),
		isActivate_(isActivate)
	{}

	template <typename Stream>
	void serialize(Stream& stream) {
		stream & worldMapCode_ & guildInfo_ & masterName_ & isActivate_;
	}
};

typedef sne::srpc::RMap<ObjectId, DominionWorldInfo> DominionWorldInfoMap;



} // namespace gideon {