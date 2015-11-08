#ifndef SIMPLEMC_H
#define SIMPLEMC_H
#include "Vanilla.h"
#include "Parameters.h"

double SimpleMonteCarlo(
	const VanillaOption& theOption,
	double Spot,
	const Parameters& Vol,
	const Parameters& r,
	unsigned long NumberOfPaths);

#endif