#include "PathDependentAsian.h"
#include <numeric>

PathDependentAsian::PathDependentAsian(const std::vector<double>& LookAtTimes_,
	double DeliveryTime_,
	const Wrapper<PayOff>& ThePayOff_)
	: PathDependent{ LookAtTimes_ }, DeliveryTime{ DeliveryTime_ }, ThePayOff{ ThePayOff_ }
{
	NumberOfTimes = LookAtTimes_.size();
}

unsigned long PathDependentAsian::MaxNumberOfCashFlows() const
{
	return 1UL;
}

std::vector<double> PathDependentAsian::PossibleCashFlowTimes() const
{
	return std::vector < double > {DeliveryTime};
}

unsigned long PathDependentAsian::CashFlows(const std::vector<double>& SpotValues,
	std::vector<CashFlow>& GeneratedFlows) const
{
	double Average = std::accumulate(SpotValues.begin(), SpotValues.end(), 0.0) / NumberOfTimes;
	double ThisValue = ThePayOff->operator()(Average);
	GeneratedFlows[0].TimeIndex = 0UL;
	GeneratedFlows[0].Amount = ThisValue;

	return 1UL;
}

PathDependent* PathDependentAsian::clone() const
{
	return new PathDependentAsian{ *this };
}