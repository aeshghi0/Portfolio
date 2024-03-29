/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1C
 * SECTION    : MTWTH 3pm
 * HW01       : random number generation
 * DUE DATE   : 04 June 2020
 ******************************************************************************/

#include"MyHeader.h"

/************************************************************
 * Random number generator
 * _________________________________________________________
 * This program generates a three digit number and does some
 * operations such as reversing the digits, adding up the
 * digits and also triple of the given number. This program
 * also stores 10 random numbers in an array, then it sorts
 * the array based. the program then is going to write the
 * numbers in an external file, then it is going to read
 * from the same file and print out the array of the numbers
 * _________________________________________________________
 * INPUT: N/A
 *
 * OUTPUT: random number(int rnum)
 * 		   reverse digits(int rev_rnum)
 * 		   sum of digits(int sum)
 * 		   triple of the number(int triple)
 * 		   10 random number array(int rnumAr[]) -> sorted
 ************************************************************/
int main()
{

	//Variables
	in rnum;				//PROCESS & OUT - random number variable
	in rnumAr[10] = {0};	//PROCESS & OUT - random number array

	srand(time(NULL)); //Initialize random number generator.
	rnum = (rand()%899 + 100);
	cout << "Random Number: " << rnum << endl;

	//reverses the digits of the random number
	reverse_SumDigits(rnum);

	//triples the given number
	triple(rnum);

	//storing 10 random number in an array
	for(int i = 0; i < 10; i++)
	{
		rnumAr[i] = (rand()%100);
	}
	cout << "10 numbers stored in the array" << endl;

	//sorts the array
	sort(rnumAr);

	//writes the array in an external file
	FileWrite(rnumAr);

	//reads from the file
	FileRead();

	//prints the array of the number
	print(rnumAr);

}



