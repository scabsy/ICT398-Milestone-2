#ifndef TREADMILL_H
#define TREADMILL_H

#include "GameObject.h"

class Treadmill : public GameObject
{
public:
	Treadmill(path modelPath, vector3df position, vector3df rotation, float scale, bool createCollision, float speed, ISceneManager* smgr);
	void Interact(GameObject* ninteractor) override;
	void Update(list<GameObject*> gos) override;
private:

};

#endif