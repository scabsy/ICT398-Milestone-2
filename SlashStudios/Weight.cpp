#include "Weight.h"

Weight::Weight(path modelPath, vector3df position, vector3df rotation, float scale, bool createCollision, float weight, ISceneManager* smgr) :GameObject(modelPath, position, rotation, scale, createCollision, smgr)
{
	SetInteractor(NULL);
	AddAffordance("pickup", weight);
}


void Weight::Interact(GameObject* ninteractor)
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


void Weight::Update(list<GameObject*> gos) 
{
	if (GetInteractor())
	{
		SetPosition(vector3df(GetInteractor()->GetPosition().X+50, GetInteractor()->GetPosition().Y/2, GetInteractor()->GetPosition().Z));
	}
}