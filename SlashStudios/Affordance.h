#ifndef AFFORDANCE_H
#define AFFORDANCE_H
#include <iostream>

using namespace std;

class Affordance
{
public:
	Affordance(std::string newName,float newVal);

	void SetName(std::string newName);
	void SetValue(float newVal);

	std::string GetName();
	float GetValue();

	bool Compare(Affordance* b);

private:
	std::string name;
	float value;
};

#endif