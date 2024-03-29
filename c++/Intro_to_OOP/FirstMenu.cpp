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
 * FirstMenu
 *    This function gets the user choice for the first menu that has been run
 *
 *    RETURNS: integer
 ******************************************************************************/

int FirstMenu()
{

	/*************
	 * VARIABLES *
	 *************/

	int startOption;
	bool	checkInp;

	/**************
	 * INITIALIZE *
	 **************/

	checkInp = false;

	//do while loop for error checking
	do
	{
		//INPUT

		cout << "1 - Initialize the Animals " << endl;
		cout << "0 - Exit" << endl;

		cout << "Enter Selection: ";


		//CHECKS FOR THE CHAR INPUT

		if (!(cin >> startOption))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << endl;
			cout << "**** Please input a NUMBER between 0 or 1 ****";
			cout << endl << endl;

			checkInp = false;

		}

		//CHECKS FOR THE RANGE ERROR

		else if (startOption >= 2 || startOption <= -1 )
		{

			cout << endl;
			cout << "**** The number "              << startOption
			<< " is an invalid entry     ****" << endl;
			cout << "**** Please input a number between 0 or 1 ****";
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
	return startOption;
}
