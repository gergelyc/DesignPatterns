#ifndef VANILLA_H
#define VANILLA_H
#include "PayOff.h"

class VanillaOption
{
public:
	VanillaOption(PayOff& ThePayOff_, double Expiry_);
	double GetExpiry() const;
	double OptionPayOff(double Spot) const;

private:
	double Expiry;
	PayOff& ThePayOff;
};

#endif