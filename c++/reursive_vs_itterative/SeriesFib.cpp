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
 * SeriesFib
 *    This function will calculate the fibbonacci number of user's number
 *    input
 *
 *    returns  integer -> fibbonacci result of the target number
 ****************************************************************/

int SeriesFib(int userInp)	//IN & PROCESS - user's input
{
	/*************
	 * 	VARIABLE *
	 *************/

	long long fib;		//PROCESS & OUT- fibonacci series of user input num


	/***************
	 * 	INITIALIZE *
	 ***************/

	fib = userInp;

	//if statement for 0 or 1 input
	if(userInp == 0 || userInp == 1)
	{
		return fib;
	}

	else
	{
		fib = SeriesFib(fib - 1) + SeriesFib(fib - 2);
		return fib;
	}
}



