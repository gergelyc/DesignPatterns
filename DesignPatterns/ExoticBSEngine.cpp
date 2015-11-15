#include "ExoticBSEngine.h"
#include <cmath>

ExoticBSEngine::ExoticBSEngine(const Wrapper<PathDependent>& TheProduct_,
	const Parameters& R_,
	const Parameters& D_,
	const Parameters& Vols_,
	const Wrapper<RandomBase>& TheGenerator_,
	double Spot_)
	: ExoticEngine(TheProduct_, R_), TheGenerator{ TheGenerator_ }
{
	std::vector<double> Times{ TheProduct_->GetLookAtTimes() };
	NumberOfTimes = Times.size();
	TheGenerator->ResetDimensionality(NumberOfTimes);
	Drifts.resize(NumberOfTimes);
	StandardDeviations.resize(NumberOfTimes);

	double Variance = Vols_.IntegralSquare(0.0, Times[0]);
	Drifts[0] = R_.Integral(0.0, Times[0]) - D_.Integral(0.0, Times[0]) - 0.5 * Variance);
	StandardDeviations[0] = std::sqrt(Variance);

	for (unsigned long i = 1; i < NumberOfTimes; i++)
	{
		double thisVariance = Vols_.IntegralSquare(0.0, Times[0]);
		Drifts[i] = R_.Integral(Times[i - 1], Times[i])
			- D_.Integral(Times[i - 1], Times[i])
			- 0.5 * thisVariance;

		StandardDeviations[i] = std::sqrt(thisVariance);
	}

	Variates.resize(NumberOfTimes);
	LogSpot = std::log(Spot_);
}

void ExoticBSEngine::GetOnePath(std::vector<double> SpotValues)
{
	TheGenerator->GetUniforms(Variates);
	
	double CurrentLogSpot = LogSpot;
	for (unsigned long i = 0; i < NumberOfTimes; i++)
	{
		CurrentLogSpot += Drifts[i] + StandardDeviations[i] * Variates[i];
		SpotValues[i] = std::exp(CurrentLogSpot);
	}
}