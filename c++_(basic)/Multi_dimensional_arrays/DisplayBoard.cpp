/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Assign #2  : tic-tac-toe game (multi-dimensional arrays)
 * DUE DATE   : 19 September 2019
 ******************************************************************************/
#include "MyHeader.h"

/*******************************************************************************
 * DisplayBoard
 * This function outputs the tic-tac-toe board including the tokens
 * played in the proper format (as described below).
 *
 * 			1       2        3
 * 		 [1][1] | [1][2] | [1][3]
 * 	            |        |
 * 1            |        |
 *              |        |
 *      --------------------------
 *       [2][1] | [2][2] | [2][3]
 *       		|        |
 * 2            |        |
 * 			    |        |
 * 		--------------------------
 * 		 [3][1] | [3][2] | [3][3]
 * 		 		|        |
 * 3            |        |
 * 				|        |
 *
 * * RETURNS: nothing
 *  outputs the current state of the board
 ******************************************************************************/

void DisplayBoard(const char boardAr[][COL_SIZE]) // IN -tic tac toe board
{
	/*************
	 * VARIABLES *
	 ************/

	int i; //used in loop
	int j; //used in loop

	cout << setw(10) << "1"<< setw(8) << "2"<< setw(9) << " 3\n";
	for(i=0; i < 3; i++)
	{
		cout << setw(7)<< "["<< i+1 << "][1] | "<< "["<< i+1;
		cout <<"][2] | " <<"["<< i+1 << "][3]"<< endl;
		cout << setw(14)<< "|"<< setw(9) << "|"<< endl;

		for(j = 0; j < 3; j++)
		{
			switch(j)
			{
				case 0: cout << i + 1 << setw(9) << boardAr[i][j];
						cout  << setw(4) << "|";
						break;

				case 1: cout << setw(4) << boardAr[i][j];
						cout << setw(5) << "|";
						break;

				case 2: cout << setw(4) << boardAr[i][j] << endl;
						break;

				default: cout <<"ERROR!\n\n";
			}
		}

		cout << setw(14)<< "|"<< setw(10) << "|\n";

		if(i != 2)
		{
			cout << setw(32) << "--------------------------\n";
		}
	}
	cout << endl << endl;
}


