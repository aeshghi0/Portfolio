/******************************************************************************
* AUTHOR     : Amirarsalan Valipour & Ali Eshghi
* STUDENT ID : 1103126 - 1112261
* LAB #10    : Creating an Ordered List
* CLASS      : CS 1B
* SECTION    : MW - 7:30 pm
* DUE DATE   : 11/05/2019
*******************************************************************************
* PrintMenu
*******************************************************************************
*  This function will output the menu, gets the user's option and checks to see
*    if the input is eligible or not.
*******************************************************************************/

#ifndef MYHEADER_H_
#define MYHEADER_H_

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<limits>
#include<sstream>
using namespace std;

const string NAME = "Creating an Ordered List";
const char   TYPE    = 'L';
const int    NUM     = 10 ;
const string CLASS   = "CS1B";
const string SECTION = "MW: 7:30p - 9:50p";



enum MenuOption
{
	EXIT,
	CREATE,
	DISPLAY,
	ISEMPTY,
	SEARCH,
	REMOVE,
	CLEAR
};

struct PersonNode
{
	string	   name;
	char	   gender;
	int		   age;
	PersonNode *next;
	PersonNode *prev;
};

/*******************************************************************************
 * Function - PrintHeaderFile
 * ---------------------------------------------------------------------------
 * This function will output the class heading to the screen.
 *
 * return type - nothing
 * 				 the function is void type
 ******************************************************************************/
void PrintHeaderFile();

/*******************************************************************************
 * Function - PrintMenu
 * ---------------------------------------------------------------------------
 * This function will output menu option to the screen and waits for the user to
 * input an option to what to what to do. The options are as following:
 *
 * 1 – Create List
 * 2 – Display List
 * 3 - Is the list empty?
 * 4 - Search by name
 * 5 - Remove Node
 * 6 - Clear List
 * 0 – to Exit
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
void CreatList(PersonNode *&head);

/*******************************************************************************
 * Function - DisplayList
 * ---------------------------------------------------------------------------
 * This function will output the contents of the nodes of the linked list
 * created in the CreatList function
 *
 * return type - nothing
 * 				 the function is void type
 ******************************************************************************/
void DisplayList(PersonNode *head);

/*******************************************************************************
 * Function - IsEmpty
 * ---------------------------------------------------------------------------
 * This function check if the list created or modified by the user is empty or
 * no and then  outputs if the list is empty or no
 *
 * return type - nothing
 * 				 the function is void type
 ******************************************************************************/
void IsEmpty(PersonNode *head);

/*******************************************************************************
 * Function - SearchName
 * ---------------------------------------------------------------------------
 * This function will get a name from the user and search the name content of
 * each node to see if there is a matching name in the nodes with the name
 * searched by the user. if found, the function prints out every content of the
 * node for the user, if not found, the function outputs that the name searched
 * by the user was not found.
 *
 * return type - nothing
 * 				 the function is void type
 ******************************************************************************/
void SearchName(PersonNode *head);

/*******************************************************************************
 * Function - RemoveNode
 * ---------------------------------------------------------------------------
 * This function will ask the user which node the user wants to remove and it
 * searches the nodes based on the name content of the nodes and if the name
 * content of a node matches the name input by the user, the function removes
 * the node from the list, if not, the function outputs that the name searched
 * by the user has not found in the list.
 *
 * return type - nothing
 * 				 the function is void type
 ******************************************************************************/
void RemoveNode(PersonNode *&head);

/*******************************************************************************
* Function - ClearList
*******************************************************************************
*  This function Allows the user to delete all the nodes in the linked list and
*  make an empty list out of the list of the names that we had
*
*  return type - nothing
*  				 the function is void type
*******************************************************************************/
void ClearList(PersonNode *&head);


#endif /* MYHEADER_H_ */
