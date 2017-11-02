#include "Machine.h"

Machine::Machine(path modelPath, vector3df position, vector3df rotation, float scale, bool createCollision, float weight, ISceneManager* smgr) :GameObject(modelPath, position, rotation, scale, createCollision, smgr)
{
	AddAffordance("pickup", weight);
}

void Machine::Interact(GameObject* ninteractor)
{
	if (GetInteractor() != NULL)
	{
		SetInteractor(NULL);
		ninteractor->SetInteractee(NULL);
	}
	else
	{
		if (ninteractor->GetInteractee() == NULL)
		{
			SetInteractor(ninteractor);
			ninteractor->SetInteractee(this);
		}
	}
}

void Machine::Update(list<GameObject*> gos)
{
	if (GetInteractor())
	{
		GetInteractor()->SetPosition(vector3df(GetPosition().X, GetPosition().Y, GetPosition().Z));
	}
}