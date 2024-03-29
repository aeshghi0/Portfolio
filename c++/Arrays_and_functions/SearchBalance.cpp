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
 * Function : SearchBalance
 * ---------------------------------------------------------------------------
 * This function searches for the largest or smaller balance in the balance
 * array using a for loop and then returns an integer type variable as the
 * index of the  larger balance in the array to an integer type variable in
 * the main named "balanceIndex".
 *****************************************************************************/

int SearchBalance(float balanceAr[],
				  int option,
				  const int AR_SIZE)
{
	/*************
	 * VARIABLES *
	 ************/

	int		balanceIndex; // PROCESS - Adjusts to the index of the larger balance
	int		index;		  // PROCESS - Used in the for loop for the initial, check
						  //		   and change in the loop.

	//Initializing this to 0, to be changed later.
	balanceIndex = 0;

	//If statement used if the user chooses the option 1.
	if(option == 1)
	{
		//For loop to search the largest balance between the
		//elements of the array, checking index by index.
		for (index = 0; index < AR_SIZE; index++)
		{
			//If statement to change the integer as the the
			//index for the larger balance if the balance of the
			//next element is higher.
			if (balanceAr[index] > balanceAr[balanceIndex])
			{
				balanceIndex = index;
			}//End of if statement.


		}//End of the for loop.

	}//End of the if statement.

	//If statement used if the user chooses the option 2.
	else if(option == 2)
	{
		//For loop to search the smaller balance between the
		//elements of the array, checking index by index.
		for (index = 1; index <= AR_SIZE; index++)
		{
			//If statement to change the integer as the the
			//index for the larger balance if the balance of the
			//next element is higher.
			if (balanceAr[index] < balanceAr[balanceIndex])
			{
				balanceIndex = index;
			}//End of if statement.


		}//End of for loop.

	}//End of if statement.



	//Returns the index integer to the main.
	return balanceIndex;
}


