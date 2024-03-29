/***********************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * LAB #0.5	  : Enumerated Types
 * DUE DATE   : 23 September 2019
 ***********************************/

#include "myHeader.h"

void ConvertToDays(Days &today, string inputDay)
{

	switch (toupper(inputDay[0]))
	{
		case 'S': if (toupper(inputDay[1]) == 'A')
					{
						today = SATURDAY;


					}
					else
					{
						today = SUNDAY;
					}
		break;

		case 'M' : today = MONDAY;
		break;

		case 'T' : if (toupper(inputDay[1]) == 'U')
					{
						today = TUESDAY;
					}
					else
					{
						today = THURSDAY;
					}
		break;

		case 'W' : today = WEDNESDAY;
		break;

		case 'F' : today = FRIDAY;
		break;

		default	 : cout << "**** Invalid day input! ****\n\n";
				   today = INVALID;
		}



}

