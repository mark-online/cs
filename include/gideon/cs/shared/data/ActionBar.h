#pragma once

#include "Code.h"
#include <sne/srpc/RpcContainers.h>

namespace gideon {

/**
 * @enum ActionBarPosition
 */
enum ActionBarPosition
{
    abpStartIndex = 0,
    abpEndIndex = 11,
    abpCount,
};

typedef sne::srpc::RArray<DataCode, abpCount> ActionBar;

inline bool isValid(ActionBarPosition index)
{
    return abpStartIndex <= index && index < abpCount;
}

template <typename T>
inline ActionBarPosition toActionBarPosition(T value)
{
    return static_cast<ActionBarPosition>(value);
}


/**
 * @enum ActionBarIndex
 */
enum ActionBarIndex
{
    abcStartIndex = 0,
    abcFirstSubActionBarIndex = 3,
    abcEndIndex = 9,
    abcDefaultCount = 10,

    abcMainActionBarCount = 3
};

inline bool isValid(ActionBarIndex index)
{
    return (abcStartIndex <= index) && (index <= abcEndIndex);
}


inline bool isMainActionBar(ActionBarIndex index)
{
    return (abcStartIndex <= index) && (index < abcFirstSubActionBarIndex);
}


template <typename T>
inline ActionBarIndex toActionBarIndex(T value)
{
    return static_cast<ActionBarIndex>(value);
}



/**
 * @struct CharacterActionBars
 */
struct CharacterActionBars
{
    typedef sne::srpc::RVector<ActionBar> ActionBars;
    
    bool isActionBarLock_;
    ActionBars actionbars_;

    CharacterActionBars() {
        isActionBarLock_ = false;
        actionbars_.reserve(abcDefaultCount);
    }

    void reset() {
        actionbars_.clear();
        isActionBarLock_ = false;
    }

    void add(const ActionBar& actionBar) {
        actionbars_.push_back(actionBar);
    }

    void setActionBarLock(bool isLocked) {
        isActionBarLock_ = isLocked;
    }

    bool save(ActionBarIndex index, ActionBarPosition position, DataCode code) {
        if (! isValid(index)) {
            return false;
        }
        if (index >= ActionBarIndex(actionbars_.size())) {
            return false;
        }

        if (! isValid(position)) {
            return false;
        }

        ActionBar& actionBar = actionbars_[index];
        actionBar[position] = code;

        return true;
    }

    ActionBar* getActionBar(ActionBarIndex index) {
        if (! isValid(index)) {
            return nullptr;
        }

        if (index >= ActionBarIndex(actionbars_.size())) {
            return nullptr;
        }

        return &actionbars_[index];
    }

    bool has(DataCode code) const {
        if (! isValidDataCode(code)) {
            return false;
        }
        for (const ActionBar& actionBar : actionbars_) {
            for (DataCode hadDataCode : actionBar) {
                if (hadDataCode == code) {
                    return true;
                }
            }
        }
        return false;
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        stream & isActionBarLock_ & actionbars_;
    }
};

} // namespace gideon {


namespace sne { namespace core {

inline OStream& operator<<(OStream& lhs, gideon::ActionBarPosition rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::ActionBarPosition& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::ActionBarPosition>(value);
    return lhs;
}


inline OStream& operator<<(OStream& lhs, gideon::ActionBarIndex rhs)
{
    lhs << static_cast<uint8_t>(rhs);
    return lhs;
}


inline IStream& operator>>(IStream& lhs, gideon::ActionBarIndex& rhs)
{
    uint8_t value;
    lhs >> value;
    rhs = static_cast<gideon::ActionBarIndex>(value);
    return lhs;
}


}} // namespace sne { namespace core {