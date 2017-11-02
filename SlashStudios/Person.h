#ifndef PERSON_H
#define PERSON_H

#include "GameObject.h"
#include "StateMachine.h"
#include "Emotion.h"

class Person : public GameObject
{
public:
	Person() {}
	Person(path modelPath, vector<vector3df> position, ISceneManager* smgr);
	void Update(list<GameObject*> gos) override;
	StateMachine<Person>* FSM;

	float GetMovementSpeed() { return movement_speed; }
	Emotion* GetEmotion() { return emotionalState; }

	void SetMovementSpeed(float newSpeed);
	void SetEmotion(Emotion* nemotion);

	void AddPossibleLocation(vector3df newLoc);
	vector<vector3df> GetPossibleLocations() { return possible_locations; }

	void virtual Insult();
	void virtual Praise();

	void Walk();
private:
	float movement_speed;
	int target_location;
	vector<vector3df> possible_locations;
	Emotion* emotionalState;
	vector3df start_location;

	IBillboardSceneNode* emotion_display;

	void NextTargetLocation();
	void SetEmotionColour();
};

#endif