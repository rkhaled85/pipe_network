#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "PipeNetwork.h"


using namespace std;
int main()
{
	cie::pipenetwork::PipeNetwork project("input.txt");
	vector<double> f = project.computeFluxes();
	for (unsigned int i = 0; i < f.size(); i++)
	{
		cout << f[i] << endl;
	}

	system("PAUSE");

	return 0;
}