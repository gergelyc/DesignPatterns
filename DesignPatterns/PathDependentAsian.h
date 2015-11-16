#ifndef PATH_DEPENDENT_ASIAN_H
#define PATH_DEPENDENT_ASIAN_H
#include "PathDependent.h"
#include "Wrapper.h"
#include "PayOff.h"

class PathDependentAsian : public PathDependent
{
public:
	PathDependentAsian(const std::vector<double>& LookAtTimes_,
		double DeliveryTime_,
		const Wrapper<PayOff>& ThePayOff_);

	virtual unsigned long CashFlows(const std::vector<double>& SpotValues,
		std::vector<CashFlow>& GeneratedFlows) const;
	virtual PathDependent* clone() const;
	virtual std::vector<double> PossibleCashFlowTimes() const;
	virtual unsigned long MaxNumberOfCashFlows() const;

private:
	Wrapper<PayOff> ThePayOff;
	double DeliveryTime;
	unsigned long NumberOfTimes;
};
#endif