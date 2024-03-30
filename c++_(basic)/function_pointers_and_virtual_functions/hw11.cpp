// hw11.cpp
// to illustrate function pointers and virtual functions

/*************************************************************************
 * AUTHOR     : Ali Eshghi
 * HW11       : function pointers and virtual functions
 * CLASS      : CS 1C
 * SECTION    : July 9th, 2020
*************************************************************************/

#include <iostream>
#include <algorithm>

using std::string;
using std::cout;
using std::cin;
using std::endl;

// function & class definitions go into hw11.cpp:

// hw11.cpp

namespace hw11 {

//--Q#1-------------------------------------------------------------------------

// (footnote 1)

string foo()
{
    return "foo";
}

//------------------------------------------------------------------------------

int hoo(int x)
{
    return x;
}

//------------------------------------------------------------------------------

int boo(int x)
{
    return 2 * x;
}

//------------------------------------------------------------------------------

double goo(int x, double y)
{
    return x * y;
}

// (footnote 1 - source) adapted from learncpp.com - Alex - 7.8 function pointers

//--Q#2-------------------------------------------------------------------------

// (footnote 1)

// Note our user-defined comparison is the third parameter
void selectionSort(int *array, int size, bool (*comparisonFcn)(int, int))
{
    // Step through each element of the array
    for (int startIndex = 0; startIndex < size - 1; ++startIndex)
    {
        // bestIndex is the index of the smallest/largest element we've encountered so far.
        int bestIndex = startIndex;
 
        // Look for smallest/largest element remaining in the array (starting at startIndex+1)
        for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
        {
            // If the current element is smaller/larger than our previously found smallest
            if (comparisonFcn(array[bestIndex], array[startIndex])) // COMPARISON DONE HERE
                // This is the new smallest/largest number for this iteration
                bestIndex = currentIndex;
        }
 
        // Swap our start element with our smallest/largest element
        std::swap(array[startIndex], array[bestIndex]);
    }
}

//------------------------------------------------------------------------------
 
// Here is a comparison function that sorts in ascending order
// (Note: it's exactly the same as the previous ascending() function)
bool ascending(int x, int y)
{
    return x > y;   //swaps if the first element is bigger than second element
}

//------------------------------------------------------------------------------
 
// Here is a comparison function that sorts in descending order
bool descending(int x, int y)
{
    return x < y;   //swaps if first element is smaller than the second element
}

//------------------------------------------------------------------------------
 
// custom comparison function, explain how your function sorts array components
bool custom_sort(int x, int y)
{
    if((x % 2 == 1) && !(y % 2 == 1))
    {
        return false;
    }
    if(!(x % 2 == 1) && (y % 2 == 1))
    {
        return true;
    }
    //the custome sort puts the odd numbers first

}

//------------------------------------------------------------------------------
 
// This function prints out the values in the array
void printArray(int *array, int size)
{
    for (int index=0; index < size; ++index)
        cout << array[index] << " ";
    cout << '\n';
}

// (footnote 1 - source) learncpp.com - Alex - 7.8 function pointers

//--Q#3,4-----------------------------------------------------------------------

// (footnote 2)

class Base
{
public:
    virtual void function1() {};
    virtual void function2() {};
};
 
//------------------------------------------------------------------------------
 
class D1 : public Base
{
public:
    virtual void function2() {};
};
 
//------------------------------------------------------------------------------
 
class D2 : public Base
{
public:
    virtual void function1() {};
    virtual void function3() {};
};

//------------------------------------------------------------------------------

class D3 : public D2
{
public:
    virtual void function2() {};
};

// (footnote 2 - source) adapted from learncpp.com - Alex - 12.5 the virtual table

//--Q#5-------------------------------------------------------------------------

class BaseSlice
{
   int base_id;
};

//------------------------------------------------------------------------------

class DerivedSlice : public BaseSlice
{
   int derived_id;
};

//------------------------------------------------------------------------------

} // hw11

//------------------------------------------------------------------------------

using namespace hw11;

int main()
{
    // console header
	cout << endl;
	cout << "************************************** " << endl;
	cout << "*           Running HW11             * " << endl;
	cout << "*      Programmed by Ali Eshghi      * " << endl;
	cout << "*      CS1C July 9th, 2020           * " << endl;
	cout << "************************************** " << endl;
	cout << endl;

	// Q#1 - function pointer examples

    // function pointer assignments
    string (*fcnPtr1)(); // [1.1] declare and init function pointer fcnPtr1 to point to function foo
    fcnPtr1 = foo;
    int (*fcnPtr2)(int); // [1.2] declare and init function pointer fcnPtr2 to point to function hoo
    fcnPtr2 = hoo;
    double (*fcnPtr3)(int, double); // [1.3] declare and init function pointer fcnPtr3 to point to function goo
    fcnPtr3 = goo;
    // fcnPtr1 = boo; // [1.4] assign fcnPtr1 to point to boo - error, because the pointer to function type is different 

    fcnPtr2 = boo; // [1.5] assign fcnPtr2 to point to boo, okay - function pointer signature matches function boo

    // calling a function using a function pointer via explicit dereference
    (*fcnPtr3)(2, 5.0); // [1.6] call function goo(2,5.0) through fcnPtr3 via explicit dereference

    // calling a function using a function pointer via implicit dereference
    fcnPtr3(2, 5.0); // [1.7] call function goo(2,5.0) through fcnPtr3 implicit dereference

	// Q#2 - function pointers - calling user defined comparison functions in algorithms

    int array[9] = { 3, 7, 9, 5, 6, 1, 8, 2, 4 };

    std::cerr << "sorting array 1" << endl;
    // TEMP - COMPLETE FUNCTION CALL AND UNCOMMENT LINE BELOW
    selectionSort(array, 9, descending); // [2.1] sort array in descending order
    printArray(array, 9);
 
    std::cerr << "storing array 2" << endl;
    // TEMP - COMPLETE FUNCTION CALL AND UNCOMMENT LINE BELOW
    selectionSort(array, 9, ascending); // [2.2] sort array in ascending order
    printArray(array, 9);
 
    std::cerr << "storing array 3" << endl;
    // TEMP - COMPLETE FUNCTION CALL AND UNCOMMENT LINE BELOW
    selectionSort(array, 9, custom_sort); // [2.3] sort array via custom_sort algorithm
    printArray(array, 9);

	// Q#3,4 - virtual function tables & calls

    D2 d2;
    Base *dPtr = &d2;
    dPtr->function1(); // [Q#4] what happens here ... explain in WRITTEN ANSWERS below?

	// Q#5 - the slicing problem

    DerivedSlice dSlice;          // instantiate derived class object
    BaseSlice baseSlice = dSlice; // instantiate base class object and assign to derived class
                                  // [Q#5] what is the slicing problem ... explain in WRITTEN ANSWERS below?


    return 0;
}

//------------------------------------------------------------------------------

// WRITTEN ANSWERS

// Q#3 (footnote 1)

/******* Base Class Virtual Function Table ********/
/* virtual function1() -> calls Base::function1() */
/* virtual function2() -> calls Base::function2() */
/**************************************************/

/******* D1 Class Virtual Function Table **********/
/* virtual function1() -> calls Base::function1() */
/* virtual function2() -> calss D1::function2()   */
/**************************************************/

/******* D2 Class Virtual Function Table **********/
/* virtual function1() -> calls D2::function1()   */
/* virtual function2() -> calls base::function2() */
/* virtual function3() -> calls D2::function3()   */
/**************************************************/

/******* D3 Class Virtual Function Table **********/
/* virtual function1() -> calls base::function1() */
/* virtual function2() -> calls D3::function2()   */
/* virtual function3() -> error - undefined virFnc*/
/**************************************************/

// (footnote 1 - source) adapted from learncpp.com - Alex - 12.5 the virtual table

// Q#4: at the first line of the selected three line for the question for, we declare a
//      d2 that is D2 object, then in the second line we set a base pointer to D2. and 
//      finally in the last line, the program recognizes that the finction1() is a virtual
//      function. and then the program uses dPtr->__vPtr to get to D2's virtual table.

// add written answers here

// Q#5: Object slicing doesn’t occur when pointers or references to objects are passed 
//      as function arguments since a pointer or reference of any type takes same
//      amount of memory.

// add written answers here
