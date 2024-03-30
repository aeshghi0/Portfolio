/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Assign #2  : tic-tac-toe game (multi-dimensional arrays)
 * DUE DATE   : 19 September 2019
 ******************************************************************************/
#include "MyHeader.h"

/*******************************************************************************
 * Function - PrintHeaderFile
 * ---------------------------------------------------------------------------
 * This function will output the class heading to the screen.
 *
 * return type - nothing
 * 				 the function is void type
 ******************************************************************************/

void PrintHeader(const string MY_NAME, //OUT
		   const string CLASS,		   //OUT
		   const string CLASS_TIME,	   //OUT
		   const int    ASSIGN_NUM,	   //OUT
		   const string ASSIGN_NAME)   //OUT
{
	cout << left;
	cout << "***************************************************\n"       ;
	cout << "*  PROGRAMMED BY : "    << MY_NAME  				     ;
	cout << "\n*  "		<< setw(14) << "CLASS"	   << ": " << CLASS      ;
	cout << "\n*  "		<< setw(14) << "SECTION"   << ": " << CLASS_TIME ;
	cout << "\n*  LAB #"	<< setw(9)  << ASSIGN_NUM  << ": " << ASSIGN_NAME;
	cout << "\n***************************************************\n\n"   ;
	cout << right;
}

