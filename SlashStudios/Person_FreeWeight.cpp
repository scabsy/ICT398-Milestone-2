#include "Person_FreeWeight.h"
#include "AIStates.h"

Person_FreeWeight::Person_FreeWeight(vector3df position, ISceneManager* smgr) :Person("./media/person_R.obj", position, smgr)
{
	FSM = new StateMachine<Person>(this);
	FSM->SetCurrentState(&state_Sad::Instance());

	AddAffordance("pickup", 0.95f);
}