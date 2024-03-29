/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1C
 * SECTION    : MW 5pm
 * Assign #1  : Deck of cards
 * DUE DATE   : 22 January 2020
 ******************************************************************************/

#include"Header.h"

/***********************************************************
 * Function - display
 ***********************************************************
 * This function just prints out the pointer variable's
 * value to the screen based on a for loop
 *
 * Return type - nothing
 * void type function
 ***********************************************************/

void display(inventory *inv)
{
	cout << "Name of equipment\tCost\tQuantity" << endl;

	//for loop for printing the items one by one
	for(int i = 0; i < SIZE; i++)
	{
		cout << inv[i].eqpName << "\t";
		cout << "$" << inv[i].price << "\t";
		cout << inv[i].quantity << endl;
	}
}

