/******************************************************************************
 * PROGRAMMER : Amirarsalan Valipour & Elsa Micklin
 * STUDENT ID : 1103126 & Elsa Micklin
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * LAB #2     : Coin Flip
 * DUE DATE   : 29 August 2019
 *****************************************************************************/

#include "Header.h"

int main()
{
	/**************************************************************************
	* CONSTANTS
	* ------------------------------------------------------------------------
	* OUTPUT - USED FOR CLASS HEADING
	* ------------------------------------------------------------------------
	* PROGRAMMER  : Programmer's Name
	* CLASS	   	  : Student's Course
	* SECTION	  : Class Days and Time
	* LAB_NUM	  : Lab Number (specific to this lab)
	* LAB_NAME    : Title of the Lab
	*************************************************************************/

	const char PROGRAMMER[]	= "Amirarsalan Valipour & Elsa Micklin";
	const char CLASS[]		= "CS1B";
	const char SECTION[]	= "MW: 7:30p - 9:50p";
	const int  LAB_NUM		= 2;
	const char LAB_NAME[]	= "Coin Flip";




	/*************
	 * VARIABLES *
	 *************/

	string name;      //IN&OUT 		-  name of user
	char   gender;    //IN&CALC 	- gender of user

	int    totFlips;  //IN&CALC&OUT - total number of flips
	int    heads;     //CALC&CALC   - total number of heads flipped
	int    headRow;   //CALC&CALC   - number of heads flipped in a row
	bool   flipHeads; //CALC&CALC   - flip result, heads true, tails false
	float  percHeads; //CALC&OUT    - percentage of heads out of all flips

	/**************************************************************************
	 * OUTPUT - Class Heading
	 *************************************************************************/

	cout << left;
	cout << "***************************************************\n";
	cout << "*  PROGRAMMED BY : "	<< PROGRAMMER  << endl;
	cout << "*  "		<< setw(14) << "CLASS"	   << ": " << CLASS	    << endl;
	cout << "*  "		<< setw(14) << "SECTION"   << ": " << SECTION   << endl;
	cout << "*  LAB #"	<< setw(9)  << LAB_NUM   << ": "   << LAB_NAME	<< endl;
	cout << "***************************************************\n\n";
	cout << right;

	/******************
	 * INITIALIZATION *
	 ******************/

	totFlips = 0;
	heads = 0;
	headRow = 0;

	srand(time(NULL));

	/*************************************************************************
	 * INPUT - Prompt user for name and gender, read into variables.
	 *************************************************************************/

	cout << "Welcome to coin toss! Get 3 heads in a row to win!\n\n";

	GetName(name, gender);

	cout << endl << "Try to get 3 heads in a row. Good luck ";

	if(gender == 'M')
	{
		cout << "Mr. " << name << "!" << endl << endl;
	}
	else
	{
		cout << "Ms. " << name << "!" << endl << endl;
	}

	/*************************************************************************
	 * PROCESSING - flip coin until 3 heads in a row (headRow = 3)
	 *************************************************************************/

	while(headRow != 3)
	{
		totFlips++;

		flipHeads = FlipCoin();

		if(flipHeads)
		{
			headRow++;
			heads++;
			cout << "HEAD\n";
		}
		else
		{
			headRow = 0;
			cout << "TAIL\n";
		}

	}//end while loop

	/*************************************************************************
	 * PROCESSING - Calculate average
	 *************************************************************************/

	percHeads = Average(heads, totFlips);

	/*************************************************************************
	 * OUTPUT - Output percent average and total plays
	 *************************************************************************/

	Output(totFlips, percHeads);

	return 0;


}//end program! (woo!)





