#include "AntiThetic.h"

AntiThetic::AntiThetic(const Wrapper<RandomBase>& innerGenerator)
	: RandomBase{ *innerGenerator },
	InnerGenerator{ innerGenerator }, 
	OddEven{ true }, 
	NextVariates( GetDimensionality() )
{
}

RandomBase* AntiThetic::clone() const
{
	return new AntiThetic(*this);
}

void AntiThetic::GetUniforms(std::vector<double>& variates)
{
	if (OddEven)
	{
		InnerGenerator->GetUniforms(variates);
		for (unsigned long i = 0; i < GetDimensionality(); i++)
			NextVariates[i] = 1.0 - variates[i];
		OddEven = false;
	}
	else
	{
		variates = NextVariates;
		OddEven = true;
	}
}

void AntiThetic::SetSeed(unsigned long Seed)
{
	InnerGenerator->SetSeed(Seed);
	OddEven = true;
}

void AntiThetic::Skip(unsigned long numberOfPaths)
{
	if (numberOfPaths)
		return;
	if (OddEven)
	{
		OddEven = false;
		numberOfPaths--;
	}
	
	InnerGenerator->Skip(numberOfPaths / 2);

	if (numberOfPaths % 2)
	{
		std::vector<double> temp(GetDimensionality());
		GetUniforms(temp);
	}
}

void AntiThetic::ResetDimensionality(unsigned long NewDimensionality)
{
	RandomBase::ResetDimensionality(NewDimensionality);

	NextVariates.resize(NewDimensionality);

	InnerGenerator->ResetDimensionality(NewDimensionality);
}

void AntiThetic::Reset()
{
	OddEven = true;
	InnerGenerator->Reset();
}
