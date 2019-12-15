/**
* Copyright (c) 2011 Enel Studio.
*
* @author Kim ByeongSu <kcando@enel.co.kr>
*/
#ifndef _ESUT_SIMPLESTATEMACHINE_H_
#define _ESUT_SIMPLESTATEMACHINE_H_

#include "State.h"
#include <boost/noncopyable.hpp>
#include <string>
#include <cassert>

namespace esut
{

/**
 * @class SimpleStateMachine
 * State machine class. Inherit from this class and create some states
 * to give your agents FSM functionality
 */
template <class Context>
class SimpleStateMachine : public boost::noncopyable
{
public:
    SimpleStateMachine(Context* owner):
        m_owner(owner),
        m_currentState(0),
        m_previousState(0),
        m_globalState(0) {}

    ~SimpleStateMachine() {}

    // use these methods to initialize the FSM
    void setCurrentState(State<Context>* s) {
        m_currentState = s;
    }
    void setGlobalState(State<Context>* s) {
        m_globalState = s;
    }
    void setPreviousState(State<Context>* s){
        m_previousState = s;
    }

    /// call this to update the FSM
    void update()const {
        // if a global state exists, call its execute method, else do nothing
        if (m_globalState != 0) {
            m_globalState->onExecute(m_owner);
        }

        // same for the current state
        if (m_currentState != 0) {
            m_currentState->onExecute(m_owner);
        }
    }

    /// change to a new state
    void transit(State<Context>* newState) {
        assert(newState && 
            "<SimpleStateMachine::transit>: trying to change to 0 state");

        // keep a record of the previous state
        m_previousState = m_currentState;

        // call the exit method of the existing state
        if (m_currentState != 0) {
            m_currentState->onExit(m_owner);
        }

        // change state to the new state
        m_currentState = newState;

        // call the entry method of the new state
        m_currentState->onEnter(m_owner);
    }

    /// change state back to the previous state
    void revertToPreviousState() {
        transit(m_previousState);
    }

#ifndef NDEBUG
    /// returns true if the current state's type is equal to the type of the
    /// class passed as a parameter. 
    bool isInState(const State<Context>& st) const {
        return typeid(*m_currentState) == typeid(st);
    }
#endif

    State<Context>* getCurrentState() const{
        return m_currentState;
    }
    State<Context>* getGlobalState() const {
        return m_globalState;
    }
    State<Context>* getPreviousState() const {
        return m_previousState;
    }

private:
    /// a pointer to the agent that owns this instance
    Context* m_owner;

    State<Context>* m_currentState;

    /// a record of the last state the agent was in
    State<Context>* m_previousState;

    /// this is called every time the FSM is updated
    State<Context>* m_globalState;
};

} // namespace esut

#endif    //_ESUT_SIMPLESTATEMACHINE_H_
