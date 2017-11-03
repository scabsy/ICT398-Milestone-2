#ifndef AFFORDANCE_H
#define AFFORDANCE_H
#include <iostream>

using namespace std;

/**
* @class Affordance
* @brief Creates and manages Affordance objects
* 
* 
* @author Samuel Brownley 31691379
* @version 1.0
* @date 03/11/2017
*/

class Affordance
{
public:
	/**
	* @brief Creates a new Affordance with the given parameters
	* @param newName - name of the affordance
	* @param newVal - value for the affordance
	*/
	Affordance(std::string newName,float newVal);

	/**
	* @brief Sets name to newName
	* @param newName - new value of name
	*/
	void SetName(std::string newName);

	/**
	* @brief Sets value to newVal
	* @param newVal - new value between 0 - 1
	*/
	void SetValue(float newVal);

	/**
	* @brief Returns the name of the affordance
	* @return - name of the affordance
	*/
	std::string GetName();

	/**
	* @brief Returns the value of the affordance
	* @return value of the affordance
	*/
	float GetValue();

	/**
	* @brief Compare with another affordance
	* Checks whether the name of the 2 affordances match, also whether the value of the other affordance is less than this
	* @param b - affordance to compare with
	* @return boolean value of whether the names of the 2 affordances match and if the values are equal or greater than each other
	*/
	bool Compare(Affordance* b);

private:
	///Name of the affordance
	std::string name;
	
	///Value of the affordance - between 0 - 1
	float value;
};

#endif