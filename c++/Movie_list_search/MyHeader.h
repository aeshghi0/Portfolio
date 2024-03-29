/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Assign #3  : Searching linked list
 * DUE DATE   : 6 November 2019
 ******************************************************************************/

#ifndef MYHEADER_H_
#define MYHEADER_H_

#include<iostream>   // INPUT AND OUTPUT
#include<iomanip>	 // FOR USING SETW'S
#include<string>	 // FOR USING STRINGS
#include<fstream>	 // FOR USING OUTPUT FILES
#include<limits>	 // FOR USING LIMITS
#include<ios>		 // FOR USING STREAM SIZE
#include<sstream>	 // FOR USING OSTRINGSETREAM
using namespace std;

/*************
 * VARIABLES *
 ************/


struct MovieNode
{
	string		title;
	string		leadActor;
	string		supportActor;
	string		genre;
	string		altGenre;
	string		synopsis;

	int			year;
	int			rate;

	MovieNode  *next;
	MovieNode  *prev;
};


/*******************************************************************************
 * Function - PrintHeaderFile
 * ---------------------------------------------------------------------------
 * This function will output the class heading to the screen and output file
 *
 * return type - nothing
 * 				 the function is void type
 ******************************************************************************/
void PrintHeader(const string MY_NAME,
		   	   	 const string CLASS,
				 const string CLASS_TIME,
				 const int    ASSIGN_NUM,
				 const string ASSIGN_NAME,
				 ofstream     &outFile);

/*******************************************************************************
 * Function - PrintMenu
 * ---------------------------------------------------------------------------
 * This function will output menu option to the screen and waits for the user to
 * input an option to what to what to do. The options are as following:
 *
 * 1 – Output Entire List
 * 2 – Title Search
 * 3 - Genre Search
 * 4 - Actor Search
 * 5 - Year Search
 * 6 - Rating Search (0-9)
 * 0 – Exit
 *
 * return type - Integer
 ******************************************************************************/
int PrintMenu();

/*******************************************************************************
 * Function - CreatList
 * ---------------------------------------------------------------------------
 * This function will get the data from the input file and puts the data into
 * the contents of the nodes, then add the nodes to the empty lists passed by
 * Reference to the function
 *
 * return type - nothing
 * 				 the function is void type
 ******************************************************************************/
void CreatList(MovieNode *&head);

/*******************************************************************************
 * Function - DisplayList
 * ---------------------------------------------------------------------------
 * This function will output the contents of the nodes of the linked list
 * created in the CreatList function in the output file created by the user.
 *
 * return type - nothing
 * 				 the function is void type
 ******************************************************************************/
void DisplayList(MovieNode *head, ofstream &outFile);

/*******************************************************************************
 * Function - SearchTitle
 * ---------------------------------------------------------------------------
 * This function will get a title from the user and search the title content of
 * each node to see if there is a matching title in the nodes with the title
 * searched by the user. if found, the function prints out every content of the
 * node for the user, if not found, the function outputs that the title searched
 * by the user was not found.
 *
 * return type - nothing
 * 				 the function is void type
 ******************************************************************************/
void SearchTitle(MovieNode *head, ofstream &outFile);

/*******************************************************************************
 * Function - SearchGenre
 * ---------------------------------------------------------------------------
 * This function will get a genre from the user and search the genre content of
 * each node to see if there is a matching genre in the nodes with the genre
 * searched by the user. if found, the function prints out every content of
 * every node for the user, if not found, the function outputs that the genre
 * searched by the user was not found.
 *
 * return type - nothing
 * 				 the function is void type
 ******************************************************************************/
void SearchGenre(MovieNode *head, ofstream &outFile);

/*******************************************************************************
 * Function - SearchActor
 * ---------------------------------------------------------------------------
 * This function will get a actor's name from the user and search the actors'
 * content of each node to see if there is a matching actor's name in the nodes
 * with the actor's name searched by the user. if found, the function prints out
 * every content of every node for the user, if not found, the function outputs
 * that the actor's name searched by the user was not found.
 *
 * return type - nothing
 * 				 the function is void type
 ******************************************************************************/
void SearchActor(MovieNode *head, ofstream &outFile);

/*******************************************************************************
 * Function - SearchYear
 * ---------------------------------------------------------------------------
 * This function will get a year from the user and search the year content of
 * each node to see if there is a matching year in the nodes with the year
 * searched by the user. if found, the function prints out every content of
 * every node for the user, if not found, the function outputs that the year
 * searched by the user was not found.
 *
 * return type - nothing
 * 				 the function is void type
 ******************************************************************************/
void SearchYear(MovieNode *head, ofstream &outFile);

/*******************************************************************************
 * Function - SearchRate
 * ---------------------------------------------------------------------------
 * This function will get a rating from the user and search the genre content of
 * each node to see if there is a matching rating in the nodes with the rating
 * searched by the user. if found, the function prints out every content of
 * every node for the user, if not found, the function outputs that the rating
 * searched by the user was not found.
 *
 * return type - nothing
 * 				 the function is void type
 ******************************************************************************/
void SearchRate(MovieNode *head, ofstream &outFile);

#endif /* MYHEADER_H_ */
