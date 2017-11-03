#ifndef EMOTION_H
#define EMOTION_H

/**
* @class Emotion
* @brief Creates and manages Emotion objects
* Manages each of the 6 emotions given to each person
* 
* @author Samuel Brownley 31691379
* @version 1.0
* @date 03/11/2017
*/

class Emotion
{
private:
	///Each of the 6 emotions that make up human emotions
	float happiness,anger,disgust,fear,sadness,surprise;
	
public:
	/**
	* @brief Creates a new default Emotion object
	*/
	Emotion();

	/**
	* @brief Creates a new Emotion object with the given parameters
	* @param nhappiness - values of happiness
	* @param nanger - values of anger
	* @param ndisgust - values of disgust
	* @param nfear - values of fear
	* @param nsadness - values of sadness
	* @param nsurprise - values of surprise
	*/
	Emotion(float nhappiness, float nanger, float ndisgust, float nfear, float nsadness, float nsurprise);
	
	/**
	* @brief Set the value of happiness to nhappiness
	* @param nhappiness - new value of happiness
	*/
	void SetHappiness(float nhappiness);

	/**
	* @brief Set the value of anger to nanger
	* @param nanger - new value of anger
	*/
	void SetAnger(float nanger);

	/**
	* @brief Set the value of disgust to ndisgust
	* @param ndisgust - new value of disgust
	*/
	void SetDisgust(float ndisgust);

	/**
	* @brief Set the value of fear to nfear
	* @param nfear - new value of fear
	*/
	void SetFear(float nfear);

	/**
	* @brief Set the value of sadness to nsadness
	* @param nsadness - new value of sadness
	*/
	void SetSadness(float nsadness);

	/**
	* @brief Set the value of surprise to nsurprise
	* @param nsurprise - new value of surprise
	*/
	void SetSurprise(float nsurprise);

	/**
	* @brief Returns the value of happiness
	* @return value of happiness
	*/
	float GetHappiness() { return happiness; }

	/**
	* @brief Returns the value of anger
	* @return value of anger
	*/
	float GetAnger() { return anger; }

	/**
	* @brief Returns the value of disgust
	* @return value of disgust
	*/
	float GetDisgust() { return disgust; }

	/**
	* @brief Returns the value of fear
	* @return value of fear
	*/
	float GetFear() { return fear; }

	/**
	* @brief Returns the value of sadness
	* @return value of sadness
	*/
	float GetSadness() { return sadness; }

	/**
	* @brief Returns the value of surprise
	* @return value of surprise
	*/
	float GetSurprise() { return surprise; }

	/**
	* @brief Creates an emotional state from the values of all 6 emotions
	* @return emotional state of the object
	*/
	float GetEmotionalState();
};

#endif