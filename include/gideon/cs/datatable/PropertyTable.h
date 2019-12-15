#pragma once

#include <gideon/cs/Common.h>
#include <sne/core/container/Containers.h>
#include <sne/core/utility/Singleton.h>
#include <boost/noncopyable.hpp>
#include <boost/lexical_cast.hpp>

namespace gideon { namespace datatable {

/**
 * @class PropertyTable
 *
 */
class GIDEON_CS_API PropertyTable : public boost::noncopyable
{
    SNE_DECLARE_SINGLETON(PropertyTable);

public:
    /// key/value
    typedef sne::core::HashMap<std::wstring , std::wstring > PropertyMap;

public:
    virtual ~PropertyTable() {}

public:
    virtual const std::wstring * getProperty(const std::wstring & key) const = 0;

    virtual const PropertyMap& getPropertyMap() const = 0;

    virtual const std::string & getLastError() const = 0;

    virtual bool isLoaded() const = 0;

public:
    template <typename T>
    T getPropertyValue(const std::wstring & key) /*throw (boost::bad_lexical_cast)*/
    {
        const std::wstring * value = getProperty(key);
        if (! value) {
            return T();
        }
        return boost::lexical_cast<T>(*value);
    }
};

}} // namespace gideon { namespace datatable {

#define GIDEON_PROPERTY_TABLE gideon::datatable::PropertyTable::instance()
