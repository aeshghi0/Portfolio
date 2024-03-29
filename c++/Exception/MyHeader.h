/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1C
 * SECTION    : MW 5pm
 * Assign #7  : Exception
 * DUE DATE   : 23 March 2020
 ******************************************************************************/

#ifndef MYHEADER_H_
#define MYHEADER_H_


//Preprocessor directives

#include <iostream>	//for input and output
#include <math.h>	//for math equations

//using the name space standard
using namespace std;

//class shape: base class for the sub classes with public attributes
class Shape
{
//public parts containing the method functions of the class
public:

	//virtual method for calculating perimeter
	virtual float calcPerimeter() = 0;

	//virtual method for calculating Are
	virtual float calcArea() = 0;

	// to check perimeter of different types of shapes
	friend bool equalPer(Shape &x, Shape &y);
};

//function equalPer: checks if the perimeter of two shapes are equal
//return type: bool
bool equalPer(Shape &x, Shape &y)
{
	if(x.calcPerimeter() == y.calcPerimeter())
		return true;
	else
		return false;
}

//class Square: class for the square attributes
//inherit from the shape class
class Square : public Shape
{
	float length;

//public functions of class Square
public:

	//Constructor
	Square(float l)
	{
		length=l;
	}

	//method for claculating perimeter
	float calcPerimeter()
	{
		return length * 4;
	}

    //method for calculating area
	float calcArea()
	{
		return length*length;
	}

    //method for printing perimeter
	void printPerimeter()
	{
		cout<<"Perimeter of Square is "<<calcPerimeter()<<"\n";
	}

    //method for printing area
	void printArea()
	{
		cout<<"Area of Square is "<<calcArea()<<"\n";
	}

    //method for addition
	void addition(int x)
	{
		length += x;
		cout<<"Length increased by "<<x<<" units\n";
	}
	// overloading operator ==
	friend bool operator==(Square &r1, Square &r2);

	// overloading operator +
	friend Square operator+(Square &r1, int x);

	// overloading operator <<
	friend ostream& operator<< (ostream &out, Square &point);

	// overloading operator >>
	friend istream& operator>> (istream &in, Square &point);
};

//function to overload the == operator
//return type : bool
bool operator==(Square &r1, Square &r2)
{
	return (r1.calcArea() == r2.calcArea());
}

//function to overload the + operator
//return type : square class type variable
Square operator+(Square &r, int x)
{
	r.length += x;
	cout<<"Length increased by "<<x<<" units\n";
	return r;
}


ostream& operator<< (ostream &out, Square &r)
{
	out<<"Length of Square : "<<r.length;
	out<<endl;
	r.printPerimeter();
	r.printArea();
	return out;
}

istream& operator>> (istream &in, Square &r)
{
	cout<<"Enter length : ";
	cin>>r.length;
	r.printArea();
	r.printArea();
}

class Triangle : public Shape
{
	float side1,side2,side3;

public:
	Triangle(float a,float b,float c)
	{
		side1=a;
		side2=b;
		side3=c;
	}

	float calcPerimeter()
	{
		return side1+side2+side3;
	}

	float calcArea()
	{
		float s=calcPerimeter()/2;
		float area = sqrt(s*(s-side1)*(s-side2)*(s-side3));
		return area;
	}

	void printPerimeter()
	{
		cout<<"Perimeter of Triangle is "<<calcPerimeter()<<"\n";
	}

	void printArea()
	{
		cout<<"Area of Triangle is "<<calcArea()<<"\n";
	}
};






#endif /* MYHEADER_H_ */
