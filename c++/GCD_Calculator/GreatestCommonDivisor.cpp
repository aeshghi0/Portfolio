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
 * Function : Greatest Common Divisor
 * ---------------------------------------------------------------------------
 * This function will read in two integers from main, and find their greatest
 * common divisor using the Euclidian Algorithm. Returns this gcd as an int.
 *****************************************************************************/


int GreatestCommonDivisor(int n1,int n2)
{
	int smaller;		// PROCESS - holds the smaller integer
	int larger;			// PROCESS - holds the larger integer
	int remainder;		// PROCESS - the remainder of the two integers
	int greatestDivisor;// PROCESS - the greatest divisor of the two integers
	int divResult;		// PROCESS - the division result of two integers

	/**************************************************************************
	* PROCESS - it gets the greatest divisor of two integers put by the user
	* 			by the Euclidian Algorithm
	*************************************************************************/
	if(n1 >= n2 && n2 != 0)
	{
		larger = n1;
		smaller = n2;
	}
	else
	{
		larger = n2;
		smaller = n1;
	}

	do
	{
		divResult = larger / smaller;
		remainder = larger % smaller;

		if (remainder == 0)
		{
			greatestDivisor = smaller;
		}
		else
		{
			larger = smaller;
			smaller = remainder;
		}

	}while(remainder != 0);

	// returns the greatest divisor of two integers
	return greatestDivisor;

}


