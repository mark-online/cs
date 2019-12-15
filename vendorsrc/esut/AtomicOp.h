#if !defined(ESUT_ATOMICOP_H)
#define ESUT_ATOMICOP_H

#include <boost/detail/interlocked.hpp>
#include <boost/noncopyable.hpp>

// reference count object 기반의 smart pointer

namespace esut
{

/**
 * @class AtomicOp
 */
template <typename T = long>
class AtomicOp : public boost::noncopyable
{
public:
    explicit AtomicOp(T initial = 0) :
        value_(initial) {}

    /// Atomically pre-increment @c value_.
    T operator++() {
        return static_cast<T>(
            BOOST_INTERLOCKED_INCREMENT(reinterpret_cast<long*>(&value_)));
    }

    /// Atomically increment @c value_ by rhs.
    T operator+=(T rhs) {
        BOOST_INTERLOCKED_EXCHANGE_ADD(reinterpret_cast<long*>(&value_), rhs);
        return value_;
    }

    /// Atomically pre-decrement @c value_.
    T operator--() {
        return static_cast<T>(
            BOOST_INTERLOCKED_DECREMENT(reinterpret_cast<long*>(&value_)));
    }

    /// Atomically decrement @c value_ by rhs.
    T operator-=(T rhs) {
        BOOST_INTERLOCKED_EXCHANGE_ADD(reinterpret_cast<long*>(&value_), -rhs);
        return value_;
    }

    T value() const {
        return value_;
    }

private:
    T value_;
};

} // namespace esut

#endif // !defined(ESUT_ATOMICOP_H)
