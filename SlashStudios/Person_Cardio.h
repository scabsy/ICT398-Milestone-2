#ifndef PERSON_CARDIO_H
#define PERSON_CARDIO_H

#include "Person.h"

class Person_Cardio : public Person
{
public:
	Person_Cardio(vector<vector3df> position, ISceneManager* smgr);
	void Insult() override;
	void Praise() override;
private:

};

#endif