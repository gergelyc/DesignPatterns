#ifndef SIMPLEMC_H
#define SIMPLEMC_H
#include "Vanilla.h"

double SimpleMonteCarlo(
	const VanillaOption& theOption,
	double Spot,
	double Vol,
	double r,
	unsigned long NumberOfPaths);

#endif