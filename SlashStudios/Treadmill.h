#ifndef TREADMILL_H
#define TREADMILL_H

#include "GameObject.h"

/**
* @class Treadmill
* @brief Defines the Treadmill object
* 
* @author Samuel Brownley 31691379
* @version 1.0
* @date 03/11/2017
*/

class Treadmill : public GameObject
{
public:
	/**
	* @brief Creates a new Treadmill object with the given parameters
	* @param modelPath - the path of model to be used
	* @param position - starting position 
	* @param rotation - starting rotation
	* @param scale - scale of the model
	* @param createCollision - whether or not to create a collision box
	* @param speed - speed of the treadmill, used for affordance
	* @param smgr - scene manager to the GameObject to
	*/
	Treadmill(path modelPath, vector3df position, vector3df rotation, float scale, bool createCollision, float speed, ISceneManager* smgr);
	
	/**
	* @brief Interact with this object
	* @param ninteractor - GameObject interacting with this object
	*/
	void Interact(GameObject* ninteractor) override;
	
	/**
	* @brief Updates the Treadmill object
	* @param gos - list of GameObjects
	*/
	void Update(list<GameObject*> gos) override;
private:

};

#endif