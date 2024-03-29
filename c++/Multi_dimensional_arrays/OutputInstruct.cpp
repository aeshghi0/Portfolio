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
 * OutputInstruct
 *    This function outputs instructions to the users. There are no input
 *    or output parameters for this function as it only displays text to
 *    the screen.
 *
 *
 *    RETURNS: nothing
 *     Displays the instructions to the user
 ******************************************************************************/
void OutputInstruct()
{
	cout << "Welcome to the Tic-Tac-Toe computer game!" 		<< endl << endl;

	cout << "There are two ways that you could play this game." 		<< endl;
	cout << "1 - Single player" 										<< endl;
	cout << "2 - Multiplayer"   								<< endl << endl;

	cout << "1 - In the single player mode, you are playing against"    << endl;
	cout << "the computer. and at the end, if the game ended   "   	    << endl;
	cout << "in tie, you get to play again."			    	<< endl << endl;

	cout << "2 - In the multiplayer mode, you can play this game with"  << endl;
	cout << "a friend and you can compete with each other. you guys"	<< endl;
	cout << "put in the names when you choose your tokens, then the"	<< endl;
	cout << "Game begins. Good luck to both players"	<< endl << endl << endl;

}

