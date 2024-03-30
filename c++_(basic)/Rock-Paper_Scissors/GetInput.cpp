#include "header.h"

void GetInput(string &user, int &turn)
{
	cout << "Enter Player's Name: ";
	getline(cin, user);

	cout << "Enter Number of Rounds in Match";
	cin  >> turn;

}

