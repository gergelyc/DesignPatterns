#include "PathDependent.h"

PathDependent::PathDependent(const std::vector<double>& LookAtTimes_)
	: LookAtTimes{ LookAtTimes_ }
{
}

const std::vector<double> PathDependent::GetLookAtTimes() const
{
	return LookAtTimes;
}