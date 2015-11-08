#include "PayOffBridge.h"

PayOffBridge::PayOffBridge(const PayOff& innerPayOff)
{
	ThePayOffPtr = innerPayOff.clone();
}

PayOffBridge::PayOffBridge(const PayOffBridge& original)
{
	ThePayOffPtr = original.ThePayOffPtr->clone();
}

PayOffBridge& PayOffBridge::operator=(const PayOffBridge& original)
{
	if (this != &original)
	{
		delete ThePayOffPtr;
		ThePayOffPtr = original.ThePayOffPtr->clone();
	}
	return *this;
}

PayOffBridge::~PayOffBridge()
{
	delete ThePayOffPtr;
}