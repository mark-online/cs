#pragma once

#include <gideon/cs/Common.h>
#include <sne/core/stream/Streamable.h>
#include <cassert>

namespace gideon {

/**
 * @enum ErrorCode
 * 서버 측의 에러 코드 (16비트만 쓰인다)
 */
enum ErrorCode
{
    /// 정상!
    ecOk = 0,

    // = 로그인 관련

    /// 로그인 서버가 바빠서 인증을 할 수 없다
    ecLoginIsBusy = 1,

    /// 로그인 가능 인원 초과
    ecLoginIsFull = 2,

    /// 로그인(인증) 서버에서 사용자 인증 실패 (잘못된 계정 정보)
    ecAuthenticateFailed = 3,

    /// 이미 로그인 요청을 하였다
    ecLoginAlreadyLoggingIn = 4,

    /// 이미 로그인하였다
    ecLoginAlreadyLoggedIn = 5,

    /// 잘못된 인증서
    ecLoginInvalidCertificate = 7,

	// 중복된 유저 아이디
	ecLoginDuplicatedUserId = 8,

	/// 로그인된 유저가 아니다
	ecLoginIsNotLoginUser = 9,

	/// 접근 서버 경로가 올바르지 않습니다.
	ecLoginInvalidAccessServer = 10,

    /// 요청을 처리 중이다
    ecLoginRequestPended = 11,

    /// 아이디가 너무 짧다
    ecLoginUserIdTooShort = 12,

    /// 아이디에 유효하지 않은 문자가 포함되어있다(알파벳, 숫자만 허용)
    ecLoginInvalidUserId = 13,

    /// 비밀번호가 너무 짧다
    ecLoginUserPasswordTooShort = 14,

    /// 비밀번호에 유효하지 않은 문자가 포함되어있다(공백, 제어문자 허용 안함)
    ecLoginInvalidUserPassword = 15,

    /// 이메일 주소 형식이 올바르지 않다
    ecLoginInvalidUserEmail = 16,

	/// 벤 당한 유저
	ecLoginBanUser = 17,

    /// 로그아웃 중(플레이어 로그아웃 대기 중)
    ecLoginLoggingOut = 18,

    // = Zone Server 관련

    /// 존 서버가 바빠서 연결을 유지할 수 없다
    ecZoneIsBusy = 21,

    /// 존 서버의 사용자 수용 능력 초과
    ecZoneIsFull = 22,

    /// 존 서버에서 사용자를 찾을 수 없다
    ecZoneUserNotExist = 23,

    /// 캐릭터의 스폰 위치가 잘못되었다(운영자에게 문의하세요~~)
    ecZoneInvalidSpawnPosition = 25,

    // = 커뮤니티 서버 관련

    // 커뮤니티 서버가 바빠서 연결을 유지할 수 없다
    ecCommunityIsBusy  = 31,

    /// 커뮤니티 서버의 사용자 수용 능력 초과
    ecCommunityIsFull = 32,

    /// 커뮤니티 서버에서 사용자를 찾을 수 없다
    ecCommunityUserNotExist = 33,

	// = 인증 관련

	// 이미 인증 요청 중이다
	ecCertificateAlreadyRequest = 50,

    // = 유저 관련

    /// 계정을 찾을 수 없다
    ecAccountNotFound = 2001,

    // = 캐릭터 관련

    /// 중복된 닉네임
    ecCharacterDuplicatedNickname = 2101,

    /// 캐릭터가 너무 많다(더이상 생성할 수 없다)
    ecCharacterTooMany = 2102,

    /// 캐릭터를 찾을 수 없다
    ecCharacterNotFound = 2103,

    /// 캐릭터 장비 정보가 올바르지 않다
    ecCharacterEquipIsNotValid = 2104,

    /// 캐릭터 Revive시간이 충분히 지나지 못했다.
    ecCharacterNotEnoughReviveTime = 2105,

    /// 캐릭터 정보가 올바르지 않다
    ecCharacterInvalid = 2107,

    /// 닉네임이 너무 짧다
    ecCharacterNicknameTooShort = 2108,

    /// 닉네임에 허용하지 않는 문자 포함(공백, 제어문자, 구두점 허용 안함)
    ecCharacterInvalidNickname = 2109,

    /// 닉네임 중복체크를 하세요
    ecCharacterCheckDuplicateNickname = 2110,
	
	/// 유효한 스킬이 아니다
	ecCharacterInvalidSubSkill = 2111,

    /// 유효한 클래스가 아니다
    ecCharacterInvalidClass = 2112,

    /// 유효한 무기가 아니다
    ecCharacterInvalidMainWeapon = 2113,

    /// 계정 어카운트 아이디가 유효하지 않음
    ecCharacterInvalidAccountId = 2114,

    
    // = 스킬 관련

    /// 배우지 않은 스킬을 사용했다
    ecSkillNotLearned = 2201,

    /// 스킬 시전 대상이 존재하지 않는다
    ecSkillTargetNotFound = 2202,

    /// passive 스킬은 시전할 수 없다
    ecSkillIsNotActive = 2203,

    /// 스킬 시전 간격(쿨다운 타임)이 너무 짧다
    ecSkillTooShortInterval = 2204,

    /// 타겟이 너무 멀리 있어 스킬을 시전할 수 없다
    ecSkillTargetTooFar = 2205,

    /// 타겟이 너무 가까이 있어 스킬을 시전할 수 없다
    ecSkillTargetTooNear = 2206,

    /// 시전할 수 없는 스킬(현재 상황에 맞지 않음)
    ecSkillNotAvailable = 2207,

    /// 시전하기엔 스탯(HP/MP/CP)이 부족하다
    ecSkillNotEnoughStats = 2208,

    /// 스킬을 사용할수 없는 상태이다.
    ecSkillNotUseableState = 2209,

    /// 스킬을 더이상 배울수 없다(maxSkill)
    ecSkillMaxSkillNotLearn = 2210,

    /// 유효하지 않은 스킬이다.
    ecSkillInvalidSkill = 2211,

    /// 스킬 포인터가 충분하지 않다
    ecSkillNotEnoughSkillPoint = 2212,

    /// 스킬을 사용할수 있는 장비가 없습니다.
    ecSkillNotAllowedEquipment = 2213,

    /// 스킬을 사용할수 있는 방향이 아니다(전방, 후방체크)
    ecSkillInvalidTargetDirection = 2214,

    /// 스킬을 사용할수 있는 방향이 아니다(전면, 후면체크)
    ecSkillInvalidTargetOrientation = 2215,

    /// 필요한 선행 스킬을 배우지 않았다.
    ecSkillHasNotNeedSkill = 2216,

    /// 타이머 이펙트가 돌고 있는 상황에서는 지울수 없다
    ecSkillNotDeleteTimerEffected = 2217,

    /// 이미 등록되어 있는 페시브 시킬
    ecSkillAlreayRegistPassiveSkill = 2218,

    /// 움직이면서 사용할수 있는 스킬이 아니다.
    ecSkillCannotMoveSkill = 2219,

    /// 안전 지역에서는 시전할 수 없는 스킬이다
    ecSkillCannotCastInSafeRegion = 2220,

	/// 스킬 소모 아이템이 부족합니다
	ecSkillNotEnoughMetarialItem = 2221,

	/// 필요한 스킬 이펙트가 안걸려 있습니다.
	ecSkillNotApplySkillEffectScript = 2222,

    /// 유효하지 않은 시전 대상이다
    ecSkillInvalidAvailableTarget = 2223,

    /// 자기 자신에게 시전할수 없는 스킬이다.
    ecSkillSelfExceptSkill = 2224,

    /// 스킬 초기화시 돈이 부족하다.
    ecSkillUnleranNotEnoughMoney = 2225,

    /// 배울수 없는 클래스이다.
    ecSkillLearnNotCharacterClass = 2226,

    /// 시전하기엔 스탯(HP/MP/CP)이 많다.
    ecSkillOverStats = 2227,

    /// 타겟이 무적상태이다
    ecSkillTargetSpawnProtection = 2228,

    /// 투기장에서는 쓸수없는 스킬이다
    ecSkillCannotCastableInArena = 2229,

    /// 보호받는 케릭터 입니다.
    ecSkillProtectionCharacter = 2230,

    /// 초보맵에서는 플레이어한테 스킬을 사용할수 없다
    ecSkillNotCastToPlayerInBeginnerMap = 2231,

    /// 매직류 스킬을 사용할수 없다
    ecSkillDisableMagic = 2232,

    /// 다음 스킬을 가지고 있습니다(스킬 초기화)
    ecSkillHasNextSkill = 2233,

    /// 동급의 스킬에 걸려있어 사용을 못함
    ecSkillSameCagegory = 2234,

    /// 배운 스킬이 존재하지 않는다.
    ecSkillNotExistLearnSkill = 2235,

    /// 공격할수 없는 대상입니다.
    ecSkillNotAttackTatget = 2236,

    /// (집행이나 부활 외의) 스킬을 죽은 애한테 쓸 수 없다
    ecSkillCannotUseToDeadTarget = 2237,

    /// 투기장에서는 스킬을 배울수 없습니다.
    ecSkillNotLearnSkillInArena = 2238,

    /// 투기장에서는 스킬을 초기화 없습니다.
    ecSkillNotUnlearnSkillInArena = 2239,

    // = Entity 관련

    /// Entity를 찾을 수 없다
    ecEntityNotFound = 2301,

    // = Creature 관련

    /// Creature(Player)를 소생시킬 수 없다
    ecCreatureCannotRevive = 2351,

    // = 인벤토리 관련

    /// 인벤토리가 가득 차서 아이템을 줍거나 탈착할 수 없다
    ecInventoryIsFull = 2401,

    /// 인벤토리 슬롯 번호가 올바르지 않다
    ecInventorySlotNotValid = 2402,

    /// 소유하지 않은 아이템 (슬롯 이동, 장착)
    ecInventoryItemNotFound = 2403,

    /// 장착 중인 아이템은 슬롯을 변경할 수 없다
    ecInventoryCannotChangeEquippedItemSlot = 2404,

    /// 해당 인벤토리 슬롯에 아이템이 존재하여 슬롯을 변경할 수 없다
    ecInventorySlotOccupied = 2405,

    /// 장착된 아이템은 삭제할수 없다.
    ecInventoryEquippedItemNotRemove = 2406,

	/// 장착아이템은 나눌수 없다.
	ecInventoryEquipItemNotDivide = 2407,

	/// 유효하지 않은 인벤 타입
	ecInventoryInvalidInvenType = 2408,

    /// 인벤토리가 락이 걸려있습니다
    ecInventoryLock = 2409,

    // 잘못된 금고
    ecInventoryInvalidVault = 2410,

    // = 장비 관련
    
    /// 이미 장착 중인 아이템 장착 시도
    ecEquipItemAlreadyEquipped = 2502,

    /// 착용하지 않은 아이템 탈의 시도
    ecUnequipItemNotEquipped = 2503,

    /// 조각이 부족하여 장착할수 없습니다.
    ecEquipNotEnoughFragment = 2504,

    /// 레벨이 부족하여 입을수 없습니다.
    ecEquipNotEnoughLevel = 2505,


    ecEquipNotReprocess = 2506,

	// = Drop Item 관련

	/// 비석을 찾을수 없다.
	ecGraveStoneNotFound = 2601,

    /// 비석 hp가 아직 있다.
    ecGraveStoneNotMinHp = 2602,

    /// 비석의 hp가 없습니다.
    ecGraveStoneMinHp = 2703,

    // = 루팅 관련

    /// 루팅 정보가 없다.
    ecLootingInfoNotExist = 2701,

    /// 루팅 시간이 안됐다(시간부족).
    ecLootingNotCompleteTime = 2702,

    // = 아이템 관련

    /// 존재하지 않는 아이템이다
    ecItemNotExist = 2801,

    /// 재료 아이템이 아니다.
    ecItemNotElementItem = 2802,

    /// 재료 아이템이 아니다.
    ecItemNotRecipeItem = 2803,

    /// 유효하지 않은 재료 아이템
    ecItemInvalidElementItem  = 2804,

    /// 유효하지 않은 레시피 아이템
    ecItemInvalidRecipeItem  = 2805,

    /// 재료가 부족합나다
    ecItemNotEnoughElementItem = 2806,

    /// 레시피 완성 시간이 아니다(시간부족).
    ecItemRecipeNotCompleteTime = 2807,

    /// 재료 아이템이 충분하지 않습니다
    ecItemComponentNotEnough = 2808,

    /// 사용 등록된 레시피아이템이 아니다
    ecItemRecipeItemNotRegistered = 2809,

    /// 사용 안 함
    //ecItemNotUsed_1 = 2810,

    /// 사용 안 함
    //ecItemNotUsed_2 = 2811,

    /// 잘못된 SkillIndex 입니다.
    ecItemInvalidSkillIndex = 2812,

    /// 유효하지 않은 장비 아이템
    ecItemInvalidEquiptItem = 2813,

    /// 바로 만들수 있는 장비 아이템이 아니다.
    ecItemNotMakeEquipItem = 2814,

    /// 만들기에 실패(확율)
    ecItemEquipItemMakeFailed = 2815,

    /// 조각이 부족합니다.
    ecItemNotEnoughFragmentItem = 2816,

    /// 장비 아이템이 아니다.
    ecItemNotEquipItem = 2817,

    /// 장비아이템 강화 실패
    ecItemEquipItemUpgradeFaild = 2818,

    /// 장착 아이템 조각 다른 조각
    ecItemEquipItemInvalidFragment = 2819,

    /// 장비를 더이상 강화 할수 없습니다.
    ecItemMaxUpgradeEquipItem = 2820,

	/// 인벤토리안에 있는 아이템을 변화할수 없습니다.
	ecItemCannotChangeInventory = 2821,

	/// 탈,장착 할수 없는 상태 없습니다.
	ecItemCannotEquipOrUnEquipState = 2822,

	/// 아이템을 사용할수 없는.
	ecItemCannotUseableState = 2823,

	/// 재료 아이템만 팔수 있습니다.
	ecItemSellElementItem = 2824,

    /// 사용할수 없는 아이템 이다.
    ecItemNotUseItem = 2825,

    /// 아이템 사용 글로벌 쿨다운 타임이 지나지 않았다
    ecItemUseGlobalCoolDownTime = 2826,

    /// 아이템 사용 쿨다운 타임이 지나지 않았다
    ecItemUseCoolDownTime = 2827,

    /// 인챈트 할수 있는 슬롯이 부족하다
    ecItemNotEnoughEnchantSlot = 2828,

    /// 인첸트 실패
    ecItemEnchantFailed = 2829,

    /// 캐스팅 시간이 충분하지 않습니다.
    ecItemNotEnoughCastingTime = 2830,

    /// 분해 가능한 아이템이 아니다.
    ecItemNotReprocessableItem = 2831,

    /// 장착중인 아이템은 분해할수 없습니다.
    ecItemCannotReprocessEquippedItem = 2832,

    /// 아이템이 케스팅 중입니다.
    ecItemCasting = 2833,

    /// 퀘스트 아이템 아니다
    ecItemNotQuestItem = 2834,

    /// 아이템이 부족하여 사용할수 없다
    ecItemNotEnoughUseable = 2835,

    /// 아이템 사용시 타켓을 찾을수 없다
    ecItemTargetNotFound = 2836,

    /// 조각 갯수가 부족하다
    ecItemFragmentNotEnough = 2837,

    /// 너무 낡아서 분해할수 없습니다.(초라하고 강화 0)
    ecItemCannotReprocessBaseShabbyItem = 2838,

    /// 투기장에서는 귀한 주문서를 사용할수 없다
    ecItemUseNotBindRecallItemInArena = 2839,

    /// 사용 안 함
    //ecItemNotUsed_3 = 2840,

    /// 사용 안 함
    //ecItemNotUsed_4 = 2841,

    /// 장비아이템의 유효한 슬롯 인덱스가 아닙니다.
    ecItemNotInvalidEquipEnchatSlotIndex = 2842,

    /// 인첸트 아이템에 가지고 슬롯을 가지고 있지 않다
    ecItemEnchantHasSlotInvalidSlot = 2843,

    /// 게임머니가 부족하다
    ecItemUnenchantNotEnoughGameMoney = 2844,

    /// 더이상 인첸트를 할수 없습니다
    ecItemEnchantMaxLevel = 2845,

    /// 슬롯 확장 불가능 합니다..
    ecItemNotExtendIventorySlot = 2846,

	/// 유효한 탈것 아이템이 아닙니다
	ecItemInvalidVelicleItem = 2847,

	/// 유효한 글라이더 아이템이 아닙니다
	ecItemInvalidGliderItem = 2848,

	/// 수리 포인트가 부족하다
	ecItemNotEnoughForgeCoin = 2849,

	/// 수리 할 필요가 없다 
	ecItemFullUpgradeRate = 2850,

	/// 근처에 제작에 필요한 건물이 없다
	ecItemManufactureNotNearNeedBuilding = 2851,

    /// 장비에 필요한 아이템이 없다
    ecItemHasNotUpgradeNeedItem = 2852,
    
    /// 기능성 아이템이 아니다
    ecItemNotFunctionItem = 2853,

    /// 퀘스트 아이템은 버릴수 없습니다
    ecItemQuestItemNotRemove = 2854,

    // = 액션바

    /// 유효하지 않은 액션바입니다.
    ecInvalidActionBar = 2901,

    /// 락상태 액션바입니다.
    ecActionBarLock = 2902,

    // = 상태

    /// 기절상태입니다.
    ecStateCannotSkillCastState = 3001,

    /// 비석에서 루팅중입니다
    ecStateItemLooting = 3003,

	// = 거래

	/// 거래를 할수 없는 객체입니다.
	ecTradeCannotTradeObject = 3101,

	/// 자신이 거래 대기중인 상태입니다.
	ecTradeWaitSelfTradeState = 3102,

	/// 상대방이 거래 대기중인 상태입니다.
	ecTradeWaitOrderTradeState = 3103,

	/// 상대방과 거리가 멀어요
	ecTradeTargetFarDistance = 3104,

	/// 자신이 거래를 할수 없는 상태입니다.
	ecTradeCannotSelfTradeState = 3105,
	
	/// 상대방이 거래 요청을 받을수 없는 상태입니다.
	ecTradeCannotOrderTradeState = 3106,

	/// 상대방이 거래 요청을 취소 했습니다.
	ecTradeCancelRequestTrade = 3107,

	/// 유효하지 않은 거래 정보
	ecTradeInvalidTradeInfo = 3108,

	/// 확인 상태가 활성화입니다.
	ecTradeActivateConform = 3109,
	
	/// 이미 등록된 아이템 입니다.
	ecTradeAlreadyRegistItem = 3110,

	/// 래디상태에서는 거래 아이템을 변경할수 없습니다.
	ecTradeReadyCannotTradeItemsChange = 3111,

	/// 등록안된 아이템입니다.
	ecTradeNotRegistItem = 3112,

	/// 장착된 아이템은 거래 할수 없습니다.
	ecTradeCannotTradeEquipped = 3113,

	/// 래디 비활성 상태
	ecTradeInactiveReady = 3114,

	/// 자신의 인벤토리가 부족합니다.
	ecTradeSelfNotEnoughInventory = 3115,

	/// 상대방 인벤토리가 부족합니다.
	ecTradeOrderNotEnoughInventory = 3116,

	/// 돈이 부족합니다.
	ecTradeNotEnoughTradeGameMoney = 3117,

    /// 이미 거래 중입니다.
    ecTradeAlreadyTrade = 3118,

    /// 최대치를 넘어선 거래입니다(아이템 갯수)
    ecTradeMaxOverTradeItem = 3119,

	// = 은행거래

	/// 저축할 돈이 모자르다.
	ecBankDipositNotEnoughGameMoney = 3201,

	/// 출금할 돈이 모자르다
	ecBankWithdrawNotEnoughGameMoney = 3202,

    /// 오브젝트를 찾을수 없다
    ecBankNotFindBankObject = 3203,

    /// 은행 기능이 없는 오브젝트이다 .
    ecBankNotAbilltyBankObject = 3204,

    /// 오늘 출금금액을 오버했다
    ecBankOverTodayWithdraw = 3205,

	// = 퀘스트

	/// 이미 완료된 퀘스트입니다
	ecQuestAlreadyCompleteQuest = 3301,

	/// 없는 퀘스트이다
	ecQuestNotFindQuest = 3302,

	/// 완료되지 않은 퀘스트
	ecQuestNotCompleteQuest = 3303,

	/// 유효하지 않은 퀘스트이다.
	ecQuestInvalidQuest = 3304,

	/// 이미 받은 퀘스트이다.
	ecQuestAlreayAcceptedQuest = 3305,

	/// 유효하지 않은 보상품
	ecQuestInvalidRewardItem = 3306,

	/// Npc와 거리가 멀다
	ecQuestTargetTooFar = 3307,

	/// Npc정보와 틀리다
	ecQuestInvalidNpcInfo = 3308,

	/// 타겟을 찾을수 없다.
	ecQuestTargetNotFind = 3309,

    /// 선행 퀘스트를 수행하지 않았다
    ecQuestNotFindPreQuest = 3310,

    /// 카오틱이 부족하다.
    ecQuestNotEnoughCaotic = 3311,

    ///게임머니가 부족하다.
    ecQuestNotEnoughGameMoney = 3312,

    /// 레벨이 부족하다.
    ecQuestNotEnoughLevel = 3313,

    /// 유효하지 않은 퀘스트 미션을 가지고 있다.
    ecQuestInvalidMission = 3314,

    /// 완료된 운송 미션이다.
    ecQuestAlreadyTransportMission = 3315,

    /// 유효하지 않은 용병퀘스트
    ecQuestNotInvalidMercenaryQuest = 3316,

    /// 용병포인트가 부족합니다.
    ecQuestNotEnoughMercenaryPoint = 3317,

    /// 캐릭터 클래스가 틀립니다.
    ecQuestInvalidCharacterClass = 3318,

    /// 완료된 탐사 미션이다.
    ecQuestAlreadyProbMission = 3319,

    /// 탐사 미션지역이 아니다.
    ecQuestProbMissionNotRegion = 3320,

    /// 다시 받기에 충분한 시간이 안지났다(반복 퀘스트)
    ecQuestNotEnoughAcceptTime = 3321,

    /// 유효하지 않은 선택 아이템 이다
    ecQuestInvalidSelectItem = 3322,

    /// 수락할수있는 퀘스트 갯수를 넘었다
    ecQuestMaxOverAcceptCount = 3323,

    /// 유효하지 않은 선택 스킬
    ecQuestInvalidSelectSkill = 3324,

    /// 유효하지 않은 케릭터 레벨입니다.
    ecQuestInvalidCharacterLevel = 3325,

    // 사용 안함 = 3326,
    // 사용 안함 = 3327,

    /// 완료된 작동 퀘스트이다
    ecQuestAlreadyActiveMission = 3329,

    /// 보상할수 있는 부위의 아이템을 입고 있지 못했다
    ecQuestCannotFindRewardEquipPartItem = 3334,

    /// 보상할수 있는 등급의 아이템입 입고 있지 않습니다.
    ecQuestCannotUpgradeRewardEquipGrade = 3335,

    /// 보상할수 있는 레벨의 아이템입 입고 있지 않습니다.
    ecQuestCannotUpgradeRewardEquipLevel = 3336,

    /// 퀘스트를 수행할 수 있는 지역이 아닙니다
    ecQuestInvalidRegion = 3337,

	/// 필요한 수집 퀘스트가 없습니다.
	ecQuestNotExistNeedObtainQuest = 3338,

	/// 필요한 수집품을 모았습니다
	ecQuestAlreadyEnoughObtainQuestItem = 3339,

    /// 파티 멤버가 아니다
    ecQuestInNotPartyMember = 3340,

    /// 공유할수 없는 퀘스트
    ecQuestNotShareable = 3341,

    /// 퀘스트 준사람을 찾을수 없다
    ecQuestNotFindQuestPusher = 3342, 

    /// 필요한 방어구 아이템을 장착하지 않았다.
    ecQuestNotNeedArmorItemEquipped = 3343,

    /// 필요한 무기 아이템을 장착하지 않았다.
    ecQuestNotNeedWeaponItemEquipped = 3344,

	// = 채집

	/// 채집 시간이 완료 되지 않았다
	ecHarvestNotCompleteTime = 3401,
	
	/// 채집 할수없는 상태입니다.
	ecHarvestNotHarvestState = 3402,
	
	/// 채집 시작을 안했다.
	ecHarvestNotStartHarvest = 3403,

	/// 유효하지 않은 채집물
	ecHarvestInvalidHarvest = 3404,

	/// 채집한 아이템을 찾을수 없다.
	ecHarvestNotFindHarvestItem = 3405,

	/// 채집물과 거리가 멀다
	ecHarvestTargetTooFar = 3406,

	/// 현재 채집중이 아닙니다.
	ecHarvestCurrentNotHarvest = 3408,

	// = 보물

	/// 다른 사람에게 소유된 보물
	ecTreasureOrderOwnerTreasure = 3501,

	/// 상자와 거리가 멀다
	ecTreasureTargetTooFar = 3502,

	/// 보물상자 열기 시도를 안했다
	ecTreasureNotOpenTreasure = 3503,

	/// 상자 오픈 시간이 지나지 않았다
	ecTreasureNotOpenDelay = 3504,

	/// 보물상자에서 아이템을 찾을수 없다.
	ecTreasureNotFindItem = 3505,

	/// 유효하지 않은 채집물
	ecTreasureInvalidTreasure = 3506,

    /// 보물을 열수없는 상태이다
    ecTreasureCannotOpenState = 3507,

    /// 보물을 여는 중이 아니다
    ecTreasureIsNotOpening = 3508,

    /// 열린 보물상자가 아닙니다.
    ecTreasureIsNotOpen = 3509,

    // = 상정

    /// 상점 npc를 찾을수 없다
    ecStoreNotFindNpc = 3601,

    /// 물건을 파는 Npc가 아니다.
    ecStoreNotSellNpc = 3702,

    /// 파는 목록 리스트에 없다
    ecStoreNotFindSellItemList = 3703,

    /// 매입하는 Npc가 아니다.
    ecStoreNotBuyNpc = 3704,

    /// 돈이 모자르다
    ecStoreNotEnoughGameMoney = 3705,

    /// 판매 아이템 갯수가 모자르다
    ecStoreSellNotEnoughItemCount = 3706,

    /// 입고있는 옷은 팔수없다.
    ecStoreNotSellEquipped = 3707,

    /// 명점이 부족하다
    ecStoreNotEnoughArenaPoint = 3708,

	/// 거리가 멀다
	ecStoreNpcFarDistance = 3709,

	/// 대장장이 코인 부족하다
	ecStoreNotEnoughForgeCoin = 3711,

	/// 대장장이 코인 부족하다
	ecStoreNotEnoughEventCoin = 3712,

	/// 상점 파는(NPC 기준) 아이템이 아니다
	ecStoreNotSellItem = 3713,

	/// 상점 사는(NPC 기준) 아이템이 아니다
	ecStoreNotBuyItem = 3714,

    /// 되사기 아이템이 없다
    ecStoreNotExistBuyBackItem = 3715,

    // = 파티
    /// 유저를 찾을수 없다.
    ecPartyNotFindUser = 3801,
    
    /// 파티 최대 인원수입니다.
    ecPartyMaxOverUser = 3802,

    /// 이미 파티에 가입되어 있습니다.
    ecPartyAlreadyMember = 3803,

    /// 파티 멤버가 아니다
    ecPartyIsNotMember = 3804,

    /// 권한이 부족하다.
    ecPartyNotEnoughMemberGrade = 3805,

    /// 잘못된 초대
    ecPartyInvalidInvite = 3806,

    /// 파티를 찾을수 없습니다
    ecPartyNotFindParty = 3807,

    /// 자기 자신은 초대할수 없다.
    ecPartyNotInviteSelf = 3808,

    /// 자기 자신은 강퇴할수 없다
    ecPartyNotKickSelf = 3809,

    /// 이미 파티에 참가돼어 있다
    ecPartySelfJoined = 3810,

    /// 퍼블릭 파티 멤법이다.
    ecPartyPublicPartyMember = 3811,

    /// 파티인원수가 많습니다.(레이드에서->일반파티로 전환할때)
    ecPartyIsOverPartyMemberRaidPartyToParty = 3812,

    /// 유효하지 않은 파티 타입입니다.
    ecPartyInvalidPartyType = 3813,

    /// 퍼블릭 파티는 변경될수 없습니다.
    ecPartyNotChangePublicParty = 3814,

    /// 파티그룹을 이동할수 없는 파티입니다
    ecPartyGroupNotChangeInvalidPartyType = 3815,

    /// 해당 그룹의 위치는 이미 유효하지 않습니다.
    ecPartyInvalidGroupPosition = 3816,

    /// 한사람이 위치를 교환할수 없다
    ecPartyGroupNotSwitchSameMember = 3817,

    // = 설치물

    /// 설치물 아이템이 아니다.
    ecAnchorNotAnchorItem = 3901,

    /// 유효하지 않은 설치물입니다.
    ecAnchorInvalidItem = 3902,

    /// 빌드가 이미 완료된 설치물입니다.
    ecAnchorAlreadyBuildAnchor = 3903,

    /// 설치물을 찾을수 없다
    ecAnchorNotFind = 3904,

    /// 설치물 재료가 충분하지 않다
    ecAnchorNotEnoughBuildConsumeItems = 3905, 

    /// 설치물 주인이 존재한다.
    ecAnchorExistOwner = 3906,

    /// 연료 아이템이 아니다.
    ecAnchorIsNotSupportItem = 3907,

    /// 설치물 슬롯이 가득 차있다.
    ecAnchorFullInventory = 3908,

    /// 설치물 슬롯에 아이템을 찾을수 없다.
    ecAnchorNotFindItem = 3909,

    /// 유효하지 않은 효과이다
    ecAnchorInvalidEffect = 3910,

    /// 유효하지 않은 타겟타입이다
    ecAnchorInvalidEffectTargeting = 3911,

    /// 효과를 사용하는데 글로벌 쿨타임이 지나지 않았다
    ecAnchorNotEnoughGlobalCoolTime = 3912,

    /// 효과를 사용하는데 쿨타임이 지나지 않았다
    ecAnchorNotEnoughCoolTime = 3913,

    /// 유효하지 않은 타겟이다
    ecAnchorInvalidTarget = 3914,

    /// 유효하지 않은 거리이다
    ecAnchorInvalidDistance = 3915,

    /// effect 재료 아이템이 부족하다.
    ecAnchorNotEnoughEffectElementItem = 3916,

    /// 마나가 부족합니다.
    ecAnchorNotEnoughMana = 3917,

    /// 조정할수 없는 설치물입니다
    ecAncourNotControll = 3918,

    /// 근처에 없어야 할 설치물이 있습니다(모델링끼리 겹칠때)
    ecAnchorNearDistanceBuildAnchor = 3919,

    /// 근처에 필요한 설치물이 없습니다.
    ecAnchorNeedNotBuildAnchor = 3920,

    /// 길드 멤버만 지을수 있습니다
    ecAnchorNotBuildNotGuildMember = 3921,

    /// 토대 상태가 아니다
    ecAnchorNotFoundation = 3922,

    /// 에너지가 부족 합니다.
    ecAnchorNotEnoughHp = 3923,

    /// 건설할수 없는 설치물입니다.
    ecAnchorNotBuild = 3924,

    /// 인벤토리가 없다
    ecAnchorNotExistInventory = 3925,

    /// 인벤토리 사용할수 있는 권한이 없다.
    ecAnchorNotUsableGradeInventory = 3926,

    /// 개인용 빌딩에서만 귀환위치를 추가할수 있다.
    ecAnchorPrivateOwnerAddBindRecall = 3927,

    /// 이미 귀환위치가 저장된곳이다.
    ecAnchorAlreadyAddBindRecall = 3928,

    /// 건물이 완료가 안되어서 귀환을 지정할수 없다.
    ecAnchorNotAddBindRecallNotComplete = 3929,

    /// 설치물 주인이 아니다
    ecAnchorNotOwner = 3930,

    /// 귀환을 지정할수 없는 건물이다.
    ecAnchorCanNotBindRecallAnchor = 3931,

    /// 존재하지 않는 귀환입니다.
    ecAnchorNotExistBindRecall = 3932,
    
    /// 발사가능한 스킬이 아니다
    ecAnchorNotFireSkill = 3933,

    /// 주변에 필요한 건물이 완성이 되어 있어야 합니다.
    ecAnchorNotCompleteNearNeedAnchor = 3934,

    /// 주변에 필요한 건물을 활성화 시켜야 합니다.
    ecAnchorNotActivateNearNeedAnchor = 3935,

	/// 건설할 상태가 아니다.
	ecAnchorNotEnoughBuildCondition = 3936,

	/// 텔레포트 할수 있는 건물이 아니다
	ecAnchorNotTeleportBuilding = 3937,

	/// 텔레포트를 할수 있는 권한이 없다.
	ecAnchorTeleportNotEnoughGrade = 3938,

	/// 활성화 되어 있지 않다.
	ecAnchorTeleportNotActivate = 3939,

	/// 앵커 hp가 아직 있다.
	ecAnchorNotMinHp = 3940,

	/// 앵커에 아이템이 없습니다.
	ecAnchorHasNotItem = 3941,

    /// 선택 제작을 지원 안한다.
    ecAnchorNotSelectProduction = 3942,

    /// 선택 제작 레시피를 가지고 있지 않다.
    ecAnchorHasNotSelectRecipe = 3943,

    /// 최대 선택제작 할수 있는 수를 넘었다
    ecAnchorOverCountCreateSelectRecipe = 3944,

    /// 최소 선택제작 갯수 이하이다
    ecAnchorMinCountCreateSelectRecipe = 3945,

    /// 선택 제작에 필요한 아이템을 가지고 있지않다
    ecAnchorHasNotNeedComponentsSelectRecipe = 3946,

    /// 선택 제작에 필요한 인벤토리 공간을 가지고있지 않다.
    ecAnchorNotEnoughInventorySelectRecipe = 3947,

    /// 이미 제작중이다
    ecAnchorAlreadySelectRecipeProduction = 3948,

    /// 문을 가지고 있지 않다
    ecAnchorHasNotDoor = 3949,

    /// 완성되지 않아 문을 사용할수 없다
    ecAnchorNotCompleteNotToggleDoor = 3950,

    /// 문을 사용할수 있는 권한이 없다
    ecAnchorToggleDoorNotEnoughGrade = 3951,

    /// 잘못된 인벤 타입
    ecAnchorInvalidInvenType = 3952,

    /// 집어넣을수 없는 인벤타입입니다
    ecAnchorNotAddInventory = 3953,

    /// 넣을수 없는 아이템 입니다
    ecAnchorNotAddItem = 3954,

    /// 인벤토리를 사용할수 없는 상태이다
    ecAnchorNotUseInventoryByBuildingState = 3955,

    /// 지원하지 않은 인벤
    ecAnchorNotSupportInventory = 3956,

    /// 선택제작할수 있는 갯수(종류)를 넘었다
    ecAnchorOverSelectProductionType = 3957,

    /// 은행을 이용할수 있는 권한이 없다
    ecAnchorBankNotEnoughGrade = 3958,

    /// 건물이 비활성화 상태라 은행을 이용할수 없다
    ecAnchorNotActivateBank = 3959,

    /// 은행 기능이 없습니다
    ecAnchorNotBankAbillity = 3960,

    /// 완성된 공용건물은 아이템을 뺄수없습니다
    ecAnchorCommonBuildingNotOutItem = 3961,

    /// 귀환을 사용할수 없는 상태입니다
    ecAnchorNotBindRecallState = 3962,

    /// 용병을 파지 않습니다
    ecAnchorNotSellGuard = 3963,

    /// 용병이 오버 패치 됐습니다. 
    ecAnchorOverGuard = 3964,

    /// 용병을 이용할수 있는 권한이 없다
    ecAnchorGuardNotEnoughGrade = 3965,

    /// 건물이 활성화 용병을 사용할수 있다
    ecAnchorGuardNotActivate = 3966,

    // = 탈거

    /// 글라이더 탈 준비를 할수 없는 상태이다
    ecGliderCannotReadyMountState = 4001,

    /// 글라이더 탈수 없는 상태이다
    ecGliderCannotMountState = 4002,

    /// 글라이더를 타고 있는 상태가 아닙니다.
    ecGliderIsNotGliding = 4003,

	/// 유효하지 않은 글라이더 입니다.
	ecVehicleInvalidGlider = 4004,

	/// 없는 글라이더이다
	ecGliderNotFind = 4005,

	/// 돈이 부족하다
	ecGliderNotEnoughGameMoney = 4006,

	/// 내구도가 0입니다.
	ecGliderZeroDurability = 4007,

    /// 운송 수단을 탈수 없는 상태이다
    ecVehicleCannotMountState = 4101,

    /// 운송 수단에서 내릴수 없는 상태이다
    ecVehicleCannotDismountState = 4102,

	/// 운송 수단이 선택되어 있지 않습니다.
	ecVehicleNotSelectVehicle = 4103,

	/// 유효하지 않은 운송 수단입니다.
	ecVehicleInvalidVehicle = 4104,

	/// 찾을수 없는 운송 수단입니다.
	ecVehicleNotFind = 4105,

    // = 채팅 관련

    /// 상대방을 찾을수 없다
    ecChattingNotFindPlayer = 4201,

    // = 길드

    /// 길드 최대 인원수입니다.
    ecGuildMaxOverUser = 4302,

    /// 이미 길드에 가입되어 있습니다.
    ecGuildAlreadyMember = 4303,

    /// 길드 멤버가 아니다
    ecGuildIsNotMember = 4304,

    /// 권한이 부족하다.
    ecGuildNotEnoughMemberGrade = 4305,

    /// 잘못된 초대
    ecGuildInvalidInvite = 4306,

    /// 길드를 찾을수 없습니다
    ecGuildNotFindGuild = 4307,

    /// 자기 자신은 초대할수 없다.
    ecGuildNotInviteSelf = 4308,

    /// 자기 자신은 강퇴할수 없다
    ecGuildNotKickSelf = 4309,

    /// 이미 길드에 참가돼어 있다
    ecGuildSelfJoined = 4310,

    /// 용병포인트가 충분하지 못합니다.
    ecGuildNotEnoughMercenaryPoint = 4311,

    /// 길드명이 너무 짧다
    ecGuildNameTooShort = 4312,

    /// 길드명에 허용하지 않는 문자 포함(공백, 제어문자, 구두점 허용 안함)
    ecGuildInvalidName = 4313,

    /// 현재 길드 등급에 가질수 있는 멤버를 초과했다.
    ecGuildMercenaryGradeNotInvite = 4314,

    /// 이미 관계를 가지고 있다
    ecGuildAlrealyHasRelationship = 4315,

    /// 관계를 가지고 있지 않다
    ecGuildNotHasRelationship = 4316,

    /// 자신의 길드는 관계를 추가할수 없다
    ecGuildSelfGuildNotAddRelationship = 4317,

    /// 길드 지원자가 아니다
    ecGuildNotApplicant = 4318,

    /// 길드 지원자이다
    ecGuildApplicant = 4319,

    /// 길드 인벤토리에 아이템이 없다
    ecGuildNotFindInventoryItem = 4320,

    /// 잘못된 금고 ID
    ecGuild_InvalidVault = 4321,

    /// 너무 많은 금고
    ecGuild_TooManyVault = 4322,

    /// 금고 이름이 없음
    ecGuild_VaultNameIsEmpty = 4323,

    /// 돈 부족
    ecGuild_NotEnoughMoney = 4324,

    /// 잘못된 Rank ID
    ecGuild_InvalidRankId = 4325,

    /// 등급 이름이 없음
    ecGuild_RankNameIsEmpty = 4326,

    /// 등급이 너무 많음
    ecGuild_TooManyRank = 4327,

    /// 유효한 스킬이 아니다
    ecGuildInvalidSkill = 4328,

    /// 이미 활성화된 스킬
    ecGuildAreadyActivateSkill = 4329,

    /// 길드레벨이 충분하지 않습니다.
    ecGuildNotEnoughLevel = 4330,

    /// 길드 스킬 포인트가 부족합니다.
    ecGuildNotEnoughSkillPoint = 4331,


    // = 메일관련

    /// 메일 보내는데 돈이 부족하다.
    ecMailNotEnoughMoney = 4401,

    /// 메일 첨부 아이템이 유효하지 않다.
    ecMailInvalidSendMailItem = 4402,

    /// 자신에게는 메일을 보낼수 없습니다.
    ecMailNotSendSelf = 4403,

    /// 메일 동기화 중입니다.
    ecMailSync = 4404,

    /// 메일이 이미 동기화 됐다.
    ecMailAlreadySync = 4405,

    /// 유효하지 않은 메일 입니다.
    ecMailInvalidMail = 4406,

    /// 메일 NPC가 아니다(메일 기능 없음).
    ecMailCannotMailable = 4407,

    // = 경매 관련
    /// 유효하지 않은 옥션 정보입니다.
    ecAuctionInvalidAuctionInfo = 4501,

    /// 장비하고 있는 아이템은 팔수가 없습니다.
    ecAuctionCannotSellEquippedItem = 4502,

    /// 유효하지 않는 아이템 입니다.
    ecAuctionInvalidItem = 4503,

    /// 옥션 NPC를 찾을수 없습니다.
    ecAuctionNotFindNpc = 4504,

    /// 옥션 NPC가 아니다(옥션 기능 없음).
    ecAuctionCannotAuctionable = 4505,

    /// 유효하지 않은 옥션 정보이다.
    ecAuctionInvalidAuction = 4506,

    /// 돈이 모자르다.
    ecAuctionNotEnoughGameMoney = 4507,

    /// 현재 경매값보다 적은값을 냈다
    ecAuctionBidHigherCurrentBid = 4508,

    /// 자기 자신의 옥션이 아니다
    ecAuctionNotSelfAuction = 4509,

    /// 자기 자신의 물건에 경매할수 없다
    ecAuctionSelfNotBidAndBuyOut = 4510,


    // = 투기장
    /// 유효하지 않다.
    ecArenaInvalidArena = 4601,

    /// 이미 도전되어 있는 상태이다.
    ecArenaAlreayChallenge = 4602,

    /// 투기장 생성 실패
    ecArenaMapCreateFaild = 4603,

    /// 매칭 상태입니다
    ecArenaMatcher = 4604,

    /// 투기장 서버에 입장되어 있는 상태가 아니다.
    ecArenaNotEnterArenaServer = 4605,

    /// 입장 가능한 레벨이 아니다(20레벨 이상 가능)
    ecArenaNotEnterableLevel = 4606,

    /// 탈영병은 도전할수 없다.
    ecArenaNotChallengDeserter = 4607,

    /// 죽은 상태에서는 입장 할수없습니다.
    ecArenaDeadNotJoin = 4608,

    /// 투기장에서느 말을 탈수없다
    ecArenaNotEnterdVehicleMount = 11005,

    /// 투기장에서는 글라이더를 탈수없다
    ecArenaNotEnterdGliderMount = 11006,


    // = 캐스팅

    /// 이미 캐스팅 중이다
    ecCastAlreadyCasting = 4701,

    // = Device

    /// 잘못된 Device
    ecDeviceInvalidDevice = 4801,

    /// 필요한 아이템을 소지하고 있지 않아 장치를 작동시킬 수 없다
    ecDeviceCannotActivateBecauseHaveNoItem = 4802,


    // = Messenger
    /// 이미 친구
    ecMessengerAlreadyBuddy = 4901,

    /// 유저를 찾을수 없다
    ecMessengerNotFindUser = 4902,

    /// 자신과는 친구등록을 할수 없다.
    ecMessengerSelfNotBuddy = 4903,

    /// 친구가 아니다
    ecMessengerNotBuddy = 4904,

    /// 이미 차단하였다
    ecMessengerAlreadyBlocked = 4905,

    /// 자기 자신을 차단할 수 없다
    ecMessengerCannotBlockSelf = 4906,


    // = Duel
    // 결투 상대를 찾을수 없다
    ecDuelTargetNotFind = 5000,

    // 상대방과 거리가 멀다
    ecDuelTargetFarDistance = 5001,

    // 올바른 결투 대상자가 아니다
    ecDuelTargetInvalid = 5002,

    // 이미 결투중이다
    ecDuelAlready = 5003,

    // 상대방이 결투중이다
    ecDuelTargetAlready = 5004,

    // 카오상태에서는 결투를 할수 없다
    ecDuelChaoStateNotPlay = 5005,

    // 상대방이 카오상태라 결투를 할수 없다
    ecDuelTargetChaoStateNotPlay = 5006,

    // 결투중에는 사용할수 없는 스킬입니다
    ecDuelNotCastingSkill = 5007,

    // = 제작및 분해....
    // 타겟을 찾을수 없습니다.
    ecCraftNotFindTarget = 5100,

    // 타겟 정보가 유효하지 않습니다.
    ecCraftInvalidTaget = 5101,

    // 분해 기능이 없습니다.
    ecCraftCanNotReprocess = 5102,

    // Npc가 해당 레시피를 가지고 있지 않다. 
    ecCraftNpcHasNotRecipe = 5103,

    // 장비 레시피를 사용할수 없습니다.
    ecCraftNotEquipRecipe = 5104,

    // 분해 할수 없는 아이템 
    ecCraftNotReprocessItem = 5105,

    /// 해당 크래프트 기능을 가지고 있는 Npc가 아니다
    ecCraftNpcHasNotCraftFunction = 5106,

    /// 해당 레시피 제조법을 가지고 있지 않습니다.
    ecCraftHasNotRecipeItem = 5107,

    //  = 칭호관련
    // 가지고 있는 칭호가 아니다
    ecTitleHasNotCharacterTitle = 5201,
    // 이미 가지고 있는 칭호
    ecTitleAlreadyCharacterTitle = 5201,

    // = 치트 관련
    ///  잘못된 커맨트
    ecCheatInvalidCommand = 9900,
    ///  잘못된 파라미터
    ecCheatInvalidParam = 9901,
    /// 타겟을 찾을수 없다. 
    ecCheatNotFindTarget = 9902,
    /// 치트 등급이 모자르다
    ecCheatNotEnoughGrade = 9903,
    /// 유효하지 않은 타겟
    ecCheatInvalidTarget = 9904,
    /// 유효하지 않은 상태이다
    ecCheatInvalidState = 9905,

    // = 월드맵 관련(서버 내부에서 사용)

    /// 월드맵을 찾을 수 없다
    ecWorldMapNotFound = 10001,

    /// 월드맵에서의 NPC가 올바르지 않다
    ecWorldMapInvalidNpc = 10002,

    /// 이미 다른 월드맵에 입장 중이다(월드맵 -> 월드맵, 던전 -> 던전)
    ecWorldMapAlreadyEntered = 10003,

    /// 월드맵에 입장하지 않았다
    ecWorldMapNotEntered = 10004,

    /// 월드맵에서의 Harvest가 올바르지 않다
    ecWorldMapInvalidHarvest = 10005,

    /// 월드맵에서의 Treasure가 올바르지 않다
    ecWorldMapInvalidTreasure = 10006,

    /// 월드맵에서의 Dungeon가 올바르지 않다
    ecWorldMapInvalidDungeon = 10007,

    /// 월드맵에서의 Device가 올바르지 않다
    ecWorldMapInvalidDevice = 10008,

    // = 던전 관련

    /// 던전 정보가 올바르지 않다
    ecDungeonInvalid = 11001,

    /// 던전을 찾을 수 없다
    ecDungeonNotFound = 11002,

    /// 던전 입장 조건이 맞지 않아 입장할 수 없다
    ecDungeonNoPermission = 11003,

    /// 던전에 입장 중이 아니다
    ecDungeonNotEntered = 11004,

    /// 던전에서는는 말을 탈수없다
    ecDungeonNotEnterdVehicleMount = 11005,

    /// 던전서는 글라이더를 탈수없다
    ecDungeonNotEnterdGliderMount = 11006,


    // = 텔레포트 관련

    /// 텔레포트할 수 없다
    ecTeleportNotAvailable = 12001,

    /// 돈이 부족하여 텔레포트할 수 없다
    ecTeleportNotEnoughGameMoney = 12002,

    /// 귀환을 더이상 저장 할수 없다
    ecTeleportMaxOverBindRecall = 12003,

    /// 전투 상태일때는 오벨리스크를 사용할수 없습니다
    ecTeleportNotUseObeliskPlayerCombatState = 12004,

    // = Obelisk 관련

    /// 잘못된 오벨리스크
    ecWorldMapInvalidObelisk = 12101,

    // = Shard 관련

    /// 잘못된 Shard
    ecShardInvalid = 13001,

    /// Shard를 선택하지 않았다
    ecShardNotSelected = 13002,

    // = 서버 상태 관련

    /// DB Proxy 서버가 다운되었음
    ecDbProxyServerIsDown = 63001,

    /// 로그인 서버가 다운되었음
    ecLoginServerIsDown = 63002,

    /// 존 서버가 다운되었음
    ecZoneServerIsDown = 63003,

    // = 기타

    /// 데이터베이스 오류
    ecDatabaseInternalError = 64001,

    /// 서버 내부 오류(복구 불가능)
    ecServerInternalError = 64002,

    // = server only

    /// 서버 인증 실패
    ecServerAuthenticateFailed = 65534,

    ecWhatDidYouTest = 65535,

    // = 클라이언트 관련

    /// 시간 초과
    ecClientTimeout = 62001,

    /// 연결할 수 없다
    ecClientConnectionFailed = 62002,

    /// 이미 요청 중이다
    ecClientAlreadyRequested = 62003,

    /// 서버에 연결되지 않았다
    ecClientNotConnected = 62004,
};


inline bool isValid(ErrorCode ec) {
    return (ecOk <= ec) && (ec <= USHRT_MAX);
}


inline bool isSucceeded(ErrorCode ec) {
    assert(isValid(ec));
    return ecOk == ec;
}


inline bool isFailed(ErrorCode ec) {
    assert(isValid(ec));
    return !isSucceeded(ec);
}


template <typename T>
inline ErrorCode toErrorCode(T ec)
{
    return static_cast<ErrorCode>(ec);
}

} // namespace gideon {

namespace sne { namespace core {

    inline OStream& operator<<(OStream& lhs, gideon::ErrorCode rhs)
    {
        lhs << static_cast<uint16_t>(rhs);
        return lhs;
    }


    inline IStream& operator >> (IStream& lhs, gideon::ErrorCode& rhs)
    {
        uint16_t value;
        lhs >> value;
        rhs = static_cast<gideon::ErrorCode>(value);
        return lhs;
    }

}} // namespace sne { namespace core {