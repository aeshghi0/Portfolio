/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1C
 * SECTION    : MW 5pm
 * Assign #4  : Surface and Area
 * DUE DATE   : 26 Febuary 2020
 ******************************************************************************/

#include "MyHeader.h"

int main(int argc, char *argv[])
{
	/************************************************************
	 * Perimeter and Area of shapes
	 * _________________________________________________________
	 * This program prompts the user to input information for a
	 * shape of square and a shape of triangle. then using the
	 * virtual methods and inheritance of the classes, calculates
	 * the perimeter and area of those shapes
	 * _________________________________________________________
	 * INPUT: square length, triangle sides
	 *
	 * OUTPUT: prints out the perimeter and area of the both shapes
	 * 		   based on the information that the user put in
	 *
	 ************************************************************/

	//Introduction
	cout << "************************************************************" << endl;
	cout << "* Perimeter and Area of shapes" << endl;
	cout << "* _________________________________________________________" << endl;
	cout << "* This program prompts the user to input information for a" << endl;
	cout << "* shape of square and a shape of triangle. then using the" << endl;
	cout << "* virtual methods and inheritance of the classes, calculates" << endl;
	cout << "* the perimeter and area of those shapes" << endl;
	cout << "* _________________________________________________________" << endl;
	cout << "* INPUT: square length, triangle sides" << endl;
	cout << "*" << endl;
	cout << "* OUTPUT: prints out the perimeter and area of the both shapes" << endl;
	cout << "* 		   based on the information that the user put in" << endl;
	cout << "*" << endl;
	cout << "************************************************************" << endl;

	//Variables

    double length;	//PROCESS - stores user input length
    double sideA, sideB, sideC; //PROCESS - stores user input sides


    Square r;	//PROCESS - square class type variable
    Triangle t;	//PROCESS - triangle class type variable

    //check the 3 arguments are provided
    if(argc < 2)
    {
    	cout << "Argument not provided correctly\n";
    	return 1;
    }

    //Display the first and last name
    cout << "First name: "  << argv[1];
    cout << "\nLast name: " << argv[2];

    //Display second character
    cout << "\nSecond character of first name is: " << argv[1][1];
    cout << "\nSecond character of last name is:  " << argv[2][1];
    cout << endl;

    //getting the infromation for square
    cout << "For square:" << endl;
    cout << "Enter length: ";
    cin >> length;
    r.setLength(length);
    r.calcArea();
    printPerimeter(r);

   // printPerimeter(r);
    printArea(r);

    cout << endl;

    //getting the information for triangle
    cout << "For triangle:" << endl;
    cout << "Enter length of side A: ";
    cin >> sideA;
    cout << "Enter length of side B: ";
    cin >> sideB;
    cout << "Enter length of side C: ";
    cin >> sideC;
    t.setSideA(sideA);
    t.setSideB(sideB);
    t.setSideC(sideC);
    printPerimeter(t);
    printArea(t);
    return 0;
}
