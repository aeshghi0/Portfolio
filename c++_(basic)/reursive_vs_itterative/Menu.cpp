/************************************************************
* AUTHOR	    : Ali Eshghi
* STUDENT ID    : 1112261
* ASSIGNMENT #4	: Assessing Recursion Performance
* CLASS	        : CS 1B
* SECTION	    : MW - 7:30 pm - 9:50 pm
* DUE DATE	    : 11/26/2019
*************************************************************/

#include "MyHeader.h"

/****************************************************************
 * Menu
 *    This function will print the program menu into the console.
 *
 *    returns  nothing -> This will output the menu.
 ****************************************************************/

void Menu()
{

	cout << endl << endl;
	cout << left;
	cout << "MENU OPTIONS\n\n";
	cout << "1 – Calculate and Display Factorial of a Number\n";
	cout << "2 – Calculate and Display Fibonacci Series of a Number\n";
	cout << "3 – Compare Performance for Factorial Implementations\n";
	cout << "4 – Compare Performance for Fibonacci Series Implementations\n";
	cout << "0 -EXIT\n";
	cout << right;

}
