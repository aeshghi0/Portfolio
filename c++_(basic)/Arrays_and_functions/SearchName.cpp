/***********************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Assign #1  : Functions and arrays
 * DUE DATE   : 19 September 2019
 ***********************************************/
#include "MyHeader.h"

/******************************************************************************
 * Function : SearchName
 * ---------------------------------------------------------------------------
 * This function prompts the user that who is the user searching for and uses
 * while loop and an boolean expression to check the name array and if the name
 * was found, returns the index of the array to be used in the parallel arrays
 * and if the name was not found, lets the user know
 *****************************************************************************/

int SearchName(information personalData[],const int AR_SIZE)
{

	/*************
	 * VARIABLES *
	 ************/

	int index;			// PROCESS - used for the for loop
	string searchName;	// IN & PROCESS - user input and used for the search
	bool searchStat;	// PROCESS - changes if the name was found

	//initializing the boolean expression to true
	searchStat = true;

	//initializing the index to zero to be used in the while loop
	index = 0;

	//Prompts the user for for who is he/she searching for.
	cin.ignore(1000,'\n');
	cout << "\nWho do you want to search for (enter done to exit) :  ";
	getline(cin,searchName);


	//uses the while loop to check if the name was found and
	//if the index has reached the array length.
	while (searchStat && index <= AR_SIZE)
	{
		//if statement to see if the name assigned to the index of the
		//array matches the searched name
		if (searchName == nameAr[index])
		{
			//changes when the name is found
			searchStat = false;
		}//End of if statement

		//else statement for if the name was not match with the array,
		// element index, then increments the index.
		else
		{
			index++;
		}//end of else statement

	}//end of while loop


	//if statement to print out the not found name and lets the user know that
	//there is no matching name in the list with the searched name.
	if (searchStat == true)
	{
		cout << searchName << " was not found." << endl << endl;
		index = 11;
	}//end of if statement

	//else statement to let the user know that the name was found
	else if (searchStat == false)
	{
		cout << "Found." << endl << endl;
	}//end of else statement


	//returns an integer type variable and assign it to an integer variable in the main.
	return index;
}

