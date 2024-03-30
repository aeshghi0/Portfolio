/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1C
 * SECTION    : MTWTH 3pm
 * HW01       : random number generation
 * DUE DATE   : 04 June 2020
 ******************************************************************************/

#ifndef MYHEADER_H_
#define MYHEADER_H_

#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
#include<ctime> //for time()
#include<cstdlib> //for srand() and rand()
using namespace std;

int twoDigit(int);

//Use enum
enum functions
{
	RANDOM_NUM,
	STORE_NUM,
	SORT,
	W_FILE,
	R_FILE,
	PRINT,
};

//Use typedef
typedef int in;

//Reverse the digits
void reverse_SumDigits(in rnum);

//Triple the number
void triple(in rnum);

//Sort the array
void sort(int rnumAr[]);

//Write the array to an external file
void FileWrite(int rnumAr[]);

//Call a function to read the external file
void FileRead();

//Print the array in a function
void print(int rnumAr[]);



#endif /* MYHEADER_H_ */
