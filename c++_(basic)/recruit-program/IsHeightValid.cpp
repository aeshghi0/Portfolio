#include"header.h"

int IsHeightValid()
{
	int	height;
	do
	{
		cout << "Height:  ";
		cin  >> height;

		if(height < 24 || height > 110)
		{
			cout << "*****Invalid height, please enter a height in inches between 24 and 110*****" << endl;
		}
	}while(height < 24 || height > 110);

	return height;
}


