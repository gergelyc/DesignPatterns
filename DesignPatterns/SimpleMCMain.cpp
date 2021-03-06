#include <iostream>
#include "SimpleMC.h"
#include "DoubleDigital.h"
#include "ConvergenceTable.h"

using namespace std;

int main()
{
	double Expiry;
	double LowerLevel;
	double UpperLevel;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;

	cout << "\nEnter expiry\n";
	cin >> Expiry;

	cout << "\nEnter lower level\n";
	cin >> LowerLevel;

	cout << "\nEnter upper level\n";
	cin >> UpperLevel;

	cout << "\nEnter spot\n";
	cin >> Spot;

	cout << "\nEnter vol\n";
	cin >> Vol;

	cout << "\nEnter r\n";
	cin >> r;

	cout << "\nNumber of paths\n";
	cin >> NumberOfPaths;

	PayOffDoubleDigital payOffDoubleDigital{ LowerLevel, UpperLevel };
	VanillaOption theOption(payOffDoubleDigital, Expiry);

	ParametersConstant VolParam(Vol);
	ParametersConstant rParam(r);

	StatisticsMean gathererMean;
	ConvergenceTable gathererMeanConvTable(gathererMean);

	SimpleMonteCarlo(theOption, Spot, VolParam, rParam, NumberOfPaths, gathererMeanConvTable);
	
	vector<vector<double>> results = gathererMeanConvTable.GetResultSoFar();

	cout << "For the double digital the results are:" << endl;

	for (unsigned long i = 0; i < results.size(); i++)
	{
		for (unsigned long j = 0; j < results[i].size(); j++)
			cout << results[i][j] << " ";
		cout << endl;
	}
}