#include "header.h"

char GetAndCheckPlay(string name)
{
	char userPlay;

	cout << "**********************" << endl;
	cout << "** CHOOSE YOUR PLAY **" << endl;
	cout << "**********************" << endl;
	cout << "R - Rock"     << endl;
	cout << "P - Paper"    << endl;
	cout << "S - Scissors" << endl;

	cout << "Enter your Play:  ";
	cin.get(userPlay);
	cin.ignore(1000,'\n');


	if (userPlay == 'r' || userPlay == 'R')
	{
		userPlay = 'R';
	}
	else if (userPlay == 'p' || userPlay == 'P')
	{
		userPlay = 'P';
	}
	else if (userPlay == 's' || userPlay == 'S')
	{
		userPlay = 'S';
	}

	if( userPlay == 'S')
	{
		cout << name << " Chooses Scissors!" << endl;
	}
	else if(userPlay == 'R')
	{
		cout << name << "Chooses Rock!" << endl;
	}
	else
	{
		cout << name << "Chooses Paper!" << endl;
	}


		return userPlay;
}
