/*****************************************************************************
 * PROGRAMMER : Ali Eshghi & Amirarsalan Valipour
 * STUDENT ID : 1112261 / 1103126
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Lab #5     : Binary Search
 * DUE DATE   : 24 September 2019
 *****************************************************************************
 * BINARY SEARCH
 * ---------------------------------------------------------------------------
 * In this program we will assign an array and will do the following through
 * 	different functions: SORTING, BINARY SEARCH, SEQUENTIAL SEARCH, OUTPUT
 *****************************************************************************/

#include "MyHeader.h"

int main()
{
	/*************************************************************************
	 * CONSTANTS
     * -----------------------------------------------------------------------
	 * OUTPUT - USED FOR CLASS HEADING
	 * -----------------------------------------------------------------------
	 * PROGRAMMER  : Programmer's Name
	 * CLASS	   : Student's Course
	 * SECTION	   : Class Days and Time
	 * LAB_NUM	   : Lab Number (specific to this lab)
	 * LAB_NAME    : Title of the Assignment
	 *************************************************************************/

	const string PROGRAMMER	= "Ali Eshghi & Amirarsalan Valipour";
	const string CLASS		= "CS1B";
	const string SECTION	= "MW: 7:30p - 9:50p";
	const int    LAB_NUM	=  5;
	const string LAB_NAME= "Finary Search";

	/*************************************************************************
	 * OUTPUT - HEADER
	 *************************************************************************/

	PrintHeader(PROGRAMMER, CLASS, SECTION, LAB_NUM, LAB_NAME);

	/*************************************************************************
	 * CONSTANTS
	 * -----------------------------------------------------------------------
	 * ESSENTIAL CONSTANTS
	 * -----------------------------------------------------------------------
	 * AR_SIZE    : Used for the size of array
	 *************************************************************************/

	const int AR_SIZE = 8;

	/*************************************************************************
	 * VARIABLES
	 *************************************************************************/

	int numAr[AR_SIZE]= {4,1,7,12,8,13,9,21}; // Calc & Out - given array

	int i;					// Calc - index for the for loop
	int seqIndex;			// Calc - index for the sequential search
	int binSearch;			// Calc - index for binary search
	int searchNum;			// In, Calc & Out - User's choice of number

	/*************************************************************************
	 * OUTPUT ARRAY
	 *************************************************************************/

	ArrayOutput(numAr, AR_SIZE);

	/*************************************************************************
	 * INPUT / PROCESSING
	 *************************************************************************/

	//FOR loop runs 4 times and asks user to input the number they want to
	//search for

	for(i = 1; i <= 4; i++)
	{
		//asks for users number of choice

		cout << "Enter an integer to search for: ";
		cin  >> searchNum;

		//Search for the number through this function
		seqIndex = ArraySequentialSearch(numAr, AR_SIZE, searchNum);

		//OUTPUT
		if(seqIndex != -1)
		{
			cout << "The integer " << searchNum
				 << " was found in index #"
				 << seqIndex  << "."
				 << endl << endl;
		} //END - IF

		else
		{
			cout << searchNum << " was not found!"
				 << endl << endl;
		} //END - ELSE

	} //END - FOR

	cout << "Performing Insertion sort" << endl << endl;

	//Sorts Array
	ArraySort(numAr, AR_SIZE);

	//Outputs Array
	ArrayOutput(numAr, AR_SIZE);

	//FOR loop runs 4 times and asks user to input the number they want to
	//search for

	for(i = 1; i <= 4; i++)
	{
		//asks for users number of choice
		cout << "Enter an integer to search for: ";
		cin  >> searchNum;

		//Search for the number through this function
		binSearch = ArrayBinarySearch(numAr, AR_SIZE, searchNum);

		//OUTPUT
		if(binSearch != -1)
		{
			cout << "The integer " << searchNum
				 << " was found in index #"
				 << binSearch  << "."
				 << endl << endl;
		} //END - IF

		else
		{
			cout << searchNum << " was not found!"
				 << endl << endl;
		} //END - ELSE

	} //END - FOR

	return 0;
}




