#ifndef PERSON_H
#define PERSON_H

#include "GameObject.h"
#include "StateMachine.h"

class Person : public GameObject
{
public:
	Person(path modelPath, vector3df position, ISceneManager* smgr);
	void Update(list<GameObject*> gos) override;
	StateMachine<Person>* FSM;
private:

};

#endif