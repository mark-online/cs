#pragma once

#include "Coordinate.h"
#include "Time.h"

namespace gideon {

const GameTime bindRecallTime = 10 * 1000; // 30초
const GameTime bindRecallCooltime = 30 * 60 * 1000; // 30분

/**
 * @struct BindRecallInfo
 * 포탈 정보
 */
struct BindRecallInfo
{
    ObjectId linkId_;
    DataCode dataCode_;
    WorldPosition wordlPosition_;

    BindRecallInfo(const DataCode dataCode = invalidDataCode,
        const WorldPosition& wordlPosition = WorldPosition()) :
        dataCode_(dataCode),
        wordlPosition_(wordlPosition)
    {
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & linkId_ & dataCode_ & wordlPosition_;
    }
};


typedef sne::srpc::RVector<BindRecallInfo> BindRecallInfos;

} // namespace gideon {