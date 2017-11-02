#include "States_Person.h"
#include "Person.h"

void Roam::Enter(Person* go) {}

void Roam::Execute(Person* go)
{
	go->Walk();
}

void Roam::Exit(Person* go) {}

void Run::Enter(Person* go) {}

void Run::Execute(Person* go)
{
	go->Walk();
}

void Run::Exit(Person* go) {}