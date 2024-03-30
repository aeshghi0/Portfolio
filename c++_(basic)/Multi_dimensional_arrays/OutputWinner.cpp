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
 * OutputWinner
 *   This function receives as input a character indicating which player won
 *   or if the game was a tie and outputs an appropriate message. This function
 *   does not return anything as it simply outputs the appropriate message to
 *   the screen.
 *
 * RETURNS: nothing
 * Displays the winner’s name
 ******************************************************************************/

void OutputWinner(char &wonPlayer,	// IN  -represents the winner or a value
									//  indicating a tied game.
				  string playerX,	//OUT -player X’s name
				  string playerO, 	//OUT -player O’x name
				  char	 tokenChoice,
				  char	 compToken,
				  int	 option)
{
	if (option == 1)
	{
		/*******************************************************************
		* OUTPUT - outputs the result of the game(who has one). or the game
		* 		   ended in tie.
		*******************************************************************/
		if(toupper(tokenChoice) == 'X')
		{
			switch(wonPlayer)
			{
			case 'X': cout << "You have won the Game"
											<< endl;
			break;
			case 'O': cout << "Master has won the Game;";
							cout <<" Better luck next time;"
								 << endl;
			break;
			default:  cout << "The Game ended in tie."       << endl;
					  wonPlayer = 'N';
			}
		}

		else if(toupper(tokenChoice) == 'O')
		{
			switch(wonPlayer)
			{
			case 'O': cout << "You have won the Game"
											<< endl;
			break;
			case 'X': cout << "Master has won the Game;";
							cout <<" Better luck next time;"
								 << endl;
			break;
			default:  cout << "The Game ended in tie."       << endl;
					  wonPlayer = 'N';
			}
		}
	}

	else if(option == 2)
	{
		/***********************************************************************
		* OUTPUT - outputs the result of the game(who has one). or the game
		* 		   ended in tie.
		***********************************************************************/
		switch(wonPlayer)
		{
		case 'X': cout << playerX << " has won the Game" << endl;
		break;
		case 'O': cout << playerO << " has won the Game" << endl;
		break;
		default:  cout << "The Game ended in tie."       << endl;
				  wonPlayer = 'N';
		}
	}
}
