/************************************************************
* AUTHOR	 : Ali Eshghi
* STUDENT ID : 1112261
* LAB #14	 : Inheritance, Overloading, & Redefining
* CLASS		 : CS 1B
* SECTION	 : MW - 7:30 pm - 9:50 pm
* DUE DATE	 : 12/12/2019
*************************************************************/

#include "AnimalClass.h"
#include "SheepClass.h"

using namespace std;

/*******************************************
 * Sheep()
 * Constructor: Class attribute initializer
 * Parameters:  None
 * Return:      None
 *******************************************/

Sheep::Sheep()
{
	woolColor.clear();

	woolType = NONE;
}


/*******************************************
 * ~Sheep()
 * Destructor: Does not perform anything
 * Parameters: None
 * Return:     None
 *******************************************/

Sheep::~Sheep()
{

}


/******************************************************************************
 *  METHOD SetValues: Sheep Class
 * ____________________________________________________________________________
 *  This Method inputs the new sheep info into the object.
 *
 *  => returns nothing.
 * ____________________________________________________________________________
 * PRE-CONDITIONS:
 *
 * 		string name:  sheep name
 *      int age:      sheep age
 *      string type:  wool type
 *      string color: color of the wool
 *
 * POST-CONDITIONS:
 *
 *		None
 *
 ******************************************************************************/

void Sheep::setValues(string name,  //IN, CALC - sheep name
					  int age,      //IN, CALC - sheep age
					  string type,  //IN, CALC - wool type
					  string color) //IN, CALC - wool color
{
	sheep.setValues(name, age);

	woolColor = color;

	if(type == "LONG")
	{
		woolType = LONG;
	}

	else if(type == "MEDIUM")
	{
		woolType = MEDIUM;
	}

	else if(type == "FINE")
	{
		woolType = FINE;
	}

	else if(type == "CARPET")
	{
		woolType = CARPET;
	}
}


/******************************************************************************
 *  METHOD ChangeAge: Sheep Class
 * ____________________________________________________________________________
 *  This Method receives a an age input and replace it with sheep age.
 * ____________________________________________________________________________
 * PRE-CONDITIONS:
 *
 * 		int age: sheep age
 *
 * POST-CONDITIONS:
 *
 * 		None
 ******************************************************************************/

void Sheep::changeAge(int age) //IN & CALC - sheep age
{
	sheep.setValues(age);
}


/******************************************************************************
 *  METHOD GetName: Sheep Class
 * ____________________________________________________________________________
 *  This Method displays sheep's name.
 *
 *  => returns name.
 * ____________________________________________________________________________
 * PRE-CONDITIONS:
 *
 * 			None
 *
 * POST-CONDITIONS:
 *
 * 			Returns:
 *
 * 					name
 *
 ******************************************************************************/

string Sheep::getName()const
{
	return (sheep.getName());
}


/******************************************************************************
 *  METHOD TableHeader: Sheep Class
 * ____________________________________________________________________________
 *  Displays the table setting
 * ____________________________________________________________________________
 * PRE-CONDITIONS:
 *
 * 		None
 *
 * POST-CONDITIONS:
 *
 * 		None
 *
 ******************************************************************************/

void Sheep::tableHeader()const
{
	sheep.tableHeader();
	cout << left;
	cout << setw(9) << "WOOLTYPE" << " ";
	cout << setw(5) << "COLOR" << " ";
}


/*****************************************************************************
 * METHOD TableHeaderLine: Sheep Class
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

void Sheep::tableHeaderLine()const
{
	sheep.tableHeaderLine();

	cout << setfill('-');
	cout << right;
	cout << setw(11) << " ";
	cout << setw(7) << " ";
	cout << setfill(' ');
}


/*****************************************************************************
 * METHOD DisplayTable: Sheep Class
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

void Sheep::displayTable()const
{
	string wool;

	switch(woolType)
	{
		case LONG:

					wool = "Long";

					break;

		case MEDIUM:

					wool = "Medium";

					break;

		case FINE:

					wool = "Fine";

					break;

		case CARPET:

					wool = "Carpet";

					break;

		default:

					wool = "No Information";

					break;
	}

	sheep.displayTable();

	cout << left;
	cout << setw(9) << wool << " ";
	cout << setw(5) << woolColor;
}



