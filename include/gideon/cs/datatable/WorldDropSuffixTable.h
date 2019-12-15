#pragma once

#include <gideon/cs/shared/data/ItemDropInfo.h>
#include <gideon/cs/shared/data/Rate.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>


namespace gideon { namespace datatable {
    
/**
 * @class WorldDropSuffixTemplate
 *
 */
class WorldDropSuffixTemplate
{
public:
    WorldDropSuffixTemplate(const WorldDropIds& worldDropIds = WorldDropIds(),
        uint8_t loopCount = 0, uint16_t dropPct = 0) :
        worldDropIds_(worldDropIds),
        loopCount_(loopCount),
        dropPct_(dropPct)
    {
    }

    bool isValid() const {
        return ! worldDropIds_.empty() && loopCount_ > 0 && dropPct_ > 0;
    }

    WorldDropId getRandomWorldDropId() {
        if (worldDropIds_.empty()) {
            return invalidWorldDropId;
        }
        const int maxRandValue = static_cast<uint32_t>(worldDropIds_.size() - 1);
        uint32_t randIndex = esut::random(0, maxRandValue);
        return worldDropIds_[randIndex];
    }

    bool shouldDrop() const {
        return isSuccessRate(dropPct_);
    }

    uint8_t getLoopCount() const {
        return loopCount_;
    }

private:
    WorldDropIds worldDropIds_;
    uint8_t loopCount_;
    uint16_t dropPct_;
};


/**
 * @class WorldDropSuffixTable
 *
 */
class GIDEON_CS_API WorldDropSuffixTable : public boost::noncopyable
{
public:
	SNE_DECLARE_SINGLETON(WorldDropSuffixTable);

public:
    typedef sne::core::HashMap<WorldDropSuffixId, WorldDropSuffixTemplate> WorldDropSuffixMap;

public:
    virtual ~WorldDropSuffixTable() {}

public:
    virtual WorldDropSuffixTemplate getWorldDropSuffixTemplate(WorldDropSuffixId index) = 0;

    virtual const WorldDropSuffixMap& getWorldDropSuffixMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define WORLD_DROP_SUFFIX_TABLE gideon::datatable::WorldDropSuffixTable::instance()
