#pragma once

#include "UserId.h"
#include "NpcInfo.h"
#include <sne/srpc/RpcContainers.h>

namespace gideon {

/**
 * @struct UnionGraveStoneName
 * 비석에 표시할 이름
 * - ownerType_에 따라 의미가 달라진다
 **/
struct UnionGraveStoneName
{
	ObjectType ownerType_;

	NpcCode npcCode_;
	Nickname nickname_;

    UnionGraveStoneName() {
        reset();
    }

    UnionGraveStoneName(ObjectType ownerType, NpcCode npcCode) :
        ownerType_(ownerType),
        npcCode_(npcCode) {}

    UnionGraveStoneName(ObjectType ownerType, const Nickname& nickname) :
        ownerType_(ownerType),
        nickname_(nickname) {}


	void reset() {	
		ownerType_ = otInvalid;
		npcCode_ = invalidNpcCode;
		nickname_.clear();
	}

	bool isValid() const {
		switch (ownerType_) {
        case otPc:
			return ! nickname_.empty();
        case otNpc:
			return isValidNpcCode(npcCode_);
		}
		return false;
	}

    template <typename Stream>
    void serialize(Stream& stream) {
        const bool isInput = stream.isInput();
		stream & ownerType_;
        switch (ownerType_) {
        case otPc:
			stream & nickname_;
            if (isInput) {
                npcCode_ = invalidNpcCode;
            }
            break;
        case otNpc:
			stream & npcCode_;
            if (isInput) {
                nickname_.clear();
            }
            break;
        }
	}
};

} // namespace gideon {
