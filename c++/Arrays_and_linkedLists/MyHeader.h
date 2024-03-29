/************************************************************
* AUTHOR	    : Ali Eshghi
* STUDENT ID    : 1112261
* LAB #13		: LAB 13 - ARRAYS AND LINKED LIST (OOP)
* CLASS	        : CS 1B
* SECTION	    : MW - 7:30 pm - 9:50 pm
* DUE DATE	    : 12/3/2019
*************************************************************/

#ifndef MYHEADER_H_
#define MYHEADER_H_

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<limits>
#include<sstream>
#include "ClassHeader.h"
using namespace std;

/********************************************************
* CONSTANTS
* ----------------------------------------------------
* USED FOR CLASS HEADING – ALL WILL BE OUTPUT
* ----------------------------------------------------
* Type	   : Program Type
* LAB_NUM  : Lab Number (specific to this lab)
* LAB_NAME : Title of the Lab
*********************************************************/

const string NAME = "LAB 13 - ARRAYS AND LINKED LIST (OOP)";
const char   TYPE    = 'L';
const int    NUM     = 13 ;
const string CLASS   = "CS1B";
const string SECTION = "MW: 7:30p - 9:50p";

/************************************************************
 * Function - PrintHeaderFile
 * ----------------------------------------------------------
 * This function will output the class heading to the screen.
 *
 * return type - nothing
 * 				 the function is void type
 ************************************************************/
void PrintHeader();

/************************************************************
 * Function - Menu
 * ----------------------------------------------------------
 * This function will outputs the menu and prompts the user
 * to choose an option from the menu
 *
 * return type - integer
 * 				 the function is int type
 ************************************************************/
int Menu();

#endif /* MYHEADER_H_ */
