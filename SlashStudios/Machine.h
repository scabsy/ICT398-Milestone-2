#ifndef MACHINE_H
#define MACHINE_H

#include "GameObject.h"

/**
* @class Machine
* @brief Defines the Machine object
* 
* @author Samuel Brownley 31691379
* @version 1.0
* @date 03/11/2017
*/

class Machine : public GameObject
{
public:
	/**
	* @brief Creates a new Machine object with the given parameters
	* @param modelPath - the path of model to be used
	* @param position - starting position 
	* @param rotation - starting rotation
	* @param scale - scale of the model
	* @param createCollision - whether or not to create a collision box
	* @param weight - weight of the machine, used for affordance
	* @param smgr - scene manager to the GameObject to
	*/
	Machine(path modelPath, vector3df position, vector3df rotation, float scale, bool createCollision, float weight, ISceneManager* smgr);
	
	/**
	* @brief Interact with this object
	* @param ninteractor - GameObject interacting with this object
	*/
	void Interact(GameObject* ninteractor) override;
	
	/**
	* @brief Updates the Machine object
	* @param gos - list of GameObjects
	*/
	void Update(list<GameObject*> gos) override;
private:

};

#endif
