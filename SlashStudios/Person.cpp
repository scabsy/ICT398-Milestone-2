#include "Person.h"
#include "AIStates.h"
#include <math.h>

using namespace std;

Person::Person(path modelPath, vector<vector3df> position,ISceneManager* smgr):GameObject(modelPath, position[0], vector3df(0, 0, 0), .7f, true, smgr)
{
	if (position.size() > 0)
	{
		possible_locations = position;
		target_location = 1;
		start_location = GetPosition();
	}

	AddAffordance("insult", 1);
	AddAffordance("praise", 1);

	emotionalState = new Emotion();
	emotion_display = smgr->addBillboardSceneNode();
	emotion_display->setMaterialFlag(EMF_LIGHTING, false);
	emotion_display->setMaterialType(EMT_SOLID);
	emotion_display->setSize(dimension2d<f32>(20, 20));
	SetEmotionColour();
}

void Person::Update(list<GameObject*> gos)
{
	bool colliding = false;
	for (list<GameObject*>::Iterator it = gos.begin(); it != gos.end(); ++it)
	{
		if (CheckCollision(*it))
		{
			colliding = true;
		}
	}

	//if(!colliding)
		FSM->Update();

	SetEmotionColour();
	emotion_display->setPosition(vector3df(GetPosition().X, GetPosition().Y + 120, GetPosition().Z));
}

void Person::SetMovementSpeed(float newSpeed)
{
	movement_speed = newSpeed;
}

void Person::Walk()
{		
	if (possible_locations.size() > 1)
	{
		float xDist = possible_locations[target_location].X - start_location.X;// x;
		float zDist = possible_locations[target_location].Z - start_location.Z;// z;

		float dist = sqrt(xDist*xDist + zDist*zDist);

		float newX = GetPosition().X + (xDist / dist * movement_speed);
		float newZ = GetPosition().Z + (zDist / dist * movement_speed);

		SetPosition(vector3df(newX, GetPosition().Y, newZ));

		if (sqrt(pow(GetPosition().X - start_location.X, 2) + pow(GetPosition().Z - start_location.Z, 2)) >= dist)
		{
			NextTargetLocation();
			start_location = GetPosition();
		}
	}
}

void Person::AddPossibleLocation(vector3df newLoc)
{
	possible_locations.push_back(newLoc);
}

void Person::SetEmotion(Emotion* nemotion)
{
	emotionalState = nemotion;
}

void Person::NextTargetLocation()
{
	if (target_location < possible_locations.size()-1)
	{
		target_location++;
	}
	else
	{
		target_location = 0;
	}
}

void Person::SetEmotionColour()
{
	float es = emotionalState->GetEmotionalState();
	cout << es << endl;
	if (es < 0.35)
	{
		emotion_display->setColor(SColor(255, 255, 0, 0));
	}
	else if(es > 0.65)
	{
		emotion_display->setColor(SColor(255, 0, 255, 0));
	}
	else
	{
		emotion_display->setColor(SColor(255, 255, 255, 0));
	}

}

void Person::Insult()
{

}

void Person::Praise()
{

}