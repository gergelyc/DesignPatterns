#include "Vanilla.h"

VanillaOption::VanillaOption(const Wrapper<PayOff>& ThePayOff_, double Expiry_)
	: Expiry{ Expiry_ }, ThePayOff{ ThePayOff_ }
{
}

double VanillaOption::GetExpiry() const
{
	return Expiry;
}

double VanillaOption::OptionPayOff(double Spot) const
{
	return ThePayOff->operator()(Spot);
}