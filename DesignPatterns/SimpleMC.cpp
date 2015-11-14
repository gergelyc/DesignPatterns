#include "SimpleMC.h"
#include <cmath>

void SimpleMonteCarlo(
	const VanillaOption& theOption,
	double Spot,
	const Parameters& Vol,
	const Parameters& r,
	unsigned long NumberOfPaths,
	StatisticsMC& gatherer,
	RandomBase& generator)
{
	generator.ResetDimensionality(1);

	double Expiry = theOption.GetExpiry();
	double variance = Vol.IntegralSquare(0, Expiry);
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5 * variance;

	double movedSpot = Spot * exp(r.Integral(0, Expiry) + itoCorrection);
	double thisSpot;

	double discounting = exp(-r.Integral(0, Expiry));
	
	std::vector<double> VariateVector(1);

	for (unsigned long i = 0; i < NumberOfPaths; i++)
	{
		generator.GetGaussian(VariateVector);
		thisSpot = movedSpot * exp(rootVariance * VariateVector[0]);
		gatherer.DumpOneResult(discounting * theOption.OptionPayOff(thisSpot));
	}
}
