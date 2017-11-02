#ifndef CAMERA_H
#define CAMERA_H

#include "Person.h"

class Camera:public Person
{
public:
	Camera(float rotationSpeed,float movementSpeed, vector3df position, ISceneManager* smgr);
	Camera(float rotationSpeed,float movementSpeed, vector3df position,ISceneManager* smgr, ITriangleSelector* selector);
	void SetKeyMap();
	void CreateAABB(vector3df mins,vector3df maxs);
	float GetRotationY();
	void Update(list<GameObject*> other);
private:
	//ISceneNode* camera;
	SKeyMap keyMap[6];
};

#endif