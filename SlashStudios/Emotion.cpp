#include "Emotion.h"

Emotion::Emotion()
{
	happiness = 0.5f;
	anger = 0.5f;
	disgust = 0.5f;
	fear = 0.5f;
	sadness = 0.5f;
	surprise = 0.5f;
}
Emotion::Emotion(float nhappiness, float nanger, float ndisgust, float nfear, float nsadness, float nsurprise)
{
	happiness = nhappiness;
	anger = nanger;
	disgust = ndisgust;
	fear = nfear;
	sadness = nsadness;
	surprise = nsurprise;
}

void Emotion::SetHappiness(float nhappiness)
{
	happiness = nhappiness;
	if (nhappiness > 1)
	{
		happiness = 1;
	}
	if (nhappiness < 0)
	{
		happiness = 0;
	}
}

void Emotion::SetAnger(float nanger)
{
	anger = nanger;
	if (nanger > 1)
	{
		anger = 1;
	}
	if (nanger < 0)
	{
		anger = 0;
	}
}

void Emotion::SetDisgust(float ndistgust)
{
	disgust = ndistgust;
	if (ndistgust > 1)
	{
		disgust = 1;
	}
	if (ndistgust < 0)
	{
		disgust = 0;
	}
}

void Emotion::SetFear(float nfear)
{
	fear = nfear;
	if (nfear > 1)
	{
		happiness = 1;
	}
	if (nfear < 0)
	{
		happiness = 0;
	}
}

void Emotion::SetSadness(float nsadness)
{
	sadness = nsadness;
	if (nsadness > 1)
	{
		sadness = 1;
	}
	if (nsadness < 0)
	{
		sadness = 0;
	}
}

void Emotion::SetSurprise(float nsurprise)
{
	surprise = nsurprise;
	if (nsurprise > 1)
	{
		surprise = 1;
	}
	if (nsurprise < 0)
	{
		surprise = 0;
	}
}

float Emotion::GetEmotionalState()
{
	return (happiness + anger + disgust + fear + sadness + surprise) / 6;
}