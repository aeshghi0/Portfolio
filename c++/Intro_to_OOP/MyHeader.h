/*******************************************************************************
 * PROGRAMMER : Ali Eshghi & Amirarsalan Valipour
 * STUDENT ID : 1112261 & 1103126
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Assign #2  : tic-tac-toe game (multi-dimensional arrays)
 * DUE DATE   : 19 September 2019
 ******************************************************************************/

#ifndef MYHEADER_H_
#define MYHEADER_H_

#include <iostream>		 //input and output
#include <iomanip>		 //setting the fraction
#include <string>		 //using the string
#include <fstream>		 //using input and output file
#include <sstream>		 //using ostringstream
#include "ClassHeader.h" //using theheader that contains the class
using namespace std;

/******************************************************************************
 * PrintHeader
 * 		This function outputs the header into the screen.
 *****************************************************************************/
void PrintHeader(const string MY_NAME, //OUT
		   const string CLASS,		   //OUT
		   const string CLASS_TIME,	   //OUT
		   const int    LAB_NUM,	   //OUT
		   const string LAB_NAME);     //OUT

/*******************************************************************************
 * FirstMenu
 *    This function gets the user choice for the first menu that has been run
 *
 *    RETURNS: integer
 ******************************************************************************/
int FirstMenu();

/*******************************************************************************
 * Menu
 * This function outputs the main menu and gets the user's choice for the menu
 * options
 *
 * RETURNS: ineger
 ******************************************************************************/
int Menu();

/*******************************************************************************
 * ChangeAge
 * This function asks the user for the new age that the user wants to change
 *
 * RETURNS: integer
 ******************************************************************************/
int ChangeAge();

/*******************************************************************************
 * ChangeAge
 * This function asks the user for the new value that the user wants to change
 *
 * RETURNS: float
 ******************************************************************************/
float ChangeValue();


#endif /* MYHEADER_H_ */
