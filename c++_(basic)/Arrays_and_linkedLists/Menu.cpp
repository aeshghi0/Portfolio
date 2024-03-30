/************************************************************
* AUTHOR	    : Ali Eshghi
* STUDENT ID    : 1112261
* LAB #13		: LAB 13 - ARRAYS AND LINKED LIST (OOP)
* CLASS	        : CS 1B
* SECTION	    : MW - 7:30 pm - 9:50 pm
* DUE DATE	    : 12/3/2019
*************************************************************/

#include"MyHeader.h"

/************************************************************
 * Function - Menu
 * ----------------------------------------------------------
 * This function will outputs the menu and prompts the user
 * to choose an option from the menu
 *
 * return type - integer
 * 				 the function is int type
 ************************************************************/

int Menu()
{

	/*************
	 * 	VARIABLE *
	 *************/

	int menuOption;
	bool checkInp;

	/*******************
	 * 	INITIALIZATION *
	 *******************/

	checkInp = false;

	//do while loop for input check
	do
	{

	cout << "SHEEP LIST MANAGER" << endl;
	cout << "1 - Add Sheep" << endl;
	cout << "2 - Output 1st Sheep" << endl;
	cout << "3 - Find Sheep" << endl;
	cout << "4 - List Size" << endl;
	cout << "5 - Output List" << endl;
	cout << "6 - Clear list" << endl;
	cout << "0 - Exit" << endl;
	cout << "Enter a command: ";



	//CHECKS FOR THE CHAR INPUT

	if (!(cin >> menuOption))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << endl;
		cout << "**** Please input a NUMBER between 0 or 6 ****";
		cout << endl << endl;

		checkInp = false;

	}

	//CHECKS FOR THE RANGE ERROR

	else if (menuOption > 6 || menuOption < 0 )
	{

		cout << endl;
		cout << "**** The number "              << menuOption
		<< " is an invalid entry     ****" << endl;
		cout << "**** Please input a number between 0 or 6 ****";
		cout << endl << endl;

		checkInp = false;

	}

	checkInp = true;

	}while(!checkInp);


	return menuOption;
}


