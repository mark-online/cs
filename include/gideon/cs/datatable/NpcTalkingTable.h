#pragma once

#include <gideon/cs/shared/data/NpcInfo.h>
#include <gideon/cs/shared/data/NpcTalkingInfo.h>
#include <gideon/cs/datatable/template/npc_talking_table.hxx>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @enum NpcTalkingState
 */
enum NpcTalkingState
{
    ntsPeace = 0, //< 평화 상태
    ntsCombat = 1 //< 전투 상태
};


/**
 * @enum NpcTalkingLevelDiff
 */
enum NpcTalkingLevelDiff
{
    ntlIgnore = 0, //< 레벨 무시
    ntlLow = 1, //< NPC level < User level 
    ntlHigh = 2 //< NPC level >= User level
};


/**
 * @enum NpcTalkingRelation
 */
enum NpcTalkingRelation
{
    ntrIgnore = 0, //< 관계 무시
    ntrHostile = 1, //< 적대 관계
    ntrChao = 2 //< (동맹 or 우호) 범죄자
};

/**
 * @class NpcTalkingTemplate
 */
class NpcTalkingTemplate
{
    enum {
        talkingCount = 3
    };

    typedef sne::core::Vector<const wchar_t*> Talkings;

public:
    NpcTalkingTemplate(const gdt::npc_talking_t& info) :
        info_(info) {
        init();
    }

    const gdt::npc_talking_t& getInfo() const {
        return info_;
    }

    NpcTalkingState getState() const {
        return NpcTalkingState(info_.peace_or_combat());
    }

    NpcTalkingLevelDiff getLevelDiff() const {
        return NpcTalkingLevelDiff(info_.level_diff());
    }

    NpcTalkingRelation getRelation() const {
        return NpcTalkingRelation(info_.relation());
    }

    template <typename T>
    const wchar_t* selectTalking(T seed) const {
        if (talkings_.empty()) {
            assert(false && "FIX npc_talking_table!!");
            return NULL;
        }
        return talkings_[seed % talkings_.size()];
    }

private:
    void init() {
        addTalking(info_.talking_1());
        addTalking(info_.talking_2());
        addTalking(info_.talking_3());
    }

    void addTalking(const ::xml_schema::string& talking) {
        if (talking != L"0") {
            talkings_.push_back(talking.c_str());
        }
   }

private:
    const gdt::npc_talking_t& info_;
    Talkings talkings_;
};


/**
 * @class NpcTalkingList
 * - for forward decl.
 */
class NpcTalkingList : public sne::core::Vector<const NpcTalkingTemplate*>
{};


/**
 * @class NpcTalkingTable
 *
 */
class GIDEON_CS_API NpcTalkingTable : public boost::noncopyable
{
	SNE_DECLARE_SINGLETON(NpcTalkingTable);

public:
    typedef sne::core::HashMap<NpcCode, NpcTalkingList> NpcTalkingListMap;

public:
    virtual ~NpcTalkingTable() {}

public:
    virtual const NpcTalkingTemplate* getNpcTalkingTemplate(NpcTalkingCode talkingCode) const = 0;

    virtual const NpcTalkingList* getNpcTalkingList(NpcCode code) const = 0;

    virtual const NpcTalkingListMap& getNpcTalkingListMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define NPC_TALKING_TABLE gideon::datatable::NpcTalkingTable::instance()
