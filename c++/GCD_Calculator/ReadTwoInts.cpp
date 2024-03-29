/******************************************************************************
 * PROGRAMMER : Ali Eshghi & Elsa Micklnin
 * STUDENT ID : 1112261    & 1028119
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * LAB #3     : Functions and arrays
 * DUE DATE   : 10 September 2019
 *****************************************************************************/

#include "header.h"

/******************************************************************************
 * Function : ReadTwoInts
 * ---------------------------------------------------------------------------
 * This function will read two integers from the user and assigns them to two
 * integers from the main passed by reference
 *****************************************************************************/
void ReadTwoInts(int &n1,
				 int &n2)
{
	cout << left;
	cout << setw(26) << "Enter the first integer:";
	cin  >> n1;

	cout << setw(26) << "Enter the second integer:";
	cin  >> n2;

	cout << endl;

	cin.ignore(10000, '\n');

}

