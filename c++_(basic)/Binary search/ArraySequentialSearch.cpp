/*****************************************************************************
 * PROGRAMMER : Ali Eshghi & Amirarsalan Valipour
 * STUDENT ID : 1112261 / 1103126
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Lab #5     : Binary Search
 * DUE DATE   : 24 September 2019
 *****************************************************************************
 * ArraySequentialSearch
 * ---------------------------------------------------------------------------
 * This function will look for the user's given number in our array through
 *  sequential search and checks to see if it exits, then it will return the
 *  location of that number as an index. if it does not exists it will return
 *   -1 as an sensitive value.
 *****************************************************************************/

#include "MyHeader.h"

int ArraySequentialSearch(int numAr[], const int AR_SIZE, int searchNum)
{

	int index;			//Calc & Output - index to go through the loop
	bool searchStat;	//Calc - bool to check if find the value or no

	//INITIALIZATION

	index = 0;
	searchStat = false;

	//SEQUENTIAL SEARCH

	while(!searchStat && index < AR_SIZE)
	{

		if(searchNum == numAr[index])
		{
			searchStat = true;
		}

		else
		{
			index++;
		}

	} //END - WHILE

	//IF NOT FOUND IN ARRAY

	if(!searchStat)
	{
		index = -1;
	}


	return index;
}



