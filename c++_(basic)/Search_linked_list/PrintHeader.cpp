/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Assign #3  : Searching linked list
 * DUE DATE   : 6 November 2019
 ******************************************************************************/
#include "myHeader.h"

/********************************************************************
* FUNCTION PrintHeader
* __________________________________________________________________
*
* This function outputs a header including the lab name, lab number,
* the programmer's name, the class name, and the section time
* as a string by ostream
* __________________________________________________________________
* PRE-CONDITIONS:
* output - ostream variable to dynamically choose datatype
* of cout or ofstream
* labName - Name of the lab. The labName should be previously
* defined
* labNumber - Number of the lab. The labNumber should be
* previously defined
* labType - type of assignment
* 'A' - assignment
* 'L' - lab
*
* POST-CONDITIONS:
* outputs header as string
*******************************************************************/

void PrintHeader(ostream &output, //IN & OUT - output file
				 string labName,  //OUT - name of lab
				 int labNumber,   //OUT - number of lab
				 char labType)    //OUT - type of lab
{
	//Defining and initializing constant variables
	const char PROGRAMMER[30] = "Ali Eshghi";
	const char CLASS[5] = "CS1B";
	const char SECTION[20] = "MW: 7:30p - 9:50p";

	// OUTPUT - Class Heading
	output << left;
	output << endl;
	output << "********************************************************";
	output << "\n* PROGRAMMED BY : " << PROGRAMMER;
	output << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	output << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	output << "\n* ";
	if (toupper(labType) == 'L')
	{
		output << "LAB #" << setw(8);
	}
	else
	{
		output << "ASSIGNMENT #" << setw(1);
	}
	output << labNumber << " : " << labName;
	output << "\n******************************************************";
	output << "**\n\n";
	output << right;
}
