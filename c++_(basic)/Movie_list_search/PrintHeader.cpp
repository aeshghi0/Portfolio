/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Assign #3  : Searching linked list
 * DUE DATE   : 6 November 2019
 ******************************************************************************/

#include "MyHeader.h"

/*******************************************************************************
 * Function - PrintHeaderFile
 * ---------------------------------------------------------------------------
 * This function will output the class heading to the screen and output file
 *
 * return type - nothing
 * 				 the function is void type
 ******************************************************************************/

void PrintHeader(const string MY_NAME,    //OUT
		   	   	 const string CLASS,	  //OUT
				 const string CLASS_TIME, //OUT
				 const int    ASSIGN_NUM, //OUT
				 const string ASSIGN_NAME,//OUT
				 ofstream     &outFile)    //OUT
{
	cout << left;
	cout << "***************************************************\n"       ;
	cout << "*  PROGRAMMED BY : "    << MY_NAME  				     ;
	cout << "\n*  "		<< setw(14) << "CLASS"	   << ": " << CLASS      ;
	cout << "\n*  "		<< setw(14) << "SECTION"   << ": " << CLASS_TIME ;
	cout << "\n*  LAB #"	<< setw(9)  << ASSIGN_NUM  << ": " << ASSIGN_NAME;
	cout << "\n***************************************************\n\n"   ;
	cout << right;


	outFile << left;
	outFile << "***************************************************\n"       ;
	outFile << "*  PROGRAMMED BY : "    << MY_NAME  				     ;
	outFile << "\n*  "		<< setw(14) << "CLASS"	   << ": " << CLASS      ;
	outFile << "\n*  "		<< setw(14) << "SECTION"   << ": " << CLASS_TIME ;
	outFile << "\n*  LAB #"	<< setw(9)  << ASSIGN_NUM  << ": " << ASSIGN_NAME;
	outFile << "\n***************************************************\n\n"   ;
	outFile << right;
}

