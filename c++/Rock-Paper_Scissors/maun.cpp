#include "header.h"


int main()
{
	string 	name;
	int		rounds;
	char	userPlay;
	char	compPlay;
	bool	winStatus;
	int		winCount;
	int		roundCount;

	//initialization
	winCount   = 0;
	roundCount = 1;


	//INPUT
	GetInput(name, rounds);

	for(roundCount = 1; roundCount <= rounds; roundCount++)
	{
		userPlay  = GetAndCheckPlay(name);
		compPlay  = GetCompPlay();
		winStatus = CheckWin(userPlay, compPlay);

		if(winStatus)
		{
			winCount++;
		}//end if statement

		OutputWin(name, winStatus);

	}//end of for loop

	OutputMatchWinner(name, winCount, rounds);


	return 0;
}

