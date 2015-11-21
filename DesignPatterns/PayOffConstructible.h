#ifndef PAYOFF_CONSTRUCTIBLE_H
#define PAYOFF_CONSTRUCTIBLE_H
#include <string>
#include <iostream>
#include "PayOff.h"
#include "PayOffFactory.h"

template<typename T>
class PayOffHelper
{
public:
	PayOffHelper(std::string PayOffId);
	static PayOff* Create(double Strike);
};

template<typename T>
PayOffHelper<T>::PayOffHelper(std::string PayOffId)
{
	PayOffFactory::Instance().RegisterPayOff(PayOffId, &PayOffHelper::Create);
}

template<typename T>
PayOff* PayOffHelper<T>::Create(double Strike)
{
	return new T(Strike);
}
#endif