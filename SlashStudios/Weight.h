#ifndef WEIGHT_H
#define WEIGHT_H

#include "GameObject.h"

class Weight : public GameObject
{
public:
	Weight(path modelPath, vector3df position, vector3df rotation, float scale, bool createCollision, float weight, ISceneManager* smgr);
	void Interact(GameObject* ninteractor) override;
	void Update(list<GameObject*> gos) override;
private:
	
};

#endif