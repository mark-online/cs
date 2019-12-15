#pragma once

#include "ObjectInfo.h"
#include "UserId.h"
#include "Money.h"
#include "Time.h"
#include "CharacterClass.h"
#include "WorldInfo.h"
#include "GuildInventoryInfo.h"
#include "GuildLogInfo.h"
#include "SkillInfo.h"
#include "LevelInfo.h"
#include <cassert>

namespace gideon {

const GameMoney defaultDayMaxGuildWithdraw = 1000;
const GameMoney createGuildMoney = byGold(1);
const GameMoney unlimitGuildWithdraw = 0xffffffffffffffff;
const GameMoney deActivateSkillFee = 200000; // 20G   

typedef uint32_t GuildId;

const GuildId invalidGuildId = 0;

inline bool isValidGuildId(GuildId id)
{
    return invalidGuildId != id;
}

typedef uint32_t GuildFame;

/**
 * @enum GuildOrganization
 */
enum GuildOrganization
{
    goGuard,
    goAssault,
    goPolice,
    goEncomienda
};


/**
 * @enum GuildMemberPosition
 */
enum GuildMemberPosition
{
    gmpUnknown = 0,
    gmpGuildMaster = 1, // 길드 마스터
    gmpLord = 2, // 영주
    gmpConsul = 3, // 집정관
    gmpSteward = 4, // 집사
    gmpCaptainGuard = 5, // 친위대장
    gmpCaptainAssault = 6, // 돌격대장
    gmpCaptainPolice = 7, // 치안대장
    gmpCaptainKnight = 8, // 기사 단장
    gmpGuardMember = 9, // 친위대
    gmpAssaultMember = 10, // 돌격대
    gmpPoliceMember = 11,  // 치안대
    gmpKnightMember = 12, // 기사단원
    gmpNone = 13, // 직무없음
};


/**
 * @enum GuildAbillity
 */
enum GuildAbillity
{
    gaNone = 0x00000000, // 없음
    gaGuildInvenInput = 0x00000001, // 길드 창고 넣기
    gaGuildInvenOutput = 0x00000002, // 길드 창고 빼기
    gaGuildInvite = 0x00000004, // 초대
    gaGuildKick = 0x00000008, // 강퇴
    gaGuildNotice = 0x00000010, // 공지
    gaGuildRelaytionship = 0x00000020, // 외교
    gaGuildKill = 0x00000040, // 척살령
    gaGuildAuthority= 0x00000080, // 인사권'
    gaGuildBatchMilitarUint = 0x00000100, // 부대 배치 
    gaTexRate = 0x00000200, // 세율
    gaBuildGuildBuilding = 0x00000400, // 길드 건물 건
};


/**
 * @enum GuildMemberGrade
 */
enum GuildMemberGrade
{
    gmgUnknown = 0,
    gmgMedium = 1,
    gmgHigher = 2,
    gmgImportant = 3,
};


enum GuildProperties
{
    minGuildNameLength = 4,
    maxGuildNameLength = 15,
    maxGuildIntroduction = 254,
    maxGuildNotice = 254,

    maxGuildRankNameLength = 10, //< 최대 길드 등급 이름 길이
    unlimitedGoldWithdrawlPerDay = 0, //< 자금 인출 일일 한도 제한 없음
    unlimitedItemWithdrawlPerDay = 0, //< 아이템 인출 일일 한도 제한 없음

    minGuildRankCount = 3,
    maxGuildRankCount = 10
};

/// RPC type for guild-name (UNICODE supported)
typedef sne::srpc::RpcStringType<std::wstring, maxGuildNameLength> GuildName;

/// RPC type for guild-introduction (UNICODE supported)
typedef sne::srpc::RpcStringType<std::wstring, maxGuildIntroduction> GuildIntroduction;

/// RPC type for guild-notice (UNICODE supported)
typedef sne::srpc::RpcStringType<std::wstring, maxGuildIntroduction> GuildNotice;

typedef sne::srpc::RpcStringType<std::wstring, maxGuildRankNameLength> GuildRankName;

typedef uint32_t GuildMarkCode;
const GuildMarkCode invalidGuildMarkCode = 0;


inline GuildMarkCode makeGuildMarkCode(uint32_t backgroundCode, uint32_t patternCode, uint32_t markCode)
{
    return (backgroundCode << 16) | (patternCode << 8) | markCode;
}


inline void parseGuildMarkCode(uint32_t& backgroundCode, uint32_t& patternCode, uint32_t& markCode,
                               GuildMarkCode guildMarkCode)
{
    backgroundCode = (guildMarkCode & 0x00FF0000) >> 16;
    patternCode = (guildMarkCode & 0x0000FF00) >> 8;
    markCode = (guildMarkCode & 0x000000FF);
}


/**
 * @enum GuildRankRight
 * 길드 등급 권한
 */
enum GuildRankRight
{
    grrEmpty = 0,

    grrChat = 0x00000001, //< 길드 대화
    grrOfficerChat = 0x00000002, //< 관리자 대화

    grrPromote = 0x00000010, //< 승급
    grrDemote = 0x00000020, //< 강등
    grrInvite = 0x00000040, //< 초대(가입)
    grrKick = 0x00000080, //< 추방(탈퇴)

    grrEditIntroduction = 0x00010000, //< 소개글 편집
    grrEditMotd = 0x00020000, //< 공지사항 편집
    grrEditRanks = 0x00040000, //< 등급 편집
    grrSetDiplomacy = 0x00080000, //< 외교 설정
    
    grrActivateSkill = 0x01000000, //< 스킬 활성화
    
    grrMoneyWithdrawal = 0x10000000, //< 금고 출금 가능
    grrVaultPurchase = 0x20000000, //< 금고 구매
    grrEditVaultName = 0x40000000, //< 금고 이름 변경

    grrAll = 0xFFFFFFFF,

    grrGuildMaster = grrAll,
    grrOfficer = grrAll & ~(grrMoneyWithdrawal | grrVaultPurchase | grrEditVaultName | grrActivateSkill),
    grrVeteran = grrChat | grrInvite,
    grrRegular = grrChat,
    grrGreen = grrChat
};


/**
 * @enum GuildBankRights
 * 길드 은행 권한
 */
enum GuildBankRights
{
    gbrEmpty = 0,

    gbrViewVault = 0x01, //< 금고 보기
    gbrItemDeposit = 0x02, //< 아이템 저장
    gbrItemWithdrawal = 0x04, //< 아이템 인출

    gbrAll = 0xFF
};


/**
 * @struct GuildBankVaultRightInfo
 * 금고별 권한 정보
 */
struct GuildBankVaultRightInfo
{
    GuildBankRights rights_;
    uint32_t itemWithdrawalPerDay_; //< 아이템 인출 일일 한도

    static GuildBankVaultRightInfo forGuildMaster() {
        return GuildBankVaultRightInfo(gbrAll, uint32_t(unlimitedItemWithdrawlPerDay));
    }

    explicit GuildBankVaultRightInfo(
        GuildBankRights rights = gbrEmpty, uint32_t itemWithrawalPerDay = 0) :
        rights_(rights),
        itemWithdrawalPerDay_(itemWithrawalPerDay) {}

    bool hasRight(GuildBankRights right) const {
        return (rights_ & right) != 0;
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & rights_ & itemWithdrawalPerDay_;
    }
};


/// 길드 은행 금고별 권한(인덱스 == VaultId)
typedef sne::srpc::RVector<GuildBankVaultRightInfo> GuildBankVaultRightInfos;


/// 길드 등급 아이디(순서, 낮을 수록 등급이 높다)
typedef int8_t GuildRankId;
static const GuildRankId invalidGuildRankId = -1;
static const GuildRankId firstGuildRankId = 0;

/**
 * @enum GuildDefaultRanks
 * 기본 길드 등급
 */
enum GuildDefaultRanks
{
    gdrGuildMaster = firstGuildRankId,
    gdrOfficer,
    gdrVeteran,
    gdrRegular,
    gdrGreen,
    gdrCount
};


/**
 * @struct GuildRankInfo
 * 길드 등급
 */
struct GuildRankInfo
{
    GuildRankId rankId_; //< 랭크 순위
    GuildRankName name_;
    GuildRankRight rights_; //< 권한 bits
    uint32_t goldWithdrawalPerDay_; //< 자금 인출 일일 한도(골드 단위)
    GuildBankVaultRightInfos vaultRights_; //< 금고별 권한 설정

    static GuildRankInfo forGuildMaster() {
        return GuildRankInfo(gdrGuildMaster, grrGuildMaster, uint32_t(unlimitedGoldWithdrawlPerDay));
    }

    static GuildRankInfo forOfficer() {
        return GuildRankInfo(gdrOfficer, grrOfficer, 0);
    }

    static GuildRankInfo forVeteran() {
        return GuildRankInfo(gdrVeteran, grrVeteran, 0);
    }

    static GuildRankInfo forRegular() {
        return GuildRankInfo(gdrRegular, grrRegular, 0);
    }

    static GuildRankInfo forGreen() {
        return GuildRankInfo(gdrGreen, grrGreen, 0);
    }

    explicit GuildRankInfo(GuildRankId rankId = invalidGuildRankId, GuildRankRight rights = grrEmpty,
        uint32_t goldWithdrawalPerDay = 0) :
        rankId_(rankId),
        rights_(rights),
        goldWithdrawalPerDay_(goldWithdrawalPerDay) {}

    bool isValid() const {
        return (rankId_ > invalidGuildRankId);
    }

    bool isMasterRight() const {
        return rights_ == grrGuildMaster;
    }

    bool isMasterRank() const {
        return rankId_ == gdrGuildMaster;
    }

    bool hasRight(GuildRankRight right) const {
        return (rights_ & right) != 0;
    }

    bool hasVaultRight(VaultId id) const {
        return isValidVaultId(id) && (size_t(id) < vaultRights_.size());
    }

    bool hasRight(VaultId id, GuildBankRights right) const {
        if (rights_ == grrGuildMaster) {
            return true;
        }
        if (! hasVaultRight(id)) {
            return false;
        }
        return vaultRights_[id].hasRight(right);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & rankId_ & name_ & rights_ & rights_ & goldWithdrawalPerDay_ & vaultRights_;
    }
};


/// 길드 등급 목록(index == RankId)
typedef sne::srpc::RVector<GuildRankInfo> GuildRankInfos;


inline GuildRankInfos& fillDefaultGuildRanks(GuildRankInfos& infos)
{
    infos.clear();
    infos.reserve(gdrCount);
    infos.push_back(GuildRankInfo::forGuildMaster());
    infos.push_back(GuildRankInfo::forOfficer());
    infos.push_back(GuildRankInfo::forVeteran());
    infos.push_back(GuildRankInfo::forRegular());
    infos.push_back(GuildRankInfo::forGreen());
    return infos;
}


inline bool isValidGuildRankId(GuildRankInfos& rankInfos, GuildRankId rankId)
{
    return (firstGuildRankId <= rankId) && (rankId < static_cast<GuildRankId>(rankInfos.size()));
}


inline void deleteGuildRankInfo(GuildRankInfos& rankInfos, GuildRankId rankId)
{
    bool isDeleted = false;
    GuildRankInfos::iterator pos = rankInfos.begin();
    while (pos != rankInfos.end()) {
        GuildRankInfo& rankInfo = *pos;
        if (rankInfo.rankId_ == rankId) {
            pos = rankInfos.erase(pos);
            isDeleted = true;
        }
        else {
            if (isDeleted) {
                --rankInfo.rankId_;
            }
            ++pos;
        }
    }
}


inline bool swapGuildRankInfo(GuildRankInfos& rankInfos, GuildRankId rankId1, GuildRankId rankId2)
{
    if ((! isValidGuildRankId(rankInfos, rankId1)) || (! isValidGuildRankId(rankInfos, rankId2))) {
        return false;
    }

    std::swap(rankInfos[rankId1].rankId_, rankInfos[rankId2].rankId_);
    std::swap(rankInfos[rankId1], rankInfos[rankId2]);
    return true;
}


inline GuildRankInfo* getGuildRankInfo(GuildRankInfos& rankInfos, GuildRankId rankId)
{
    if ((rankId < firstGuildRankId) || (rankId >= GuildRankId(rankInfos.size()))) {
        return nullptr;
    }
    return &rankInfos[rankId];
}


inline const GuildRankInfo* getGuildRankInfo(const GuildRankInfos& rankInfos, GuildRankId rankId)
{
    if ((rankId < firstGuildRankId) || (rankId >= GuildRankId(rankInfos.size()))) {
        return nullptr;
    }
    return &rankInfos[rankId];
}



/**
 * @struct BaseGuildInfo
 * 월드 상에 존재하는 길드 정보
 */
struct BaseGuildInfo
{
    GuildId guildId_;
    GuildName guildName_;
    GuildMarkCode guildMarkCode_;
        
    explicit BaseGuildInfo(GuildId guildId = invalidGuildId, const GuildName& guildName = L"",
        GuildMarkCode markCode = invalidGuildMarkCode) :
        guildId_(guildId),
        guildName_(guildName),
        guildMarkCode_(markCode) {}

    void reset() {
        guildId_ = invalidGuildId;
        guildName_.clear();
        guildMarkCode_ = invalidGuildMarkCode;
    }

    bool isValid() const {
        return isValidGuildId(guildId_);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        const bool isInput = stream.isInput();
        stream & guildId_;
        if (isValidGuildId(guildId_)) {
            stream & guildName_ & guildMarkCode_;
        }
        else {
            if (isInput) {
                guildName_.clear();
                guildMarkCode_ = invalidGuildMarkCode;
            }
        }
    }
};

/**
 * @struct BaseGuildMemberInfo
 * 월드 상에 존재하는 길드맴버 정보
 */
struct BaseGuildMemberInfo
{
    ObjectId playerId_;
    Nickname playerNickname_;
    GuildMemberPosition position_;  // 직위
    bool isOnline_;

    explicit BaseGuildMemberInfo(ObjectId playerId = invalidObjectId,
        const Nickname& playerNickname = L"", GuildMemberPosition position = gmpUnknown,
        bool isOnline = false) :
        playerId_(playerId),
        playerNickname_(playerNickname),
        position_(position),
        isOnline_(isOnline) {}

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & playerId_& playerNickname_ & position_ & isOnline_;
    }
};


/**
 * @struct GuildMemberInfo
 * 월드 상에 존재하는 길드맴버 정보
 */
struct GuildMemberInfo : public BaseGuildMemberInfo
{
    GuildRankId rankId_;
    uint32_t contributiveness_; //< 기여도
    CharacterClass characterClass_;
    CreatureLevel level_;
    GameMoney dayWithdraw_; //< 일일 인출 금액
    sec_t resetDayWithdrawTime_; //< 일일 인출 재설정 시간

    explicit GuildMemberInfo(ObjectId playerId = invalidObjectId,
        const Nickname& playerNickname = L"", GuildMemberPosition position = gmpUnknown,
        bool isOnline = false, GuildRankId rankId = invalidGuildRankId, uint32_t contributiveness = 0,
        CharacterClass characterClass = ccAny, CreatureLevel level = clMinLevel, GameMoney dayWithdraw = 0, sec_t resetDayWithdrawTime = 0) :
        BaseGuildMemberInfo(playerId, playerNickname, position, isOnline),
        rankId_(rankId),
        contributiveness_(contributiveness),
        characterClass_(characterClass),
        level_(level),
        dayWithdraw_(dayWithdraw),
        resetDayWithdrawTime_(resetDayWithdrawTime) {}

    bool isGuildMaster() const {
        return rankId_ == gdrGuildMaster;
    }

    bool hasRight(GuildRankRight right, const GuildRankInfos& rankInfos) const {
        const GuildRankInfo* rankInfo = getGuildRankInfo(rankInfos, rankId_);
        if (! rankInfo) {
            return false;
        }

        return rankInfo->hasRight(right);
    }

    bool hasRight(VaultId id, GuildBankRights right, const GuildRankInfos& rankInfos) const {
        const GuildRankInfo* rankInfo = getGuildRankInfo(rankInfos, rankId_);
        if (! rankInfo) {
            return false;
        }

        return rankInfo->hasRight(id, right);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        BaseGuildMemberInfo::serialize(stream);
        stream & rankId_ & contributiveness_ & characterClass_ & level_ & dayWithdraw_ & resetDayWithdrawTime_;
    }
};

typedef sne::srpc::RHashMap<ObjectId, GuildMemberInfo> GuildMemberInfoMap;
typedef sne::srpc::RVector<GuildMemberInfo> GuildMemberInfos;


inline bool isGuildRankAssigned(const GuildMemberInfoMap& guildMembers, GuildRankId rankId)
{
    for (const gideon::GuildMemberInfoMap::value_type& value : guildMembers) {
        const gideon::GuildMemberInfo& memberInfo = value.second;
        if (memberInfo.rankId_ == rankId) {
            return true;
        }
    }
    return false;
}


/// rankId보다 낮은 등급의 길드원을 승급시킨다(범위 보정)
inline void promoteGuildRank(GuildMemberInfoMap& guildMembers, GuildRankId rankId)
{
    assert(rankId > firstGuildRankId);
    for (GuildMemberInfoMap::value_type& value : guildMembers) {
        GuildMemberInfo& memberInfo = value.second;
        if (memberInfo.rankId_ > rankId) {
            --memberInfo.rankId_;
        }
    }
}


/**
 * @enum GuildRelatioshipType
 * 길드 관계 타입
 */
enum GuildRelatioshipType
{
    grtUnknown = 0,
    grtFriendly = 1, // 동맹
    grtHostility = 2, // 적대

    grtMaxRelationship = 20,
};


/**
 * @struct GuildRelationshipInfo
 * 길드 정보
 */
struct GuildRelationshipInfo
{
    GuildId targetGuildId_;
    GuildMarkCode guildMarkCode_;
    GuildName guildName_;
    GuildRelatioshipType relationship_;
    sec_t relationshipTime_;

    GuildRelationshipInfo(GuildId targetGuildId = invalidGuildId,
        GuildMarkCode guildMarkCode = invalidGuildMarkCode, 
        const  GuildName& guildName = L"", GuildRelatioshipType relationship = grtUnknown,
        sec_t relationshipTime = 0) :
        targetGuildId_(targetGuildId),
        guildMarkCode_(guildMarkCode),
        guildName_(guildName),
        relationship_(relationship),
        relationshipTime_(relationshipTime) {}

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & targetGuildId_ & guildMarkCode_ & guildName_ & relationship_ & relationshipTime_;
    }
};

typedef sne::srpc::RHashMap<GuildId, GuildRelationshipInfo> GuildRelationshipInfoMap;
typedef sne::srpc::RVector<GuildRelationshipInfo> GuildRelationshipInfos;


/**
 * @struct GuildApplicantInfo
 * 길드 지원자
 */
struct GuildApplicantInfo
{
    Nickname nickname_;
    CharacterClass characterClass_;
    MapCode mapCode_;
    bool isOnline_;

    explicit GuildApplicantInfo(const Nickname& nickname = L"",
        CharacterClass characterClass = ccAny,
        MapCode mapCode = invalidMapCode,
        bool isOnline = false) :
        nickname_(nickname),
        characterClass_(characterClass),
        mapCode_(mapCode),
        isOnline_(isOnline) {}
    
    template <typename Stream>
    void serialize(Stream& stream) {
        stream & nickname_ & characterClass_ & mapCode_ & isOnline_;
    }
};

typedef sne::srpc::RHashMap<ObjectId, GuildApplicantInfo> GuildApplicantInfoMap;

enum GuildLevel
{
    glInvalid = 0,
    glStart = 1,
    glBeginLevel = glStart,
    glMaxLevel = 15,
    glCount,
};

inline bool isValid(GuildLevel level)
{
    return glStart <= level && level <= glMaxLevel;
}


inline bool isMaxGuildLevel(GuildLevel level)
{
    return glMaxLevel <= level;
}


template <typename T>
GuildLevel toGuildLevel(T value)
{
    return static_cast<GuildLevel>(static_cast<uint8_t>(value));
}

typedef uint64_t GuildExp;
typedef uint32_t GuildSkillPoint;

/**
 * @struct GuildLevelInfo
 * 길드 레벨 정보
 */
struct GuildLevelInfo
{
    GuildExp guildExp_;    
    GuildExp dayGuildAddExp_;
    sec_t lastUpdateExpTime_;
    GuildSkillPoint skillPoint_;

    explicit GuildLevelInfo(GuildExp guildExp= 0, GuildExp dayGuildAddExp = 0,
        sec_t lastUpdateExpTime = 0, GuildSkillPoint skillPoint = 0) :
        guildExp_(guildExp),
        dayGuildAddExp_(dayGuildAddExp),
        lastUpdateExpTime_(lastUpdateExpTime),
        skillPoint_(skillPoint)
    {
    }

    void reset() {
        guildExp_ = 0;
        dayGuildAddExp_ = 0;
        lastUpdateExpTime_ = lastUpdateExpTime_;
        skillPoint_ = 0;
    }

    bool canAddExp(GuildExp maxDayExp) {
        return dayGuildAddExp_ < maxDayExp;
    }

    // = return : 진짜 적용 되었는가?
    bool addExp(GuildExp maxDayExp, GuildExp addGuildExp) {
        if (dayGuildAddExp_ == maxDayExp) {
            return false;
        }

        GuildExp totalDayExp = dayGuildAddExp_ + addGuildExp;
        if (totalDayExp <= maxDayExp) {            
            dayGuildAddExp_ += addGuildExp;
            guildExp_ += addGuildExp;
        }
        else {
            const GuildExp applyExp = maxDayExp - dayGuildAddExp_;
            dayGuildAddExp_ = maxDayExp;
            guildExp_ += applyExp;
        }
        return true;
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & guildExp_ & dayGuildAddExp_ & lastUpdateExpTime_ & skillPoint_;
    }
};

/**
 * @struct GuildInfo
 * 길드 정보
 */
struct GuildInfo : public BaseGuildInfo
{
    GuildMemberInfos guildMemberInfos_;
    GuildRelationshipInfos relytionships_;
    GuildApplicantInfoMap guildApplicantInfoMap_;    
    GuildNotice notice_;
    GuildIntroduction introduction_;
    GuildInventoryInfo inventoryInfo_;
    GuildRankInfos rankInfos_;
    GameMoney gameMoney_;
    GuildEventLogManager eventLogManager_;
    GuildBankEventLogManager eventBankLogManager_;
    GuildGameMoneyEventLogManager guildGameMoneyEventLogManager_;

    GuildLevelInfo levelInfo_;
    SkillCodes guildSkillCodes_;

    explicit GuildInfo(GuildId guildId = invalidGuildId, const GuildName& guildName = L"",
        GuildMarkCode markCode = invalidGuildMarkCode) :
        BaseGuildInfo(guildId, guildName, markCode),
        gameMoney_(0)
        {}

    GuildInfo(const BaseGuildInfo& guildInfo) :
        BaseGuildInfo(guildInfo) {}

    void reset() {
        BaseGuildInfo::reset();
        guildMemberInfos_.clear();
        relytionships_.clear();
        guildApplicantInfoMap_.clear();
        notice_.clear();
        introduction_.clear();
        inventoryInfo_.reset();
        rankInfos_.clear();
        gameMoney_ = 0;
        eventLogManager_.reset();
        eventBankLogManager_.reset();
        guildGameMoneyEventLogManager_.reset();
        levelInfo_.reset();
        guildSkillCodes_.clear();
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        BaseGuildInfo::serialize(stream);
        stream & guildMemberInfos_ & relytionships_ & guildApplicantInfoMap_ & 
            notice_ &introduction_ & inventoryInfo_ & rankInfos_  & gameMoney_ & eventLogManager_ &
            guildGameMoneyEventLogManager_ & eventBankLogManager_ & levelInfo_ & guildSkillCodes_;
    }
};

typedef sne::srpc::RVector<GuildInfo> GuildInfos;

/**
 * @struct SearchGuildInfo
 * 길드 정보
 */
struct SearchGuildInfo
{
    GuildId guildId_;
    GuildName guildName_;
    GuildMarkCode guildMarkCode_;
    Nickname guildMasterName_;

    inline bool isValid() const {
        return isValidGuildId(guildId_);
    }

    explicit SearchGuildInfo(GuildId guildId = invalidGuildId, const GuildName& guildName = L"",
        GuildMarkCode markCode = invalidGuildMarkCode, const Nickname& guildMasterName = L"") :
        guildId_(guildId),
        guildName_(guildName),
        guildMarkCode_(markCode),
        guildMasterName_(guildMasterName)
        {}

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & guildId_ & guildName_ & guildMarkCode_ & guildMasterName_;
    }
};

typedef sne::srpc::RVector<SearchGuildInfo> SearchGuildInfos;


/**
 * @struct DetailSearchGuildInfo
 * 길드 정보
 */
struct DetailSearchGuildInfo : BaseGuildInfo
{
    Nickname masterName_;
    GuildFame guildFame_;
    GuildIntroduction guildIntroduction_;

    explicit DetailSearchGuildInfo(GuildId guildId = invalidGuildId, const GuildName& guildName = L"",
        GuildMarkCode markCode = invalidGuildMarkCode, const Nickname& guildMasterName = L"",
        GuildFame guildFame = 0, const GuildIntroduction& guildIntroduction = L"") :
        BaseGuildInfo(guildId, guildName, markCode),
        masterName_(guildMasterName),
        guildFame_(guildFame),
        guildIntroduction_(guildIntroduction)
    {}

    inline bool isValid() const {
        return isValidGuildId(guildId_);
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        BaseGuildInfo::serialize(stream);
        stream & masterName_ & guildFame_ & guildIntroduction_;
    }
};


} // namespace gideon {

namespace sne { namespace core {


inline OStream& operator<<(OStream& lhs, gideon::GuildMemberPosition rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::GuildMemberPosition& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::GuildMemberPosition>(value);
    return lhs;
}


inline OStream& operator<<(OStream& lhs, gideon::GuildRelatioshipType rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::GuildRelatioshipType& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::GuildRelatioshipType>(value);
    return lhs;
}



inline OStream& operator<<(OStream& lhs, gideon::GuildLevel rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::GuildLevel& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::GuildLevel>(value);
    return lhs;
}

}} // namespace sne { namespace core {
