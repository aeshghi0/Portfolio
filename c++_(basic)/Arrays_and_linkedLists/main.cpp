/************************************************************
* AUTHOR	    : Ali Eshghi
* STUDENT ID    : 1112261
* LAB #13		: LAB 13 - ARRAYS AND LINKED LIST (OOP)
* CLASS	        : CS 1B
* SECTION	    : MW - 7:30 pm - 9:50 pm
* DUE DATE	    : 12/3/2019
*************************************************************/
#include "MyHeader.h"
#include "Classheader.h"

/************************************************************
 * LAB 13 - ARRAYS AND LINKED LIST (OOP)
 *_________________________________________________________
 * This program will use the arrays and linked list as an
 * objects of a class and gets the information base of the
 * users choice and add those information to the list and
 * prompts a menu for the user who can have more options
 *_________________________________________________________
 * INPUT:menuOption -> user input for the menu
 * 		 name       -> name of a new sheep
 * 		 age		-> age of a new sheep
 *
 *
 * OUTPUT:name      -> name of the sheeps in the list
 * 		  age    	-> age of the sheeps in the list
 * 		  size		-> how many sheeps are in the list
 * 		  search	-> user input name to search in the list
 * 		  if the list is empty or no
 ************************************************************/

int main()
{

	/*************
	 * 	VARIABLE *
	 *************/
	int		menuOption;
	Animal  sheep;
	string  name;
	string  search;
	int     age;
	int		size;


	//this function will output the class header
	PrintHeader();



	cout << "*************************************" << endl;
	cout <<	"* WELCOME TO THE SHEEP LIST MANAGER *" << endl;
	cout << "*************************************" << endl << endl;

	//do while loop for menu
	do
	{
		//this function prompts the user the menu and gets the user input
		menuOption = Menu();


		//first option that adds the sheep to the menu
		if(menuOption == 1)
		{
			cin.ignore(10000,'\n');
			cout << "Sheep name: ";
			getline(cin,name);
			cout << "Sheep Age:  ";
			cin  >> age;

			sheep.AddSheep(name, age);
			sheep.AddSheepLinkedList(name, age);
		}

		//second option that displays the first sheep in the list
		else if(menuOption == 2)
		{
			sheep.DisplayFirstSheep();
		}

		//third option that searches for a specific sheep
		else if(menuOption == 3)
		{
			cin.ignore(10000,'\n');
			cout << "Who are you looking for? ";
			getline(cin,search);
			sheep.FindSheep(search);
		}

		//fourth option that outputs how many sheeps are in the list
		else if(menuOption == 4)
		{
			size = sheep.ListSize();
			cout << "There are " << size << " sheeps in the list"
								 << endl << endl;
		}

		//fifth option that displays the members of the list
		else if(menuOption == 5)
		{
			sheep.Display();

			size = sheep.ListSize();
			cout << "There are " << size << " sheeps in the list"
								 << endl << endl;
		}

		//sixth option that clears the list (deconstruction)
		else if(menuOption == 6)
		{
			sheep.~Animal();

		}


	}while(menuOption != 0);


	return 0;


}
