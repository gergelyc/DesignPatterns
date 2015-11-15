#ifndef EXOTICENGINE_H
#define EXOTICENGINE_H
#include "MCStatistics.h"
#include "Wrapper.h"
#include "Parameters.h"
#include "PathDependent.h"

class ExoticEngine
{
public:
	ExoticEngine(const Wrapper<PathDependent>& TheProduct_, const Parameters& r_);

	virtual void GetOnePath(std::vector<double>& SpotValues) = 0;
	void DoSimulation(StatisticsMC& TheGatherer, unsigned long NumberOfPath);
	virtual ~ExoticEngine(){}
	double DoOnePath(const std::vector<double>& SpotValues) const;

private:
	Wrapper<PathDependent> TheProduct;
	Parameters r;
	std::vector<double> Discounts;
	mutable std::vector<CashFlow> TheseCashFlows;
};
#endif