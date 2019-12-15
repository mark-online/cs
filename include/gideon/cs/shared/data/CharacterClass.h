#pragma once

#include <sne/core/stream/IStream.h>
#include <sne/core/stream/OStream.h>

namespace gideon {


/**
 * @enum CharacterClass
 */
enum CharacterClass
{
    ccUnknown = -1,

    ccAny = 0, // 공통 클래스

    ccFighter = 1, // 파이터 (1차 직업)
    ccWizard = 2, // 메이지 (1차 직업)
    ccRogue = 3, // 로그 (1차 직업)

    ccBarbarian = 4, //< 바바리안 (2차 직업)
    ccWarrior = 5, //< 5. 워리어 (2차 직업)
    ccCommander = 6, //< 6. 커맨더 (2차 직업)
    ccChanneler = 7, //< 7. 채널러 (2차 직업)
    ccMage = 8, //< 8. 위자드 (2차 직업)
    ccDruid = 9, //< 9. 드루이드 (2차 직업)
    ccRanger = 10, //< 10. 레인저 (2차 직업)
    ccScout = 11, //< 11. 스카우트 (2차 직업)
    ccAssassin = 12, //< 12. 어쌔신 (2차 직업)

    ccCount
};


inline bool isValid(CharacterClass cc)
{
    return (ccUnknown < cc) && (cc < ccCount);
}


inline bool isCommonClass(CharacterClass cc)
{
    return cc == ccAny;
}


inline bool isFirstClass(CharacterClass cc)
{
    return (ccFighter <= cc) && (cc <= ccRogue);
}


inline bool isSecondClass(CharacterClass cc)
{
    return (ccBarbarian <= cc) && (cc <= ccAssassin);
}


/// 2차 직업에 해당하는 1차 직업을 얻는다
inline CharacterClass toFirstClass(CharacterClass cc)
{
    if (isFirstClass(cc)) {
        return cc;
    }
    switch (cc) {
    case ccBarbarian:
    case ccWarrior:
    case ccCommander:
        return ccFighter;
    case ccChanneler:
    case ccMage:
    case ccDruid:
        return ccWizard;
    case ccRanger:
    case ccScout:
    case ccAssassin:
        return ccRogue;
    }
    return ccUnknown;
}


template <typename T>
inline CharacterClass toCharacterClass(T value)
{
    return static_cast<CharacterClass>(static_cast<int32_t>(value));
}


inline bool isLastCharacterClassGroup(CharacterClass cc) 
{
    return isSecondClass(cc);
}

} // namespace gideon {


namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::CharacterClass rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::CharacterClass& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::CharacterClass>(value);
    return lhs;
}

}} // namespace sne { namespace core {