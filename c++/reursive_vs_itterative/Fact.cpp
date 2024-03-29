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
 * factNum
 *    This function will calculate the factNumorial of user's number.
 *
 *    returns  integer -> factNumorial of the target number
 ****************************************************************/

int Fact(int userInp)	//IN & PROCESS - user's input
{

	/*************
	 * 	VARIABLE *
	 *************/

	long long factNum;		//PROCESS & OUT - factNumorial of user input number

	/***************
	 * 	INITIALIZE *
	 ***************/

	factNum = userInp;

	//if statement for user input
	if(userInp == 0 || userInp == 1)
	{
		factNum = 1;
		return factNum;
	}

	else
	{
		factNum = factNum * Fact(userInp - 1);
		return factNum;
	}
}
