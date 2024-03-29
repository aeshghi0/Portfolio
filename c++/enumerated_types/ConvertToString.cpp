/***********************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * LAB #0.5	  : Enumerated Types
 * DUE DATE   : 23 September 2019
 ***********************************/

#include "myHeader.h"

void ConvertToString(Days today)
{
	switch(today)
		{
			case SUNDAY: cout << "today is SUNDAY" << endl << endl;
			break;
			case MONDAY: cout << "today is MONDAY" << endl << endl;
			break;
			case TUESDAY: cout << "today is TUESDAY" << endl << endl;
			break;
			case WEDNESDAY: cout << "today is WEDNESDAY" << endl << endl;
			break;
			case THURSDAY: cout << "today is THURSDAY" << endl << endl;
			break;
			case FRIDAY: cout << "today is FRIDAY" << endl << endl;
			break;
			case SATURDAY: cout << "today is SATURDAY" << endl << endl;
			break;
			default: cout << "today is INVALID" << endl << endl;
		}
}

