#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include "irrlicht.h"
#include "Affordance.h"
#include <vector>
#include <string>

using namespace std;
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

/**
* @class GameObject
* @brief Creates and manages the basic GameObject
* 
* @author Samuel Brownley 31691379
* @version 1.0
* @date 03/11/2017
*/

class GameObject
{
public:
	/**
	* @brief Create a new default GameObject
	*/
	GameObject();

	/**
	* @brief Creates a new GameObject with the given parameters
	* @param modelPath - the path of model to be used
	* @param position - starting position 
	* @param rotation - starting rotation
	* @param scale - scale of the model
	* @param createCollision - whether or not to create a collision box
	* @param smgr - scene manager to the GameObject to
	*/
	GameObject(path modelPath, vector3df position, vector3df rotation, float scale, bool createCollision, ISceneManager* smgr);

	/**
	* @brief Sets position to newPos
	* @param newPos - new position
	*/
	void SetPosition(vector3df newPos);

	/**
	* @brief Sets rotation to newRot
	* @param newRot - new rotation
	*/
	void SetRotation(vector3df newRot);

	/**
	* @brief Sets old position to newOldPos - used for collisions
	* @param newOldPos - new old position
	*/
	void SetOldPosition(vector3df newOldPos);

	/**
	* @brief Set scale to newScale
	* @param newScale - new scale
	*/
	void SetScale(float newScale);

	/**
	* @brief Returns the current position
	* @return position
	*/
	vector3df GetPosition();

	/**
	* @brief Returns the current rotation
	* @return rotation
	*/
	vector3df GetRotation();

	/**
	* @brief Returns the old position
	* @return old position
	*/
	vector3df GetOldPosition(){return g_oldPosition;}

	/**
	* @brief Returns the current scale
	* @return scale
	*/
	float GetScale();

	/**
	* @brief Return the collision box
	* @return collision box
	*/
	aabbox3d<f32> GetAABB(){return aabb;}

	/**
	* @brief Adds a new affordance to the possible affordances
	* @param affName - name of the new affordance
	* @param addVal - value of the new affordance
	*/
	void AddAffordance(std::string affName, float affVal);

	/**
	* @brief Match affordances between 2 GameObjects
	* Checks if any of the affordances of either GameObject match
	* @return true if any match
	*/
	bool MatchAffordances(GameObject* other);

	/**
	* @brief Match a specific affordance between 2 GameObjects
	* @param afford - affordance to match
	* @return true if both GameObjects contain the affordance in a matching state
	*/
	bool MatchAffordances(Affordance* afford);

	/**
	* @brief Creates the AABB based on the mesh and scale
	*/
	void CreateAABB();
	
	/**
	* @brief Returns the Irrlicht node
	* @return node
	*/
	ISceneNode* GetNode();

	/**
	* @brief Sets the node to n
	* @param n - new value for node
	*/
	void SetNode(ISceneNode* n);

	/**
	* @brief Checks if self and other are colliding
	* @param other - GameObject to check collision
	* @return true if colliding
	*/
	bool CheckCollision(GameObject* other);

	/**
	* @brief Generic Update unless overridden by inheriting class
	* @param gos - list of GameObjects to check collisions
	*/
	void virtual Update(list<GameObject*> gos);

	/**
	* @brief Generic Interact unless overridden by inheriting class
	* @param ninteractor - GameObject interacting with this object
	*/
	void virtual Interact(GameObject* ninteractor);

	/**
	* @brief Set the interacting GameObject
	* @param i - GameObject to be interactor
	*/
	void SetInteractor(GameObject* i);

	/**
	* @brief Set the interactee GameObject
	* @param i - GameObject to be interactee
	*/
	void SetInteractee(GameObject* i);

	/**
	* @brief Sets the AABB of the object
	* @param naabb - new aabb
	*/
	void SetAABB(aabbox3d<f32> naabb);

	/**
	* @brief Returns the interactor
	* @return interactor of this object
	*/
	GameObject* GetInteractor() { return interactor; }

	/**
	* @brief Returns the interactee
	* @param interactee of this object
	*/
	GameObject* GetInteractee() { return interactee; }
private:
	///Node used by Irrlicht
	ISceneNode* node;
	///Current position
	vector3df g_position;
	///Current rotation
	vector3df g_rotation;
	///Scale used to display the mesh
	float g_scale;
	///Old position - used for collision resolution
	vector3df g_oldPosition;
	///List of affordances this object has
	vector<Affordance*> affordances;
	///Object interacting with this object
	GameObject* interactor;
	///Object this object is interacting with
	GameObject* interactee;
	///Collision box for this object
	aabbox3d<f32> aabb;
};

#endif