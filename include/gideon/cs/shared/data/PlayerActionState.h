#pragma once

#include "Time.h"

namespace gideon
{

/**
 * @enum PlayerAnimation
 * 
 * 플레이어 행동 정의
 **/
enum PlayerAnimation
{
    paNormal,
    paSkill,
	paProvoke,
	paLoot,

	paBoundary
};


inline bool isPlayAnimation(PlayerAnimation ani)
{
    return paNormal < ani && ani < paBoundary;
}


inline const char* getPlayerAnimationString(PlayerAnimation ani) 
{
	switch(ani) {
	case paProvoke:
		return "Provoke";
	case paLoot:
		return "Loot";
    default:
        return "OutOfBoundary"
    }    
}


/**
 * @enum PlayerAnimationInfo
 * 
 * 플레이어 행동 정의
 **/
struct PlayerAnimationInfo
{
    PlayerAnimation animation_;
    DataCode dataCode_;

    PlayerAnimationInfo(PlayerAnimation animation = paNormal,
        DataCode dataCode = invalidDataCode) :
        animation_(animation),
        dataCode_(dataCode) {}


    template <typename Stream>
    void serialize(Stream& stream) {
        stream & animation_;
        if (hasDataCode(animation_)) {
            stream & dataCode_;
        }
        else {
            dataCode_ = invalidDataCode;
        }
    }
private:
    bool hasDataCode(PlayerAnimation ani) {
        return paSkill == ani;
    }
};



}// namespace gideon


namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::PlayerAnimation rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::PlayerAnimation& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::PlayerAnimation>(value);
    return lhs;
}

}