#ifndef PAYOFFBRIDGE_H
#define PAYOFFBRIDGE_H
#include "PayOff.h"

class PayOffBridge
{
public:
	PayOffBridge(const PayOff& innerPayOff);
	PayOffBridge(const PayOffBridge& original);
	PayOffBridge& operator=(const PayOffBridge& original);

	inline double operator()(double Spot) const;
	~PayOffBridge();

private:
	PayOff* ThePayOffPtr;
};

double PayOffBridge::operator()(double Spot) const
{
	return ThePayOffPtr->operator()(Spot);
}

#endif PAYOFFBRIDGE_H