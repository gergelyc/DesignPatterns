#include <iostream>
#include "ConvergenceTable.h"
#include "ParkMiller.h"
#include "AntiThetic.h"
//#include "PathDependentAsian.h"
#include "SimpleMC.h"
#include "MCStatistics.h"
#include "PayOffFactory.h"
#include <string>
using namespace std;

int main()
{
	double Expiry;
	double Strike;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;
	string PayOffId;

	cout << "\nEnter expiry\n";
	cin >> Expiry;

	cout << "\nEnter stirke\n";
	cin >> Strike;

	cout << "\nEnter spot\n";
	cin >> Spot;

	cout << "\nEnter vol\n";
	cin >> Vol;

	cout << "\nEnter r\n";
	cin >> r;

	cout << "\nNumber of paths\n";
	cin >> NumberOfPaths;

	cout << "\nEnter pay-off id\n";
	cin >> PayOffId;
	
	//create pay off using the factory
	PayOff* thePayOffPtr = PayOffFactory::Instance().CreatePayOff(PayOffId, Strike);

	//create option
	VanillaOption theOption(*thePayOffPtr, Expiry);

	//set up parameters
	ParametersConstant VolParam{ Vol };
	ParametersConstant rParam{ r };

	//set up random number generator
	RandomParkMiller ParkMillerGenerator(1);
	AntiThetic generator(ParkMillerGenerator);

	//set up statistics gatherer
	StatisticsMean gathererMean;
	ConvergenceTable gathererMeanConvTable(gathererMean);

	//run simulation
	SimpleMonteCarlo(theOption,
		Spot,
		VolParam,
		rParam,
		NumberOfPaths,
		gathererMeanConvTable,
		generator);

	vector<vector<double>> results = gathererMeanConvTable.GetResultSoFar();

	cout << "\nFor the " << PayOffId << " the results are:" << endl;

	for (unsigned long i = 0; i < results.size(); i++)
	{
		for (unsigned long j = 0; j < results[i].size(); j++)
			cout << results[i][j] << " ";
		cout << endl;
	}
}