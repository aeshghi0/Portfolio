#include "header.h"

char GenderErrorCheck()
{
	char gender;
	do
	{

		cout << "Gender:  ";
		cin.get(gender);
		cin.ignore(100,'\n');

		if (gender != 'm' && gender != 'M' && gender != 'f' && gender != 'F' && gender != 'x' && gender != 'X')
		{
			cout << "*****Invalid gender; please enter M or F*****"<< endl;

		}


	}while(gender != 'm' && gender != 'M' && gender != 'f' && gender != 'F' && gender != 'x' && gender != 'X');
	
	return gender;
}




