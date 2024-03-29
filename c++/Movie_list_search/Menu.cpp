/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Assign #3  : Searching linked list
 * DUE DATE   : 6 November 2019
 ******************************************************************************/

#include "MyHeader.h"

/*******************************************************************************
 * Function - PrintMenu
 * ---------------------------------------------------------------------------
 * This function will output menu option to the screen and waits for the user to
 * input an option to what to what to do. The options are as following:
 *
 * 1 – Output Entire List
 * 2 – Title Search
 * 3 - Genre Search
 * 4 - Actor Search
 * 5 - Year Search
 * 6 - Rating Search (0-9)
 * 0 – Exit
 *
 * return type - Integer
 ******************************************************************************/

int PrintMenu()
{

	/*************
	 * VARIABLES *
	 ************/

	int  option; 		//In & Calc - users choice for the menu
	bool checkInp;		//Calc      - LCV for checking the user's input

	/****************
	 * INITIALIZING *
	 ****************/

	checkInp = true;

	do
	{
		//INPUT

		cout << endl;

		cout << "DVD MENU OPTION:"       << endl << endl;

		cout << "1 – Output Entire List"         << endl;
		cout << "2 – Title Search"               << endl;
		cout << "3 - Genre Search"               << endl;
		cout << "4 - Actor Search"               << endl;
		cout << "5 - Year Search"                << endl;
		cout << "6 - Rating Search (0-9)"        << endl;
		cout << "0 – Exit"                       << endl;

		cout << "Enter an option (0 to exit): ";

		//CHECKS FOR THE CHAR INPUT

		if (!(cin >> option))
		{

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << endl;
			cout << "**** Please input a NUMBER between 0 and 6 ****";
			cout << endl;

			checkInp = false;

		}

		//CHECKS FOR THE RANGE ERROR

		else if (option > 6 || option < 0)
		{

			cout << endl;
			cout << "**** The number "              << option
				 << " is an invalid entry     ****" << endl;
			cout << "**** Please input a number between 0 and 6 ****";
			cout << endl;

			checkInp = false;

		}

		//PASS

		else
		{

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			checkInp = true;

		}

	}while(!checkInp);

	return option;
}




