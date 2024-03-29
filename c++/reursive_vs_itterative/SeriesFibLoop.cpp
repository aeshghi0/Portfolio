/************************************************************
* AUTHOR	    : Ali Eshghi
* STUDENT ID    : 1112261
* ASSIGNMENT #4	: Assessing Recursion Performance
* CLASS	        : CS 1B
* SECTION	    : MW - 7:30 pm - 9:50 pm
* DUE DATE	    : 11/26/2019
*************************************************************/

#include "MyHeader.h"

/****************************************************************
 * SeriesFibLoop
 *    This function will calculate the fibbinacci result number of
 *    user's number input using a loop
 *
 *    returns  integer -> fibbonacci result of the target number
 ****************************************************************/

int SeriesFibLoop(int userInp)	//IN & PROCESS - user's input
{
	/*************
	 * 	VARIABLE *
	 *************/

	//INTEGERS

	long long i;			//PROCESS & OUT - fibonacci series of user input num
	long long x;			//PROCESS - number for n - 1
	long long y;			//PROCESS - number for n - 2
	int  z;

	/***************
	 * 	INITIALIZE *
	 ***************/

	i = 1;
	x = 0;
	y = 1;
	z = 2;

	//While loop for number of times
	while (z <= userInp)
	{
		x = y;
		y = i;

		i = x + y;

		z++;
	}

	//returns an integer to the main
	return i;

}
