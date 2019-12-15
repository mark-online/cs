#pragma once

#include <gideon/cs/Common.h>
#include <sne/srpc/RpcContainers.h>

namespace gideon {

/**
 * @enum CodeType
 * 코드 종류
 */
enum CodeType
{
    ctInvalid = 0,
    ctBegin = 1,

    ctSkill = ctBegin, //< 스킬
    ctNpcTalking = 2, //< NPC 잡담
    ctEquipment = 3, //< 장비 
    ctFunction = 4, //< 기능성 아이템
    ctRecipe = 5, //< 레시피
    ctNpc = 6, //< NPC(몬스터 포함)
    ctElement = 7, //< 재료
    ctGathering = 8, //< 채집
    ctGem = 9, //< 보석
    ctFragment = 10, //< 조각
    ctMap = 11, //< 월드맵
    ctRegion = 12, //< 지역
	ctItemDrop = 13, //< 아이템 드롭
	ctDungeon = 14, //< 던전
	ctHarvest = 15, //< 채집
	ctTreasure = 16, //< 보물 상자
    ctAnchor = 17, //< 설치물
    ctEntityPath = 18, //< Entity 이동 path
    ctBuilding = 19, //< 조정가능한 설치물
    ctQuestItem = 20, //< 퀘스트 아이템 코드
    ctQuest = 21, //< 퀘스트
    ctQuestMission = 22, //< 퀘스트 미션
    ctObelisk = 23, //< 오벨리스크(텔레포트)
    ctAccessory = 24, //< 장신구 (목걸리, 팔찌, 반지)
    ctDevice = 25, //< (작동할 수 있는) 장치
    // ctQuestUpgradeEquip = 26, // 퀘스트 보상으로 업그레이드 할수 있는 정보코드(파싱 필요)
	ctVehicle = 27, // 탈것 아이템
	ctGlider = 28, // 글라이더 아이템
	// ctQuestSelectUpgradeEquip = 29, // 퀘스트에서 선택으로 할때 임의적으 합친 코드를 만들어준다.
	ctHarness = 30, // 마갑
	ctCastState = 31, // 현재 캐스팅에 사용할 코드가 없는경우 이용할수 있음.
    ctBuildingGuard = 32, // 용병
    ctWorldEvent = 33,
    ctWorldEventPhase = 34,
    ctWorldEventMission = 35,
    ctCharacterTitle = 36,
    ctAchievement = 37,
    ctAchievementMission = 38,

    ctBoundary,
    ctEnd = ctBoundary - 1
};


inline bool isValid(CodeType ct)
{
    return (ctBegin <= ct) && (ct <= ctEnd);
}


template <typename T>
inline CodeType toCodeType(T value)
{
    return static_cast<CodeType>(static_cast<uint8_t>(value));
}


/// 아이템 여부를 얻는다,
inline bool isItemType(CodeType ct)
{
    return (ctEquipment == ct) || (ctAccessory == ct) ||
        (ctRecipe == ct) ||  (ctElement == ct) ||
        (ctGem == ct) || (ctFragment == ct) || (ctAnchor == ct) ||
        (ctBuilding == ct) || (ctQuestItem == ct) || (ctVehicle == ct) || (ctGlider == ct) ||
        (ctBuildingGuard == ct) || (ctFunction == ct);
}


/// 제작 가능한가?
inline bool canCraft(CodeType ct)
{
    return (ctElement == ct) || (ctRecipe == ct) || (ctGem == ct);
}


/// (장비) 강화 가능한가?
inline bool canUpgrade(CodeType ct)
{
    return (ctEquipment == ct);
}


/// 분해 가능한가?
inline bool canReprocess(CodeType ct)
{
    return (ctFragment == ct) || (ctEquipment == ct) || (ctElement == ct) || (ctGem == ct);
}


/// 소켓 강화 가능한가?
inline bool canEnchant(CodeType ct)
{
    return ctEquipment == ct;
}


inline bool isSpawnable(CodeType ct)
{
    return (ctHarvest == ct) || (ctNpc == ct) || (ctObelisk == ct) ||
        (ctTreasure == ct) || (ctDungeon == ct) || (ctAnchor == ct) || (ctBuilding == ct);
}


// 재료 아이템 여부를 얻는다
inline bool isElementType(CodeType ct)
{
    return ctElement == ct;
}


// Gem 아이템 여부를 얻는다
inline bool isGemType(CodeType ct)
{
    return ctGem == ct;
}


inline bool isFunctionType(CodeType ct)
{
    return ctFunction == ct;
}


// 장착 아이템 여부를 얻는다
inline bool isEquipmentType(CodeType ct)
{
    return ctEquipment == ct; 
}


inline bool isAccessoryType(CodeType ct)
{
    return ctAccessory == ct;
}


// 조각 아이템 여부를 얻는다
inline bool isFragmentType(CodeType ct)
{
    return ctFragment == ct;
}


// 레시피 아이템 여부를 얻는다
inline bool isRecipeType(CodeType ct)
{
    return ctRecipe == ct;
}


// Npc  여부
inline bool isNpcType(CodeType ct)
{
	return ctNpc == ct;
}


// 채집 돌 여부
inline bool isHarvestType(CodeType ct)
{
	return ctHarvest == ct;
}


// 보물 상자 여부
inline bool isTreasureType(CodeType ct)
{
	return ctTreasure == ct;
}


// 설치물 여부
inline bool isAnchorType(CodeType ct)
{
    return ctAnchor == ct;
}


// 설치물 여부
inline bool isBuildingType(CodeType ct)
{
    return ctBuilding == ct;
}


// 퀘스트 아이템 여부
inline bool isQuestItemType(CodeType ct)
{
    return ctQuestItem == ct;
}


// 퀘스트 여부
inline bool isQuestType(CodeType ct)
{
    return ctQuest == ct;
}


// 퀘스트 미션 여부
inline bool isQuestMissionType(CodeType ct)
{
    return ctQuestMission == ct;
}


// 스킬 체크
inline bool isSkillType(CodeType ct)
{
    return ctSkill == ct;
}


inline bool isVehicleType(CodeType ct)
{
	return ctVehicle == ct;
}


inline bool isGliderType(CodeType ct)
{
	return ctGlider == ct;
}

//inline bool isQuestUpgradeEquipType(CodeType ct)
//{
//	return ctQuestUpgradeEquip == ct;
//}
//
//
//inline bool isQuestSelectUpgradeEquipType(CodeType ct)
//{
//	return ctQuestSelectUpgradeEquip == ct;
//}


inline bool isHarnessType(CodeType ct)
{
	return ctHarness == ct;
}


inline bool isCastStateType(CodeType ct)
{
    return ctCastState == ct;
}


inline bool isBuildingGuardType(CodeType ct)
{
    return ctBuildingGuard == ct;
}

/// 액션바에 장착이 가능한가?
inline bool canPlaceOnActionBar(CodeType ct)
{
    return isElementType(ct) || isFunctionType(ct) || isAnchorType(ct) || isBuildingType(ct) ||
        isQuestItemType(ct);
}


inline bool isUsableItem(CodeType ct)
{
    return isElementType(ct) || isFunctionType(ct) || isQuestItemType(ct);
}


inline bool hasItemSuffix(CodeType ct)
{
    return isEquipmentType(ct) || isAccessoryType(ct);
}


inline bool isCharacterTitleType(CodeType ct)
{
    return ctCharacterTitle == ct;
}


inline bool isAchievementType(CodeType ct)
{
    return ctAchievement == ct;
}


inline bool isAchievementMissionType(CodeType ct)
{
    return ctAchievementMission == ct;
}

/// Data Code (장비, 스킬, ...)
/// Category | Subcategory | Index
typedef uint32_t DataCode;
const DataCode invalidDataCode = 0;

inline bool isValidDataCode(DataCode dataCode)
{
    return dataCode != invalidDataCode;
}


/// 코드의 최소값을 얻는다
inline DataCode getMinGideonCode(CodeType codeType)
{
    return codeType << (32 - 8); // *16777216
}


/// 코드의 최대값을 얻는다
inline DataCode getMaxGideonCode(CodeType codeType)
{
    return getMinGideonCode(codeType) + 0x00FFFFFF; // 16711680 + 65535
}


/// 코드 종류를 얻는다
inline CodeType getCodeType(DataCode dc)
{
    return static_cast<CodeType>(dc >> (32 - 8));
}


/// 아이템을 중첩(stack)할 수 있는가?
inline bool isStackable(DataCode itemCode)
{
    const CodeType codeType = getCodeType(itemCode);
    return (! isEquipmentType(codeType)) && (! isAccessoryType(codeType));
}

typedef sne::core::Vector<gideon::DataCode> DataCodes;
typedef sne::core::Set<gideon::DataCode> DataCodeSet;

} // namespace gideon {
