/******************************************************************************
* AUTHOR     : Amirarsalan Valipour & Ali Eshghi
* STUDENT ID : 1103126 - 1112261
* LAB #10    : Creating an Ordered List
* CLASS      : CS 1B
* SECTION    : MW - 7:30 pm
* DUE DATE   : 11/05/2019
*******************************************************************************/

#include "MyHeader.h"


/*******************************************************************************
 * Function : PrintHeaderFile
 * ---------------------------------------------------------------------------
 * This function will output the class heading to the screen.
 ******************************************************************************/

void PrintHeaderFile()
{

	/***************************************************************************
	 * OUTPUT - outputs class heading to file and then console.
	 **************************************************************************/

	cout << left;
	cout << "******************************************************\n"     ;
	cout << "*  PROGRAMMED BY : Ali Eshghi & Amirarsalan Valipour	   "   ;
	cout << "\n*  "		<< setw(14) << "CLASS"	   << ": " << CLASS        ;
	cout << "\n*  "		<< setw(14) << "SECTION"   << ": " << SECTION      ;
	cout << "\n*  LAB #"	<< setw(9)  << NUM     << ": " << NAME       ;
	cout << "\n******************************************************\n\n" ;
	cout << right;

}

