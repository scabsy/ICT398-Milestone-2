#ifndef MACHINE_H
#define MACHINE_H

#include "GameObject.h"

class Machine : public GameObject
{
public:
	Machine(path modelPath, vector3df position, vector3df rotation, float scale, bool createCollision, float weight, ISceneManager* smgr);
	void Interact(GameObject* ninteractor) override;
	void Update(list<GameObject*> gos) override;
private:

};

#endif
