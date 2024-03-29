/*******************************************************************************
 * PROGRAMMER : Ali Eshghi & Amirarsalan Valipour
 * STUDENT ID : 1112261 & 1103126
 * CLASS      : CS1B
 * SECTION    : MW 7:30pm
 * Assign #2  : tic-tac-toe game (multi-dimensional arrays)
 * DUE DATE   : 19 September 2019
 ******************************************************************************/

#include "MyHeader.h"
#include "ClassHeader.h"

//Outputting the information for Fluffy using a method

void Sheep1::PrintSheep1(string name1, string type1, int age1, float value1) const
{
	cout << fixed << setprecision(2);
	cout << setw(11) << type << setw(15) << name << setw(8) << age << setw(8) << value << endl;
}

//Outputting the information for Maa using a method

void Sheep2::PrintSheep2(string name2, string type2, int age2, float value2) const
{
	cout << fixed << setprecision(2);
	cout << setw(11) << type << setw(15) << name << setw(8) << age << setw(8) << value << endl;
}

//Outputting the information for Babe using a method

void Pig::PrintPig(string nameP, string typeP, int ageP, float valueP) const
{
	cout << fixed << setprecision(2);
	cout << setw(11) << type << setw(15) << name << setw(8) << age << setw(8) << value << endl;
}
