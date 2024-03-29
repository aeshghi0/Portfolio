/************************************************************
* AUTHOR	    : Ali Eshghi
* STUDENT ID    : 1112261
* LAB #13		: LAB 13 - ARRAYS AND LINKED LIST (OOP)
* CLASS	        : CS 1B
* SECTION	    : MW - 7:30 pm - 9:50 pm
* DUE DATE	    : 12/3/2019
*************************************************************/

#include "MyHeader.h"

/************************************************************
 * Function - PrintHeaderFile
 * ----------------------------------------------------------
 * This function will output the class heading to the screen.
 *
 * return type - nothing
 * 				 the function is void type
 ************************************************************/

void PrintHeader()
{
	cout << left;
	cout << "***************************************************\n"       ;
	cout << "*  PROGRAMMED BY : ALI ESHGHI & JULIAN LASTING" 		      ;
	cout << "\n*  "		<< setw(14) << "CLASS"	   << ": " << CLASS       ;
	cout << "\n*  "		<< setw(14) << "SECTION"   << ": " << SECTION     ;
	cout << "\n*  LAB #"	<< setw(9)  << NUM  << ": " << NAME           ;
	cout << "\n***************************************************\n\n"   ;
	cout << right;
}

