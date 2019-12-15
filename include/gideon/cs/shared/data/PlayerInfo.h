#pragma once

#include "AccountId.h"
#include "ObjectInfo.h"
#include "UserId.h"
#include "MercenaryInfo.h"
#include "GuildInfo.h"
#include "CharacterClass.h"
#include "LevelInfo.h"

namespace gideon {

/**
 * @struct PlayerInfo
 * CommunityServer를 위한 Player 정보
 */
struct PlayerInfo
{
    AccountId accountId_;
    ObjectId playerId_;
    Nickname nickname_;
    GuildId guildId_;
    CharacterClass characterClass_;
    CreatureLevel level_;

    explicit PlayerInfo(AccountId accountId = invalidAccountId,
        ObjectId playerId = invalidObjectId, const Nickname& nickname = L"",
        GuildId guildId = invalidGuildId,
        CharacterClass characterClass = ccAny, CreatureLevel level = clInvalidLevel) :
        accountId_(accountId),
        playerId_(playerId),
        nickname_(nickname),
        guildId_(guildId),
        characterClass_(characterClass),
        level_(level) {}

    void reset() {
        accountId_ = invalidAccountId;
        playerId_ = invalidObjectId;
        nickname_.clear();
        guildId_ = invalidGuildId;
        characterClass_ = ccUnknown;
    }

    bool isValid() const {
        return isValidAccountId(accountId_) && isValidObjectId(playerId_) &&
            (! nickname_.empty());
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & accountId_ & playerId_ & nickname_ & guildId_ & characterClass_ & level_;
    }
};

} // namespace gideon {
