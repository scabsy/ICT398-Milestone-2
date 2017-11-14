#include "Affordance.h"
#include "Singleton.h"

Affordance::Affordance(std::string newName, float amount)
{
	SetName(newName);
	SetValue(amount);	
}

void Affordance::SetName(std::string newName)
{
	name = newName;
}

void Affordance::SetValue(float newVal)
{
	if (newVal < 0 || newVal > 1)
	{
		value = 0;
	}
	else
	{
		value = newVal;
	}	
}

std::string Affordance::GetName()
{
	return name;
}

float Affordance::GetValue()
{
	return value;
}

bool Affordance::Compare(Affordance* b)
{
	if (!name.compare(b->GetName()) && value >= b->GetValue())
	{
		return true;
	}
	return false;
}