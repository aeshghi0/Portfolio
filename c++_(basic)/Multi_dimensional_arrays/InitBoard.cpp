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
 * InitBoard
 * This function initializes each spot in the board to a space ' '.
 *
 * RETURNS: Board initialized with all spaces
 ******************************************************************************/

void InitBoard(char boardAr[][3]) // OUT -tic tac toe board
{
	/*************
	 * VARIABLES *
	 ************/

	int i; //PROCESS - for the loop
	int j; //PROCESS - for the loop

	for(i = 0; i < ROW_SIZE; i++)
	{
		for(j = 0; j < COL_SIZE; j++)
		{
			boardAr[i][j] = ' ';
		}
	}

}
