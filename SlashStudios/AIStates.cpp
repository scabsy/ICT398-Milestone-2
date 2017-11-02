#include "AIStates.h"
#include "Person.h"

//Happy state
void Happy::Enter(Person* go)
{

}

void Happy::Execute(Person* go)
{
	go->SetPosition(vector3df(go->GetPosition().X + .01f, go->GetPosition().Y, go->GetPosition().Z));
}

void Happy::Exit(Person* go)
{

}

//Sad state
void Sad::Enter(Person* go)
{

}

void Sad::Execute(Person* go)
{
	go->SetPosition(vector3df(go->GetPosition().X , go->GetPosition().Y, go->GetPosition().Z + .01f));
}

void Sad::Exit(Person* go)
{

}

//Exited state
void Excited::Enter(Person* go)
{

}

void Excited::Execute(Person* go)
{

}

void Excited::Exit(Person* go)
{

}

//Scared state
void Scared::Enter(Person* go)
{

}

void Scared::Execute(Person* go)
{

}

void Scared::Exit(Person* go)
{

}

//Angry state
void Angry::Enter(Person* go)
{

}

void Angry::Execute(Person* go)
{
	go->SetPosition(vector3df(go->GetPosition().X + .01f, go->GetPosition().Y, go->GetPosition().Z + .01f));
}

void Angry::Exit(Person* go)
{

}