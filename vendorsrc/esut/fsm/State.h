/**
* Copyright (c) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#ifndef _ESUT_STATE_H_
#define _ESUT_STATE_H_

#include <boost/noncopyable.hpp>

namespace esut
{

/**
 * @class State
 * abstract base class to define an interface for a state
 */
template <class ContextType>
class State : public boost::noncopyable
{
protected:
    typedef ContextType Context;
public:
    virtual ~State() {}

    /// this will execute when the state is entered
    virtual void onEnter(Context* context) = 0;

    /// this is the states normal update function
    virtual void onExecute(Context* context) = 0;

    /// this will execute when the state is exited. (My word, isn't
    /// life full of surprises... ;o))
    virtual void onExit(Context* context) = 0;
};


/**
* @class SingletonState
* Flyweight pattern
*/
template <class MostDerived, class ContextType>
class SingletonState : public State<ContextType>
{
public:
    static MostDerived* instance() {
        static MostDerived anInstance;
        return &anInstance;
    }
};

} // namespace esut

#endif    //_ESUT_STATE_H_
