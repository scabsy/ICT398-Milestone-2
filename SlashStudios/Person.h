#ifndef PERSON_H
#define PERSON_H

#include "GameObject.h"
#include "StateMachine.h"
#include "Emotion.h"

/**
* @class Person
* @brief Defines the Person object
* 
* @author Samuel Brownley 31691379
* @version 1.0
* @date 03/11/2017
*/

class Person : public GameObject
{
public:
	/**
	* @brief Creates a default Person object
	*/
	Person() {}

	/**
	* @brief Creates a new Person object using the given parameters
	* @param modelPath - the path of model to be used
	* @param position - starting position 
	* @param smgr - smgr - scene manager to the GameObject to
	*/
	Person(path modelPath, vector<vector3df> position, ISceneManager* smgr);

	/**
	* @brief Updates the person each frame
	* @param gos - list of GameObjects
	*/
	void Update(list<GameObject*> gos) override;
	
	/**
	* @brief Returns the movement speed of the person
	* @return movement speed
	*/
	float GetMovementSpeed() { return movement_speed; }

	/**
	* @brief Return the current emotional state
	* @return emotional state
	*/
	Emotion* GetEmotion() { return emotionalState; }

	/**
	* @brief Sets the movement speed to newSpeed
	* @param newSpeed - new speed
	*/
	void SetMovementSpeed(float newSpeed);

	/**
	* @brief Sets the emotional state to nemotion
	* @param nemotion - new emotion
	*/
	void SetEmotion(Emotion* nemotion);

	/**
	* @brief Adds a new location to the possible locations
	* @param newLoc - new location to add
	*/
	void AddPossibleLocation(vector3df newLoc);

	/**
	* @brief Returns the possible locations the person can walk
	* @return possible locations
	*/
	vector<vector3df> GetPossibleLocations() { return possible_locations; }

	/**
	* @brief Generic action when praised by the player
	*/
	void virtual Insult();

	/**
	* @brief Generic action when praised by the player
	*/
	void virtual Praise();

	/**
	* @brief Person walks between the start location and end location
	*/
	void Walk();
private:
	///Movement speed of the person
	float movement_speed;
	///Index of possible_locations to walk
	int target_location;
	///List of possible locations to walk
	vector<vector3df> possible_locations;
	///Emotional state of the person
	Emotion* emotionalState;
	///Location used when transitioning between 2 points
	vector3df start_location;
	///Billboard above the persons head, showing emotion
	IBillboardSceneNode* emotion_display;

	/**
	* @brief Finds the next location to walk toward
	*/
	void NextTargetLocation();
	
	/**
	* @brief Set the colour of the emotion billboard based on the emotionalState
	*/
	void SetEmotionColour();

protected:
	///State machine of the person
	StateMachine<Person>* FSM;
};

#endif