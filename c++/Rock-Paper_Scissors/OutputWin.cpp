#include "header.h"

void OutputWin(string user, bool matchResult)
{
	if(matchResult)
	{
		cout << "Computer Wins, better luck next time "<< user << '!' << endl;
	}
	else
	{
		cout << user << "WINS !" << endl;
	}

}
