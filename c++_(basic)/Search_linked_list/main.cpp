/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Assign #3  : Searching linked list
 * DUE DATE   : 6 November 2019
 ******************************************************************************/

#include "MyHeader.h"
#include "ClassHeader.h"

/***************************************************************************
 * OBJECT ORIENTED PROGRAMMING - DVD MOVIE LIST
 * -------------------------------------------------------------------------
 * This program outputs list of movies through linked lists using Object
 * Oriented Programming. DVDs have titles, lead actors, support actors, genre,
 * alternative genre, year, rating, and synopsis. This program allows a user
 * to track/search their DVDs. This program will create a movie list and
 * output a movie list using Object Oriented Programming.
 * -------------------------------------------------------------------------
 * INPUT:
 * inFileName : input file name
 * oFileName : output file name
 * OUTPUT:
 * PROCESSING:
 * MovieList : movie linked list
 *****************************************************************************/

int main()
{
	string		inFileName;	 //IN & PROCESS  - used input file
	string		outFileName; //IN & PROCESS  - used output file
	StackList	list;		 //PROCESS & OUT - stack class
	MovieList	movie;		 //PROCESS & OUT - movie linked list


	//Print Header to console
	PrintHeader(cout, "OOP - DVD Movie List", 5, 'A');

	//get the name of the input file
	cout << "Which input file to use:  ";
	getline(cin,inFileName);

	//get the name of the output file
	cout << "Which output file to use: ";
	getline(cin,outFileName);

	//creates the linked list
	movie.CreatList(inFileName);

	//outputs the linked list to the output file
	movie.OutputList(outFileName);


	return 0;
}




