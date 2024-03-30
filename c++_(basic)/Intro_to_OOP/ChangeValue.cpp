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
 * This function asks the user for the new value that the user wants to change
 *
 * RETURNS: float
 ******************************************************************************/

float ChangeValue()
{
	/*************
	 * VARIABLES *
	 *************/

	float 	newValue; //IN - user input for new value
	bool	checkInp; //PROCESS - input checking

	/**************
	 * INITIALIZE *
	 **************/

	checkInp = false;

	//do while loop for error checking
	do
	{
		//INPUT

		cout << "\nNEW VALUE: ";



		//CHECKS FOR THE CHAR INPUT

		if (!(cin >> newValue))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << endl;
			cout << "**** Please input a NUMBER between 0 and 400000 ****";
			cout << endl << endl;

			checkInp = false;

		}

		//CHECKS FOR THE RANGE ERROR

		else if (newValue >= 400001 || newValue <= -1 )
		{

			cout << endl;
			cout << "**** The number "              << newValue
			<< " is an invalid entry     ****" << endl;
			cout << "**** Please input a number between 0 and 400000 ****";
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

	//returns float to the main
	return newValue;
}




