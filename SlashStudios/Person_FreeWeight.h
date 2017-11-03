#ifndef PERSON_FREEWEIGHT_H
#define PERSON_FREEWEIGHT_H

#include "Person.h"

/**
* @class Person_FreeWeight
* @brief Defines one of the types of Person
* 
* @author Samuel Brownley 31691379
* @version 1.0
* @date 03/11/2017
*/

class Person_FreeWeight : public Person
{
public:
	/**
	* @brief Creates a new Person_FreeWeight using the given parameters
	* @param position - list of possible positions for the person
	* @param smgr - scene manager to the GameObject to
	*/
	Person_FreeWeight(vector<vector3df> position, ISceneManager* smgr);

	/**
	* @brief Action to perform when insulted
	*/
	void Insult() override;
	
	/**
	* @brief Action to perform when praised
	*/
	void Praise() override;
private:

};

#endif