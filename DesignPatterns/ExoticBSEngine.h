#ifndef EXOTIC_BS_ENGINE_H
#define EXOTIC_BS_ENGINE_H
#include "ExoticEngine.h"
#include "Random.h"

class ExoticBSEngine : public ExoticEngine
{
public:
	ExoticBSEngine(const Wrapper<PathDependent>& TheProduct_,
		const Parameters& R_,
		const Parameters& D_,
		const Parameters& Vol_,
		const Wrapper<RandomBase>& TheGenerator_,
		double Spot_);

	void GetOnePath(std::vector<double> SpotValues);
	virtual ~ExoticBSEngine() {}

private:
	std::vector<double> Drifts;
	std::vector<double> StandardDeviations;
	Wrapper<RandomBase> TheGenerator;
	unsigned long NumberOfTimes;
	double LogSpot;
	std::vector<double> Variates;
};

#endif