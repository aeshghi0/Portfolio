/******************************************************************************
* AUTHOR     : Ali Eshghi
* STUDENT IDs: 1112261
* AS #6	     : Assignment 6 - Loop & Boolean Expressions
* CLASS      : CS1A
* SECTION    : TTH: 8am
* DUE DATE   : 5/07/19
******************************************************************************/

#include"header.h"


bool IsHeightValid( int MALE_MIN_HEIGHT, int MALE_MAX_HEIGHT,
		  	  	    int FMALE_MIN_HEIGHT, int FMALE_MAX_HEIGHT,
				    char gender)
{
	bool	heightInvalid;		// PROCESS - used as a boolean expression in process
	bool	acceptableHeight;	// PROCESS - a boolean expression that is used in process of return
	int		height;				// INPUT & PROCESS - user input and used in process


	/*************************************************************************
	 * PROCESS - the process to find if height inputed is valid:
	 *************************************************************************/
	do
	{
		cout << "Height:  ";	//height - user input
		cin  >> height;

		heightInvalid = height < 24 || height > 110;

		if(heightInvalid)
		{
			cout << "*****Invalid height, please enter a"
					" height in inches between 24 and 110*****"
					<< endl;
		}//end of if-statement

	}while(heightInvalid);	//end of do-while loop

	acceptableHeight = ((gender == 'm' || gender == 'M')
	      			   && (height >= MALE_MIN_HEIGHT && height <= MALE_MAX_HEIGHT))
	      		       ||((gender == 'f' || gender == 'F')
	      		       &&(height >= FMALE_MIN_HEIGHT && height <= FMALE_MAX_HEIGHT));
	//boolean expression that detemines return true or false

	return acceptableHeight;	//returns the boolean expression
}



