/************************************************************
* AUTHOR	 : Ali Eshghi
* STUDENT ID : 1112261
* LAB #14	 : Inheritance, Overloading, & Redefining
* CLASS		 : CS 1B
* SECTION	 : MW - 7:30 pm - 9:50 pm
* DUE DATE	 : 12/12/2019
*************************************************************/

#ifndef ANIMALCLASS_H_
#define ANIMALCLASS_H_

// Preprocessor Directives

#include <iostream>
#include <iomanip>

using namespace std;

/************************************************************
 * AnimalClass
 ************************************************************
 * This class represents an animal object.
 *
 * It manages two attributes:
 * - name
 * - age
 ************************************************************/

class Animal
{

	public:

			/******************************
			 *  CONSTRUCTOR / DESTRUCTOR  *
			 ******************************/

		/*******************************************
		 * Animal()
		 * Constructor: Class attribute initializer
		 * Parameters:  None
		 * Return:      None
		 *******************************************/

		Animal();


		/*******************************************
		 * ~Animal()
		 * Destructor: Does not perform anything
		 * Parameters: None
		 * Return:     None
		 *******************************************/

		~Animal();


					/****************
					 *   Mutators   *
					 ****************/


		/*******************************************
         * SetValues1(string, int)
         * Mutator: Update Animals
		 * ----------------------------------------
		 * Parameters: name(string), age(int)
		 * ----------------------------------------
         * Return:     None
         *******************************************/

		void setValues(string animalName, int animalAge);


		/*******************************************
		 * SetValues2(string)
		 * Mutator: Updates Animals
		 * ----------------------------------------
		 * Parameters: name(string)
		 * ----------------------------------------
		 * Return:     None
		 *******************************************/

		void setValues(string animalName);


		/*******************************************
		 * SetValues3(int)
		 * Mutator: Updates Animals
		 * ----------------------------------------
		 * Parameters: age(int)
		 * ----------------------------------------
		 * Return:     None
		 *******************************************/

		void setValues(int animalAge);


		/*****************
		 *   ACCESSORS   *
		 *****************/

		/*******************************************
	 	 * TableHeader() const
	 	 * Accessor: Sets up the table
	 	 * ----------------------------------------
         * Parameters: None
         * ----------------------------------------
         * Return:     name
         *******************************************/

		void tableHeader()const;


		/*******************************************
		 * TableHeader() const
		 * Accessor: Displays the table prompt
		 * ----------------------------------------
         * Parameters: None
         * ----------------------------------------
         * Return:     name
         *******************************************/

		void tableHeaderLine()const;


		/*******************************************
         * tableHeaderLine() const
         * Accessor: Displays the table setting
		 * ----------------------------------------
		 * Parameters: None
		 * ----------------------------------------
         * return:     name
         ******************************************/

		void displayTable()const;


		/*******************************************
         * GetName() const
         * Accessor: Receives the name of the animal.
         * ----------------------------------------
         * Parameters: None
         * ----------------------------------------
         * Return:     name
         ******************************************/

		string getName()const;


		/*******************************************
		 * GetAge(int)
         * Mutator: Receives the age of the animal.
         * ----------------------------------------
         * Parameters:  None
         * ----------------------------------------
         * Return:      age
         *******************************************/

		int getAge()const;


	private:

		string name;	//Animal Name
		int    age; 	//Animal Age

};

#endif /* ANIMALCLASS_H_ */
