/******************************************************************************
* AUTHOR     : Amirarsalan Valipour & Ali Eshghi
* STUDENT ID : 1103126 - 1112261
* LAB #10    : Creating an Ordered List
* CLASS      : CS 1B
* SECTION    : MW - 7:30 pm
* DUE DATE   : 11/05/2019
*******************************************************************************
* PrintMenu
*******************************************************************************
*  This function will output the menu, gets the user's option and checks to see
*    if the input is eligible or not.
*******************************************************************************/

#include "MyHeader.h"

int PrintMenu()
{

	int  option; 		//In & Calc - users choice for the menu

	bool checkInp;		//Calc      - LCV for checking the user's input

	checkInp = true;

	do
	{
		//INPUT

		cout << endl;

		cout << "LIST MENU:"             << endl;
		cout << "1 – Create List"        << endl;
		cout << "2 – Display List"       << endl;
		cout << "3 - Is the list empty?" << endl;
		cout << "4 - Search by name"     << endl;
		cout << "5 - Remove Node"        << endl;
		cout << "6 - Clear List"         << endl;
		cout << "0 – to Exit"            << endl;

		cout << "Enter a command (0 to exit): ";

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







