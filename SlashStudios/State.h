#ifndef STATE_H
#define STATE_H

/**
* @class State
* @brief Define the virtual State class
* 
* @author Samuel Brownley 31691379
* @version 1.0
* @date 03/11/2017
*/

template <class T>
class State
{
public:
	/**
	* @brief Default constructor
	*/
	virtual ~State(){}

	/**
	* @brief Triggered when a state is entered
	* @param T* - object of owners type
	*/
	virtual void Enter(T*)=0;

	/**
	* @brief Triggered when a state is executed
	* @param T* - object of owners type
	*/
	virtual void Execute(T*)=0;

	/**
	* @brief Triggered when a state is exited
	* @param T* - object of owners type
	*/
	virtual void Exit(T*)=0;
};

#endif