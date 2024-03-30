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
 * ChangeAge
 * This function asks the user for the new age that the user wants to change
 *
 * RETURNS: integer
 ******************************************************************************/

int ChangeAge()
{

	/*************
	 * VARIABLES *
	 *************/

	int 	newAge;   //IN - the new age user input
	bool	checkInp; //PROCESS - input check

	/**************
	 * INITIALIZE *
	 **************/

	checkInp = false;

	//do while loop for error checking
	do
	{
		//INPUT

		cout << "\nNEW AGE: ";



		//CHECKS FOR THE CHAR INPUT

		if (!(cin >> newAge))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << endl;
			cout << "**** Please input a NUMBER between 0 and 10 ****";
			cout << endl << endl;

			checkInp = false;

		}

		//CHECKS FOR THE RANGE ERROR

		else if (newAge >= 11 || newAge <= -1 )
		{

			cout << endl;
			cout << "**** The number "              << newAge
			<< " is an invalid entry     ****" << endl;
			cout << "**** Please input a number between 0 and 10 ****";
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

	//returns integer to main
	return newAge;

}


