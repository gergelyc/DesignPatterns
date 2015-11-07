#include <iostream>
#include "SimpleMC.h"

using namespace std;

int main()
{
	double Expiry;
	double Strike;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;

	cout << "\nEnter expiry\n";
	cin >> Expiry;

	cout << "\nEnter strike\n";
	cin >> Strike;

	cout << "\nEnter spot\n";
	cin >> Spot;

	cout << "\nEnter vol\n";
	cin >> Vol;

	cout << "\nEnter r\n";
	cin >> r;

	cout << "\nNumber of paths\n";
	cin >> NumberOfPaths;

	PayOff callPayOff(Strike, PayOff::call);
	PayOff putPayOff(Strike, PayOff::put);

	double resultCall = SimpleMonteCarlo(callPayOff, Expiry, Spot, Vol, r, NumberOfPaths);
	double resultPut = SimpleMonteCarlo(putPayOff, Expiry, Spot, Vol, r, NumberOfPaths);

	cout << "the call price is " << resultCall << endl;
	cout << "the put price is " << resultPut << endl;
}