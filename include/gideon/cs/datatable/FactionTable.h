#pragma once

#include <gideon/cs/Common.h>
#include <gideon/cs/datatable/template/faction_table.hxx>
#include <gideon/cs/shared/data/FactionInfo.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @struct FactionTemplate
 */
struct FactionTemplate
{
    const FactionCode factionCode_;
    const FactionMask ourMask_;
    const FactionMask friendlyMask_;
    const FactionMask hostileMask_;
    FactionCodeSet friendlyFactions_;
    FactionCodeSet hostileFactions_;

    FactionTemplate(const gdt::faction_t& factionInfo) :
        factionCode_(factionInfo.faction_code()),
        ourMask_(static_cast<FactionMask>(factionInfo.our_mask())),
        friendlyMask_(static_cast<FactionMask>(factionInfo.friendly_mask())),
        hostileMask_(static_cast<FactionMask>(factionInfo.hostile_mask())) {
        addFactions(friendlyFactions_, factionInfo.friendly_factions());
        addFactions(hostileFactions_, factionInfo.hostile_factions());
    }

    // for test
    FactionTemplate(FactionCode factionCode, FactionMask ourMask,
        FactionMask friendlyMask, FactionMask hostileMask) :
        factionCode_(factionCode),
        ourMask_(ourMask),
        friendlyMask_(friendlyMask),
        hostileMask_(hostileMask) {}

    bool isFriendlyTo(const FactionTemplate& targetFactionTemplate) const {
        if (hasFactionCode(hostileFactions_, targetFactionTemplate.factionCode_)) {
            return false;
        }

        if (hasFactionCode(friendlyFactions_, targetFactionTemplate.factionCode_)) {
            return true;
        }

        return (friendlyMask_ & targetFactionTemplate.ourMask_) != 0;
    }

    bool isHostileTo(const FactionTemplate& targetFactionTemplate) const {
        if (hasFactionCode(hostileFactions_, targetFactionTemplate.factionCode_)) {
            return true;
        }

        if (hasFactionCode(friendlyFactions_, targetFactionTemplate.factionCode_)) {
            return false;
        }

        return (hostileMask_ & targetFactionTemplate.ourMask_) != 0;
    }

private:
    void addFactions(FactionCodeSet& codeSet,
        const gdt::faction_t::friendly_factions_optional& factions) {
        if (! factions.present()) {
            return;
        }
        gdt::faction_list_t::const_iterator pos = factions.get().begin();
        const gdt::faction_list_t::const_iterator end = factions.get().end();
        for (; pos != end; ++pos) {
            codeSet.insert(*pos);
        }
    }
};

/**
 * @class FactionTable
 *
 */
class GIDEON_CS_API FactionTable : public boost::noncopyable
{
	SNE_DECLARE_SINGLETON(FactionTable);
public:
    typedef sne::core::HashMap<FactionCode, FactionTemplate> FactionMap;

public:
    virtual ~FactionTable() {}

public:
    virtual const FactionTemplate* getFaction(FactionCode code) const = 0;

    virtual const FactionMap& getFactionMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {


#define FACTION_TABLE gideon::datatable::FactionTable::instance()