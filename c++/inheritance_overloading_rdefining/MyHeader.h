/************************************************************
* AUTHOR	 : Ali Eshghi
* STUDENT ID : 1112261
* LAB #14	 : Inheritance, Overloading, & Redefining
* CLASS		 : CS 1B
* SECTION	 : MW - 7:30 pm - 9:50 pm
* DUE DATE	 : 12/12/2019
*************************************************************/

#ifndef MYHEADER_H_
#define MYHEADER_H_

// Preprocessor Directives

#include <fstream>
#include <sstream>
#include "SheepClass.h"
#include "PigClass.h"

using namespace std;


// User Defined Types go here (more on this later)

enum Menu	//MENU OPTION
{
	EXIT,
	REINIT_SHEEP,
	REINIT_PIGS,
	CHANGE_AGE,
	DISPLAY
};


struct sheepList
{
	Sheep sheep;
	sheepList *next;
};


struct pigList
{
	Pig pig;
	pigList *next;
};


// Prototypes go here

/****************************************************************
 * PrintHeader
 *    This function receives receives an assignment name, type
 *     and number then outputs the appropriate header
 *
 *     - returns  nothing -> This will output the class heading.
 ****************************************************************/

void PrintHeader(string asName,  // IN - assignment Name
				 char   asType,  // IN - assignment type
				 	 	 	 	 //      (LAB or ASSIGNMENT)
				 int    asNum);  // IN - assignment number

/******************************************************************************
 * InputMenu
 * 		This function will prompt the user with menu and get and check their
 * 	     user input.
 *
 *    - returns -> option1
 ******************************************************************************/


int InputMenu();


/******************************************************************************
 * MainMenu
 * 	 This function receives displays the main menu of the program, prompts and
 *    receives an choice from the user, error checks that input and returns the
 *    enumerated menu variable to the main menu.
 *
 *   - returns -> option2
 ******************************************************************************/

Menu MainMenu();



/******************************************************************************
 * InputSheepList
 * 		This function will input the related data into the sheep object.
 *
 * - returns -> sheepNode
 ******************************************************************************/

sheepList *InputSheepList();


/******************************************************************************
 * InputPigList
 * 		This function will input the related data into the pig object.
 *
 * - returns -> pigNode
 ******************************************************************************/

pigList *InputPigList();


/******************************************************************************
 * Update
 * 		This function will update the info based on user's data.
 *
 * - returns -> opion3
 ******************************************************************************/

char Update();


/******************************************************************************
 * ChooseAnimal
 * 	This function ask users to choose the animal they want to choose.
 *
 * 	- returns -> animalType
 ******************************************************************************/

char ChooseAnimal();


/******************************************************************************
 * TargetSheep
 *  This function will ask user to choose their target sheep.
 *
 * -return -> animalOption
 ******************************************************************************/

int TargetSheep(sheepList *head);	//PROC - sheep node


/******************************************************************************
 * TargetPig
 *  This function will ask user to choose their target pig.
 *
 * -return -> animalOption
 ******************************************************************************/

int TargetPig(pigList *head);	//PROC - pig node


/******************************************************************************
 * ChangeAgeSheep
 *  This function will update the sheep's age based on user data.
 *
 * - returns nothing
 ******************************************************************************/

void ChangeAgeSheep(sheepList *head,  	//PROC - sheep node
					const int option);	//PROC - user target


/******************************************************************************
 * ChangeAgePig
 *  This function will update the pig's age based on user data.
 *
 * - returns nothing
 ******************************************************************************/

void ChangeAgePig(pigList *head,  		//PROC - pig node
				  const int option);	//PROC - user target


/******************************************************************************
 * SheepDisplay
 *  This function will display sheep list.
 *
 * - returns nothing
 ******************************************************************************/

void SheepDisplay(sheepList *head);


/******************************************************************************
 * PigpDisplay
 *  This function will display pig list.
 *
 * - returns nothing
 ******************************************************************************/

void PigDisplay(pigList *head);


#endif /* MYHEADER_H_ */
