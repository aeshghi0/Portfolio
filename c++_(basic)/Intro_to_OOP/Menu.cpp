/*******************************************************************************
 * PROGRAMMER : Ali Eshghi & Amirarsalan Valipour
 * STUDENT ID : 1112261 & 1103126
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Assign #2  : tic-tac-toe game (multi-dimensional arrays)
 * DUE DATE   : 19 September 2019
 ******************************************************************************/

#include "MyHeader.h"
#include "ClassHeader.h"

/*******************************************************************************
 * Menu
 * This function outputs the main menu and gets the user's choice for the menu
 * options
 *
 * RETURNS: ineger
 ******************************************************************************/

int Menu()
{
	/*************
	 * VARIABLES *
	 *************/

	int     menuOption; //IN - user input for menu
	bool	checkInp;   //PROCESS - input check

	/**************
	 * INITIALIZE *
	 **************/

	checkInp = false;


	//do while loop for error checking
	do
	{
		//INPUT

		cout << "1 - Initialize the Animals " << endl;
		cout << "2 - Change Age" 			  << endl;
		cout << "3 - Change Value"			  << endl;
		cout << "4 - Display" 				  << endl;
		cout << "0 - Exit" 					  << endl;

		cout << "Enter Selection: ";


		//CHECKS FOR THE CHAR INPUT

		if (!(cin >> menuOption))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << endl;
			cout << "**** Please input a NUMBER between 0 and 4 ****";
			cout << endl << endl;

			checkInp = false;

		}

		//CHECKS FOR THE RANGE ERROR

		else if (menuOption >= 5 || menuOption <= -1 )
		{

			cout << endl;
			cout << "**** The number "              << menuOption
			<< " is an invalid entry     ****" << endl;
			cout << "**** Please input a number between 0 and 4 ****";
			cout << endl << endl;

			checkInp = false;

		}

		//PASS

		else
		{

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			checkInp = true;

		}

	}while(!checkInp);

	//returns an integer to the main
	return menuOption;
}
