/***********************************************
 * PROGRAMMER : Ali Eshghi & Jonathan Aguirre
 * STUDENT ID : 1112261 & 1094753
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * LAB #6     : Structs
 * DUE DATE   : 1 October 2019
 ***********************************************/
#ifndef MYHEADER_H_
#define MYHEADER_H_

#include <iostream> // input output
#include <iomanip>  // Calculations
#include <stdio.h>  //
#include <fstream>  // input and output files
#include <string>   // strings
#include <sstream>  // ostringstream
using namespace std;


struct information
{
	string name;
	int	   balance;
	int	   id;
};

/******************************************************************************
 * Function : PrintHeader
 * ---------------------------------------------------------------------------
 * This function stores the header file into a string variable and returns that
 * string variable to a string variable in the main called "header"
 *****************************************************************************/

string PrintHeader(const string PROGRAMMER,
				   const string CLASS,
				   const string SECTION,
				   const int    ASSIGN_NUM,
				   const string ASSIGN_NAME);


/******************************************************************************
 * Function : Input
 * ---------------------------------------------------------------------------
 * This function gets the data from the input file and puts them in order in
 * the parallel arrays for the name, id, and balance using a while loop. This
 * is a void type function, so it doesn't need any return.
 *****************************************************************************/

void Input(ifstream &inFile,
		   const int AR_SIZE,
		   struct information personalData[]);


/******************************************************************************
 * Function : SearchBalance
 * ---------------------------------------------------------------------------
 * This function searches for the largest or smaller balance in the balance
 * array using a for loop and then returns an integer type variable as the
 * index of the  larger balance in the array to an integer type variable in
 * the main named "balanceIndex".
 *****************************************************************************/

int SearchBalance(struct information personalData[],
				  int option,
				  const int AR_SIZE);


/******************************************************************************
 * Function : SumOrAvg
 * ---------------------------------------------------------------------------
 * This function gets all the balances from the list using a for loop
 * and add them up together to get the sum and average of all the balances.
 * then returns a float type variable to a float variable in the main called
 * "sumOrAvg".
 *****************************************************************************/

float SumOrAvg(struct information personalData[],
			   int option,
			   const int AR_SIZE);


/******************************************************************************
 * Function : SearchName
 * ---------------------------------------------------------------------------
 * This function prompts the user that who is the user searching for and uses
 * while loop and an boolean expression to check the name array and if the name
 * was found, returns the index of the array to be used in the parallel arrays
 * and if the name was not found, lets the user know
 *****************************************************************************/

int SearchName(struct information personalData[], const int AR_SIZE);


/******************************************************************************
 * Function : FileOutput
 * ---------------------------------------------------------------------------
 * This function will out put the results that were assigned to variables in
 * the main from the other functions to the output file. the function is a void
 * type function, so it doesn't need any return.
 *****************************************************************************/

void FileOutput(ostream &outFile,
				struct information personalData[],
				int      option,
				int		 balanceIndex,
				float	 sumOrAvg,
				int		 nameIndex);

#endif /* MYHEADER_H_ */
