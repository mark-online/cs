#pragma once

#include "AccountId.h"
#include "AppearanceInfo.h"
#include "CharacterClass.h"
#include "UserId.h"
#include "EquipmentInfo.h"
#include "SexType.h"
#include <cassert>

namespace gideon {

/**
 * @struct CreateCharacterInfo
 */
struct CreateCharacterInfo
{
    AccountId accountId_;
    CharacterClass characterClass_;
    CharacterAppearance appearance_;
    EquipCode selectMainWeaponCode_;
    Nickname nickname_;
    SexType sexType_;

    explicit CreateCharacterInfo(AccountId accountId = invalidAccountId,
        CharacterClass characterClass = ccUnknown, 
        const CharacterAppearance& appearance = CharacterAppearance(),
        EquipCode selectMainWeaponCode = invalidEquipCode,
        const Nickname& nickname = L"", SexType sexType = stMale) :
        accountId_(accountId),
        characterClass_(characterClass),
        appearance_(appearance),
        selectMainWeaponCode_(selectMainWeaponCode),
        nickname_(nickname),
        sexType_(sexType)
    {
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & accountId_ & characterClass_ & appearance_ & selectMainWeaponCode_ & nickname_ &
            sexType_;
    }

};

} // namespace gideon {
