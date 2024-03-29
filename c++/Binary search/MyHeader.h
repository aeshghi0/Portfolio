/*****************************************************************************
 * PROGRAMMER : Ali Eshghi & Amirarsalan Valipour
 * STUDENT ID : 1112261 / 1103126
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Lab #5     : Binary Search
 * DUE DATE   : 24 September 2019
 *****************************************************************************/

#ifndef MYHEADER_H_
#define MYHEADER_H_

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//FUNCTIONS

void PrintHeader(const string PROGRAMMER,
				   const string CLASS,
				   const string SECTION,
				   const int    ASSIGN_NUM,
				   const string ASSIGN_NAME);

void ArrayOutput(int numAr[], const int AR_SIZE, int searchNum);

void ArraySort(int numAr[], const int AR_SIZE);

int ArraySequentialSearch(int numAr[], const int AR_SIZE, int searchNum);

int ArrayBinarySearch(int numAr[], const int AR_SIZE, int searchNum);

void ArrayOutput(int numAr[], const int AR_SIZE);

#endif /* MYHEADER_H_ */
