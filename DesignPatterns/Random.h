#ifndef RANDOM_H
#define RANDOM_H
#include <vector>

class RandomBase
{
public:
	RandomBase(unsigned long Dimensionality);

	inline unsigned long GetDimensionality() const;

	virtual RandomBase* clone() const = 0;
	virtual void GetUniforms(std::vector<double>& variates) = 0;
	virtual void Skip(unsigned long numberOfPaths) = 0;
	virtual void SetSeed(unsigned long Seed) = 0;
	virtual void Reset() = 0;

	virtual void GetGaussian(std::vector<double>& variates);
	virtual void ResetDimensionality(unsigned long NewDimensionality);
private:
	unsigned long Dimensionality;
};

unsigned long RandomBase::GetDimensionality() const
{
	return Dimensionality;
}

#endif