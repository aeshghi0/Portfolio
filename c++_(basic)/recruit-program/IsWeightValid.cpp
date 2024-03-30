#include"header.h"


int IsWeightValid()
{
	int weight;

	do
	{
		cout << "Weight:  ";
		cin  >> weight;
		cin.ignore(1000,'\n');
		if (weight <= 50 || weight >= 1400)
		{
			cout << "*****Invalid weight, please enter a weight in lb between 50 and 1400.*****" << endl;
		}

	}while(weight < 50 || weight > 1400);


	return weight;

}
