/************************************************************
* AUTHOR	    : Ali Eshghi
* STUDENT ID    : 1112261
* LAB #13		: LAB 13 - ARRAYS AND LINKED LIST (OOP)
* CLASS	        : CS 1B
* SECTION	    : MW - 7:30 pm - 9:50 pm
* DUE DATE	    : 12/3/2019
*************************************************************/

#include "MyHeader.h"
#include "ClassHeader.h"


Animal::Animal()	/*** CONSTRUCTOR ***/
{
	/*******************
	 * 	INITIALIZATION *
	 *******************/

	name.clear();
	age  = 0;
	listSize = 0;
	head = NULL;
}

Animal::~Animal()	 /*** DESTRUCTOR ***/
{

	/*************
	 * 	VARIABLE *
	 *************/

	SheepNode *sheepPtr;

	if(head != NULL)
	{
		//clear the list
		sheepPtr = head;
		while(sheepPtr != NULL)
		{
			head = head -> next;
			delete sheepPtr;

			sheepPtr = head;
		}

		for(int i = 0; i < AR_SIZE; i++)
		{
			nameAr[i] = ' ';
		}
		cout << "The list has been cleared!" << endl << endl;
	}

	else if(head == NULL)
	{
		cout << "\nThe list is empty" << endl << endl;
	}

}


//method for adding a new sheep and its age to parallel arrays
void Animal::AddSheep(string name, int age)
{
	if(listSize < AR_SIZE)
	{
		nameAr[listSize] = name;
		ageAr[listSize]  = age;

		listSize++;

		cout << endl << endl;
		cout << "The Sheep..."           << endl;
		cout << "Sheep Name: "   << name << endl;
		cout << "Sheep Age:  "   << age  << endl;
		cout << "Has been added" << endl << endl;
	}

	else
	{
		cout << "could not add new animal, list is full..." << endl;
	}

}

//method for adding a new sheep to a linked list
void Animal::AddSheepLinkedList(string name, int age)
{
	/*************
	 * 	VARIABLE *
	 *************/

	SheepNode *newSheepNode;
	SheepNode *tail;

	/*******************
	 * 	INITIALIZATION *
	 *******************/

	newSheepNode = new SheepNode;

    /*** ADD TO THE TAIL ***/

	//check if there is memory for new node
	if(newSheepNode != NULL)
	{
		newSheepNode -> sheepName = name;
		newSheepNode -> sheepAge  = age;


		//check if list is empty
		if(head != NULL)
		{
			tail = head;

			//find the tail
			while(tail != NULL)
			{
				tail = tail -> next;
			}

			tail -> next = newSheepNode;
		}

		else
		{
			head = newSheepNode;
		}

		listSize++;
	}

	else
	{
		cout << "Could not add to the list - out of memory";
	}
}

//method that returns the size of the list of the sheeps
int Animal::ListSize() const
{
	if(head != NULL)
	{
		return listSize;
	}
	else if(head == NULL)
	{
		cout << "\nThe list is empty" << endl << endl;
		return 0;
	}

}

//method for showing the first sheep from the list
void Animal::DisplayFirstSheep()
{
	if(head != NULL)
	{
		cout << left;
		cout << setw(15) << "NAME" << "AGE" <<endl;
		cout << setw(15) << "--------------" << "---" << endl;
		cout << setw(16) << nameAr[0] << ageAr[0];
		cout << endl << endl << endl;

		cout << "Is at the front of the list!" << endl << endl;
	}

	else if(head == NULL)
	{
		cout << "Nobody is in front -the list is empty!" << endl << endl;
	}


}

//method for finding the sheep in the list
void Animal::FindSheep(string search) const
{
	/*************
	 * 	VARIABLE *
	 *************/

	int   i;
	bool  stat;

	/*******************
	 * 	INITIALIZATION *
	 *******************/

	i    = 0;
	stat = false;

	if(head != NULL)
	{
		while(i < AR_SIZE && stat)
		{
			if(nameAr[i] == search)
			{
				stat = true;
			}

			else
			{
				i++;
			}

			if(stat == true)
			{
				cout << setw(15) << "NAME" << "AGE" <<endl;
				cout << setw(15) << "--------------" << "---" << endl;
				cout << setw(16) << nameAr[i] << ageAr[i] << endl << endl;
				cout << "Has Been Found";
			}
		}
	}

	else if(head == NULL)
	{
		cout << "There are no sheep to be found!" << endl << endl;
	}

}


//method  for outputting the objects
void Animal::Display() const
{
	/*************
	 * 	VARIABLE *
	 *************/

	SheepNode *sheepPtr;

	if(head != NULL)
	{
		cout << "<output using the array>" << endl;
		cout << left;
		cout << setw(15) << "NAME" << "AGE" <<endl;
		cout << setw(15) << "--------------" << "---" << endl;

		for(int index = 0; index < listSize; index++)
		{
			cout << setw(16) << nameAr[index] << ageAr[index] << endl;
		}
		cout << endl << endl;


		cout << "<output using the linked list>" << endl;
		cout << left;
		cout << setw(15) << "NAME" << "AGE" <<endl;
		cout << setw(15) << "--------------" << "---" << endl;

		for(sheepPtr = head -> next; sheepPtr != NULL; sheepPtr = sheepPtr -> next)
		{
			cout << setw(16) << sheepPtr->sheepName << sheepPtr->sheepAge << endl;
		}

	}

	else if(head == NULL)
	{
		cout << "\nThe list is empty" << endl << endl;
	}

}



