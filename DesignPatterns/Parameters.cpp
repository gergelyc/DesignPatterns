#include "Parameters.h"
#include <cmath>

Parameters::Parameters(const ParametersInner& innerParameter)
{
	InnerObjectPtr = innerParameter.clone();
}

Parameters::Parameters(const Parameters& original)
{
	InnerObjectPtr = original.InnerObjectPtr->clone();
}

Parameters& Parameters::operator=(const Parameters& original)
{
	if (this != &original)
	{
		delete InnerObjectPtr;
		InnerObjectPtr = original.InnerObjectPtr->clone();
	}
	return *this;
}

double Parameters::Mean(double time1, double time2) const
{
	return InnerObjectPtr->Integral(time1, time2) / (time2 - time1);
}

double Parameters::RootMeanSquare(double time1, double time2) const
{
	double result = InnerObjectPtr->IntegralSquare(time1, time2);
	return sqrt(result / (time2 - time1));
}

Parameters::~Parameters()
{
	delete InnerObjectPtr;
}

ParametersConstant::ParametersConstant(double Constant_)
	: Constant{ Constant_ }, ConstantSquare{ Constant * Constant }
{
}

ParametersInner* ParametersConstant::clone() const
{
	return new ParametersConstant(*this);
}

double ParametersConstant::Integral(double time1, double time2) const
{
	return Constant * (time2 - time1);
}

double ParametersConstant::IntegralSquare(double time1, double time2) const
{
	return ConstantSquare * (time2 - time1);
}