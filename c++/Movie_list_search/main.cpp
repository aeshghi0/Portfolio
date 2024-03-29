/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Assign #3  : Searching linked list
 * DUE DATE   : 6 November 2019
 ******************************************************************************/

#include "MyHeader.h"

/*******************************************************************************
* Assignment 3
* ------------------------------------------------------------------------------
* Write a program that allows a user to track/search their DVDs.  Use an input
* file, which includes the following attributes for each movie:
* -Title
* -Leading actor/actress
* -Supporting Actor
* -Genre
* -Alternate Genre
* -Year
* -Rating
* -Synopsis
* ------------------------------------------------------------------------------
* INPUT  : option         -> Menu option for which action
* 		   node.title     -> Which title the user is searching
* 		   node.leadAcotr -> Which actor the user is searching
* 		   node.genre     -> Which genre the user is searching
* 		   node.year      -> Which year the user is searching
* 		   node.rate	  -> Which rating the user is searching
* ------------------------------------------------------------------------------
* PROCESS: Creating the linked list of the DVD's nodes with the named contents
* 		   Searching for the title between the title content of nodes
* 		   Searching for the acotr's name between the actors' content of nodes
* 		   searching for the genre between the genre content of nodes
* 		   searching for the year between the year content of nodes
* 		   searching for the rating between the rate content of nodes
* ------------------------------------------------------------------------------
* OUTPUT : every content of the node found based on the title search
* 		   every content of every nodes found based on the actor's search
* 		   every content of every nodes found based on the genre search
* 		   every content of every nodes found based on the year search
* 		   every content of every nodes found based on the rating search
*******************************************************************************/


int main()
{

	/***************************************************************************
	* CONSTANTS
	* --------------------------------------------------------------------------
	* OUTPUT - USED FOR CLASS HEADING
	* --------------------------------------------------------------------------
	* PROGRAMMER  : Programmer's Name
	* CLASS	   	  : Student's Course
	* SECTION	  : Class Days and Time
	* LAB_NUM	  : Lab Number (specific to this lab)
	* LAB_NAME    : Title of the Assignment
	***************************************************************************/
	const string PROGRAMMER	= "Ali Eshghi";
	const string CLASS		= "CS1B";
	const string SECTION	= "MW: 7:30p - 9:50p";
	const int    ASSIGN_NUM	= 3;
	const string ASSIGN_NAME= "Searching Linked list";



	/*************
	 * VARIABLES *
	 ************/

	ofstream 	outFile;	// OUT - Program outputs here
	int  		menuOption; // IN & PROCESS - menu option input by user
	MovieNode 	*head;		// PROCESS - the linked list

	/****************
	 * INITIALIZING *
	 ****************/

	head = NULL;	//creating an empty list

	outFile.open("outFile.txt"); //opening the output file

	//This function will output the header file
	PrintHeader(PROGRAMMER, CLASS, SECTION, ASSIGN_NUM, ASSIGN_NAME, outFile);

	//This function gets the data from the input file and put them in the
	//content of the nodes and add them to the list
	CreatList(head);

	//This function prints the menu and gets the option from the user.
	menuOption = PrintMenu();


	//while loop for continuing the program for the searches until the user
	//determines to terminate it
	while (menuOption != 0)
		{
			//if statement for the 1st option
			if (menuOption == 1)
			{
				cout << endl;
				DisplayList(head, outFile);
			}

			//if statement for the 2nd option
			else if (menuOption == 2)
			{
				SearchTitle(head, outFile);
			}

			//if statement for the 3rd option
			else if (menuOption == 3)
			{

				SearchGenre(head, outFile);
			}

			//if statement for the 4th option
			else if (menuOption == 4)
			{

				SearchActor(head, outFile);
			}

			//if statement for the 5th option
			else if (menuOption == 5)
			{

				SearchYear(head, outFile);

			}

			//if statement for the 6th option
			else if (menuOption == 6)
			{

				SearchRate(head, outFile);
			}

			//This function prints the menu and gets the option from the user.
			menuOption = PrintMenu();

		}// END of while loop



	outFile.close(); //closing the output file


	return 0;

}
