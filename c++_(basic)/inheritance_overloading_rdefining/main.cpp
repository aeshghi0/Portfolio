/************************************************************
* AUTHOR	 : Ali Eshghi
* STUDENT ID : 1112261
* LAB #14	 : Inheritance, Overloading, & Redefining
* CLASS		 : CS 1B
* SECTION	 : MW - 7:30 pm - 9:50 pm
* DUE DATE	 : 12/12/2019
*************************************************************/

#include "MyHeader.h"


/*****************************************************************************
 * Inheritance, Overloading, & Redefining
 * ---------------------------------------------------------------------------
 * This program will create a list of animals, based on the input file,
 * 	using linked lists.
 * ---------------------------------------------------------------------------
 * VARIABLES
 * ---------------------------------------------------------------------------
 * 	- option1: 		menu option for introduction menu
 * 	- option2: 		menu option for the main menu
 *  - option3: 		updated option from the user
 *  - animalType:   choice of which animal
 *  - animalOption: second choice of animal
 *  - sheepNode:    sheep node
 *  - pigNode:      pig node
 *****************************************************************************/

int main()
{
	/********************************************************
	* CONSTANTS
	* ----------------------------------------------------
	* USED FOR CLASS HEADING – ALL WILL BE OUTPUT
	* ----------------------------------------------------
	* Type	   : Program Type
	* LAB_NUM  : Lab Number (specific to this lab)
	* LAB_NAME : Title of the Lab
	*********************************************************/

	const int  LAB_NUM		= 14;
	const char TYPE			= 'L';
	const char LAB_NAME[39] = "Inheritance, Overloading, & Redefining";


	/********************************************************
	 * 						 VARIABLE
	 ********************************************************/

	//INTEGER

    int option1;			//IN & CALC - menu option for introduction menu
    int animalOption;		//IN & CALC - second choice of animal


    //CHARCTER

    char option3;			//IN & CALC - updated option from the user
    char animalType;		//IN & CALC - choice of which animal


    //OTHERS

    Menu 		option2;		//IN & CALC - menu option for the main menu
    sheepList   *sheepNode;		//CALC - sheep node
	pigList	    *pigNode; 		//CALC - pig node


	/********************************************************
	 * 					  OUTPUT HEADING
	 ********************************************************/

	//PRINT PROGRAM HEADER

	PrintHeader(LAB_NAME, TYPE, LAB_NUM);


	/********************************************************
	 * 						   INPUT
	 ********************************************************/

	//DISPLAYS FUNCTION AND INPUT THE USER OPTION

	option1 = InputMenu();

	//PROGRAM WILL FUNCTION BASED ON USER'S DATA

	switch(option1)
	{
		//EXITS THE PROGRAM

		case 0:

			break;

		//STARTS THE PROGRAM

		case 1:

			sheepNode = InputSheepList();

			pigNode   = InputPigList();

			cout << "Setting up the animals...";
			cout << endl << endl;

			break;
	}

	/********************************************************
	 * 						PROCESSING
	 ********************************************************/

	if(option1 != 0)
	{
		do
		{
			option2 = MainMenu();

			switch(option2)
			{

				case REINIT_SHEEP:

					option3 = Update();

					if(option3 == 'Y')
					{
						sheepNode = InputSheepList();

						cout << "\nSetting up for Sheeps..." << endl;
					}

					else
					{
						cout << "\nSheep have not been re-initialized!";

						cout << endl;
					}

					break;


				case REINIT_PIGS:

					option3 = Update();

					if(option3 == 'Y')
					{
						pigNode = InputPigList();

						cout << "\nSetting up for Pigs..." << endl;
					}

					else
					{
						cout << "\nPig have not been re-initialized!";

						cout << endl;
					}

					break;


				case CHANGE_AGE:

					animalType = ChooseAnimal();

					if(animalType == 'S')
					{
						animalOption = TargetSheep(sheepNode);

						ChangeAgeSheep(sheepNode, animalOption);
					}

					else
					{
						animalOption = TargetPig(pigNode);

						ChangeAgePig(pigNode, animalOption);
					}

					break;


				case DISPLAY:

					SheepDisplay(sheepNode);

					cout << endl << endl;

					PigDisplay(pigNode);

					break;


				case EXIT:

					break;
			}

			cout << endl << endl;

		}while(option2 != EXIT);
	}

	return 0;
}
