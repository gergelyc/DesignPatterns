#include "Random.h"
#include "Normals.h"

RandomBase::RandomBase(unsigned long Dimensionality_)
	: Dimensionality{ Dimensionality_ }
{
}

void RandomBase::GetGaussian(std::vector<double>& variates)
{
	GetUniforms(variates);

	for (unsigned long i = 0; i < Dimensionality; i++)
	{
		double x = variates[i];
		variates[i] = InverseCumulativeNormal(x);
	}
}

void RandomBase::ResetDimensionality(unsigned long NewDimensionality)
{
	Dimensionality = NewDimensionality;
}