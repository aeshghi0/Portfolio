#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	int 	weight;
	int		lightCount;
	int		lightMediumCount;
	int		mediumHeavyCount;
	int		heavyCount;
	float 	price;

	lightCount       = 0;
	lightMediumCount = 0;
	mediumHeavyCount = 0;
	heavyCount		 = 0;
	price            = 0;

	do
	{
		cout << "Enter the package weight(enter <0> to quit): ";
		cin  >> weight;

		if (weight > 0 && weight <= 2)
		{
			price += 5.00;
			lightCount++;
		}
		else if (weight > 2 && weight <= 12)
		{
			price += 8.50;
			lightMediumCount++;
		}
		else if (weight > 12 && weight <= 20)
		{
			price += 12.50;
			mediumHeavyCount++;
		}
		else if (weight > 20 && weight <= 40)
		{
			price += 18.00;
			heavyCount++;
		}

	}while (weight != 0);

	cout << left;
	cout << setprecision(2)  << fixed << endl << endl;
	cout << lightCount 		 << " package(s) under 2 lbs." 		 << endl;
	cout << lightMediumCount << " package(s) between 3-12 lbs."  << endl;
	cout << mediumHeavyCount << " package(s) between 13-20 lbs." << endl;
	cout << heavyCount		 << " package(s) between 21-40 lbs." << endl;
	cout << "The total shipping price is $" << price;
	cout << right;



	return 0;
}

