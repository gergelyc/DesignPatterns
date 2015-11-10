#ifndef VANILLA_H
#define VANILLA_H
#include "PayOff.h"
#include "Wrapper.h"

class VanillaOption
{
public:
	VanillaOption(const Wrapper<PayOff>& ThePayOff_, double Expiry_);
	double GetExpiry() const;
	double OptionPayOff(double Spot) const;

private:
	double Expiry;
	Wrapper<PayOff> ThePayOff;
};

#endif