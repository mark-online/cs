#pragma once

#include <gideon/cs/shared/data/Code.h>
#include <gideon/cs/shared/data/CraftInfo.h>
#include <gideon/cs/shared/data/Rate.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>


namespace gideon { namespace datatable {

/**
 * @struct ReprocessDropItemInfo
 *
 */
struct ReprocessDropItemInfo
{
    DataCode itemCode_;
    uint8_t minCount_;
    uint8_t maxCount_;
    permil_t dropRate_;

    ReprocessDropItemInfo(DataCode itemCode = invalidDataCode, uint8_t minCount = 0,
        uint8_t maxCount = 0, permil_t dropRate = 0) :
        itemCode_(itemCode),
        minCount_(minCount),
        maxCount_(maxCount),
        dropRate_(dropRate)
    {
    }

    bool shouldDrop() const {
        return isSuccessRate(dropRate_);
    }

    BaseItemInfo getItemInfo() const {
        return BaseItemInfo(itemCode_, static_cast<uint8_t>(esut::random(minCount_, maxCount_)));
    }
};

typedef sne::core::Vector<ReprocessDropItemInfo> ReprocessDropItemInfos;

/**
 * @class ReprocessInfo
 *
 */
class ReprocessInfo
{
public:
    ReprocessInfo(CraftType craftType, uint8_t maxDropCount, const ReprocessDropItemInfos& reprocessDropItemInfos) :
        craftType_(craftType),
        maxDropCount_(maxDropCount),
        reprocessDropItemInfos_(reprocessDropItemInfos) {}
        
    /// 랜덤하게 선택된 아이템 목록 리턴
    BaseItemInfos getReprocessItems() const {
        BaseItemInfos infos;
        for (const ReprocessDropItemInfo& itemInfo : reprocessDropItemInfos_) {
            if (itemInfo.shouldDrop()) {
                infos.push_back(itemInfo.getItemInfo());
            }
            if (maxDropCount_ == infos.size()) {
                return infos;
            }
        }
        return infos;
    }

    const ReprocessDropItemInfos& getReprocessDropItemInfos() const {
        return reprocessDropItemInfos_;
    }

    CraftType getCraftType() const {
        return craftType_;
    }

private:
    CraftType craftType_;
    uint8_t maxDropCount_; 
    ReprocessDropItemInfos reprocessDropItemInfos_;
};

/**
 * @class ReprocessTable
 *
 */
class GIDEON_CS_API ReprocessTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(ReprocessTable);

public:
    typedef sne::core::HashMap<DataCode, ReprocessInfo> ReprocessMap;

public:
    virtual ~ReprocessTable() {}

public:
    virtual const ReprocessInfo* getReprocessInfo(DataCode itemCode) const = 0;

    virtual const ReprocessMap& getReprocessMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;

};

}} // namespace gideon { namespace datatable {

#define REPROCESS_TABLE gideon::datatable::ReprocessTable::instance()
