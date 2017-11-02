#ifndef EMOTION_H
#define EMOTION_H

class Emotion
{
private:
	float happiness,anger,disgust,fear,sadness,surprise;
	
public:
	Emotion();
	Emotion(float nhappiness, float nanger, float ndistgust, float nfear, float nsadness, float nsurprise);
	
	void SetHappiness(float nhappiness);
	void SetAnger(float nanger);
	void SetDisgust(float ndisgust);
	void SetFear(float nfear);
	void SetSadness(float nsadness);
	void SetSurprise(float nsurprise);

	float GetHappiness() { return happiness; }
	float GetAnger() { return anger; }
	float GetDisgust() { return disgust; }
	float GetFear() { return fear; }
	float GetSadness() { return sadness; }
	float GetSurprise() { return surprise; }

	float GetEmotionalState();
};

#endif