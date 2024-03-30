/*******************************************************************************
 * PROGRAMMER : Ali Eshghi & Amirarsalan Valipour
 * STUDENT ID : 1112261 & 1103126
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Assign #2  : tic-tac-toe game (multi-dimensional arrays)
 * DUE DATE   : 19 September 2019
 ******************************************************************************/

#ifndef CLASSHEADER_H_
#define CLASSHEADER_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

/*************
 * VARIABLES *
 ************/

/*******************************************************************
 * Class of Sheep1, containing objects of information about Fluffy *
 *******************************************************************/
class Sheep1
{
	//public part of the class that is available for outside of the class
	public:
		//constructor
		Sheep1()
		{
			name.clear();
			type.clear();
			age  = 0;
			value= 0;
		};

		//decosntructor
		~Sheep1();

		//method for seting the animal type
		void SetTypeSheep1(string);

		//method for setting or changing the age
		void SetAgeSheep1(int);

		//method for setting the name
		void SetNameSheep1(string);

		//method for setting or changing the value
		void SetValueSheep1(float);

		//method  for outputting the objects
		void PrintSheep1(string, string, int, float) const;


	//private part only available for the class
	private:
		string name;
		string type;
		int    age;
		float  value;

};


/*******************************************************************
 * Class of Sheep1, containing objects of information about Maa    *
 *******************************************************************/
class Sheep2
{
	//public part of the class that is available for outside of the class
	public:
		//constructor
		Sheep2()
		{
			name.clear();
			type.clear();
			age  = 0;
			value= 0;
		};

		//decosntructor
		~Sheep2();

		//method for seting the animal type
		void SetTypeSheep2(string);

		//method for setting or changing the age
		void SetAgeSheep2(int);

		//method for setting the name
		void SetNameSheep2(string);

		//method for setting or changing the value
		void SetValueSheep2(float);

		//method  for outputting the objects
		void PrintSheep2(string, string, int, float) const;

	//private part only available for the class
	private:

		string name;
		string type;
		int    age;
		float  value;

};

/*******************************************************************
 * Class of Sheep1, containing objects of information about Babe   *
 *******************************************************************/
class Pig
{
	//public part of the class that is available for outside of the class
	public:
		//constructor
		Pig()
		{
			name.clear();
			type.clear();
			age  = 0;
			value= 0;
		};

		//decosntructor
		~Pig();

		//method for seting the animal type
		void SetTypePig(string);

		//method for setting or changing the age
		void SetAgePig(int);

		//method for setting the name
		void SetNamePig(string);

		//method for setting or changing the value
		void SetValuePig(float);

		//method  for outputting the objects
		void PrintPig(string, string, int, float) const;


	//private part only available for the class
	private:
		string name;
		string type;
		int    age;
		float  value;

};




#endif /* CLASSHEADER_H_ */
