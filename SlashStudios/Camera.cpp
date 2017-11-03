#include "Camera.h"

Camera::Camera(float rotationSpeed,float movementSpeed, vector3df position,ISceneManager* smgr, ITriangleSelector* selector)
{
	SKeyMap keyMap[6];
	keyMap[0].Action = EKA_MOVE_FORWARD;
	keyMap[0].KeyCode = KEY_KEY_W;
	keyMap[1].Action = EKA_MOVE_BACKWARD;
	keyMap[1].KeyCode = KEY_KEY_S;
	keyMap[2].Action = EKA_STRAFE_LEFT;
	keyMap[2].KeyCode = KEY_KEY_A;
	keyMap[3].Action = EKA_STRAFE_RIGHT;
	keyMap[3].KeyCode = KEY_KEY_D;
	keyMap[4].Action = EKA_JUMP_UP;
	keyMap[4].KeyCode = KEY_SPACE;
	keyMap[5].Action = EKA_CROUCH;
	keyMap[5].KeyCode = KEY_KEY_C;

	SetNode((ICameraSceneNode*)smgr->addCameraSceneNodeFPS(0, rotationSpeed, movementSpeed, 0, keyMap, 6, true, 3.f));
	GetNode()->setPosition(position);

	if(selector)
	{
		ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(selector, GetNode(), vector3df(5, 5, 5), vector3df(0, -10, 0), vector3df(0, position.Y / 2, 0));
		selector->drop();
		GetNode()->addAnimator(anim);
		anim->drop();
	}

	AddAffordance("freeweight", 0.8f);
	AddAffordance("machineweight",0.6f);
	AddAffordance("run", 0.6f);
	AddAffordance("insult", 1);
	AddAffordance("praise", 1);
}

void Camera::CreateAABB(vector3df mins,vector3df maxs)
{
	SetAABB(aabbox3df(mins, maxs));
}

float Camera::GetRotationY()
{
	return GetNode()->getRotation().Y;
}

void Camera::Update(list<GameObject*> other)
{
	//cout << node->getRotation().Y << endl;

	for(list<GameObject*>::Iterator it=other.begin();it!=other.end();++it)
	{
		if(CheckCollision(*it))
		{
			SetPosition(vector3df(GetOldPosition().X,GetOldPosition().Y,GetOldPosition().Z));
		}
	}
	
	SetOldPosition(GetPosition());
}

