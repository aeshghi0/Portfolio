/******************************************************************************
* AUTHOR     : Ali Eshghi
* STUDENT IDs: 1112261
* AS #6	     : Assignment 6 - Loop & Boolean Expressions
* CLASS      : CS1A
* SECTION    : TTH: 8am
* DUE DATE   : 5/07/19
******************************************************************************/

#include"header.h"


bool IsWeightValid(int MALE_MIN_WEIGHT, int MALE_MAX_WEIGHT,
				   int FMALE_MIN_WEIGHT, int FMALE_MAX_WEIGHT,
				  char gender)
{
	int 	weight;				// INPUT & PROCESS - user input and used in process
	bool	acceptableWeight;	// PROCESS - a boolean expression that is used in process of return
	bool	invalidWeight;		// PROCESS - used as a boolean expression in process

	/*************************************************************************
	 * PROCESS - the process to find if weight inputed is valid:
	 *************************************************************************/
	do
	{
		cout << "Weight:  ";	//weight - user input
		cin  >> weight;
		cin.ignore(1000,'\n');

		invalidWeight = weight <= 50 || weight >= 1400;

		if (invalidWeight)
		{
			cout << "*****Invalid weight, please enter a weight in"
					" lb between 50 and 1400.*****" << endl;
		}//end of if-statement

	}while(invalidWeight);	//end of do-while loop

	acceptableWeight = ((gender == 'm' || gender == 'M')
	    			&& (weight >= MALE_MIN_WEIGHT && weight <= MALE_MAX_WEIGHT))
	    			|| ((gender == 'f' || gender == 'F')
	    			&& (weight >= FMALE_MIN_WEIGHT && weight <= FMALE_MAX_WEIGHT));
	//boolean expression that detemines return true or false

	return acceptableWeight;	//returns the boolean expression

}



