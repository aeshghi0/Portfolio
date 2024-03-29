#include "header.h"

bool CheckWin(char userChoice, char compChoice)
{

	bool winCheck;



	winCheck = (compChoice == 'R' && userChoice == 'S')
			 ||(compChoice == 'S' && userChoice == 'P')
			 ||(compChoice == 'P' && userChoice == 'R');


	return winCheck;
}

