#ifndef CAMERA_H
#define CAMERA_H

#include "Person.h"

/**
* @class Camera
* @brief Creates and manages Camera objects
* 
* @author Samuel Brownley 31691379
* @version 1.0
* @date 03/11/2017
*/

class Camera:public Person
{
public:
	/**
	* @brief Creates a new Camera with the given parameters
	* @param rotationSpeed - speed the camera rotated
	* @param movementSpeed - speed the camera moves
	* @param position - starting position of the camera
	* @param smgr - scene manager to add the camera to
	*/
	Camera(float rotationSpeed,float movementSpeed, vector3df position, ISceneManager* smgr);

	/**
	* @brief Creates a new Camera with the given parameters
	* @param rotationSpeed - speed the camera rotated
	* @param movementSpeed - speed the camera moves
	* @param position - starting position of the camera
	* @param smgr - scene manager to add the camera to
	* @param selector - Triangle selector containing the data for the environment mesh
	*/
	Camera(float rotationSpeed,float movementSpeed, vector3df position,ISceneManager* smgr, ITriangleSelector* selector);
	
	
	/**
	* @brief Create the collision box for the camera
	* @param mins - vector of minimal values of the AABB
	* @param maxs - vector of maximum values of the AABB
	*/
	void CreateAABB(vector3df mins,vector3df maxs);

	/**
	* @brief Returns the Y value of the camera rotation
	* @return y rotation of the camera
	*/
	float GetRotationY();

	/**
	* @brief Update the camera object with each tick
	* @param other - list of other GameObjects to check collisions
	*/
	void Update(list<GameObject*> other);
private:
	///Keys and their associated functionality
	SKeyMap keyMap[6];
};

#endif