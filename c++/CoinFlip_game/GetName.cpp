
#include "Header.h"

/******************************************************************************
 * Function : Get Name
 * ---------------------------------------------------------------------------
 * This function will prompt the user for their name and gender and read it
 * into variables n1 & g1
 *****************************************************************************/

void GetName(string &n1, char &g1)
{
	//CONSTANTS
	const int COL_SIZE = 27; //size of prompt column for name and gender

	/**************************************************************************
	 * INPUT - Prompt user for name and gender, read into variables.
	 *************************************************************************/

	cout << left;

	cout << setw(COL_SIZE) << "What is your name? ";
	getline(cin, n1);

	cout << setw(COL_SIZE) << "What is your gender (m/f):";
	cin.get(g1);
	cin.ignore(10000, '\n');

	g1 = toupper(g1);

	cout << right;


}





