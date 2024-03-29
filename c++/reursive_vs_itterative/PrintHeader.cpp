/************************************************************
* AUTHOR	    : Ali Eshghi
* STUDENT ID    : 1112261
* ASSIGNMENT #4	: Assessing Recursion Performance
* CLASS	        : CS 1B
* SECTION	    : MW - 7:30 pm - 9:50 pm
* DUE DATE	    : 11/26/2019
*************************************************************/

#include "MyHeader.h"

/****************************************************************
 * PrintHeader
 *    This function receives receives an assignment name, type
 *     and number then outputs the appropriate header
 *
 *    returns  nothing -> This will output the class heading.
 ****************************************************************/

void PrintHeader(string asName,  // IN - assignment Name
				 char   asType,  // IN - assignment type
				 int    asNum)   // IN - assignment number
{

	cout << left;
	cout << "**************************************************\n";
	cout << "*  Programmer : Ali Eshghi\n";
	cout << "*  " << setw(14) << "STUDENT ID" << ": 1112261\n";
	cout << "*  " << setw(14) << "CLASS"      << ": MW - 7:30-9:50\n";
	cout << "*  ";

	if (toupper(asType) == 'L')
	{
		cout << "LAB #" << setw(9);
	}

	else
	{
		cout << "ASSIGNMENT #" << setw(2);
	}

	cout << asNum << ": " << asName << endl;
	cout << "**************************************************\n\n";
	cout << right;

}


