/******************************************************************************
* AUTHOR     : Amirarsalan Valipour & Ali Eshghi
* STUDENT ID : 1103126 - 1112261
* LAB #10    : Creating an Ordered List
* CLASS      : CS 1B
* SECTION    : MW - 7:30 pm
* DUE DATE   : 11/05/2019
*******************************************************************************/


#include "MyHeader.h"

/*******************************************************************************
* LAB 10
* ------------------------------------------------------------------------------
* This program gets an integer as an option from the user based in the printed
* menu. the first option gets the data from an input file and put the data into
* the content of nodes and add them to an empty list that has been created in
* main. the second option displays the list that has been created in the
* first option of the menu on the screen. the second option runs a function that
* determines that the list created or modified by the user is empty or no, and
* it outputs on the screen if the list is empty or no. the fourth option let the
* user to search the nodes based on the name content of the nodes and if the
* name content of a node matches the name content of the searched name by the
* user, it shows every content of the node.the fifth option will ask the user
* which node the user wants to remove and it searches the nodes based on the
* name content of the nodes and if the name content of a node matches the name
* input by the user, the function removes the node from the list, if not, the
* function outputs that the name searched by the user has not found in the list.
* the sixth option This function Allows the user to delete all the nodes in the
* linked list and make an empty list out of the list of the names that we had.
* ------------------------------------------------------------------------------
* INPUT  : option      -> menu option
* ------------------------------------------------------------------------------
* PROCESS: creating the list
* 		   Displaying the list
* 		   Check if the list is empty
* 		   Searching by the name
* 		   searching and removing a name
* 		   clearing the list
*
*
* ------------------------------------------------------------------------------
* OUTPUT : Content of the nodes
* 		   Information about the list based on the creating and modifying
*******************************************************************************/


int main()
{
	/*************
	 * VARIABLES *
	 ************/

	int  menuOption;  // IN - user input
	PersonNode *head; // PROCESS - pointer for an empty list

	//creating an empty list
	head = NULL;



	//This function outputs the class heading
	PrintHeaderFile();


	// GETS USER INPUT AND CHECK IT

	//This function will output menu option to the screen and waits for the user
	//to input an option to what to what to do.
	menuOption = PrintMenu();

	while (menuOption != 0)
	{
		if (menuOption == 1)
		{
			cout << endl;

			 //This function will get the data from the input file and puts the
			 //data into the contents of the nodes, then add the nodes to the
			 //empty lists passed by Reference to the function
			CreatList(head);
		}

		else if (menuOption == 2)
		{
			 //This function will output the contents of the nodes of the linked
			 //list created in the CreatList function
			DisplayList(head);
		}

		else if (menuOption == 3)
		{
			 //This function check if the list created or modified by the user
			 //is empty or no and then  outputs if the list is empty or no
			IsEmpty(head);
		}

		else if (menuOption == 4)
		{
			 //This function will get a name from the user and search the name
			 //content of each node to see if there is a matching name in the
			 //nodes with the name searched by the user.
			SearchName(head);
		}

		else if (menuOption == 5)
		{
			 //This function will ask the user which node the user wants to
			 //remove and it searches the nodes based on the name content of the
			 //nodes and if the name content of a node matches the name input by
			 //the user, the function removes the node from the list,
			RemoveNode(head);

		}

		else if (menuOption == 6)
		{
			//This function Allows the user to delete all the nodes in the
			//linked list and make an empty list out of the list of the names
			//that we had
			ClearList(head);
		}

		// GETS USER INPUT AND CHECK IT

		menuOption = PrintMenu();
	}

}


