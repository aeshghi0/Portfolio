/************************************************************
* AUTHOR	 : Ali Eshghi
* STUDENT ID : 1112261
* LAB #14	 : Inheritance, Overloading, & Redefining
* CLASS		 : CS 1B
* SECTION	 : MW - 7:30 pm - 9:50 pm
* DUE DATE	 : 12/12/2019
*************************************************************/

#ifndef SHEEPCLASS_H_
#define SHEEPCLASS_H_

#include "AnimalClass.h"

using namespace std;

/******************************************
 * THE SHEEP CLASS
 *
 *  This class is for sheep objects.
 *
 * It manages two attributes:
 * - WoolType
 * - WoolColor
 ******************************************/

class Sheep:public Animal
{

			/******************************
			 *   CONSTRUCTOR/DESTRUCTOR   *
			 ******************************/

	public:

		/*******************************************
		 * Sheep()
		 * Constructor: Class attribute initializer
		 * Parameters: None
		 * Return:     None
		 *******************************************/

		Sheep();


		/*******************************************
		 * ~Sheep()
         * Destructor: Does not perform anything
		 * Parameters: None
	     * Return:     None
	     *******************************************/

		~Sheep();


					/****************
					 *   Mutators   *
					 ****************/


		/*******************************************
		 * SetValues(string, int)
		 * Mutator: Update Animals
		 * ----------------------------------------
		 * Parameters: name(string), age(int)
		 * ----------------------------------------
		 * Return:     None
		 *******************************************/

		void setValues(string name, 	//IN & CALC - SheepName
					   int age, 		//IN & CALC - SheepAge
					   string type, 	//IN & CALC - Wool Type
					   string color); 	//IN & CALC - Wool Color


		/*******************************************
		 * ChangeAge(int)
         * Mutator: changes the age of target
         * ----------------------------------------
         * Parameters: age(int)
		 * ----------------------------------------
		 * Return:     None
		 *******************************************/

		void changeAge(int age); //CALC - Sheep Age


					/*****************
					 *   ACCESSORS   *
					 *****************/

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


		//ENUM FOR WOOL TYPE AS REQUESTED

		enum WoolType
		{
			NONE,
			LONG,
			MEDIUM,
			FINE,
			CARPET
		};

		Animal	 sheep;	        //ANIMAL OBJECT

		WoolType woolType;		//WOOL TYPE
		string   woolColor;     //WOOL COLOR

};

#endif /* SHEEPCLASS_H_ */
