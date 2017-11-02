#ifndef PERSON_MACHINE_H
#define PERSON_MACHINE_H

#include "Person.h"

class Person_Machine : public Person
{
public:
	Person_Machine(vector<vector3df> position, ISceneManager* smgr);
	void Insult() override;
	void Praise() override;
private:

};

#endif