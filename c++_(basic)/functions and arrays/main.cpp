/******************************************************************************
 * PROGRAMMER : Ali Eshghi & Ivan Ma
 * STUDENT ID : 1112261    & 1114811
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Assign #1  : Functions and arrays
 * DUE DATE   : 19 September 2019
 *****************************************************************************/
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main()
{

	/**************************************************************************
	* CONSTANTS
	* ------------------------------------------------------------------------
	* OUTPUT - USED FOR CLASS HEADING
	* ------------------------------------------------------------------------
	* PROGRAMMER  : Programmer's Name
	* CLASS	   	  : Student's Course
	* SECTION	  : Class Days and Time
	* LAB_NUM	  : Lab Number (specific to this lab)
	* LAB_NAME    : Title of the Lab
	* AS_TYPE	  : Type of the assignment (Lab or Assignment)
		*************************************************************************/
	const string PROGRAMMER	  = "Ali Eshghi & Ivan Ma";
	const string CLASS  	  = "CS1B";
	const string SECTION	  = "MW: 7:30p - 9:50p";
	const int    LAB_NUM	  = 4;
	const string LAB_NAME	  = "Lab 4 : Introduction to array";


	cout << left;
	cout << "***************************************************"    	 << endl;
	cout << "*  PROGRAMMED BY : " << PROGRAMMER				     	     << endl;
	cout << "*  "	  << setw(14) << "CLASS"	 << ": " << CLASS  	     << endl;
	cout << "*  "	  << setw(14) << "SECTION"   << ": " << SECTION	     << endl;
	cout << "*  LAB #"<< setw(9)  << LAB_NUM     << ": " << LAB_NAME     << endl;
	cout << "***************************************************"<< endl << endl;
	cout << right;


	/*************
	 * VARIABLES *
	 ************/
	const int AR_SIZE = 10;  // PROCESS - const for the number elements of the array

	int index;				 // PROCESS - used in the loops to put variables in array
	int nameCount;			 // Process - used for the count of instances

	string nameAr[AR_SIZE];  // IN & PROCESS - array of the names, user input
	string searchName;		 // IN & PROCESS - name for the search, user input



	/**************************************************************************
	* INPUT - begin to prompt ask the user for the names that are going to
	* 		  be in the array and initialize the array based on the user input
	* 		  using a for loop.
	*************************************************************************/

	for(index = 0; index <AR_SIZE; index++) //gets the names from the user
	{
		cout << "Enter name #" << index+1 << ": ";
		getline(cin,nameAr[index]);
	}//end of for loop

	/*************************************************************************
	* PROCESS & OUTPUT - the program asks the user what name's instances the
	* 					 user is looking for and outputs the name searched and
	* 					 the number of the instances of the name in the list.
	**************************************************************************
	* 					 the program gets the user input and based on the
	* 					 user's input it search for the name in the array and
	* 					 if the program finds it it outputs the name and the
	* 					 number of instances, but if the searched name wasn't
	* 					 in the list, the program outputs that the program
	* 					 couldn't find the name.
	*************************************************************************/

	cout << endl << endl;
	cout << "Who do you want to search for (Enter done to exit)? ";
	getline(cin,searchName);


	while(searchName != "done")//using the while loop because we never know
	{						   //when the search ends.
		nameCount = 0;

		for (index = 0; index < AR_SIZE; index++)//for loop to search the
		{										 //the name in the array.
			if(searchName == nameAr[index])//if the name found it increments
			{							   //the instances.
				nameCount++;
			}// end of if statement
		}//end of while loop

		if (nameCount != 0)//if there are any instances,
		{				   // it follows the statement below.
			if (nameCount > 1)//if the instances are more than one,
			{				  //the statement below occurs.
				cout << "There are " << nameCount   << " instances of the name "
					 << searchName   << "." << endl << endl;
			}//end of if statement

			if (nameCount == 1)//if there is only instances, statement below occurs.
			{
				cout << "There is one instance of the name " << searchName << "."
					 << endl << endl;
			}//end of if statement
		}
		else//else statement if the name isn't in the list.
		{
			cout << searchName << "\'s name does not exist in this list." << endl << endl;
		}//end of else statement.



		//prompts the user for another input(change the input for the loop).
		cout << "Who do you want to search for (Enter done to exit)? ";
		getline(cin,searchName);


	}

	//output to shows the user the program ended perfectly.
	cout << "\nThank you for using my program.";

	return 0;

}

