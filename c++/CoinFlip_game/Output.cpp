
#include "Header.h"

/******************************************************************************
 * Function : Output
 * ---------------------------------------------------------------------------
 * This function will output the results of the match.
 *****************************************************************************/

void Output(int totalFlips, float perc)
{

	cout << fixed << setprecision(0);

	cout << endl << endl;
	cout << "It took you " << totalFlips
		 << " tosses to get 3 heads in a row.\n";
	cout << "On average you flipped heads " << perc << "% of the time";

	cout.unsetf(ios::fixed);

}



