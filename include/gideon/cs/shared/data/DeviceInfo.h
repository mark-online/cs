#pragma once

#include "Code.h"
#include "EntityInfo.h"

namespace gideon {

/**
 * @enum DeviceType
 */
enum DeviceType
{
    dtUnknown = 0,
    dtQuest, //< 퀘스트 관련 장치
    dtBoundary
};


inline bool isValid(DeviceType value)
{
    return (dtUnknown < value) && (value < dtBoundary);
}


inline bool isQuestDevice(DeviceType value)
{
    return value == dtQuest;
}


/**
 * 장치 코드
 * - Category(1B) | DeviceType(1B) | 인덱스(2B)
 */
typedef DataCode DeviceCode;
const DeviceCode invalidDeviceCode = 0;


inline bool isValidDeviceCode(DeviceCode code)
{
    return getCodeType(code) == ctDevice;
}


/// DeviceCode를 만든다
inline DeviceCode makeDeviceCode(DeviceType deviceType, uint16_t index)
{
    return getMinGideonCode(ctDevice) + (deviceType << 16) + index;
}


inline DeviceType getDeviceType(DeviceCode rc)
{
    assert(getCodeType(rc) == ctDevice);
    return static_cast<DeviceType>((rc & 0x00FF0000) >> 16);
}


inline uint32_t getDeviceCodeIndex(DeviceCode rc)
{
    assert(getCodeType(rc) == ctDevice);
    return static_cast<uint32_t>(rc & 0x0000FFFF);
}


/// DeviceCode를 파싱한다
inline bool parseDeviceCode(DeviceType& deviceType, uint32_t& index, DeviceCode rc)
{
    const CodeType codeType = getCodeType(rc);
    if (codeType != ctDevice) {
        return false;
    }

    deviceType = getDeviceType(rc);
    index = getDeviceCodeIndex(rc);
    return true;
}


/**
 * @struct DeviceInfo
 */
struct DeviceInfo : public EntityInfo
{
    DeviceCode deviceCode_;
    bool activated_; //< 작동 중인가?

    explicit DeviceInfo(ObjectType objectType = otInvalid,
        ObjectId objectId = invalidObjectId) :
        EntityInfo(objectType, objectId) {
        reset();
    }

    void reset() {
        deviceCode_ = invalidDeviceCode;
        activated_ = false;
    }

    template <typename Stream>
    void serialize(Stream& stream) {
        EntityInfo::serialize(stream);
        stream & deviceCode_ & activated_;
    }
};

} // namespace gideon {
