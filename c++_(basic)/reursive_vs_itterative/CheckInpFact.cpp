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
 * CheckInpFact
 *    This function gets the user's input and pass
 *     it back to the main.
 *
 *    returns  integer -> target number for fib/fact
 ****************************************************************/

int CheckInpFact()
{
	/*************
	 *  VARIABLE *
	 *************/

	int factInp;	   //IN - user's target number

	bool checkInput;   //PROCESS - input checking

	/****************
	 *  INITIALIZE  *
	 ****************/

	checkInput = false;


	/************
	 *   INPUT	*
	 ************/

	//do while loop for error checking
	do
	{

		cout << "Enter the target number: ";

		//CHECK INPUT

		if (!(cin >> factInp))
		{
			cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "\n**** Please input a NUMBER ****\n";

			checkInput = false;

		}

		//CHECK FOR RANGE
		else if (factInp < 0)
		{
			cout << "\n****   The number " << factInp
				 << " is an invalid entry   ****\n"
				 << "**** Please input a positive ****\n";

			checkInput = false;
		}

		else
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			checkInput = true;
		}

	} while (!checkInput);

	//returns integer to the main
	return factInp;
}

