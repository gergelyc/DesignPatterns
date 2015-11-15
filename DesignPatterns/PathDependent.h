#ifndef PATHDEPENDENT_H
#define PATHDEPENDENT_H
#include <vector>

class CashFlow
{
public:
	double Amount;
	unsigned long TimeIndex;

	CashFlow(unsigned long TimeIndex_ = 0UL, double Amount_ = 0.0)
		: Amount{ Amount_ }, TimeIndex{ TimeIndex_ }
	{
	}
};

class PathDependent
{
public:
	PathDependent(const std::vector<double>& LookAtTimes);

	const std::vector<double> GetLookAtTimes() const;

	virtual unsigned long MaxNumberOfCashFlows() const = 0;
	virtual std::vector<double> PossibleCashFlowTimes() const = 0;
	virtual unsigned long CashFlows(const std::vector<double>& SpotValues, std::vector<CashFlow>& GeneratedFlows) const = 0;
	virtual PathDependent* clone() const = 0;

	virtual ~PathDependent() {}

private:
	std::vector<double> LookAtTimes;
};

#endif