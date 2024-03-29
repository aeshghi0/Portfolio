#include "Header.h"

/******************************************************************************
 * Function : Average
 * ---------------------------------------------------------------------------
 * This function will calculate the average of head flips for the total amount
 * of tries.
 *****************************************************************************/

float Average(int numHeads, int totalFlips)
{
	float result;

	result = (float(numHeads) / totalFlips) * 100;

	return result;

}// end function




