/*****************************************************************************
 * PROGRAMMER : Ali Eshghi & Amirarsalan Valipour
 * STUDENT ID : 1112261 / 1103126
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Lab #5     : Binary Search
 * DUE DATE   : 24 September 2019
 *****************************************************************************
 * ArrayBinarySearch
 * ---------------------------------------------------------------------------
 * This function will look for the user's given number in our array through
 *  binary search and checks to see if it exits, then it will return the
 *  location of that number as an index. if it does not exists it will return
 *   -1 as an sensitive value.
 *****************************************************************************/

#include "MyHeader.h"

int ArrayBinarySearch(int numAr[], const int AR_SIZE, int searchNum)
{
	int 	index;			//Calc & Output - index to go through the loop
	int 	low;			//Calc - to store the smaller number
	int 	high;			//Calc - to store the bigger number
	int		mid;			//Calc - middle of the array address
	bool 	searchStat;		//Calc - bool to check if find the value or no

	//INITIALIZATION

	low = 0;
	high = AR_SIZE - 1;
	searchStat = false;

	//BINARY SEARCH

	while(!searchStat && low <= high)
	{
		mid = (low + high) / 2;

		if(numAr[mid] == searchNum)
		{
			searchStat = true;
			index = mid;
		}

		else if(numAr[mid] < searchNum)
		{
			low = mid + 1;
		}

		else
		{
			high = mid - 1;
		}
	} //END - WHILE

	//IF NOT FOUND IN ARRAY

	if(!searchStat)
	{
		index = -1;
	}

	return index;
}
