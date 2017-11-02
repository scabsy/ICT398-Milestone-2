#ifndef PERSON_FREEWEIGHT_H
#define PERSON_FREEWEIGHT_H

#include "Person.h"

class Person_FreeWeight : public Person
{
public:
	Person_FreeWeight(vector<vector3df> position, ISceneManager* smgr);
	void Insult() override;
	void Praise() override;
private:

};

#endif