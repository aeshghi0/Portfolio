/******************************************************************************
 * PROGRAMMER : Ali Eshghi & Elsa Micklnin
 * STUDENT ID : 1112261    & 1028119
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * LAB #3     : Functions and arrays
 * DUE DATE   : 10 September 2019
 *****************************************************************************/
#include "header.h"


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
		*************************************************************************/
	const string PROGRAMMER	  = "Ali Eshghi & Elsa Micklin";
	const string CLASS  	  = "CS1B";
	const string SECTION	  = "MW: 7:30p - 9:50p";
	const int    ASSIGN_NUM	  = 3;
	const string ASSIGN_NAME  = "Greatest Common Divisor";
	const char   AS_TYPE      = 'L';


	/*************
	 * VARIABLES *
	 ************/

	int num1;		//IN - used for input from user
	int num2;		//IN - used for input from user
	int gcd;		//OUT- outputs the greatest common divisor
	string header;  //OUT- outputs the headerfile
	int index;		//PROCESS- used for the for loop
	string result;  //OUT- string sentence to output file of results


	/**************************************************************************
	* PROCESS & OUTPUT - open output file and output class heading
	*************************************************************************/

	ofstream outFile;

	outFile.open("outPut.txt");

	PrintHeaderFile(outFile, ASSIGN_NAME, AS_TYPE, ASSIGN_NUM, CLASS, SECTION);

	header = PrintHeaderScreen(ASSIGN_NAME, AS_TYPE, ASSIGN_NUM, CLASS, SECTION);

	cout    << header;
	outFile << header;

	/**************************************************************************
	* PROCESS - begin to prompt user for two integers. run set number of times
	*************************************************************************/


	for(index = 1; index <=4; index++)
	{

		/**********************************************************************
		 * INPUT - prompt user for two values
		 *********************************************************************/
		ReadTwoInts(num1, num2);

		/**********************************************************************
		* PROCESS - calculate greatest common divisor
		*********************************************************************/

		gcd = GreatestCommonDivisor(num1, num2);

		/**********************************************************************
		* OUTPUT - make result into string and output to file
		*********************************************************************/

		result = OutputResults(num1, num2, gcd);

		outFile << endl << result;

	}

	cout << "Thank you for using my GCD calculator!\n";
	cout << "--------------------------------------------";

	outFile.close();




	return 0;
}

