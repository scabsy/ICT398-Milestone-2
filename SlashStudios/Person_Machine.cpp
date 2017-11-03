#include "Person_Machine.h"
#include "States_Person.h"

Person_Machine::Person_Machine(vector<vector3df> position, ISceneManager* smgr):Person("./media/person_B.obj",position, smgr)
{
	FSM = new StateMachine<Person>(this);
	FSM->SetCurrentState(&state_Roam::Instance());

	SetMovementSpeed(0.6f);

	AddAffordance("freeweight", 0.5f);
	AddAffordance("machineweight", 0.9f);
	AddAffordance("run", 0.5f);
}

void Person_Machine::Insult()
{
	Emotion* e = GetEmotion();
	e->SetAnger(e->GetAnger() - 0.003f);
	e->SetHappiness(e->GetHappiness() - 0.003f);
}

void Person_Machine::Praise()
{
	Emotion* e = GetEmotion();
	e->SetAnger(e->GetAnger() + 0.003f);
	e->SetHappiness(e->GetHappiness() + 0.003f);
}
