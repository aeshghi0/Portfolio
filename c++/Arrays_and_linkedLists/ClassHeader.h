/************************************************************
* AUTHOR	    : Ali Eshghi
* STUDENT ID    : 1112261
* LAB #13		: LAB 13 - ARRAYS AND LINKED LIST (OOP)
* CLASS	        : CS 1B
* SECTION	    : MW - 7:30 pm - 9:50 pm
* DUE DATE	    : 12/3/2019
*************************************************************/

#ifndef CLASSHEADER_H_
#define CLASSHEADER_H_

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<limits>
#include<sstream>
using namespace std;

const int AR_SIZE = 50;


class Animal
{
	//public part of the class that is available for outside of the class
	public:
		//constructor
		Animal();

		//decosntructor
		~Animal();

		//method for adding a new sheep and its age to parallel arrays
		void AddSheep(string name, int age);

		//method for adding a new sheep to a linked list
		void AddSheepLinkedList(string name, int age);

		//method for showing the first sheep from the list
		void DisplayFirstSheep();

		//method that returns the size of the list of the sheeps
		int ListSize() const;

		//method  for outputting the objects
		void Display() const;

		//method for finding the sheep in the list
		void FindSheep(string) const;


	//private part only available for the class
	private:
		string nameAr[AR_SIZE];
		int    ageAr[AR_SIZE];
		string name;
		int    age;
		int	   listSize;

		struct SheepNode
		{
			string	   sheepName;
			int		   sheepAge;
			SheepNode  *next;
		};
		SheepNode *head;

};



#endif /* CLASSHEADER_H_ */
