#include "ExoticEngine.h"
#include <cmath>

ExoticEngine::ExoticEngine(const Wrapper<PathDependent>& TheProduct_, const Parameters& r_)
	: TheProduct{ TheProduct_ }, r{ r_ }, Discounts{ TheProduct_->PossibleCashFlowTimes() }
{
	TheseCashFlows.resize(TheProduct->MaxNumberOfCashFlows());

	for (auto& Discount : Discounts)
		Discount = std::exp(-Discount * r.Integral(0.0, Discount)); //on the right hand side Discount is the time fo the cashflow
}

void ExoticEngine::DoSimulation(StatisticsMC& TheGatherer, unsigned long NumberOfPaths)
{
	std::vector<double> SpotValues(TheProduct->GetLookAtTimes().size());

	double ThisValue;
	for (unsigned long i = 0; i < NumberOfPaths; i++)
	{
		GetOnePath(SpotValues);
		ThisValue = DoOnePath(SpotValues);
		TheGatherer.DumpOneResult(ThisValue);
	}

	return;
}

double ExoticEngine::DoOnePath(const std::vector<double>& SpotValues) const
{
	unsigned long NumberOfCashFlows;
	NumberOfCashFlows = TheProduct->CashFlows(SpotValues, TheseCashFlows);

	double ThisValue = 0.0;
	for (unsigned long i = 0; i < NumberOfCashFlows; i++)
	{
		ThisValue += TheseCashFlows[i].Amount * Discounts[TheseCashFlows[i].TimeIndex];
	}

	return ThisValue;
}