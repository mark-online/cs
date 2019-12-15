#pragma once

#include "Code.h"
#include "CreatureStatusInfo.h"
#include "Coordinate.h"
#include "CharacterClass.h"
#include <sne/srpc/RpcContainers.h>

namespace gideon {


typedef uint32_t PartyId;
const PartyId invalidPartyId = 0;

inline bool isValidPartyId(PartyId id)
{
    return invalidPartyId != id;
}


const int8_t maxPartyGroupCount = 4;
const int8_t maxPartyGroupMember = 5;
const int8_t maxTotalGroupPartyMember = (maxPartyGroupCount * maxPartyGroupMember);

const int8_t invalidPartyGroupIndex = -1;
const int8_t startPartyGroupIndex = 0;

inline bool isValidPartyGroupIndex(uint32_t groupIndex)
{
    return startPartyGroupIndex <= groupIndex && groupIndex < maxPartyGroupCount;
}


/**
 * @enum PartyTyp
 * 
 **/
enum PartyType
{
    ptSolo = 1,
	ptPublic = 2,
    ptRaid = 3,
    ptBoundery,
};


inline bool isValid(PartyType type)
{
    return ptSolo <= type && type < ptBoundery;
}


inline bool isSoloParty(PartyType partyType)
{
    return ptSolo == partyType;
}


inline bool isPublicParty(PartyType partyType)
{
    return ptPublic == partyType;
}


inline bool isRaidParty(PartyType partyType)
{
    return ptRaid == partyType;
}


inline bool isGroupParty(PartyType partyType)
{
    return ptPublic == partyType || ptRaid == partyType;
}

/**
 * @enum PartyMemberGrade
 * 
 **/
enum PartyMemberGrade
{
	pmgUnknown = 0,
	pmgGeneral = 1,
	pmgMaster = 2,
};


/**
 * @struct Waypoints
 */
struct Waypoints
{
    Waypoint worldWaypoint_;
    Waypoint dungeonWaypoint_;

    explicit Waypoints(const Waypoint& worldWaypoint = Waypoint(),
        const Waypoint& dungeonWaypoint = Waypoint()) :
        worldWaypoint_(worldWaypoint),
        dungeonWaypoint_(dungeonWaypoint) {}

	template <typename Stream>
	void serialize(Stream& stream) {
        stream & worldWaypoint_ & dungeonWaypoint_;
	}
};


/**
 * @struct PartyPosition
 * 
 **/
struct PartyPosition
{
    int8_t groupIndex_;
    int8_t position_;

    explicit PartyPosition(int8_t groupIndex = -1, int8_t position = -1) :
        groupIndex_(groupIndex),
        position_(position) {}

    void reset() {
        groupIndex_ = -1;
        position_ = -1;
    }

    bool isValid() const {
        return (0 <= groupIndex_ && groupIndex_ < maxPartyGroupCount) &&
            (0 <= position_ && position_ < maxPartyGroupMember);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & groupIndex_ & position_;
    }
};

typedef sne::srpc::RHashMap<ObjectId, PartyPosition> PartyPositionMap;

/**
 * @struct PartyMemberInfo
 * 
 **/
struct PartyMemberInfo
{
	ObjectId playerId_;
    CharacterClass characterClass_;
    PartyPosition partyPosition_; // 레이드 or 퍼블릭 파티일때만 유효함
	Nickname nickname_;
	MapCode worldMapCode_;
    MapCode subMapCode_;
	PartyMemberGrade grade_;
    Waypoints waypoints_;

	explicit PartyMemberInfo(ObjectId playerId = invalidObjectId,
        CharacterClass characterClass = ccUnknown,
        const PartyPosition& position = PartyPosition(),
        const Nickname& nickname = L"",
		MapCode worldMapCode = invalidMapCode, MapCode subMapCode = invalidMapCode, 
        PartyMemberGrade grade = pmgUnknown) :
		playerId_(playerId),
        characterClass_(characterClass),
        partyPosition_(position),
		nickname_(nickname),
		worldMapCode_(worldMapCode),
        subMapCode_(subMapCode),
		grade_(grade) {}

    void setWaypoint(const Waypoint& waypoint) {
        if (! isValidMapCode(waypoint.mapCode_)) {
            return;
        }

        if (isWorldMap(getMapType(waypoint.mapCode_))) {
            waypoints_.worldWaypoint_ = waypoint;
        }
        else {
            waypoints_.dungeonWaypoint_ = waypoint;
        }
    }

	template <typename Stream>
	void serialize(Stream& stream) {
		stream & playerId_ & characterClass_ & partyPosition_ & nickname_ & worldMapCode_ & subMapCode_ & grade_ & waypoints_;
	}
};

typedef sne::srpc::RVector<PartyMemberInfo> PartyMemberInfos;

typedef sne::core::HashMap<ObjectId, PartyMemberInfo> PartyMemberInfoMap;

/**
 * @struct FullPartyMemberInfo
 * 
 **/
struct FullPartyMemberInfo : public PartyMemberInfo
{
	LifeStats lifeStats_;

	FullPartyMemberInfo(const PartyMemberInfo& memberInfo = PartyMemberInfo(), 	
		const LifeStats& lifeStats = LifeStats()) :
		PartyMemberInfo(memberInfo),
		lifeStats_(lifeStats)
	{}


	template <typename Stream>
	void serialize(Stream& stream) {
		PartyMemberInfo::serialize(stream);
		if (login_) {
			stream & lifeStats_;
		}		
	}
};

typedef sne::srpc ::RVector<FullPartyMemberInfo> FullPartyMemberInfos;

} // namespace gideon {


namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::PartyMemberGrade rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::PartyMemberGrade& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::PartyMemberGrade>(value);
    return lhs;
}


inline OStream& operator<<(OStream& lhs, gideon::PartyType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::PartyType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::PartyType>(value);
    return lhs;
}

}} // namespace sne { namespace core {