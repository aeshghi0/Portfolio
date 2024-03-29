/*****************************************************************************
 * PROGRAMMER : Ali Eshghi & Amirarsalan Valipour
 * STUDENT ID : 1112261 / 1103126
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Lab #5     : Binary Search
 * DUE DATE   : 24 September 2019
 *****************************************************************************
 * ArraySort
 * ---------------------------------------------------------------------------
 * This function will sort the array from the smaller number to the bigger
 * 	numbers.
 *****************************************************************************/

#include "MyHeader.h"

void ArraySort(int numAr[], const int AR_SIZE)
{
	int i;			//Calc - index to go through array
	int j;			//Calc - index to go through array
	int tempNum;	//Calc - store value to replace

	//SORTS THE ARRAY
	for(i = 1; i < AR_SIZE; i++)
	{
		tempNum = numAr[i];

		j = i - 1;

		while (j >= 0 && numAr[j] > tempNum)
		{
			numAr[j + 1] = numAr[j];

			j = j - 1;
		} // END - While

		numAr[j + 1] = tempNum;

	} // End - For

}
