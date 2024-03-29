/************************************************************
* AUTHOR	 : Ali Eshghi
* STUDENT ID : 1112261
* LAB #14	 : Inheritance, Overloading, & Redefining
* CLASS		 : CS 1B
* SECTION	 : MW - 7:30 pm - 9:50 pm
* DUE DATE	 : 12/12/2019
*************************************************************/

#ifndef PIGCLASS_H_
#define PIGCLASS_H_

#include "AnimalClass.h"

using namespace std;

/******************************************
 * PIG CLASS
 *
 * This class is for sheep objects.
 *
 * It manages two attributes:
 * - tail type
 ******************************************/

class Pig:public Animal
{


			/******************************
			 *   CONSTRUCTOR/DESTRUCTOR   *
			 ******************************/

	public:

		/*******************************************
		 * Pig()
		 * Constructor: Class attribute initializer
		 * Parameters: None
		 * Return:     None
		 *******************************************/

		Pig();


		/*******************************************
		 * ~Pig()
         * Destructor: Does not perform anything
		 * Parameters: None
	     * Return:     None
	     *******************************************/

		~Pig();


					/****************
					 *   Mutators   *
					 ****************/


		/*******************************************
        * SetValues(string, int, string)
        * Mutator: Updates Pig object
        * ----------------------------------------
        * Parameters:
        *
        * - name (string)
        * - age (int)
        * - tail (string)
        * ----------------------------------------
        * Return: None
        ********************************************/

		void setValues(string name, int age, string tail);


		/*******************************************
		 * ChangeAge(int)
         * Mutator: changes the age of target
         * ----------------------------------------
         * Parameters: age(int)
		 * ----------------------------------------
		 * Return:     None
		 *******************************************/

		void changeAge(int age);


		/*******************************************
		 * GetName() const
		 * Accessor: Receives the age of the animal.
		 * ----------------------------------------
		 * Parameters: None
		 * ----------------------------------------
		 * Return:     name
		 *******************************************/

		string getName()const;


		/*******************************************
		 * TableHeader() const
		 * Accessor: Displays the top line
		 * 			  table.
		 * ----------------------------------------
         * Parameters: None
         * ----------------------------------------
         * Return:     None
         *******************************************/

		void tableHeader()const;


		/*******************************************
         * TableHeaderLine() const
         * Accessor: Displays the table prompt
         * ----------------------------------------
         * Parameters: None
         * ----------------------------------------
         * Return:     None
         ******************************************/

		void tableHeaderLine()const;


		/*******************************************
		 * DisplayTable() const
         * Accessor: displays the related data
		 * ----------------------------------------
		 * Parameters: None
		 * ----------------------------------------
		 * Return:     None
		 ******************************************/

		void displayTable()const;


	private:


		//ENUM FOR TAIL TYPE AS REQUESTED

		enum TailType
		{
			NONE,
			STRAIGHT,
			CORKSCREW,
			CURL_UP,
			CURL_RIGHT,
			CURL_LEFT
		};

		Animal 	 pig; 		//PIG OBJECT

		TailType tailType;	//TAIL TYPE

};

#endif /* PIGCLASS_H_ */
