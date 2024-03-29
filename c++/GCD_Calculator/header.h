/******************************************************************************
 * PROGRAMMER : Ali Eshghi & Elsa Micklnin
 * STUDENT ID : 1112261    & 1028119
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * LAB #3     : Functions and arrays
 * DUE DATE   : 10 September 2019
 *****************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

void PrintHeaderFile(ostream  &oFile,
					 string	   asName,
					 char 	   asType,
					 int	   asNum,
					 string	   asClass,
					 string    asSection);

string PrintHeaderScreen(string	   asName,
						 char 	   asType,
						 int	   asNum,
						 string	   asClass,
						 string    asSection);

void ReadTwoInts(int &n1,
				 int &n2);

int GreatestCommonDivisor(int n1,int n2);

string OutputResults(int n1, int n2, int greatestDivisor);



#endif /* HEADER_H_ */
