/***********************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * LAB #0.5	  : Enumerated Types
 * DUE DATE   : 23 September 2019
 ***********************************/

#ifndef MYHEADER_H_
#define MYHEADER_H_

#include <iostream>
#include <string>
using namespace std;

enum	Days{ SUNDAY,
			  MONDAY,
			  TUESDAY,
			  WEDNESDAY,
			  THURSDAY,
			  FRIDAY,
			  SATURDAY,
			  INVALID
			 };

void ConvertToDays(Days &today, string inputDay);

void ConvertToString(Days today);


#endif /* MYHEADER_H_ */
