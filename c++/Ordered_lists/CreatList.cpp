/******************************************************************************
* AUTHOR     : Amirarsalan Valipour & Ali Eshghi
* STUDENT ID : 1103126 - 1112261
* LAB #10    : Creating an Ordered List
* CLASS      : CS 1B
* SECTION    : MW - 7:30 pm
* DUE DATE   : 11/05/2019
*******************************************************************************
* CreatsList
*******************************************************************************
*  This function Creates a linked list adding each node in alphabetical order
*   from the input file.
*******************************************************************************/

#include "MyHeader.h"

void CreatList(PersonNode *&head)
{

	fstream     inFile;

	//OPEN FILE

	inFile.open("inFile.txt");

	PersonNode *persPtr;		//In & Calc  - node to input data
	PersonNode *searchPtr;		//Calc       - node to go through the loop
	PersonNode  node;			//In         - node to set the input into main
								//				main linked list

	bool found;					//Proc - lcv  varibale

	persPtr   = head;

	while (inFile)
	{
		//FIRST INPUT

		getline(inFile,node.name);
		inFile.get(node.gender);
		inFile >> node.age;
		inFile.ignore(10000,'\n');

		//CREATE A NEW NODE

		persPtr   = new PersonNode;
		*persPtr  = node;
		searchPtr = head;

		found     = false;

		//IF EMPTY
		if (head == NULL)
		{

			persPtr -> next = head;
			persPtr -> prev = NULL;
			head            = persPtr;
			persPtr         = NULL;

		}

		//ADDING IN TO THE FRONT

		else if(head -> name > persPtr -> name)
		{

			persPtr -> prev = NULL;
			persPtr -> next = head;
			head -> prev    = persPtr;
			head            = persPtr;
			persPtr         = NULL;

		}

		else
		{
			//COMPARING NODES TO SEE WHICH SHOULD GO WHERE

			while ((searchPtr -> next != NULL) && !found)
			{

				if (searchPtr -> next -> name > persPtr -> name)
				{

					found = true;

				}

				else
				{

					searchPtr = searchPtr -> next;

				}
			}

			//TAIL

			if(searchPtr -> next == NULL)
			{

				persPtr -> next = NULL;
				persPtr -> prev = searchPtr;
				searchPtr -> next = persPtr;

				persPtr = NULL;
			}

			//MIDDLE

			else
			{

				persPtr -> next = searchPtr -> next;
				persPtr -> prev = searchPtr;
				searchPtr -> next -> prev = persPtr;
				searchPtr -> next = persPtr;

				searchPtr = persPtr = NULL;

			}


		} // END - ELSE

		cout << "Adding: " << node.name << endl;

	} // END - WHILE

	//CLOSE FILE

	inFile.close();

	cout << endl;

}




