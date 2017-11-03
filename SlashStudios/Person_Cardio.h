#ifndef PERSON_CARDIO_H
#define PERSON_CARDIO_H

#include "Person.h"

/**
* @class Person_Cardio
* @brief Defines one of the types of Person
* 
* @author Samuel Brownley 31691379
* @version 1.0
* @date 03/11/2017
*/

class Person_Cardio : public Person
{
public:
	/**
	* @brief Creates a new Person_Cardio using the given parameters
	* @param position - list of possible positions for the person
	* @param smgr - scene manager to the GameObject to
	*/
	Person_Cardio(vector<vector3df> position, ISceneManager* smgr);

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