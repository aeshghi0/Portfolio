/***********************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Assign #1  : Functions and arrays
 * DUE DATE   : 19 September 2019
 ***********************************************/
#include "MyHeader.h"


int main()
{
	/**************************************************
	* CONSTANTS
	* ------------------------------------------------
	* OUTPUT - USED FOR CLASS HEADING
	* ------------------------------------------------
	* PROGRAMMER  : Programmer's Name
	* CLASS	   	  : Student's Course
	* SECTION	  : Class Days and Time
	* LAB_NUM	  : Lab Number (specific to this lab)
	* LAB_NAME    : Title of the Assignment
	**************************************************/
	const string PROGRAMMER	= "Ali Eshghi";
	const string CLASS		= "CS1B";
	const string SECTION	= "MW: 7:30p - 9:50p";
	const int  ASSIGN_NUM	= 1;
	const string ASSIGN_NAME= "Functions and Arrays";

	/*************
	 * VARIABLES *
	 ************/

	const int AR_SIZE = 10;	 //PROCESS - used for size of arrays.

	ofstream outFile ;		  //OUTPUT  - used to save the output.
	ifstream inFile;		  //INPUT   - gives the data to program.
	string	 inFileName;	  //INPUT   - user input for the infile name.
	string	 outFileName;	  //INPUT   - user input for the outfile name.
	string	 header;		  //OUTPUT  - saves the header file and outputs it.
	int 	 option;		  //IN AND PROCESS - user input for the menu option.
	int 	 balanceIndex;	  //PROCESS - used for the balance search.
	float	 sumOrAvg;		  //PROCESS - used for getting the sum or average.
	int		 nameIndex;		  //PROCESS - used for searching the name.

	string nameAr[AR_SIZE];   //PROCESS - stores the names from the input file.
	int	   idAr[AR_SIZE];	  //PROCESS - stores the id's from the input file.
	float  balanceAr[AR_SIZE];//PROCESS - stores the balances from the input file.

	//the string type variable named "header" saves the header
	//file as a string inside itself, then outputs that.
	header = PrintHeader(PROGRAMMER, CLASS, SECTION, ASSIGN_NUM, ASSIGN_NAME);
	cout    << header;
	outFile << header;

	//the program prompts the user for the input file and output file names
	//and then save them as a string and use that to open the file with the
	//name that the user inputs.
	cout << left;
	cout << setw(40) << "What input file would you like to use?";
	getline(cin,inFileName);
	inFile.open(inFileName.c_str());

	cout << setw(40) << "What output file would you like to use?";
	getline(cin,outFileName);
	outFile.open(outFileName.c_str());

	//The "Input" function gets the data from the input file named by
	//the user and puts them in three parallel arrays to be used in
	//the program.
	Input(inFile, AR_SIZE, nameAr, idAr, balanceAr);


	/**************************************************************************
	* PROCESS & OUTPUT - Open output file and outputs the data based on the
	* 					 options that the user inputed in the program.
	*************************************************************************/

	//The program shows the menu option to the user and prompts the
	//user to which option the user would like to use.
	cout << endl;
	cout << "MENU OPTIONS" << endl 					 << endl;
	cout << "1 - Find the larger balance" 			 << endl;
	cout << "2 - Find the smaller balance"			 << endl;
	cout << "3 - Obtain sum of all balances" 		 << endl;
	cout << "4 - Obtain the average of all balances" << endl;
	cout << "5 - Find Person" 						 << endl;
	cout << "0 - Exit" 								 << endl;

	cout << "Enter an option (0 to exit) : ";
	cin  >> option;

	/**************************************************************************
	* PROCESS - Begins to use if and else statement based on the user input for
	* 			the "option" and chooses the right function to do the work.
	*************************************************************************/

	while (option != 0)//While loop that continues to run the program
	{				   //until the user inputs "0" as an option.

		if (option == 1 || option == 2)//If statement for the first two
		{							   //options, because they are in same
									   //functions.

			//This function gets the index of the larger balance
			//or the smaller balance from the array and returns it
			// to the variable named "balanceIndex".
			balanceIndex = SearchBalance(balanceAr, option, AR_SIZE);

		}//End of the if statement for the first two options

		else if (option == 3 || option == 4)//If statement for the second
		{									//two options because they are
											//in the same function.

			//This function gets the sum or the average of all balances
			// and returns the value to the variable named "sumOrAvg".
			sumOrAvg = SumOrAvg(balanceAr, option, AR_SIZE);

		}//End of if statement for the second two options

		else if (option == 5)//If statement for the last option
		{
			//This function ask the user for who is the user is searching for
			//from the list, then searches for the name in the list and if the
			//name was found, it passes the name's index from the array to the
			//variable named "nameIndex" and prints out "found", if the name
			//doesn't exists in the list, then it prints out the name and
			//"was not found".
			nameIndex = SearchName(nameAr,AR_SIZE);

		}//End of if statement for the last option

		/**********************************************************************
		* OUTPUT - This function outputs the result in the output file.
		*********************************************************************/

		//This function outputs all the data acquired from the arrays by
		//the user from the menu to an output file.
		FileOutput(outFile, nameAr, idAr, balanceAr, option, balanceIndex, sumOrAvg, nameIndex);

		//The program shows the menu again and prompts the user
		//to change the option for the while loop.
		cout << endl;
		cout << "MENU OPTIONS" << endl 					 << endl;
		cout << "1 - Find the larger balance" 			 << endl;
		cout << "2 - Find the smaller balance"			 << endl;
		cout << "3 - Obtain sum of all balances" 		 << endl;
		cout << "4 - Obtain the average of all balances" << endl;
		cout << "5 - Find Person" 						 << endl;
		cout << "0 - Exit" 								 << endl;

		cout << "Enter an option (0 to exit) : ";
		cin  >> option;
	}

	//This message is shown to show the user that the program is done
	//completely and it is terminated.
	cout << "\n\nThank you for using my program.";
	cout << right;


	//These are for closing the files because the program has ended
	inFile.close();
	outFile.close();

	//Returning "0" because of the int main.
	return 0;

}
