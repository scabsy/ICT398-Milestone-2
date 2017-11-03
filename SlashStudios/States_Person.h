#ifndef STATES_PERSON_H
#define STATES_PERSON_H

#include "Singleton.h"
#include "State.h"
#include "irrlicht.h"

class Person;

/**
* @class Roam
* @brief Defines the Roam state
* 
* @author Samuel Brownley 31691379
* @version 1.0
* @date 03/11/2017
*/

class Roam : public State<Person>
{
	void Enter(Person* go);
	void Execute(Person* go);
	void Exit(Person* go);
};

/**
* @class Run
* @brief Defines the Run state - on treadmill
* 
* @author Samuel Brownley 31691379
* @version 1.0
* @date 03/11/2017
*/

class Run : public State<Person>
{
	void Enter(Person* go);
	void Execute(Person* go);
	void Exit(Person* go);
};

///Roam singleton
typedef Singleton<Roam> state_Roam;
///Run singleton
typedef Singleton<Run> state_Run;

#endif