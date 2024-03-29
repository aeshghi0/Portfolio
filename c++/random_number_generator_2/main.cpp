/************************************************************
* AUTHOR     : Amirarsalan Valipour & Ali Eshghi
* STUDENT ID : 1103126
* LAB #1	 : Random Number Generator
* CLASS		 : CS 1C
* SECTION	 : MW - 5 pm - 7 pm
* DUE DATE	 : 1/13/2020
*************************************************************/

#include "Header.h"


int main()
{
	//CONSTANTS

	const int  PROMPT = 14;
	const int  asNum  = 1;
	const char PROGRAMMER[50] = "Amirarsalan Valipour & ALi Eshghi";
	const char CLASS[5]		  = "CS1B";
	const char SECTION[25]	  = "MW: 5p - 7p";
	const char asType = 'A';
	const char asName[50] = "Random Number Generator";



	//VARIABLES

	num integer;				//Calc & Out - Random Integer
	num intAr[AR_SIZE];			//Calc & Out - Random Integer Array
	num sumAr[AR_SIZE];			//Calc & Out - Total Value Array
	num sortedIntAr[AR_SIZE];	//Calc & Out - Sorted Integer Array
	num reverseIntAr[AR_SIZE];	//Calc & Out - Reversed Numbers Array

	num sum;	//Calc & Out - Total Values
	num i;		//Calc - LCV
	num j;		//Calc - LCV
	num temp;	//Calc - Temporary Value
	num k;
	num strLen;
	num intNum;
	num strSum;

	convert ss;

	string s;

	std::string textNum;


	//INITIALAZATION

	sum = 0;
	strSum = 0;


	//PRINT HEADER

	cout << left;
	cout << endl;
	cout << "********************************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(PROMPT) << "CLASS"   << ": " << CLASS;
	cout << "\n* " << setw(PROMPT) << "SECTION" << ": " << SECTION;
	cout << "\n* ";

	if (toupper(asType) == 'L')
	{
		cout << "LAB #" << setw(8);
	}

	else
	{
		cout << "ASSIGNMENT #" << setw(1);
	}

	cout << asNum << " : " << asName;
	cout << "\n******************************************************";
	cout << "**\n\n";
	cout << right;


	cout << "Generating RANDOM integers...\n";


	//PROCESSING

	srand(time(NULL));	//time seed


	//generates 16 random number

	for(i = 0; i < 16; i++)
	{
		integer = rand() % 99 + 1;

		intAr[i] = integer;

		cout << integer << endl;
	}

	cout << endl;


	//bubble sort the array

	for(int i = 0; i < AR_SIZE; i++)
	{
		for(j = 0; j < AR_SIZE; j++)
		{
			if(intAr[j] > intAr[j+1])
			{
				temp       = intAr[j];

				intAr[j]   = intAr[j+1];

				intAr[j+1] = temp;
			}
		}
	}


	//initialize sorted numbers in another array

	cout << "Sorting...\n";

	for(i = 0; i < AR_SIZE; i++)
	{
		sortedIntAr[i] = intAr[i];

		cout << sortedIntAr[i];

		cout << endl;
	}

	cout << endl;


	//Reversing the numbers

	cout << "Reversing Each Integer: \n";


	for(i = 0; i < AR_SIZE; i++)
	{
		k = sortedIntAr[i];

		ss << k;

		ss >> s;

		if(s.length() == 1)
		{
			cout << s;
			cout << endl;
		}

		else if(s.length() == 2)
		{
			if(s[1] == '0')
			{
				cout << s[0];
				cout << endl;
			}

			else
			{
				cout << s[1];
				cout << s[0];
				cout << endl;
			}

		}

		ss.clear();
		s.clear();
	}
	cout << endl << endl;



	//find the sum of the random numbers and store them

	cout << "Total of Each Integers: \n";

	for(i = 0; i < AR_SIZE; i++)
	{
		k = sortedIntAr[i];

		ss << k;

		ss >> s;

		if(s.length() == 1)
		{
			cout << s;
			cout << endl;
		}

		else if(s.length() == 2)
		{
			for(i = 0; i < s.length(); ++i)
			{
				int a = charToInt(s[i]);

				strSum = strSum + a;

			}

			cout << strSum;
			cout << endl;
			strSum = 0;
		}

		ss.clear();
		s.clear();
	}


	cout << endl << endl;

	return 0;
}

