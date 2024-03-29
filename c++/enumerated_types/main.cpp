/***********************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * LAB #0.5	  : Enumerated Types
 * DUE DATE   : 23 September 2019
 ***********************************/

#include "myHeader.h"


int main()
{


	string	inputDay;
	string	theDay;
	Days	today;





	do
	{
		cout << "What day is today?: ";
		getline(cin,inputDay);

		ConvertToDays(today, inputDay);



		ConvertToString(today);



	}while (today != INVALID);

	return 0;
}



