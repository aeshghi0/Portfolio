/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1C
 * SECTION    : MTWTH 3pm
 * Assign #1  : STL Vectors
 * DUE DATE   : 23 June 2020
 ******************************************************************************/
#include"hw05.h"

/************************************************************
 * STL Vectors
 * _________________________________________________________
 * This program passes two arguments  to the function
 * with vector return type (lotto()). the first number is the 
 * number of the spots on a lottery card and the second is the 
 * number of spots selected at random. The program would assign
 * to winners a vector that contains six  numbers selected randomly
 * from range 1 through 51.
 * _________________________________________________________
 * INPUT: N/A
 *
 * OUTPUT: 
 *
 *
 ************************************************************/

int main()
{
    //Variables
    vector<int>winners; //PROCESS & OUT - vector for the lottery winners

    //calling function get the lotto winner
    cout << "The maximum number passed is " << 51 << endl
         << "The count numbers passed is  " << 6  << endl;
    winners = lotto(51,6);

    //Printing the numbers
    for(int i = 0; i < winners.size(); i++)
    {
        cout << winners.at(i) <<" ";
    }
    cout << endl;
}

