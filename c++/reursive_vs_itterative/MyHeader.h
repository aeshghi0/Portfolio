/************************************************************
* AUTHOR	    : Ali Eshghi
* STUDENT ID    : 1112261
* ASSIGNMENT #4	: Assessing Recursion Performance
* CLASS	        : CS 1B
* SECTION	    : MW - 7:30 pm - 9:50 pm
* DUE DATE	    : 11/26/2019
*************************************************************/

#ifndef MYHEADER_H_
#define MYHEADER_H_



#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <chrono>
#include <ctime>
using namespace std;
using namespace std::chrono;	// using namespace std::chrono

/*************
 * 	VARIABLE *
 *************/

enum MenuOption //PROCESS - used for the menu
{
	EXIT,
	FACTLOOP,
	FIBLOOP,
	FACTREC,
	FIBREC
};


/****************************************************************
 * PrintHeader
 *    This function receives receives an assignment name, type
 *     and number then outputs the appropriate header
 *
 *    returns  nothing -> This will output the class heading.
 ****************************************************************/
void PrintHeader(string asName,  // IN - assignment Name
				 char   asType,  // IN - assignment type
				 int    asNum);  // IN - assignment number


/****************************************************************
 * Menu
 *    This function will print the program menu into the console.
 *
 *    returns  nothing -> This will output the menu.
 ****************************************************************/
void Menu();


/****************************************************************
 * GetCheckInput
 *    This function will get the user's option from the menu and
 *     returns it into the main.
 *
 *    returns  nothing -> This will output the menu.
 ****************************************************************/
void GetCheckInp(int &userOption);  //IN & PROCESS - user's input


/****************************************************************
 * CheckInpFact
 *    This function gets the user's input and pass
 *     it back to the main.
 *
 *    returns  integer -> target number for fib/fact
 ****************************************************************/
int CheckInpFact(); //IN & PROCESSS - user's input

/****************************************************************
 * Fact
 *    This function will calculate the factorial of user's number.
 *
 *    returns  integer -> factorial of the target number
 ****************************************************************/
int Fact(int userInt);	//IN & PROCESS - user's input


/****************************************************************
 * SeriesFib
 *    This function will calculate the fibbonacci number of user's number
 *    input
 *
 *    returns  integer -> fibbonacci result of the target number
 ****************************************************************/
int SeriesFib(int userInp);	//IN & PROCESS - user's input

/****************************************************************
 * FactLoop
 *    This function will calculate the factorial number of user's number
 *    input using a loop
 *
 *    returns  integer -> factorial result of the target number
 ****************************************************************/
int FactLoop(int userInp);	//IN & PROCESS - user's input

/****************************************************************
 * SeriesFibLoop
 *    This function will calculate the fibbinacci result number of
 *    user's number input using a loop
 *
 *    returns  integer -> fibbonacci result of the target number
 ****************************************************************/
int SeriesFibLoop(int userInp);	//IN & PROCESS - user's input

#endif /* MYHEADER_H_ */
