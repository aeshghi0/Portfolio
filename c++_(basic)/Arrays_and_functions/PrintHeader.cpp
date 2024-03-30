/***********************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Assign #1  : Functions and arrays
 * DUE DATE   : 19 September 2019
 ***********************************************/
#include "MyHeader.h"

/******************************************************************************
 * Function : PrintHeader
 * ---------------------------------------------------------------------------
 * This function stores the header file into a string variable and returns that
 * string variable to a string variable in the main called "header"
 *****************************************************************************/

string PrintHeader(const string MY_NAME,
				   const string CLASS,
				   const string CLASS_TIME,
				   const int    ASSIGN_NUM,
				   const string ASSIGN_NAME)
{
	/*************
	 * VARIABLES *
	 ************/

	ostringstream output; //PROCESS - stores the header file as string

	//This statements stores the header file into the string type variable.
	output << left;
	output << "***************************************************\n"       ;
	output << "*  PROGRAMMED BY : "    << MY_NAME  				     ;
	output << "\n*  "		<< setw(14) << "CLASS"	   << ": " << CLASS      ;
	output << "\n*  "		<< setw(14) << "SECTION"   << ": " << CLASS_TIME ;
	output << "\n*  LAB #"	<< setw(9)  << ASSIGN_NUM  << ": " << ASSIGN_NAME;
	output << "\n***************************************************\n\n"   ;
	output << right;


	//returns the string type variable into the main
	return output.str();
}

