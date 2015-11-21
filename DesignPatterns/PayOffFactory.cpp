#include "PayOffFactory.h"
#include <iostream>

using namespace std;

PayOffFactory& PayOffFactory::Instance()
{
	static PayOffFactory theFactory;
	return theFactory;
}

void PayOffFactory::RegisterPayOff(string PayOffId, CreatePayOffFunction CreatorFunction)
{
	TheCreateFunctions.insert(pair<string, CreatePayOffFunction>(PayOffId, CreatorFunction));
}

PayOff* PayOffFactory::CreatePayOff(string PayOffId, double Strike)
{
	map<string, CreatePayOffFunction>::const_iterator i = TheCreateFunctions.find(PayOffId);

	if (i == TheCreateFunctions.end())
	{
		cout << PayOffId << " is an unknown payoff." << endl;
		return nullptr;
	}
	
	return (i->second)(Strike);
}