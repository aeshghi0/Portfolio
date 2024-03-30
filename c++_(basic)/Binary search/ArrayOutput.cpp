/*****************************************************************************
 * PROGRAMMER : Ali Eshghi & Amirarsalan Valipour
 * STUDENT ID : 1112261 / 1103126
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Lab #5     : Binary Search
 * DUE DATE   : 24 September 2019
 *****************************************************************************
 * ArrayOutput
 * ---------------------------------------------------------------------------
 * This function will output the sorted array.
 *****************************************************************************/

#include "MyHeader.h"

void ArrayOutput(int numAr[], const int AR_SIZE)
{
	int index; 	//Calc - index to go through array

	for(index = 0; index < AR_SIZE; index++)
	{

		cout << "index #" << index
			 << ": " << numAr[index]
			 << endl;

	} //END - FOR

	cout << endl;

}

