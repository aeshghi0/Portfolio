#include "Header.h"

/******************************************************************************
 * Function : Flip Coin
 * ---------------------------------------------------------------------------
 * This function will generate a random number between 0 and 1.
 *****************************************************************************/

bool FlipCoin()
{
	bool headOrTail; // bool for heads (true) or tails (false)
	char random;     // dummy variable to read in enter from keyboard

	cout << "Press <enter> to flip";
	cin.get(random);

	headOrTail = rand() % 2;

	return headOrTail;

}//end function




