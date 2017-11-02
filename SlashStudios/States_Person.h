#ifndef STATES_PERSON_H
#define STATES_PERSON_H

#include "Singleton.h"
#include "State.h"
#include "irrlicht.h"

class Person;

class Roam : public State<Person>
{
	void Enter(Person* go);
	void Execute(Person* go);
	void Exit(Person* go);
};

class Run : public State<Person>
{
	void Enter(Person* go);
	void Execute(Person* go);
	void Exit(Person* go);
};

typedef Singleton<Roam> state_Roam;
typedef Singleton<Run> state_Run;

#endif