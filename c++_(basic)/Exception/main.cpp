/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1C
 * SECTION    : MW 5pm
 * Assign #7  : Exception
 * DUE DATE   : 23 March 2020
 ******************************************************************************/

#include "MyHeader.h"

int main(int argc, char *argv[])
{
	/****************************************************************
	 * Perimeter and Area of shapes comparing using
	 * overloading frined functions and class methods
	 * ______________________________________________________________
	 * This program prompts the user to input information for a
	 * shape of square and a shape of triangle. then using the
	 * virtual methods and inheritance of the classes, calculates
	 * the perimeter and area of those shapes, then using the
	 * frined class functions and class methods, the program
	 * compares the area and perimeter of the squares with the
	 * area and perimeter of the triangle. then outputs if any
	 * attributes of these shapes were equal, then again promts the
	 * user how many units they want to increase the length of both
	 * shapes and again print outs the attribute of the shapes
	 *
	 *Also, using the try/catch blocks, the program determines if the
	 *input numbers by the user are correct or no.
	 * ______________________________________________________________
	 * INPUT: square length, triangle sides
	 *
	 * OUTPUT: prints out the perimeter and area of the both shapes
	 * 		   based on the information that the user put in, the
	 * 		   result of the comparison of the attributes, and the
	 * 		   new attributes after the modification
	 *
	 ****************************************************************/


	cout << "/****************************************************************\n"
		 << "* Perimeter and Area of shapes comparing using\n"
	 	 << "* overloading frined functions and class methods\n"
	 	 << "* ______________________________________________________________\n"
		 << "* This program prompts the user to input information for a\n"
		 << "* shape of square and a shape of triangle. then using the\n"
	 	 << "* virtual methods and inheritance of the classes, calculates\n"
	 	 << "* the perimeter and area of those shapes, then using the\n"
	 	 << "* frined class functions and class methods, the program\n"
	 	 << "* compares the area and perimeter of the squares with the\n"
	 	 << "* area and perimeter of the triangle. then outputs if any\n"
	 	 << "* attributes of these shapes were equal, then again promts the\n"
	 	 << "* user how many units they want to increase the length of both\n"
	 	 << "* shapes and again print outs the attribute of the shapes\n"
	 	 << "*\n"
	 	 << "* ______________________________________________________________\n"
		 << "* INPUT: square length, triangle sides\n"
		 << "*\n"
	 	 << "* OUTPUT: prints out the perimeter and area of the both shapes\n"
	 	 << "* 		   based on the information that the user put in, the\n"
	 	 << "* 		   result of the comparison of the attributes, and the\n"
	 	 << "* 		   new attributes after the modification\n"
	 	 << "*\n"
	 	 << "****************************************************************/\n\n";


// check if 3 arguments are provided are not
// argv[0] is program name
// argv[1] is first name, argv[2] is last name
if(argc < 3)
{
cout<<"Arguments not provided correctly\n";
return 1;
}


// display first and last name
cout<<"First Name : "<<argv[1];
cout<<"\nLast Name : "<<argv[2];


// display second characters
// since argv[] is a char array we can directly access it's second char by [1] index
cout<<"\nSecond Character of First Name : "<<argv[1][1];
cout<<"\nSecond Character of Last Name : "<<argv[2][1];
// PART B ends

// input 3 squares and triangles for sample testing
float length,side1,side2,side3;

//begin try block
try
{
	cout << "\n\nTRY BLOCK #1: ";

	cout<<"\n\nEnter the length of 1st Square:";
	cin>>length;

	throw length;
}

catch(float length)
{
	cout << "\n\nCATCHBLOCK #1: ";

	while(length < 0 || length > 50)
	{


		if(length < 0)
		{
			cout << "\nThe side length: " << length
				 << " is too small.\nPlease enter a value greater than 0.\n\n";
		}

		else if(length > 50)
		{
			cout << "\nThe side length: " << length
				 << " is too big.\nPlease enter a value smaller than 50.\n\n";
		}

		cout<<"\n\nEnter the length of 1st Square:";
		cin>>length;
		cin.ignore(10000,'\n');
	}

}

cout << "\n<<Valid side length input>>\n\n";

Square r1(length);
r1.printPerimeter();
r1.printArea();
cout<<"Enter the three sides of 1st triangle:";
cin>>side1>>side2>>side3;
Triangle s1(side1,side2,side3);
s1.printPerimeter();
s1.printArea();


//begin try block
try
{
	cout << "\n\nTRY BLOCK #2: ";

	cout<<"\n\nEnter the length and width of 2nd square:";
	cin>>length;

	throw length;
}

catch(float length)
{
	cout << "\n\nCATCHBLOCK #1: ";

	while(length < 0 || length > 50)
	{


		if(length < 0)
		{
			cout << "\nThe side length: " << length
				 << " is too small.\nPlease enter a value greater than 0.\n\n";
		}

		else if(length > 50)
		{
			cout << "\nThe side length: " << length
				 << " is too big.\nPlease enter a value smaller than 50.\n\n";
		}

		cout<<"\n\nEnter the length of 2nd Square:";
		cin>>length;
		cin.ignore(10000,'\n');
	}
}

cout << "\n<<Valid side length input>>\n\n";

Square r2(length);
r2.printPerimeter();
r2.printArea();
cout<<"Enter the three sides of 2nd triangle:";
cin>>side1>>side2>>side3;
Triangle s2(side1,side2,side3);
s2.printPerimeter();
s2.printArea();

//begin try block
try
{
	cout << "\n\nTRY BLOCK #3: ";

	cout<<"\n\nEnter the length of 3rd square:";
	cin>>length;

	throw length;
}

catch(float length)
{
	cout << "\n\nCATCHBLOCK #3: ";

	while(length < 0 || length > 50)
	{


		if(length < 0)
		{
			cout << "\nThe side length: " << length
				 << " is too small.\nPlease enter a value greater than 0.\n\n";
		}

		else if(length > 50)
		{
			cout << "\nThe side length: " << length
				 << " is too big.\nPlease enter a value smaller than 50.\n\n";
		}

		cout<<"\n\nEnter the length of 3rd square:";
		cin>>length;
		cin.ignore(10000,'\n');
	}
}

Square r3(length);
r3.printPerimeter();
r3.printArea();
cout<<"Enter the three sides of 3rd triangle:";
cin>>side1>>side2>>side3;
Triangle s3(side1,side2,side3);
s3.printPerimeter();
s3.printArea();


// Testing for equal perimeters
cout<<"\nSquare 1 and Triangle 1 Perimeter Check : ";
if(equalPer(r1, s1))
{
cout<<"Equal\n";
}
else
cout<<"Unequal\n";

cout<<"\nSquare 2 and Triangle 2 Perimeter Check : ";
if(equalPer(r2, s2))
{
cout<<"Equal\n";
}
else
cout<<"Unequal\n";


// Testing rectangles for equal area
cout<<"\nSquare 1 and Rectangle 2 Area Check : ";
if(r1 == r2)
{
cout<<"Equal\n";
}
else
cout<<"Unequal\n";

cout<<"\nSquare 2 and Rectangle 3 Area Check : ";
if(r2 == r3)
{
cout<<"Equal\n";
}
else
cout<<"Unequal\n";


// testing addition member function
int x;
cout<<"\nIncrease length of Square 1 by how much : ";
cin>>x;
r1.addition(x);


// testing overloaded + operator
cout<<"\nAfter doing r2 = r2 + 8 :\n";
r2 = r2 + 8;


// testing >> overloaded operator
cout<<"\nAfter doing cin>>r3 :\n";
cin>>r3;

// testing << overloaded operator
cout<<"\nAfter doing cout<<r3 :\n";
cout<<r3;

return 0;
}



