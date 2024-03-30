
/******************************************************************************
* AUTHOR     : Ali Eshghi
* STUDENT IDs: 1112261
* AS #6	     : Assignment 6 - Loop & Boolean Expressions
* CLASS      : CS1A
* SECTION    : TTH: 8am
* DUE DATE   : 5/07/19
******************************************************************************/

#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>		/* needed for INPUT and OUTPUT */
#include <iomanip>		/* needed for Mathematical Expressions*/
using namespace std;	/* all library entities are defined within namespace std*/


/******************************************************************************
 * Header file - This header file is made header file that is used in all of the
 * 				 functions and help the programmer to organize the functions and
 * 				 use this made header file in the functions and main.
 ******************************************************************************/

char    GenderErrorCheck();
/******************************************************************************
 * GenderErrorCheck - this function that is defined in this header file is the
 * 					  function that asks the user for the gender and get that as
 * 					  a character. after it gets the gender as a character, it
 * 					  error checks it to see if it is valid or no,
 ******************************************************************************/

bool		IsHeightValid(const int MALE_MIN_HEIGHT, const int MALE_MAX_HEIGHT,
					  const int FMALE_MIN_HEIGHT, const int FMALE_MAX_HEIGHT,
					  char gender);
/******************************************************************************
 * IsHeightValid - This function asks for the Height that is a user input and
 * 				   passes the value into an error check statement for checking
 * 				   for valid or invalid statement, then after checking it for
 * 				   being valid, it passes the height variable to a boolean
 * 				   statement for the True or False statement in a selection
 * 				   statement
 ******************************************************************************/

bool		IsWeightValid(const int MALE_MIN_WEIGHT, const int MALE_MAX_WEIGHT,
					  const int FMALE_MIN_WEIGHT, const int FMALE_MAX_WEIGHT,
					  char gender);
/******************************************************************************
 * IsWeightValid - This function asks for the Weight that is a user input and
 * 				   passes the value into an error check statement for checking
 * 				   for valid or invalid statement, then after checking it for
 * 				   being valid, it passes the weight variable to a boolean
 * 				   statement for the True or False statement in a selection
 * 				   statement
 ******************************************************************************/

#endif /* HEADER_H_ */





