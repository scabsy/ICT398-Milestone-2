#ifndef SINGLETON_H
#define SINGLETON_H

/**
* @class Singleton
* @brief 
* 
* @author Samuel Brownley 31691379
* @version 1.0
* @date 03/11/2017
*/

template <class T>
class Singleton
{
public:
	/**
	* @brief Creates instance of an object of type <T>
	*/
	static T& Instance()
	{
		static T _instance;
		return _instance;
	}

private:
	/**
	* @brief Default constructor
	*/
	Singleton();

	/**
	* @brief Default deconstructor
	*/
	~Singleton();

	/**
	* @brief 
	*/
	Singleton(Singleton const&);

	/**
	* @brief Make this equal the parameter
	* @param new Singleton
	* @return a copy of the parameter
	*/
	Singleton& operator = (Singleton const&);
};

#endif