#ifndef SIMPLEMC_H
#define SIMPLEMC_H
#include "Vanilla.h"
#include "Parameters.h"
#include "MCStatistics.h"

void SimpleMonteCarlo(
	const VanillaOption& theOption,
	double Spot,
	const Parameters& Vol,
	const Parameters& r,
	unsigned long NumberOfPaths,
	StatisticsMC& gatherer);

#endif