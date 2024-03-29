/************************************************************
* AUTHOR	 : Ali Eshghi
* STUDENT ID : 1112261
* LAB #14	 : Inheritance, Overloading, & Redefining
* CLASS		 : CS 1B
* SECTION	 : MW - 7:30 pm - 9:50 pm
* DUE DATE	 : 12/12/2019
*************************************************************/

#include "AnimalClass.h"
#include "PigClass.h"

using namespace std;

/*******************************************
 * Pig()
 * Constructor: Class attribute initializer
 * Parameters:  None
 * Return:      None
 *******************************************/

Pig::Pig()
{
	tailType = NONE;
}


/*******************************************
 * ~Pig()
 * Destructor: Does not perform anything
 * Parameters: None
 * Return:     None
 *******************************************/

Pig::~Pig()
{

}


/******************************************************************************
 *  METHOD SetValues: Pig Class
 * ____________________________________________________________________________
 *  This Method inputs the new sheep info into the object.
 *
 *  => returns nothing.
 * ____________________________________________________________________________
 * PRE-CONDITIONS:
 *
 * 		string name:  pig name
 *      int age:      pig age
 *      string tail:  pig tail
 *
 * POST-CONDITIONS:
 *
 *		None
 *
 ******************************************************************************/

void Pig::setValues(string name, //IN & CALC - PIG NAME
					int age, 	 //IN & CALC - PIG AGE
					string tail) //IN & CALC - PIG TAIL

{
	pig.setValues(name, age);

	if(tail == "STRAIGHT")
	{
		tailType = STRAIGHT;
	}

	else if(tail == "CORKSCREW")
	{
		tailType = CORKSCREW;
	}

	else if(tail == "CURL UP")
	{
		tailType = CURL_UP;
	}

	else if(tail == "CURL RIGHT")
	{
		tailType = CURL_RIGHT;
	}

	else if(tail == "CURL LEFT")
	{
		tailType = CURL_LEFT;
	}
}


/******************************************************************************
 *  METHOD ChangeAge: Pig Class
 * ____________________________________________________________________________
 *  This Method receives a an age input and replace it with pig age.
 * ____________________________________________________________________________
 * PRE-CONDITIONS:
 *
 * 		int age: pig age
 *
 * POST-CONDITIONS:
 *
 * 		None
 ******************************************************************************/

void Pig::changeAge(int age) 	//IN & CALC - PIG AGE
{
	pig.setValues(age);
}


/******************************************************************************
 *  METHOD GetName: Pig Class
 * ____________________________________________________________________________
 *  This Method displays spig's name.
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

string Pig::getName()const
{
	return (pig.getName());
}


/******************************************************************************
 *  METHOD TableHeader: Pig Class
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

void Pig::tableHeader()const
{
	pig.tableHeader();
	cout << left;
	cout << setw(10) << "TAILTYPE" <<" ";
}


/*****************************************************************************
 * METHOD TableHeaderLine: Pig Class
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

void Pig::tableHeaderLine()const
{
	pig.tableHeaderLine();

	cout << setfill('-');
	cout << right;
	cout << setw(12) << " ";
	cout << setfill(' ');
}


/*****************************************************************************
 * METHOD DisplayTable: Pig Class
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

void Pig::displayTable()const
{
	string tail;

	switch(tailType)
	{
		case STRAIGHT:

			tail = "Straight";

				break;

		case CORKSCREW:

				tail = "Corkscrew";

				break;

		case CURL_UP:

				tail = "Curl Up";

				break;

		case CURL_RIGHT:

				tail = "Curl Right";

				break;

		case CURL_LEFT:

				tail = "Curl Left";

				break;

		case NONE:

				tail = "Unprovided";

				break;
	}

	pig.displayTable();

	cout << left;
	cout << setw(10) << tail;

}








