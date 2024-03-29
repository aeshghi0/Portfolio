/***********************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Assign #1  : Functions and arrays
 * DUE DATE   : 19 September 2019
 ***********************************************/
#include "MyHeader.h"

/******************************************************************************
 * Function : SumOrAvg
 * ---------------------------------------------------------------------------
 * This function gets all the balances from the list using a for loop
 * and add them up together to get the sum and average of all the balances.
 * then returns a float type variable to a float variable in the main called
 * "sumOrAvg".
 *****************************************************************************/


float SumOrAvg(float balanceAr[], int option, const int AR_SIZE)
{
	/*************
	 * VARIABLES *
	 ************/

	float 	sum;	 //PROCESS - sum of all numbers
	float 	avg;	 //PROCESS - average of all numbers
	float 	sumOrAvg;//PROCESS & OUT - assigns sum or average to itself
	int 	index;	 //PROCESS - used for the for loop.

	//initialize the sum to zero, then adds the balance to it
	sum = 0;

	//initialize the sum or average to zero, then assign a value to it
	sumOrAvg = 0;

	//for loop using index to add the balances to the sum
	for (index = 0; index <= AR_SIZE; index++)
	{
		sum += balanceAr[index];
	}//end of for loop

	//calculating average
	avg = sum / AR_SIZE;

	//if statement for option 3, assigns sum to sumOrAvg
	if (option == 3)
	{
		sumOrAvg = sum;
	}//end of if statement

	//if statement for option 4, assigns average to sumOrAvg
	else if (option == 4)
	{
		sumOrAvg = avg;
	}//end of if statement

	//returns a float variable and assigns it to a float variable in main
	return sumOrAvg;
}
