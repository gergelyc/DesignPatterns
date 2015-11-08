#ifndef VANILLA_H
#define VANILLA_H
#include "PayOff.h"

class VanillaOption
{
public:
	VanillaOption(PayOff& ThePayOff_, double Expiry_);
	VanillaOption(const VanillaOption& original);
	VanillaOption& operator=(const VanillaOption& original);
	double GetExpiry() const
	{
		return Expiry;
	}
	double OptionPayOff(double Spot) const
	{
		return (*ThePayOffPtr)(Spot);
	}
	~VanillaOption();

private:
	double Expiry;
	PayOff* ThePayOffPtr;
};

#endif