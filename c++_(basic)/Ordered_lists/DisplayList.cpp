/******************************************************************************
* AUTHOR     : Amirarsalan Valipour & Ali Eshghi
* STUDENT ID : 1103126 - 1112261
* LAB #10    : Creating an Ordered List
* CLASS      : CS 1B
* SECTION    : MW - 7:30 pm
* DUE DATE   : 11/05/2019
*******************************************************************************
* DisplayList
*******************************************************************************
*  This function will Displays the linked-list in the format described in the
*   expected input/output section on the console;.
*******************************************************************************/

#include "MyHeader.h"

void DisplayList(PersonNode *head)
{
	//VARIABLES

	int i;	//Calc & Out - used for quantity

	//INITIALIZING

	i = 1;

	 if (head == NULL)
	 {
		 cout << endl;
		 cout << "Can't Display an empty list!";
		 cout << endl;
	 }


	 else
	 {
		//SETTING UP THE TABLE

		cout << endl;

		cout << right;

		cout << setw(4)  << '#';
		cout << setw(8)  << "NAME";
		cout << setw(29) << "GENDER";
		cout << setw(7)  << "AGE ";

		cout << left;

		cout << endl;

		cout << "------- ";
		cout << "------------------------  ";
		cout << "-------- ";
		cout << "-----";

		cout << endl;

		//OUTPUTTING DATA IN ALPHABETICAL ORDER

		while(head != NULL)
		{
			cout << right;
			cout << setw(4) << i << "    ";
			cout << left;
			cout << setw(29) << head -> name;
			cout << setw(7)  << head -> gender;
			cout << setw(4)  << head -> age;
			cout << endl;
			cout << left;

			i++;
			head = head -> next;
		}

	 }


}

