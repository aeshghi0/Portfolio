#include "header.h"

char GetCompPlay()
{
	int 	compPlay;
	char	compChoice;

	compPlay = rand() % 3 + 1;

	switch(compPlay)
	{
		case 1: compChoice = 'R';                             				  //strncpy(compChoice,"Rock", 9);
		break;

		case 2: compChoice = 'P';											  //strncpy(compChoice,"Paper", 9);
		break;

		case 3: compChoice = 'S';											//strncpy(compChoice,"Scissors", 9);
	}

	cout << "computer Chooses " << compChoice << endl;


	return compChoice;
}
