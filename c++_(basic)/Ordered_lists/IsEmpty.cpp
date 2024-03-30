/******************************************************************************
* AUTHOR     : Amirarsalan Valipour & Ali Eshghi
* STUDENT ID : 1103126 - 1112261
* LAB #10    : Creating an Ordered List
* CLASS      : CS 1B
* SECTION    : MW - 7:30 pm
* DUE DATE   : 11/05/2019
*******************************************************************************
* IsEmpty
*******************************************************************************
*  This function will provides an appropriate response indicating if the list
*   is empty or not.
*******************************************************************************/

#include "MyHeader.h"

void IsEmpty(PersonNode *head)
{

	//EMPTY LIST

	if (head == NULL)
	{
		cout << endl;
		cout << "Yes, the list is empty.";
		cout << endl;
	}

	//NON EMPTY LIST

	else
	{
		cout << endl;
		cout << "No, The list is NOT empty.";
		cout << endl;
	}

}
