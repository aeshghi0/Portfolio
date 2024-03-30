/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1C
 * SECTION    : MW 5pm
 * Assign #4  : Enhanced Employee
 * DUE DATE   : 26 Febuary 2020
 ******************************************************************************/
#ifndef MYHEADER_H_
#define MYHEADER_H_

//Preprocessor directives

#include <iostream>	//for input and output
#include <cmath>	//for math equations

//using the name space standard
using namespace std;

//class shape: base class for the sub classes with public attributes
class Shape
{
//public parts containing the method functions of the class
public:

	//virtual method for calculating perimeter
    virtual double calcPerimeter() = 0;

    //virtual method for calculating Are
    virtual double calcArea() = 0;
};

//class Square: class for the square attributes
//inherit from the shape class
class Square : public Shape
{

//private attributes of class aquare
private:
    double length;

//public functions of class Square
public:

    //Constructor
    Square(double _length = 0)
	{
    	length = _length;
	}

    //method for setting the length
    void setLength(double l)
    {
        length = l;
    }

    //method for claculating perimeter
    double calcPerimeter()
    {
        return (length * 4);
    }

    //method for calculating area
    double calcArea()
    {
        return length * length;
    }
};

//Class Triangle: contains the attributes of triangle
//inherit from the class Shape
class Triangle : public Shape
{

//private attributes of the class
private:
    double sideA, sideB, sideC;

//public functions of the class triangle
public:

    //constructor
    Triangle(double _sideA = 0, double _sideB = 0, double _sideC = 0)
	{
    	sideA = _sideA;
    	sideB = _sideB;
    	sideC = _sideC;
	}

    //Method for setting first side of the triabgle
    void setSideA(double sideA)
    {
        Triangle::sideA = sideA;
    }

    //method for setting the second side of the triangle
    void setSideB(double sideB)
    {
        Triangle::sideB = sideB;
    }

    //method for setting the third side of the triangle
    void setSideC(double sideC)
    {
        Triangle::sideC = sideC;
    }

    //method for calculating the perimeter
    double calcPerimeter()
    {
        return sideA + sideB + sideC;
    }

    //method for calculating the area
    double calcArea(){
        double p = calcPerimeter()/2;//Get half perimeter
        return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
    }
};

//function for printing the perimeter
void printPerimeter(Shape &obj){
    cout << "Perimeter: " << obj.calcPerimeter() << endl;
}

//function for printing area
void printArea(Shape &obj){
    cout << "Area: " << obj.calcArea() << endl;
}


#endif /* MYHEADER_H_ */
