#include "Person.h"
#include "AIStates.h"

using namespace std;

Person::Person(path modelPath, vector3df position,ISceneManager* smgr):GameObject(modelPath, position, vector3df(0, 0, 0), .7f, true, smgr)
{
	
}

void Person::Update(list<GameObject*> gos)
{
	FSM->Update();
}
