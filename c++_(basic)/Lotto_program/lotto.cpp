/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1C
 * SECTION    : MTWTH 3pm
 * Assign #1  : STL Vectors
 * DUE DATE   : 23 June 2020
 ******************************************************************************/
#include"hw05.h"

/******************************************************************************
 * Function generates random lotto values
 * Take maximum of random number and count of lotto umber as parameter
 * Return winners lotto vector
 ******************************************************************************/
vector<int>lotto(int maxRandNum, int count)
{
    //Variable
    vector<int>winners; //PROCESS & OUT - vectors to store the winner numbers
    vector<int>temp;    //PROCESS - temporary vector

    //Adds one to the maximum random number
    for(int i=1; i<=maxRandNum; i++)
    {
        temp.push_back(i);
    }

    //shuffle the vector
    random_shuffle(temp.begin(),temp.end());

    //put first count of values in the winner lottos
    for(int i=0; i < count; i++)
    {
        winners.push_back(temp.at(i));
    }

    //Sort the vector
    sort(winners.begin(),winners.end());

    //Return resulting vector
    return winners;

}