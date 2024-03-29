/******************************************************************************
* AUTHOR     : Amirarsalan Valipour & Ali Eshghi
* STUDENT ID : 1103126 - 1112261
* LAB #10    : Creating an Ordered List
* CLASS      : CS 1B
* SECTION    : MW - 7:30 pm
* DUE DATE   : 11/05/2019
*******************************************************************************
* SearchName
*******************************************************************************
*  This function Allows the user to input a name and will output the node as
*   described.
*******************************************************************************/

#include "MyHeader.h"

void SearchName(PersonNode *head)
{
	 PersonNode *persPtr;	//Proc - stores the target name
	 PersonNode node;		//Proc & In - passes the info into persPtr

	 bool found;			//Proc - condition value for the searched name

	 //CHECKS FOR EMPTY LIST

	 found = false;

	 if (head == NULL)
	 {
		 cout << endl;
		 cout << "Search operation is not available for an empty list.";
		 cout << endl;
	 }

	 else
	 {
		 //NEW NODE

		 persPtr = new PersonNode;

		 //INPUT

		 cout << endl;
		 cout << "Who would you like to search for? ";
		 getline(cin, node.name);

		 *persPtr = node;

		 cout << endl;
		 cout << "Searching for " << persPtr -> name << "...";
		 cout << endl;

		 //GOES ATHROUGH THE LIST



		 while ((head -> next != NULL) && !found)
		 {
			 //IF FOUND

			 if (head -> name == persPtr -> name)
			 {
				 cout << endl;
				 cout << "Name:    " << head -> name   << endl;
				 cout << "Gender:  " << head -> gender << endl;
				 cout << "Age:     " << head -> age     << endl;

				 found = true;
			 }

			 else
			 {
				 head  = head -> next;
				 found = false;

			 }


		 }

		 if (head -> next == NULL && head -> name == persPtr -> name)
		 {
			cout << endl;
			cout << "Name:    " << head -> name   << endl;
			cout << "Gender:  " << head -> gender << endl;
			cout << "Age:     " << head -> age     << endl;

			found = true;
		 }

		 //IF NOT FOUND IN THE LIST

		 else if (!found)
		 {
			 cout << endl;
			 cout << "I'm sorry, \"" << persPtr -> name;
			 cout << "\" was NOT found!";
			 cout << endl;
		 }

	 }

	 persPtr = NULL;
}
