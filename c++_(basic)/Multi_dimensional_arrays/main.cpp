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
* Assignment 2
* ------------------------------------------------------------------------------
* This program is a simulation of the tic-tac-toe game. based on the player's
* choice, they can play against the computer, or against a friend.
* If the player tries to play against the computer, randomly, the game starts
* by the player or the computer and the computer has the algorithm to block the
* player and win the game.
*
* If the player decides to start the game with a friend, randomly, the games
* by either of the players by chance. and the players play against each other
* ------------------------------------------------------------------------------
* INPUT  : option      -> play against the computer or a friend
* 		   tokenChoice -> choice of player to play as 'X' or 'O'
* 		   playerX     -> Name of the player X
* 		   playerO     -> Name of the player O
* 		   row         -> player('s) choice of the row
* 		   col         -> player('s) choice of the column
*
* ------------------------------------------------------------------------------
* PROCESS: Initializing the board
* 		   Getting Players name
* 		   getting players choice of play
* 		   deciding whose turn is it
* 		   getting the play from both players
* 		   checking for the input
* 		   checking for the win
*
*
* ------------------------------------------------------------------------------
* OUTPUT : Who has won the game
*******************************************************************************/


int main()
{
	/***************************************************************************
	* CONSTANTS
	* --------------------------------------------------------------------------
	* OUTPUT - USED FOR CLASS HEADING
	* --------------------------------------------------------------------------
	* PROGRAMMER  : Programmer's Name
	* CLASS	   	  : Student's Course
	* SECTION	  : Class Days and Time
	* LAB_NUM	  : Lab Number (specific to this lab)
	* LAB_NAME    : Title of the Assignment
	***************************************************************************/
	const string PROGRAMMER	= "Ali Eshghi";
	const string CLASS		= "CS1B";
	const string SECTION	= "MW: 7:30p - 9:50p";
	const int    ASSIGN_NUM	= 2;
	const string ASSIGN_NAME= "Tic-Tac-Toe game";

	PrintHeader(PROGRAMMER, CLASS, SECTION, ASSIGN_NUM, ASSIGN_NAME);


	/*************
	 * VARIABLES *
	 ************/

	string 	playerX;	 //IN & OUT 	- name of player for token X
	string 	playerO;	 //IN & OUT 	- name of player for token O
	int		option;		 //IN & PROCESS - single or multi player
	int		randToken;	 //PROCESS		- random token to start the game
	char	token;		 //PROCESS		- deciding the turn for the players
	char	wonPlayer;	 //PROCESS & OUT- which token won the game
	char 	tokenChoice; //IN & PROCESS - choice of token in single player mode
	char	compToken;   //PROCESS      - system's token in single player mode

	char boardAr[ROW_SIZE][COL_SIZE]; // PROCESS - 2 dimensional array for game


	InitBoard(boardAr);
	//This function initializes each spot in the board to a space ' '.


	OutputInstruct();
	//This function outputs instructions to the users.


	do	// do while loop for continuing the game if the player played the single
	{	//player mode or the game ended in tie

		/***********************************************************************
		* INPUT - gets the input for the option in the menu
		***********************************************************************/
		time(NULL);

		InitBoard(boardAr);
		//This function initializes each spot in the board to a space ' '.

		cout << "MENU:"			    << endl;
		cout << "---------------"   << endl;
		cout << "1 - Single Player" << endl;
		cout << "2 - Multiplayer"   << endl;
		cout << "0 - Exit the Game" << endl << endl;

		cout << "Enter your option to play: ";
		cin  >> option;
		cout << endl << endl;

		if(option == 1) //option = 1 -> single player mode
		{

			GetPlayers(playerX, playerO, compToken,tokenChoice, option);
			//This function prompts the user and gets the input for the players’
			//names.

			DisplayBoard(boardAr);
			//This function outputs the tic-tac-toe board including the tokens
			// played in the proper format


			/*******************************************************************
			* PROCESS - random number generator to get which player starts the
			* 			game
			*******************************************************************/
			srand(time(NULL));

			randToken = rand() % 2 + 1;

			if(randToken == 1)
			{
				token = 'X';
			}
			else if(randToken == 2)
			{
				token = 'O';
			}

			wonPlayer = CheckWin(boardAr);
			//This function checks to see if either player has won.

			while(wonPlayer == 'K') //while loop to keep the game going until
			{						//one of the player has won or the game ends
									//in tie

				GetAndCheckInp(boardAr, token, playerX, playerO,
							   option, tokenChoice, compToken);
				//This functions gets each player's play and checks the inputed
				//numbers are in the domain of the row and column of the game.

				cout << endl;

				DisplayBoard(boardAr);
				//This function outputs the tic-tac-toe board including the
				//tokens played in the proper format

				wonPlayer = CheckWin(boardAr);
				//This function checks to see if either player has won.



				if(wonPlayer == 'K') //if no one has one the game, or ended in
				{					 //tie, the game continues

					token = SwitchToken(token);
					//This function switches the active player.
				}

			}

			OutputWinner(wonPlayer,	playerX, playerO, tokenChoice, compToken,
					     option);

		}





		else if(option == 2) //option = 1 -> single player mode
		{
			GetPlayers(playerX, playerO, compToken ,tokenChoice, option);
			//This function prompts the user and gets the input for the players’
			//names.


			DisplayBoard(boardAr);
			//This function outputs the tic-tac-toe board including the tokens
			// played in the proper format


			/*******************************************************************
			* PROCESS - random number generator to get which player starts the
			* 			game
			*******************************************************************/
			srand(time(NULL));

			randToken = rand()% 2 + 1;

			if(randToken == 1)
			{
				token = 'X';
			}
			else if(randToken == 2)
			{
				token = 'O';
			}

			wonPlayer = CheckWin(boardAr);
			//This function checks to see if either player has won.


			while(wonPlayer == 'K') //while loop to keep the game going until
									//one of the player has won or the game ends
									//in tie
			{

				GetAndCheckInp(boardAr, token, playerX, playerO,
							   option, tokenChoice, compToken);
				//This functions gets each player's play and checks the inputed
				//numbers are in the domain of the row and column of the game.

				cout << endl;

				DisplayBoard(boardAr);
				//This function outputs the tic-tac-toe board including the
				//tokens played in the proper format


				wonPlayer = CheckWin(boardAr);
				//This function checks to see if either player has won.


				if(wonPlayer == 'K') //if no one has one the game, or ended in
				{					 //tie, the game continues
					token = SwitchToken(token);
				}

			}



			OutputWinner(wonPlayer,	playerX, playerO, tokenChoice, compToken,
					     option);



		}

	}while(wonPlayer == 'N' || option != 0 || option == 1);


	cout << "Thank you for playing my tic-tac-toe game. Have a Great day";


	return 0;
}
