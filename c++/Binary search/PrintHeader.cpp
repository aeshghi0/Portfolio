/*****************************************************************************
 * PROGRAMMER : Ali Eshghi & Amirarsalan Valipour
 * STUDENT ID : 1112261 / 1103126
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Lab #5     : Binary Search
 * DUE DATE   : 24 September 2019
 *****************************************************************************
 * Function : PrintHeader
 * ---------------------------------------------------------------------------
 * This function will print the program header onto the console.
 *****************************************************************************/

#include "MyHeader.h"

void PrintHeader ( const string MY_NAME,
				   const string CLASS,
				   const string CLASS_TIME,
				   const int    ASSIGN_NUM,
				   const string ASSIGN_NAME )
{

	cout  << left;
	cout  << "******************************************************\n"      ;
	cout  << "*  PROGRAMMED BY : "    << MY_NAME  				   		     ;
	cout  << "\n*  "		<< setw(14) << "CLASS"	   << ": " << CLASS      ;
	cout  << "\n*  "		<< setw(14) << "SECTION"   << ": " << CLASS_TIME ;
	cout  << "\n*  LAB #"	<< setw(9)  << ASSIGN_NUM  << ": " << ASSIGN_NAME;
	cout  << "\n******************************************************\n\n"  ;
	cout  << right;

}

