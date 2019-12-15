#pragma once

#include "AccountId.h"
#include "UserId.h"
#include "CharacterInfo.h"
#include <sne/base/utility/Assert.h>
#include <sne/core/container/Containers.h>

namespace gideon {

/**
 * @struct BaseUserInfo
 * 사용자 기본 정보
 */
struct BaseUserInfo
{
    AccountId accountId_;

    explicit BaseUserInfo(AccountId accountId = invalidAccountId) :
        accountId_(accountId) {}

    void reset() {
        accountId_ = invalidAccountId;
    }

    bool isValid() const {
        return isValidAccountId(accountId_);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & accountId_;
    }
};


/**
 * @struct FullUserInfo
 * Shard 별로 유지하는 상세한 사용자 정보
 */
struct FullUserInfo : BaseUserInfo
{
    FullCharacterInfos characters_;
    ObjectId lastAccessCharacterId_;

    explicit FullUserInfo(AccountId accountId = invalidAccountId) :
        BaseUserInfo(accountId),
        lastAccessCharacterId_(invalidObjectId) {}

    explicit FullUserInfo(const BaseUserInfo& userInfo) :
        BaseUserInfo(userInfo),
        lastAccessCharacterId_(invalidObjectId) {}

    void reset() {
        BaseUserInfo::reset();
        characters_.clear();
        lastAccessCharacterId_ = invalidObjectId;
    }

    bool isValid() const {
        return BaseUserInfo::isValid() &&
            isValidCharacters();
    }

    bool hasCharacter() const {
        return ! characters_.empty();
    }

    bool hasCharacter(ObjectId characterId) const {
        return getCharacter(characterId) != nullptr;
    }

    FullCharacterInfo* getCharacter(ObjectId characterId) {
        const FullCharacterInfos::iterator pos = characters_.find(characterId);
        if (pos == characters_.end()) {
            return nullptr;
        }
        return &(*pos).second;
    }

    const FullCharacterInfo* getCharacter(ObjectId characterId) const {
        const FullCharacterInfos::const_iterator pos = characters_.find(characterId);
        if (pos == characters_.end()) {
            return nullptr;
        }
        return &(*pos).second;
    }

    bool isValidCharacters() const {
        FullCharacterInfos::const_iterator pos = characters_.begin();
        const FullCharacterInfos::const_iterator end = characters_.end();
        for (; pos != end; ++pos) {
            const FullCharacterInfo& character = (*pos).second;
            if (! character.isValid()) {
                return false;
            }
        }
        return true;
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        BaseUserInfo::serialize(stream);
        stream & characters_ & lastAccessCharacterId_;
    }
};

} // namespace gideon {
