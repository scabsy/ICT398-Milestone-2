#include "Person_Cardio.h"
#include "AIStates.h"

Person_Cardio::Person_Cardio(vector3df position, ISceneManager* smgr) :Person("./media/person_G.obj", position, smgr)
{
	FSM = new StateMachine<Person>(this);
	FSM->SetCurrentState(&state_Angry::Instance());


	AddAffordance("pickup", 0.5);
}