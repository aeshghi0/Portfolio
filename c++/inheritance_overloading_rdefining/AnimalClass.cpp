/************************************************************
* AUTHOR	 : Ali Eshghi
* STUDENT ID : 1112261
* LAB #14	 : Inheritance, Overloading, & Redefining
* CLASS		 : CS 1B
* SECTION	 : MW - 7:30 pm - 9:50 pm
* DUE DATE	 : 12/12/2019
*************************************************************/

#include "AnimalClass.h"

/*******************************************
 * Animal()
 * Constructor: Class attribute initializer
 * Parameters:  None
 * Return:      None
 *******************************************/

Animal::Animal()
{
	name.clear();

	age = 0;
}


/*******************************************
 * Destructor: Does not perform anything
 * Parameters: None
 * Return:     None
 *******************************************/

Animal::~Animal()
{
	//Nothing
}


/******************************************************************************
 * METHOD setValues1: Animals Class
 * ____________________________________________________________________________
 * This Method initializes the new name and age to the new animal.
 *
 *  => returns nothing, just updates.
 * ____________________________________________________________________________
 *
 * PRE-CONDITIONS:
 *
 *  	string name: name of animal
 *  	int age: 	 age of animal POST-CONDITIONS:
 *
 * POST-CONDITIONS:
 *
 * 		No return value
 *
*******************************************************************************/

void Animal::setValues(string animalName, //CALC - Animal's Name
					   int    animalAge)  //CALC - Animal's Age
{
    name = animalName;
    age  = animalAge;
}


/******************************************************************************
 * METHOD setValues2: Animals Class
 * ____________________________________________________________________________
 * This Method initializes the new name to the new animal.
 *
 * => returns nothing, just updates class.
 * ____________________________________________________________________________
 * PRE-CONDITIONS:
 *
 * 		string name: Animal's Name
 *
 * POST-CONDITIONS:
 * 		No return value
 *
 ******************************************************************************/

void Animal::setValues(string animalName) //CALC - Animal's Name
{
    name = animalName;
}


/******************************************************************************
 * METHOD setValues3: Animals Class
 * ____________________________________________________________________________
 * This Method initializes the new age and age to the new animal.
 *
 * => returns nothing, just updates.
 * ____________________________________________________________________________
 * PRE-CONDITIONS:
 *
 * 		int age: Animal's Age
 *
 * POST-CONDITIONS:
 *
 * 		No return value
 *
 ******************************************************************************/

void Animal::setValues(int animalAge) // CALC - Animal's Age
{
    age = animalAge;
}


/******************************************************************************
 * METHOD TableHeader: Animal Class
 * ____________________________________________________________________________
 * Displays the table setting
 * ____________________________________________________________________________
 * PRE-CONDITIONS:
 *
 * 		None
 *
 * POST-CONDITIONS:
 *
 *		None
 *
 ******************************************************************************/

void Animal::tableHeader()const
{
	cout << left;
	cout << setw(10) << "NAME" << " ";
	cout << setw(4) << "AGE"  << " ";
}


/*****************************************************************************
 * METHOD TableHeaderLine: Animal Class
 * ___________________________________________________________________________
 * Displays the table prompt
 * ___________________________________________________________________________
 * PRE-CONDITIONS:
 *
 *		None
 *
 * POST-CONDITIONS:
 *
 * 		None
 *
 ****************************************************************************/

void Animal::tableHeaderLine()const
{
	cout << setfill('-');
	cout << right;
	cout << setw(11) << " ";
	cout << setw(5)  << " ";
	cout << setfill(' ');
}


/*****************************************************************************
 * METHOD DisplayTable: Animal Class
 * ___________________________________________________________________________
 * Displays the name and age data of all animal
 * ___________________________________________________________________________
 * PRE-CONDITIONS:
 *
 * 		None
 *
 * POST-CONDITIONS:
 *
 * 		None
 *
 *****************************************************************************/

void Animal::displayTable()const
{
	cout << left;
	cout << setw(11) << name << " ";
	cout << setw(5)  << age << " ";
}


/******************************************************************************
 * METHOD GetName: Animal Class
 * ____________________________________________________________________________
 * This Method returns animal's name
 *
 * 	=> returns name.
 * ____________________________________________________________________________
 * PRE-CONDITIONS:
 *
 * 		None
 *
 * POST-CONDITIONS:
 *
 * 		returns:
 *
 * 				name
 *
 *****************************************************************************/

string Animal::getName()const
{
	return name;
}


/******************************************************************************
 *  METHOD GetAge: Animal Class
 * ____________________________________________________________________________
 * This Method returns animal's age
 *
 * 	=> returns name.
 * ____________________________________________________________________________
 * PRE-CONDITIONS:
 *
 * 		None
 *
 * POST-CONDITIONS:
 *
 * 		returns:
 *
 * 				name
 *
 *****************************************************************************/

int Animal::getAge()const
{
	return age;
}






