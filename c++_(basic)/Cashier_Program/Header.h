/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1C
 * SECTION    : MW 5pm
 * Assign #1  : Deck of cards
 * DUE DATE   : 22 January 2020
 ******************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_


//Preprocessor directives
#include<iostream>		//For input, output
#include<iomanip>		//For style
#include<string>		//For using string
using namespace std;	//using namespace standard

#define SIZE 5			//defining the constant SIZE = 5


//using #ifndef and #endif to define a structure
#ifndef INVENTORY
#define INVENTORY

//definition of inventory structure
typedef struct inventory
{
	/***************
	 *  VARIABLES  *
	 ***************/

	string 	eqpName;  //PROCESS & OUT - storing the name
	double 	price;	  //PROCESS & OUT - storing the price
	int		quantity; //PROCESS & OUT - storing the quantity
}inventory;

#endif

/***********************************************************
 * Function - display
 ***********************************************************
 * This function just prints out the pointer variable's
 * value to the screen based on a for loop
 *
 * Return type - nothing
 * void type function
 ***********************************************************/
void display(inventory *inv);


#endif /* HEADER_H_ */
