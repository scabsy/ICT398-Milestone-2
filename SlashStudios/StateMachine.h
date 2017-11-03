#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "State.h"

/**
* @class StateMachine
* @brief Defines the Finite State Machine that each person has
* 
* @author Samuel Brownley 31691379
* @version 1.0
* @date 03/11/2017
*/

template <class T>
class StateMachine
{
private:
	///Owner of the StateMachine
	T* owner;
	///State prior to the current state
	State<T>* previousState;
	///State the owner is currently in
	State<T>* currentState;
	///The state is executed every time the object is updated
	State<T>* globalState;

public:
	/**
	* @brief Creates a new StateMachine
	* @param FSMowner - owner of the FSM
	*/
	StateMachine(T* FSMowner)
	{
		owner=FSMowner;
		previousState=NULL;
		currentState=NULL;
		globalState=NULL;
	}

	/**
	* @brief Sets the previous state to st
	* @param st - new previous state
	*/
	void SetPreviousState(State<T>* st){previousState=st;}

	/**
	* @brief Sets the current state to st
	* @param st - new current state
	*/
	void SetCurrentState(State<T>* st){currentState=st;}

	/**
	* @brief Sets the global state to st
	* @param st - new global state
	*/
	void SetGlobalState(State<T>* st){globalState=st;}

	/**
	* @brief Executes the current and global states
	*/
	void Update() const
	{
		if(globalState)
		{
			globalState->Execute(owner);
		}
		if(currentState)
		{
			currentState->Execute(owner);
		}
	}

	/**
	* @brief Changes the current state to newState while aldo setting the previous state
	* @param newState - new current state
	*/
	void ChangeState(State<T>* newState)
	{
		previousState=currentState;
		currentState->Exit(owner);
		currentState=newState;
		currentState->Enter(owner);
	}
	
	/**
	* @brief Revert the current state back to the previous state
	*/
	void RevertToPreviousState()
	{
		currentState=previousState;
	}

	/**
	* @brief Returns the previous state
	* @return previous state
	*/
	State<T>* GetPreviousState(){return previousState;}

	/**
	* @brief Returns the current state
	* @return current state
	*/
	State<T>* GetCurrentState(){return currentState;}

	/**
	* @brief Returns the global state
	* @return global state
	*/
	State<T>* GetGlobalState(){return globalState;}

	/**
	* @brief Determine if this state is of a certain type
	*/
	bool IsInState(const State<T>& st) const
	{
		return typeid(*currentState) == typeid(st);
	}

	/**
	* @brief Default constructor
	*/
	virtual ~StateMachine(){};
};

#endif