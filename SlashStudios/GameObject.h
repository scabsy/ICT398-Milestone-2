#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include "irrlicht.h"
#include "Affordance.h"
#include <vector>
#include <string>

using namespace std;
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class GameObject
{
public:
	GameObject();
	GameObject(vector3df position, vector3df whd);
	GameObject(path modelPath, vector3df position, vector3df rotation, float scale, bool createCollision, ISceneManager* smgr);


	void SetPosition(vector3df newPos);
	void SetRotation(vector3df newRot);
	void SetOldPosition(vector3df newOldPos);
	void SetScale(float newScale);

	vector3df GetPosition();
	vector3df GetRotation();
	vector3df GetOldPosition(){return g_oldPosition;}
	float GetScale();
	aabbox3d<f32> GetAABB(){return aabb;}

	void AddAffordance(std::string affName, float affVal);
	bool MatchAffordances(GameObject* other);

	void CreateAABB();
	void CreateAABB(vector3df position, vector3df whd);

	ISceneNode* GetNode();

	bool CheckCollision(GameObject* other);

	void virtual Update(list<GameObject*> gos);
	void virtual Interact(GameObject* ninteractor);

	void SetInteractor(GameObject* i);
	void SetInteractee(GameObject* i);

	GameObject* GetInteractor() { return interactor; }
	GameObject* GetInteractee() { return interactee; }
	
	ISceneNode* node;
	aabbox3d<f32> aabb;
private:
	//ISceneNode* node;
	vector3df g_position;
	vector3df g_rotation;
	float g_scale;

	vector3df g_oldPosition;

	vector<Affordance*> affordances;
	GameObject* interactor;
	GameObject* interactee;
	//aabbox3d<f32> aabb;
};

#endif