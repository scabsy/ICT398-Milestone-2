#include "Person_FreeWeight.h"
#include "States_Person.h"

Person_FreeWeight::Person_FreeWeight(vector<vector3df> position, ISceneManager* smgr) :Person("./media/person_R.obj", position, smgr)
{
	FSM = new StateMachine<Person>(this);
	FSM->SetCurrentState(&state_Roam::Instance());

	SetMovementSpeed(0.5f);

	AddAffordance("freeweight", 0.9f);
	AddAffordance("machineweight", 0.5f);
	AddAffordance("run", 0.5f);
}

void Person_FreeWeight::Insult()
{
	Emotion* e = GetEmotion();
	e->SetAnger(e->GetAnger() - 0.003f);
	e->SetHappiness(e->GetHappiness() - 0.003f);
}

void Person_FreeWeight::Praise()
{
	Emotion* e = GetEmotion();
	e->SetAnger(e->GetAnger() + 0.003f);
	e->SetHappiness(e->GetHappiness() + 0.003f);
}