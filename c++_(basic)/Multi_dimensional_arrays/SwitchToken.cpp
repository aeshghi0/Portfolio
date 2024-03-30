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
 * SwitchToken
 *   This function switches the active player.
 *   It takes in a parameter representing the current player's token
 *   as a character value (either an X or an O) and returns the opposite.
 *   For example, if this function receives an X it returns an O. If it
 *   receives and O it returns and X.
 *
 * RETURNS: the token opposite of the one in which it receives.
 ******************************************************************************/

char SwitchToken(char token)
{

	if(token == 'X')
	{
		token = 'O';
	}
	else if(token == 'O')
	{
		token = 'X';
	}

	return token;
}
