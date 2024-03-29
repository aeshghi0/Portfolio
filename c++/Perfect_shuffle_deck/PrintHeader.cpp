/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1C
 * SECTION    : MW 5pm
 * Assign #1  : Deck of cards
 * DUE DATE   : 22 January 2020
 ******************************************************************************/

#include"Header.h"

void PrintHeader (string asName, // In - assignment Name
				  int asNum)     // In - assignment number
{
	char asType = 'A';

	//OUTPUT - Console

	cout << left;

	cout << "**************************************************\n";
	cout << "* PROGRAMMED BY : Ali Eshghi" << endl;
	cout << "* " << setw(14) << "STUDENT ID" << ": 1112261" << endl;
	cout << "* " << setw(14) << "CLASS" << ": CS1B - MW - 7pm"<<
			endl;
	cout << "* ";

	// PROCESSING - This will adjust setws and format appropriately
	// based on if this is a lab 'L' or assignment.


	if (asType == 'L')
	{
		cout << "LAB #:" << setw(9);
	}

	else
	{
		cout << "ASSIGNMENT #" << setw(2);
	}

	cout << asNum << ": " << asName << endl;
	cout <<
			"**************************************************\n\n";
	cout << right;

	}


