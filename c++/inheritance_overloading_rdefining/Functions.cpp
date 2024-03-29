/************************************************************
* AUTHOR	 : Ali Eshghi
* STUDENT ID : 1112261
* LAB #14	 : Inheritance, Overloading, & Redefining
* CLASS		 : CS 1B
* SECTION	 : MW - 7:30 pm - 9:50 pm
* DUE DATE	 : 12/12/2019
*************************************************************/

#include "SheepClass.h"
#include "PigClass.h"
#include "MyHeader.h"

using namespace std;

/**************************************************************
 *
 * PrintHeader
 *_________________________________________________________
 * This function receives an assignment name, type
 *   and number then outputs the appropriate header -
 *   returns nothing.
 *_________________________________________________________
 * PRE-CONDITIONS
 * 		asName: Assignment Name has to be previously defined
 * 		asType: Assignment Type has to be previously defined
 * 		asNum : Assignment Number has to be previously defined
 *
 * POST-CONDITIONS
 *      This function will output the class heading.
 *      <Post-conditions are the changed outputs either
 *       passed by value or by reference OR anything affected
 *       by the function>
 **************************************************************/

void PrintHeader(string asName,  // IN - assignment Name
				 char   asType,  // IN - assignment type
				 	 	 	 	 //      (LAB or ASSIGNMENT)
				 int    asNum)   // IN - assignment number
{

	cout << left;
	cout << "**************************************************\n";
	cout << "*  PROGRAMMED BY : Ali Eshghi\n";
	cout << "*  " << setw(14) << "STUDENT ID" << ": 1112261\n";
	cout << "*  " << setw(14) << "CLASS"      << ": CS1B –-> MW - 7:30-9:50\n";
	cout << "*  ";

	// PROC – This will output “LAB #” or “ASSIGNMENT #”  based on the
	//			asType and adjust the setw accordingly

	if (toupper(asType) == 'L')
	{
		cout << "LAB #" << setw(9);
	}

	else
	{
		cout << "ASSIGNMENT #" << setw(2);
	}

	cout << asNum << ": " << asName << endl;
	cout << "**************************************************\n\n";
	cout << right;

}



/**************************************************************
 *
 * InputMenu
 *_________________________________________________________
 * This function will prompt the user with menu and get
 *  and check their user input.
 *_________________________________________________________
 * PRE-CONDITIONS
 * 		option: menu option for introduction menu
 *
 * POST-CONDITIONS
 *      returns -> option1
 **************************************************************/

int InputMenu()
{
	int option; //IN & CALC - User input for menu option

	//GETS AND CHECK INPUT

	do
	{
		//CHECKS FOR CHARACTER

		if(cin.fail())
		{
			cout << endl << endl;
			cout << "**** Please input a NUMBER between 0 and 1 ****";
			cout << endl << endl;

			cin.clear();
			cin.ignore(1000, '\n');
		}

		//DISPLAYS MENU

		cout << "MENU\n\n";
		cout << "1 - Initialize Animals\n";
		cout << "0 - Exit\n";
		cout << "Enter selection: ";

		cin >> option;
		cin.ignore(1000,'\n');

		cout << endl;;

		//CHECKS FOR BOUNDARY VALUES

		if((option < 0) || (option > 1))
		{
			cout << endl << endl;
			cout << "**** The number " << option << " is an invalid entry ****";
			cout << endl;
			cout << "**** Please input a number between 0 and 1 ****";
			cout << endl << endl;

		}

	}while(cin.fail() || (option < 0) || (option > 1));

	return option;
}



/**************************************************************
 *
 * MainMenu
 *_________________________________________________________
 * This function receives displays the main menu of the
 *  program, prompts and receives an choice from the user,
 *  error checks that input and returns the enumerated menu
 *  variable to the main menu.
 *_________________________________________________________
 * PRE-CONDITIONS
 * 		option: user input for menu option
 *      base:   enum for menu
 *
 * POST-CONDITIONS
 *      returns -> option
 **************************************************************/

Menu MainMenu()
{
	int option; 		//IN & CALC - User input for menu option

	Menu base; 	//PROC - enum for menu

	do
	{
		//CHECKS FOR CHARACTER

		if(cin.fail())
		{
			cout << endl << endl;
			cout << "**** Please input a NUMBER between 0 and 4 ****";
			cout << endl << endl;

			cin.clear();
			cin.ignore(1000, '\n');
		}

		//DISPLAYS MENU

		cout << "MAIN MENU\n\n";
		cout << "1 - Re-Initialize Sheep\n";
		cout << "2 - Re-Initialize Pigs\n";
		cout << "3 - Change Age\n";
		cout << "4 - Display\n";
		cout << "0 - Exit\n";
		cout << "Enter selection: ";

		cin >> option;
		cin.ignore(1000,'\n');

		cout << endl;;

		if((option < 0) || (option > 4))
		{
			cout << endl << endl;
			cout << "**** The number " << option << " is an invalid entry ****";
			cout << endl;
			cout << "**** Please input a number between 0 and 4 ****";
			cout << endl << endl;
		}

	}while(cin.fail() || (option < 0) || (option > 4));

	switch(option)
	{
		case 1: base = REINIT_SHEEP;
				break;

		case 2: base = REINIT_PIGS;
				break;

		case 3: base  = CHANGE_AGE;
				break;

		case 4: base = DISPLAY;

				break;

		case 0: base = EXIT;

				break;
	}

	return base;

}



/**************************************************************
 *
 * InputSheepList
 *_________________________________________________________
 * This function will input the related data into the sheep
 *  object.
 *_________________________________________________________
 * PRE-CONDITIONS
 *
 *
 * POST-CONDITIONS
 *      head: first node
 **************************************************************/

sheepList *InputSheepList()
{

	int age;				//IN & CALC - sheep age

	string name;			//IN & CALC - sheep name
	string type;			//IN & CALC - wool type
	string color;			//IN & CALC - wool color

	sheepList *head;		//CALC - first node
	sheepList *tail;		//CALC - last node
	sheepList *sheepPtr;	//CALC - pointer counter

	ifstream  iFile;		//PROC - input file

	//INITIALIALIZING THE POINTERS

	head = NULL;

	sheepPtr = NULL;

	sheepPtr = new sheepList;

	//CHECKS FOR EMPTY LIST

	if(sheepPtr != NULL)
	{
		//OPENS INPUT FILE

		iFile.open("Sheeps.txt");


		//INPUTS DATA

		getline(iFile, name);

		iFile >> age;

		iFile.ignore(1000, '\n');

		getline(iFile, type);

		getline(iFile, color);

		iFile.ignore(1000, '\n');

		//ASSIGNS EACH INPUT

		while(iFile && (sheepPtr != NULL))
		{
			sheepPtr->sheep.setValues(name, age, type, color);

			sheepPtr->next = NULL;

			if(head != NULL)
			{
				tail = head;

				while(tail->next != NULL)
				{
					tail = tail->next;
				}

				tail->next = sheepPtr;
			}

			else
			{
				head = sheepPtr;
			}

			sheepPtr = new sheepList;

			getline(iFile, name);

			iFile >> age;

			iFile.ignore(1000, '\n');

			getline(iFile, type);

			getline(iFile, color);

			iFile.ignore(1000, '\n');

		}

		iFile.close();

		tail     = NULL;

		sheepPtr = NULL;

	}

	//IF LIST IS EMPTY

	else
	{

		cout << "Sheep List is Empty!" << endl;

	}

	return head;
}



/**************************************************************
 *
 * InputPigList
 *_________________________________________________________
 * This function will input the related data into the pig
 *  object.
 *_________________________________________________________
 * PRE-CONDITIONS
 *
 *
 * POST-CONDITIONS
 *      head: first node
 **************************************************************/

pigList *InputPigList()
{

	int age;				//IN & CALC - pig age

	string name;			//IN & CALC - pig name
	string type;			//IN & CALC - tail type

	pigList *head;			//CALC - first node
	pigList *tail;			//CALC - last node
	pigList *pigPtr;		//CALC - pointer counter

	ifstream  iFile;		//PROC - input file

	//INITIALIALIZING THE POINTERS

	head = NULL;

	pigPtr = NULL;

	pigPtr = new pigList;

	//CHECKS FOR EMPTY LIST

	if(pigPtr != NULL)
	{
		//OPENS INPUT FILE

		iFile.open("Pigs.txt");

		//INPUTS DATA

		getline(iFile, name);

		iFile >> age;

		iFile.ignore(1000, '\n');

		getline(iFile, type);

		iFile.ignore(1000, '\n');

		//ASSIGNS EACH INPUT

		while(iFile && (pigPtr != NULL))
		{
			pigPtr->pig.setValues(name, age, type);

			pigPtr->next = NULL;

			if(head != NULL)
			{
				tail = head;

				while(tail->next != NULL)
				{
					tail = tail->next;
				}

				tail->next = pigPtr;
			}

			else
			{
				head = pigPtr;
			}

			pigPtr = new pigList;

			getline(iFile, name);

			iFile >> age;

			iFile.ignore(1000, '\n');

			getline(iFile, type);

			iFile.ignore(1000, '\n');

		}

		iFile.close();

		tail   = NULL;

		pigPtr = NULL;

	}

	//IF LIST IS EMPTY

	else
	{
		cout << "Pig List is Empty!"<< endl;
	}

	return head;
}



/**************************************************************
 *
 * Update
 *_________________________________________________________
 * This function will update the info based on user's data.
 *_________________________________________________________
 * PRE-CONDITIONS
 *
 *
 * POST-CONDITIONS
 *      option: user option
 **************************************************************/

char Update()
{
	char option; //IN & CALC - user's option

	do
	{
		//CHECKS FOR CORRECT TYPE OF DATA

		if(cin.fail())
		{
			cout << "**** Please input a N or Y ****" << endl << endl;

			cin.clear();

			cin.ignore(1000, '\n');
		}

		//PROMPT

		cout << "Are you sure you want to update your list (Y/N)? ";

		cin >> option;

		cin.ignore(1000, '\n');

		option = toupper(option);

		//VAILD ENTRY

		if((option != 'Y') && (option != 'N'))
		{
			cout << "**** " << option << " is an invalid entry ****";

			cout << endl;

			cout << "**** Please input from your available choices ****";

			cout << endl << endl;
		}

	}while (cin.fail() || ((option != 'Y') && (option != 'N')));

	return option;
}



/**************************************************************
 *
 * ChooseAnimal
 *_________________________________________________________
 * This function will ask user to choose their target sheep.
 *_________________________________________________________
 * PRE-CONDITIONS
 *
 *
 * POST-CONDITIONS
 *      option: user option
 **************************************************************/

char ChooseAnimal()
{
	char option;	//IN & CALC - user's option

	do
	{
		//CHECKS FOR CORRECT INPUT

		if (cin.fail())
		{
			cout << "**** Please input a S or P ****" << endl << endl;

			cin.clear();

			cin.ignore(1000, '\n');
		}

		//PROMPT

		cout << "Which animal type would you like to change (S/P)? ";

		cin >> option;

		cin.ignore(1000, '\n');

		cout << endl;

		option = toupper(option);

		//CHECKS FOR VALID INPUT

		if((option != 'S') && (option != 'P'))
		{
			cout << endl << endl;

			cout << "**** " << option << " is an invalid entry" << "****";

			cout << endl;

			cout << "**** Please input a S or P ****";

			cout << endl << endl;
		}

	}while(cin.fail() || ((option != 'S') && (option != 'P')));

	return option;
}



/**************************************************************
 *
 * TargetSheep
 *_________________________________________________________
 * This function will ask user to choose their target sheep.
 *_________________________________________________________
 * PRE-CONDITIONS
 *		head: first pointer
 *
 * POST-CONDITIONS
 *      return -> option: user option
 **************************************************************/

int TargetSheep(sheepList *head)	//PROC - sheep node
{
	int i;			//CALC - LCV
	int option;		//IN & CALC - user choice

	sheepList *sheepPtr;  //CALC - pointer for the list

	//INITIALIZE

	i = 0;

	sheepPtr = NULL;

	sheepPtr = head;

	//PROMPT

	cout << "Sheep: ";

	cout << endl;

	//CHECKS FOR EMPTY LIST

	while(sheepPtr != NULL)
	{
		cout << ++i << " - " << sheepPtr->sheep.getName() << endl;

		sheepPtr = sheepPtr->next;

	}

	cout << endl;

	do
	{
		if (cin.fail())
		{
			cout << endl << endl;

			cout << "**** Please input a NUMBER between 1 and " << i;

			cout << " ****";

		    cout << endl << endl;

		    cin.clear();

		    cin.ignore(1000, '\n');
		}

		//PROMPT

		cout << "Select the animal you'd like to change: ";

		cin >> option;

		cin.ignore(1000, '\n');

		cout << endl;

		//CHECKS FOR RANGE

		if((option < 0) || (option > i))
		{
			cout << endl << endl ;

			cout << "**** The number " << option << " is an invalid entry";

			cout << "****";

			cout << endl << endl ;

			cout << "**** Please input a number between 1 and " << i << " ****";

			cout << endl << endl ;
		}

	}while(cin.fail() || (option < 1) || (option > i));

	//JUST TO BE SAFE

	delete sheepPtr;

	sheepPtr = NULL;

	return option;

}



/**************************************************************
 *
 * TargetPig
 *_________________________________________________________
 * This function will ask user to choose their target pig.
 *_________________________________________________________
 * PRE-CONDITIONS
 *		head: first pointer
 *
 * POST-CONDITIONS
 *      return -> option: user option
 **************************************************************/

int TargetPig(pigList *head)	//PROC - pig node
{
	int i;			//CALC - LCV
	int option;		//IN & CALC - user choice

	pigList *pigPtr;  //CALC - pointer for the list

	//INITIALIZE

	pigPtr = NULL;

	pigPtr = head;

	i = 0;

	//PROMPT

	cout << "Pig: ";

	cout << endl;

	//CHECKS FOR EMPTY LIST

	while(pigPtr != NULL)
	{
		cout << ++i << " - " << pigPtr->pig.getName() << endl;

		pigPtr = pigPtr->next;
	}

	cout << endl;

	do
	{
		if (cin.fail())
		{
			cout << endl << endl;

			cout << "**** Please input a NUMBER between 1 and " << i;

			cout << " ****";

			cout << endl << endl;

			cin.clear();

			cin.ignore(1000, '\n');
		}

		//PROMPT

		cout << "Select the animal you'd like to change: ";

		cin >> option;

		cin.ignore(1000, '\n');

		cout << endl;

		//CHECKS FOR RANGE

		if((option < 0) || (option > i))
		{
			cout << endl << endl ;

			cout << "**** The number " << option << " is an invalid entry";

			cout << "****";

			cout << endl << endl ;

			cout << "**** Please input a number between 1 and " << i << " ****";

			cout << endl << endl ;
		}

	}while(cin.fail() || (option < 1) || (option > i));

	//JUST TO BE SAFE

	delete pigPtr;

	pigPtr = NULL;

	return option;

}



/**************************************************************
 *
 * ChangeAgeSheep
 *_________________________________________________________
 * This function will update the sheep's age based on user
 *  data.
 *_________________________________________________________
 * PRE-CONDITIONS
 *		head: first pointer
 *
 * POST-CONDITIONS
 *
 **************************************************************/

void ChangeAgeSheep(sheepList *head,  	//PROC - sheep node
					const int option)	//PROC - user target
{
	int age;	//IN & CALC - user choice for new age
	int i;		//CALC - LCV

	sheepList *sheepPtr; 	//CALC - Sheep pointer

	//INITIALIZE

	sheepPtr = NULL;

	sheepPtr = head;

	do
	{
		//CHECKS FOR CORRECT TYPE

		if (cin.fail())
		{
			cout << endl << endl;

			cout << "**** Please input a NUMBER between 1 and 10 ****";

			cout << endl << endl;

			cin.clear();

			cin.ignore(1000, '\n');
		}

		//PROMPT

		cout << "New Age: ";

		cin >> age;

		cin.ignore(1000, '\n');

		cout << endl;

		//CHECKS FOR RANGE

		if((age < 0) || (age > 10))
		{
			cout << endl << endl;

			cout << "**** The number " << age << " is an invalid entry ****";

			cout << endl;

			cout << "**** Please input a number between 0 and 10 ****";

			cout << endl << endl;
		}

	}while(cin.fail() || (age < 0) || (age > 10));

	//GOES THROUGH THE LOOP

	for(i = 1; i < option; i++)
	{
		sheepPtr = sheepPtr->next;
	}

	//OUTPUT

	cout << "Changing " << sheepPtr->sheep.getName() << "'s age to ";

	cout << age << "..." << endl;

	//CHANGE AGE

	sheepPtr->sheep.changeAge(age);

	//JUST TO BE SAFE

	sheepPtr = NULL;

}



/**************************************************************
 *
 * ChangeAgePig
 *_________________________________________________________
 * This function will update the pig's age based on user
 *  data.
 *_________________________________________________________
 * PRE-CONDITIONS
 *		head: first pointer
 *
 * POST-CONDITIONS
 *
 **************************************************************/

void ChangeAgePig(pigList *head,  		//PROC - pig node
				  const int option)		//PROC - user target
{
	int age;	//IN & CALC - user choice for new age
	int i;		//CALC - LCV

	pigList *pigPtr; 	//CALC - pig pointer

	//INITIALIZE

	pigPtr = NULL;

	pigPtr = head;

	do
	{
		//CHECKS FOR CORRECT TYPE

		if (cin.fail())
		{
			cout << endl << endl;

			cout << "**** Please input a NUMBER between 1 and 10 ****";

			cout << endl << endl;

			cin.clear();

			cin.ignore(1000, '\n');
		}

		//PROMPT

		cout << "New Age: ";

		cin >> age;

		cin.ignore(1000, '\n');

		cout << endl;

		//CHECKS FOR RANGE

		if((age < 0) || (age > 10))
		{
			cout << endl << endl;

			cout << "**** The number " << age << " is an invalid entry ****";

			cout << endl;

			cout << "**** Please input a number between 0 and 10 ****";

			cout << endl << endl;
		}

	}while(cin.fail() || (age < 0) || (age > 10));

	//GOES THROUGH THE LOOP

	for(i = 1; i < option; i++)
	{
		pigPtr = pigPtr->next;
	}

	//OUTPUT

	cout << "Changing " << pigPtr->pig.getName() << "'s age to ";

	cout << age << "..." << endl;

	//CHANGE AGE

	pigPtr->pig.changeAge(age);

	//JUST TO BE SAFE

	pigPtr = NULL;

}



/**************************************************************
 *
 * SheepDisplay
 *_________________________________________________________
 * This function will display sheep list.
 *_________________________________________________________
 * PRE-CONDITIONS
 *		head: first pointer
 *
 * POST-CONDITIONS
 *
 **************************************************************/

void SheepDisplay(sheepList *head)
{
	sheepList *sheepPtr;	//Calc - sheep list pointer

	//INITIALIZE

	sheepPtr = NULL;

	sheepPtr = head;

	//IF LIST IS NOT EMPTY DISPLAY THE TAVLE

	if(sheepPtr != NULL)
	{
		sheepPtr->sheep.tableHeader();

		cout << endl; sheepPtr->sheep.tableHeaderLine();

		cout << endl;

		while(sheepPtr != NULL)
		{
			sheepPtr->sheep.displayTable();

			cout << endl;

			sheepPtr = sheepPtr->next;
		}
	}

	else
	{
		cout << "Can't display an empty list!" << endl;
	}

	//JUST TO BE SAFE

	delete sheepPtr;

	sheepPtr = NULL;
}



/**************************************************************
 *
 * PigDisplay
 *_________________________________________________________
 * This function will display sheep list.
 *_________________________________________________________
 * PRE-CONDITIONS
 *		head: first pointer
 *
 * POST-CONDITIONS
 *
 **************************************************************/

void PigDisplay(pigList *head)
{
	pigList *pigPtr;	//Calc - pig list pointer

	//INITIALIZE

	pigPtr = NULL;

	pigPtr = head;

	//IF LIST IS NOT EMPTY DISPLAY THE TAVLE

	if(pigPtr != NULL)
	{
		pigPtr->pig.tableHeader();

		cout << endl; pigPtr->pig.tableHeaderLine();

		cout << endl;

		while(pigPtr != NULL)
		{
			pigPtr->pig.displayTable();

			cout << endl;

			pigPtr = pigPtr->next;
		}
	}

	else
	{
		cout << "Can't display an empty list!" << endl;
	}

	//JUST TO BE SAFE

	delete pigPtr;

	pigPtr = NULL;
}
