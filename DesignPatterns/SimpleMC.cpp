#include "SimpleMC.h"
#include "Random1.h"
#include <cmath>

void SimpleMonteCarlo(
	const VanillaOption& theOption,
	double Spot,
	const Parameters& Vol,
	const Parameters& r,
	unsigned long NumberOfPaths,
	StatisticsMC& gatherer)
{
	double Expiry = theOption.GetExpiry();
	double variance = Vol.IntegralSquare(0, Expiry);
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5 * variance;

	double movedSpot = Spot * exp(r.Integral(0, Expiry) + itoCorrection);
	double thisSpot;

	double discounting = exp(-r.Integral(0, Expiry));
	
	for (unsigned long i = 0; i < NumberOfPaths; i++)
	{
		double thisGaussian = GetOneGaussianByBoxMuller();
		thisSpot = movedSpot * exp(rootVariance * thisGaussian);
		gatherer.DumpOneResult(discounting * theOption.OptionPayOff(thisSpot));
	}
}
