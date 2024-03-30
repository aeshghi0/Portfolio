/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1C
 * SECTION    : MTWTH - 3pm
 * HW07 	  : Pointers and Dynamic arryas
 * DUE DATE   : 30 June 2020
 ******************************************************************************/

#include"inventoryManagement.h"

//default constructor
inventoryManagement::inventoryManagement()
{
    /***************
	 *  VARIABLES  *
	 ***************/
	count = 0;					//INITIALIZING - increments as the items add to the list
	inv = new inventory*[SIZE];	//PROCESS - for storing the features

	cerr << "Constructor is called" << endl;

	// for(int i = 0; i < SIZE; i++)
	// {
	// 	inv[i] = new inventory[SIZE];
	// }

	//invCopy = inv;
}

// //copy constructor
// inventoryManagement::inventoryManagement(const inventoryManagement& obj)
// {
// 	//cout << "Copy constructor allocating inv: " << endl;
// 	count = obj.count;
// 	inv = new inventory*[SIZE];

// 	for(int i = 0; i < count; i++)
// 	{
// 		inv[i] = obj.inv[i];
// 	}

// }

//Destructor
inventoryManagement::~inventoryManagement() 
{
	cout << "Freeing memory..." << endl;
	//deleting the pointer variable to prevent memory leak

	for(int i =0; i < count; i++)
	{
		delete inv[i];
	}

	delete [] inv;
}

//member function that displays inventory
void inventoryManagement::displayInventory()
{

	// for(int i = 0; i < SIZE; i++)
	// {
	// 	inv--;
	// }
	
	cout << left;

	cout << setw(25) <<"Name of equipment" << setw(8)  <<"Cost" <<"Quantity" << endl;

	//for loop for printing the items one by one
	for(int i = 0; i < SIZE; i++)
	{
		cout << setw(25) <<inv[i]->eqpName;
		cout <<"$" << setw(10)  << inv[i]->price;
		cout << inv[i]->quantity << endl;

		// inv++;
	}

}

//member function that changes the inventory after the shopping
void inventoryManagement::changeInventory()
{
	//making some changes in the inventory
	(*inv)->quantity-=4;
	(*inv)->quantity-=5;
	(*inv)->quantity-=6;
	(*inv)->quantity-=1;
}

void inventoryManagement::addItem(string name, double price, int qnt)
{
	inv[count] = new inventory{ name, price, qnt };

	// (*inv)->eqpName = name;
	// (*inv)->price = price;
	// (*inv)->quantity = qnt;

	// inv++;
	count++; 

}