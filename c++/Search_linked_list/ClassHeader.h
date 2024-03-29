/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Assign #3  : Searching linked list
 * DUE DATE   : 6 November 2019
 ******************************************************************************/
#ifndef CLASSHEADER_H_
#define CLASSHEADER_H_


#include<iostream>   // INPUT AND OUTPUT
#include<iomanip>	 // FOR USING SETW'S
#include<string>	 // FOR USING STRINGS
#include<fstream>	 // FOR USING OUTPUT FILES
#include<limits>	 // FOR USING LIMITS
#include<ios>		 // FOR USING STREAM SIZE
#include<sstream>	 // FOR USING OSTRINGSETREAM
#include"MyHeader.h"
using namespace std;


struct DVDNode
{
	string		title;		//store Movie's title
	string		leadActor;	//store leading Actor/Actress
	string		supActor;	//store supporting Actor/Actress
	string		genre;		//store Movie's genre
	string		altGenre;	//store Movie's alternate genre
	int			year;		//store Movie's year
	int			rating;		//store Movie's rating
	string		synopsis;	//store Movie's Synopsis
	DVDNode		*next;		//linked list next pointer
};



class StackList
{
public:

	//constructor
	StackList();

	//destructor
	~StackList();

	/******************
	 **** MUTATORS ****
	 ******************/

	void Push(DVDNode newDVD);	//create a DVDNode, add the
								// node to the stack, by
								// adding the node to front of the List

	DVDNode Pop();				//returns the node from the top of the list
								//removes the node from the list and delets it

	/******************
	 **** ACCESSORS ***
	 ******************/

	bool IsEmpty() const;		//checks if the list is empty

	DVDNode Peek() const;		//returns the node at the top of the list

	int Size() const;			//returns the number of the nodes in the list

protected:
	DVDNode *head;				//head pointer for the list
	int		stackCount;			//total number of nodes in the list

};



class MovieList: public StackList
{
public:

	//constructor
	MovieList();

	//destructor
	~MovieList();

	/******************
	 **** MUTATORS ****
	 ******************/

	void CreatList(string inFileName);

	/******************
	 **** ACCESSORS ***
	 ******************/

	void OutputList(string outFileName) const;

private:

	string WordWrap(string plot) const;

	void PrintClassHeader(ostream &output,	       //IN & OUT - utput file
						  string  labName,	       //OUT      - lab name
						  int	  labNumber, 	   //OUT	  - lab number
						  char	  labType) const;  //OUT	  - lab type



};





#endif /* CLASSHEADER_H_ */
