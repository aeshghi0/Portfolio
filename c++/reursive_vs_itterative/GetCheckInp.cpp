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
 * GetCheckInput
 *    This function will get the user's option from the menu and
 *     returns it into the main.
 *
 *    - returns  nothing -> This will output the menu.
 ****************************************************************/

void GetCheckInp(int &option)  //IN & PROCESS - user's input
{
	/*************
	 * 	VARIABLE *
	 *************/

	bool checkInput;   //PROCESS - input checking

	/***************
	 * 	INITIALIZE *
	 ***************/

	checkInput = false;


	//do while loop for error checking
	do
	{
		//this function prints menu
		Menu();
		cout << "Enter an userOption (0 to exit): ";

		//CHECK INPUT
		if (!(cin >> option))
		{
			cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n**** Please input a NUMBER between 0 and 5 ****\n";
			checkInput = false;
		}

		//CHECK FOR RANGE
		else if (option > 4 || option < 0)
		{
			cout << "\n****   The number " << option
				 << " is an invalid entry   ****\n"
			     << "**** Please input a number between 0 and 5 ****\n";

			checkInput = false;
		}

		else
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			checkInput = true;
		}

	} while (!checkInput);

}


