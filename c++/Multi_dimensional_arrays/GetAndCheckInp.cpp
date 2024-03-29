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
 * GetAndCheckInp
 * 	This functions gets each player's play and checks if the inputed numbers are
 * 	in the domain of the row and column of the game. also it checks if the
 * 	row and column in the board is empty or no
 *
 * RETURNS: nothing
 * 			it puts the players token in the boardAr
 ******************************************************************************/
void GetAndCheckInp(char   boardAr[][3],
					char   token,
					string playerX,
					string playerO,
					int    option,
					char   tokenChoice,
					char   compToken)
{
	/*************
	 * VARIABLES *
	 ************/

	bool 	valid;			//PROCESS - to exit the loop
	bool	xPlayersTurn;	//PROCESS - if player token is X, player's turn
	bool	oPlayersTurn;	//PROCESS - if player token is O, player's turn

	int		row;			//IN & PROCESS - row input for the token
	int		col;			//IN & PROCESS - col input for the token


	/***************************************************************************
	* PROCESS - determines whose turn is it and if the input is valid or no
	***************************************************************************/
	valid = false;

	xPlayersTurn = ((token == toupper(tokenChoice))
				 &&  (toupper(tokenChoice) == 'X'));

	oPlayersTurn = ((token == toupper(tokenChoice))
				 &&  (toupper(tokenChoice) == 'O'));



	if (option == 1) //single player
	{
		do
		{
			/*******************************************************************
			* INPUT & PROCESS - gets the input for the row and the col from the
			* 				    player and checks if it is valid
			*******************************************************************/
			if (xPlayersTurn)
			{
				cout << playerX << "\'s turn! What is your play?: ";
				cin  >> row   >> col;

				row--;
				col--;

				if(row > ROW_SIZE - 1 || row < 0)
				{
					cout << "Invalid row - Please try again! \n";
				}
				else if(col > COL_SIZE - 1 || col < 0)
				{
					cout << "Invalid column - please try again!\n";
				}
				else if(!isspace(boardAr[row][col]))
				{
					cout << "That spot is already taken - try again\n";
				}
				else
				{
					valid = true;


					boardAr[row][col] = token;
				}


			}

			else if (oPlayersTurn)
			{
				cout << playerO << "\'s turn! What is your play?: ";
				cin  >> row   >> col;

				row--;
				col--;

				if(row > ROW_SIZE - 1 || row < 0)
				{
					cout << "Invalid row - Please try again! \n";
				}
				else if(col > COL_SIZE - 1 || col < 0)
				{
					cout << "Invalid column - please try again!\n";
				}
				else if(!isspace(boardAr[row][col]))
				{
					cout << "That spot is already taken - try again\n";
				}
				else
				{
					valid = true;
					boardAr[row][col] = token;
				}

			}


			/*******************************************************************
			* PROCESS - if the player plays before computer, the computer puts
			* 			its token based on the position of the last play by the
			* 			player, and if it is the computer's turn to play and
			* 			there is no threat for the computer, the computer tries
			* 			to put the token for winning and if the computer sees
			* 			any threat from the player, it blocks the player.
			*******************************************************************/
			else if(!xPlayersTurn && !oPlayersTurn)
			{
				cout << "Master's turn..." << endl;



				/***************************************************************
				* PROCESS - there are 24 ways that the computer could win and if
				* 			the computer sees any of those 24 ways available and
				* 			to win the game. the computer puts its token to the
				* 			board.
				***************************************************************/


				if((boardAr[0][0] == compToken)
				&& (boardAr[2][0] == compToken)
				&&  isspace(boardAr[1][0])) //1
				{
					boardAr[1][0] = compToken;


				}
				else if((boardAr[0][1] == compToken)
					 && (boardAr[2][1] == compToken)
					 &&  isspace(boardAr[1][1])) //2
				{
					boardAr[1][1] = compToken;


				}
				else if((boardAr[0][2] == compToken)
					 && (boardAr[2][2] == compToken)
					 &&  isspace(boardAr[1][2])) //3
				{
					boardAr[1][2] = compToken;


				}
				else if((boardAr[0][0] == compToken)
					 && (boardAr[0][2] == compToken)
					 && isspace(boardAr[0][2])) //4
				{
					boardAr[0][1] = compToken;


				}
				else if((boardAr[1][0] == compToken)
					 && (boardAr[1][2] == compToken)
					 && isspace(boardAr[1][1])) //5
				{
					boardAr[1][1] = compToken;


				}
				else if((boardAr[2][0] == compToken)
					 && (boardAr[2][2] == compToken)
					 && isspace(boardAr[2][1])) //6
				{
					boardAr[2][1] = compToken;


				}
				else if((boardAr[0][0] == compToken)
					 && (boardAr[2][2] == compToken)
					 && isspace(boardAr[1][1])) //7
				{
					boardAr[1][1] = compToken;


				}
				else if((boardAr[0][2] == compToken)
					 && (boardAr[2][0] == compToken)
					 && isspace(boardAr[1][1])) //8
				{
					boardAr[1][1] = compToken;


				}
				else if((boardAr[1][0] == compToken)
					 && (boardAr[2][0] == compToken)
					 && isspace(boardAr[0][0])) //9
				{
					boardAr[0][0] = compToken;


				}
				else if((boardAr[1][1] == compToken)
					 && (boardAr[2][1] == compToken)
					 && isspace(boardAr[0][1])) //10
				{
					boardAr[0][1] = compToken;


				}
				else if((boardAr[1][2] == compToken)
					 && (boardAr[2][2] == compToken)
					 && isspace(boardAr[0][2])) //11
				{
					boardAr[0][2] = compToken;


				}
				else if((boardAr[0][1] == compToken)
					 && (boardAr[0][2] == compToken)
					 && isspace(boardAr[0][0])) //12
				{
					boardAr[0][0] = compToken;


				}
				else if((boardAr[1][1] == compToken)
					 && (boardAr[1][2] == compToken)
					 && isspace(boardAr[1][0])) //13
				{
					boardAr[1][0] = compToken;


				}
				else if((boardAr[2][1] == compToken)
					 && (boardAr[2][2] == compToken)
					 && isspace(boardAr[2][0])) //14
				{
					boardAr[2][0] = compToken;


				}
				else if((boardAr[1][1] == compToken)
					 && (boardAr[2][2] == compToken)
					 && isspace(boardAr[0][0])) //15
				{
					boardAr[0][0] = compToken;


				}
				else if((boardAr[1][1] == compToken)
					 && (boardAr[2][0] == compToken)
					 && isspace(boardAr[0][2])) //16
				{
					boardAr[0][2] = compToken;


				}
				else if((boardAr[0][0] == compToken)
					 && (boardAr[1][0] == compToken)
					 && isspace(boardAr[2][0])) //17
				{
					boardAr[2][0] = compToken;


				}
				else if((boardAr[0][1] == compToken)
					 && (boardAr[1][1] == compToken)
					 && isspace(boardAr[2][1])) //18
				{
					boardAr[2][1] = compToken;


				}
				else if((boardAr[0][2] == compToken)
					 && (boardAr[1][2] == compToken)
					 && isspace(boardAr[2][2])) //19
				{
					boardAr[2][2] = compToken;


				}
				else if((boardAr[0][0] == compToken)
					 && (boardAr[0][1] == compToken)
					 && isspace(boardAr[0][2])) //20
				{
					boardAr[0][2] = compToken;


				}
				else if((boardAr[1][0] == compToken)
					 && (boardAr[1][1] == compToken)
					 && isspace(boardAr[1][2])) //21
				{
					boardAr[1][2] = compToken;


				}
				else if((boardAr[2][0] == compToken)
					 && (boardAr[2][1] == compToken)
					 &&  isspace(boardAr[2][2])) //22
				{
					boardAr[2][2] = compToken;


				}
				else if((boardAr[0][0] == compToken)
					 && (boardAr[1][1] == compToken)
					 &&  isspace(boardAr[2][2])) //23
				{
					boardAr[2][2] = compToken;


				}
				else if((boardAr[0][2] == compToken)
					 && (boardAr[1][1] == compToken)
					 &&  isspace(boardAr[2][0])) //24
				{
					boardAr[2][0] = compToken;


				}
				/***************************************************************
				* PROCESS - there are 24 ways that the computer can feel the
				* 			threat from the player and if there were no way to
				* 			win before the player could put the token, the
				* 			computer puts the token in the place to block the
				* 			player from the winning
				***************************************************************/
				else if((boardAr[0][0] == toupper(tokenChoice))
					 && (boardAr[2][0] == toupper(tokenChoice))
					 &&  isspace(boardAr[1][0]))
				{
					boardAr[1][0] = compToken;

				}
				else if((boardAr[0][1] == toupper(tokenChoice))
					 && (boardAr[2][1] == toupper(tokenChoice))
					 && isspace(boardAr[1][1]))
				{
					boardAr[1][1] = compToken;

				}
				else if((boardAr[0][2] == toupper(tokenChoice))
				     && (boardAr[2][2] == toupper(tokenChoice))
					 && isspace(boardAr[1][2]))
				{
					boardAr[1][2] = compToken;

				}
				else if((boardAr[0][0] == toupper(tokenChoice))
					 && (boardAr[0][2] == toupper(tokenChoice))
					 && isspace(boardAr[0][2]))
				{
					boardAr[0][1] = compToken;

				}
				else if((boardAr[1][0] == toupper(tokenChoice))
					 && (boardAr[1][2] == toupper(tokenChoice))
					 && isspace(boardAr[1][1]))
				{
					boardAr[1][1] = compToken;

				}
				else if((boardAr[2][0] == toupper(tokenChoice))
					 && (boardAr[2][2] == toupper(tokenChoice))
					 && isspace(boardAr[2][1]))
				{
					boardAr[2][1] = compToken;

				}
				else if((boardAr[0][0] == toupper(tokenChoice))
					 && (boardAr[2][2] == toupper(tokenChoice))
					 && isspace(boardAr[1][1]))
				{
					boardAr[1][1] = compToken;

				}
				else if((boardAr[0][2] == toupper(tokenChoice))
					 && (boardAr[2][0] == toupper(tokenChoice))
					 && isspace(boardAr[1][1]))
				{
					boardAr[1][1] = compToken;

				}
				else if((boardAr[1][0] == toupper(tokenChoice))
					 && (boardAr[2][0] == toupper(tokenChoice))
					 && isspace(boardAr[0][0]))
				{
					boardAr[0][0] = compToken;

				}
				else if((boardAr[1][1] == toupper(tokenChoice))
					 && (boardAr[2][1] == toupper(tokenChoice))
					 && isspace(boardAr[0][1]))
				{
					boardAr[0][1] = compToken;

				}
				else if((boardAr[1][2] == toupper(tokenChoice))
					 && (boardAr[2][2] == toupper(tokenChoice))
					 && isspace(boardAr[0][2]))
				{
					boardAr[0][2] = compToken;

				}
				else if((boardAr[0][1] == toupper(tokenChoice))
					 && (boardAr[0][2] == toupper(tokenChoice))
					 && isspace(boardAr[0][0]))
				{
					boardAr[0][0] = compToken;

				}
				else if((boardAr[1][1] == toupper(tokenChoice))
					 && (boardAr[1][2] == toupper(tokenChoice))
					 && isspace(boardAr[1][0]))
				{
					boardAr[1][0] = compToken;

				}
				else if((boardAr[2][1] == toupper(tokenChoice))
					 && (boardAr[2][2] == toupper(tokenChoice))
					 && isspace(boardAr[2][0]))
				{
					boardAr[2][0] = compToken;

				}
				else if((boardAr[1][1] == toupper(tokenChoice))
					 && (boardAr[2][2] == toupper(tokenChoice))
					 && isspace(boardAr[0][0]))
				{
					boardAr[0][0] = compToken;

				}
				else if((boardAr[1][1] == toupper(tokenChoice))
					 && (boardAr[2][0] == toupper(tokenChoice))
					 && isspace(boardAr[0][2]))
				{
					boardAr[0][2] = compToken;

				}
				else if((boardAr[0][0] == toupper(tokenChoice))
					 && (boardAr[1][0] == toupper(tokenChoice))
					 &&  isspace(boardAr[2][0]))
				{
					boardAr[2][0] = compToken;

				}
				else if((boardAr[0][1] == toupper(tokenChoice))
					 && (boardAr[1][1] == toupper(tokenChoice))
					 && isspace(boardAr[2][1]))
				{
					boardAr[2][1] = compToken;

				}
				else if((boardAr[0][2] == toupper(tokenChoice))
					 && (boardAr[1][2] == toupper(tokenChoice))
					 && isspace(boardAr[2][2]))
				{
					boardAr[2][2] = compToken;

				}
				else if((boardAr[0][0] == toupper(tokenChoice))
					 && (boardAr[0][1] == toupper(tokenChoice))
					 && isspace(boardAr[0][2]))
				{
					boardAr[0][2] = compToken;

				}
				else if((boardAr[1][0] == toupper(tokenChoice))
					 && (boardAr[1][1] == toupper(tokenChoice))
					 && isspace(boardAr[1][2]))
				{
					boardAr[1][2] = compToken;

				}
				else if((boardAr[2][0] == toupper(tokenChoice))
					 && (boardAr[2][1] == toupper(tokenChoice))
					 && isspace(boardAr[2][2]))
				{
					boardAr[2][2] = compToken;

				}
				else if((boardAr[0][0] == toupper(tokenChoice))
					 && (boardAr[1][1] == toupper(tokenChoice))
					 && isspace(boardAr[2][2]))
				{
					boardAr[2][2] = compToken;

				}
				else if((boardAr[0][2] == toupper(tokenChoice))
					 && (boardAr[1][1] == toupper(tokenChoice))
					 && isspace(boardAr[2][0]))
				{
					boardAr[2][0] = compToken;

				}

				/***************************************************************
				* PROCESS - if the computer determines no chance to win or
				* 			determines no threat from the player, it randomly
				* 			puts a token on the board.
				***************************************************************/
				else
				{

					srand(time(NULL));

					row = rand() % 3 + 1;
					col = rand() % 3 + 1;


					row--;
					col--;

					while(!isspace(boardAr[row][col]))
					{
						srand(time(NULL));

						row = rand() % 3 + 1;
						col = rand() % 3 + 1;


						row--;
						col--;

					}

					if(isspace(boardAr[row][col]))
					{


						boardAr[row][col] = compToken;
						valid = true;

					}



					else if(!isspace(boardAr[row - 1][col - 1]))
					{
						while(!isspace(boardAr[row - 1][col - 1]))
						{
							if(row == 1)
							{
								srand(time(NULL));

								row = rand() % 2 + 1;

								if(row == 1)
								{
									row = 2;
								}
								if(row == 2)
								{
									row = 3;
								}

								row--;
								col--;

								boardAr[row][col] = compToken;
								valid = true;
							}

							else if(row == 2)
							{
								srand(time(NULL));

								row = rand() % 2 + 1;

								if(row == 1)
								{
									row = 1;
								}
								if(row == 2)
								{
									row = 3;
								}

								row--;
								col--;

								boardAr[row][col] = compToken;
								valid = true;
							}

							else if(row == 3)
							{
								srand(time(NULL));

								row = rand() % 2 + 1;

								if(row == 1)
								{
									row = 1;
								}
								if(row == 2)
								{
									row = 2;
								}

								row--;
								col--;

								boardAr[row][col] = compToken;
								valid = true;
							}


							else if(col == 1)
							{
								srand(time(NULL));

								row = rand() % 2 + 1;

								if(col == 1)
								{
									col = 2;
								}
								if(row == 2)
								{
									col = 3;
								}

								row--;
								col--;

								boardAr[row][col] = compToken;
								valid = true;
							}

							else if(col == 2)
							{
								srand(time(NULL));

								col = rand() % 2 + 1;

								if(col == 1)
								{
									col = 1;
								}
								if(col == 2)
								{
									col = 3;
								}

								row--;
								col--;

								boardAr[row][col] = compToken;
								valid = true;
							}

							else if(col == 3)
							{
								srand(time(NULL));

								col = rand() % 2 + 1;

								if(col == 1)
								{
									col = 1;
								}
								if(col == 2)
								{
									col = 2;
								}

								row--;
								col--;

								boardAr[row][col] = compToken;
								valid = true;
							}
						}
					}
				}
				valid = true;
			}
		}while(!valid);
	}




	else if(option == 2) // multiplayer
	{

		do
		{
			/*******************************************************************
			* INPUT & PROCESS - gets the input for the row and the col from the
			* 				    players and checks if it is valid
			*******************************************************************/
			if(token == 'X')
			{
				cout << playerX;
			}
			else if(token == 'O')
			{
				cout << playerO;
			}

			cout << "\'s turn! What is your play?: ";
			cin  >> row   >> col;

			row--;
			col--;

			if(row > ROW_SIZE - 1 || row < 0)
			{
				cout << "Invalid row - Please try again! \n";
			}
			else if(col > COL_SIZE - 1 || col < 0)
			{
				cout << "Invalid column - please try again!\n";
			}
			else if(!isspace(boardAr[row][col]))
			{
				cout << "That spot is already taken - try again\n";
			}
			else
			{
				valid = true;
			}
		}while(!valid);

		boardAr[row][col] = token;
		cin.ignore(10000,'\n');

	}
	//clear();
}
