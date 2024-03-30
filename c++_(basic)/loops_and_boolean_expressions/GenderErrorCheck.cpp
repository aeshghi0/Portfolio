/******************************************************************************
* AUTHOR     : Ali Eshghi
* STUDENT IDs: 1112261
* AS #6	     : Assignment 6 - Loop & Boolean Expressions
* CLASS      : CS1A
* SECTION    : TTH: 8am
* DUE DATE   : 5/07/19
******************************************************************************/

#include "header.h"

char GenderErrorCheck()
{

	char gender;		//INPUT & PROCESS - local variable, User input and used
						//					in process
	bool genderInvalid; //PROCESS - boolean expression used in the processing



	/*************************************************************************
     * PROCESS - the process to find if gender inputed is valid:
     *************************************************************************/
	do
	{

		cout << "Gender:  ";	//input: user input for the character gender
		cin.get(gender);
		cin.ignore(100,'\n');

		genderInvalid = gender != 'm' && gender != 'M' && gender !=
						'f' && gender != 'F' && gender != 'x' && gender != 'X';

		if (genderInvalid)
		{
			cout << "*****Invalid gender; please enter M or F*****"<< endl;

		}


	}while(genderInvalid);	//end of do-while loop

	return gender;			// return the boolean expression to the main

}	//end of GenderErrorCheck function



