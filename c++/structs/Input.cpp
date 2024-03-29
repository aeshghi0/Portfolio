/***********************************************
 * PROGRAMMER : Ali Eshghi & Jonathan Aguirre
 * STUDENT ID : 1112261 & 1094753
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * LAB #6     : Structs
 * DUE DATE   : 1 October 2019
 ***********************************************/
#include "MyHeader.h"

/******************************************************************************
 * Function : Input
 * ---------------------------------------------------------------------------
 * This function gets the data from the input file and puts them in order in
 * the parallel arrays for the name, id, and balance using a while loop. This
 * is a void type function, so it doesn't need any return.
 *****************************************************************************/


void Input(ifstream &iFile,
		   const int AR_SIZE,
		   struct information personalData[])
{
	/*************
	 * VARIABLES *
	 ************/

	int index; //PROCESS - Used for initializing the arrays

	//Initializing the index to 0 for the while loop
	index = 0;

	//This while loop uses the input file and the arrays to
	//get the data from the input file and puts that in the
	//parallel arrays for the names, id's, and balances.
	//This while loop doesn't exit before the index reaches
	//the size of the array and the input file still has data.
	while(iFile && index < AR_SIZE)
	{
		getline(iFile,personalData[index].name);
		iFile >> personalData[index].id;
		iFile >> personalData[index].balance;
		iFile.ignore(100,'\n');


		//increments the index to change the variable in the
		//while loop for check.
		index++;
	}



}
