/*******************************************************************************
 * PROGRAMMER : Ali Eshghi & Amirarsalan Valipour
 * STUDENT ID : 1112261 & 1103126
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Assign #2  : Intro to OOP
 * DUE DATE   : 19 September 2019
 ******************************************************************************/

#include "MyHeader.h"
#include "ClassHeader.h"

/*******************************************************************************
* Lab 12
* ------------------------------------------------------------------------------
* This program uses the class and initializes the objects of the class using
* methods. then based on the user's choice the objects' values can be changed
* or get reinitialized to the first values.
* ------------------------------------------------------------------------------
* INPUT  : firstMenuOption -> The first choice that initializes the objects
* 							  or exits the program
* 		   menuChoice      -> choice of the user to change the age or value,
* 		   					  reinitialize, or display the data
* 		   newAge          -> change the value of the object age of the class
* 		   newValue        -> change the value of the object value of the class
* ------------------------------------------------------------------------------
* PROCESS: Initializing objects
* 		   Getting the first choice for the first menu
* 		   Getting the choice for the main menu
* 		   changing the age
* 		   changing the value
* ------------------------------------------------------------------------------
* OUTPUT : the values of the object variables of the class
*******************************************************************************/
int main()
{
	/***************************************************************************
	* CONSTANTS
	* --------------------------------------------------------------------------
	* OUTPUT - USED FOR CLASS HEADING
	* --------------------------------------------------------------------------
	* PROGRAMMER  : Programmer's Name
	* CLASS	   	  : Student's Course
	* SECTION	  : Class Days and Time
	* LAB_NUM	  : Lab Number (specific to this lab)
	* LAB_NAME    : Title of the Assignment
	***************************************************************************/
	const string PROGRAMMER	= "Ali Eshghi and Amirarsalan Valipour";
	const string CLASS		= "CS1B";
	const string SECTION	= "MW: 7:30p - 9:50p";
	const int    LAB_NUM	= 12;
	const string LAB_NAME   = "Intro to OOP";

	/*************
	 * VARIABLES *
	 *************/

	int 	startOption;  //IN - choice of the first menu
	int		menuOption;   //IN - choice of the main menu
	int		animalOption; //IN - choice of which animal

	bool	checkInp;     //PROCESS - input checking

	char	initialSure;  //IN - choice of reinitializing

	int age1;			  //PROCESS & OUT - age for Fluffy
	int age2;			  //PROCESS & OUT - age for Maa
	int ageP;			  //PROCESS & OUT - age for Babe

	float value1;		  //PROCESS & OUT - value for Fluffy
	float value2;		  //PROCESS & OUT - value for Maa
	float valueP;		  //PROCESS & OUT - value for Babe

	string name1;		  //OUT - name for Fluffy
	string name2;		  //OUT - name for Maa
	string nameP;		  //OUT - name for Babe

	string type1;		  //OUT - animal type for Fluffy
	string type2;		  //OUT - animal type for Maa
	string typeP;		  //OUT - animal type for Babe


	Sheep1 fluffy;		  //PROCESS - variable for class Sheep1
	Sheep2 maa;			  //PROCESS - variable for class Sheep2
	Pig	   babe;		  //PROCESS - variable for class Pig


	/*************
	 *  PROCESS  *
	 *************/
	//this function will print header to the screen
	PrintHeader(PROGRAMMER, CLASS, SECTION, LAB_NUM, LAB_NAME);

	//This function gets the user choice for the first menu to initialize or
	//exit the program
	startOption = FirstMenu();

	//if for the first choice that initializes the objects
	if(startOption == 1)
	{
		cout << "\nInitializing Fluffy, Maa, and Babe..." << endl << endl;

		/**************
		 * INITIALIZE *
		 **************/

		age1 = 1;
		age2 = 3;
		ageP = 2;

		value1 = 15000.00;
		value2 = 16520.35;
		valueP = 10240.67;

		name1  = "Fluffy";
		name2  = "Maa";
		nameP  = "Babe";

		type1  = "Sheep";
		type2  = "Sheep";
		typeP  = "Pig";


		//methods for the three class that initializes the objects of the class

		fluffy.SetTypeSheep1(type1);
		fluffy.SetNameSheep1(name1);
		fluffy.SetAgeSheep1(age1);
		fluffy.SetValueSheep1(value1);

		maa.SetTypeSheep2(type2);
		maa.SetNameSheep2(name2);
		maa.SetAgeSheep2(age2);
		maa.SetValueSheep2(value2);

		babe.SetTypePig(typeP);
		babe.SetNamePig(nameP);
		babe.SetAgePig(ageP);
		babe.SetValuePig(valueP);

	}



	//while loop for the main menu untill the choice 0 is entered
	while(startOption != 0 || menuOption != 0)
	{
		//this function will get the user's choice for the main menu
		menuOption = Menu();

		//if statement for the first option
		if(menuOption == 1)
		{
			checkInp = false;

			do
			{
				//INPUT - asks user if they are sure for reinitialization


				cout << "Are you sure you want to reinitialize (Y/N)?";
				cin.get(initialSure);


				//CHECKS FOR THE CHAR INPUT

				if (toupper(initialSure) != 'Y' && toupper(initialSure) != 'N')
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					cout << endl;
					cout << "**** "<< initialSure
						 << " is an invalid entry     ****" << endl;
					cout << "**** Please input Y or N ****";
					cout << endl << endl;

					checkInp = false;


				}

				else
				{

					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					checkInp = true;

				}

			}while(!checkInp);

			//if statement for reinitializing the classes to the first values
			if(toupper(initialSure) == 'Y')
			{
				cout << "\nInitializing Fluffy, Maa, and Babe..." << endl
					 << endl;

				age1 = 1;
				age2 = 3;
				ageP = 2;

				value1 = 15000.00;
				value2 = 16520.35;
				valueP = 10240.67;

				name1 = "Fluffy";
				name2 = "Maa";
				nameP = "Babe";

				type1 = "Sheep";
				type2 = "Sheep";
				typeP = "Pig";

				fluffy.SetTypeSheep1(type1);
				fluffy.SetNameSheep1(name1);
				fluffy.SetAgeSheep1(age1);
				fluffy.SetValueSheep1(value1);

				maa.SetTypeSheep2(type2);
				maa.SetNameSheep2(name2);
				maa.SetAgeSheep2(age2);
				maa.SetValueSheep2(value2);

				babe.SetTypePig(typeP);
				babe.SetNamePig(nameP);
				babe.SetAgePig(ageP);
				babe.SetValuePig(valueP);


			}

			else if(toupper(initialSure) == 'N')
			{
				cout << "Animals have not beenre-initialized!" << endl <<endl;
			}



		}

		//if statement for the second option of the menu
		else if(menuOption == 2)
		{
			checkInp = false;


			//do while loop for user input for which animal they want to change
			do
			{
				//INPUT
				cout << "\nCHANGE AGE:" << endl;
				cout << "1 - Fluffy"    << endl;
				cout << "2 - Maa"       << endl;
				cout << "3 - Babe"      << endl;

				cout << "Select the animal you'd like to change: ";


				//CHECKS FOR THE CHAR INPUT

				if (!(cin >> animalOption))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					cout << endl;
					cout << "**** Please input a NUMBER between 1 and 3 ****";
					cout << endl << endl;

					checkInp = false;

				}

				//CHECKS FOR THE RANGE ERROR

				else if (animalOption >= 4 || animalOption <= 0 )
				{

					cout << endl;
					cout << "**** The number "              << animalOption
					<< " is an invalid entry     ****" << endl;
					cout << "**** Please input a number between 1 and 3 ****";
					cout << endl << endl;

					checkInp = false;

				}

				//PASS

				else
				{

					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					checkInp = true;

				}

			}while(!checkInp);


			//if statement if the user wants to change the age for Fluffy
			if(animalOption == 1)
			{

				age1 = ChangeAge();

				cout << "\nChanging Fluffy's age to " << age1 << "..." << endl
					 << endl;

				fluffy.SetAgeSheep1(age1);
			}

			//if statement if the user wants to change the age for Maa
			else if(animalOption == 2)
			{
				age2 = ChangeAge();

				cout << "\nChanging Maa's age to " << age2 << "..." << endl
					 << endl;

				maa.SetAgeSheep2(age2);
			}

			//if statement if the user wants to change the age for Babe
			else if(animalOption == 3)
			{
				ageP = ChangeAge();

				cout << "\nChanging Babe's age to " << ageP << "..." << endl
					 << endl;

				babe.SetAgePig(ageP);
			}
		}

		//if statement for the third option of the main menu
		else if(menuOption == 3)
		{
			checkInp = false;

			cout << "\nCHANGE Value:" << endl;

			//do while loop for user input for which animal the user wants to
			//change
			do
			{
				//INPUT

				cout << "1 - Fluffy" << endl;
				cout << "2 - Maa"    << endl;
				cout << "3 - Babe"   << endl;

				cout << "Select the animal you'd like to change: ";


				//CHECKS FOR THE CHAR INPUT

				if (!(cin >> animalOption))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					cout << endl;
					cout << "**** Please input a NUMBER between 1 and 3 ****";
					cout << endl << endl;

					checkInp = false;

				}

				//CHECKS FOR THE RANGE ERROR

				else if (animalOption >= 4 || animalOption <= 0 )
				{

					cout << endl;
					cout << "**** The number "              << animalOption
					<< " is an invalid entry     ****" << endl;
					cout << "**** Please input a number between 1 and 3 ****";
					cout << endl << endl;

					checkInp = false;

				}

				//PASS

				else
				{

					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					checkInp = true;

				}

			}while(!checkInp);


			//if statement if the user wants to change value for Fluffy
			if(animalOption == 1)
			{
				value1 = ChangeValue();

				cout << "\nChanging Fluffy's value to " << value1 << "..."
					 << endl << endl;

				fluffy.SetValueSheep1(value1);
			}


			//if statement if the user wants to change value for Maa
			else if(animalOption == 2)
			{
				value2 = ChangeValue();

				cout << "\nChanging Maa's value to " << value2 << "..." << endl
					 << endl;


				maa.SetValueSheep2(value2);
			}


			//if statement if the user wants to change value for Babe
			else if(animalOption == 3)
			{
				valueP = ChangeValue();

				cout << "\nChanging Babe's value to " << valueP << "..." << endl
					 << endl;


				babe.SetValuePig(valueP);
			}
		}

		//if statement for the fourth option of the menu
		else if(menuOption == 4)
		{

			cout << endl;
			cout << left;
			cout << setw(11) << "ANIMAL" << setw(15) << "NAME" << setw(7)
				 << "AGE" << setw(8) << "VALUE" << endl;
			cout << "---------- " << "-------------- " << "--- "
				 << "-----------"
				 << endl;

			//these methods outputs the objects of the classes

			fluffy.PrintSheep1(name1, type1, age1, value1);

			maa.PrintSheep2(name2, type2, age2, value2);

			babe.PrintPig(nameP, typeP, ageP, valueP);

			cout << endl << endl;
		}
	}


	return 0;
}

