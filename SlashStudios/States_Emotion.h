#ifndef STATES_EMOTION_H
#define STATES_EMOTION_H

#include "Singleton.h"
#include "State.h"
#include "irrlicht.h"

class Person;

/**
* @class Happy
* @brief Defines methods of the Happy state
*/
class Happy: public State<Person>
{
	void Enter(Person* go);
	void Execute(Person* go);
	void Exit(Person* go);
};

class Sad: public State<Person>
{
	void Enter(Person* go);
	void Execute(Person* go);
	void Exit(Person* go);
};

class Excited: public State<Person>
{
	void Enter(Person* go);
	void Execute(Person* go);
	void Exit(Person* go);
};

class Scared: public State<Person>
{
	void Enter(Person* go);
	void Execute(Person* go);
	void Exit(Person* go);
};

class Angry: public State<Person>
{
	void Enter(Person* go);
	void Execute(Person* go);
	void Exit(Person* go);
};

class Disgust: public State<Person>
{
	void Enter(Person* go);
	void Execute(Person* go);
	void Exit(Person* go);
};

typedef Singleton<Happy> state_Happy;
typedef Singleton<Sad> state_Sad;
typedef Singleton<Excited> state_Excited;
typedef Singleton<Scared> state_Scared;
typedef Singleton<Angry> state_Angry;
typedef Singleton<Angry> state_Disgust;

#endif