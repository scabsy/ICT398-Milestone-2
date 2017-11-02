#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "State.h"

template <class T>
class StateMachine
{
private:
	T* owner;
	State<T>* previousState;
	State<T>* currentState;
	State<T>* globalState;

public:
	StateMachine(T* FSMowner)
	{
		owner=FSMowner;
		previousState=NULL;
		currentState=NULL;
		globalState=NULL;
	}

	void SetPreviousState(State<T>* st){previousState=st;}
	void SetCurrentState(State<T>* st){currentState=st;}
	void SetGlobalState(State<T>* st){globalState=st;}

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

	void ChangeState(State<T>* newState)
	{
		previousState=currentState;
		currentState->Exit(owner);
		currentState=newState;
		currentState->Enter(owner);
	}
	
	void RevertToPreviousState()
	{
		currentState=previousState;
	}

	State<T>* GetPreviousState(){return previousState;}
	State<T>* GetCurrentState(){return currentState;}
	State<T>* GetGlobalState(){return globalState;}

	bool IsInState(const State<T>& st) const
	{
		return typeid(*currentState) == typeid(st);
	}

	virtual ~StateMachine(){};
};

#endif