/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Assign #3  : Searching linked list
 * DUE DATE   : 6 November 2019
 ******************************************************************************/

#ifndef MYHEADER_H_
#define MYHEADER_H_

#include<iostream>   // INPUT AND OUTPUT
#include<iomanip>	 // FOR USING SETW'S
#include<string>	 // FOR USING STRINGS
#include<fstream>	 // FOR USING OUTPUT FILES
#include<limits>	 // FOR USING LIMITS
#include<ios>		 // FOR USING STREAM SIZE
#include<sstream>	 // FOR USING OSTRINGSETREAM
#include"ClassHeader.h"
using namespace std;



/********************************************************************
* PrintHeader
* This function outputs a header including the lab name, lab number,
* the programmer's name, the class name, assignment type, and the
* section time outputs header.
*******************************************************************/
void PrintHeader(ostream &output, //IN & OUT - output file
				 string labName,  //OUT - name of lab
				 int labNumber,   //OUT - number of lab
				 char labType);   //OUT - type of lab




#endif /* MYHEADER_H_ */
