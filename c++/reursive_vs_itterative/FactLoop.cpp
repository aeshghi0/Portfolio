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
 * FactLoop
 *    This function will calculate the factorial number of user's number
 *    input using a loop
 *
 *    returns  integer -> factorial result of the target number
 ****************************************************************/

int FactLoop(int userInp)	//IN & PROCESS - user's input
{

	/*************
	 * 	VARIABLE *
	 *************/


	long long factTot;	//PROCESS & OUT - factorial of the user input number
	int i;			//PROCESS - loop LCV

	//if statement for 1 or 0 input
	if(userInp == 0 || userInp == 1)
	{
		factTot = 1;
		return factTot;
	}

	else
	{
		for(i = 2; i <= userInp ; i++)
		{
			factTot = factTot * i;
		}

		//returns an integer to the main
		return factTot;
	}
}

