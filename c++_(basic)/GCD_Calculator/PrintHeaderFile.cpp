/******************************************************************************
* AUTHOR     : Amirarsalan Valipour & Ali Eshghi
* STUDENT ID : 1103126 - 1112261
* LAB #10    : Creating an Ordered List
* CLASS      : CS 1B
* SECTION    : MW - 7:30 pm
* DUE DATE   : 11/05/2019
*******************************************************************************/

#include "MyHeader.h"


/******************************************************************************
 * Function : PrintHeaderFile
 * ---------------------------------------------------------------------------
 * This function will output the class heading to the scree.
 *****************************************************************************/

void PrintHeaderFile(string	   asName,
					 char 	   asType,
					 int	   asNum,
					 string	   asClass,
					 string    asSection)
{

	/******************************************************************************
	 * OUTPUT - outputs class heading to file and then console.
	 *****************************************************************************/

	cout << left;
	cout << "***************************************************\n"         ;
	cout << "*  PROGRAMMED BY : Ali Eshghi & Elsa Micklin	   "         ;
	cout << "\n*  "		<< setw(14) << "CLASS"	   << ": " << asClass    ;
	cout << "\n*  "		<< setw(14) << "SECTION"   << ": " << asSection  ;
	cout << "\n*  LAB #"	<< setw(9)  << asNum       << ": " << asName     ;
	cout << "\n***************************************************\n\n"     ;
	cout << right;

}

