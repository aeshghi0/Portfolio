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
 * GetPlayers
 * 	This function prompts the user and gets the input for the players’ names.
 * 	playerXwill always contain the name of the player that is using the X token.
 *  playerOwill always contain the name of the player that is using the O token.
 *
 * RETURNS: the players names through the variables playerX and playerO.
 ******************************************************************************/

void GetPlayers(string &playerX, 	//IN & OUT -player X’s name
				string &playerO,	//IN & OUT -player O’x name
				char   &compToken,
				char   &tokenChoice,
				int     option)
{



	if(option == 1) //single player
	{

		/***********************************************************************
		* INPUT - gets the choice of the token that the player wants to play
		* 		  and based on that inputs the input name from the user to
		* 		  the player O (if the player chooses O) or player X (if the
		* 		  player chooses X)
		***********************************************************************/
		cin.ignore(10000,'\n');

		cout << "Would you like to play as player \'X\' or player \'O\'? ";
		cin.get(tokenChoice);
		cin.ignore(1000,'\n');

		if(toupper(tokenChoice) == 'X')
		{
			cout << "What is the Player's name for token X? ";
			getline(cin,playerX);
			playerO = "system";
			compToken = 'O';
		}
		else if(toupper(tokenChoice) == 'O')
		{
			cout << "What is the Player's name for token O? ";
			getline(cin,playerO);
			playerX = "system";
			compToken = 'X';
		}
	}

	else if(option == 2) //multi-Player
	{
		/***********************************************************************
		* INPUT - gets the name of both playerX and playerO
		***********************************************************************/
		cin.ignore(10000,'\n');

		cout << "What is the Player's name for token X? ";
		getline(cin,playerX);

		cout << "What is the Player's name for token O? ";
		getline(cin,playerO);

		cout << endl;
	}


}
