/*******************************************************************************
 * PROGRAMMER : Ali Eshghi
 * STUDENT ID : 1112261
 * CLASS      : CS1C
 * SECTION    : MW 5pm
 * Assign #3  : Cashier
 * DUE DATE   : 22 January 2020
 ******************************************************************************/

#include"Header.h"

/*******************************************************************************
* Assignment 3
* ------------------------------------------------------------------------------
* This program will get name, price, and quantity of some sport equipments and
* using the pointer variable, it stores them and send them to a display function
* for output on the screen, then using the struct variables, we calculate that if
* a user buys something from store, how many of that item is going to be
* available after that and also it calculates that how much the cost is going to
* be, before and after tax.
* ------------------------------------------------------------------------------
* INPUT  : Nothing
* ------------------------------------------------------------------------------
* PROCESS: the program calculates Mark's purchas bill for four pairs of Nike
* 		   basketball shoes, five Under Armour T-shirts, six Under Armour shorts
* 		   , and one pair of Asics running shoes, including the total cost
* 		   before and after tax. Assume the tax rate is 7.75%
* ------------------------------------------------------------------------------
* OUTPUT : The progeam will output a recipt of the items that mark purchased,
* 		   and outputs the total price of what mark has purchased before and
* 		   after tax. It also outputs the store inventory before and after
* 		   mark's purchase
*******************************************************************************/
int main()
{
	/***************
	 *  VARIABLES  *
	 ***************/

	inventory *inv = new inventory[SIZE];	//PROCESS - for storing the features
	double total;							//PROCESS & OUT - calculating the total price
	double tax;								//PROCESS & OUT - calculating the tax

	/********************
	 *  INITIALIZATION  *
	 ********************/

	inv[0].eqpName  = "Nike basketball shoes";
	inv[0].price    = 179.99;
	inv[0].quantity = 25;

	inv[1].eqpName  = "Under Armor T-shirt";
	inv[1].price    = 29.99;
	inv[1].quantity = 88;

	inv[2].eqpName  = "Brooks running shoes";
	inv[2].price    = 121.44;
	inv[2].quantity = 13;

	inv[3].eqpName  = "Asics running shoes";
	inv[3].price    = 165.88;
	inv[3].quantity = 12;

	inv[4].eqpName  = "Under Armor shorts";
	inv[4].price    = 45.77;
	inv[4].quantity = 35;

	cout<<"*** Purchase bill *** "						<<endl;
	cout<<"Item No. Name of equipment\tCost\tQuantity"  <<endl;
	cout<<"1. Nike basketball shoes\t$179.99\t\t4 "     <<endl;
	cout<<"2. Under Armour T-shirt\t\t$29.99\t\t5 "     <<endl;
	cout<<"3. Under Armour shorts\t\t$45.77\t\t6 "      <<endl;
	cout<<"4. Asics running shoes\t\t$165.88\t\t1 "		<<endl;

	//calculating total purchase price
	total = 4 * 179.99 + 5 * 29.99 + 6 * 45.77 + 165.88;
	cout<<" Total Cost: $"<< total << endl;

	//calculating the tax
	tax = total * 7.75/100;

	cout << "Tax(7.75%) $" << tax << endl;

	cout <<"Total cost $" << (total + tax) << endl << endl;

	//inventory before the purchase
	cout << "Inventory before marks purchase:" << endl;
	display(inv);

	//making some changes in the inventory
	inv[0].quantity-=4;
	inv[1].quantity-=5;
	inv[4].quantity-=6;
	inv[3].quantity-=1;

	//inventory after the purchase
	cout << "\n\nInventory after marks purchase:" << endl;
	display(inv);

	//deleting the pointer variable to prevent memory leak
	delete []inv;

	return 0;


}
