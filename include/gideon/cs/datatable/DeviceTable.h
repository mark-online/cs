#pragma once

#include <gideon/cs/datatable/template/device_table.hxx>
#include <gideon/cs/shared/data/DeviceInfo.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>

namespace gideon { namespace datatable {

/**
 * @enum DeviceConditionType
 * 장치 활성화 조건
 **/
enum DeviceConditionType
{
    actUnknown = 0,
    actItem, //< 아이템 소지 검사(삭제 안됨)
    actConsumeItem, //< 아이템 소비(작동 후 삭제됨)
    actBoundary
};


inline bool isValid(DeviceConditionType type)
{
    return actUnknown < type && type < actBoundary;
}


template <typename T>
inline DeviceConditionType toDeviceConditionType(T value)
{
    return static_cast<DeviceConditionType>(static_cast<int>(value));
}


/// 작동하기 위해 해당 아이템을 소지해야 하는가?
inline bool shouldHaveItem(DeviceConditionType value)
{
    return (value == actItem) || (value == actConsumeItem);
}


/// 작동 후 아이템을 파괴해야 하는가?
inline bool shouldDestroyItem(DeviceConditionType value)
{
    return (value == actConsumeItem);
}


/**
 * @struct DeviceCondition
 * 장치 작동 조건
 */
struct DeviceCondition
{
    DeviceConditionType condition_;
    union {
        /// actItem, actConsumeItem
        struct {
            DataCode itemCode_; //< 아이템 코드
            uint32_t itemCount_; //< 아이템 갯수
        } item_;

        /// raw
        struct {
            int32_t param1_;
            int32_t param2_;
        } raw_;
    };

    DeviceCondition(int condition, int param1, int param2) :
        condition_(toDeviceConditionType(condition)) {
        raw_.param1_ = param1;
        raw_.param2_ = param2;
    }
};

typedef sne::core::Vector<DeviceCondition> DeviceConditions;


/**
 * @class DeviceTemplate
 */
class DeviceTemplate
{
public:
    DeviceTemplate(const gdt::device_t& device) :
        device_(device) {
        initConditions();
    }

public:
    /// @internal
    void deleteDeviceInfo() {
        delete &device_;
    }

public:
    DeviceCode getDeviceCode() const {
        return device_.device_code();
    }

    const DeviceConditions& getConditions() const {
        return conditions_;
    }

	GameTime getCastTime() const {
		return static_cast<GameTime>(device_.cast_time());
	}

	const wchar_t* getEffectName() const {
		return device_.object_effect().c_str();
	}

	const wchar_t* getActivatedEffectName() const {
		return device_.object_activated_effect().c_str();
	}

    uint32_t getActivatetype() const {
        return device_.activate_type();
    }

    const wchar_t* getActivateParam1() const {
        return device_.activate_param1().c_str();
    }

    const wchar_t* getActivateParam2() const {
        return device_.activate_param2().c_str();
    }

    const wchar_t* getActivateParam3() const {
        return device_.activate_param3().c_str();
    }

public:
    const gdt::device_t& getInfo() const {
        return device_;
    }

private:
    void initConditions() {
        if (isValid(toDeviceConditionType(device_.condition1_type()))) {
            conditions_.push_back(
                DeviceCondition(device_.condition1_type(), device_.condition1_param1(), device_.condition1_param2()));
        }
        if (isValid(toDeviceConditionType(device_.condition2_type()))) {
            conditions_.push_back(
                DeviceCondition(device_.condition2_type(), device_.condition2_param1(), device_.condition2_param2()));
        }
    }

private:
	const gdt::device_t& device_;
    DeviceConditions conditions_;
};


/**
 * @class DeviceTable
 *
 */
class GIDEON_CS_API DeviceTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(DeviceTable);

public:
	typedef sne::core::HashMap<DeviceCode, DeviceTemplate> DeviceMap;

public:
    virtual ~DeviceTable() {}

public:
    virtual const DeviceTemplate* getDeviceTemplate(DeviceCode code) const = 0;

    virtual const DeviceMap& getDeviceMap() const = 0;

    virtual const std::string& getLastError() const = 0;

    virtual bool isLoaded() const = 0;
};

}} // namespace gideon { namespace datatable {

#define DEVICE_TABLE gideon::datatable::DeviceTable::instance()
