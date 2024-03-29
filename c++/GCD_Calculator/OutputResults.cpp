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
 * Function : Output Results
 * ---------------------------------------------------------------------------
 * This function will read in results from main and convert to a string.
 *****************************************************************************/

string OutputResults(int n1, int n2, int greatestDivisor)
{
	ostringstream output; // PROCESS - stores the string of output

	output << "The GCD for " << n1 << " & " << n2 << " = " << greatestDivisor;

	//returns the string of result
	return output.str();

}
