#include "Person_Cardio.h"
#include "States_Person.h"

Person_Cardio::Person_Cardio(vector<vector3df> position, ISceneManager* smgr) : Person("./media/person_G.obj", position, smgr)
{
	FSM = new StateMachine<Person>(this);
	FSM->SetCurrentState(&state_Roam::Instance());

	SetMovementSpeed(0.6f);

	AddAffordance("freeweight", 0.5f);
	AddAffordance("machineweight", 0.5f);
	AddAffordance("run", 0.9f);
}

void Person_Cardio::Insult()
{
	Emotion* e = GetEmotion();
	e->SetAnger(e->GetAnger() - 0.001f);
	e->SetHappiness(e->GetHappiness() - 0.001f);
	cout << "Sad: " << e->GetSadness() << " Happy: " << e->GetHappiness() << endl;
}

void Person_Cardio::Praise()
{
	Emotion* e = GetEmotion();
	e->SetAnger(e->GetAnger() + 0.001f);
	e->SetHappiness(e->GetHappiness() + 0.001f);
	cout << "Sad: " << e->GetSadness() << " Happy: " << e->GetHappiness() << endl;
}