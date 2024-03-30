/******************************************************************************
 * PROGRAMMER : Ali Eshghi & Elsa Micklnin
 * STUDENT ID : 1112261    & 1028119
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * LAB #3     : Functions and arrays
 * DUE DATE   : 10 September 2019
 *****************************************************************************/

#include "header.h"

/******************************************************************************
 * Function : PrintHeaderScreen
 * ---------------------------------------------------------------------------
 * This function will turn the class heading into a string and return to main.
 *****************************************************************************/

string PrintHeaderScreen(string	   asName,
						 char 	   asType,
						 int	   asNum,
						 string	   asClass,
						 string    asSection)

{
	ostringstream output; //PROCESS - holds the class header as a string

	/******************************************************************************
	 * PROCESS - turns class heading into a string
	 *****************************************************************************/

	output << left;
	output << "***************************************************\n"        ;
	output << "*  PROGRAMMED BY : Ali Eshghi & Elsa Micklin	   "             ;
	output << "\n*  "		<< setw(14) << "CLASS"	   << ": " << asClass    ;
	output << "\n*  "		<< setw(14) << "SECTION"   << ": " << asSection  ;
	output << "\n*  LAB #"	<< setw(9)  << asNum       << ": " << asName     ;
	output << "\n***************************************************\n\n"    ;
	output << right;


	//return string
	return output.str();


}



