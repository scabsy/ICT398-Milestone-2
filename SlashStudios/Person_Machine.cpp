#include "Person_Machine.h"
#include "AIStates.h"

Person_Machine::Person_Machine(vector3df position, ISceneManager* smgr):Person("./media/person_B.obj",position, smgr)
{
	FSM = new StateMachine<Person>(this);
	FSM->SetCurrentState(&state_Happy::Instance());
	AddAffordance("pickup", 0.8f);
}

