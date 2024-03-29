/******************************************************************************
* AUTHOR     : Amirarsalan Valipour & Ali Eshghi
* STUDENT ID : 1103126 - 1112261
* LAB #10    : Creating an Ordered List
* CLASS      : CS 1B
* SECTION    : MW - 7:30 pm
* DUE DATE   : 11/05/2019
*******************************************************************************
* ClearList
*******************************************************************************
*  This function Allows the user to delete all the nodes in the linked list.
*******************************************************************************/

#include "MyHeader.h"

void ClearList(PersonNode *&head)
{
	bool clear; 	//Calc - condition to check for empty list

	clear = false;

	//CHECKS FOR EMPTY LIST

	if (head == NULL)
	{
		cout << endl;
		cout << "The list has been cleared!";
		cout << endl;
	}

	//IF THE LIST IS NOT EMPTY

	else
	{
		cout << endl;
		cout << "CLEARING LIST:" << endl;

		while(!clear)
		{
			if(head != NULL)
			{
				cout << "Removing " << head -> name << endl;

				head = head -> next;

				delete head;

			}
			else
			{
				clear = true;
			}

		}
	}

}
